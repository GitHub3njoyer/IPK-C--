#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>

int hp = 7;

// (g) Bonusaufgabe
void galgen (int leben) {
    if (leben == 6) {
        std::cout << "          " << std::endl;
        std::cout << "          " << std::endl;
        std::cout << "          " << std::endl;
        std::cout << "          " << std::endl;
        std::cout << "          " << std::endl;
        std::cout << " / \\     " << std:: endl;
    }
    if (leben == 5) {
        std::cout << "          " << std::endl;
        std::cout << "          " << std::endl;
        std::cout << "          " << std::endl;
        std::cout << "          " << std::endl;
        std::cout << "  |       " << std::endl;
        std::cout << " / \\     " << std:: endl;
    }
    if (leben == 4) {
        std::cout << "          " << std::endl;
        std::cout << "          " << std::endl;
        std::cout << "          " << std::endl;
        std::cout << "  |       " << std::endl;
        std::cout << "  |       " << std::endl;
        std::cout << " / \\     " << std:: endl;
    }
    if (leben == 3) {
        std::cout << "          " << std::endl;
        std::cout << "          " << std::endl;
        std::cout << "  |       " << std::endl;
        std::cout << "  |       " << std::endl;
        std::cout << "  |       " << std::endl;
        std::cout << " / \\     " << std:: endl;
    }
    if (leben == 2) {
        std::cout << "          " << std::endl;
        std::cout << "  |       " << std::endl;
        std::cout << "  |       " << std::endl;
        std::cout << "  |       " << std::endl;
        std::cout << "  |       " << std::endl;
        std::cout << " / \\     " << std:: endl;
    }
    if (leben == 1) {
        std::cout << "   ____   " << std::endl;
        std::cout << "  |    |  " << std::endl;
        std::cout << "  |       " << std::endl;
        std::cout << "  |       " << std::endl;
        std::cout << "  |       " << std::endl;
        std::cout << " / \\     " << std:: endl;
    }
    if (leben == 0) {
        std::cout << "   ____   " << std::endl;
        std::cout << "  |    |  " << std::endl;
        std::cout << "  |    O  " << std::endl;
        std::cout << "  |   /|\\" << std::endl;
        std::cout << "  |   / \\" << std::endl;
        std::cout << " / \\     " << std:: endl;
    }
}


// (a)
std::string verstecken (std::string wort){
    std::string wortVersteckt;
    for (int i = 0; i < wort.size(); i++){
        wortVersteckt = wortVersteckt + "_";
    }
    return wortVersteckt;
}

// (b)
bool aufdecken (std::string& wortMomentan, std::string lösung, char buchstabe){
    bool istBuchstabeInLösung = false;
    for (int i = 0; i < wortMomentan.size(); i++){
        if (std::tolower(buchstabe) == std::tolower (lösung[i])) {
            wortMomentan[i] = lösung[i];
            istBuchstabeInLösung = true;
        }
    }
    return istBuchstabeInLösung;
}

// (c)
bool istFertig (std::string wortMomentan, std::string lösung) {
    for (int i = 0; i < wortMomentan.size(); i++){
        if (wortMomentan[i] != lösung[i]) {
            return false;
        }
    }
    return true;
}

// (d)
void gameLoop (std::string lösung) {
    std::string wortMomentan = verstecken(lösung);
    while (true) {
        std::cout << wortMomentan << std::endl;
        char buchstabe;
        std::cin >> buchstabe;
        if (aufdecken(wortMomentan, lösung, buchstabe)){
            if (istFertig(wortMomentan, lösung)){
                std::cout << "Du hast gewonnen!" << std::endl;
                break;
            }
        } else {
            hp--;
            std::cout << "Fehler Alarm! Restliche hp: ";
            std::cout << hp << std::endl;
            galgen(hp); //Bonusaufgabe
            if (hp == 0) {
                std::cout << "Looser hast verloren!" << std::endl;
                break;
            }
        }
    }
}

// (f)
void readFiles (std::vector <std::string>& wordsVector) {
    wordsVector.clear();
    wordsVector.resize(235650);
    std::ifstream file;
    file.open("wortliste.txt");
    for (int i = 0; i < 239650; i++) {
        file >> wordsVector[i];
    }
    file.close();
}


int main()
{
    // (e)
    std::vector<std::string> words{"Hund", "Katze", "Maus", "Schwimmbad", "Motorrad", "Baum", "Informatik"};
    
    // (f)
    readFiles (words);

    // (e)
    std::srand(std::time(nullptr));
    int randomZahl = std::rand() % words.size();
    gameLoop(words[randomZahl]);
    return 0;
}