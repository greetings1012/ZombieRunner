// 제목, 스토리, 목표, 조작키, 아이템 정보, 결과창 구현

#pragma once
// page.h

#ifndef PAGE_H
#define PAGE_H

void ShowPage(char** page, int numLines) {
    system("cls");

    for (int i = 0; i < numLines; i++) {
        printf("%s\n", page[i]);
    }

    printf("\nPress Enter to continue...\n");
    while (_getch() != 13);
}

/*------showTitle------*/
// 제목
char* Title[1] = {
    "ZOMBIE RUNNER"
};
/*------showStory------*/
// 게임 스토리
char* Story[7] = {
    "2050년, 서울에 좀비 바이러스가 퍼진 지도 한 달이 되어갑니다.",
    "빠른 초기 대응 덕분에 아직 서울에는 좀비의 수가 적다고 하네요.",
    "하지만 곧 추석입니다. '설은 나가서 쇠어도 추석은 집에서 쇠어야 한다.' 부모님께서 누누이 말해 오셨죠…",
    "주인공은 고향에 있는 가족들을 만나기 위해 고향으로 떠날 채비를 합니다.",
    "좀비는 무섭습니다… 특히 그들이 내는 소리는 아주 기괴하고 끔찍하죠.",
    "하지만 주인공의 에어팟 프로 맥스 8은 노이즈 캔슬링이 짱 잘되기 때문에 괜찮습니다.",
    "풀충전한 헤드폰과 함께, 주인공은 평소 좋아하던 노래를 들으며 가족들의 품으로 달려갑니다!"
};
// 게임 목표
char* Goal[3] = {
    "게임 목표",
    "1. 좀비를 피하거나 공격함으로써 체력을 모두 소진하지 않고 스테이지 클리어하기",
    "2. 최대한 많은 동전 획득하거나 좀비를 처치하여 높은 점수 얻기"
};
/*------showManual------*/
// 게임 조작키
char* Manual[4] = {
    "조작키",
    " → : 공격",
    " ↑ : 한 번 점프, 두 번 더블 점프",
    " ↓ : 슬라이딩"
};

// 좋은 아이템 및 동전
char* GoodItem[5] = {
    "획득하면 좋은 것들",
    "$ : 모든 장애물을 동전으로 바꿔줌",
    "★ : 잠시 캐릭터 무적 상태가 됨",
    "○ : 동전, 점수가 올라감",
    "@ : 비싼 동전, 점수가 올라감"
};

// 안 좋은 아이템 및 장애물
char* BadItem[7] = {
    "획득하면 좋지 않은 것들",
    "△ : 장애물, 닿으면 체력이 소모됨",
    "↔ : 맵을 좌우 반전시킴",
    "↕ : 맵을 상하 반전시킴",
    "(?_?)",
    "6( )9 : 좀비, 닿으면 첷력이 감소되지만, 공격 (방향키 →)으로 해치울 수 있음",
    "/ ?\\"
};

#endif