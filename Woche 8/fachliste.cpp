#include "fachliste.hh"

FachListe::FachListe()
{
}
FachListe::FachListe(std::vector<Fach> faecher)
{
    for (int i = 0; i < faecher.size(); i++) {
        (*this)._faecher[i] = faecher[i];
    }
}

void FachListe::addFach(Fach fach) {
    (*this)._faecher.push_back(fach);
}

unsigned int FachListe::summeECTS() {
    unsigned int summeECTS = 0;
    for (int i = 0; i < (*this)._faecher.size(); i++) {
        if ((*this)._faecher[i].bestanden()) {
            summeECTS = summeECTS + (*this)._faecher[i].getECTS();
        }
    }
    return summeECTS;
}

double FachListe::durchschnitt() {
    return summeECTS() / (*this)._faecher.size();
}

std::vector<std::string> FachListe::list() {
    std::vector<std::string> a;
    return a;
}

bool FachListe::noteEintragen(std::string kuerzel, double note) {
    for (int i = 0; i < (*this)._faecher.size(); i++) {
        if ((*this)._faecher[i].getKuerzel() == kuerzel) {
            (*this)._faecher[i].noteEintragen(note);
            return true;
        }
    }
    return false;
}

/*
FachListe();
    FachListe(std::vector<Fach> faecher); // trägt die Fächer in faecher direkt in _faecher ein.
    void addFach(Fach fach); // fügt fach zu _faecher hinzu
    unsigned int summeECTS(); // summiert die ECTS aller bestandenen Fächer
    double durchschnitt(); // nach ECTS gewertete Summe aller bestandenen Fächer
    std::vector<std::string> list(); // gibt vector von Zustandsbeschreibungen aller Fächer zurück
    bool noteEintragen(std::string kuerzel, double note); // trägt für (das erste) Fach mit Kürzel kuerzel die Note note ein; gibt genau dann true zurück, wenn das funktioniert hat

*/