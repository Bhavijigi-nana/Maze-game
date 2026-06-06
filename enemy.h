#ifndef ENEMY_H
#define ENEMY_H
#include "player.h"
typedef struct enemy
{
	int x;
	int y;
	char symbol;
} ENEMY;

void initializeEnemy(ENEMY * e, char **arr, int rows, int cols);
int freeBlock(char **arr, int y, int x, int rows, int cols);
void moveEnemy(ENEMY * e, char **arr, int rows, int cols, PLAYER * p);



#endif
