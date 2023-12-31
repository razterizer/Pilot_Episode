#pragma once

const int max_health = 30;//15;
int health = max_health;
int score = 0;
int num_enemies_shot_down = 0;
bool show_title = true;
bool show_instructions = false;
// Misc
const float pix_to_ft = 36.0833f/11.f; // 1 character width to feet.
const float pix_to_m = 11.f/11.f; // 36.0833 ft ~= 11m.
const int r_mid = 12;
const int c_mid = 32;
const float plane_half_len = 5.5f;
const float plane_half_len_2 = 5.f;
const float cloud_limit = 4000.f;
const float ground_level = 5000.f;
const int alt_soft_limit_ft = 40'000;
const int alt_hard_limit_ft = 51'000;
bool enable_alt_hard_limit = true;
