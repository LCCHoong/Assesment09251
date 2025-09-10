#include <iostream>
#include <string>


struct main
{
    /* data */
};


int prodCode [6] { 1 , 2 ,3 , 4 ,5 ,6};
std::string prodName [6] {"Smartwatch Pro" , "Wireless Earbuds" ,"Smart Home Kit" ,"Gaming Keyboard","4K Action Camera","Portable Projector"};
int basePrice [6] {350 ,200 ,500, 250,800,600};
int earlyDisc [6] {10 , 12 ,15 ,8 ,10 ,12 };
int studentDisc [6] {15 , 10 ,12 ,10 ,8 ,10};
int seniorDisc [6] {5, 5,8 ,5,6,7, };


//Display the product list along with pricing and discount rules.
// so either thw whole thing , or just prodCode + prodName + basePrice, do both why not

void printMinimal ()
{
    for(int iii = 0 ; iii < 6 ; iii++)
    {
        std::cout << "Product Code: " << prodCode[iii] << " Product Name: " << prodName[iii] << " Product Price" <<basePrice[iii] <<'\n';
    }    
    
}





int main()
{
    printMinimal();
}