#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>

//general could add more : input confirmation <- worry later

// create array for each value of each attribute in the table , each value should be tied to prodcode 0-5
int const prodCode[6]{1, 2, 3, 4, 5, 6};
std::string const prodName[6]{"Smartwatch Pro", "Wireless Earbuds", "Smart Home Kit", "Gaming Keyboard", "4K Action Camera", "Portable Projector"};
float const basePrice[6]{350, 200, 500, 250, 800, 600};
float const couponDisc[6]{10, 12, 15, 8, 10, 12};
float const studentDisc[6]{15, 10, 12, 10, 8, 10};
float const seniorDisc[6]{5,5,8,5,6,7,};


// Display the product list along with pricing + discount rules
void displayProdcuts()
{
    for (int iii = 0; iii < 6; iii++)
    {
        std::cout << "|Product Code:" << prodCode[iii] << "| |Product Name:" << prodName[iii] << "| |Product Price:" << basePrice[iii] << "|" << "| |Early Bird Discount :" << couponDisc[iii]
                  << "%| |Student Discount :" << studentDisc[iii] << "%| |Senior Discount :" << seniorDisc[iii] << "% |\n";
    }

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
        std::cout << "Invalid input. Please enter  1 or 2: \n";
    }
    if(value == 1)
    {
    
        return false;

    }
    return true;
}




bool couponValid()
{
    std::string coupon;
    std::cout << "Enter coupon code (if any): ";
    std::cin >> coupon;

    if (coupon == "TECH2025") 
    {
       return true;
    }  
     else {
   return false;
    }
    
}

/*3) For each customer, collect the following details:
• Name
• IC/Passport Number (must be unique) validation = crosscheck if IC exist in arr then check if arr[exist] name = same , if same pass , if not re-input? 
• Age
• Product Code
• Purchase Type (Early Bird / Normal) -  0 = normla 1 = early bird
• Student status (Yes/No).*/

std::vector<std::string> purchaseName;
std::vector<std::string> purchaseICPP;
std::vector<int> purchaseAge;
std::vector<int> purchaseProdCode;
std::vector<bool> purchaseCouponType;
std::vector<bool> purchaseStdStat;
std::vector<float>purchaseFinalprice;
int purchaseLoop {0};


//keep track of producst?
std::string tempString;
int tempInt;
bool stringValidate {false};





void getPurchaseInfo()
{
    
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
    tempInt = {};
    
    //check for 1 to 6 only
    
    std::cout <<"Enter your Product Code: \n";
    while(!(std::cin >> tempInt)||(tempInt < 1 )|| (tempInt >6))
    {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Reenter you product code , it should be 1 or 6 \n";
        
    }
    purchaseProdCode.push_back(tempInt);
    tempInt = {};
    
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
    else
    {
        std::cout <<"someting wong";
    }
    

    //input validation needed
    std::cout << "Enter 1 if your are a student , Enter 0 if you are not: " ;
    std::cin >> tempInt;
    if(tempInt == 1)
    {
        purchaseStdStat.push_back(true);
    }
    else if (tempInt == 0)
    {
        purchaseStdStat.push_back(false);
    }
    else
    {
        std::cout << "Something wong";
    }
    purchaseLoop ++;

}

//Calc final price of item
//  Early Bird Discount earlydisc - purchaseEb = true
//    StudentDiscount   stddisc - purchaseStd = true
//    SeniorDiscount    seniordisc - purchaseAge >= 60

float calcFinPrice(int x)
{
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
        purchaseFinalprice.push_back(price);
        return price;
       
}



//printall
/*std::vector<std::string> purchaseName;
std::vector<std::string> purchaseICPP;
std::vector<int> purchaseAge;
std::vector<int> purchaseProdCode;
std::vector<bool> purchaseCouponType;
std::vector<bool> purchaseStdStat;
std::vector<float>finalprice;*/
void printAll(int purchaseLoop)
{
    for(int iii = 0 ; iii < purchaseLoop ; iii ++)
    {
        std::cout <<"Customer Details: \n";
        std::cout << "Name: "<<purchaseName[iii] <<"\n";
        std::cout <<"IC/PP: " <<purchaseICPP[iii]<<'\n';
        std::cout <<"Age: " <<purchaseAge[iii]<<'\n';
        std::cout <<"Product Name: " <<prodName[purchaseProdCode[iii]-1]<<'\n';
        std::cout <<"Your total with discounts: \n" <<calcFinPrice(iii)<<'\n';
    }
}

void printgrandTotal()
{
    int x = 0;
    for(int iii = 0 ; iii < purchaseLoop ; iii ++)
    {
        x = x + purchaseFinalprice[iii];
    }
    std::cout << x;

}
int main()
{


    bool donecheck;
    displayProdcuts();
    while (donecheck == false)
    {
        
        getPurchaseInfo();
    
        donecheck = isDone();
    }

    printAll(purchaseLoop);
    printgrandTotal();
    
}

/*
what would main look like

int main()
{
    bool donecheck;
    while (donecheck == false)
    {
        
    
    
        donecheck = isdone();
    }

    print all ;

}


*/