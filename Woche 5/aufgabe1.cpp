#include <iostream>


// Aufgabe 1
// Collatz-Folge

// (a)
bool isEven (unsigned int number) {
    return (number % 2)== 0;
}

// (b)
void collatz (unsigned int number) {
    while (number != 0 && number != 1){
        std::cout << number << std::endl;
        if (isEven(number)){
            number = number / 2;
        } else {
            number = (number * 3) + 1;
        }
    }
    std::cout << number << std::endl;
}

// (c)
void collatzWithCin () {
    unsigned int collatzNumber;
    std::cout << "Collatz number: ";
    std::cin >> collatzNumber;
    collatz(collatzNumber);
}



int main()
{
    collatzWithCin();
    return 0;
}
