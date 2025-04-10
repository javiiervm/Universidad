OPTS = -O3 -std=c++0x
OPTSDEBUG = -g -Wall -Wextra -std=c++0x

all: maze_greedy

maze: maze_greedy.cc
	g++ ${OPTS} -o maze_greedy maze_greedy.cc

debug: maze_greedy.cc
	g++ ${OPTSDEBUG} -o maze_greedy maze_greedy.cc

tar: maze.cc makefile
	tar cvfz 51299727K.tar.gz maze.cc makefile

clean: 
	rm -f maze_greedy
