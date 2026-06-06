CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic -g
OBJS = main.o map.o maze.o colourGuide.o terminal.o player.o random.o enemy.o sleep.o linkedList.o
EXEC = labyrinth

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

main.o: main.c map.h
	$(CC) $(CFLAGS) -c main.c
map.o: map.c map.h
	$(CC) $(CFLAGS) -c map.c
maze.o: maze.c maze.h colourGuide.h
	$(CC) $(CFLAGS) -c maze.c
colourGuide.o: colourGuide.c colourGuide.h
	$(CC) $(CFLAGS) -c colourGuide.c
terminal.o: terminal.c terminal.h
	$(CC) $(CFLAGS) -c terminal.c
player.o: player.c player.h terminal.h
	$(CC) $(CFLAGS) -c player.c
random.o: random.c random.h
	$(CC) $(CFLAGS) -c random.c
enemy.o: enemy.c enemy.h random.h player.h
	$(CC) $(CFLAGS) -c enemy.c
sleep.o: sleep.c sleep.h
	$(CC) $(CFLAGS) -c sleep.c
linkedList.o: linkedList.c linkedList.h 
	$(CC) $(CFLAGS) -c linkedList.c
clean: 
	rm -f *.o $(EXEC)
