All: a.out

a.out:main.o Maze_re.o
	g++ main.o Maze_re.o

main.o:main.cc Board_re.h Maze_re.h
	g++ -std=c++11 main.cc Board_re.h Maze_re.h -c

Maze_re: Maze_re.h Board_re.h Maze_re.cc
	g++ -std=c++11 Maze_re.h Board_re.h Maze_re.cc -c

run:
	./a.out
debug:
	g++ -std=c++11 main.cc Board_re.h Maze_re.h Maze_re.cc -g -o a.out
