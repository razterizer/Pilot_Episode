#pragma once


template<size_t N, int NR, int NC>
void draw_hot_air_balloon_small(t8::ScreenHandler<NR, NC>& sh,
                                const std::array<std::pair<int, int>, N>& balloon_rc,
                                float x_pos, float y_pos, int anim_ctr)
{
  using Color16 = t8::Color16;

  const float parallax = 0.01f;
  for (const auto& rc : balloon_rc)
  {
    auto [r, c] = rc;
    auto cc = static_cast<int>(c - parallax * x_pos);
    auto rr = static_cast<int>(r - y_pos);
    sh.write_buffer("_", rr, cc + 1, Color16::Magenta);
    sh.write_buffer("(&)", rr + 1, cc, Color16::Magenta, Color16::DarkCyan);
    sh.write_buffer("#", rr + 2, cc + 1, Color16::DarkYellow, Color16::DarkGray);
  }
}

template<size_t N, int NR, int NC>
void draw_hot_air_balloon(t8::ScreenHandler<NR, NC>& sh,
                          const std::array<std::pair<int, int>, N>& balloon_rc,
                          float x_pos, float y_pos, int anim_ctr)
{
  using Color16 = t8::Color16;
  
  const float parallax = 0.2f; //0.04f;
  for (const auto& rc : balloon_rc)
  {
    auto [r, c] = rc;
    auto cc = static_cast<int>(c - parallax * x_pos);
    auto rr = static_cast<int>(r - y_pos);
    sh.write_buffer(str::rep_char('.', 5), rr, cc + 8, Color16::Red, Color16::DarkRed);
    sh.write_buffer(str::rep_char('!', 13), rr + 1, cc + 4, Color16::Green, Color16::DarkBlue);
    sh.write_buffer(str::rep_char('"', 19), rr + 2, cc + 1, Color16::DarkCyan, Color16::Cyan);
    sh.write_buffer(str::rep_char('}', 21), rr + 3, cc, Color16::Yellow, Color16::Red);
    sh.write_buffer(str::rep_char('(', 21), rr + 4, cc, Color16::Magenta, Color16::DarkYellow);
    sh.write_buffer(str::rep_char(',', 19), rr + 5, cc + 1, Color16::Blue, Color16::Green);
    sh.write_buffer(str::rep_char('=', 17), rr + 6, cc + 2, Color16::White, Color16::DarkBlue);
    sh.write_buffer(str::rep_char('+', 13), rr + 7, cc + 4, Color16::DarkGray, Color16::DarkCyan);
    sh.write_buffer(str::rep_char('o', 11), rr + 8, cc + 5, Color16::Cyan, Color16::DarkRed);
    sh.write_buffer("\\", rr + 9, cc + 6, Color16::LightGray, Color16::Transparent2);
    sh.write_buffer(str::rep_char('-', 5), rr + 9, cc + 8, Color16::Cyan, Color16::DarkMagenta);
    sh.write_buffer("/", rr + 9, cc + 14, Color16::LightGray, Color16::Transparent2);
    sh.write_buffer("\\ _ /", rr + 10, cc + 8, Color16::LightGray, Color16::Transparent2);
    sh.write_buffer("| |", rr + 11, cc + 9, Color16::LightGray, Color16::Transparent2);
    sh.write_buffer("###", rr + 12, cc + 9, Color16::DarkYellow, Color16::DarkGray);
    sh.write_buffer("###", rr + 13, cc + 9, Color16::DarkYellow, Color16::DarkGray);

    int anim = anim_ctr % 40;
    auto flame_fg_color = Color16::Default;
    auto flame_bg_color = Color16::Transparent2;
    std::string flame_str = " ";
    if (anim < 17)
    {
      flame_bg_color = Color16::Yellow;
      flame_str = "^";
      switch (anim % 4)
      {
        case 0: flame_fg_color = Color16::Yellow; break;
        case 1: flame_fg_color = Color16::Red; break;
        case 2: flame_fg_color = Color16::DarkRed; break;
        case 3: flame_fg_color = Color16::Red; break;
      }
    }
    sh.write_buffer(flame_str, rr + 11, cc + 10, flame_fg_color, flame_bg_color);
  }
}

