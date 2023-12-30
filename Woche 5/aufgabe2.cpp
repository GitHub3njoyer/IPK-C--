#include <iostream>
#include <cmath>


// Aufgabe 2
// Berechnung Quadratischer Gleichngen mit der pq Formel

int main(int argc, char const *argv[])
{
    double p;
    double q;
    double x1;
    double x2;

    // (a)
    std::cout << "p: ";
    std::cin >> p;
    std::cout << "q: ";
    std::cin >> q;

    // (b)
    double diskriminante = ((p / 2) * (p / 2)) - q;

    // (c)
    if (diskriminante < 0) {
        return 1;
    }
    if (diskriminante == 0) {
        x1 = - (p / 2) + 0;
        x2 = - (p / 2) - 0;

        std::cout << "x1: ";
        std::cout << x1 << std::endl;
        std::cout << "x2: ";
        std::cout << x2 << std::endl;

        return 0;
    }

    // (d)
    x1 = - (p / 2) + std::sqrt(diskriminante);
    x2 = - (p / 2) - std::sqrt(diskriminante);
    
    std::cout << "x1: ";
    std::cout << x1 << std::endl;
    std::cout << "x2: ";
    std::cout << x2 << std::endl;

    return 0;
}
