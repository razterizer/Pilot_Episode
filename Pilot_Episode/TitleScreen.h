#pragma once
#include <Termin8or/title/ASCII_Fonts.h>

//    000000000011111111112222222222333333333344444444445555555556666666666677777777778
//    012345678901234567890123456789012345678901234567890123456789012345678901234567890
//------------------------------------------------------------------------------------+
//00//                                                       Rasmus Anthin            |
//01//            __   ((((((                  ,######         Presents:              |
//02//                ((((((((((((((      /################                     //    |
//03//             ___,(((((((((((((((((#####////####////#####          __ ..   ///   |
//04//__. ####         .,((((((((((((((###///////####//////####.    ____ . .   ////   |
//05//    #####         ...(((((((((((###////////####////////###.              ////   |
//06// __.######\         .(############################################@@@    ////   |
//07//    ##############################################################   @@@ ////   |
//08//    ##############################################################---   @ ///   |
//09//    ##############################################################       @/(    |
//10//_ _.########################(((((((((((((((((#####################""""""  ((*   |
//11//    ###((((((############(((((((((((((((((((######################______ @///   |
//12// __..((((((###########((((((((((((((((((((########################"""""@@////   |
//13//    ((((       '===(((((((((((((((((((((#*#\#|#/#*################@@@@@  ////   |
//14//                 ((((((((((((((((((((===(=-=(*)=-=)=============         ////   |
//15//               ((((((((((((((((((((      * / | \ *               ___ . . ////   |
//16//          ___ (((((((((((((((((              |                            ///   |
//17//       __.    ((((((((((((((                 |              ___  _  . ..  //    |
//18//               (((((((((     .               |                                  |
//19//                   ,     _)  )               |                                  |
//20//    ~~' `_        (,   _)      )                 ,------.                       |
//21//   '       .        `~~~~~=---'            __A__/_)(_)(_)\_____   ___ _         |
//22// _(     _)  )                             /                    \ .___           |
//23//(  `      '  )                            \____________________/  .._ __        |
//24// `_'`~~____  _  _     ____ _____    _____ ____  _  ____  ____  ____  _____      |
//25//      /  __\/ \/ \   /  _ Y__ __\  /  __//  __\/ \/ ___\/  _ \/  _ \/  __/      |
//26//      |  \/|| || |   | / \| / \    |  \  |  \/|| ||    \| / \|| | \||  \        |
//27//      |  __/| || |_/\| \_/| | |    |  /_ |  __/| |\___ || \_/|| |_/||  /_       |
//28//      \_/   \_/\____/\____/ \_/    \____\\_/   \_/\____/\____/\____/\____\      |
//29//                                                                 (c) 2022       |
//30//--------------------------------------------------------------------------------+
template<int NR, int NC>
void draw_title(t8::ScreenHandler<NR, NC>& sh, const t8x::FontDataColl& font_data, const t8x::ColorScheme& font_colors)
{
  using Color16 = t8::Color16;

  sh.write_buffer("Rasmus Anthin", 0, 55, Color16::Black, Color16::Cyan);
  sh.write_buffer("__", 1, 12, Color16::DarkBlue);
  sh.write_buffer("((((((,", 1, 17, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer(",######", 1, 41, Color16::DarkRed, Color16::Red);
  sh.write_buffer("Presents:", 1, 57, Color16::Black, Color16::Cyan);

  sh.write_buffer("((((((((((((((", 2, 16, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("/################", 2, 36, Color16::DarkRed, Color16::Red);
  sh.write_buffer("//", 2, 74, Color16::DarkGray, Color16::LightGray);

  sh.write_buffer("___,", 3, 13, Color16::DarkBlue);
  sh.write_buffer("(((((((((((((((((", 3, 17, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("#####", 3, 34, Color16::DarkRed, Color16::Red);
  sh.write_buffer("////", 3, 39, Color16::DarkBlue);
  sh.write_buffer("####", 3, 43, Color16::DarkRed, Color16::Red);
  sh.write_buffer("//", 3, 47, Color16::DarkBlue);
  sh.write_buffer("\\", 3, 49, Color16::Cyan);
  sh.write_buffer("/", 3, 50, Color16::DarkBlue);
  sh.write_buffer("#####", 3, 51, Color16::DarkRed, Color16::Red);
  sh.write_buffer("__ ..", 3, 66, Color16::DarkBlue);
  sh.write_buffer("///", 3, 74, Color16::DarkGray, Color16::LightGray);

  sh.write_buffer("__.", 4, 0, Color16::DarkBlue);
  sh.write_buffer("####", 4, 4, Color16::DarkRed, Color16::Red);
  sh.write_buffer(".,", 4, 17, Color16::DarkBlue);
  sh.write_buffer("((((((((((((((", 4, 19, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("###", 4, 33, Color16::DarkRed, Color16::Red);
  sh.write_buffer("///", 4, 36, Color16::DarkBlue);
  sh.write_buffer("\\", 4, 39, Color16::Cyan);
  sh.write_buffer("///", 4, 40, Color16::DarkBlue);
  sh.write_buffer("####", 4, 43, Color16::DarkRed, Color16::Red);
  sh.write_buffer("///", 4, 47, Color16::DarkBlue);
  sh.write_buffer("\\", 4, 50, Color16::Cyan);
  sh.write_buffer("//", 4, 51, Color16::DarkBlue);
  sh.write_buffer("####.", 4, 53, Color16::DarkRed, Color16::Red);
  sh.write_buffer("____ . .", 4, 62, Color16::DarkBlue);
  sh.write_buffer("////", 4, 73, Color16::DarkGray, Color16::LightGray);

  sh.write_buffer("#####", 5, 4, Color16::DarkRed, Color16::Red);
  sh.write_buffer("...", 5, 18, Color16::DarkBlue);
  sh.write_buffer("(((((((((((", 5, 21, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("###", 5, 32, Color16::DarkRed, Color16::Red);
  sh.write_buffer("//", 5, 35, Color16::DarkBlue);
  sh.write_buffer("\\", 5, 37, Color16::Cyan);
  sh.write_buffer("/////", 5, 38, Color16::DarkBlue);
  sh.write_buffer("####", 5, 43, Color16::DarkRed, Color16::Red);
  sh.write_buffer("////////", 5, 47, Color16::DarkBlue);
  sh.write_buffer("###.", 5, 55, Color16::DarkRed, Color16::Red);
  sh.write_buffer("////", 5, 73, Color16::DarkGray, Color16::LightGray);

  sh.write_buffer("__.", 6, 1, Color16::DarkBlue);
  sh.write_buffer("######\\", 6, 4, Color16::DarkRed, Color16::Red);
  sh.write_buffer(".", 6, 20, Color16::DarkBlue);
  sh.write_buffer("(", 6, 21, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("############################################", 6, 22, Color16::DarkRed, Color16::Red);
  sh.write_buffer("@@@", 6, 66, Color16::Black, Color16::DarkGray);
  sh.write_buffer("////", 6, 73, Color16::DarkGray, Color16::LightGray);

  sh.write_buffer("##############################################################", 7, 4, Color16::DarkRed, Color16::Red);
  sh.write_buffer("   @@@", 7, 66, Color16::Black, Color16::DarkGray);
  sh.write_buffer("////", 7, 73, Color16::DarkGray, Color16::LightGray);

  sh.write_buffer("##############################################################", 8, 4, Color16::DarkRed, Color16::Red);
  sh.write_buffer("---   @", 8, 66, Color16::Black, Color16::DarkGray);
  sh.write_buffer("///", 8, 74, Color16::DarkGray, Color16::LightGray);

  sh.write_buffer("##############################################################", 9, 4, Color16::DarkRed, Color16::Red);
  sh.write_buffer("       @", 9, 66, Color16::Black, Color16::DarkGray);
  sh.write_buffer("/(", 9, 74, Color16::DarkGray, Color16::LightGray);

  sh.write_buffer("_ _.", 10, 0, Color16::DarkBlue);
  sh.write_buffer("########################", 10, 4, Color16::DarkRed, Color16::Red);
  sh.write_buffer("(((((((((((((((((", 10, 28, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("#####################", 10, 45, Color16::DarkRed, Color16::Red);
  sh.write_buffer("\"\"\"\"\"\"  ", 10, 66, Color16::Black, Color16::DarkGray);
  sh.write_buffer("((*", 10, 74, Color16::DarkGray, Color16::LightGray);

  sh.write_buffer("###", 11, 4, Color16::Red, Color16::DarkRed);
  sh.write_buffer("((((((", 11, 7, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("############", 11, 13, Color16::Red, Color16::DarkRed);
  sh.write_buffer("(((((((((((((((((((", 11, 25, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("######################", 11, 44, Color16::Red, Color16::DarkRed);
  sh.write_buffer("______ @", 11, 66, Color16::DarkGray, Color16::Black);
  sh.write_buffer("///", 11, 74, Color16::DarkGray, Color16::LightGray);

  sh.write_buffer("__..", 12, 1, Color16::DarkBlue);
  sh.write_buffer("((((((", 12, 5, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("###########", 12, 11, Color16::Red, Color16::DarkRed);
  sh.write_buffer("((((((((((((((((((((", 12, 22, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("########################", 12, 42, Color16::Red, Color16::DarkRed);
  sh.write_buffer("\"\"\"\"\"@@", 12, 66, Color16::DarkGray, Color16::Black);
  sh.write_buffer("////", 12, 73, Color16::DarkGray, Color16::LightGray);

  sh.write_buffer("((((", 13, 4, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("'===", 13, 15, Color16::Red, Color16::DarkRed);
  sh.write_buffer("(((((((((((((((((((((", 13, 19, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("#", 13, 40, Color16::Red, Color16::DarkRed);
  sh.write_buffer("*", 13, 41, Color16::Red, Color16::DarkYellow);
  sh.write_buffer("#", 13, 42, Color16::Red, Color16::DarkRed);
  sh.write_buffer("\\", 13, 43, Color16::Yellow, Color16::DarkYellow);
  sh.write_buffer("#", 13, 44, Color16::Red, Color16::Red);
  sh.write_buffer("|", 13, 45, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("#", 13, 46, Color16::Red, Color16::Red);
  sh.write_buffer("/", 13, 47, Color16::Yellow, Color16::DarkYellow);
  sh.write_buffer("#", 13, 48, Color16::Red, Color16::DarkRed);
  sh.write_buffer("*", 13, 49, Color16::Red, Color16::DarkYellow);
  sh.write_buffer("################", 13, 50, Color16::Red, Color16::DarkRed);
  sh.write_buffer("@@@@@", 13, 66, Color16::Black, Color16::Black);
  sh.write_buffer("////", 13, 73, Color16::DarkGray, Color16::LightGray);

  sh.write_buffer("((((((((((((((((((((", 14, 17, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("===", 14, 37, Color16::Red, Color16::DarkRed);
  sh.write_buffer("(", 14, 40, Color16::DarkRed, Color16::DarkYellow);
  sh.write_buffer("=", 14, 41, Color16::Red, Color16::DarkRed);
  sh.write_buffer("-", 14, 42, Color16::Yellow, Color16::DarkYellow);
  sh.write_buffer("=", 14, 43, Color16::Red, Color16::Red);
  sh.write_buffer("(", 14, 44, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("*", 14, 45, Color16::Cyan, Color16::Yellow);
  sh.write_buffer(")", 14, 46, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("=", 14, 47, Color16::Red, Color16::Red);
  sh.write_buffer("-", 14, 48, Color16::Yellow, Color16::DarkYellow);
  sh.write_buffer("=", 14, 49, Color16::Red, Color16::DarkRed);
  sh.write_buffer(")", 14, 50, Color16::DarkRed, Color16::DarkYellow);
  sh.write_buffer("=============", 14, 51, Color16::Red, Color16::DarkRed);
  sh.write_buffer("////", 14, 73, Color16::DarkGray, Color16::LightGray);

  sh.write_buffer("((((((((((((((((((((", 15, 15, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("*", 15, 41, Color16::Red, Color16::DarkYellow);
  sh.write_buffer("/", 15, 43, Color16::Yellow, Color16::DarkYellow);
  sh.write_buffer("|", 15, 45, Color16::Green, Color16::Yellow);
  sh.write_buffer("\\", 15, 47, Color16::Yellow, Color16::DarkYellow);
  sh.write_buffer("*", 15, 49, Color16::Red, Color16::DarkYellow);
  sh.write_buffer("___ . .", 15, 65, Color16::DarkBlue);
  sh.write_buffer("////", 15, 73, Color16::DarkGray, Color16::LightGray);

  sh.write_buffer("___", 16, 10, Color16::DarkBlue);
  sh.write_buffer("(((((((((((((((((", 16, 14, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("|", 16, 45, Color16::Green, Color16::Cyan);
  sh.write_buffer("///", 16, 74, Color16::DarkGray, Color16::LightGray);

  sh.write_buffer("__.", 17, 7, Color16::DarkBlue);
  sh.write_buffer("((((((((((((((", 17, 14, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("|", 17, 45, Color16::Green, Color16::Cyan);
  sh.write_buffer("___  _  . ..", 17, 60, Color16::DarkBlue);
  sh.write_buffer("//", 17, 74, Color16::DarkGray, Color16::LightGray);

  sh.write_buffer("(((((((((", 18, 15, Color16::DarkYellow, Color16::Yellow);
  sh.write_buffer("     ", 18, 24, Color16::LightGray, Color16::White);
  sh.write_buffer(".", 18, 29, Color16::White, Color16::Cyan);
  sh.write_buffer("|", 18, 45, Color16::Green, Color16::Cyan);

  sh.write_buffer(",", 19, 19, Color16::White, Color16::Cyan);
  sh.write_buffer("     ", 19, 20, Color16::LightGray, Color16::White);
  sh.write_buffer("_)", 19, 25, Color16::White, Color16::LightGray);
  sh.write_buffer("  ", 19, 27, Color16::LightGray, Color16::White);
  sh.write_buffer(")", 19, 29, Color16::White, Color16::Cyan);
  sh.write_buffer("|", 19, 45, Color16::Green, Color16::Cyan);

  sh.write_buffer("~~'", 20, 4, Color16::White, Color16::Cyan);
  sh.write_buffer(" ", 20, 7, Color16::LightGray, Color16::White);
  sh.write_buffer("`_", 20, 8, Color16::White, Color16::Cyan);
  sh.write_buffer("(,", 20, 18, Color16::White, Color16::Cyan);
  sh.write_buffer("   ", 20, 20, Color16::LightGray, Color16::White);
  sh.write_buffer("_)", 20, 23, Color16::White, Color16::LightGray);
  sh.write_buffer("      ", 20, 25, Color16::LightGray, Color16::White);
  sh.write_buffer(")", 20, 31, Color16::White, Color16::Cyan);
  sh.write_buffer(",------.", 20, 49, Color16::DarkMagenta, Color16::Magenta);

  sh.write_buffer("'", 21, 3, Color16::White, Color16::Cyan);
  sh.write_buffer("       ", 21, 4, Color16::LightGray, Color16::White);
  sh.write_buffer(".", 21, 11, Color16::White, Color16::Cyan);
  sh.write_buffer("`", 21, 20, Color16::LightGray, Color16::DarkCyan);
  sh.write_buffer("~~~~~=---", 21, 21, Color16::DarkGray, Color16::LightGray);
  sh.write_buffer("'", 21, 30, Color16::LightGray, Color16::DarkCyan);
  sh.write_buffer("__", 21, 43, Color16::DarkMagenta);
  sh.write_buffer("A", 21, 45, Color16::DarkMagenta, Color16::Magenta);
  sh.write_buffer("__", 21, 46, Color16::DarkMagenta);
  sh.write_buffer("/", 21, 48, Color16::DarkMagenta, Color16::Magenta);
  sh.write_buffer("_", 21, 49, Color16::DarkGray, Color16::Cyan);
  sh.write_buffer(")(", 21, 50, Color16::LightGray, Color16::DarkCyan);
  sh.write_buffer("_", 21, 52, Color16::DarkGray, Color16::Cyan);
  sh.write_buffer(")(", 21, 53, Color16::LightGray, Color16::DarkCyan);
  sh.write_buffer("_", 21, 55, Color16::DarkGray, Color16::Cyan);
  sh.write_buffer(")", 21, 56, Color16::LightGray, Color16::DarkCyan);
  sh.write_buffer("\\", 21, 57, Color16::DarkMagenta, Color16::Magenta);
  sh.write_buffer("_____", 21, 58, Color16::DarkMagenta);
  sh.write_buffer("___ _", 21, 66, Color16::DarkBlue);

  sh.write_buffer("_(", 22, 1, Color16::White, Color16::Cyan);
  sh.write_buffer("     ", 22, 3, Color16::LightGray, Color16::White);
  sh.write_buffer("_)", 22, 8, Color16::White, Color16::LightGray);
  sh.write_buffer("  ", 22, 10, Color16::LightGray, Color16::White);
  sh.write_buffer(")", 22, 12, Color16::White, Color16::Cyan);
  sh.write_buffer("/", 22, 42, Color16::DarkMagenta, Color16::Cyan);
  sh.write_buffer("  ________________  ", 22, 43, Color16::DarkMagenta, Color16::Magenta);
  sh.write_buffer("\\", 22, 63, Color16::DarkMagenta, Color16::Cyan);
  sh.write_buffer(".___", 22, 65, Color16::DarkBlue);

  sh.write_buffer("(", 23, 0, Color16::White, Color16::Cyan);
  sh.write_buffer("  ", 23, 1, Color16::LightGray, Color16::White);
  sh.write_buffer("`", 23, 3, Color16::White, Color16::LightGray);
  sh.write_buffer("      ", 23, 4, Color16::LightGray, Color16::White);
  sh.write_buffer("'", 23, 10, Color16::White, Color16::LightGray);
  sh.write_buffer("  ", 23, 11, Color16::LightGray, Color16::White);
  sh.write_buffer(")", 23, 13, Color16::White, Color16::Cyan);
  sh.write_buffer("\\", 23, 42, Color16::DarkMagenta, Color16::Cyan);
  sh.write_buffer("_____________________", 23, 42, Color16::DarkMagenta, Color16::Magenta);
  sh.write_buffer("/", 23, 63, Color16::DarkMagenta, Color16::Cyan);
  sh.write_buffer(".._ __", 23, 66, Color16::DarkBlue);

  sh.write_buffer("`", 24, 1, Color16::LightGray, Color16::DarkCyan);
  sh.write_buffer("_'`~~", 24, 2, Color16::DarkGray, Color16::LightGray);
  sh.write_buffer("____ ", 24, 7, Color16::Black, Color16::LightGray);
  
  t8x::draw_text(sh, font_data, font_colors, "Pilot Episode", 24, 6, t8x::Font::Avatar);
  //sh.replace_bg_color(Color16::Yellow, ttl::Rectangle { 25, 6, 69, 4 });
  sh.replace_bg_color(Color16::Yellow, t8::Rectangle { 25, 6, 4, 28 });
  sh.replace_bg_color(Color16::Yellow, t8::Rectangle { 25, 36, 4, 39 });

  sh.write_buffer("(c) 2022 - 2024", 29, 64, Color16::White);
  
  sh.write_buffer("Press space-bar to continue...", 29, 25, Color16::White);
}

