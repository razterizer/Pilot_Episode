#pragma once
#include <Termin8or/ScreenUtils.h>
#include <Termin8or/ParticleSystem.h>

namespace plane_data
{
  const float x_acc = 10.f;
  float x_vel = 0.f;
  float x_pos = 0.f;
  int x_mv_dir = 0;
  const float y_acc = x_acc/t8::screen::pix_ar2;
  float y_vel = 0.f;
  float y_pos = 0.f;
  int y_mv_dir = 0;
  const float z_vel = 20.f;
  float alt_px = 0.f;
  float alt_ft = 0.f;
  float alt_km = 0.f;
  enum class BlackoutState { Normal, AccUp, WarnIn, Blackout, WarnOut, Stall, NUM_ITEMS };
  BlackoutState blackout_state = BlackoutState::Normal;
  std::array<float, static_cast<int>(BlackoutState::NUM_ITEMS)> state_time { 0.f, 10.f, 1.f, 5.f, 0.5f, 20.f };
  std::array<float, static_cast<int>(BlackoutState::NUM_ITEMS)> state_timer { 0.f };
  const int vel_max = 50;
  const float vel_max_stall = 45.f;
  bool fix_curr = false;
  bool fix_prev = false;
  std::array<bool, 25> fix_press_toggles;
  int frame_idx = 0;
  bool fix_toggles_full = false;
  float fix_time = 0.f;
  float fix_press_rate = 0.f;
  
  t8x::physics::ParticleHandler smoke_engine(500);
}
