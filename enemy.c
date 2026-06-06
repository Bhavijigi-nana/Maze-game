#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "enemy.h"
#include "player.h"


void initializeEnemy(ENEMY * e, char **arr, int rows, int cols)
{
	int i,j;
	for (i=0;i<rows+2;i++)
	{
		for (j=0;j<cols+2;j++)
		{
			if (arr[i][j] == '<') /*finds for enemy in maze*/
			{
				e->y = i;
				e->x = j;
				e->symbol = '<';
				return;
			}
		}
	}
}

int freeBlock(char **arr, int y, int x, int rows, int cols)
{
	int blockFree;
	if (y<0 || y>=rows+2 || x<0 || x>=cols+2) /* check boundaries*/
	{
		blockFree = 0;
	}
	else
	{
		if (arr[y][x]=='#' || arr[y][x]=='*' || arr[y][x]=='T' || arr[y][x]=='G') /*if wall, border, treasure, goal block it*/
		{
			blockFree = 0; /*block*/
		}
		else
		{
			blockFree = 1; /*free to go*/
		}
	}
	return blockFree;
}
		
void moveEnemy(ENEMY * e, char **arr, int rows, int cols, PLAYER * p)
{
	int choice;
	int leftX, leftY, rightX, rightY, frontX, frontY;	
	char leftSymbol, rightSymbol, backSymbol;
	int leftFree, rightFree, frontFree;
	
	int newY;
	int newX;
	char newSymbol;
	
	if(e->symbol == '<')
	{
		frontY = e->y;
		frontX = e->x - 1;
		leftY = e->y +1;
		leftX = e->x;
		rightY = e->y -1;
		rightX = e->x;
		leftSymbol = 'v';
		rightSymbol = '^';
		backSymbol = '>';
	}
	else if(e->symbol == '>')
	{
		frontY = e->y;
		frontX = e->x + 1;
		leftY = e->y -1;
		leftX = e->x;
		rightY = e->y +1;
		rightX = e->x;
		leftSymbol = '^';
		rightSymbol = 'v';
		backSymbol = '<';
	}
	else if(e->symbol == '^')
	{
		frontY = e->y -1;
		frontX = e->x;
		leftY = e->y;
		leftX = e->x -1;
		rightY = e->y;
		rightX = e->x +1;
		leftSymbol = '<';
		rightSymbol = '>';
		backSymbol = 'v';
	}
	else if(e->symbol == 'v')
	{
		frontY = e->y +1;
		frontX = e->x;
		leftY = e->y;
		leftX = e->x +1;
		rightY = e->y;
		rightX = e->x -1;
		leftSymbol = '>';
		rightSymbol = '<';
		backSymbol = '^';
	}
	
	leftFree = freeBlock(arr, leftY, leftX, rows, cols);
	rightFree = freeBlock(arr, rightY, rightX, rows, cols);
	frontFree = freeBlock(arr, frontY, frontX, rows, cols);
	
	newY = e->y;
	newX = e->x;
	newSymbol = e->symbol;
	
	if (frontFree == 1 && leftFree==0 && rightFree==0) /*only forward allowed*/
	{
		newY=frontY;
		newX=frontX;
	}
	else if(frontFree == 1 && leftFree==1 && rightFree==1) /*all directions are open*/
	{
		choice = randomUCP(0,2);
		if(choice==0) /*go forward*/
		{
			newY = frontY;
			newX = frontX;
		}
		else if (choice==1)/*go to the left*/
		{
			newY=leftY;
			newX=leftX;
			newSymbol = leftSymbol;
		}
		else if(choice==2)/*go to the roght*/
		{
			newY=rightY;
			newX=rightX;
			newSymbol=rightSymbol;
		}
	}
	else if(frontFree==1 && leftFree==1 && rightFree==0)/*forward and left*/
	{
		choice=randomUCP(0,1);
		if (choice==0)/*forward*/
		{
			newY = frontY;
			newX = frontX;
		}
		else if(choice==1)/*left*/
		{
			newY = leftY;
			newX=leftX;
			newSymbol = leftSymbol;
		}
	}
	else if(frontFree==1 && leftFree==0 && rightFree==1)/*forward and right*/
	{
		choice=randomUCP(0,1);
		if (choice==0)/*forward*/
		{
			newY = frontY;
			newX = frontX;
		}
		else if(choice==1)/*right*/
		{
			newY = rightY;
			newX=rightX;
			newSymbol = rightSymbol;
		}
	}
	else if (frontFree==0 && leftFree==1 && rightFree==1)/*left and right*/
	{
		choice=randomUCP(0,1);
		if (choice==0)/*left*/
		{
			newY = leftY;
			newX = leftX;
			newSymbol=leftSymbol;
		}
		else if(choice==1)/*right*/
		{
			newY = rightY;
			newX=rightX;
			newSymbol = rightSymbol;
		}
	}
	else if (frontFree==0 && leftFree==1 && rightFree==0)/*left only*/
	{
		newY=leftY;
		newX=leftX;
		newSymbol=leftSymbol;
	}
	else if (frontFree==0 && leftFree==0 && rightFree==1)/*right only*/
	{
		newY=rightY;
		newX=rightX;
		newSymbol=rightSymbol;
	}
	else if(frontFree==0 && leftFree==0 && rightFree==0)
	{
		int backY, backX;
		backY = e->y;
		backX = e->x;
		if(e->symbol=='<')
		{
			backX = e->x +1;
		}
		else if(e->symbol=='>')
		{
			backX=e->x -1;
		}
		else if(e->symbol=='^')
		{
			backY=e->y +1;
		}
		else if(e->symbol=='v')
		{
			backY=e->y -1;
		}
		
		newY = backY;
		newX = backX;
		newSymbol = backSymbol;
	}
	if (e->y==p->y && e->x==p->x)
	{
		arr[e->y][e->x] = 'P';
	}
	else
	{
		arr[e->y][e->x] = ' ';
	}
	
	e->y = newY;
	e->x=newX;
	e->symbol = newSymbol;
	arr[e->y][e->x] = e->symbol;
}

