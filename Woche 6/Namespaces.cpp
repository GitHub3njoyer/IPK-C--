#include <iostream>

int main(int argc, char const *argv[])
{
    std::pair <std::string, int> name_and_grade = std::make_pair ("Max", 2);
    std::cout   << "Name: " << name_and_grade.first << std::endl
                << "Note: " << name_and_grade.second << std::endl;
}
