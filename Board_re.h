//Author David

#ifndef BOARD_RE_H
#define BOARD_RE_H

#include <iostream>

class Maze;
class Board
{
	private:
		//board structures
		//up
		const std::string m_up="+---";
		const std::string m_up_broken="+   ";
		bool m_up_flag;//0-> broken 1-> wall
		//down 
		const std::string m_down="+---";//we are not going to print each time we'll be printing cell this only for bottom line
		bool m_down_flag;//dummy variable 
		//left
		const std::string m_left="|";	
		const std::string m_left_broken=" ";
		bool m_left_flag;//0->broken 1-> wall
		//right
		const std::string m_right="|";
		bool m_right_flag;//dummy variable
		
		//filled spaces
		const std::string m_filled=" # ";
		const std::string m_unfilled="   ";
		bool m_filled_status;//0->unfilled 1->filled
		
		//visited marker
		bool m_visited;//0->not visited 1->visited
		
	public:
		Board()
		:m_up_flag(1),m_down_flag(1),m_left_flag(1),m_right_flag(1),
		m_filled_status(0),m_visited(0)
		{
			//does nothing
		}
		friend Maze;
		friend std::ostream& operator<<(std::ostream &cout,Maze &maze);
};
#endif
