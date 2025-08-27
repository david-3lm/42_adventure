#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery_Form", 145, 137)
{
	_target = "nadie";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery_Form", 145, 137)
{
	_target = target;
} 

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
{
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other) 
	{
		this->_target = other.getTarget();
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (!getSign())
			throw AForm::FormNotSignedException();
		if (executor.getGrade() > getGradeToExecute())
			throw AForm::GradeTooLowException();
		printTree();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void printDirs(std::string path, std::ofstream &out, const std::string& prefix = "├")
{
    DIR* dir = opendir(path.c_str());
    if (!dir) return;

    struct dirent* ent;
    while ((ent = readdir(dir)) != NULL) {
        const char* name = ent->d_name;
        if (std::strcmp(name, ".") == 0 || std::strcmp(name, "..") == 0) continue;

        std::string full = path + "/" + name;

        out << prefix << "─ " << name << "\n";

        struct stat st;
        if (stat(full.c_str(), &st) == 0 && S_ISDIR(st.st_mode)) {
            printDirs(full, out, prefix + "──"); // añade sangría
        }
    }
    closedir(dir);
}

void ShrubberyCreationForm::printTree() const
{
	std::string file(_target + "_shrubbery");
	std::ofstream out(file.c_str());
	if (!out)
	{
        std::cerr << "No se pudo crear tree.txt\n";
        return;
    }
	std::cout << ".\n";
	printDirs(".", out);
}
