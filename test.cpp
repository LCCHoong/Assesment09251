#include <iostream>
#include <string>


struct customerdetails
{
    std::string Name;
};

customerdetails getInput()
{
    customerdetails temp;
    std::cout << "Enter name: ";
    std::getline(std::cin >> std::ws , temp.Name);
    return temp;
}

int main() {
    customerdetails c = getInput();
    std::cout << "You entered: " << c.Name << std::endl;
    return 0;
}