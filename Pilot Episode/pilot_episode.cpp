// Pilot Episode - author: Rasmus Anthin

#include "Clouds.h"
#include "Seagulls.h"
#include "Powerups.h"
#include "Globals.h"
#include "PlaneData.h"
#include "Plane.h"
#include "Enemy.h"
#include "Mountains.h"
#include "HotAirBalloons.h"
#include "Sun.h"
#include "Ground.h"
#include "Keyboard.h"
#include "TitleScreen.h"
#include "InstructionsScreen.h"
#include "Hud.h"
#include "Sky.h"
#include "../../lib/Terminal Text Lib/Screen.h"
#include "../../lib/Terminal Text Lib/SpriteHandler.h"
#include "../../lib/Terminal Text Lib/Delay.h"
#include "../../lib/Terminal Text Lib/GameEngine.h"
#include "../../lib/8-Bit Audio Emulator Lib/AudioSourceHandler.h"
#include "../../lib/8-Bit Audio Emulator Lib/ChipTuneEngine.h"
#include "../../lib/Core Lib/Math.h"
//#include <cstdlib>
#include <iostream>
//#include <unistd.h>
//#include <ncurses.h>
//#include <SDL2/SDL.h>
//#include <termios.h>

// TODO:
// --1. Seagulls.--
// --2. Hide from enemies in the clouds.--
// 3. Proper keyboard controller (definition of done?...).
// 4. Can we avoid flooding the terminal screen buffer and instead always draw from the true first row?
// --5. Fix buggy shooting.--
// --6. Plane should be able to shoot the enemies as well.--
// 7. Enemies should try to track the plane (speed?) while in SHOOT-mode.
// --8. Add score to HUD.--
// --9. Add title screen.--
// --10. Sort enemy "shadows" by size (i.e. distances to enemies).--
// --11. Update score as enemies are being successfully shot down.--
// --12. Lose health when flying through a flock of birds.--
// --13. Should be possible to shoot down birds (minus points).--
// 14. Should be possible to outrun an enemy.
// --15. Background should be darker when getting close to space.--
// 16. Stop the plane from going outside of the cloud box.
// --17. 0-based drawing.--
// --18. Fix bug that causes birds to be shot only by touching them with the plane.--
// --19. Adjust length scale. Cessna has a wing span of 36'1'' = 36.0833...' ~= 11 m, thus a charachter should be about 36.08'/11 wide.--
// --20. Add winning screen.--
//?--21. Fix bug that seems to kill an enemy if passing it. It might be the plane bullet that is buggy again.--
// 22. Fix bug that causes UFO to fall up in some cases (when waiting in cloud).
// --23. Ability to hide behind multiple clouds at the same time. Maybe just check the buffer directly? Maybe use a bool-array mapped by plane_hull?--
// --24. Add ability to pick up first aid kits to increase health. Maybe falling ones with parachutes.--
// --25. Add crosshair to show which direction the plane is going to shoot.--
// --26. Be able to pause the game.--
// --27. Draw mountains.--
// --28. Fix bug that seems to cause the plane bullets not to reset properly after it times out.--
//x 29. Add minimum delay between firings from enemy so that you don't get shot down so fast when they are close to the plane.x
// 30. Shots sometimes go straight through the enemy vessel without killing it.
// --31. Plane should have the same bg-color as the object it passes over. Same with powerups, enemies and seagulls.--
// --32. Enable instant refire only for plane and make shooting time longer again. This gives some edge over the enemy. --
// --33. Fix so that powerup crates and birds have the proper minimum height before being respawned or inactivated.--
// --34. Create mountain contour.--
// --35. Draw lakes.--
// --36. Draw hot air balloon (easter egg).--
//? 37. Clouds should not be located close to the ground.
//? 38. Add upper limit to clouds? Cumulus clouds are below 2 km.
// --39. Add trees on ground and on mountains.--
// --40. Fix parallaxes (mainly make parallaxes near ground logical).--
// --41. Houses, boats, cars.--
// 42. Far away balloons on the horizon.
// --43. Do not require 100% of the plane to be in the clouds in order to be hidden.--
// --44. There seems to be a bug that causes the plane speed to jump from maximum at about 100 kn to about 50 kn.--
// --45. Plane can be resurrected in the game-over screen if the plane is hit by a power-up crate.--
// 46. We need a more accurate cross-hair control.
// 47. Maybe have a larger delay between shots triggered by an UFO.
// 48. Perhaps make it a bit easier to pursuit an UFO?
// 49. Add sailboats as well?
// --50. Let the pilot get a blackout if climbing for too long and too fast, then stalling and falling for 1000 feet or so and if too close to the ground, then crash.--
// --51. Add smoke when plane is very damaged. Re-use the particle system from LapSim Lite.--
// --52. Perhaps include a message "Press space-bar to continue..." at the bottom of the title screen to let users understand how to continue to the next screen.--
// --53. Eventually remove the info: "Be aware! The controls are a bit wonky so be careful of pressing a key too long!".--
// 54. Make the "PAUSED"-message less fast. Maybe delay-based rather than FPS-bound.
// --55. Fix transparency issue between plane and sky at high altitudes.--
// 56. Fix so that arrow keys work on Windows.
// 57. Arrow keys make the simulation go faster than ASDW keys. Investigate and fix! Maybe related to (3).
// --58. Too difficult to find any small hot air balloons, let alone the big ones. Are they really put in the right place at all?--
// --59. Be able to disable altitude limiting.--

///////////////////////////////

class Game : public GameEngine<>
{
public:
  Game(int argc, char** argv)
  {
  #ifndef _WIN32
    fps = 20;
    delay = 60'000;
  #endif
    //if (argc >= 2)
    //  delay = atoi(argv[1]);
    //dt = static_cast<float>(delay) / 1e6f;
    if (argc >= 2)
      fps = atoi(argv[1]);
    //dt = 1.f / static_cast<float>(fps);
    dt = static_cast<float>(delay) / 1e6f;

    auto set_alt = [&]() -> float { return -alt_km_f * 1e3 / pix_to_m + ground_level + 13 * pix_ar2; };
    plane_data::y_pos = set_alt();
    if (argc >= 3)
    {
      alt_km_f = atof(argv[2]);
      plane_data::y_pos = set_alt();
    }
    
    if (argc >= 4)
    {
      if (strcmp(argv[3], "off") == 0)
        enable_alt_limiting = false;
    }
  }

  virtual void generate_data() override
  {
    // Mountain Range
    generate_mountain_range(mountain_data::mountain_range_height_fields, cloud_limit);

    // Hot Air Balloon
    for (size_t i = 0; i < balloon_rc.size(); ++i)
      balloon_rc[i] = { clouds::rnd_cloud_pos(), clouds::rnd_cloud_pos() };
    for (size_t i = 0; i < balloon_small_rc.size(); ++i)
      balloon_small_rc[i] = { rnd::randn(ground_level - 60, 10.f), clouds::rnd_cloud_pos() };

    // Seagulls
    for (size_t i = 0; i < seagull_flocks.size(); ++i)
    {
      auto& flock = seagull_flocks[i];
      size_t num_birds = std::round(rnd::rand() * 15);
      flock.seagulls.resize(num_birds);
      flock.x_pos = clouds::rnd_cloud_pos();
      flock.y_pos = clouds::rnd_seagull_height();
      flock.x_vel = (rnd::rand() - 0.5f) * 30.f;
      for (size_t j = 0; j < num_birds; ++j)
      {
        auto& bird = flock.seagulls[j];
        bird.x_rel_pos = rnd::rand() * 20;
        bird.y_rel_pos = rnd::rand() * 7;
        bird.type = std::round(rnd::rand());
        bird.anim_offset = std::round(rnd::rand() * 3);
      }
    }

    // Powerups
    for (size_t i = 0; i < powerups.size(); ++i)
    {
      auto& pud = powerups[i];
      pud.x_pos = clouds::rnd_cloud_pos();
      pud.y_pos = clouds::rnd_cloud_pos();
    }

    // Enemies
    for (size_t i = 0; i < enemies_data.size(); ++i)
      enemies_data[i] = EnemyData { clouds::rnd_cloud_pos(), clouds::rnd_seagull_height() };
    // #HACK
    //enemies_data[0].x_pos = 20;
    //enemies_data[0].y_pos = y_pos;
    
    try
    {
      if (chip_tune.load_tune("../../sound_test/sound_test/chiptune2.txt"))
      {
          //chip_tune.play_tune();
          chip_tune.play_tune_async();
          chip_tune.wait_for_completion();
      }
    }
    catch (const std::exception& e)
    {
      std::cerr << "Caught exception: " << e.what() << std::endl;
    }
  }
  
  float get_alt_km() const { return alt_km_f; }

private:

  virtual bool update() override
  {
    if (show_title)
      bg_color = Text::Color::Blue;
    else if (show_instructions)
      bg_color = Text::Color::Black;
    else
      bg_color = Text::Color::Blue;

    Key curr_key = Key::None;

    if (!register_keypresses(curr_key, key_ctr, arrow_key_ctr, arrow_key_buffer, paused))
    {
      chip_tune.stop_tune_async();
      return false;
    }

    if (show_title)
    {
      draw_title(sh);
      if (curr_key == Key::Fire)
      {
        show_title = false;
        show_instructions = true;
      }
    }
    else if (show_instructions)
    {
      draw_instructions(sh);
      if (curr_key == Key::Fire)
        show_instructions = false;
    }
    else if (paused)
      draw_paused(sh, anim_ctr);
    else
    {
      update_plane_controls(sh, arrow_key_buffer, curr_key, ground_level, dt);

      draw_hud(sh, ground_level, health, max_health, score);

      draw_frame(sh, Text::Color::DarkBlue);

      if (health < 0)
        health = 0;

      if (health == 0)
      {
        if (game_over_timer == 0)
          draw_game_over(sh);
        else
          game_over_timer--;
      }
      else if (num_enemies_shot_down == enemies_data.size())
      {
        if (you_won_timer == 0)
          draw_you_won(sh);
        else
          you_won_timer--;
      }

      for (size_t e_idx = 0; e_idx < enemies_data.size(); ++e_idx)
      {
        auto& edi = enemies_data[e_idx];
        edi = enemy_step_ai(sh, edi,
          plane_data::x_pos, plane_data::y_pos, plane_data::x_vel, plane_data::y_vel,
          plane_hull, plane_hiding,
          r_mid + y_pos_shot + 1, c_mid + x_pos_shot + plane_half_len, shot_fired, shot_hit,
          anim_ctr, dt, cloud_limit, ground_level);
      }

      const float shot_speed = 1.f;
      if (shot_timeout == 0 || curr_key == Key::Fire)
      {
        x_pos_shot = 0.f;
        y_pos_shot = 0.f;
        shot_fired = false;
      }
      if (curr_key == Key::Fire)
      {
        shot_angle = std::atan2(plane_data::y_vel, plane_data::x_vel);
        x_pos_shot = 5.f * std::cos(shot_angle);
        y_pos_shot = 5.f * std::sin(shot_angle) / pix_ar2;
        shot_fired = true;
        shot_timeout = 50 / shot_speed; //  ft / (ft/s) -> s
        shot_hit = false;
      }
      else if (shot_fired && shot_timeout > 0)
      {
        x_pos_shot += shot_speed * std::cos(shot_angle);
        y_pos_shot += shot_speed * std::sin(shot_angle) / pix_ar2;
        shot_timeout--;
      }

      enemies_data_sorted = enemies_data;
      std::sort(enemies_data_sorted.begin(), enemies_data_sorted.end(),
        [](const auto& ed0, const auto& ed1) { return ed0.dist < ed1.dist; });

      for (size_t e_idx = 0; e_idx < enemies_data.size(); ++e_idx)
      {
        const auto& edi = enemies_data_sorted[e_idx];
        draw_enemy_shadow(sh, edi.dist, r_mid, c_mid,
          edi.x_pos - plane_data::x_pos,
          edi.y_pos - plane_data::y_pos,
          edi.state, anim_ctr);
      }

      plane_hiding = false;
      draw_clouds_fg(sh,
        cloud_data,
        plane_data::x_pos, plane_data::y_pos,
        plane_hull, plane_hiding);

      // #DEBUG
      //int r_offs_dbg = 10;
      //for (const auto& rch : plane_hull)
      //  sh.write_buffer(std::get<2>(rch) ? "-" : "*", std::get<0>(rch) + r_offs_dbg, std::get<1>(rch), Text::Color::Black);
      //sh.write_buffer("Plane Hiding: " + std::to_string(plane_hiding), 27, 3, Text::Color::White);

      draw_crosshair(sh, plane_data::x_vel, plane_data::y_vel);

      for (size_t e_idx = 0; e_idx < enemies_data.size(); ++e_idx)
      {
        auto& edi = enemies_data[e_idx];
        for (int r = 1; r < 29; ++r)
          draw_enemy(sh,
            r,
            r_mid + std::round(edi.y_pos - plane_data::y_pos),
            c_mid + std::round(edi.x_pos - plane_data::x_pos),
            edi.state == EnemyState::DESTROYED, anim_ctr);
        draw_enemy_shot(sh, edi);
        if (edi.plane_explosion_anim_ctr++ < edi.plane_explosion_anim_max)
          draw_explosion(sh, r_mid + std::round(edi.plane_explosion_offs_y), c_mid + std::round(edi.plane_explosion_offs_x), edi.plane_explosion_anim_ctr);
        if (edi.enemy_explosion_anim_ctr++ < edi.enemy_explosion_anim_max)
          draw_explosion(sh,
            r_mid + std::round(edi.y_pos - plane_data::y_pos) + 1,
            c_mid + std::round(edi.x_pos - plane_data::x_pos) + 2 * edi.enemy_explosion_anim_ctr / 3,
            anim_ctr);
      }

      generate_engine_smoke(sh, { r_mid + 1, c_mid + 5 }, dt, time);

      plane_hull.clear();
      for (int r = 1; r < 29; ++r)
        draw_plane(sh, r, r_mid, c_mid, anim_ctr, plane_data::x_mv_dir, plane_data::y_mv_dir, plane_hull);

      if (shot_fired)
        draw_shot(sh, shot_hit, shot_angle, x_pos_shot + plane_half_len, y_pos_shot + 1, Text::Color::Black);

      draw_update_seagull_flocks<4000>(sh,
        seagull_flocks,
        plane_data::x_pos, plane_data::y_pos,
        x_pos_shot, y_pos_shot, shot_hit, shot_fired,
        cloud_limit, ground_level,
        anim_ctr, dt);

      gnd_data.draw(sh, ground_level);

      draw_update_powerup<2000>(sh,
        powerups,
        plane_hull,
        plane_data::x_pos, plane_data::y_pos,
        cloud_limit, ground_level,
        dt);

      draw_clouds_bg(sh,
        cloud_data,
        plane_data::x_pos, plane_data::y_pos);

      draw_hot_air_balloon<20>(sh,
        balloon_rc, plane_data::x_pos, plane_data::y_pos, anim_ctr);

      draw_mountain_range(sh, mountain_data::mountain_range_height_fields,
        plane_data::x_pos, plane_data::y_pos,
        ground_level);

      draw_hot_air_balloon_small<400>(sh,
        balloon_small_rc, plane_data::x_pos, plane_data::y_pos, anim_ctr);

      draw_sun(sh, 3, 60, plane_data::x_pos);

      // Space Tests
      //sh.write_buffer("\u2591\u2592\u2593", 27, 78, Text::Color::Black);
      //sh.write_buffer("####", 25, 70, Text::Color::Blue, Text::Color::Black);
      //sh.write_buffer("####", 26, 70, Text::Color::Blue, Text::Color::Black);
      //sh.write_buffer("####", 27, 70, Text::Color::Blue, Text::Color::Black);
    }
    ///

    draw_sky(sh);

    return true;
  }

  //////////////////////////////////////////////////////////////////////////

  std::array<Key, 3> arrow_key_buffer;
  int arrow_key_ctr = 0;

  // Grass, Lakes, Sand, Trees
  ground::GroundData gnd_data;

  // Clouds
  clouds::CloudData cloud_data;

  bool plane_hiding = false;

  // Hot Air Balloon
  std::array<std::pair<int, int>, 20> balloon_rc;
  std::array<std::pair<int, int>, 400> balloon_small_rc;

  // Powerups
  std::array<PowerUpData, 2'000> powerups;

  // Seagulls
  std::array<SeagullFlockData, 4'000> seagull_flocks;

  // Enemies
  std::array<EnemyData, 200> enemies_data;
  std::array<EnemyData, 200> enemies_data_sorted;

  // Plane Hull
  std::vector<std::tuple<int, int, bool>> plane_hull; // { r, c, hiding }

  // Plane Shooting
  float x_pos_shot = 0.f;
  float y_pos_shot = 0.f;
  float shot_angle = 0.f;
  bool shot_fired = false;
  int shot_timeout = 0;
  bool shot_hit = false;
  
  float alt_km_f = 0.5f; // 14 = very high up.
  
  audio::AudioSourceHandler audio;
  audio::WaveformGeneration wave_gen;
  audio::ChipTuneEngine chip_tune { audio, wave_gen };
};

//////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{
  //initscr();
  //noecho();
  //cbreak();
  //keypad(stdscr, true);
  
  Game game(argc, argv);

  if (argc >= 2 && !strcmp(argv[1], "--help"))
  {
    std::cout << "pilot_episode (\"--help\" | [<frame-delay-us> [<altitude-km> [<altitude-limiting \"on\"|\"off\">]]])" << std::endl;
    std::cout << "  default values:" << std::endl;
    std::cout << "    <frame-delay-us>    : " << game.get_delay_us() << std::endl;
    std::cout << "    <altitude-km>       : " << game.get_alt_km() << std::endl;
    std::cout << "    <altitude-limiting> : off" << std::endl;
    return EXIT_SUCCESS;
  }

  game.init();
  game.generate_data();
  game.run();

  return EXIT_SUCCESS;
}
