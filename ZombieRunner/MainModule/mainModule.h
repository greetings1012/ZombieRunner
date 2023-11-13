#ifndef MAINMODULE_H
#define MAINMODULE_H

#include "utility.h"
#include "userInput.h"
#include <stdio.h>

extern int HEALTH;
extern int CURRENT_STAGE;
extern int TOTAL_SCORE;
extern int KILLED_ZOMBIE;

int gameStart();
void checkStage();
int gameOver();
void showResult();

#endif