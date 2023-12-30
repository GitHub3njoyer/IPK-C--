#include <iostream>

template <typename T, int i>
class myClass {
    //eine Klasse die zusätzlich ein template hat mit 2 variablen die übergeben werden können.
    private:
        int _value;
    public: 
        myClass(int value) {
            _value = value;
        };
        int getValue(){
            return (*this)._value;
        }
};


//----------------------------------------------------
template <int rows, int colls>
class Matrix {

};

template <int rows>             //wozu ist diese Zeile da?
class Matrix <rows, 1> {

};
//----------------------------------------------------

int main(int argc, char const *argv[])
{
    myClass <double, 5> myObj1(5);
    myClass <double, 10> myObj2(3);
    myClass <double, 10> myObj3(10);

    std::cout << myObj2.getValue() << std::endl;
    myObj2 = myObj3;
    std::cout << myObj2.getValue() << std::endl;
    return 0;
}
