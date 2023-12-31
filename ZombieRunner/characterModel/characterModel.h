#ifndef CHARACTER_H
#define CHARACTER_H

// 기본
char pcInfo[3][5] =
{
   {'(','0','U','0',')'},
   {'/','|','_','|','~'},
   {' ','/',' ','|',' '}

};
// 공격
char pcAttackInfo[3][5] =
{
   {'(','`','^','`',')'},
   {'|','\\','_','|','\\'},
   {' ','/',' ','|',' '}

};
// 점프
char pcJumpInfo3[3][5] =
{
   {'(','0','_','0',')'},
   {'/','|','_','|','\\'},
   {' ','*',' ','*',' '}

};
// 높은 점프
char pcHighJumpInfo4[3][5] =
{
   {'(','0','_','0',')'},
   {'/','|','_','|','\\'},
   {' ','^',' ','^',' '}

};
// 슬라이드
char pcSlideInfo5[2][5] =
{
   {'(','0','_','0',')'},
   {'/','|','_','|','\\'}
};
#endif