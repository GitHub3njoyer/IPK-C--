#include <iostream>

struct myStructure {
    int pi;
    int roottwo;
};

int main(int argc, char const **argv)
{
    myStructure structurevariable;
    myStructure *a = &structurevariable;
    (*a).pi = 5;
    std::cout << (*a).pi << std::endl;
    a->pi = 10;
    std::cout << a->pi << std::endl;

    myStructure *b = new myStructure;
    b->roottwo = 4;
    std::cout << (*b).roottwo << std::endl;
    delete b;

    return 0;
}
