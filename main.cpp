#include <iostream>
#include <string>
#include <limits>
#include <vector>

//general could add more : input confirmation <- worry later

// create array for each value of each attribute in the table , each value should be tied to prodcode 1-6 (0-5)
int const prodCode[6]{1, 2, 3, 4, 5, 6};//product code 1-6 (0-5)
std::string const prodName[6]{"Smartwatch Pro", "Wireless Earbuds", "Smart Home Kit", "Gaming Keyboard", "4K Action Camera", "Portable Projector"};
//product names
float const basePrice[6]{350, 200, 500, 250, 800, 600};//base product price
float const couponDisc[6]{10, 12, 15, 8, 10, 12};//discount spplied with valid coupon code
float const studentDisc[6]{15, 10, 12, 10, 8, 10};//discount applied if customer is student
float const seniorDisc[6]{5,5,8,5,6,7};//discount applied if customer >= 60



// Display the product list along with pricing + discount rules
void displayProducts()
{
    for (int iii = 0; iii < 6; iii++)
    {
        std::cout << "|Product Code:" << prodCode[iii] << "| |Product Name:" << prodName[iii] << "| |Product Price:" << basePrice[iii] << "|" << "| |Early Bird Discount :" << couponDisc[iii]
                  << "%| |Student Discount :" << studentDisc[iii] << "%| |Senior Discount :" << seniorDisc[iii] << "% |\n";
    }
    std::cout << "Senior Discount will be applied for customers over 60. \n";
    // if time pretty tables for now just one liner
    // very pretty-able
}
//Allow multiple purchases in a single transaction
bool isDone() 
{
    // promt user isDone , if done return true else return false
    int value;
    std::cout << "Enter 1 to continue shopping , enter 2 to stop shopping: \n";
    while (!(std::cin >> value) || (value != 1 && value != 2))
    {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        std::cout << "Invalid input. Please enter  1 or 2: \n"; //repromt input
    }
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


float calcFinPrice(int x);

//get customer information
//[can maybe give second validation attemp etc etc]
void getPurchaseInfo()
{
    
    //get customer name
    std::cout <<"Enter your Name: \n" ;
    std::cin >> tempString; //optimisable , maybe ltr
    purchaseName.push_back(tempString);
    tempString = "";

    std::cout <<"Enter your IC/Passport Number: \n" ;
    std::cin >> tempString ;
    purchaseICPP.push_back(tempString);
    tempString = "";

    //check input
    
    
    
    std::cout <<"Enter your Age: \n";
    while(!(std::cin >> tempInt) || tempInt <= 0)
    {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Reenter you age: \n";
        
    }
    purchaseAge.push_back(tempInt);
    tempInt = 0;
    
    //check for 1 to 6 only
    
    std::cout <<"Enter your Product Code: \n";
    while(!(std::cin >> tempInt)||(tempInt < 1 )|| (tempInt >6))
    {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Reenter your product code, it should be between 1 and 6\n";
        
    }
    purchaseProdCode.push_back(tempInt);
    tempInt = 0;
    
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

    

    //input validation needed
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
    
        std::cout <<"Customer Details: \n"; 
        std::cout << "Name: "<<purchaseName[iii] <<"\n"; // name
        std::cout <<"IC/PP: " <<purchaseICPP[iii]<<'\n'; // IC or PassPort No.
        std::cout <<"Age: " <<purchaseAge[iii]<<'\n'; // Age
        std::cout <<"Product Name: " <<prodName[purchaseProdCode[iii]-1]<<'\n'; // Prodcut Name
        std::cout <<"Price before discounts: "<<basePrice[purchaseProdCode[iii]-1]<<'\n';
        std::cout <<"Your total with discounts: RM" <<purchaseFinalprice[iii]<<'\n'; // Discounts applied and Final price 
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
    std::cout << "Grand Total: RM" << x << "\n";

}
int main()
{


    bool donecheck = false;
    // could add welcome to something
    //or a would you like to buy stuff etc etc
    displayProducts();
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
