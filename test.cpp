#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>

int const prodCode[6]{1, 2, 3, 4, 5, 6};
std::string const prodName[6]{"Smartwatch Pro", "Wireless Earbuds", "Smart Home Kit", "Gaming Keyboard", "4K Action Camera", "Portable Projector"};
int const basePrice[6]{350, 200, 500, 250, 800, 600};
int const earlyDisc[6]{10, 12, 15, 8, 10, 12};
int const studentDisc[6]{15, 10, 12, 10, 8, 10};
int const seniorDisc[6]{5,5,8,5,6,7,};

std::vector<int> purchaseID ; 
std::vector<std::string> purchaseName;
std::vector<std::string> purchaseICPP;
std::vector<int> purchaseAge;
std::vector<int> purchaseProdCode;
std::vector<bool> purchaseEBType;
std::vector<bool> purchaseStdStat;
int purchaseLoop {0};
std::string tempString;
int tempInt;




int main()
{
    purchaseICPP.push_back("stringaaaaaaaa");
    std::string str {"string"};
    std::cout << purchaseICPP[0];
    if(std::find(purchaseICPP.begin(),purchaseICPP.end(),str) != purchaseICPP.end())
    {
        std::cout << "is in vector";
    }
    if(std::find(purchaseICPP.begin(),purchaseICPP.end(),str) == purchaseICPP.end())
    {
        std::cout << "is not in vector";
    }
    
}

