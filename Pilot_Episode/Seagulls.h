#pragma once
#include "Globals.h"
#include <8Beat/AudioSourceHandler.h>


template<int NR, int NC>
void draw_seagull(ScreenHandler<NR, NC>& sh, int r, int c, int anim_ctr)
{
  switch (anim_ctr % 5)
  {
    //case 0: sh.write_buffer("M", r, c, Color::White); break;
    case 0: sh.write_buffer("/v\\", r, c-1, Color::White, Color::Transparent2); break;
    case 1: sh.write_buffer("-v-", r, c-1, Color::White, Color::Transparent2); break;
    case 2: sh.write_buffer("\\v/", r, c-1, Color::White, Color::Transparent2); break;
    case 3: sh.write_buffer("-v-", r, c-1, Color::White, Color::Transparent2); break;
    case 4: sh.write_buffer("/v\\", r, c-1, Color::White, Color::Transparent2); break;
  }
}

template<int NR, int NC>
void draw_seagull_small(ScreenHandler<NR, NC>& sh, int r, int c, int anim_ctr)
{
  switch (anim_ctr % 6)
  {
    //case 0: sh.write_buffer("M", r, c, Color::White, Color::Transparent2); break;
    case 0: sh.write_buffer("A", r, c, Color::White, Color::Transparent2); break;
    case 1: sh.write_buffer("T", r, c, Color::White, Color::Transparent2); break;
    case 2: sh.write_buffer("Y", r, c, Color::White, Color::Transparent2); break;
    case 3: sh.write_buffer("Y", r, c, Color::White, Color::Transparent2); break;
    case 4: sh.write_buffer("T", r, c, Color::White, Color::Transparent2); break;
    case 5: sh.write_buffer("A", r, c, Color::White, Color::Transparent2); break;
    //case 7: sh.write_buffer("M", r, c, Color::White, Color::Transparent2); break;
  }
}


struct SeagullData
{
  float x_rel_pos = 0.f;
  float y_rel_pos = 0.f;
  int type = 0;
  int anim_offset = 0;
  bool killed = false;
  float y_vel = 0.f;
  float flock_x_pos_killed = 0.f;
  /*const*/ int explosion_anim_ctr_max = 3;
  int explosion_anim_ctr = explosion_anim_ctr_max;
};
struct SeagullFlockData
{
  float x_pos = 0.f;
  float y_pos = 0.f;
  float x_vel = 0.f;
  std::vector<SeagullData> seagulls;
  float plane_dist = 0.f;
};


template<size_t Nf, int NR, int NC>
void draw_update_seagull_flocks(ScreenHandler<NR, NC>& sh,
                                audio::AudioStreamSource* src_fx,
                                std::array<SeagullFlockData, Nf>& seagull_flocks,
                                float x_pos, float y_pos,
                                float x_pos_shot, float y_pos_shot, bool& shot_hit, bool shot_fired,
                                float cloud_limit, float ground_level,
                                int& score,
                                int anim_ctr, std::function<int(int&)>& expl_anim_func,
                                float dt)
{
  for (auto& flock : seagull_flocks)
  {
    float flock_centre_r = 0.f;
    float flock_centre_c = 0.f;

    for (auto& bird : flock.seagulls)
    {
      int r = 4 + math::roundI(flock.y_pos + bird.y_rel_pos - y_pos);
      int c = 7 + math::roundI((bird.killed ? bird.flock_x_pos_killed : flock.x_pos) + bird.x_rel_pos - x_pos);
      flock_centre_r += r;
      flock_centre_c += c;
      int c_begin = c - 1 + bird.type;
      int c_end = c + 1 - bird.type;
      switch (bird.type)
      {
        case 0: draw_seagull(sh, r, c, (bird.killed ? 0 : anim_ctr) + bird.anim_offset); break;
        case 1: draw_seagull_small(sh, r, c, (bird.killed ? 0 : anim_ctr) + bird.anim_offset); break;
      }
      int shot_r = r_mid + math::roundI(y_pos_shot + 1);
      int shot_c = c_mid + math::roundI(x_pos_shot + plane_half_len);
      if (shot_fired && !bird.killed && r == shot_r && c_begin <= shot_c && shot_c <= c_end)
      {
        bird.killed = true;
        score -= 10;
        //shot_fired = false;
        //x_pos_shot = 0.f;
        //y_pos_shot = 0.f;
        shot_hit = true;
        bird.flock_x_pos_killed = flock.x_pos;
        bird.explosion_anim_ctr = 0;
      }
      if (bird.killed)
      {
        if (expl_anim_func(bird.explosion_anim_ctr) < bird.explosion_anim_ctr_max)
          draw_explosion(sh, r, c, bird.explosion_anim_ctr, src_fx, 2);
        if (flock.y_pos + bird.y_rel_pos - 23 < ground_level)
        {
          const float y_acc = +5.f;
          bird.y_vel += y_acc*dt;
          // Critical velocity:
          const float crit_vel = 40.f;
          if (bird.y_vel > crit_vel)
            bird.y_vel = crit_vel;
          bird.y_rel_pos += bird.y_vel*dt;
        }
        else
          bird.y_rel_pos = ground_level - flock.y_pos + 23;
      }
    }

    auto Nb = static_cast<float>(flock.seagulls.size());
    flock_centre_r /= Nb;
    flock_centre_c /= Nb;
    float r_diff = flock_centre_r - (r_mid + 1);
    float c_diff = flock_centre_c - (c_mid + plane_half_len);
    float plane_dist_sq = r_diff*r_diff + c_diff*c_diff;
    float plane_dist_prev = flock.plane_dist;
    flock.plane_dist = std::sqrt(plane_dist_sq);
    if (plane_dist_prev >= 4.f && flock.plane_dist < 4.f)
      health--;

    flock.x_pos += flock.x_vel*dt;
    if ((flock.x_pos) < -cloud_limit || (flock.x_pos) > +cloud_limit)
      flock.x_vel *= -1.f;
  }
}

