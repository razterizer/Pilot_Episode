#pragma once
#include "Enums.h"
#include <Termin8or/Keyboard.h>


Key register_keypresses(const keyboard::KeyPressData& kpd)
{
  Key curr_special_key = Key::None;
  auto key = keyboard::get_char_key(kpd);
  
  if (key == ' ')
    curr_special_key = Key::Fire;
  else if (str::to_lower(key) == 'f')
    curr_special_key = Key::Fix;
  else if (str::to_lower(key) == 'a')
    curr_special_key = Key::Left;
  else if (str::to_lower(key) == 'd')
    curr_special_key = Key::Right;
  else if (str::to_lower(key) == 's')
    curr_special_key = Key::Down;
  else if (str::to_lower(key) == 'w')
    curr_special_key = Key::Up;

  return curr_special_key;
}
