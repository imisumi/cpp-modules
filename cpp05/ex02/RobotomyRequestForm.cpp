#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), m_Target(target)
{
}

const std::string& RobotomyRequestForm::getTarget() const
{
	return m_Target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	validateExecution(executor);
	std::cout << "*drilling noises*" << std::endl;
	if (rand() % 2)
	{
		std::cout << m_Target << " has been robotomized successfully" << std::endl;
	}
	else
	{
		std::cout << m_Target << " robotomization failed" << std::endl;
	}
}