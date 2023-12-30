#include <iostream>
#include <list>

//print Fnktion zum testen
void printList (std::list <int> a) {
    for (int intZahl : a) {
        std::cout << intZahl << " ";
    }
    std::cout << std::endl;
}

// (a)
void reverseList (std::list <int> &a) {
    
    std::list<int>::iterator pointerA = a.begin();
    std::list<int>::iterator pointerB = std::prev(a.end());

    for (int i = 0; i < (a.size()/2); i++) {
        std::swap (*pointerA, *pointerB);
        pointerA++;
        pointerB--;
    }
}

// (b)
void zigzag (std::list <int> &a){
    
    std::list <int> copyOfa = a;
    copyOfa.sort();
    a.clear();

    while (copyOfa.size() >= 1) {
        if (copyOfa.size() > 1) {
            a.push_back(*copyOfa.begin());
            copyOfa.pop_front();
            a.push_back(*std::prev(copyOfa.end()));
            copyOfa.pop_back();
        } else {
            a.push_back(*copyOfa.begin());
            copyOfa.pop_front();
        }
    }    
}

int main(int argc, char const *argv[])
{
    std::list <int> listLeer {};
    std::list <int> listGerade {2, 3, 9, 6, 8, 7, 1, 4};
    std::list <int> listUngerade {2, 3, 9, 6, 8, 7, 1};
    
    //reverse Funktion
    printList(listLeer);
    reverseList(listLeer);
    printList(listLeer);
    std::cout << "-----------------------" << std::endl;
    
    printList(listGerade);
    reverseList(listGerade);
    printList(listGerade);
    std::cout << "-----------------------" << std::endl;

    printList(listUngerade);
    reverseList(listUngerade);
    printList(listUngerade);
    std::cout << "-----------------------" << std::endl;

    //zigzag Funktion
    printList(listLeer);
    zigzag(listLeer);
    printList(listLeer);
    std::cout << "-----------------------" << std::endl;
    
    printList(listGerade);
    zigzag(listGerade);
    printList(listGerade);
    std::cout << "-----------------------" << std::endl;

    printList(listUngerade);
    zigzag(listUngerade);
    printList(listUngerade);
    std::cout << "-----------------------" << std::endl;

    return 0;
}
