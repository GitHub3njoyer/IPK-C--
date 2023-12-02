#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// (a)
void print (std::vector <double> & a){
    if (a.empty()) {
        std::cout << "[]" << std::endl;
    } else {
        std::cout << "[";
        for (int i = 0; i < a.size() - 1; i++){
            std::cout << a[i];
            std::cout << ", ";
        }
        std::cout << a[a.size() - 1];
        std::cout << "]" << std::endl;
    }
}

// (b)
double median (std::vector <double> a){
    if (!a.empty()) {
        std::sort(a.begin(), a.end());
        if (a.size() % 2 == 1) {
            return a[(int) a.size() / 2];
        } else {
            return a[a.size() / 2];
        }
    } else {
        return 0;
    }
}

// (c)
void sin (std::vector <double> & a) {
    for (int i = 0; i < a.size(); i++) {
        a[i] = std::sin(a[i]);
    }
}

// (d)
std::vector<double> sums (std::vector<std::vector<double>> a) {
    
    std::vector<double> sumVector;
    sumVector.resize(a.size());
    
    for (int i = 0; i < a.size(); i++){
        double sumEinzelnesElement = 0;
        for (int j = 0; j < a[i].size(); j++){
            sumEinzelnesElement += a[i][j];
        }
        sumVector[i] = sumEinzelnesElement;
    }        
    return sumVector;
}

// (e)
int main(int argc, char const *argv[])
{
    std::vector <double> vectorEinfachLeer {};
    std::vector <double> vectorEinfachGerade {1.444, 2.66, 0.444, 4.33};
    std::vector <double> vectorEinfachUngerade {1.444, 2.66, 0.444, 4.33, 1.99};

    std::vector <std::vector<double>> vectorDoppeltLeer1 {};
    std::vector <std::vector<double>> vectorDoppeltLeer2 {{}, {}, {}};
    std::vector <std::vector<double>> vectorDoppelt {{1.444, 2.66}, {1.0, 4.0}, {6.88, 1.12}};

    print(vectorEinfachLeer);

    std::cout << "---------------------------------------" << std::endl;
    print(vectorEinfachGerade);
    std::cout << "Median bei gerader Anzahl: ";
    std::cout << median(vectorEinfachGerade) << std::endl;

    std::cout << "---------------------------------------" << std::endl;
    print(vectorEinfachUngerade);
    std::cout << "Median bei ungerader Anzahl: ";
    std::cout << median(vectorEinfachUngerade) << std::endl;

    std::cout << "---------------------------------------" << std::endl;
    print(vectorEinfachGerade);
    std::cout << "Sinus Werte von einem Vector: " << std::endl;
    sin(vectorEinfachGerade);
    print(vectorEinfachGerade);

    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Summe eines leeren Vector 1: " << std::endl;
    std::vector <double> sumVector1 = sums(vectorDoppeltLeer1);
    print(sumVector1);

    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Summe eines leeren Vector 2: " << std::endl;
    std::vector <double> sumVector2 = sums(vectorDoppeltLeer2);
    print(sumVector2);

    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Summe eines doppelten Vectors: " << std::endl;
    std::vector <double> sumVector3 = sums(vectorDoppelt);
    print(sumVector3);

    return 0;
}
