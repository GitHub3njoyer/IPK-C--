#include <iostream>
#include <fstream>



// (a)
std::vector<std::vector<bool>> startSpielfeld () {

    std::ifstream file;
    file.open("spielfeld.txt");
    std::vector<std::vector<bool>> spielfeldVector;
    std::vector<std::vector<bool>> leererVector;
    std::vector<bool> line;

    while (file) {
        while (file.peek() == ' ' || file.peek() == '0') {
            if (file.peek() == ' ') {
                line.push_back(false);
                file.get();
            }
            if (file.peek() == '0') {
                line.push_back(true);
                file.get();
            }
        }

        if (file.peek() == '\n') {
            file.get();
            spielfeldVector.push_back(line);
            line.clear();
        } 
        
        if (file.peek() != ' ' && file.peek() != '0' && file.peek() != '\n' && file.peek() != -1){ //-1 steht für das letzte Element?
            return leererVector;
        }
           
    }
    spielfeldVector.push_back(line);


    //checken ob jede Zeile die gleiche länge hat
    bool istRechteckig = true;
    int ersteLinieSize = spielfeldVector[0].size();
    for (int i = 0; i < spielfeldVector.size(); i++) {
        if (ersteLinieSize != spielfeldVector[i].size()) {
            istRechteckig = false;
        }
    }
    
    if(istRechteckig) {
        return spielfeldVector;
    } else {
        return leererVector;
    }
}


// (b)
std::vector<std::vector<bool>> updateEinzeleneZelle (std::vector<std::vector<bool>> feld, int a, int b) {

    //zählen wie viele lebendige nachbarn eine zelle hat
    int anzahlLebendigerNachbarn = 0;
    
    
    //update der zelleZustand
    bool zelleZustand = feld[a][b];
    if (zelleZustand) { //also gerade am leben
        if (anzahlLebendigerNachbarn == 3 || anzahlLebendigerNachbarn == 2) {
            zelleZustand = true;
        } else {
            zelleZustand = false;
        }
    } else {            //also gerade Tod
        if (anzahlLebendigerNachbarn == 3) {
            zelleZustand = true;
        } else {
            zelleZustand = false;
        }
    }
    //ruckgabe des vector mit update der neuen Zelle
    feld[a][b] = zelleZustand;
    return feld;
 }


// (c)
void printSpielfeld(std::vector<std::vector<bool>> feld) {
    for (int j = 0; j < feld.size(); j++) {
        for (int i = 0; i < feld[j].size(); i++) {
            if (feld[j][i]) {
                std::cout << '0';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    } 
}    


int main() {
    printSpielfeld(startSpielfeld());
    return 0;
}
