#pragma once

template<int NR, int NC>
void draw_shot(SpriteHandler<NR, NC>& sh, bool shot_hit, float shot_angle, float bullet_offs_x, float bullet_offs_y, Text::Color color)
{
  if (!shot_hit)
  {
    std::string bullet = "*";
    const float deg2rad = math::c_pi/180.f; // #FIXME: Use math::deg2rad() instead.
    const float ang_step = 22.5f*deg2rad;
    if (-9*ang_step < shot_angle && shot_angle <= -7*ang_step)
      bullet = "-";
    else if (-7*ang_step < shot_angle && shot_angle <= -5*ang_step)
      bullet = "\\";
    else if (-5*ang_step < shot_angle && shot_angle <= -3*ang_step)
      bullet = "|";
    else if (-3*ang_step < shot_angle && shot_angle <= -ang_step)
      bullet = "/";
    else if (-ang_step < shot_angle && shot_angle <= ang_step)
      bullet = "-";
    else if (ang_step < shot_angle && shot_angle <= 3*ang_step)
      bullet = "\\";
    else if (3*ang_step < shot_angle && shot_angle <= 5*ang_step)
      bullet = "|";
    else if (5*ang_step < shot_angle && shot_angle <= 7*ang_step)
      bullet = "/";
    else if (7*ang_step < shot_angle && shot_angle <= 9*ang_step)
      bullet = "-";
    sh.write_buffer(bullet,
        r_mid + math::roundI(bullet_offs_y),
        c_mid + math::roundI(bullet_offs_x),
        color, Text::Color::Transparent2);
  }
}

template<int NR, int NC>
void draw_explosion(SpriteHandler<NR, NC>& sh, int r, int c, int anim_ctr)
{
  sh.write_buffer("*", r, c, Text::Color::DarkRed);
  int anim = anim_ctr % 3;
  if (1 <= anim)
  {
    sh.write_buffer("<", r, c-2, Text::Color::Red, Text::Color::Transparent2);
    sh.write_buffer(">", r, c+2, Text::Color::Red, Text::Color::Transparent2);
    sh.write_buffer("^", r+1, c, Text::Color::Red, Text::Color::Transparent2);
    sh.write_buffer("v", r-1, c, Text::Color::Red, Text::Color::Transparent2);
  }
  if (2 <= anim)
  {
    sh.write_buffer("|", r, c-4, Text::Color::Yellow, Text::Color::Transparent2);
    sh.write_buffer("|", r, c+4, Text::Color::Yellow, Text::Color::Transparent2);
    sh.write_buffer("---", r+2, c-1, Text::Color::Yellow, Text::Color::Transparent2);
    sh.write_buffer("---", r-2, c-1, Text::Color::Yellow, Text::Color::Transparent2);
    sh.write_buffer("/", r-1, c-4, Text::Color::Yellow, Text::Color::Transparent2);
    sh.write_buffer("\\", r-1, c+4, Text::Color::Yellow, Text::Color::Transparent2);
    sh.write_buffer("\\", r+1, c-4, Text::Color::Yellow, Text::Color::Transparent2);
    sh.write_buffer("/", r+1, c+4, Text::Color::Yellow, Text::Color::Transparent2);
  }
}
