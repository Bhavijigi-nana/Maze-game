#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "terminal.h"

char userInput()
{
	char input;
	disableBuffer();
	scanf(" %c", &input);
	enableBuffer();
	return input;
}
void initializePlayer(PLAYER *p, char **arr, int rows, int cols)
{
	int i,j;
	for (i=0; i<rows +2; i++)
	{
		for(j=0; j<cols+2;j++)
		{
			if(arr[i][j] == 'P')
			{
				p->y = i;
				p->x = j; 
				return;
			}
		}
	}
}
int movePlayer(PLAYER *p, char **arr, char input, int rows, int cols, int * gotTreasure)
{
	int win =0;
	int newY = p->y;
	int newX = p->x;
	
	switch(input)
	{
		case 'w':
			newY--;
			break;
		case 's':
			newY++;
			break;
		case 'a':
			newX--;
			break;
		case 'd':
			newX++;
			break;
		default:
			return 0;
	}
	if (newY>=0 && newY<rows+2 && newX>=0 && newX<cols+2)
	{
		if(arr[newY][newX]=='#'|| arr[newY][newX] =='*') /*Wall and border */
		{
			return 0;
		}
		if(arr[newY][newX]=='T')
		{
			*gotTreasure=1; /*got the treasure*/
		}
		if(arr[newY][newX]=='G')
		{
			if (*gotTreasure == 1)
			{
				win = 1;
			}
			else
			{
				return 0;
			}
		}
		if (arr[newY][newX]=='<' || arr[newY][newX]=='>' || arr[newY][newX]=='^' || arr[newY][newX]=='v')
		{
			return 0;
		}   
		arr[p->y][p->x] = ' ';
		p->y = newY;
		p->x = newX;
		arr[p->y][p->x] = 'P';
	}
	return win;
}
			
		  
			
			
			
			
			
			
			
			
			
			
			
			
