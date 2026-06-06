#ifndef MAP_H
#define MAP_H
int loadMap(const char *filename, char ***arr, int *row, int *cols);
char convertTiles(int num);
void free_Map(char **arr, int rows);
#endif
