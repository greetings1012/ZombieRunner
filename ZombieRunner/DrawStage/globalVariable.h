#pragma once

static int gameBoardInfo[20][100];

static int char_x = 3, char_y = 13;//캐릭터생성위치
static int char_size_x = 5, char_size_y = 7;//캐릭터 크기
static int obs_x = 92, obs_y = 13;//장애물생성위치
static int obs_size_x = 4, obs_size_y = 7;//장애물 크기
static int char_n = 7;//캐릭터 번호
static int obs_n = 1;//장애물 번호
static int floor_y = 20;//바닥위치
static int hp = 10;
static int cheat = 0; //무적 1:on, 0:off