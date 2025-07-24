#pragma once
#include "Enums.h"
#include <Termin8or/Keyboard.h>


Key register_keypresses(const keyboard::KeyPressDataPair& kpdp)
{
  Key curr_special_key = Key::None;
  auto key = keyboard::get_char_key(kpdp.transient);
  auto key_held = keyboard::get_char_key(kpdp.held);
  
  if (key == ' ')
    curr_special_key = Key::Fire;
  else if (str::to_lower(key) == 'f')
    curr_special_key = Key::Fix;
  else if (str::to_lower(key_held) == 'a')
    curr_special_key = Key::Left;
  else if (str::to_lower(key_held) == 'd')
    curr_special_key = Key::Right;
  else if (str::to_lower(key_held) == 's')
    curr_special_key = Key::Down;
  else if (str::to_lower(key_held) == 'w')
    curr_special_key = Key::Up;

  return curr_special_key;
}
