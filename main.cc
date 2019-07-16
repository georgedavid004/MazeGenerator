//Author David

#include <iostream>
#include "Maze_re.h"

//variables

Coord test;
//forward declaration
void traverse(Maze &maze,Coord coord);
char randDir();
void moveUp(Maze &maze,Coord coord);
void moveDown(Maze &maze,Coord coord);
//functions
void moveDown(Maze &maze,Coord coord)
{
	//breaking curent down wall
	maze.offDownFlag(coord);
	//modifying coord to next 
	coord.m_x=coord.m_x+1;
	//marking this posit visisted
	maze.markVisited(coord);
	//now breaking up wall of next cell
	maze.offUpFlag(coord);//this one is dummy one can remove this 
	//marking curent position
//	maze.markPosit(coord);	
//	std::cout<<maze;	
		//recursion
	traverse(maze,coord);
	return ;
}
void moveUp(Maze &maze,Coord coord)
{
	//breaking curent up wall
	maze.offUpFlag(coord);
	//modifying coord to next 
	coord.m_x=coord.m_x-1;
		maze.markVisited(coord);
	//now breaking down wall of next cell
	maze.offDownFlag(coord);//this one is dummy one
	//marking curent position
//	maze.markPosit(coord);	
//	std::cout<<maze;	
		//recursion
	traverse(maze,coord);
	return ;
}

void moveLeft(Maze &maze,Coord coord)
{
	//breaking curent up wall
	maze.offLeftFlag(coord);
	//modifying coord to next 
	coord.m_y=coord.m_y-1;
		maze.markVisited(coord);
	//now breaking down wall of next cell
	maze.offRightFlag(coord);//this one is dummy one
	//marking curent position
//	maze.markPosit(coord);	
//	std::cout<<maze;	
	//recursion
	traverse(maze,coord);
	return ;
}

void moveRight(Maze &maze,Coord coord)
{
	//breaking curent up wall
	maze.offRightFlag(coord);//dummy
	//modifying coord to next 
	coord.m_y=coord.m_y+1;
		maze.markVisited(coord);
	//now breaking down wall of next cell
	maze.offLeftFlag(coord);//this one is dummy one
	//marking curent position
//	maze.markPosit(coord);	
//	std::cout<<maze;	
	//recursion
	traverse(maze,coord);
	return ;
}
//movement done
char randDir()
{
	switch(std::rand()%4)
	{
		case 1:
			return 'l';
		case 2:
			return 'r';
		case 3:
			return 'u';
		case 0:
			return 'd';
	}
}

void traverse(Maze &maze,Coord coord)
{

	test=coord;
	//choosing random dirrection to move
	switch(randDir())
	{
		case 'u':	
			if(maze.checkMove(Coord(coord.m_x-1,coord.m_y)))
			{
//				std::cout<<"move up";
				moveUp(maze,coord);
				//recursion
			//	traverse(maze,coord);
			}
			else if(maze.checkMove(Coord(coord.m_x+1,coord.m_y)))
			{
//				std::cout<<"move down";
				moveDown(maze,coord);
				//recursion
			//	traverse(maze,coord);
		
			}
			else if(maze.checkMove(Coord(coord.m_x,coord.m_y-1)))
			{
//				std::cout<<"move left";
				moveLeft(maze,coord);
				//recursion
			//	traverse(maze,coord);
			}
			else if(maze.checkMove(Coord(coord.m_x,coord.m_y+1)))
			{
//				std::cout<<"move right";
				moveRight(maze,coord);
				//recursion
			//	traverse(maze,coord);
			}
			else
				break;//upto here+++++++++++++++++++++++++=
	
		case 'd':
			if(maze.checkMove(Coord(coord.m_x+1,coord.m_y)))
			{
//				std::cout<<"move down";
				moveDown(maze,coord);
				//recursion
			//	traverse(maze,coord);
		
			}
			else if(maze.checkMove(Coord(coord.m_x-1,coord.m_y)))
			{
//				std::cout<<"move up";
				moveUp(maze,coord);
				//recursion
			//	traverse(maze,coord);
			}
			else if(maze.checkMove(Coord(coord.m_x,coord.m_y-1)))
			{
//				std::cout<<"move left";
				moveLeft(maze,coord);
				//recursion
			//	traverse(maze,coord);
			}
			else if(maze.checkMove(Coord(coord.m_x,coord.m_y+1)))
			{
//				std::cout<<"move right";
				moveRight(maze,coord);
				//recursion
			//	traverse(maze,coord);
			}
			else	
				break;//upto here++++++++++++++++++++++++

		case 'l':
			if(maze.checkMove(Coord(coord.m_x,coord.m_y-1)))
			{
//				std::cout<<"move left";
				moveLeft(maze,coord);
				//recursion
			//	traverse(maze,coord);
			} 
			else if(maze.checkMove(Coord(coord.m_x-1,coord.m_y)))
			{
//				std::cout<<"move up";
				moveUp(maze,coord);
				//recursion
			//	traverse(maze,coord);
			}
			else if(maze.checkMove(Coord(coord.m_x+1,coord.m_y)))
			{
//				std::cout<<"move down";
				moveDown(maze,coord);
				//recursion
			//	traverse(maze,coord);
		
			}
			else if(maze.checkMove(Coord(coord.m_x,coord.m_y+1)))
			{
//				std::cout<<"move right";
				moveRight(maze,coord);
				//recursion
			//	traverse(maze,coord);
			}
			else
				break;//upto here++++++++++++++++++++++++

		case 'r':
			if(maze.checkMove(Coord(coord.m_x,coord.m_y+1)))
			{
//				std::cout<<"move right";
				moveRight(maze,coord);
				//recursion
			//	traverse(maze,coord);
			}
			else if(maze.checkMove(Coord(coord.m_x-1,coord.m_y)))
			{
//				std::cout<<"move up";
				moveUp(maze,coord);
				//recursion
			//	traverse(maze,coord);
			}
			else if(maze.checkMove(Coord(coord.m_x+1,coord.m_y)))
			{
//				std::cout<<"move down";
				moveDown(maze,coord);
				//recursion
			//	traverse(maze,coord);
		
			}
			else if(maze.checkMove(Coord(coord.m_x,coord.m_y-1)))
			{
//				std::cout<<"move left";
				moveLeft(maze,coord);
				//recursion
				//traverse(maze,coord);
			}
			else
				break;//upto here+++++++++++++++++++++++++=
	
	}
	if(!(coord.m_x==test.m_x&&coord.m_y==coord.m_y))
		traverse(maze,coord);//______________________

	return ;	
}

int randPositX()
{
	return std::rand()%c_row;
}
int randPositY()
{
	return std::rand()%c_col;
}
int main()
{
	std::srand(time(0));
	Coord coord(randPositX(),randPositY());//position 
	Maze maze;
//	std::cout<<maze;
//	maze.markPosit(coord);	
	//setting all around 5,5 to visited
//	maze.markVisited(Coord(4,5));
//	maze.markVisited(Coord(6,5));
//	maze.markVisited(Coord(5,4));
//	maze.markVisited(Coord(4,6));
//	maze.markVisited(Coord(5,5));
//     while(1)	
	traverse(maze,coord);
	Coord finalCoord(randPositX(),randPositY());
	maze.markPosit(finalCoord);
	maze.markPosit(Coord(randPositX(),randPositY()));
	std::cout<<maze;	
	return 0;
}
