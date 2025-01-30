#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << " [DEBUG]\n I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void)
{
	std::cout << " [INFO]\n I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning(void)
{
	std::cout << " [WARNING]\n I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void)
{
	std::cout << " [ERROR]\n This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::complaing(std::string level)
{
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	bool barrier = false;
	void (Harl::*ptrToMemberFunction[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level || barrier)
		{
			barrier = true;
			(this->*ptrToMemberFunction[i])();
		}
	}
	if (!barrier)
		std::cout << "??????????????? " << std::endl;
}
