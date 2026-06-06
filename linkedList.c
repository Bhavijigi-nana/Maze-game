#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

linkedList * createLL()
{
	linkedList * list = (linkedList*)malloc(sizeof(linkedList));
	list ->head = NULL;
	return list;
}

void insertFirst(linkedList* list, void *newData)
{
	node *newNode = (node* )malloc(sizeof(node));
	if (newNode != NULL)
	{
		newNode->data = newData;
		newNode->next = list->head;
		list->head = newNode;
	}
}

void * removeFirst(linkedList * list)
{
	node* temp;
	void* data = NULL;
	if (list->head !=NULL)
	{
		temp = list->head;
		data = temp->data;
		list->head = list->head->next;
		free(temp);
	}
	return data;
}

GameState* save(PLAYER p, ENEMY e, int gotTreasure, char **arr, int rows, int cols)
{
	int i, j;
	GameState* g = (GameState*)malloc(sizeof(GameState));
	
		g->p = p;
		g->e = e;
		g->gotTreasure = gotTreasure;
		g->arrCopy = (char**)malloc((rows+2) * sizeof(char*));
		for(i=0; i<rows+2; i++)
		{
			g->arrCopy[i]=(char*)malloc((cols+2)*sizeof(char));
			for(j=0;j<cols+2;j++)
			{
				g->arrCopy[i][j]=arr[i][j];
			}
		}

	return g;
}

void freeGameState(void* data, int rows)
{
	int i;
	GameState* g = (GameState*) data;
	if (g!=NULL)
	{
		for (i=0;i<rows+2;i++)/*free each row in arr*/
		{
			free(g->arrCopy[i]);
		}
		free(g->arrCopy);
		free(g);/*free the struct*/
	}
}
void freeLL(linkedList* list, int rows)
{
	node* cur = list->head; /*start form head*/
	node* next = NULL;
	
	while (cur!=NULL)
	{
		next=cur->next;
		freeGameState(cur->data, rows);/* free the data in GameState*/
		free(cur); /*free the node*/
		cur=next;
	}
	free(list);
}
