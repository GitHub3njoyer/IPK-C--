#include "temperatur.hh"

Temperatur::Temperatur()
{
    (*this).Kelvin = 0;
}

Temperatur::Temperatur(double Kelvinwert)
{
    (*this).Kelvin = Kelvinwert;
}

double Temperatur::getKelvin() const
{
    return (*this).Kelvin;
}

double Temperatur::getCelsius() const
{
    return (*this).Kelvin - 273.15;
}

double Temperatur::getFahrenheit() const
{
    return ((*this).Kelvin - 273.15) * 1.8 + 32.00;
}

double Temperatur::add(double kelvinWert)
{
    (*this).Kelvin = (*this).Kelvin + kelvinWert;
    return (*this).Kelvin;
}