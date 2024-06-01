#pragma once
#include "Effects.h"
#include <8Beat/AudioSourceHandler.h>
#include <8Beat/SFX.h>


enum class EnemyState { PATROL, HUNT, SHOOT, EVADE, DESTROYED };
struct EnemyData
{
  EnemyData() = default;
  EnemyData(float x, float y)
   : x_pos(x), y_pos(y), id(++g_id) {}

  int id = -1;
  static int g_id;
  EnemyState state = EnemyState::PATROL;
  float x_pos = 0.f;
  float y_pos = 0.f;
  float x_vel = 0.f;
  float y_vel = 0.f;
  float x_acc = 0.f;//5.f;
  float y_acc = 0.f;//5.f/1.4;
  float x_diff = 0.f;
  float y_diff = 0.f;
  float dist = 0.f;
  // Enemy Fire
  int time_shooting = 0;
  int shot_timeout = 0;
  float x_pos_shot = 0.f;
  float y_pos_shot = 0.f;
  float shot_angle = 0.f;
  float bullet_offs_x = 0.f;
  float bullet_offs_y = 0.f;
  bool shot_hit = false;
  /*const*/ int plane_explosion_anim_max = 1*3;
  int plane_explosion_anim_ctr = plane_explosion_anim_max;
  float plane_explosion_offs_x = 0.f;
  float plane_explosion_offs_y = 0.f;
  // Plane Fire
  /*const*/ int enemy_explosion_anim_max = 3*3;
  int enemy_explosion_anim_ctr = enemy_explosion_anim_max;
};
int EnemyData::g_id = -1;
template<int NR, int NC>
EnemyData enemy_step_ai(SpriteHandler<NR, NC>& sh, EnemyData ed,
                        audio::AudioStreamSource* src_fx,
                        float x_pos_plane, float y_pos_plane, float x_vel_plane, float y_vel_plane,
                        const std::vector<std::tuple<int, int, bool>>& plane_hull, bool plane_hiding,
                        int plane_shot_r, int plane_shot_c, bool plane_shot_fired, bool& shot_down,
                        int anim_ctr, float dt,
                        int cloud_limit, int ground_level)
{
//#define DEBUG_ENEMY

#ifdef DEBUG_ENEMY
  const int sel_id = 0;
#endif

  const int enemy_len = 7;
  const float enemy_half_len = 3.5f;

  ed.x_diff = (ed.x_pos + enemy_half_len) - (x_pos_plane + plane_half_len);
  ed.y_diff = ed.y_pos - y_pos_plane;

  auto dist_sq = ed.x_diff*ed.x_diff + ed.y_diff*ed.y_diff;
  ed.dist = std::sqrt(dist_sq);

  auto& es = ed.state;

  int enemy_r = r_mid + math::roundI(ed.y_pos - y_pos_plane);
  int enemy_c = c_mid + math::roundI(ed.x_pos - x_pos_plane);
  if (es != EnemyState::DESTROYED
      && plane_shot_fired
      && (enemy_r + 1) == plane_shot_r
      && enemy_c <= plane_shot_c && plane_shot_c < enemy_c + enemy_len)
  {
    shot_down = true;
    es = EnemyState::DESTROYED;
    ed.enemy_explosion_anim_ctr = 0;
    score += 1000;
    num_enemies_shot_down++;
  }


  switch (es)
  {
    case EnemyState::PATROL:
    {
#ifdef DEBUG_ENEMY
      if (ed.id == sel_id)
        sh.write_buffer("PATROL", 2, 5, Text::Color::Green);
#endif
      if (anim_ctr % 40 == 0)
      {
        const float acc_scale = 2.f;
        auto calc_acc_f = [acc_scale](float acc)
        {
          float t_rnd = rnd::rand();
          return math::sign(acc) * acc_scale * t_rnd;
        };
        ed.x_acc += calc_acc_f(ed.x_acc);
        ed.y_acc += calc_acc_f(ed.y_acc)/pix_ar2;
      }
      else if (std::rand() % 100 == 0)
        ed.x_acc *= -1.f;
      else if (std::rand() % 100 == 0)
        ed.y_acc *= -1.f;
      else if (std::rand() % 60 == 0)
      {
        ed.x_acc /= 2.f;
        ed.y_acc /= 2.f;
        ed.x_vel /= 4.f;
        ed.y_vel /= 4.f;
      }
      if (ed.x_pos < -cloud_limit)
      {
        if (ed.x_acc < 0)
          ed.x_acc *= -1.f;
        if (ed.x_vel < 0)
          ed.x_vel *= -1.f;
      }
      else if (ed.x_pos > +cloud_limit)
      {
        if (ed.x_acc > 0)
          ed.x_acc *= -1.f;
        if (ed.x_vel > 0)
          ed.x_vel *= -1.f;
      }
      if (ed.y_pos < -cloud_limit)
      {
        if (ed.y_acc < 0)
          ed.y_acc *= -1.f;
        if (ed.y_vel < 0)
          ed.y_vel *= -1.f;
      }
      else if (ed.y_pos > +cloud_limit)
      {
        if (ed.y_acc > 0)
          ed.y_acc *= -1.f;
        if (ed.y_vel > 0)
          ed.y_vel *= -1.f;
      }
      ed.x_vel += ed.x_acc*dt;
      ed.y_vel += ed.y_acc*dt;
      ed.x_pos += ed.x_vel*dt;
      ed.y_pos += ed.y_vel*dt;
      if (ed.dist < 100)
        es = EnemyState::HUNT;
      break;
    }
    case EnemyState::HUNT:
    {
#ifdef DEBUG_ENEMY
      if (ed.id == sel_id)
        sh.write_buffer("HUNT", 2, 5, Text::Color::Green);
#endif
      ed.time_shooting = 0;
      float ang = std::atan2(ed.y_diff, ed.x_diff);
      const float speed = math::clamp(0.04f*ed.dist, 0.f, 5.f);
      ed.x_pos -= speed*std::cos(ang);
      ed.y_pos -= speed*std::sin(ang);
      if (ed.dist < 17)
        es = EnemyState::SHOOT;
      else if (ed.dist > 200 || plane_hiding)
        es = EnemyState::PATROL;
      break;
    }
    case EnemyState::SHOOT:
    {
#ifdef DEBUG_ENEMY
      if (ed.id == sel_id)
        sh.write_buffer("SHOOT", 2, 5, Text::Color::Green);
#endif
      // Shoot at plane.
      const float shot_speed = 1.f;
      if (ed.time_shooting == 0 || ed.shot_hit || ed.shot_timeout == 0)
      {
        using namespace audio;
        auto wd = SFX::generate(SFXType::LASER);
        src_fx->update_buffer(wd);
        src_fx->stop();
        src_fx->play();
        
        if (ed.shot_hit)
        {
          ed.plane_explosion_offs_x = ed.bullet_offs_x;
          ed.plane_explosion_offs_y = ed.bullet_offs_y;
          ed.plane_explosion_anim_ctr = 0;
          ed.shot_hit = false;
        }
        if (!plane_hiding)
        {
          ed.shot_timeout = 50 / shot_speed; // ft / (ft/s) -> s
          ed.x_pos_shot = 0.f;
          ed.y_pos_shot = 0.f;
          ed.shot_angle = std::atan2(ed.y_diff, ed.x_diff);
        }
      }
      else
      {
        ed.x_pos_shot -= shot_speed*std::cos(ed.shot_angle);
        ed.y_pos_shot -= shot_speed*std::sin(ed.shot_angle);
        ed.bullet_offs_x = enemy_half_len + ed.x_pos + ed.x_pos_shot - x_pos_plane;
        ed.bullet_offs_y = (ed.y_pos + 1) + ed.y_pos_shot - y_pos_plane;
        if (std::any_of(plane_hull.begin(), plane_hull.end(),
             [&ed](const auto& rch) { return std::get<0>(rch) == r_mid + math::roundI(ed.bullet_offs_y) && std::get<1>(rch) == c_mid + math::roundI(ed.bullet_offs_x); }))
        {
          ed.shot_hit = true;
          health--;
        }

        if (ed.shot_timeout > 0)
          ed.shot_timeout--;
      }
      ed.time_shooting++;
      if (ed.dist > 25)
        es = EnemyState::HUNT;
      else if (ed.time_shooting >= 150)
        es = EnemyState::EVADE;
      break;
    }
    case EnemyState::EVADE:
    {
#ifdef DEBUG_ENEMY
      if (ed.id == sel_id)
        sh.write_buffer("EVADE", 2, 5, Text::Color::Green);
#endif
      ed.time_shooting = 0;
      float ang = std::atan2(ed.y_diff, ed.x_diff);
      const float speed = math::clamp(0.08f*ed.dist, 0.f, 5.f);
      ed.x_pos += speed*std::cos(ang);
      ed.y_pos += speed*std::sin(ang);
      if (ed.dist > 200)
        es = EnemyState::PATROL;
      break;
    }
    case EnemyState::DESTROYED:
    {
#ifdef DEBUG_ENEMY
      if (ed.id == sel_id)
        sh.write_buffer("DESTROYED", 2, 5, Text::Color::Green);
#endif
      if (ed.y_pos - 14 < ground_level)
      {
        ed.y_acc = +5.f;
        ed.y_vel += ed.y_acc*dt;
        // Critical velocity:
        const float crit_vel = 40.f;
        if (ed.y_vel > crit_vel)
          ed.y_vel = crit_vel;
        ed.y_pos += ed.y_vel*dt;
      }
      else
        ed.y_pos = ground_level + 14;
      break;
    }
  }

#ifdef DEBUG_ENEMY
  if (ed.id == sel_id)
  {
    sh.write_buffer("X: " + std::to_string(ed.x_pos), 3, 5, Text::Color::Black);
    sh.write_buffer("Y: " + std::to_string(ed.y_pos), 4, 5, Text::Color::Black);
    sh.write_buffer("XP: " + std::to_string(x_pos_plane), 5, 5, Text::Color::Black);
    sh.write_buffer("YP: " + std::to_string(y_pos_plane), 6, 5, Text::Color::Black);
    sh.write_buffer("D: " + std::to_string(ed.dist), 7, 5, Text::Color::Black);
    sh.write_buffer("E-R: " + std::to_string(r_mid + math::roundI(ed.y_pos - y_pos_plane)), 8, 5, Text::Color::Black);
    sh.write_buffer("E-C: " + std::to_string(c_mid + math::roundI(ed.x_pos - x_pos_plane)), 9, 5, Text::Color::Black);
    sh.write_buffer("XV: " + std::to_string(ed.x_vel), 10, 5, Text::Color::Black);
    sh.write_buffer("YV: " + std::to_string(ed.y_vel), 11, 5, Text::Color::Black);
    sh.write_buffer("XA: " + std::to_string(ed.x_acc), 12, 5, Text::Color::Black);
    sh.write_buffer("YA: " + std::to_string(ed.y_acc), 13, 5, Text::Color::Black);
    sh.write_buffer("S-X: " + std::to_string(ed.x_pos_shot), 14, 5, Text::Color::Black);
    sh.write_buffer("S-Y: " + std::to_string(ed.y_pos_shot), 15, 5, Text::Color::Black);
    //sh.write_buffer("TS: " + std::to_string(ed.time_shooting), 14, 5, Text::Color::Black);
    //sh.write_buffer("SH: " + std::to_string(ed.shot_hit), 15, 5, Text::Color::Black);
    //sh.write_buffer("ST: " + std::to_string(ed.shot_timeout), 16, 5, Text::Color::Black);
    sh.write_buffer("S-R: " + std::to_string(r_mid + math::roundI(ed.bullet_offs_y)), 16, 5, Text::Color::Black);
    sh.write_buffer("S-C: " + std::to_string(c_mid + math::roundI(ed.bullet_offs_x)), 17, 5, Text::Color::Black);
    sh.write_buffer("S-A: " + std::to_string(ed.shot_angle*180.f/math::c_pi), 18, 5, Text::Color::Black);
    sh.write_buffer("PS-R: " + std::to_string(plane_shot_r), 19, 5, Text::Color::Black);
    sh.write_buffer("PS-C: " + std::to_string(plane_shot_c), 20, 5, Text::Color::Black);
  }
#endif

  return ed;
}

//    _
// <oOOOo>
template<int NR, int NC>
void draw_enemy(SpriteHandler<NR, NC>& sh, int r, int r0, int c, bool destroyed, int anim_ctr)
{
  //std::string sprite_part;
  //Text::Color sprite_part_color;
  int anim1 = anim_ctr % 6;
  int anim2 = (anim_ctr + 3) % 6;

  int dr = r - r0;

  switch (dr)
  {
    case 0:
      if (anim1 < 5 && !destroyed)
        sh.write_buffer("_", r, c+1+anim1, Text::Color::Cyan, Text::Color::Transparent2);
      break;
    case 1:
      if (anim2 > 0 && !destroyed)
      {
        std::string window = (anim2 == 1 || anim2 == 5) ? "o" : "O";
        sh.write_buffer(window, r, c+anim2, Text::Color::Magenta, Text::Color::Transparent2);
      }
      sh.write_buffer("<", r, c, destroyed ? Text::Color::DarkGray : Text::Color::DarkMagenta, Text::Color::Transparent2);
      sh.write_buffer("oOOOo", r, c+1, destroyed ? Text::Color::LightGray : Text::Color::DarkBlue, Text::Color::Transparent2);
      sh.write_buffer(">", r, c+6, destroyed ? Text::Color::DarkGray : Text::Color::DarkMagenta, Text::Color::Transparent2);
      break;
  }
}

template<int NR, int NC>
void draw_enemy_shadow(SpriteHandler<NR, NC>& sh, float dist, int r_plane, int c_plane, float x_diff, float y_diff, EnemyState es, int anim_ctr)
{
  int r = r_plane + math::roundI(y_diff) + 1;
  int c = c_plane + math::roundI(x_diff) + 3;
  bool r_inside = false;
  bool c_inside = false;
  int anim = anim_ctr % 2;

  if (r < 1)
    r = 1;
  else if (r > 28)
    r = 28;
  else
    r_inside = true;

  if (c < 1)
    c = 1;
  else if (c > 78)
    c = 78;
  else
    c_inside = true;

  if (r_inside && c_inside)
    return;

  switch (es)
  {
    case EnemyState::PATROL:
    case EnemyState::EVADE:
      if (dist < 500)
        sh.write_buffer("o", r, c, es == EnemyState::EVADE ? Text::Color::Cyan : Text::Color::Black);
      else
        sh.write_buffer(".", r, c, es == EnemyState::EVADE ? Text::Color::Cyan : Text::Color::Black);
      break;
    case EnemyState::HUNT:
      sh.write_buffer(anim == 0 ? "o" : ".", r, c, anim == 0 ? Text::Color::Red : Text::Color::Black);
      break;
    case EnemyState::SHOOT:
      sh.write_buffer("o", r, c, Text::Color::DarkRed);
      break;
    default:
      break;
  }
}

template<int NR, int NC>
void draw_enemy_shot(SpriteHandler<NR, NC>& sh, EnemyData& ed)
{
  if (ed.state == EnemyState::SHOOT)
    draw_shot(sh, ed.shot_hit, ed.shot_angle, ed.bullet_offs_x, ed.bullet_offs_y, Text::Color::Cyan);
}
