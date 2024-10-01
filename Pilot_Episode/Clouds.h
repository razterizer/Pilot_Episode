#pragma once
#include "Globals.h"
#include <Termin8or/SpriteHandler.h>
#include <Core/Math.h>
#include <Core/Rand.h>
#include <execution>


namespace clouds
{
  auto rnd_cloud_pos = []()
  {
    return rnd::rand_float(-cloud_limit, cloud_limit);
  };
  auto rnd_seagull_height = []()
  {
    return rnd::rand_float(-cloud_limit, ground_level);
  };

  struct CloudData
  {
    std::array<float, 5'000> cloud_x_pos, cloud_y_pos;
    std::array<float, 5> cloud_parallax;
    const float parallax_rate = 0.8f;
    std::array<int, 30'000> cloud_type;

    CloudData()
    {
      for (size_t i = 0; i < cloud_x_pos.size(); ++i)
      {
        cloud_x_pos[i] = rnd_cloud_pos();
        cloud_y_pos[i] = rnd_cloud_pos();
      }
      float parallax = 1.f;
      for (size_t i = 0; i < cloud_parallax.size(); ++i)
      {
        cloud_parallax[i] = parallax;
        parallax *= parallax_rate;
      }
      for (size_t i = 0; i < cloud_type.size(); ++i)
        cloud_type[i] = math::roundI(rnd::rand());
    }
  };
}

//      ~~' `_
//     '       .
//   _(     _)  )
//  ( `       '  )
//   `_'`~~=~~---'
template<int NR, int NC>
void draw_cloud(SpriteHandler<NR, NC>& sh, int r, int c,
                std::vector<std::tuple<int, int, bool>>& plane_hull)
{
  if (c < 1-14 || c > 80+14)
    return;

  if (r < 0-5 || r > 29+5)
    return;

  auto white = Color::White;
  auto light_gray = Color::LightGray;
  auto dark_gray = Color::DarkGray;
  //auto light_blue = Color::Blue;
  //auto dark_blue = Color::DarkBlue;
  auto light_cyan = Color::Cyan;
  auto dark_cyan = Color::DarkCyan;
  //auto black = Color::Black;

  auto register_cloud_line = [&plane_hull](const std::string& str, int r, int c)
  {
    for (auto& rch : plane_hull)
    {
      auto& [pr, pc, ph] = rch;
      if (pr == r && (c <= pc && pc < c + static_cast<int>(str.size())))
        ph = true;
    }
  };

  sh.write_buffer("~~'", r, c+4, white, light_cyan);
  sh.write_buffer(" ", r, c+7, light_gray, white);
  sh.write_buffer("`_", r, c+8, white, light_cyan);
  register_cloud_line("~~ `_", r, c+4);
  sh.write_buffer("'", r+1, c+3, white, light_cyan);
  sh.write_buffer("       ", r+1, c+4, light_gray, white);
  sh.write_buffer(".", r+1, c+11, white, light_cyan);
  register_cloud_line("'       .", r+1, c+3);
  sh.write_buffer("_(", r+2, c+1, white, light_cyan);
  sh.write_buffer("     ", r+2, c+3, light_gray, white);
  sh.write_buffer("_)", r+2, c+8, white, light_gray);
  sh.write_buffer("  ", r+2, c+10, light_gray, white);
  sh.write_buffer(")", r+2, c+12, white, light_cyan);
  register_cloud_line("_(     _)  )", r+2, c+1);
  sh.write_buffer("(", r+3, c, white, light_cyan);
  sh.write_buffer(" ", r+3, c+1, light_gray, white);
  sh.write_buffer("`", r+3, c+2, white, light_gray);
  sh.write_buffer("       ", r+3, c+3, light_gray, white);
  sh.write_buffer("'", r+3, c+10, white, light_gray);
  sh.write_buffer("  ", r+3, c+11, light_gray, white);
  sh.write_buffer(")", r+3, c+13, white, light_cyan);
  register_cloud_line("( `       '  )", r+3, c);
  sh.write_buffer("`", r+4, c+1, light_gray, dark_cyan);
  sh.write_buffer("_'`~~=~~---", r+4, c+2, dark_gray, light_gray);
  sh.write_buffer("'", r+4, c+13, light_gray, dark_cyan);
  register_cloud_line("`_'`~~=~~---'", r+4, c+1);
}

//     .,-.
//    (    )),.
//   ( (    ) `)_
//    '( `'   '  )__
//  (   , ('    ) -'`-.
// (   (       )'`  ') )
//  `~-~=--~~==-=~~~-~'
template<int NR, int NC>
void draw_cloud_big(SpriteHandler<NR, NC>& sh, int r, int c,
                    std::vector<std::tuple<int, int, bool>>& plane_hull)
{
  if (c < 1-21 || c > 80+21)
    return;

  if (r < 0-7 || r > 29+7)
    return;

  auto white = Color::White;
  auto light_gray = Color::LightGray;
  auto dark_gray = Color::DarkGray;
  //auto light_blue = Color::Blue;
  //auto dark_blue = Color::DarkBlue;
  auto light_cyan = Color::Cyan;
  auto dark_cyan = Color::DarkCyan;
  auto black = Color::Black;

  auto register_cloud_line = [&plane_hull](const std::string& str, int r, int c)
  {
    for (auto& rch : plane_hull)
    {
      auto& [pr, pc, ph] = rch;
      if (pr == r && (c <= pc && pc < c + static_cast<int>(str.size())))
        ph = true;
    }
  };

  // ".,-."
  sh.write_buffer(".,-.'", r, c+4, white, light_cyan);
  register_cloud_line(".,-.", r, c+4);
  // "(    )),."
  sh.write_buffer("(", r+1, c+3, white, light_cyan);
  sh.write_buffer("    ", r+1, c+4, light_gray, white);
  sh.write_buffer(")),.", r+1, c+8, white, light_cyan);
  register_cloud_line("(    )),.", r+1, c+3);
  // "( (    ) `)_"
  sh.write_buffer("(", r+2, c+2, white, light_cyan);
  sh.write_buffer(" ", r+2, c+3, light_gray, white);
  sh.write_buffer("(", r+2, c+4, white, light_gray);
  sh.write_buffer("    ", r+2, c+5, light_gray, white);
  sh.write_buffer(")", r+2, c+9, white, light_gray);
  sh.write_buffer(" ", r+2, c+10, light_gray, white);
  sh.write_buffer("`)_", r+2, c+11, white, light_cyan);
  register_cloud_line("( (    ) `)_", r+2, c+2);
  // "'( `'   '  )__"
  sh.write_buffer("'(", r+3, c+3, white, light_cyan);
  sh.write_buffer(" ", r+3, c+5, light_gray, white);
  sh.write_buffer("`'", r+3, c+6, white, light_gray);
  sh.write_buffer("   ", r+3, c+8, light_gray, white);
  sh.write_buffer("'", r+3, c+11, white, light_gray);
  sh.write_buffer("  ", r+3, c+12, light_gray, white);
  sh.write_buffer(")__", r+3, c+14, white, light_cyan);
  register_cloud_line("'( `'   '  )__", r+3, c+3);
  // "(   , ('    ) -'`-."
  sh.write_buffer("(", r+4, c+1, white, light_cyan);
  sh.write_buffer("   ", r+4, c+2, light_gray, white);
  sh.write_buffer(",", r+4, c+5, white, light_gray);
  sh.write_buffer(" ", r+4, c+6, light_gray, white);
  sh.write_buffer("('", r+4, c+7, white, light_gray);
  sh.write_buffer("    ", r+4, c+9, light_gray, white);
  sh.write_buffer(")", r+4, c+13, white, light_gray);
  sh.write_buffer(" ", r+4, c+14, light_gray, white);
  sh.write_buffer("-'`-.", r+4, c+15, white, light_cyan);
  register_cloud_line("(   , ('    ) -'`-.", r+4, c+1);
  // "(   (       )'`  ') )"
  sh.write_buffer("(", r+5, c, white, light_cyan);
  sh.write_buffer("   ", r+5, c+1, light_gray, light_gray);
  sh.write_buffer("(", r+5, c+4, dark_gray, light_gray);
  sh.write_buffer("       ", r+5, c+5, light_gray, light_gray);
  sh.write_buffer(")'`", r+5, c+12, dark_gray, light_gray);
  sh.write_buffer("  ", r+5, c+14, light_gray, light_gray);
  sh.write_buffer("')", r+5, c+16, dark_gray, light_gray);
  sh.write_buffer(" ", r+5, c+18, light_gray, light_gray);
  sh.write_buffer(")", r+5, c+19, white, light_cyan);
  register_cloud_line("(   (       )'`  ') )", r+5, c);
  // "`~-~=--~~==-=~~~-~'"
  sh.write_buffer("`", r+6, c+1, dark_gray, dark_cyan);
  sh.write_buffer("~-~=--~~==-=~~~-~", r+6, c+2, black, dark_gray);
  sh.write_buffer("'", r+6, c+19, dark_gray, dark_cyan);
  register_cloud_line("`~-~=--~~==-=~~~-~'", r+6, c+1);
}

template<int NR, int NC>
void draw_cloud_f(int cloud_type, SpriteHandler<NR, NC>& sh,
                  float cloud_x_pos, float cloud_y_pos,
                  float plane_x_pos, float plane_y_pos,
                  float parallax, float ground_level,
                  std::vector<std::tuple<int, int, bool>>& plane_hull)
{
  int r = math::roundI(cloud_y_pos - parallax*plane_y_pos);
  int c = math::roundI(cloud_x_pos - parallax*plane_x_pos);
  //if (r > ground_level - 1000) // #FIXME
  //  return;
  switch (cloud_type)
  {
    case 0: draw_cloud(sh, r, c, plane_hull); break;
    case 1:
    default: draw_cloud_big(sh, r, c, plane_hull); break;
  }
}


template<int NR, int NC>
void draw_clouds_fg(SpriteHandler<NR, NC>& sh,
                    const clouds::CloudData& cd,
                    float x_pos, float y_pos,
                    std::vector<std::tuple<int, int, bool>>& plane_hull, bool& plane_hiding)
{
  auto parallax = cd.cloud_parallax[0];
  for (int cloud_idx = 0; cloud_idx < 1000; ++cloud_idx)
  {
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 0], sh, cd.cloud_y_pos[cloud_idx], cd.cloud_x_pos[cloud_idx], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 1], sh, cd.cloud_y_pos[cloud_idx+500], cd.cloud_x_pos[cloud_idx], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 2], sh, cd.cloud_y_pos[cloud_idx], cd.cloud_x_pos[cloud_idx+500], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 3], sh, cd.cloud_x_pos[cloud_idx], cd.cloud_y_pos[cloud_idx], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 4], sh, cd.cloud_x_pos[cloud_idx+500], cd.cloud_y_pos[cloud_idx], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 5], sh, cd.cloud_x_pos[cloud_idx], cd.cloud_y_pos[cloud_idx+500], x_pos, y_pos, parallax, ground_level, plane_hull);
  }

  parallax = cd.cloud_parallax[1];
  for (int cloud_idx = 1000; cloud_idx < 2000; ++cloud_idx)
  {
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 0], sh, cd.cloud_y_pos[cloud_idx], cd.cloud_x_pos[cloud_idx], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 1], sh, cd.cloud_y_pos[cloud_idx+500], cd.cloud_x_pos[cloud_idx], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 2], sh, cd.cloud_y_pos[cloud_idx], cd.cloud_x_pos[cloud_idx+500], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 3], sh, cd.cloud_x_pos[cloud_idx], cd.cloud_y_pos[cloud_idx], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 4], sh, cd.cloud_x_pos[cloud_idx+500], cd.cloud_y_pos[cloud_idx], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 5], sh, cd.cloud_x_pos[cloud_idx], cd.cloud_y_pos[cloud_idx+500], x_pos, y_pos, parallax, ground_level, plane_hull);
  }

  parallax = cd.cloud_parallax[2];
  for (int cloud_idx = 2000; cloud_idx < 3000; ++cloud_idx)
  {
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 0], sh, cd.cloud_y_pos[cloud_idx], cd.cloud_x_pos[cloud_idx], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 1], sh, cd.cloud_y_pos[cloud_idx+500], cd.cloud_x_pos[cloud_idx], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 2], sh, cd.cloud_y_pos[cloud_idx], cd.cloud_x_pos[cloud_idx+500], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 3], sh, cd.cloud_x_pos[cloud_idx], cd.cloud_y_pos[cloud_idx], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 4], sh, cd.cloud_x_pos[cloud_idx+500], cd.cloud_y_pos[cloud_idx], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 5], sh, cd.cloud_x_pos[cloud_idx], cd.cloud_y_pos[cloud_idx+500], x_pos, y_pos, parallax, ground_level, plane_hull);
  }

  parallax = cd.cloud_parallax[3];
  for (int cloud_idx = 3000; cloud_idx < 4000; ++cloud_idx)
  {
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 0], sh, cd.cloud_y_pos[cloud_idx], cd.cloud_x_pos[cloud_idx], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 1], sh, cd.cloud_y_pos[cloud_idx-500], cd.cloud_x_pos[cloud_idx], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 2], sh, cd.cloud_y_pos[cloud_idx], cd.cloud_x_pos[cloud_idx-500], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 3], sh, cd.cloud_x_pos[cloud_idx], cd.cloud_y_pos[cloud_idx], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 4], sh, cd.cloud_x_pos[cloud_idx-500], cd.cloud_y_pos[cloud_idx], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 5], sh, cd.cloud_x_pos[cloud_idx], cd.cloud_y_pos[cloud_idx-500], x_pos, y_pos, parallax, ground_level, plane_hull);
  }

  float num_chars_hidden = std::count_if(plane_hull.begin(), plane_hull.end(), [](const auto& rch)
  {
    return std::get<2>(rch);
  });
  float num_chars_tot = plane_hull.size();
  plane_hiding = num_chars_hidden / num_chars_tot > 0.8f;
}

template<int NR, int NC>
void draw_clouds_bg(SpriteHandler<NR, NC>& sh,
                    const clouds::CloudData& cd,
                    float x_pos, float y_pos)
{
  std::vector<std::tuple<int, int, bool>> plane_hull;

  auto parallax = cd.cloud_parallax[4];
  for (int cloud_idx = 4000; cloud_idx < 5000; ++cloud_idx)
  {
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 0], sh, cd.cloud_x_pos[cloud_idx], cd.cloud_y_pos[cloud_idx], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 1], sh, cd.cloud_x_pos[cloud_idx], cd.cloud_x_pos[cloud_idx-500], x_pos, y_pos, parallax, ground_level, plane_hull);
    draw_cloud_f(cd.cloud_type[6*cloud_idx + 2], sh, cd.cloud_x_pos[cloud_idx-500], cd.cloud_y_pos[cloud_idx], x_pos, y_pos, parallax, ground_level, plane_hull);
  }
}

