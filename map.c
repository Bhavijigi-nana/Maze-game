#include <stdio.h>
#include <stdlib.h>
#include "map.h"
int loadMap(const char *filename, char ***arr, int *rows, int *cols)
{
	int success =0;/*successful reading*/
	int i, j;
	int num;
	FILE *fp = fopen(filename,"r");
	if (fp == NULL)
	{
		perror("Can't open the file");
	}
	else
	{
		if(fscanf(fp, "%d %d", rows, cols) == 2)
		{
			int total_rows = *rows + 2;
			int total_cols = *cols + 2;
			*arr = (char**) malloc(total_rows * sizeof(char*));
			for(i=0; i<total_rows;i++)
			{
				(*arr)[i] = (char *)malloc(sizeof(char)*total_cols);
				for (j=0; j<total_cols;j++)
				{
					if(i==0 || i==total_rows - 1 || j==0 || j==total_cols -1)
					{	
						(*arr)[i][j] = '*';
					}
					else
					{
						if (fscanf(fp, "%d", &num) == 1)
						{
							(*arr)[i][j] = convertTiles(num);
						}
						else /*if fails to read the int from file*/
						{
							(*arr)[i][j] = ' ';
							success = 0;
						}
					}
				}
				success = 1;
			}
		}
	}
	fclose(fp);
	return success;
}
		
char convertTiles(int num)
{
	char tile;
	switch(num)
	{
		case 0:
			tile = ' ';
			break;
		case 1:
			tile = '#'; /*wall*/
			break;
		case 2:
			tile = 'G'; /* Goal */
			break;
		case 3:
			tile = 'T'; /* Tresure*/
			break;
		case 4:
			tile = 'P'; /* Player*/
			break;
		case 5: 
			tile = '<'; /* enemy*/
			break;
	}
	return tile;
}
	
void free_Map(char **arr, int rows)
{
	int i;
	for (i=0; i<rows+2; i++)
	{
		free(arr[i]);
	}
	free(arr);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
