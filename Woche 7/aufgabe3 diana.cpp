#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>

// Funktion zum Einlesen einer Textdatei und Erstellen des Spielfelds
std::vector<std::vector<bool>> readGameField(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<bool>> gameField;

    if (file.is_open()) {
        std::string line;
        size_t width = 0;

        while (std::getline(file, line)) {
            if (width == 0) {
                width = line.size();
            } else if (line.size() != width) {
                // Überprüfen, ob alle Zeilen die gleiche Länge haben
                std::cerr << "Fehler: Alle Zeilen muessen die gleiche Laenge haben!" << std::endl;
                return {};
            }

            std::vector<bool> row;
            for (char c : line) {
                if (c == 'O') {
                    row.push_back(true); // lebendige Zelle
                } else if (c == ' ') {
                    row.push_back(false); // tote Zelle
                } else {
                    // Ungültiges Zeichen in der Datei
                    std::cerr << "Fehler: Ungueltiges Zeichen in der Datei!" << std::endl;
                    return {};
                }
            }

            gameField.push_back(row);
        }

        file.close();
    } else {
        std::cerr << "Fehler: Datei konnte nicht geoeffnet werden!" << std::endl;
    }

    return gameField;
}

// Funktion zum Updaten einer einzelnen Zelle basierend auf den Regeln
bool updateCell(const std::vector<std::vector<bool>>& gameField, size_t row, size_t col) {
    size_t numRows = gameField.size();
    size_t numCols = gameField[0].size();

    int liveNeighbors = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // die Zelle selbst wird nicht gezählt

            int neighborRow = row + i;
            int neighborCol = col + j;

            // Überprüfen, ob der Nachbar innerhalb des Spielfelds liegt
            if (neighborRow >= 0 && neighborRow < numRows && neighborCol >= 0 && neighborCol < numCols) {
                liveNeighbors += gameField[neighborRow][neighborCol] ? 1 : 0;
            }
        }
    }

    // Anwenden der Regeln
    if (gameField[row][col]) {
        return liveNeighbors == 2 || liveNeighbors == 3;
    } else {
        return liveNeighbors == 3;
    }
}

// Funktion zum Updaten des gesamten Spielfelds
std::vector<std::vector<bool>> updateGameField(const std::vector<std::vector<bool>>& gameField) {
    size_t numRows = gameField.size();
    size_t numCols = gameField[0].size();

    std::vector<std::vector<bool>> newGameField(numRows, std::vector<bool>(numCols, false));

    for (size_t i = 0; i < numRows; ++i) {
        for (size_t j = 0; j < numCols; ++j) {
            newGameField[i][j] = updateCell(gameField, i, j);
        }
    }

    return newGameField;
}

// Funktion zum Ausgeben des Spielfelds auf der Konsole
void printGameField(const std::vector<std::vector<bool>>& gameField) {
    for (const auto& row : gameField) {
        for (bool cell : row) {
            std::cout << (cell ? 'O' : ' ');
        }
        std::cout << std::endl;
    }
}

int main() {
    const std::string filename = "spielfeld.txt";
    const int animationDelay = 100; // in Millisekunden

    std::vector<std::vector<bool>> gameField = readGameField(filename);

    if (gameField.empty()) {
        return 1; // Fehler beim Einlesen des Spielfelds
    }

    while (true) {
        printGameField(gameField);
        std::this_thread::sleep_for(std::chrono::milliseconds(animationDelay));
        std::cout << "\x1B[2J\x1B[H"; // Terminal leeren

        gameField = updateGameField(gameField);
    }

    return 0;
}
