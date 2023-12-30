#include <iostream>
#include <string>

void print (std::string message) {
    std::cout << message << std::endl;
}

int main(int argc, char const *argv[])
{
    std::string greeting = "Hello, world!";
    print(greeting);
    return 0;
}
