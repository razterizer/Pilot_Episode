#pragma once
#include "Globals.h"


struct PowerUpData
{
  float x_pos = 0.f;
  float y_pos = 0.f;
  float y_vel = 0.f;
};
template<size_t N, int NR, int NC>
void draw_update_powerup(SpriteHandler<NR, NC>& sh, std::array<PowerUpData, N>& powerups,
                         std::vector<std::tuple<int, int, bool>>& plane_hull,
                         float x_pos, float y_pos,
                         float cloud_limit, float ground_level,
                         float dt)
{
  const float y_acc = 5.f;
  auto reset_pud = [cloud_limit](PowerUpData& pud)
  {
    pud.y_pos = -cloud_limit + cloud_limit*rnd::rand();
    pud.y_vel = 0;
  };

  for (auto& pud : powerups)
  {
    pud.y_vel += dt*y_acc;
    pud.y_pos += dt*pud.y_vel;
    if (pud.y_pos > ground_level + 28)
    {
      reset_pud(pud);
    }
    // Critical velocity:
    const float crit_vel = 10.f; //40.f; Lower because of parachute!
    if (pud.y_vel > crit_vel)
      pud.y_vel = crit_vel;

    //     /^^^^^^^\
    //    (         )
    //     \v^v^v^v/
    //      \ \ / /
    //       \ Y /
    //        \|/
    //     +---+---+
    //     |   |   |
    //     +---+---+
    //     |ACM|E  |
    //     +---+---+
    float x_diff = pud.x_pos - x_pos;
    float y_diff = pud.y_pos - y_pos;
    int r = r_mid + math::roundI(y_diff);
    int c = c_mid + math::roundI(x_diff);
    sh.write_buffer("/", r+0, c+1, Text::Color::Black, Text::Color::Cyan);
    sh.write_buffer("^^^^^^^", r+0, c+1, Text::Color::Black, Text::Color::White);
    sh.write_buffer("\\", r+0, c+8, Text::Color::Black, Text::Color::Cyan);
    sh.write_buffer("(", r+1, c, Text::Color::Black, Text::Color::Cyan);
    sh.write_buffer("        ", r+1, c+1, Text::Color::Default, Text::Color::White);
    sh.write_buffer(")", r+1, c+9, Text::Color::Black, Text::Color::Cyan);
    sh.write_buffer("\\", r+2, c+1, Text::Color::Black, Text::Color::Cyan);
    sh.write_buffer("v^v^v^v", r+2, c+1, Text::Color::Black, Text::Color::White);
    sh.write_buffer("/", r+2, c+8, Text::Color::Black, Text::Color::Cyan);
    sh.write_buffer("  \\ \\ / / ", r+3, c, Text::Color::LightGray, Text::Color::Transparent2);
    sh.write_buffer("   \\ Y /  ", r+4, c, Text::Color::LightGray, Text::Color::Transparent2);
    sh.write_buffer("    \\|/     ", r+5, c, Text::Color::LightGray, Text::Color::Transparent2);
    sh.write_buffer("+---+---+", r+6, c+1, Text::Color::DarkYellow, Text::Color::DarkGreen);
    sh.write_buffer("|   |   |", r+7, c+1, Text::Color::DarkYellow, Text::Color::DarkGreen);
    sh.write_buffer("+---+---+", r+8, c+1, Text::Color::DarkYellow, Text::Color::DarkGreen);
    sh.write_buffer("|", r+9, c+1, Text::Color::DarkYellow, Text::Color::DarkGreen);
    sh.write_buffer("ACM", r+9, c+2, Text::Color::Green, Text::Color::DarkGreen);
    sh.write_buffer("|", r+9, c+5, Text::Color::DarkYellow, Text::Color::DarkGreen);
    sh.write_buffer("E", r+9, c+6, Text::Color::Green, Text::Color::DarkGreen);
    sh.write_buffer("  |", r+9, c+7, Text::Color::DarkYellow, Text::Color::DarkGreen);
    sh.write_buffer("+---+---+", r+10, c+1, Text::Color::DarkYellow, Text::Color::DarkGreen);

    int plane_r_min = INT_MAX;
    int plane_r_max = -INT_MAX;
    int plane_c_min = INT_MAX;
    int plane_c_max = -INT_MAX;
    for (const auto& rch : plane_hull)
    {
      auto [pr, pc, _] = rch;
      if (pr < plane_r_min)
        plane_r_min = pr;
      else if (pr > plane_r_max)
        plane_r_max = pr;
      if (pc < plane_c_min)
        plane_c_min = pc;
      else if (pc > plane_c_max)
        plane_c_max = pc;
    }
    if (health > 0)
    {
      if (r+6 <= plane_r_max && plane_r_min <= r+10
          && c+1 <= plane_c_max && plane_c_min <= c+9)
      {
        reset_pud(pud);
        health += 5;
        if (health > max_health)
          health = max_health;
      }
    }
  }
}

