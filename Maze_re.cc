#include "Maze_re.h"

bool Maze::checkMove(const Coord &coord)
{
			if(coord.m_x<0||coord.m_x>=c_row||coord.m_y<0||coord.m_y>=c_col)
				return 0;
			else if((m_board[coord.m_x][coord.m_y]).m_visited)
				return 0;
			else
				return 1;
}
//friend functions
std::ostream& operator<<(std::ostream &cout,Maze &maze)
{
	std::cout<<"\n";
	for(int row(0);row<c_row;++row)	
	{
		//for up wall
		for(int col(0);col<c_col;++col)
		{
			if((maze(row,col)).m_up_flag)
				cout<<(maze(row,col)).m_up;
			else 
				cout<<(maze(row,col)).m_up_broken;
		}
		cout<<"+\n";
		
		for(int col(0);col<c_col;++col)
		{
			//for left wall
			if((maze(row,col)).m_left_flag)
				cout<<(maze(row,col)).m_left;
			else
				cout<<(maze(row,col)).m_left_broken;
			//for gap/filled region
			if((maze(row,col)).m_filled_status)
				cout<<(maze(row,col)).m_filled;
			else
				cout<<(maze(row,col)).m_unfilled;			
		}
		cout<<"|\n";

	}
	//for down wall
	for(int var(0);var<c_col;++var)
		cout<<"+---";
	cout<<"+\n";
}
