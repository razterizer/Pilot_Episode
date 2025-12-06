#pragma once


template<int NR, int NC>
void draw_sky(t8::ScreenHandler<NR, NC>& sh)
{
  using Color16 = t8::Color16;
  
  auto sky_bb = t8::Rectangle { 1, 1, 28, 78 };
  //if (alt_km >= 85) // End of mesosphere.
  if (plane_data::blackout_state == plane_data::BlackoutState::WarnIn
      || plane_data::blackout_state == plane_data::BlackoutState::WarnOut)
  {
    sh.replace_bg_color(Color16::Transparent, Color16::DarkRed, sky_bb);
    sh.replace_bg_color(Color16::Transparent2, Color16::DarkRed, sky_bb);
  }
  else if (plane_data::blackout_state == plane_data::BlackoutState::Stall)
  {
    sh.replace_bg_color(Color16::Transparent, Color16::DarkYellow, sky_bb);
    sh.replace_bg_color(Color16::Transparent2, Color16::DarkYellow, sky_bb);
  }
  else if (plane_data::blackout_state == plane_data::BlackoutState::Blackout)
  {
    sh.replace_fg_color(Color16::Black, sky_bb);
    sh.replace_bg_color(Color16::Black, sky_bb);
  }
  else if (plane_data::alt_ft > alt_soft_limit_ft) // A cessna can fly up to a height of 51'000 ft.
  {
    //auto t = (alt_km - 85)/(100 - 85);
    auto t = (plane_data::alt_ft - alt_soft_limit_ft)/(alt_hard_limit_ft - alt_soft_limit_ft);
    if (t > 1) t = 1;
    int h_offs = 1 + math::roundI(27*t);
    sh.replace_bg_color(Color16::Transparent, Color16::DarkBlue, { 1, 1, h_offs, 78 });
    sh.replace_bg_color(Color16::Transparent2, Color16::DarkBlue, { 1, 1, h_offs, 78 });
    if (plane_data::alt_km >= 100) // Kármán line.
    {
      auto t = (plane_data::alt_km - 100)/(400 - 100);
      if (t > 1) t = 1;
      int h_offs = 1 + math::roundI(27*t);
      sh.replace_bg_color(Color16::DarkBlue, Color16::Black, { 1, 1, h_offs, 78 });
    }
  }
}
