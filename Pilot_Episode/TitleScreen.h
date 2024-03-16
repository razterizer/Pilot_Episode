#pragma once

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
void draw_title(SpriteHandler<NR, NC>& sh)
{
  sh.write_buffer("Rasmus Anthin", 0, 55, Text::Color::Black, Text::Color::Cyan);
  sh.write_buffer("__", 1, 12, Text::Color::DarkBlue);
  sh.write_buffer("((((((,", 1, 17, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer(",######", 1, 41, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer("Presents:", 1, 57, Text::Color::Black, Text::Color::Cyan);

  sh.write_buffer("((((((((((((((", 2, 16, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("/################", 2, 36, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer("//", 2, 74, Text::Color::DarkGray, Text::Color::LightGray);

  sh.write_buffer("___,", 3, 13, Text::Color::DarkBlue);
  sh.write_buffer("(((((((((((((((((", 3, 17, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("#####", 3, 34, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer("////", 3, 39, Text::Color::DarkBlue);
  sh.write_buffer("####", 3, 43, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer("//", 3, 47, Text::Color::DarkBlue);
  sh.write_buffer("\\", 3, 49, Text::Color::Cyan);
  sh.write_buffer("/", 3, 50, Text::Color::DarkBlue);
  sh.write_buffer("#####", 3, 51, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer("__ ..", 3, 66, Text::Color::DarkBlue);
  sh.write_buffer("///", 3, 74, Text::Color::DarkGray, Text::Color::LightGray);

  sh.write_buffer("__.", 4, 0, Text::Color::DarkBlue);
  sh.write_buffer("####", 4, 4, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer(".,", 4, 17, Text::Color::DarkBlue);
  sh.write_buffer("((((((((((((((", 4, 19, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("###", 4, 33, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer("///", 4, 36, Text::Color::DarkBlue);
  sh.write_buffer("\\", 4, 39, Text::Color::Cyan);
  sh.write_buffer("///", 4, 40, Text::Color::DarkBlue);
  sh.write_buffer("####", 4, 43, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer("///", 4, 47, Text::Color::DarkBlue);
  sh.write_buffer("\\", 4, 50, Text::Color::Cyan);
  sh.write_buffer("//", 4, 51, Text::Color::DarkBlue);
  sh.write_buffer("####.", 4, 53, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer("____ . .", 4, 62, Text::Color::DarkBlue);
  sh.write_buffer("////", 4, 73, Text::Color::DarkGray, Text::Color::LightGray);

  sh.write_buffer("#####", 5, 4, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer("...", 5, 18, Text::Color::DarkBlue);
  sh.write_buffer("(((((((((((", 5, 21, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("###", 5, 32, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer("//", 5, 35, Text::Color::DarkBlue);
  sh.write_buffer("\\", 5, 37, Text::Color::Cyan);
  sh.write_buffer("/////", 5, 38, Text::Color::DarkBlue);
  sh.write_buffer("####", 5, 43, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer("////////", 5, 47, Text::Color::DarkBlue);
  sh.write_buffer("###.", 5, 55, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer("////", 5, 73, Text::Color::DarkGray, Text::Color::LightGray);

  sh.write_buffer("__.", 6, 1, Text::Color::DarkBlue);
  sh.write_buffer("######\\", 6, 4, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer(".", 6, 20, Text::Color::DarkBlue);
  sh.write_buffer("(", 6, 21, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("############################################", 6, 22, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer("@@@", 6, 66, Text::Color::Black, Text::Color::DarkGray);
  sh.write_buffer("////", 6, 73, Text::Color::DarkGray, Text::Color::LightGray);

  sh.write_buffer("##############################################################", 7, 4, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer("   @@@", 7, 66, Text::Color::Black, Text::Color::DarkGray);
  sh.write_buffer("////", 7, 73, Text::Color::DarkGray, Text::Color::LightGray);

  sh.write_buffer("##############################################################", 8, 4, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer("---   @", 8, 66, Text::Color::Black, Text::Color::DarkGray);
  sh.write_buffer("///", 8, 74, Text::Color::DarkGray, Text::Color::LightGray);

  sh.write_buffer("##############################################################", 9, 4, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer("       @", 9, 66, Text::Color::Black, Text::Color::DarkGray);
  sh.write_buffer("/(", 9, 74, Text::Color::DarkGray, Text::Color::LightGray);

  sh.write_buffer("_ _.", 10, 0, Text::Color::DarkBlue);
  sh.write_buffer("########################", 10, 4, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer("(((((((((((((((((", 10, 28, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("#####################", 10, 45, Text::Color::DarkRed, Text::Color::Red);
  sh.write_buffer("\"\"\"\"\"\"  ", 10, 66, Text::Color::Black, Text::Color::DarkGray);
  sh.write_buffer("((*", 10, 74, Text::Color::DarkGray, Text::Color::LightGray);

  sh.write_buffer("###", 11, 4, Text::Color::Red, Text::Color::DarkRed);
  sh.write_buffer("((((((", 11, 7, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("############", 11, 13, Text::Color::Red, Text::Color::DarkRed);
  sh.write_buffer("(((((((((((((((((((", 11, 25, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("######################", 11, 44, Text::Color::Red, Text::Color::DarkRed);
  sh.write_buffer("______ @", 11, 66, Text::Color::DarkGray, Text::Color::Black);
  sh.write_buffer("///", 11, 74, Text::Color::DarkGray, Text::Color::LightGray);

  sh.write_buffer("__..", 12, 1, Text::Color::DarkBlue);
  sh.write_buffer("((((((", 12, 5, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("###########", 12, 11, Text::Color::Red, Text::Color::DarkRed);
  sh.write_buffer("((((((((((((((((((((", 12, 22, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("########################", 12, 42, Text::Color::Red, Text::Color::DarkRed);
  sh.write_buffer("\"\"\"\"\"@@", 12, 66, Text::Color::DarkGray, Text::Color::Black);
  sh.write_buffer("////", 12, 73, Text::Color::DarkGray, Text::Color::LightGray);

  sh.write_buffer("((((", 13, 4, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("'===", 13, 15, Text::Color::Red, Text::Color::DarkRed);
  sh.write_buffer("(((((((((((((((((((((", 13, 19, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("#", 13, 40, Text::Color::Red, Text::Color::DarkRed);
  sh.write_buffer("*", 13, 41, Text::Color::Red, Text::Color::DarkYellow);
  sh.write_buffer("#", 13, 42, Text::Color::Red, Text::Color::DarkRed);
  sh.write_buffer("\\", 13, 43, Text::Color::Yellow, Text::Color::DarkYellow);
  sh.write_buffer("#", 13, 44, Text::Color::Red, Text::Color::Red);
  sh.write_buffer("|", 13, 45, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("#", 13, 46, Text::Color::Red, Text::Color::Red);
  sh.write_buffer("/", 13, 47, Text::Color::Yellow, Text::Color::DarkYellow);
  sh.write_buffer("#", 13, 48, Text::Color::Red, Text::Color::DarkRed);
  sh.write_buffer("*", 13, 49, Text::Color::Red, Text::Color::DarkYellow);
  sh.write_buffer("################", 13, 50, Text::Color::Red, Text::Color::DarkRed);
  sh.write_buffer("@@@@@", 13, 66, Text::Color::Black, Text::Color::Black);
  sh.write_buffer("////", 13, 73, Text::Color::DarkGray, Text::Color::LightGray);

  sh.write_buffer("((((((((((((((((((((", 14, 17, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("===", 14, 37, Text::Color::Red, Text::Color::DarkRed);
  sh.write_buffer("(", 14, 40, Text::Color::DarkRed, Text::Color::DarkYellow);
  sh.write_buffer("=", 14, 41, Text::Color::Red, Text::Color::DarkRed);
  sh.write_buffer("-", 14, 42, Text::Color::Yellow, Text::Color::DarkYellow);
  sh.write_buffer("=", 14, 43, Text::Color::Red, Text::Color::Red);
  sh.write_buffer("(", 14, 44, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("*", 14, 45, Text::Color::Cyan, Text::Color::Yellow);
  sh.write_buffer(")", 14, 46, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("=", 14, 47, Text::Color::Red, Text::Color::Red);
  sh.write_buffer("-", 14, 48, Text::Color::Yellow, Text::Color::DarkYellow);
  sh.write_buffer("=", 14, 49, Text::Color::Red, Text::Color::DarkRed);
  sh.write_buffer(")", 14, 50, Text::Color::DarkRed, Text::Color::DarkYellow);
  sh.write_buffer("=============", 14, 51, Text::Color::Red, Text::Color::DarkRed);
  sh.write_buffer("////", 14, 73, Text::Color::DarkGray, Text::Color::LightGray);

  sh.write_buffer("((((((((((((((((((((", 15, 15, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("*", 15, 41, Text::Color::Red, Text::Color::DarkYellow);
  sh.write_buffer("/", 15, 43, Text::Color::Yellow, Text::Color::DarkYellow);
  sh.write_buffer("|", 15, 45, Text::Color::Green, Text::Color::Yellow);
  sh.write_buffer("\\", 15, 47, Text::Color::Yellow, Text::Color::DarkYellow);
  sh.write_buffer("*", 15, 49, Text::Color::Red, Text::Color::DarkYellow);
  sh.write_buffer("___ . .", 15, 65, Text::Color::DarkBlue);
  sh.write_buffer("////", 15, 73, Text::Color::DarkGray, Text::Color::LightGray);

  sh.write_buffer("___", 16, 10, Text::Color::DarkBlue);
  sh.write_buffer("(((((((((((((((((", 16, 14, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("|", 16, 45, Text::Color::Green, Text::Color::Cyan);
  sh.write_buffer("///", 16, 74, Text::Color::DarkGray, Text::Color::LightGray);

  sh.write_buffer("__.", 17, 7, Text::Color::DarkBlue);
  sh.write_buffer("((((((((((((((", 17, 14, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("|", 17, 45, Text::Color::Green, Text::Color::Cyan);
  sh.write_buffer("___  _  . ..", 17, 60, Text::Color::DarkBlue);
  sh.write_buffer("//", 17, 74, Text::Color::DarkGray, Text::Color::LightGray);

  sh.write_buffer("(((((((((", 18, 15, Text::Color::DarkYellow, Text::Color::Yellow);
  sh.write_buffer("     ", 18, 24, Text::Color::LightGray, Text::Color::White);
  sh.write_buffer(".", 18, 29, Text::Color::White, Text::Color::Cyan);
  sh.write_buffer("|", 18, 45, Text::Color::Green, Text::Color::Cyan);

  sh.write_buffer(",", 19, 19, Text::Color::White, Text::Color::Cyan);
  sh.write_buffer("     ", 19, 20, Text::Color::LightGray, Text::Color::White);
  sh.write_buffer("_)", 19, 25, Text::Color::White, Text::Color::LightGray);
  sh.write_buffer("  ", 19, 27, Text::Color::LightGray, Text::Color::White);
  sh.write_buffer(")", 19, 29, Text::Color::White, Text::Color::Cyan);
  sh.write_buffer("|", 19, 45, Text::Color::Green, Text::Color::Cyan);

  sh.write_buffer("~~'", 20, 4, Text::Color::White, Text::Color::Cyan);
  sh.write_buffer(" ", 20, 7, Text::Color::LightGray, Text::Color::White);
  sh.write_buffer("`_", 20, 8, Text::Color::White, Text::Color::Cyan);
  sh.write_buffer("(,", 20, 18, Text::Color::White, Text::Color::Cyan);
  sh.write_buffer("   ", 20, 20, Text::Color::LightGray, Text::Color::White);
  sh.write_buffer("_)", 20, 23, Text::Color::White, Text::Color::LightGray);
  sh.write_buffer("      ", 20, 25, Text::Color::LightGray, Text::Color::White);
  sh.write_buffer(")", 20, 31, Text::Color::White, Text::Color::Cyan);
  sh.write_buffer(",------.", 20, 49, Text::Color::DarkMagenta, Text::Color::Magenta);

  sh.write_buffer("'", 21, 3, Text::Color::White, Text::Color::Cyan);
  sh.write_buffer("       ", 21, 4, Text::Color::LightGray, Text::Color::White);
  sh.write_buffer(".", 21, 11, Text::Color::White, Text::Color::Cyan);
  sh.write_buffer("`", 21, 20, Text::Color::LightGray, Text::Color::DarkCyan);
  sh.write_buffer("~~~~~=---", 21, 21, Text::Color::DarkGray, Text::Color::LightGray);
  sh.write_buffer("'", 21, 30, Text::Color::LightGray, Text::Color::DarkCyan);
  sh.write_buffer("__", 21, 43, Text::Color::DarkMagenta);
  sh.write_buffer("A", 21, 45, Text::Color::DarkMagenta, Text::Color::Magenta);
  sh.write_buffer("__", 21, 46, Text::Color::DarkMagenta);
  sh.write_buffer("/", 21, 48, Text::Color::DarkMagenta, Text::Color::Magenta);
  sh.write_buffer("_", 21, 49, Text::Color::DarkGray, Text::Color::Cyan);
  sh.write_buffer(")(", 21, 50, Text::Color::LightGray, Text::Color::DarkCyan);
  sh.write_buffer("_", 21, 52, Text::Color::DarkGray, Text::Color::Cyan);
  sh.write_buffer(")(", 21, 53, Text::Color::LightGray, Text::Color::DarkCyan);
  sh.write_buffer("_", 21, 55, Text::Color::DarkGray, Text::Color::Cyan);
  sh.write_buffer(")", 21, 56, Text::Color::LightGray, Text::Color::DarkCyan);
  sh.write_buffer("\\", 21, 57, Text::Color::DarkMagenta, Text::Color::Magenta);
  sh.write_buffer("_____", 21, 58, Text::Color::DarkMagenta);
  sh.write_buffer("___ _", 21, 66, Text::Color::DarkBlue);

  sh.write_buffer("_(", 22, 1, Text::Color::White, Text::Color::Cyan);
  sh.write_buffer("     ", 22, 3, Text::Color::LightGray, Text::Color::White);
  sh.write_buffer("_)", 22, 8, Text::Color::White, Text::Color::LightGray);
  sh.write_buffer("  ", 22, 10, Text::Color::LightGray, Text::Color::White);
  sh.write_buffer(")", 22, 12, Text::Color::White, Text::Color::Cyan);
  sh.write_buffer("/", 22, 42, Text::Color::DarkMagenta, Text::Color::Cyan);
  sh.write_buffer("  ________________  ", 22, 43, Text::Color::DarkMagenta, Text::Color::Magenta);
  sh.write_buffer("\\", 22, 63, Text::Color::DarkMagenta, Text::Color::Cyan);
  sh.write_buffer(".___", 22, 65, Text::Color::DarkBlue);

  sh.write_buffer("(", 23, 0, Text::Color::White, Text::Color::Cyan);
  sh.write_buffer("  ", 23, 1, Text::Color::LightGray, Text::Color::White);
  sh.write_buffer("`", 23, 3, Text::Color::White, Text::Color::LightGray);
  sh.write_buffer("      ", 23, 4, Text::Color::LightGray, Text::Color::White);
  sh.write_buffer("'", 23, 10, Text::Color::White, Text::Color::LightGray);
  sh.write_buffer("  ", 23, 11, Text::Color::LightGray, Text::Color::White);
  sh.write_buffer(")", 23, 13, Text::Color::White, Text::Color::Cyan);
  sh.write_buffer("\\", 23, 42, Text::Color::DarkMagenta, Text::Color::Cyan);
  sh.write_buffer("_____________________", 23, 42, Text::Color::DarkMagenta, Text::Color::Magenta);
  sh.write_buffer("/", 23, 63, Text::Color::DarkMagenta, Text::Color::Cyan);
  sh.write_buffer(".._ __", 23, 66, Text::Color::DarkBlue);

  sh.write_buffer("`", 24, 1, Text::Color::LightGray, Text::Color::DarkCyan);
  sh.write_buffer("_'`~~", 24, 2, Text::Color::DarkGray, Text::Color::LightGray);
  sh.write_buffer("____ ", 24, 7, Text::Color::Black, Text::Color::LightGray);
  sh.write_buffer("_  _     ____ _____    _____ ____  _  ____  ____  ____  _____", 24, 13, Text::Color::Black);

  sh.write_buffer("/  __\\/ \\/ \\   /  _ Y__ __\\", 25, 6, Text::Color::Black, Text::Color::Yellow);
  sh.write_buffer("/  __//  __\\/ \\/ ___\\/  _ \\/  _ \\/  __/", 25, 35, Text::Color::Black, Text::Color::Yellow);

  sh.write_buffer("|  \\/|| || |   | / \\| / \\  ", 26, 6, Text::Color::Black, Text::Color::Yellow);
  sh.write_buffer("|  \\  |  \\/|| ||    \\| / \\|| | \\||  \\  ", 26, 35, Text::Color::Black, Text::Color::Yellow);

  sh.write_buffer("|  __/| || |_/\\| \\_/| | |  ", 27, 6, Text::Color::Black, Text::Color::Yellow);
  sh.write_buffer("|  /_ |  __/| |\\___ || \\_/|| |_/||  /_ ", 27, 35, Text::Color::Black, Text::Color::Yellow);

  sh.write_buffer("\\_/   \\_/\\____/\\____/ \\_/  ", 28, 6, Text::Color::Black, Text::Color::Yellow);
  sh.write_buffer("\\____\\\\_/   \\_/\\____/\\____/\\____/\\____\\", 28, 35, Text::Color::Black, Text::Color::Yellow);

  sh.write_buffer("(c) 2022 - 2024", 29, 64, Text::Color::White);
  
  sh.write_buffer("Press space-bar to continue...", 29, 25, Text::Color::White);
}

