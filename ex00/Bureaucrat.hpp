//############################################################
//#                                                          #
//#   ██████╗ ██████╗ ███╗   ██╗                             #
//#   ██╔══██╗╚════██╗████╗  ██║                             #
//#   ██████╔╝ █████╔╝██╔██╗ ██║                             #
//#   ██╔══██╗██╔═══╝ ██║╚██╗██║                             #
//#   ██████╔╝███████╗██║ ╚████║                             #
//#   ╚═════╝ ╚══════╝╚═╝  ╚═══╝                             #
//#                                                          #
//#   File    : Bureaucrat.hpp                               #
//#   Created : 2026-01-16 17:12                             #
//#   Updated : 2026-01-16 17:12                             #
//#                                                          #
//############################################################

#include <string>
#include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		
		const std::string& getName() const;
		int	getGrade() const;
	

		void incrementGrade();
		void decrementGrade();

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Grade is too high!";
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Grade is too low!";
			}
	};

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);