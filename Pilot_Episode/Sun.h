#pragma once


template<int NR, int NC>
void draw_sun(ScreenHandler<NR, NC>& sh, int r, int c, float x_pos)
{
  const float parallax = 5e-3f;
  auto c_offs = static_cast<int>(parallax*x_pos);
  sh.write_buffer("   ", r, c + 2 + c_offs, Color::DarkYellow, Color::Yellow);
  sh.write_buffer("       ", r + 1, c + c_offs, Color::DarkYellow, Color::Yellow);
  sh.write_buffer("       ", r + 2, c + c_offs, Color::DarkYellow, Color::Yellow);
  sh.write_buffer("   ", r + 3, c + 2 + c_offs, Color::DarkYellow, Color::Yellow);
  sh.write_buffer(" ", r, c + 1 + c_offs, Color::DarkYellow, Color::Yellow);
  sh.write_buffer(" ", r, c + 5 + c_offs, Color::DarkYellow, Color::Yellow);
  sh.write_buffer(" ", r + 3, c + 1 + c_offs, Color::DarkYellow, Color::Yellow);
  sh.write_buffer(" ", r + 3, c + 5 + c_offs, Color::DarkYellow, Color::Yellow);
}

