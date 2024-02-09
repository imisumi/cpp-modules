#pragma once
#include <iostream>
#include <iomanip>

class Harl
{
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		// function pointer
		void(Harl::*m_Functions[4])(void);
};
