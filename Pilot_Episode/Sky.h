#pragma once


template<int NR, int NC>
void draw_sky(SpriteHandler<NR, NC>& sh)
{
  //if (alt_km >= 85) // End of mesosphere.
  if (plane_data::blackout_state == plane_data::BlackoutState::WarnIn
    || plane_data::blackout_state == plane_data::BlackoutState::WarnOut)
  {
    sh.replace_bg_color(Text::Color::Transparent, Text::Color::DarkRed, { 1, 1, 77, 27 });
    sh.replace_bg_color(Text::Color::Transparent2, Text::Color::DarkRed, { 1, 1, 77, 27 });
  }
  else if (plane_data::blackout_state == plane_data::BlackoutState::Stall)
  {
    sh.replace_bg_color(Text::Color::Transparent, Text::Color::DarkYellow, { 1, 1, 77, 27 });
    sh.replace_bg_color(Text::Color::Transparent2, Text::Color::DarkYellow, { 1, 1, 77, 27 });
  }
  else if (plane_data::blackout_state == plane_data::BlackoutState::Blackout)
  {
    sh.replace_fg_color(Text::Color::Black, { 1, 1, 77, 27 });
    sh.replace_bg_color(Text::Color::Black, { 1, 1, 77, 27 });
  }
  else if (plane_data::alt_ft > alt_soft_limit_ft) // A cessna can fly up to a height of 51'000 ft.
  {
    //auto t = (alt_km - 85)/(100 - 85);
    auto t = (plane_data::alt_ft - alt_soft_limit_ft)/(alt_hard_limit_ft - alt_soft_limit_ft);
    if (t > 1) t = 1;
    int h_offs = math::roundI(27*t);
    sh.replace_bg_color(Text::Color::Transparent, Text::Color::DarkBlue, { 1, 1, 77, h_offs });
    sh.replace_bg_color(Text::Color::Transparent2, Text::Color::DarkBlue, { 1, 1, 77, h_offs });
    if (plane_data::alt_km >= 100) // Kármán line.
    {
      auto t = (plane_data::alt_km - 100)/(400 - 100);
      if (t > 1) t = 1;
      int h_offs = math::roundI(27*t);
      sh.replace_bg_color(Text::Color::DarkBlue, Text::Color::Black, { 1, 1, 77, h_offs });
    }
  }
}
