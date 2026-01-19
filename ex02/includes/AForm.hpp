//############################################################
//#                                                          #
//#   ██████╗ ██████╗ ███╗   ██╗                             #
//#   ██╔══██╗╚════██╗████╗  ██║                             #
//#   ██████╔╝ █████╔╝██╔██╗ ██║                             #
//#   ██╔══██╗██╔═══╝ ██║╚██╗██║                             #
//#   ██████╔╝███████╗██║ ╚████║                             #
//#   ╚═════╝ ╚══════╝╚═╝  ╚═══╝                             #
//#                                                          #
//#   File    : AForm.hpp                                     #
//#   Created : 2026-01-16 18:25                             #
//#   Updated : 2026-01-16 18:25                             #
//#                                                          #
//############################################################

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string _name;
		bool sign;
		const int grade_to_sign;
		const int grade_to_execute;

	public:
		AForm(const std::string& name, int grade_to_sign, int grade_to_execute);
		~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

		std::string getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat& bureaucrat);
		void execute(Bureaucrat const&) const;
		virtual void executeAction() const = 0;
	
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
	class FormNotSign : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Form is not signed";
			}
	};
	class CannotExecute : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Form cannot be executed";
			}
	};
};