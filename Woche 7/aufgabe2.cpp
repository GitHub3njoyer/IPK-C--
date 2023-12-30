#include <iostream>
#include <unordered_map>

// print Funktion zum testen
void printMap (std::unordered_map <std::string, std::string> a){
    std::unordered_map<std::string, std::string>::iterator PointerA = a.begin();
}

// (a)
// Rückgabewert ist true, dann hat das hinzufügen geklappt
bool createUser(std::unordered_map <std::string, std::string> &a, std::string username, std::string password) {
    if (a.find(username) == a.end()) {
        a.insert({username, password});
        return true;
    }
    return false;
}

bool authenticateUser(std::unordered_map <std::string, std::string> a, std::string username, std::string password) {
    return (a.find(username) != a.end()) &&  (a[username] == password);
}


// (c) ??????????
size_t hashPassword (std::string a) {
    std::hash<std::string> hashCode;    
}

// (d)
void listUsers (std::unordered_map <std::string, std::string> a) {
    std::unordered_map <std::string, std::string>::iterator pointerA = a.begin();
    std::unordered_map <std::string, std::string>::iterator pointerB = a.end();

    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Liste aller Benutzernamen und deren Passwort:" << std::endl;
    while (pointerA != pointerB) {
        std::cout << (*pointerA).first << " " << (*pointerA).second << std::endl;
        pointerA++;
    }
}

// (e)
void changePassword (std::unordered_map <std::string, std::string> &a, std::string user, std::string neuesPasswort) {
    a[user] = neuesPasswort;
}


int main(int argc, char const *argv[])
{
    std::unordered_map <std::string, std::string> a {{"admin", "adminpasswort"}};
    
    while (true) {
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "Wählen sie Ihre Option aus:" << std::endl;
        std::cout << "1 für Registrierung" << std::endl;
        std::cout << "2 für Log-In" << std::endl;
        std::cout << "3 um das Programm zu beenden" << std::endl;
        int option = 0;
        std::cin >> option;

        if (option == 1) {
            std::cout << "Neuer Username: ";
            std::string username;
            std::cin >> username;
            std::cout << "Neues Passwort: ";
            std::string passwort;
            std::cin >> passwort;
            createUser(a, username, passwort);
            std::cout << "Neuer Benutzer erfolgreich erstellt!" << std::endl;
        } else if (option == 2){
            std::cout << "Username ";
            std::string username;
            std::cin >> username;
            std::cout << "Passwort ";
            std::string passwort;
            std::cin >> passwort;
            if (authenticateUser(a, username, passwort)) {
                if (username == "admin" && passwort == a["admin"]) {
                    listUsers(a);
                } else {
                    std::cout << "Erfolgreich eingelogt" << std::endl;
                    std::cout << "Neues Passwort? 1 für JA, 2 für NEIN!" << std::endl;
                    int m;
                    std::cin >> m;
                    if (m == 1) {
                        std::cout << "Neues Passwort: " << std::endl;
                        std::string passwortNew;
                        std::cin >> passwortNew;
                        changePassword(a, username, passwortNew);
                    }
                }
            } else {
                std::cout << "Benutzer oder Passwort falsch!" << std::endl;
            }
            
        } else if (option == 3) {
            break;
        }
    }
    return 0;
}