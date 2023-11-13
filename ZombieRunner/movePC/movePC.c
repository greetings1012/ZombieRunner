/*
	movePC
		→ 77	Attack		: pcAttack
		← 75	HighJump	: pcHighJump
		↑ 72	Jump		: pcJump
		↓ 80	Slide		: pcSlide
*/

#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)
#include "pcMovement.h"

// printf("~~~\n") 확인용

int movePC() {
	int cmd;
	do {
		cmd = getch();
		if (cmd == 224) {
			cmd = (int)getch();

			switch (cmd) {
			case ATTACK:
				pcAttack();
				//printf("%d",pcAttack());
				break;
			case HIGH_JUMP:
				pcHighJump();
				break;
			case JUMP:
				pcJump();
				break;
			case SLIDE:
				pcSlide();
				break;
			default:

				return 0;
				// 이 외의 키는 원래 모션 나오도록 -> 각자의 함수에서 처리(?) 
			}
		}
	} while (1);
}