#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "player.h"
#include "enemy.h"

typedef struct Gamestate
{
	PLAYER p;
	ENEMY e;
	int gotTreasure;
	char **arrCopy;
}GameState;

typedef struct node /*struct for node*/
{
	void * data;
	struct node * next;
} node;

typedef struct /*struct for linked list*/
{
	node * head; /*points to the first node*/
}linkedList;

linkedList * createLL();
void insertFirst(linkedList* list, void *newData);
void * removeFirst(linkedList * list);
GameState* save(PLAYER p, ENEMY e, int gotTreasure, char **arr, int rows, int cols);
void freeGameState(void* data, int rows);
void freeLL(linkedList* list, int rows);
#endif
