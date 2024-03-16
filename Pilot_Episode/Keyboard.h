#pragma once
#include "Enums.h"
#include "../../lib/Consolation/Keyboard.h"


bool register_keypresses(Key& curr_key, int& key_ctr, int& arrow_key_ctr, std::array<Key, 3>& arrow_key_buffer, bool& paused)
{

  //int ch = getch();
  char ch = readKeystroke();
  if (ch == 'q' || ch == 'Q')
    return false;
  if (key_ctr == 0 && ch == 0x1B)
    key_ctr++;
  else if (key_ctr == 1 && ch == 0x5B)
    key_ctr++;
  else if (key_ctr == 2)
  {
    key_ctr = 0;
    switch (ch)
    {
      case 0x44: curr_key = Key::Left; break;
      case 0x43: curr_key = Key::Right; break;
      case 0x42: curr_key = Key::Down; break;
      case 0x41: curr_key = Key::Up; break;
      default: break;
    }
    arrow_key_buffer[arrow_key_ctr % 3] = curr_key;
    arrow_key_ctr++;
  }
  else if (ch == 'a' || ch == 'A')
  {
    curr_key = Key::Left;
    arrow_key_buffer[arrow_key_ctr % 3] = Key::Left;
    arrow_key_ctr++;
  }
  else if (ch == 'd' || ch == 'D')
  {
    curr_key = Key::Right;
    arrow_key_buffer[arrow_key_ctr % 3] = Key::Right;
    arrow_key_ctr++;
  }
  else if (ch == 's' || ch == 'S')
  {
    curr_key = Key::Down;
    arrow_key_buffer[arrow_key_ctr % 3] = Key::Down;
    arrow_key_ctr++;
  }
  else if (ch == 'w' || ch == 'W')
  {
    curr_key = Key::Up;
    arrow_key_buffer[arrow_key_ctr % 3] = Key::Up;
    arrow_key_ctr++;
  }
  else if (ch == ' ')
  {
    curr_key = Key::Fire;
  }
  else if (ch == 'f' || ch == 'F')
  {
    curr_key = Key::Fix;
  }
  else if (ch == 'p' || ch == 'P')
  {
     paused = !paused;
  }
  else if (ch == -1 || ch == 0)
  {
    arrow_key_buffer[arrow_key_ctr % 3] = Key::None;
    arrow_key_ctr++;
  }
  //else
  //  printf("You pressed: %i.\n", ch);

  return true;
}
