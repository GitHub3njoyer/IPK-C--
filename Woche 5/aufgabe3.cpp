#include <iostream>


// Aufgabe 3
// Fibonacci-Zahlen

// (a)
unsigned int fib (unsigned int n) {
    
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

// (b)
unsigned int fibIter (unsigned int n) {
    int result = 0;
    int i = 2;
    int fibEins = 0;
    int fibZwei = 1;    

    if (n == 1) {
        return fibEins;
    }
    if (n == 2) {
        return fibZwei;
    }
    
    while (i < n) {
        result = fibEins + fibZwei;
        fibEins = fibZwei;
        fibZwei = result; 
        i++;
    }
    return result;
}

// (c)
int main(int argc, char const *argv[])
{
    int number;
    std::cout << "Fibonacci-Zahl: ";
    std::cin >> number;

    std::cout << "Die ";
    std::cout << number;
    std::cout << "te Fibonaccizahl wird berechnet:" << std::endl;
    std::cout << "Rekursiv: ";
    std::cout << fib(number) << std::endl;
    std::cout << "Iterativ: ";
    std::cout << fibIter(number) << std::endl;
    return 0;
}