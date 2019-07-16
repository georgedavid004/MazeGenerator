//Author David

#ifndef MAZE_RE_H
#define MAZE_RE_H

#include <iostream>
#include "Board_re.h"

//constants
const int c_row=20;
const int c_col=20;

//Coord class
class Coord
{
	public:
		int m_x, m_y;
		
		Coord(int xx=0,int yy=0):m_x(xx),m_y(yy)
		{
			//does nothing
		}
};

class Maze
{
	private:
		Board m_board[c_row][c_col];
	
	public:
		Maze()
		{
			//does noting
		}
		
//interface
		//functions to modify walls
		void offUpFlag(const Coord &coord)
		{
			(m_board[coord.m_x][coord.m_y]).m_up_flag=0;
		}
		
		void offDownFlag(const Coord &coord)
		{
			(m_board[coord.m_x][coord.m_y]).m_down_flag=0;
		}
		
		void offLeftFlag(const Coord &coord)
		{
			(m_board[coord.m_x][coord.m_y]).m_left_flag=0;
		}
		
		void offRightFlag(const Coord &coord)
		{
			(m_board[coord.m_x][coord.m_y]).m_right_flag=0;

		}

		void markPosit(const Coord &coord)//to mark current position
		{
			(m_board[coord.m_x][coord.m_y]).m_filled_status=1;
		}
			
		void markVisited(const Coord &coord)//to mark position as visited
		{
			(m_board[coord.m_x][coord.m_y]).m_visited=1;
		}
		//to check move	
		bool checkMove(const Coord &coord);
		
//operator overloading
		Board& operator()(int row,int col)
		{
			return m_board[row][col];
		}

//firend functions
		friend std::ostream& operator<<(std::ostream  &cout,Maze &maze);
};


#endif
