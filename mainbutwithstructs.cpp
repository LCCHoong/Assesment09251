#include <iostream>
#include <string>
//genuinely feel like im overcomplicating stuff , for fun 

//create a struct that has the required attributes
struct product
{
   int prodCode;
   std::string prodName;
   int basePrice;
   int earlyDisc;
   int studentDisc;
   int seniorDisc;
};
//struct for customer details
struct customerdetails
{
    std::string Name;
    std::string ic_passport;
    int age;
    int purchaseType;
    bool studentType; 
};

//create array for each value of each attribute in the table
int prodCode [6] { 1 , 2 ,3 , 4 ,5 ,6};
std::string prodName [6] {"Smartwatch Pro" , "Wireless Earbuds" ,"Smart Home Kit" ,"Gaming Keyboard","4K Action Camera","Portable Projector"};
int basePrice [6] {350 ,200 ,500, 250,800,600};
int earlyDisc [6] {10 , 12 ,15 ,8 ,10 ,12 };
int studentDisc [6] {15 , 10 ,12 ,10 ,8 ,10};
int seniorDisc [6] {5, 5,8 ,5,6,7, };

//function to check if customer is done (can definitely be optimised)
bool isDone()
{
    int x ;
    while (x != 1 && x != 0)
    {
        std::cout << "Are ya done shopping ?\nEnter 1 if yes , enter 0 if not ";
        std::cin >>x ;
        if(x == 1)
        {
            return 1;
        }
        else if(x == 0)
        {
            return 0;
        }
        else
        {
            std::cout << "Please only enter either 1 or 0\n";
        }
    }
    if(x ==1 )
    {
        return true;
    }
    else{
        return false;
    }
   
}

//global array of products
struct product prodarray[6];

//function to initiallsed to global array
void structshittery()
{
    
    for(int iii = 0; iii < 6 ; iii++)
    {
        prodarray[iii].prodCode = prodCode[iii];
        prodarray[iii].prodName = prodName[iii];
        prodarray[iii].basePrice = basePrice[iii];
        prodarray[iii].earlyDisc = earlyDisc[iii];
        prodarray[iii].studentDisc = studentDisc[iii];
        prodarray[iii].seniorDisc = seniorDisc[iii];

    }
}

// function gets a pointer to the customerdetail struct passed into it
// changes the value at the memory address of *temp.Name e.g.
// works for now
void getFirstInput(customerdetails* temp)
{
    std::string yes_no;
    std::cout << "Enter name: ";
    std::cin >> (*temp).Name;
    std::cout << "Enter your ic or passpport number: ";
    std::getline(std::cin >> std::ws , (*temp).ic_passport);
    std::cout << "Enter your age";
    std::cin >> (*temp).age;
    if((*temp).studentType != true && (*temp).studentType != false)
    {
        std::cout << "Enter your student status: yes / no";
        std::cin >> yes_no;
        if(yes_no == "yes")
        {
            (*temp).studentType = true;
        }
        if(yes_no == "no")
        {
            (*temp).studentType = false;
        }
    }

}

//fucntion for repeatable inputs

int main()
{
    customerdetails example ;
    getFirstInput(&example);

    std::cout << "tetx" << example.Name << '\n' << example.ic_passport << '\n' << example.age << '\n' << example.studentType ;
}

/*general loop of main
intialise vars

start is shopping loop
    get customer details
        customer buys stuff
        check isDone
            if isDone = false
                buy more and log 
        if is Done = true
    end shopping loop

calc price

print recipt

*/