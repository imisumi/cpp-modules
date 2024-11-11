#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), m_Target(target)
{
}

const std::string& PresidentialPardonForm::getTarget() const
{
	return m_Target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	validateExecution(executor);
	std::cout << m_Target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}