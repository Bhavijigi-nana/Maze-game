#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"colourGuide.h"

void setForeground(char * colour)
{
	if(strcmp(colour, "blue") == 0)
	{
		printf("\033[34m");
	}
	else if(strcmp(colour, "red") == 0)
	{
		printf("\033[31m");
	}
	else if(strcmp(colour, "reset") == 0)
	{
		printf("\033[39m");
	}
}
void setBackground(char * colour)
{
	if(strcmp(colour, "white")==0)
	{
		printf("\033[47m");
	}
	else if (strcmp(colour, "green")==0)
	{
		printf("\033[42m");
	}
	else if (strcmp(colour, "yellow")==0)
	{
		printf("\033[103m");
	}
	else if(strcmp(colour, "red")==0)
	{
		printf("\033[41m");
	}
	else if(strcmp(colour, "reset") == 0)
	{
		printf("\033[49m");
	}
}
