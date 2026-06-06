#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "colourGuide.h"
void printMaze(char **arr, int rows, int cols, int treasure)
{
	int i, j;
	char tile;
	for(i =0; i< rows+2; i++)
	{
		for(j=0;j<cols+2; j++)
		{
			tile = arr[i][j];
			switch(tile)
			{
				case 'P':
					setForeground("blue");
					printf("%c",tile);
					break;
				case '<':
				case '^':
				case '>':
				case 'v':
					if (treasure == 0)
					{
						setForeground("red");
					}
					else if (treasure == 1)
					{
						setForeground("reset");
						setBackground("red");
					}
					printf("%c",tile);
					break;
				case '#':
					setBackground("white");
					printf("%c", ' ');
					break;
				case 'G':
					setBackground("green");
					printf("%c",tile);
					break;
				case 'T':
					setBackground("yellow");
					printf("%c",tile);
					break;
				case '*':
					printf("%c",tile);
					break;
				default: 
					printf("%c",tile);
					break;
			}
			setBackground("reset");
			setForeground("reset");
		}
		printf("\n");
	}
	printf("Press the following keys:\n");
	printf("> w: up\n");
	printf("> s: down\n");
	printf("> a: left\n");
	printf("> d: right\n");
	printf("> u: undo\n");
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
			
