#include "userInput.h"

void ProcessKeyInput()
{
	for (int i = 0; i < 20; i++)
	{
		if (_kbhit() != 0)
		{
			int key = _getch();

			switch (key)
			{
			case LEFT:	break;
			case RIGHT:	break;
			case UP:	break;
			case DOWN:  break;
			case ENTER: break;

			}
		}
	}
}