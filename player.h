#ifndef PLAYER_H
#define PLAYER_H

typedef struct player
{
	int x;/*cols*/
	int y;/*row*/
} PLAYER;
char userInput();
void initializePlayer(PLAYER *p, char **arr, int rows, int cols);
int movePlayer(PLAYER *p, char **arr, char input, int rows, int cols, int * gotTreasure);
#endif
