#pragma once
#include "Enums.h"
#include <Termin8or/Keyboard.h>


Key register_keypresses(const keyboard::KeyPressData& kpd)
{
  Key curr_special_key = Key::None;
  if (kpd.curr_key == ' ')
  {
    curr_special_key = Key::Fire;
  }
  else if (str::to_lower(kpd.curr_key) == 'f')
  {
    curr_special_key = Key::Fix;
  }
  else if (str::to_lower(kpd.curr_key) == 'a')
    curr_special_key = Key::Left;
  else if (str::to_lower(kpd.curr_key) == 'd')
    curr_special_key = Key::Right;
  else if (str::to_lower(kpd.curr_key) == 's')
    curr_special_key = Key::Down;
  else if (str::to_lower(kpd.curr_key) == 'w')
    curr_special_key = Key::Up;

  return curr_special_key;
}
