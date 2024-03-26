#pragma once
#include "PlaneData.h"
#include "../../lib/Core/Rand.h"


namespace ground
{
  const auto fg_color_grass = Text::Color::Green;
  const auto bg_color_grass = Text::Color::DarkGreen;
  const auto fg_color_lake = Text::Color::Blue;
  const auto bg_color_lake = Text::Color::DarkBlue;
  const auto fg_color_sand = Text::Color::Yellow;
  const auto bg_color_sand = Text::Color::DarkYellow;
  const auto fg_color_canopy = Text::Color::Green;
  const auto bg_color_canopy = Text::Color::DarkGreen;
  const auto fg_color_trunk = Text::Color::DarkYellow;
  const auto fg_def = Text::Color::Default;
  const auto bg_def = Text::Color::Transparent2;
  using LineData = std::tuple<std::string, Text::Color, Text::Color>;
  std::vector<std::array<LineData, 3>> line_type_data_ground // 4 .. 0
  {
    { LineData { "", fg_def, bg_def }, { "", fg_def, bg_def }, { "^", fg_color_canopy, bg_color_canopy } },
    { LineData { "", fg_def, bg_def }, { "^", fg_color_canopy, bg_color_canopy }, { "^", fg_color_canopy, bg_color_canopy } },
    { LineData { "", fg_def, bg_def }, { "^", fg_color_canopy, bg_color_canopy }, { "|", fg_color_trunk, bg_def } },
    { LineData { "", fg_def, bg_def }, { "|", fg_color_trunk, bg_def }, { "|", fg_color_trunk, bg_def } },
    { LineData { "#", fg_color_grass, bg_color_grass }, { "~", fg_color_lake, bg_color_lake }, { ":", fg_color_sand, bg_color_sand } },
  };
  std::vector<std::array<LineData, 1>> line_type_data_house // 4 .. 1
  {
    { LineData { "", fg_def, bg_def } },
    { LineData { "/ \\", Text::Color::Yellow, Text::Color::DarkYellow } },
    { LineData { "###", Text::Color::Red, Text::Color::DarkRed } },
    { LineData { "###", Text::Color::Red, Text::Color::DarkRed } }
  };
  std::vector<std::array<LineData, 1>> line_type_data_boat // 4 .. 1
  {
    { LineData { "\\===/", Text::Color::White, Text::Color::DarkGray } }
  };
  
  struct GroundData
  {
    static const int N_gnd = 4000;
    std::array<int, N_gnd> ground_data;
    std::array<int, N_gnd> tree_data;
    std::array<int, N_gnd> house_data;
    std::array<int, N_gnd> boat_data;
  
    GroundData()
    {
      ground_data.fill(0);
      tree_data.fill(0);
      house_data.fill(0);
      boat_data.fill(0);
  
      //int N_gnd = static_cast<int>(ground_data.size());
      for (size_t lake_idx = 0; lake_idx < 30; ++lake_idx)
      {
        auto lake_start_idx = math::roundI(math::lerp(rnd::rand(), 0, N_gnd - 1));
        auto lake_end_idx = lake_start_idx + math::roundI(math::lerp(rnd::rand(), 10, 150));
        lake_end_idx = std::min(lake_end_idx, N_gnd - 1);
        for (int gd_idx = lake_start_idx; gd_idx <= lake_end_idx; ++gd_idx)
          ground_data[gd_idx] = 1;
      }
      for (size_t sand_idx = 0; sand_idx < 7; ++sand_idx)
      {
        auto sand_start_idx = math::roundI(math::lerp(rnd::rand(), 0, N_gnd - 1));
        auto sand_end_idx = sand_start_idx + math::roundI(math::lerp(rnd::rand(), 2, 50));
        sand_end_idx = std::min(sand_end_idx, N_gnd - 1);
        for (int gd_idx = sand_start_idx; gd_idx <= sand_end_idx; ++gd_idx)
          ground_data[gd_idx] = 2;
      }
      for (int gnd_idx = 0; gnd_idx < N_gnd; ++gnd_idx)
      {
        if (ground_data[gnd_idx] == 0)
        {
          auto tree_rnd = math::roundI(10*rnd::rand());
          int tree_type = 0;
          if (tree_rnd < 3)
            tree_type = tree_rnd;
          tree_data[gnd_idx] = tree_type;
  
          auto house_rnd = math::roundI(50*rnd::rand());
          int house_type = 0;
          if (house_rnd < 2)
            house_type = house_rnd;
          house_data[gnd_idx] = house_type;
        }
        if (ground_data[gnd_idx] == 1)
        {
          auto boat_rnd = math::roundI(70*rnd::rand());
          int boat_type = 0;
          if (boat_rnd < 2)
            boat_type = boat_rnd;
          boat_data[gnd_idx] = boat_type;
        }
      }
    }

    
    template<typename Lambda, int NR, int NC>
    void process_ground(SpriteHandler<NR, NC>& sh,
                        float ground_level,
                        float x_pos, float y_pos,
                        float parallax,
                        size_t N_gnd,
                        Lambda&& pred)
    {
      auto fg_color = Text::Color::Default;
      auto bg_color = Text::Color::Transparent2;
    
      const int vertical_offs = 28;
      for (int y_offs = 4; y_offs >= 0; --y_offs)
      {
        if (ground_level - y_pos <= y_offs + 1)
        {
          const int N = static_cast<int>(N_gnd);
          int r = ground_level - y_pos + vertical_offs - y_offs;
          for (int gnd_idx = 0; gnd_idx < N; ++gnd_idx)
          {
            int c = gnd_idx - N/2 - parallax * x_pos;
            if (1 <= c && c <= 79)
            {
              fg_color = Text::Color::Default;
              bg_color = Text::Color::Transparent2;
              std::string str;
              pred(y_offs, gnd_idx, fg_color, bg_color, str);
              sh.write_buffer(str, r, c, fg_color, bg_color);
            }
          }
        }
      }
    }

    template<int NR, int NC>
    void draw_ground(SpriteHandler<NR, NC>& sh, float ground_level,
                     float x_pos, float y_pos)
    {
      const float parallax = 1.f;//1e-1f;
    
      const int vertical_offs = 28;
    
      auto format_line = [&](int y_offs, int data_idx, Text::Color& fg_color, Text::Color& bg_color, std::string& str)
      {
        auto& ld = ground::line_type_data_ground[4 - y_offs][data_idx];
        fg_color = std::get<1>(ld);
        bg_color = std::get<2>(ld);
        str = std::get<0>(ld);
      };
    
      auto format_ground_line = [&](int y_offs, int gnd_idx, Text::Color& fg_color, Text::Color& bg_color, std::string& str)
      {
        if (y_offs == 0)
          format_line(y_offs, ground_data[gnd_idx], fg_color, bg_color, str);
        else
          format_line(y_offs, tree_data[gnd_idx], fg_color, bg_color, str);
      };
    
      process_ground(sh, ground_level, x_pos, y_pos, parallax, N_gnd,
                     format_ground_line);
    
      if (ground_level - y_pos <= 1)
      {
        int r = ground_level - y_pos + vertical_offs;
        sh.write_buffer(str::rep_char('#', 78), r, 1, ground::fg_color_grass, ground::bg_color_grass);
      }
    }
    
    template<int NR, int NC>
    void draw_houses(SpriteHandler<NR, NC>& sh, float ground_level,
                     float x_pos, float y_pos)
    {
      float parallax = 1.f;
    
      auto format_line = [&](int y_offs, int data_idx, Text::Color& fg_color, Text::Color& bg_color, std::string& str)
      {
        if (data_idx == 0)
          return;
        auto& ld = ground::line_type_data_house[4 - y_offs][data_idx - 1];
        fg_color = std::get<1>(ld);
        bg_color = std::get<2>(ld);
        str = std::get<0>(ld);
      };
    
      auto format_house_line = [&](int y_offs, int gnd_idx, Text::Color& fg_color, Text::Color& bg_color, std::string& str)
      {
        if (y_offs > 0)
          format_line(y_offs, house_data[gnd_idx], fg_color, bg_color, str);
      };
    
      process_ground(sh, ground_level, x_pos, y_pos, parallax, N_gnd,
                     format_house_line);
    }
    
    // \===/
    template<int NR, int NC>
    void draw_boats(SpriteHandler<NR, NC>& sh, float ground_level,
                    float x_pos, float y_pos)
    {
      float parallax = 1.f;
    
      auto format_line = [&](int y_offs, int data_idx, Text::Color& fg_color, Text::Color& bg_color, std::string& str)
      {
        if (y_offs != 1 || data_idx == 0)
          return;
        auto& ld = ground::line_type_data_boat[0][data_idx - 1];
        fg_color = std::get<1>(ld);
        bg_color = std::get<2>(ld);
        str = std::get<0>(ld);
      };
    
      auto format_boat_line = [&](int y_offs, int gnd_idx, Text::Color& fg_color, Text::Color& bg_color, std::string& str)
      {
        if (y_offs > 0)
          format_line(y_offs, boat_data[gnd_idx], fg_color, bg_color, str);
      };
    
      process_ground(sh, ground_level, x_pos, y_pos, parallax, N_gnd,
                     format_boat_line);
    }
    
    template<int NR, int NC>
    void draw(SpriteHandler<NR, NC>& sh, float ground_level)
    {
      draw_boats(sh, ground_level, plane_data::x_pos, plane_data::y_pos);
  
      draw_houses(sh, ground_level, plane_data::x_pos, plane_data::y_pos);
  
      draw_ground(sh, ground_level, plane_data::x_pos, plane_data::y_pos);
    }
  };

}

