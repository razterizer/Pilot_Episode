#pragma once


template<int NR, int NC>
void draw_sky(SpriteHandler<NR, NC>& sh)
{
  auto sky_bb = ttl::Rectangle { 1, 1, 27, 77 };
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
    int h_offs = math::roundI(27*t);
    sh.replace_bg_color(Color::Transparent, Color::DarkBlue, { 1, 1, h_offs, 77 });
    sh.replace_bg_color(Color::Transparent2, Color::DarkBlue, { 1, 1, h_offs, 77 });
    if (plane_data::alt_km >= 100) // Kármán line.
    {
      auto t = (plane_data::alt_km - 100)/(400 - 100);
      if (t > 1) t = 1;
      int h_offs = math::roundI(27*t);
      sh.replace_bg_color(Color::DarkBlue, Color::Black, { 1, 1, h_offs, 77 });
    }
  }
}
