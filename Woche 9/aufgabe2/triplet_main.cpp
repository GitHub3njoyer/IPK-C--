#include "triplet.hh"
#include <iostream>

int main(int argc, char const *argv[])
{
    Triplet <int, float, char> myObj (42, 3.14, 'F');

    //Ausgabe der Startwerte
    std::cout << myObj.first() << "\n";
    std::cout << myObj.second() << "\n";
    std::cout << myObj.third() << "\n";

    //alle Werte einmal neu setzen
    myObj.setFirst(10);
    myObj.setSecond(2.5555);
    myObj.setThird('?');

    //Ausgabe der neuen Werte
    std::cout << myObj.first() << "\n";
    std::cout << myObj.second() << "\n";
    std::cout << myObj.third() << "\n";
    
    return 0;
}
