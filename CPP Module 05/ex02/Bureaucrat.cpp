#include "Bureaucrat.hpp"
#include "Form.hpp"

class Form;

Bureaucrat::Bureaucrat() : _name("default"), _grade(LOWEST_GRADE){}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade){
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bc){
	*this = bc;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bc){
	if(this != &bc){
		_grade = bc._grade;
		_name = bc._name;
	}
	return *this;
}

std::string const &Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const{
	return _grade;
}

void Bureaucrat::promotion(){
	if (_grade <= HIGHEST_GRADE){
		throw GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::demotion(){
	if (_grade >= LOWEST_GRADE){
		throw GradeTooLowException();
	}
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade too hight";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &os,const Bureaucrat &bc){
	os << bc.getName() << ", bureaucrat grade " << bc.getGrade() << ".";
	return os;
}

void Bureaucrat::signForm(Form &f)const{
	try{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch(std::exception const &e){
		std::cout << _name << " couldn’t sign "<< f.getName() << " because " << e.what() <<" ." << std::endl;
	}
}