#pragma once
#include "Enums.h"
#include "../../lib/Consolation/Screen.h"
#include "../../lib/Consolation/RC.h"
#include "../../lib/Core/StlUtils.h"
#include "../../lib/8Beat/AudioSourceHandler.h"
#include "../../lib/8Beat/WaveformGeneration.h"

#define HILITE_PLANE_SURFACES

template<int NR, int NC>
void generate_engine_smoke(SpriteHandler<NR, NC>& sh,
                    const RC& rc_plane_engine,
                    float dt, float time)
{
  //bool trig = (plane_data::blackout_state == plane_data::BlackoutState::WarnOut
  //  || plane_data::blackout_state == plane_data::BlackoutState::Stall);
  
  auto health_ratio = static_cast<float>(health) / static_cast<float>(max_health);
  const float c_health_ratio_threshold = 0.3f;
  bool trig = health_ratio <= c_health_ratio_threshold && health > 0;

  const float vel_x = -0.5f*plane_data::x_vel, vel_y = -0.8f*plane_data::y_vel;
  const float acc = -10.f, spread = 13.f, life_time = math::linmap(health_ratio, 0.f, c_health_ratio_threshold, 2.f, 0.1f);
  const int cluster_size = 10;
  plane_data::smoke_engine.update(rc_plane_engine, trig, vel_x, vel_y, acc, spread, life_time, cluster_size, dt, time);
  ColorGradient smoke_fg_0
  {
    {
      { 0.f, Text::Color::Red },
      { 0.15f, Text::Color::Yellow },
      { 0.3f, Text::Color::LightGray },
      { 0.85f, Text::Color::DarkGray },
    }
  };
  ColorGradient smoke_fg_1
  {
    {
      { 0.f, Text::Color::Red },
      { 0.1f, Text::Color::Yellow },
      { 0.25f, Text::Color::DarkGray },
      { 0.9f, Text::Color::LightGray },
    }
  };
  ColorGradient smoke_bg_0
  {
    {
      { 0.f, Text::Color::DarkRed },
      { 0.3f, Text::Color::DarkGray },
      { 0.9f, Text::Color::Black },
    }
  };
  ColorGradient smoke_bg_1
  {
    {
      { 0.f, Text::Color::DarkRed },
      { 0.2f, Text::Color::Black },
      { 0.9f, Text::Color::DarkGray },
    }
  };
  std::vector<std::pair<float, std::pair<ColorGradient, ColorGradient>>> smoke_color_gradients;
  smoke_color_gradients.emplace_back(0.5f, std::pair { smoke_fg_0, smoke_bg_0 });
  smoke_color_gradients.emplace_back(0.6f, std::pair { smoke_fg_1, smoke_bg_1 });
  std::vector<std::string> smoke_txt { "&", "*", "&", "%", "&", "@" };
  plane_data::smoke_engine.draw(sh, smoke_txt, smoke_color_gradients, time);
}

template<int NR, int NC>
void draw_plane(SpriteHandler<NR, NC>& sh,
                int r, int r0, int c,
                int anim_ctr,
                int x_mv_dir, int y_mv_dir,
                std::vector<std::tuple<int, int, bool>>& plane_hull)
{
  std::string sprite_part;
  Text::Color sprite_part_fg_color;
  Text::Color sprite_part_bg_color = Text::Color::Transparent2;
  int anim = anim_ctr % 4;

  r0 = math::clamp(r0, 2, 29 - 3);
  c = math::clamp(c, 1, 79 - 11);

  int dr = r - r0;


  int p0 = 0; // Tail
  int p1 = 0; // Wing shadow down + fuselage
  int p2 = 1; // Wing profile + motor
  int p3 = 1; // Wing shadow up + fuselage
  int p4 = 2; // Landing gear
  int pr0 = 0; // Propeller top
  int pr1 = 1; // Propeller mid
  int pr2 = 2; // Propeller bottom
  if (y_mv_dir == -1) // Plane up
  {
    p0 = 3; //0;
    p1 = 3; //0;
    p2 = 1; //1;
    p3 = 2; //2;
    p4 = 2; //3;
  }
  else if (y_mv_dir == +1) // Plane down
  {
    p0 = 0;
    p1 = 1;
    p2 = 2;
    p3 = 2;
    p4 = 3;
    pr0 = 1;
    pr1 = 2;
    pr2 = 3;
  }

  // Draw Propeller
  sprite_part_fg_color = Text::Color::Black;
  if (dr == pr0)
  {
      switch (anim)
      {
        case 0: sprite_part = "           "; break;
        case 1: sprite_part = "       /   "; break;
        case 2: sprite_part = "     :     "; break;
        case 3: sprite_part = "   \\       "; break;
      }
  }
  else if (dr == pr1)
  {
      switch (anim)
      {
        case 0: sprite_part = "  === ===  "; break;
        case 1: sprite_part = "           "; break;
        case 2: sprite_part = "           "; break;
        case 3: sprite_part = "           "; break;
      }
  }
  else if (dr == pr2)
  {
      switch (anim)
      {
        case 0: sprite_part = "           "; break;
        case 1: sprite_part = "   /       "; break;
        case 2: sprite_part = "     :     "; break;
        case 3: sprite_part = "       \\   "; break;
      }
  }
  sh.write_buffer(sprite_part, r, c, sprite_part_fg_color, sprite_part_bg_color);

  // Draw Plane
  if (dr == p0)
  {
      if (x_mv_dir == -1)
        sprite_part = "    __!__  ";
      else if (x_mv_dir == +1)
        sprite_part = "  __!__    ";
      else
        sprite_part = "   __!__   ";
      sprite_part_fg_color = Text::Color::DarkYellow;
  }
  else if (dr == p1)
  {
      sprite_part = "/----^----\\";
      sprite_part_fg_color = Text::Color::DarkYellow;
      sprite_part_bg_color = Text::Color::Red;
  }
  else if (dr == p2)
  {
      sprite_part = "-----o-----";
      sprite_part_fg_color = Text::Color::DarkYellow;
      //if (y_mv_dir != 0)
      //  sprite_part_bg_color = Text::Color::Red;
  }
  else if (dr == p3)
  {
      sprite_part = "\\____v____/";
      sprite_part_fg_color = Text::Color::DarkYellow;
      sprite_part_bg_color = Text::Color::Red;
  }
  else if (dr == p4)
  {
      if (x_mv_dir == -1)
        sprite_part = "   \" \"     ";
      else if (x_mv_dir == +1)
        sprite_part = "     \" \"   ";
      else
        sprite_part = "    \" \"    ";
      sprite_part_fg_color = Text::Color::Black;
  }
#ifndef HILITE_PLANE_SURFACES
  sprite_part_bg_color = Text::Color::Transparent2;
#endif
  sh.write_buffer(sprite_part, r, c, sprite_part_fg_color, sprite_part_bg_color);
  for (size_t i = 0; i < sprite_part.size(); ++i)
    if (sprite_part[i] != ' ')
      plane_hull.emplace_back(r, c + i, false);
}

template<int NR, int NC>
void draw_crosshair(SpriteHandler<NR, NC>& sh, float x_vel, float y_vel)
{
  float dist = std::sqrt(x_vel*x_vel + y_vel*y_vel);
  float x_vel_norm = x_vel / dist;
  float y_vel_norm = y_vel / dist;
  float len = 7.f;
  float r = r_mid + 1.f + len*y_vel_norm / pix_ar2_sq;
  float c = c_mid + plane_half_len_2 + len*x_vel_norm;

  sh.write_buffer("+", std::round(r), std::round(c), Text::Color::Black, Text::Color::Transparent2);
}


template<int NR, int NC>
void update_plane_controls(SpriteHandler<NR, NC>& sh,
                           audio::AudioStreamSource* src_fx, audio::WaveformGeneration& wave_gen,
                           const std::array<Key, 3>& arrow_key_buffer, Key curr_key,
                           float ground_level, float dt)
{
  auto it_begin = std::begin(arrow_key_buffer);
  auto it_end = std::end(arrow_key_buffer);
  bool pressing_up = false;
  if (std::any_of(it_begin, it_end, [](auto v) { return v != Key::None; }))
  {
    if (std::any_of(it_begin, it_end, [](auto v) { return v == Key::Left; }))
    {
      plane_data::x_vel -= plane_data::x_acc * dt;
      plane_data::y_vel *= 0.9f;
      sh.write_buffer("L", 2, 1, Text::Color::Cyan);
    }
    else if (std::any_of(it_begin, it_end, [](auto v) { return v == Key::Right; }))
    {
      plane_data::x_vel += plane_data::x_acc * dt;
      plane_data::y_vel *= 0.9f;
      sh.write_buffer("R", 2, 3, Text::Color::Cyan);
    }
    else if (std::any_of(it_begin, it_end, [](auto v) { return v == Key::Down; }))
    {
      plane_data::y_vel += plane_data::y_acc * dt;
      plane_data::x_vel *= 0.9f;
      sh.write_buffer("D", 3, 2, Text::Color::Cyan);
    }
    else if (std::any_of(it_begin, it_end, [](auto v) { return v == Key::Up; }))
    {
      plane_data::y_vel -= plane_data::y_acc * dt;
      plane_data::x_vel *= 0.9f;
      sh.write_buffer("U", 1, 2, Text::Color::Cyan);
      pressing_up = true;
    }
    //switch (arrow_curr)
    //{
    //  case ArrowKey::Left:  x_vel -= x_acc*dt; break;
    //  case ArrowKey::Right: x_vel += x_acc*dt; break;
    //  case ArrowKey::Down:  y_vel += y_acc*dt; break;
    //  case ArrowKey::Up:    y_vel -= y_acc*dt; break;
    //  default: break;
    //}
    //bg_color = Text::Color::Red;
  }
  else if (curr_key == Key::Fire)
  {
    sh.write_buffer("F", 2, 2, Text::Color::Cyan);
    auto duration = 0.1f;
    auto wd = wave_gen.generate_waveform(audio::WaveformType::NOISE, duration, 200.f);
    src_fx->update_buffer(wd);
    src_fx->stop();
    src_fx->play();
  }
  else
  {
    plane_data::x_vel *= 0.8f;
    plane_data::y_vel *= 0.8f;
    //bg_color = Text::Color::Blue;
    //gotorc(31, 1);
    //t.print_line("Wind break!", Text::Color::Blue, Text::Color::Black);
  }
  sh.write_buffer("L", 2, 1, Text::Color::DarkCyan);
  sh.write_buffer("R", 2, 3, Text::Color::DarkCyan);
  sh.write_buffer("U", 1, 2, Text::Color::DarkCyan);
  sh.write_buffer("D", 3, 2, Text::Color::DarkCyan);
  sh.write_buffer("F", 2, 2, Text::Color::DarkCyan);
  
  plane_data::x_mv_dir = plane_data::x_vel < -1 ? -1 : (plane_data::x_vel > 1 ? 1 : 0);
  plane_data::y_mv_dir = plane_data::y_vel < -1 ? -1 : (plane_data::y_vel > 1 ? 1 : 0);
  
  bool at_max_vel = false;
  if (std::abs(plane_data::x_vel) > plane_data::vel_max)
    plane_data::x_vel = plane_data::x_mv_dir*plane_data::vel_max;
  if (std::abs(plane_data::y_vel) > plane_data::vel_max/pix_ar2)
  {
    plane_data::y_vel = plane_data::y_mv_dir*plane_data::vel_max/pix_ar2;
    if (plane_data::y_mv_dir == -1)
      at_max_vel = true;
  }
  
  auto reset_stall_breakout_data = []()
  {
    plane_data::frame_idx = 0;
    plane_data::fix_time = 0.f;
    plane_data::fix_toggles_full = false;
    stlutils::memclr(plane_data::fix_press_toggles);
  };
  
  auto& curr_timer = plane_data::state_timer[static_cast<int>(plane_data::blackout_state)];
  const auto& curr_time = plane_data::state_time[static_cast<int>(plane_data::blackout_state)];
  curr_timer += dt;
  switch (plane_data::blackout_state)
  {
    case plane_data::BlackoutState::Normal:
      if (at_max_vel)
      {
        plane_data::blackout_state = plane_data::BlackoutState::AccUp;
        curr_timer = 0.f;
      }
      break;
      
    case plane_data::BlackoutState::AccUp:
      if (!at_max_vel)
      {
        plane_data::blackout_state = plane_data::BlackoutState::Normal;
        curr_timer = 0.f;
      }
      else if (curr_timer > curr_time)
      {
        plane_data::blackout_state = plane_data::BlackoutState::WarnIn;
        curr_timer = 0.f;
      }
      break;
      
    case plane_data::BlackoutState::WarnIn:
      if (!at_max_vel)
      {
        plane_data::blackout_state = plane_data::BlackoutState::AccUp;
        curr_timer = 0.f;
      }
      else if (curr_timer > curr_time)
      {
        plane_data::blackout_state = plane_data::BlackoutState::Blackout;
        curr_timer = 0.f;
      }
      break;
      
    case plane_data::BlackoutState::Blackout:
      plane_data::y_vel = 40.f;
      if (curr_timer > curr_time)
      {
        plane_data::blackout_state = plane_data::BlackoutState::WarnOut;
        curr_timer = 0.f;
      }
      break;
      
    case plane_data::BlackoutState::WarnOut:
      plane_data::y_vel = 43.f;
      if (curr_timer > curr_time)
      {
        plane_data::blackout_state = plane_data::BlackoutState::Stall;
        curr_timer = 0.f;
      }
      break;
      
    case plane_data::BlackoutState::Stall:
      plane_data::y_vel = plane_data::vel_max_stall;
      if (curr_timer > curr_time)
      {
        plane_data::blackout_state = plane_data::BlackoutState::Normal;
        curr_timer = 0.f;
        reset_stall_breakout_data();
      }
      else
      {
        // Stall breakout / recovery by pressing rapidly on the 'F' key.
        plane_data::fix_prev = plane_data::fix_curr;
        plane_data::fix_curr = curr_key == Key::Fix;
        plane_data::fix_press_toggles[plane_data::frame_idx] = !plane_data::fix_curr && plane_data::fix_prev;
        plane_data::frame_idx++;
        if (plane_data::frame_idx == plane_data::fix_press_toggles.size())
        {
          plane_data::frame_idx = 0;
          plane_data::fix_toggles_full = true;
        }
        else if (!plane_data::fix_toggles_full)
          plane_data::fix_time += dt;
          
        auto num_fix_toggles = static_cast<float>(stlutils::count(plane_data::fix_press_toggles, true));
        auto fix_toggle_rate = num_fix_toggles / plane_data::fix_time;
        if (plane_data::fix_time > 0.f && fix_toggle_rate >= 9.f)
        {
          plane_data::blackout_state = plane_data::BlackoutState::Normal;
          curr_timer = 0.f;
          reset_stall_breakout_data();
        }
      }
      break;
      
    default:
      break;
  }
    
  plane_data::x_pos += plane_data::x_vel*dt;
  plane_data::y_pos += plane_data::y_vel*dt;
  if (plane_data::y_pos > ground_level)
  {
    plane_data::y_pos = ground_level;
    if (plane_data::y_vel == plane_data::vel_max_stall)
      health = 0; // Crash.
  }
  if (enable_alt_limiting && plane_data::alt_ft > alt_hard_limit_ft)
    plane_data::y_pos = -(alt_hard_limit_ft/pix_to_ft - ground_level - 13*pix_ar2);
}

