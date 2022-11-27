#pragma once


template<size_t N, int NR, int NC>
void draw_hot_air_balloon_small(SpriteHandler<NR, NC>& sh,
                                const std::array<std::pair<int, int>, N>& balloon_rc,
                                float x_pos, float y_pos, int anim_ctr)
{
  const float parallax = 0.01f;
  for (const auto& rc : balloon_rc)
  {
    auto [r, c] = rc;
    float cc = c - parallax * x_pos;
    float rr = r - parallax * y_pos;
    sh.write_buffer("_", rr, cc + 1, Text::Color::Magenta);
    sh.write_buffer("(&)", rr + 1, cc, Text::Color::Magenta, Text::Color::DarkCyan);
    sh.write_buffer("#", rr + 2, cc + 1, Text::Color::DarkYellow, Text::Color::DarkGray);
  }
}

template<size_t N, int NR, int NC>
void draw_hot_air_balloon(SpriteHandler<NR, NC>& sh,
                          const std::array<std::pair<int, int>, N>& balloon_rc,
                          float x_pos, float y_pos, int anim_ctr)
{
  const float parallax = 0.2f; //0.04f;
  for (const auto& rc : balloon_rc)
  {
    auto [r, c] = rc;
    float cc = c - parallax * x_pos;
    float rr = r - parallax * y_pos;
    sh.write_buffer(str::rep_char('.', 5), rr, cc + 8, Text::Color::Red, Text::Color::DarkRed);
    sh.write_buffer(str::rep_char('!', 13), rr + 1, cc + 4, Text::Color::Green, Text::Color::DarkBlue);
    sh.write_buffer(str::rep_char('"', 19), rr + 2, cc + 1, Text::Color::DarkCyan, Text::Color::Cyan);
    sh.write_buffer(str::rep_char('}', 21), rr + 3, cc, Text::Color::Yellow, Text::Color::Red);
    sh.write_buffer(str::rep_char('(', 21), rr + 4, cc, Text::Color::Magenta, Text::Color::DarkYellow);
    sh.write_buffer(str::rep_char(',', 19), rr + 5, cc + 1, Text::Color::Blue, Text::Color::Green);
    sh.write_buffer(str::rep_char('=', 17), rr + 6, cc + 2, Text::Color::White, Text::Color::DarkBlue);
    sh.write_buffer(str::rep_char('+', 13), rr + 7, cc + 4, Text::Color::DarkGray, Text::Color::DarkCyan);
    sh.write_buffer(str::rep_char('o', 11), rr + 8, cc + 5, Text::Color::Cyan, Text::Color::DarkRed);
    sh.write_buffer("\\", rr + 9, cc + 6, Text::Color::LightGray, Text::Color::Transparent2);
    sh.write_buffer(str::rep_char('-', 5), rr + 9, cc + 8, Text::Color::Cyan, Text::Color::DarkMagenta);
    sh.write_buffer("/", rr + 9, cc + 14, Text::Color::LightGray, Text::Color::Transparent2);
    sh.write_buffer("\\ _ /", rr + 10, cc + 8, Text::Color::LightGray, Text::Color::Transparent2);
    sh.write_buffer("| |", rr + 11, cc + 9, Text::Color::LightGray, Text::Color::Transparent2);
    sh.write_buffer("###", rr + 12, cc + 9, Text::Color::DarkYellow, Text::Color::DarkGray);
    sh.write_buffer("###", rr + 13, cc + 9, Text::Color::DarkYellow, Text::Color::DarkGray);

    int anim = anim_ctr % 40;
    auto flame_fg_color = Text::Color::Default;
    auto flame_bg_color = Text::Color::Transparent2;
    std::string flame_str = " ";
    if (anim < 17)
    {
      flame_bg_color = Text::Color::Yellow;
      flame_str = "^";
      switch (anim % 4)
      {
        case 0: flame_fg_color = Text::Color::Yellow; break;
        case 1: flame_fg_color = Text::Color::Red; break;
        case 2: flame_fg_color = Text::Color::DarkRed; break;
        case 3: flame_fg_color = Text::Color::Red; break;
      }
    }
    sh.write_buffer(flame_str, rr + 11, cc + 10, flame_fg_color, flame_bg_color);
  }
}

