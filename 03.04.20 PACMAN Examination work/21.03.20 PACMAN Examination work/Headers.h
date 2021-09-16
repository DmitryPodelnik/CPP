#pragma once

#include <iostream>
#include <ctime>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <windows.h>
#include <exception>

using namespace std;

typedef unsigned short ushort;
typedef unsigned int uint;

#define LEFT_UPER_CORNER (char)218
#define LEFT_DOWN_CORNER (char)192
#define RIGHT_UPER_CORNER (char)191
#define RIGHT_DOWN_CORNER (char)217
#define HORIZONTAL_LINE (char)196
#define VERTICAL_LINE (char)179
#define DOT (char)250
#define BIG_DOT (char)253

#define LUC LEFT_UPER_CORNER
#define LDC LEFT_DOWN_CORNER 
#define RUC RIGHT_UPER_CORNER
#define RDC RIGHT_DOWN_CORNER 
#define HL HORIZONTAL_LINE 
#define VL VERTICAL_LINE 
#define BD BIG_DOT

#define LIVE 3;
#define AMOUNT_OF_DOTS 244
#define SPACE_ (char)32

#include "Keys.h"
#include "Colors.h"
#include "Direction.h"
#include "Console.h"
#include "Timer.h"
#include "Menu.h"
#include "Field.h"
#include "Statistics.h"
#include "Console.h"
#include "Character.h"
#include "Pacman.h"
#include "SuperPacman.h"
#include "Ghost.h"
#include "StupidGhost.h"
#include "CleverGhost.h"
#include "Game.h"
#include "Retention.h"
#include "Bonus.h"




