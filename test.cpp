#include <iostream>
#include <string>
#include <limits>

bool type;



struct customerdetails
{
    std::string Name;
    std::string ic_passport;
    int age;
    int purchaseType;
    bool studentType; 
};


void getFirstInput(customerdetails* temp)
{
    std::string yes_no;
    std::cout << "Enter name: ";
    std::cin >> (*temp).Name;
    std::cout << "Enter your ic or passpport number: ";
    std::getline(std::cin >> std::ws , (*temp).ic_passport);
    //for some reason its infinitely looping if temp.age = char 
    do{
    std::cout << "Enter your age";
    std::cin >> (*temp).age;
    }
    while((*temp).age >0 && std::isdigit((*temp).age));
    do
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        
        std::cout << "Enter your student status: yes / no: ";
        std::cin >> yes_no;
        if(yes_no == "yes")
        {
            (*temp).studentType = true;
        }
        if(yes_no == "no")
        {
            (*temp).studentType = false;
        }
        
    }while (yes_no != "yes" && yes_no !="no");


}

int main()
{
    customerdetails example;
    getFirstInput(&example);

    std::cout << "tetx" << example.Name << '\n' << example.ic_passport << '\n' << example.age << '\n' << example.studentType ;

}