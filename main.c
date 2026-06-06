#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "colourGuide.h"
#include "maze.h"
#include "terminal.h"
#include "player.h"
#include "random.h"
#include "enemy.h"
#include "sleep.h"
#include "linkedList.h"

int main(int argc, char *argv[])
{
	char **arr;
	PLAYER p;
	ENEMY e;
	int rows, cols;
	int success =0; /*flag for able to read*/
	int gotTreasure = 0;
	char input;
	int win =0;
	int gameOver=0;
	int i,j; /*for molloc copy gamestate*/
	
	
	initRandom();
	if(argc!=2)
	{	
		printf("Usage: %s <map_file>\n", argv[0]);
		return 1;
	}
	else
	{	
		linkedList* undo = createLL(); /*create list*/
		success = loadMap(argv[1], &arr, &rows, &cols);
		if (success ==1)
		{
			printf("Map.txt has been read\n");
			initializePlayer(&p, arr, rows, cols);
			initializeEnemy(&e, arr, rows, cols);
			do
			{
				clear_screen();
				printMaze(arr, rows, cols, gotTreasure);
				input = userInput();
				if (input=='u')
				{
					GameState* prev = (GameState*)removeFirst(undo);
					if(prev!=NULL)
					{
						p=prev->p;
						e=prev->e;
						gotTreasure=prev->gotTreasure;
						
						for(i=0;i<rows+2;i++)
						{
							for(j=0;j<cols+2;j++)
							{
								arr[i][j]=prev->arrCopy[i][j];
							}
						}
					}
					freeGameState(prev, rows);
				}
				else
				{
					GameState* cur = save(p, e, gotTreasure, arr, rows, cols);
					insertFirst(undo, cur);
					win=movePlayer(&p, arr, input, rows, cols, &gotTreasure);	
					if(!win && !gameOver) 
					{
						int x;
						int moves;
						x=0;
						if (gotTreasure==0)
						{
							moves=2;
						}
						else if(gotTreasure==1)
						{
							moves=3;
						}
						while(x<moves && gameOver==0)
						{
							moveEnemy(&e, arr, rows, cols, &p);
							
							if (e.x==p.x && e.y==p.y)
							{
								gameOver=1;
							}
							clear_screen();
							printMaze(arr, rows, cols, gotTreasure);
							sleep(0.2);
							
							x++;
						}
					}	
				}				
			}while (win!=1 && gameOver!= 1);
			
			freeLL(undo, rows);
			
			if (win==1)
			{
				clear_screen();
				printMaze(arr, rows, cols, gotTreasure);
				printf("\nPlayer wins\n");
			}
			else if(gameOver==1)
			{
				clear_screen();
				printMaze(arr, rows, cols, gotTreasure);
				printf("\nPlayer lost\n");
			}
		}
	}
	free_Map(arr, rows);
	return 0;
}

