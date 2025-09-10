#include <iostream>
#include <string>

struct product
{
   int prodCode;
   std::string prodName;
   int basePrice;
   int earlyDisc;
   int studentDisc;
   int seniorDisc;
};


//create array for each value of each attribute in the table
int prodCode [6] { 1 , 2 ,3 , 4 ,5 ,6};
std::string prodName [6] {"Smartwatch Pro" , "Wireless Earbuds" ,"Smart Home Kit" ,"Gaming Keyboard","4K Action Camera","Portable Projector"};
int basePrice [6] {350 ,200 ,500, 250,800,600};
int earlyDisc [6] {10 , 12 ,15 ,8 ,10 ,12 };
int studentDisc [6] {15 , 10 ,12 ,10 ,8 ,10};
int seniorDisc [6] {5, 5,8 ,5,6,7, };


//Display the product list along with pricing and discount rules.
/*void printMinimal ()
{
    for(int iii = 0 ; iii < 6 ; iii++)
    {
        std::cout << "|Product Code: " << prodCode[iii] << "| |Product Name: " << prodName[iii] << "| |Product Price: " <<basePrice[iii] <<"|\n";
    }    
    
}*/

//allow multiple purchases in a single transaction
/*bool isDone()
{
    int x ;
    while (x != 1 || x != 0)
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
   
}*/

//For each customer, collect the following details:
//so , more choice , new global vars or define something new
//so even more things to wonder about , the must be unique either means that ever login have to be saved 
//external memory and read back so total unique purchases can be made
//https://cplusplus.com/doc/tutorial/files/

/*  
Name -string
IC/Passport Number (must be unique) -int
Age -int
Product Code  1 >= int <= 6
Purchase Type (Early Bird / Normal) int x, y
Student status (Yes/No).    int x ,y 
*/

struct product prodarray[6];

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

int main()
{
    structshittery();
    
    for(int iii =0 ; iii < 6 ; iii++)
    {
        std::cout << prodarray[iii].prodCode <<prodarray[iii].prodName <<prodarray[iii].basePrice <<prodarray[iii].earlyDisc <<prodarray[iii].studentDisc <<prodarray[iii].seniorDisc <<'\n';
    }
    
}