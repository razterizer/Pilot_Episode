#pragma once


template<int NR, int NC>
void draw_sun(SpriteHandler<NR, NC>& sh, int r, int c, float x_pos)
{
  const float parallax = 5e-3f;
  sh.write_buffer("   ", r, c + 2 + parallax*x_pos, Color::DarkYellow, Color::Yellow);
  sh.write_buffer("       ", r + 1, c + parallax*x_pos, Color::DarkYellow, Color::Yellow);
  sh.write_buffer("       ", r + 2, c + parallax*x_pos, Color::DarkYellow, Color::Yellow);
  sh.write_buffer("   ", r + 3, c + 2 + parallax*x_pos, Color::DarkYellow, Color::Yellow);
  sh.write_buffer(" ", r, c + 1 + parallax*x_pos, Color::DarkYellow, Color::Yellow);
  sh.write_buffer(" ", r, c + 5 + parallax*x_pos, Color::DarkYellow, Color::Yellow);
  sh.write_buffer(" ", r + 3, c + 1 + parallax*x_pos, Color::DarkYellow, Color::Yellow);
  sh.write_buffer(" ", r + 3, c + 5 + parallax*x_pos, Color::DarkYellow, Color::Yellow);
}

