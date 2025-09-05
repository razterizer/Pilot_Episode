#pragma once


template<int NR, int NC>
void draw_hud(t8::screen::ScreenHandler<NR, NC>& sh,
              float ground_level,
              int health, int max_health,
              int score)
{
  using Color = t8::Color;

  int hud_c = 1;
  if (health < 0)
    health = 0;
  std::string health_char = "h";
  switch (health % 3)
  {
    case 2: health_char = "*"; break;
    case 1: health_char = "o"; break;
    case 0: health_char = ""; break;
  }
  std::string life_str = "H: ["
    + str::rep_char('#', static_cast<int>(std::floor(health/3.f)))
    + health_char
    + str::rep_char(' ', static_cast<int>(std::ceil(max_health/3.f) - std::ceil(health/3.f)))
    + "]";
  sh.write_buffer(life_str, 0, hud_c, Color::Cyan);
  //sh.write_buffer(std::to_string(health), 5, 5, Color::Black);
  hud_c += 1 + static_cast<int>(life_str.size());
  std::string alt_str = "Alt: ";
  plane_data::alt_px = ground_level - plane_data::y_pos + 13*t8::screen::pix_ar2;
  plane_data::alt_ft = std::round(plane_data::alt_px*pix_to_ft);
  plane_data::alt_km = std::round(plane_data::alt_px*pix_to_m/1e3f);
  alt_str += std::to_string(static_cast<int>(plane_data::alt_ft));
  alt_str += " ft,";
  sh.write_buffer(alt_str, 0, hud_c, Color::Cyan);
  hud_c += 1 + static_cast<int>(alt_str.size());
  std::string gnd_speed_str = "Gnd Speed: ";
  const float ftps_to_knots = 1.f/1.68780986f;
  const float pixps_to_knots = pix_to_ft*ftps_to_knots;
  gnd_speed_str += std::to_string(math::roundI(std::sqrt(math::sq(plane_data::x_vel) + math::sq(plane_data::z_vel))*pixps_to_knots));
  gnd_speed_str += " kn,";
  sh.write_buffer(gnd_speed_str, 0, hud_c, Color::Cyan);
  hud_c += 1 + static_cast<int>(gnd_speed_str.size());
  std::string speed_str = "Speed: ";
  speed_str += std::to_string(math::roundI(std::sqrt(math::sq(plane_data::x_vel) + math::sq(plane_data::y_vel) + math::sq(plane_data::z_vel))*pixps_to_knots));
  speed_str += " kn, ";
  sh.write_buffer(speed_str, 0, hud_c, Color::Cyan);
  hud_c += 1 + static_cast<int>(speed_str.size());
  std::string score_str = "Score: ";
  score_str += std::to_string(score);
  sh.write_buffer(score_str, 0, hud_c, Color::Cyan);
}
