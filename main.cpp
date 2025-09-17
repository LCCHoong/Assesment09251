#include <iostream>
#include <string>
#include <limits>
#include <vector>
//general could add more : input confirmation <- worry later

// create array for each value of each attribute in the table , each value should be tied to prodcode 0-5
int const prodCode[6]{1, 2, 3, 4, 5, 6};
std::string const prodName[6]{"Smartwatch Pro", "Wireless Earbuds", "Smart Home Kit", "Gaming Keyboard", "4K Action Camera", "Portable Projector"};
int const basePrice[6]{350, 200, 500, 250, 800, 600};
int const earlyDisc[6]{10, 12, 15, 8, 10, 12};
int const studentDisc[6]{15, 10, 12, 10, 8, 10};
int const seniorDisc[6]{5,5,8,5,6,7,};


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
        std::cout << "Invalid input. Please enter a positive integer: \n";
    }
    if(value == 1)
    {
        return false;
    }
    return true;
}

/*3) For each customer, collect the following details:
• Name
• IC/Passport Number (must be unique) validation = crosscheck if IC exist in arr then check if arr[exist] name = same , if same pass , if not re-input? 
• Age
• Product Code
• Purchase Type (Early Bird / Normal) -  0 = normla 1 = early bird
• Student status (Yes/No).*/

//maybe order multiple order array , either that 

//more global vars , dyamic size arrays, could just vector = purchase id 
std::vector<int> purchaseID ; // keep track of all purchases and assign each an ID
/*
could do something like this:
    for(int iii = 0 ; iii < 3 ; iii++)
    {
        
        std::cin >> x;
        nums.push_back(x);
    }
    for(int iii = 2 ; iii >= 0 ; iii--)
    {
        
        std::cout << nums[iii] <<'\n';
        nums.pop_back();
    }
    then when print just ssize vector then loop through arrs? 
    for (data type varname : vector to iterate)
    {
        printf("%d", varname);
    }
*/
std::vector<std::string> purchaseName;
std::vector<std::string> purchaseICPP;
std::vector<int> purchaseAge;
std::vector<int> purchaseProdCode;
std::vector<bool> purchaseEBType;
std::vector<bool> purchaseStdStat;
//.pushback

//keep track of producst?
int purchaseLoop {0};
std::string tempString;
int tempInt;

void getPurchaseInfo()
{
   purchaseID.push_back(purchaseLoop); // purchaseID ++
    purchaseLoop ++;
    
    std::cout <<"Enter your Name: \n" ;
    std::cin >> tempString; //optimisable , maybe ltr
    purchaseName.push_back(tempString);

    std::cout <<"Enter your IC/Passport Number: \n" ;
    std::cin >> tempString; //optimisable , maybe ltr
    purchaseICPP.push_back(tempString);
//intintint bool
    std::cout <<"Enter your Age: \n";
    std::cin >>tempInt;
    purchaseAge.push_back(tempInt);

    std::cout <<"Enter your Product Code: \n";
    std::cin >>tempInt;
    purchaseProdCode.push_back(tempInt);

    std::cout <<"Enter your Purchase Type ,Enter 1 for ealy bird ,Enter 0 for normal: \n"; //0 = normal, 1 = early bird ; input validation
    std::cin >>tempInt;
    if(tempInt == 1)
    {
        purchaseEBType.push_back(true);
    }
    else if (tempInt == 0)
    {
        purchaseEBType.push_back(false);
    }
    else
    {
        std::cout <<"someting wong";
    }


    std::cout <<"Enter your student status ,Enter 1 if you're a student ,Enter 0 if you're not: \n" ;//0 = not std, 1 = std ; input validation
    std::cin >>tempInt;
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
        std::cout <<"someting wong";
    }


    

    
}
//how would you print multiple times , for each ID as outer then nest all the other inside?

/*
std::vector<int> purchaseID 
std::vector<std::string> purchaseName;
std::vector<std::string> purchaseICPP;
std::vector<int> purchaseAge;
std::vector<int> purchaseProdCode;
std::vector<bool> purchaseEBType;
std::vector<bool> purchaseStdStat;*/


int main()
{
    
    getPurchaseInfo();
    getPurchaseInfo();
    getPurchaseInfo();

    for(int loop : purchaseID)
    {
        std::cout<<"Your name is: "<<purchaseName[loop] <<"\nYour ICPP is: "<<purchaseICPP[loop] <<"\nYour Age is: "
        << purchaseAge[loop] << "\nYour Product Code: "<<purchaseProdCode[loop];
        std::cout <<"debug";
        if(purchaseEBType[loop] == true)
        {
            std::cout <<"\nYour Early Bird status is Valid";
        }
        else if(purchaseEBType[loop] == false)
        {
            std::cout <<"\nYour Early Bird status is Invalid";
        }
        else
        {
            std::cout <<"somehow an error in EarlyDiscPrint";
        }
        if(purchaseStdStat[loop] == true)
        {
            std::cout <<"\nYour student status is Valid";
        }
        else if(purchaseStdStat[loop] == false)
        {
            std::cout <<"\nYour student status is Invalid";
        }
        else
        {
            std::cout <<"somehow an error in studenstatPrint ";
        }
        std::cout <<'\n';
        
        
    }
}
