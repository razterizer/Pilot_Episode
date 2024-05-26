#pragma once
#include "../../lib/8Beat/AudioSourceHandler.h"
#include "../../lib/8Beat/SFX.h"

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
void draw_explosion(SpriteHandler<NR, NC>& sh, int r, int c, int anim_ctr,
                    audio::AudioStreamSource* src_fx, int expl_sound)
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
  
  if (anim == 0)
  {
    std::vector<float> expl_vp0
    {
      -1.36078f,
      -2.22594f,
      4.52445f,
      2.636f,
      1.97753f,
      2.f,
      0.00193936f,
      0.526815f,
      8.30892f,
      -0.53865f,
      -0.132234f,
      0.89504f,
      4.67884f,
      3.51095f,
      2.70944f,
      2.76928f,
      -0.434103f,
    };
    
    std::vector<float> expl_vp1 {};
    
    std::vector<float> expl_vp2
    {
      -0.777552f,
      -1.00924f,
      3.40398f,
      0.067906f,
      -0.444851f,
      2.f,
      0.560787f,
      2.26548f,
      5.96504f,
      0.144174f,
      0.191719f,
      1.34737f,
      0.796388f,
      3.30658f,
      1.10791f,
      0.0112125f,
      -0.395439f,
    };
    
    std::vector<float> &expl_vp = expl_vp0;
    if (expl_sound == 1)
      expl_vp = expl_vp1;
    else if (expl_sound == 2)
      expl_vp = expl_vp2;
    
    using namespace audio;
    auto wd = SFX::generate(SFXType::EXPLOSION, expl_vp);
    src_fx->update_buffer(wd);
    src_fx->stop();
    src_fx->play();
  }
}
