#include <iostream>
#include <string>
#include <limits>

// create array for each value of each attribute in the table
int prodCode[6]{1, 2, 3, 4, 5, 6};
std::string prodName[6]{"Smartwatch Pro", "Wireless Earbuds", "Smart Home Kit", "Gaming Keyboard", "4K Action Camera", "Portable Projector"};
int basePrice[6]{350, 200, 500, 250, 800, 600};
int earlyDisc[6]{10, 12, 15, 8, 10, 12};
int studentDisc[6]{15, 10, 12, 10, 8, 10};
int seniorDisc[6]{
    5,
    5,
    8,
    5,
    6,
    7,
};

// Display the product list along with pricing + discount rules
void displayProdcuts()
{
    for (int iii = 0; iii < 6; iii++)
    {
        std::cout << "|Product Code:" << prodCode[iii] << "| |Product Name:" << prodName[iii] << "| |Product Price:" << basePrice[iii] << "|" << "| |Early Bird Discount :" << earlyDisc[iii]
                  << "%| |Student Discount :" << studentDisc[iii] << "%| |Senior Discount :" << seniorDisc[iii] << "% |\n";
    }

    // if time pretty tables for now just one liner
    // very pretty-able
}

bool isDone()
{
    // promt user isDone , if done return true else return false
    int value;
    std::cout << "Enter 1 to continue shopping , enter 2 to stop shopping: \n";
    while (!(std::cin >> value) || (value != 1 && value != 2))
    {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        std::cout << "Invalid input. Please enter a positive integer: \n";
    }
    if(value == 1)
    {
        return false;
    }
    return true;
}

int main()
{
    bool bol = isDone();

    std::cout << bol;

}
