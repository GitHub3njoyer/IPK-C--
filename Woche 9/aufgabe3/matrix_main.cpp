#include "matrix.hh"

int main(int argc, char const *argv[])
{
    // testen der print Funktion
    Matrix<int, 2, 5> matrix1;
    matrix1.print();
    std::cout << "------------------" << std::endl;

    // testen der get Funktion
    matrix1.get(1, 1) = 5;
    std::cout << matrix1.get(1, 1) << std::endl;
    matrix1.print();
    std::cout << "------------------" << std::endl;

    // testen der transpose Funktion
    Matrix<int, 5, 2> matrix2 = matrix1.transpose();
    matrix2.print();
    std::cout << "------------------" << std::endl;

    // testen der add Funktion
    Matrix<int, 3, 4> matrix3;
    Matrix<int, 3, 4> matrix4;
    matrix3.get(1, 1) = 5;
    matrix4.get(0, 3) = 2;
    Matrix<int, 3, 4> addMatrix = matrix3.add(matrix4);
    addMatrix.print();
    std::cout << "------------------" << std::endl;

    // testen der sub Funktion
    Matrix<int, 3, 4> matrix5;
    Matrix<int, 3, 4> matrix6;
    matrix5.get(1, 1) = 5;
    matrix6.get(0, 3) = 2;
    Matrix<int, 3, 4> subMatrix = matrix5.sub(matrix6);
    subMatrix.print();
    std::cout << "------------------" << std::endl;

    // testen der multiply Funktion
    Matrix<int, 2, 3> matrix7;
    Matrix<int, 3, 5> matrix8;
    matrix7.get(0, 0) = 2;
    matrix8.get(0, 0) = 3;
    matrix7.get(0, 1) = 1;
    matrix8.get(1, 0) = 2;
    Matrix<int, 2, 5> matrix9 = matrix7.multiply<5>(matrix8);
    matrix9.print();
    std::cout << "------------------" << std::endl;

    // testen des Konstruktors der ein vector annimmt
    std::vector<std::vector<int>> vector1 = {{1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}};
    Matrix<int, 2, 5> matrix10(vector1);
    matrix10.print();
    std::cout << "------------------" << std::endl;

    int array1[3][7] = {{2, 2, 2, 2, 2, 2, 2}, {4, 4, 4, 4, 4, 4, 4}, {3, 3, 3, 3, 3, 3, 3}};
    Matrix <int, 3, 7> matrix11(array1);
    matrix11.print();
    std::cout << "------------------" << std::endl;

    return 0;
}
