#ifndef _BRAIN_H_
#define _BRAIN_H_

#include"brain.cpp"

void display(char *game[3]);
bool check_win(char play[][3],int i,int j);
int if_win(char play[][3],int i, int j, char player_sign);

#endif