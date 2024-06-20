#pragma once


struct MountainHFData
{
  std::vector<int> height_field;
  int c0 = 0;
  float parallax = 1.f;
  std::vector<std::vector<int>> bushes;
};

namespace mountain_data
{
  std::vector<MountainHFData> mountain_range_height_fields(100);
}


void subdivide_f(std::vector<float>& xv, std::vector<float>& yv,
                 float x0, float x1, float y0, float y1,
                 float std, float ratio, float eps)
{
  auto mid_f = [](float s0, float s1) -> float { return 0.5f * (s0 + s1); };

  auto xmid = mid_f(x0, x1);
  auto ymid = mid_f(y0, y1);
  if (x1 - x0 > eps)
  {
    ymid += std * rnd::rand(); // Supposed to be "randn()" here.
    std *= ratio;
    subdivide_f(xv, yv, x0, xmid, y0, ymid, std, ratio, eps);
    subdivide_f(xv, yv, xmid, x1, ymid, y1, std, ratio, eps);
  }
  else
  {
    xv.emplace_back(xmid);
    yv.emplace_back(ymid);
  }
}

// Inspired by https://craftofcoding.wordpress.com/2021/06/29/fractal-brownian-motion-using-random-midpoint-displacement/.
void generate_mountain_range(std::vector<MountainHFData>& mountain_range_height_fields, float cloud_limit)
{
  float h = 0.75f;
  float scale = 1.f;
  std::vector<float> xx, yy;
  int i = 2; // Each mountain is N = 64 samples wide.
  float epsilon = 0.1f/static_cast<float>(pow(2.f, i)); // (eps, N) : (0.1, 16), (0.05, 32), (0.025, 64), (0.1/2^i, 16*(1+i))

  auto fractal_f = [](std::vector<float>& xv, std::vector<float>& yv,
                      float x0, float x1, float y0, float y1,
                      float h, float scale, float eps)
  {
    float ratio = pow(2.f, -h);
    float std = scale * ratio;
    subdivide_f(xv, yv, x0, x1, y0, y1, std, ratio, eps);
  };

  auto rnd_cloud_pos = [cloud_limit]()
  {
    return rnd::rand_float(-cloud_limit, cloud_limit);
  };
  auto rnd_mountain_height = []()
  {
    return rnd::rand_float(4, 200);
  };

  float parallax = pow(0.8f, 6.f);
  for (auto& mountain_hfd : mountain_range_height_fields)
  {
    fractal_f(xx, yy, 0.f, 1.f, 0.f, 0.f, h, scale, epsilon);

    const float mountain_height = rnd_mountain_height();
    for (auto y : yy)
      mountain_hfd.height_field.emplace_back(y*mountain_height);
    mountain_hfd.c0 = static_cast<int>(rnd_cloud_pos());
    mountain_hfd.parallax = parallax;
    parallax *= 0.95f;
    
    auto N_gnd = mountain_hfd.height_field.size();
    mountain_hfd.bushes.resize(N_gnd);
    for (size_t gnd_idx = 0; gnd_idx < N_gnd; ++gnd_idx)
    {
      auto& bush_column = mountain_hfd.bushes[gnd_idx];
      int height = mountain_hfd.height_field[gnd_idx];
      bush_column.resize(height);
      for (int bush_idx = 0; bush_idx < height; ++bush_idx)
        if (rnd::rand() < 1e-3f)
          bush_column[bush_idx] = 1;
    }
  }
}

template<int NR, int NC>
void draw_mountain_range(SpriteHandler<NR, NC>& sh,
                         const std::vector<MountainHFData>& mountain_range_height_fields,
                         float x_pos, float y_pos,
                         float ground_level)
{
  for (const auto& mountain_hfd : mountain_range_height_fields)
  {
    auto bg_color = Color::LightGray;
    auto fg_color = Color::DarkGray;
    auto fg2_color = Color::DarkGray;
    bool is_far = mountain_hfd.parallax < 0.015f;
    bool is_really_far = mountain_hfd.parallax < 0.003f;
    bool is_near = false;
    auto bush_bg_color = Color::Green;
    auto bush_fg_color = Color::DarkGreen;
    if (is_really_far)
    {
      bg_color = Color::Black;
      fg_color = Color::Black;
      fg2_color = Color::Black;
    }
    else if (is_far)
    {
      bg_color = Color::DarkGray;
      fg_color = Color::Black;
    }
    else
      is_near = true;

    int N = static_cast<int>(mountain_hfd.height_field.size());
    for (int hf_idx = 0; hf_idx < N; ++hf_idx)
    {
      int c = hf_idx + mountain_hfd.c0 - math::roundI(mountain_hfd.parallax * x_pos);
      if (1 <= c && c <= 79)
      {
        int height_prev = hf_idx >= 1 ? mountain_hfd.height_field[hf_idx - 1] : -1;
        int height = mountain_hfd.height_field[hf_idx];
        int height_next = hf_idx < N - 1 ? mountain_hfd.height_field[hf_idx + 1] : -1;
        for (int h_idx = 0; h_idx < height; ++h_idx)
        {
          int r = static_cast<int>(ground_level - std::round(y_pos)) - h_idx + 28;
          if (height_prev <= h_idx)
            sh.write_buffer("/", r, c, fg_color, bg_color);
          else if (height_next <= h_idx)
            sh.write_buffer("\\", r, c, fg_color, bg_color);
          else if (is_near && mountain_hfd.bushes[hf_idx][h_idx] == 1)
            sh.write_buffer("^", r, c, bush_fg_color, bush_bg_color);
          else
            sh.write_buffer("#", r, c, fg2_color, bg_color);
        }
      }
    }
  }
}

