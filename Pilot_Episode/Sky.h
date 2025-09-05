#pragma once


template<int NR, int NC>
void draw_sky(t8::screen::ScreenHandler<NR, NC>& sh)
{
  using Color = t8::Color;
  
  auto sky_bb = t8::Rectangle { 1, 1, 28, 78 };
  //if (alt_km >= 85) // End of mesosphere.
  if (plane_data::blackout_state == plane_data::BlackoutState::WarnIn
      || plane_data::blackout_state == plane_data::BlackoutState::WarnOut)
  {
    sh.replace_bg_color(Color::Transparent, Color::DarkRed, sky_bb);
    sh.replace_bg_color(Color::Transparent2, Color::DarkRed, sky_bb);
  }
  else if (plane_data::blackout_state == plane_data::BlackoutState::Stall)
  {
    sh.replace_bg_color(Color::Transparent, Color::DarkYellow, sky_bb);
    sh.replace_bg_color(Color::Transparent2, Color::DarkYellow, sky_bb);
  }
  else if (plane_data::blackout_state == plane_data::BlackoutState::Blackout)
  {
    sh.replace_fg_color(Color::Black, sky_bb);
    sh.replace_bg_color(Color::Black, sky_bb);
  }
  else if (plane_data::alt_ft > alt_soft_limit_ft) // A cessna can fly up to a height of 51'000 ft.
  {
    //auto t = (alt_km - 85)/(100 - 85);
    auto t = (plane_data::alt_ft - alt_soft_limit_ft)/(alt_hard_limit_ft - alt_soft_limit_ft);
    if (t > 1) t = 1;
    int h_offs = 1 + math::roundI(27*t);
    sh.replace_bg_color(Color::Transparent, Color::DarkBlue, { 1, 1, h_offs, 78 });
    sh.replace_bg_color(Color::Transparent2, Color::DarkBlue, { 1, 1, h_offs, 78 });
    if (plane_data::alt_km >= 100) // Kármán line.
    {
      auto t = (plane_data::alt_km - 100)/(400 - 100);
      if (t > 1) t = 1;
      int h_offs = 1 + math::roundI(27*t);
      sh.replace_bg_color(Color::DarkBlue, Color::Black, { 1, 1, h_offs, 78 });
    }
  }
}
