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
	if (n == 1) //n�� multibyte_character�̸� //�ٸ� ������Ʈ/ĳ����/�������� multibyte_character ������ ���� �߰�
		gameBoardInfo[curPosY][curPosX + 1] = n;
	return 1;
}

//PC, �������̽��� �����ϰ� obj,����,������ ���� ��� �������� ��ĭ�� ���� �Լ�
int moveAllToLeft() {
	int y = obs_y;
	int obs_id;
	//obj, char, item�� ���� ���� ������ ����
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
		//gameBoardInfo[y][x]�� PC�� �ƴϰ�, obj/����/item�̶��
		if (gameBoardInfo[y][x] != char_n && gameBoardInfo[y][x] != 0) {
			//PC�� ��ֹ��� ��Ҵٸ� (switch�� ���� ����)
			if (touchCheck(char_x, char_y, cModel[0]) == 1) {
				//if �����ð� ������ �������� return     //�ӽ�
				//if ������ �ƴ϶��
				if (cheat != 1) {
					hp--; //�ӽ�
					//�浹 �� ��� �� ����  //�ӽ�
					system("color 47");
					Sleep(50);
					system("color 07");
					//�����ð� ���� �ѱ� //�ӽ�
					cheat = 1;
				}
			}
			//Pc�� ��ֹ��� �������԰�, ������ ���������� ���� ���� //�ӽ�
			if (touchCheck(char_x, char_y, cModel[0]) == 0 && cheat == 1)
				cheat = 0;
			//�������� ��ĭ ������ ���
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

	//if Pc�� ��ֹ��� ������������
	//Pc��ġ ������Ʈ (showCharacter)
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

//���� characterModel�� y�� �÷� �������� characterModel�� �����Ѵٸ� pcPosX, pcPosY ���� characterInfo������ touchCheck ����
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