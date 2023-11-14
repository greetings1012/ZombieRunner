#include <stdio.h>

#include "obsModel.h"

int showObject(char obsInfo[7][4][3]) {
	COORD curPos = GetCurrentCursorPos();
	int obsdata = atoi(obsInfo[0][0]);
	updateGameBoard(curPos.X, curPos.Y, obsdata);
	for (int y = 1; y < obs_size_y; y++) {
		for (int x = 0; x < obs_size_x; x++) {
			SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);
			if (strcmp(obsInfo[y][x], " ") != 0) {
				printf("%s", obsInfo[y][x]);
				updateGameBoard(curPos.X + (x * 2), curPos.Y + y, 1);
			}
		}
	}
	SetCurrentCursorPos(curPos.X, curPos.Y);
	return 1;
}

int removeObject(char obsInfo[7][4][3]) {
	COORD curPos = GetCurrentCursorPos();
	updateGameBoard(curPos.X, curPos.Y, 0);
	for (int y = 1; y < obs_size_y; y++) {
		for (int x = 0; x < obs_size_x; x++) {
			SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);
			if (strcmp(obsInfo[y][x], " ") != 0) {
				printf("  ");
				updateGameBoard(curPos.X + x, curPos.Y + y, 0);
				updateGameBoard(curPos.X + x + 2, curPos.Y + y, 0);
			}
		}
	}
	SetCurrentCursorPos(curPos.X, curPos.Y);
	return 1;
}

int updateGameBoard(int curPosX, int curPosY, int n) {
	gameBoardInfo[curPosY][curPosX] = n;
	if (n == 1) //n이 multibyte_character이면 //다른 오브젝트/캐릭터/아이템의 multibyte_character 여부의 따라 추가
		gameBoardInfo[curPosY][curPosX + 1] = n;
	return 1;
}

//PC, 인터페이스를 제외하고 obj,좀비,아이템 등을 모두 왼쪽으로 한칸씩 당기는 함수
int moveAllToLeft() {
	int y = obs_y;
	int obs_id;
	//obj, char, item이 왼쪽 끝에 닿으면 삭제
	if (gameBoardInfo[y][0] != 0) {
		switch (gameBoardInfo[y][0] / 10) {
		case 1:
			obs_id = gameBoardInfo[y][0] % 10;
			SetCurrentCursorPos(0, y);
			removeObject(obsModel[obs_id]);
		}
	}
	//
	for (int x = 1; x < 100; x++) {
		//gameBoardInfo[y][x]가 PC가 아니고, obj/좀비/item이라면
		if (gameBoardInfo[y][x] != char_n && gameBoardInfo[y][x] != 0) {
			//PC가 장애물과 닿았다면 (switch로 변경 가능)
			if (touchCheck(char_x, char_y, cModel[0]) == 1) {
				//if 일정시간 무적이 켜있으면 return     //임시
				//if 무적이 아니라면
				if (cheat != 1) {
					hp--; //임시
					//충돌 시 배경 색 변경  //임시
					system("color 47");
					Sleep(50);
					system("color 07");
					//일정시간 무적 켜기 //임시
					cheat = 1;
				}
			}
			//Pc가 장애물을 빠져나왔고, 무적이 켜져있으면 무적 끄기 //임시
			if (touchCheck(char_x, char_y, cModel[0]) == 0 && cheat == 1)
				cheat = 0;
			//왼쪽으로 한칸 움직여 출력
			switch (gameBoardInfo[y][x] / 10) {
			case 1:
				obs_id = gameBoardInfo[y][x] % 10;
				SetCurrentCursorPos(x, y);
				removeObject(obsModel[obs_id]);
				SetCurrentCursorPos(x - 1, y);
				showObject(obsModel[obs_id]);
			}
		}
	}

	//if Pc가 장애물을 빠져나왔으면
	//Pc위치 업데이트 (showCharacter)
	if (touchCheck(char_x, char_y, cModel[0]) == 0) {
		for (int y = 4; y < char_size_y; y++) {
			for (int x = 0; x < char_size_x; x++) {
				SetCurrentCursorPos(char_x + x, char_y + y);
				if (cModel[0][y][x] != ' ') {
					printf("%c", cModel[0][y][x]);
					updateGameBoard(char_x + x, char_y + y, char_n);
				}
			}
		}
	}

	return 1;
}

//만약 characterModel의 y를 늘려 점프까지 characterModel에 구현한다면 pcPosX, pcPosY 빼고 characterInfo만으로 touchCheck 가능
int touchCheck(int pcPosX, int pcPosY, char characterInfo[7][5]) {
	int arrX = pcPosX / 2;
	int arrY = pcPosY;

	for (int y = 0; y < char_size_y; y++) {
		for (int x = 0; x < char_size_x; x++) {
			if (characterInfo[y][x] != ' ' && gameBoardInfo[arrY + y][arrX + x] != 0 && gameBoardInfo[arrY + y][arrX + x] < 7)
				return gameBoardInfo[arrY + y][arrX + x];
		}
	}
	return 0;
}