#ifndef UTILITY_H
#define UTILITY_H

#include <Windows.h>

void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos(void);
void RemoveCursor(void);
void changeColor(int colorNum);
#endif  