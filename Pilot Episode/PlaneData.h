#pragma once
#include "../../lib/Terminal Text Lib/Screen.h"

namespace plane_data
{
  const float x_acc = 10.f;
  float x_vel = 0.f;
  float x_pos = 0.f;
  int x_mv_dir = 0;
  const float y_acc = x_acc/pix_ar2;
  float y_vel = 0.f;
  float y_pos = 0.f;
  int y_mv_dir = 0;
  const float z_vel = 20.f;
  float alt_px = 0.f;
  float alt_ft = 0.f;
  float alt_km = 0.f;
}
