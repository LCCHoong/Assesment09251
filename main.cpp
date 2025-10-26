#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <iomanip>


// create array for each value of each attribute in the table , each value should be tied to prodcode 1-6 (0-5)
int const prodCode[6]{1, 2, 3, 4, 5, 6};//product code 1-6 (0-5)
std::string const prodName[6]{"Smartwatch Pro", "Wireless Earbuds", "Smart Home Kit", "Gaming Keyboard", "4K Action Camera", "Portable Projector"};
//product names
float const basePrice[6]{350, 200, 500, 250, 800, 600};//base product price
float const couponDisc[6]{10, 12, 15, 8, 10, 12};//discount spplied with valid coupon code
float const studentDisc[6]{15, 10, 12, 10, 8, 10};//discount applied if customer is student
float const seniorDisc[6]{5,5,8,5,6,7};//discount applied if customer >= 60



// Display the product list along with pricing + discount rules
void displayProducts() {
    std::cout << "\n" << std::string(95, '=') << std::endl;
    std::cout << "|" << std::setw(40) << "PRODUCT CATALOG" << std::setw(40) << "|" << std::endl;
    std::cout << std::string(95, '=') << std::endl;
    std::cout << "| " << std::left << std::setw(3) << "ID"
        << "| " << std::setw(18) << "Product"
        << "| " << std::setw(10) << "Price"
        << "| " << std::setw(8) << "Coupon"
        << "| " << std::setw(8) << "Student"
        << "| " << std::setw(7) << "Senior"
        << " |" << std::endl;
    std::cout << std::string(95, '-') << std::endl;
    for (int iii = 0; iii < 6; iii++)
    {
        std::cout << "| " << std::setw(3) << prodCode[iii]
            << "| " << std::setw(18) << prodName[iii]
            << "| RM" << std::setw(7) << std::fixed << std::setprecision(2) << basePrice[iii]
            << "| " << std::setw(7) << couponDisc[iii] << "%"
            << "| " << std::setw(7) << studentDisc[iii] << "%"
            << "| " << std::setw(6) << seniorDisc[iii] << "%"
            << " |" << std::endl;
    }
    std::cout << std::string(95, '=') << std::endl;

    //pricing rules
    std::cout << "\nPricing Rules:\n";
    std::cout << "1. A valid coupon code 'TECH2025' grants a discount as per the product's coupon discount rate.\n";
    std::cout << "2. Students receive a discount as per the product's student discount rate.\n";
    std::cout << "3. Seniors (age 60 and above) receive a discount as per the product's senior discount rate.\n";
    std::cout << "4. Discounts are applied sequentially on the base price.\n";
    std::cout << '\n';

    std::cout << std::string(95, '=') << std::endl;


}

//Allow multiple purchases in a single transaction
bool isDone() 
{
    // prompt user isDone , if done return true else return false
    int value;
    std::cout << "Enter 1 to continue shopping , enter 2 to stop shopping: \n";
    while (!(std::cin >> value) || (value != 1 && value != 2))
    {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        std::cout << "Invalid input. Please enter  1 or 2: \n"; //repromt input
    }
    
    // Clear buffer after getting valid input for getUserInput
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if(value == 1)
    {
    
        return false;
        //user is not done with shopping

    }
    return true;
    //user is done with shopping
}



//check if coupon code is valid
bool couponValid()
{
    std::string coupon; //get user input for coupon code
    std::cout << "Enter coupon code (if any): ";
    std::cin >> coupon;

    if (coupon == "TECH2025") //check if coupon code is valid
    {
       return true;//code is valid
    }  
     else {
   return false;//code is not valid
    }
    
}


//since we dont know how many customers are gonna buy stuff . use vectors to store purchase information
int purchaseID {0};//give each order a code , also tracks number of items stored in vector 
std::vector<std::string> purchaseName; //store purchased item name
std::vector<std::string> purchaseICPP;//store customer IC or PassportNum
std::vector<int> purchaseAge;//store customer age
std::vector<int> purchaseProdCode;//store purchased item product code
std::vector<bool> purchaseCouponType;//store customer coupon validation status
std::vector<bool> purchaseStdStat;//store if customer is a student
std::vector<float>purchaseFinalprice;//store item price with discounts applied



//temporaty variables to intialise the vectors
std::string tempString {};
int tempInt = 0;


float calcFinPrice(int x); //fucntion prototype for calcFinPrice;

//get customer information
void getPurchaseInfo()
{
    //get name
    std::cout << "Enter your Name: \n";
    std::getline(std::cin, tempString); 
    purchaseName.push_back(tempString);
    tempString = "";

    //get IC/Passport No
    std::cout << "Enter your IC/Passport Number: \n";
    std::getline(std::cin, tempString);
    purchaseICPP.push_back(tempString);
    tempString = "";
    

    //get Age with input validation
    std::cout <<"Enter your Age: \n";
    while(!(std::cin >> tempInt) || tempInt <= 0)
    {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Reenter you age: \n";
        
    }
    purchaseAge.push_back(tempInt);
    tempInt = 0;
    

    //get Product Code with input validation
    std::cout <<"Enter your Product Code: \n";
    while(!(std::cin >> tempInt)||(tempInt < 1 )|| (tempInt >6))
    {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Reenter your product code, it should be between 1 and 6\n";
        
    }
    purchaseProdCode.push_back(tempInt);
    tempInt = 0;
    
    //check if coupon code is valid
    bool cvalid = couponValid();
    if(cvalid == true)
    {
        std::cout << "Your Coupon is Valid\n" ;
        purchaseCouponType.push_back(true);
    }
    else if (cvalid == false)
    {
        std::cout <<"Your Coupon is Invalid\n";
        purchaseCouponType.push_back(false);
    }

    

    //check if customer is a student
    std::cout << "Enter 1 if you are a student, Enter 0 if you are not: ";
    while(!(std::cin >> tempInt)||(tempInt < 0 )||(tempInt > 1))
    {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Reenter your answer , it should be 1 or 0 \n";
    }
    if(tempInt == 1)
    {
        purchaseStdStat.push_back(true);
    }
    else if (tempInt == 0)
    {
        purchaseStdStat.push_back(false);
    }
    purchaseID ++;

    //add final price after discounts to vector
    purchaseFinalprice.push_back(calcFinPrice(purchaseID -1));

}

//Calc final price of item after discounts
//formula used is Base Price * (100 - discount)%
float calcFinPrice(int x)
{
        //create a float and give item the baseprice of the item
        //purchaseProdCode - 1 since it starts from 1->6 but the array is 0->5
        float price =basePrice[purchaseProdCode[x]-1] ;
        if(purchaseCouponType[x]== 1)
        {
            std::cout << "Promotion Code Applied. \n";
            price = price * ((100.0 - couponDisc[purchaseProdCode[x]-1])/100.0);
        }
        if(purchaseStdStat[x] == 1)
        {
           std::cout << "Student Discount Applied. \n";
            price = price * ((100.0 - studentDisc[purchaseProdCode[x]-1])/100.0);
        }
        if(purchaseAge[x] >= 60)
        {
           std::cout << "Senior Discount Applied. \n";
            price = price * ((100.0 - seniorDisc[purchaseProdCode[x]-1])/100.0);
        }
        //add the final price to the final price vector
        //return price after discounts
        return price;
       
}



//printall customer details
void printAll(int iii)
{
    
        std::cout <<"-------------------------------------\n";
        std::cout <<"Customer Details: \n"; 
        std::cout << "Name: "<<purchaseName[iii] <<"\n"; // name
        std::cout <<"IC/PP: " <<purchaseICPP[iii]<<'\n'; // IC or PassPort No.
        std::cout <<"Age: " <<purchaseAge[iii]<<'\n'; // Age
        std::cout <<"Product Name: " <<prodName[purchaseProdCode[iii]-1]<<'\n'; // Prodcut Name
        std::cout <<"Price before discounts: RM"<<std::fixed << std::setprecision(2)<<basePrice[purchaseProdCode[iii]-1]<<'\n';
        std::cout <<"Your total with discounts: RM" << std::setprecision(2) << purchaseFinalprice[iii]<<'\n'; // Discounts applied and Final price 
        std::cout << "-------------------------------------\n";
    
}

//print grand total 
void printgrandTotal()
{
    float x = 0;
    for(int iii = 0 ; iii < purchaseID  ; iii ++)
    {
        x = x + purchaseFinalprice[iii];
    }
    std::cout << "Grand Total: RM" << std::fixed << std::setprecision(2) << x << "\n";

}

int main()
{


    bool donecheck = false; //track if user is done shopping
   
    displayProducts(); //display products at start

    while (donecheck == false)
    {
        
        getPurchaseInfo();
    
        donecheck = isDone();
    }
    for(int iii = 0 ; iii < purchaseID ; iii ++)
    {
        printAll(iii);
    }    
    printgrandTotal();
    
    
}