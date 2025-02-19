#ifndef CONSOLE_H___
#define CONSOLE_H___
/* Native Functions */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
/* Custom Functions */
#include"game.h"
#include"intro.h"
#include"ui.h"
#include"event.h"
#include"data_read.h"
/* Functions in console.h */
enum colorNum {White, Gray,
               Red, Green, Yellow, Blue, Magenta, Cyan,
               BlackOnGray, BlackOnW,
               RedOnW, GreenOnW, YellowOnW, BlueOnW, MagentaOnW, CyanOnW, WhiteOnW,
               DarkRed, DarkGreen, DarkYellow, DarkBlue, DarkMagenta, DarkCyan
              };
void getXY(int &x,int &y);
void gotoXY(int x, int  y);
void setColor(colorNum color);
#endif // CONSOLE_H___
