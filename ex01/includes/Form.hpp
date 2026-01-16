//############################################################
//#                                                          #
//#   ██████╗ ██████╗ ███╗   ██╗                             #
//#   ██╔══██╗╚════██╗████╗  ██║                             #
//#   ██████╔╝ █████╔╝██╔██╗ ██║                             #
//#   ██╔══██╗██╔═══╝ ██║╚██╗██║                             #
//#   ██████╔╝███████╗██║ ╚████║                             #
//#   ╚═════╝ ╚══════╝╚═╝  ╚═══╝                             #
//#                                                          #
//#   File    : Form.hpp                                     #
//#   Created : 2026-01-16 18:25                             #
//#   Updated : 2026-01-16 18:25                             #
//#                                                          #
//############################################################

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool sign;
		const int grade_to_sign;
		const int grade_to_execute;

	public:
		Form(const std::string& name, int grade_to_sign, int grade_to_execute);
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);

		std::string getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat& bureaucrat);
	
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