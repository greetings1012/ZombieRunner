#include "../Utility/utility.h"

int showMap() {

	int x;

	for (x = 0; x < 120; x++)
	{
		SetCurrentCursorPos(x, 20);
		printf("-");
	}

	return TRUE;
}

int removeMap() {

	int x, y;

	for (x = 0; x < 120; x++)
	{
		SetCurrentCursorPos(x, 20);
		printf(" ");
	}

	return TRUE;
}

int showPC(char pcInfo[3][5]) {
	int x, y;
	COORD curPos = GetCurrentCursorPos(); // PC 위치를 받아와야 함

	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 3; x++)
		{
			SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);
			printf(pcInfo[y][x]);
		}
	}
	SetCurrentCursorPos(curPos.X, curPos.Y);

	return TRUE;
}

int removePC(char pcInfo[3][5]) {

	int x, y;
	COORD curPos = GetCurrentCursorPos(); // PC 위치를 받아와야 함

	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 3; x++)
		{
			SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);
			printf("  ");
		}
	}

	return TRUE;
}

int showZombie(char zombieInfo[3][5]) {

	int x, y;
	COORD curPos = GetCurrentCursorPos(); // 좀비 위치를 받아와야 함

	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 3; x++)
		{
			SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);
			printf(zombieInfo[y][x]);
		}
	}

	return TRUE;
}

int removeZombie(char zombieInfo[3][5]) {

	int x, y;
	COORD curPos = GetCurrentCursorPos(); // 좀비 위치를 받아와야 함

	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 3; x++)
		{
			SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);
			printf("  ");
		}
	}

	return TRUE;
}