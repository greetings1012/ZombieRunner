#include "mainModule.h"
#include "../UserInput/userInput.h"
#include "../movePC/pcMovement.h"
#include "../Utility/utility.h"
#include "../DrawStage/drawStage.h"

int HEALTH = 4;
int CURRENT_STAGE = 1;
int TOTAL_SCORE = 0;
int KILLED_ZOMBIE = 0;

int gameStart()
{
	SetCurrentCursorPos(40, 12);
	printf("Zombie Runner");
	SetCurrentCursorPos(36, 14);
	printf("Press Enter to start...");
	while (1)
	{
		int key = _getch();
		if (key == ENTER)
		{
			checkStage();
			return TRUE;
		}
	}
	return FALSE;

}
void checkStage()
{
	system("cls");
	printf(" < STAGE %d > ", CURRENT_STAGE);
	Sleep(2000);
}
int gameOver()
{
	if (HEALTH <= 0) return TRUE;
	else return FALSE;
}
void showResult()
{

	system("cls");

	SetCurrentCursorPos(40, 2);
	if (gameOver()) printf("~ Game Over ~ ");
	else printf("~ Game Clear ~ ");


	SetCurrentCursorPos(40, 4);
	printf("SCORE : %d", TOTAL_SCORE);

	SetCurrentCursorPos(40, 5);
	printf("HP : %d", HEALTH);

	SetCurrentCursorPos(40, 6);
	printf("Killed Zombie : %d", KILLED_ZOMBIE);

	Sleep(2000);

}