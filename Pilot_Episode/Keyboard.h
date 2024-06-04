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

  return curr_special_key;
}
