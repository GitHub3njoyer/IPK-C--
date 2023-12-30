#include "fach.hh"

Fach::Fach(std::string name, std::string kuerzel, unsigned int ects)
{
    (*this).name = name;
    (*this).kuerzel = kuerzel;
    (*this).ects = ects;
    (*this).name = 0.0;
}

bool Fach::noteEintragen(double note)
{
    if (!bestanden())
    {
        if (note >= 1.0 && note <= 5.0)
        {
            (*this).note = note;
        }
        return true;
    }
    return false;
}

bool Fach::bestanden() const
{
    return (*this).note >= 0.0 && (*this).note <= 6.0;
}

double Fach::gewerteteNote() const {
    if (bestanden()) {
        return (*this).note * (*this).ects;
    } else {
        return 0;
    }
}

unsigned int Fach::getECTS() const {
    if (bestanden()) {
        return (*this).ects;
    } else {
        return 0;
    }
}

std::string Fach::getName() const {
    return (*this).name;
}

std::string Fach::getKuerzel() const {
    return (*this).kuerzel;
}

std::string Fach::toString() const {
    if (bestanden()) {
        return "KÜR (" + (*this).name + ") [" + std::to_string(getECTS()) + "]: " + std::to_string((*this).note);
    } else {
        return "KÜR (" + (*this).name + ") [" + std::to_string(getECTS()) + "]: ";
    }
}