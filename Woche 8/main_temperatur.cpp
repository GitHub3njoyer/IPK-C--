#include "temperatur.hh"
#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << "K = Kelvin" << std::endl;
    std::cout << "C = Grad Celsius" << std::endl;
    std::cout << "F = Grad Fahrenheit" << std::endl;
    char Einheit;
    std::cin >> Einheit;
    std::cout << "Betrag: ";
    double betrag;
    std::cin >> betrag;

    Temperatur temperature;
    //Umrechnen vom Betrag in Kelvin und Einlesen
    if (Einheit == 'K') {
        temperature.add(betrag);
    } else if (Einheit == 'C') {
        temperature.add(betrag + 273.15);
    } else if (Einheit == 'F') {
        temperature.add((betrag - 32) / 1.8 + 273.15);
    }

    std::cout << "Kelvin: " << temperature.getKelvin() << " K" << std::endl;
    std::cout << "Celsius: " << temperature.getCelsius() << " °C" << std::endl;
    std::cout << "Fahrenheit: " << temperature.getFahrenheit() << " °F" << std::endl;
    return 0;
}
