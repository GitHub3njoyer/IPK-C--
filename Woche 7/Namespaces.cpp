#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    pair <string, int> name_and_grade = make_pair ("Max", 2);
    cout   << "Name: " << name_and_grade.first << endl
                << "Note: " << name_and_grade.second << endl;
}
