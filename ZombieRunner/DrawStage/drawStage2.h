#pragma once

int showObject(char obsInfo[7][4][3]);

int removeObject(char obsInfo[7][4][3]);

int updateGameBoard(int curPosX, int curPosY, int n);

int moveAllToLeft();

int touchCheck(int pcPosX, int pcPosY, char characterInfo[7][5]);