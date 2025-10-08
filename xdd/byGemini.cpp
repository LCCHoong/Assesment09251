#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <limits> // Required for numeric_limits

using namespace std;

// --- Data Structures (Using Arrays) ---
// Note: Arrays are used here to store the fixed product data.
// A more robust system for transaction tracking would use dynamic structures (e.g., vectors, classes)
// but arrays are used to satisfy the prompt's requirement and the fixed product list.

const int NUM_PRODUCTS = 6;
// Array for Product Codes (1 to 6) - indices 0 to 5 correspond to codes 1 to 6
const int PRODUCT_CODES[NUM_PRODUCTS] = {1, 2, 3, 4, 5, 6};
// Array for Product Names
const string PRODUCT_NAMES[NUM_PRODUCTS] = {
    "Smartwatch Pro",
    "Wireless Earbuds",
    "Smart Home Kit",
    "Gaming Keyboard",
    "4K Action Camera",
    "Portable Projector"
};
// Array for Base Prices (RM)
const double BASE_PRICES[NUM_PRODUCTS] = {350.0, 200.0, 500.0, 250.0, 800.0, 600.0};

// Array for Early Bird Coupon Discount Rates (as decimal: 10% = 0.10)
const double EB_DISCOUNTS[NUM_PRODUCTS] = {0.10, 0.12, 0.15, 0.08, 0.10, 0.12};

// Array for Student Discount Rates (as decimal)
const double STUDENT_DISCOUNTS[NUM_PRODUCTS] = {0.15, 0.10, 0.12, 0.10, 0.08, 0.10};

// Array for Senior Discount Rates (as decimal)
const double SENIOR_DISCOUNTS[NUM_PRODUCTS] = {0.05, 0.05, 0.08, 0.05, 0.06, 0.07};

// Global array to store unique IC/Passport numbers for validation
// Max size set to a reasonable limit for a small expo simulation
const int MAX_CUSTOMERS = 100;
string recorded_ic_passports[MAX_CUSTOMERS];
int customer_count = 0;


// --- Function Prototypes ---
void displayProductList();
int getProductIndex(int code);
double calculateFinalPrice(int index, bool isEarlyBird, int age, bool isStudent);
bool validateAge(int age);
bool validateICPassport(const string& ic_passport);
string getCustomerDetails(string& name, string& ic_passport, int& age);
string getPurchaseDetails(int& productCode, bool& isEarlyBird, bool& isStudent);


// --- Main Program ---
int main() {
    // Set for currency/price display
    cout << fixed << setprecision(2);

    char anotherCustomer = 'y';
    double grandTotal = 0.0;

    cout << "====================================================\n";
    cout << "      Sunway Tech Hub Gadget Expo 2025 - Sales\n";
    cout << "====================================================\n\n";

    displayProductList(); // Requirement: Display product list

    // Main loop for multiple customers/transactions
    while (tolower(anotherCustomer) == 'y') {
        // --- Customer Details and Validation ---
        string customerName, icPassport;
        int age;
        
        // Get customer details and validate IC/Passport and Age
        getCustomerDetails(customerName, icPassport, age);

        // Record the valid IC/Passport for future checks
        if (customer_count < MAX_CUSTOMERS) {
            recorded_ic_passports[customer_count++] = icPassport;
        }

        // --- Purchase Details and Calculation ---
        char anotherPurchase = 'y';
        double transactionTotal = 0.0;
        int productCode, productIndex;
        bool isEarlyBird, isStudent;
        int purchaseCount = 0; // Counter for multiple purchases in a single transaction

        cout << "\n--- Starting Purchase for " << customerName << " ---\n";

        // Loop for multiple purchases in a single transaction
        while (tolower(anotherPurchase) == 'y') {
            // Get purchase details and validate Product Code
            getPurchaseDetails(productCode, isEarlyBird, isStudent);
            
            // Find product index in the arrays
            productIndex = getProductIndex(productCode);
            // This check should ideally be in getPurchaseDetails, but repeated here for clarity
            if (productIndex == -1) {
                // This branch should only be hit if validation fails in getPurchaseDetails
                cout << "Error: Invalid product code used for calculation.\n";
                continue; 
            }

            // Calculate the final price
            double finalPrice = calculateFinalPrice(productIndex, isEarlyBird, age, isStudent);
            transactionTotal += finalPrice;
            purchaseCount++;
            
            cout << "  -> Item: " << PRODUCT_NAMES[productIndex] << " | Final Price: RM" << finalPrice << "\n";
            
            // Ask for another purchase
            cout << "\nAnother item for this customer? (Y/N): ";
            cin >> anotherPurchase;
            // Clear input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        // --- Sales Receipt Display ---
        cout << "\n========================================\n";
        cout << "            SALES RECEIPT\n";
        cout << "========================================\n";
        cout << "Customer Name: " << customerName << "\n";
        cout << "IC/Passport: " << icPassport << "\n";
        cout << "Age: " << age << "\n";
        cout << "Total Items Purchased: " << purchaseCount << "\n";
        cout << "----------------------------------------\n";
        cout << "Transaction Total: RM" << transactionTotal << "\n";
        cout << "========================================\n\n";

        grandTotal += transactionTotal; // Update grand total

        // Ask for another customer
        cout << "Process another customer? (Y/N): ";
        cin >> anotherCustomer;
        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Display Grand Total
    cout << "\n****************************************\n";
    cout << "  GRAND TOTAL SALES: RM" << grandTotal << "\n";
    cout << "****************************************\n";

    return 0;
}


// --- Function Implementations ---

/**
 * @brief Displays the product list, base prices, and discount rules.
 */
void displayProductList() {
    cout << "--- Product List and Pricing Rules ---\n";
    cout << "Code | Product Name         | Base Price | Early Bird | Student Disc | Senior Disc\n";
    cout << "----------------------------------------------------------------------------------\n";
    for (int i = 0; i < NUM_PRODUCTS; ++i) {
        cout << left << setw(4) << PRODUCT_CODES[i] << " | "
             << left << setw(20) << PRODUCT_NAMES[i] << " | "
             << right << "RM" << setw(6) << BASE_PRICES[i] << " | "
             << right << setw(10) << (EB_DISCOUNTS[i] * 100) << "% | "
             << right << setw(12) << (STUDENT_DISCOUNTS[i] * 100) << "% | "
             << right << setw(11) << (SENIOR_DISCOUNTS[i] * 100) << "%\n";
    }
    cout << "----------------------------------------------------------------------------------\n";
    cout << "Early Bird valid on or before 15 November 2025. Senior Discount for age 60+.\n\n";
}

/**
 * @brief Retrieves the array index for a given product code.
 * @param code The Product Code (1-6).
 * @return The array index (0-5) or -1 if the code is invalid.
 */
int getProductIndex(int code) {
    // Internal comment: Loop through the PRODUCT_CODES array to find the index.
    for (int i = 0; i < NUM_PRODUCTS; ++i) {
        if (PRODUCT_CODES[i] == code) {
            return i;
        }
    }
    return -1; // Product code not found
}

/**
 * @brief Validates if the age is greater than 0.
 * @param age The age to validate.
 * @return true if valid, false otherwise.
 */
bool validateAge(int age) {
    // Internal comment: Check if age is positive.
    return age > 0;
}

/**
 * @brief Validates if the IC/Passport number is unique against previously recorded ones.
 * @param ic_passport The IC/Passport number to validate.
 * @return true if unique, false otherwise.
 */
bool validateICPassport(const string& ic_passport) {
    // Internal comment: Iterate through the recorded_ic_passports array up to customer_count.
    for (int i = 0; i < customer_count; ++i) {
        if (recorded_ic_passports[i] == ic_passport) {
            return false; // Duplicate found
        }
    }
    return true; // Unique
}


/**
 * @brief Collects and validates customer details (Name, IC/Passport, Age).
 * @param name Output parameter for customer name.
 * @param ic_passport Output parameter for IC/Passport number.
 * @param age Output parameter for age.
 */
string getCustomerDetails(string& name, string& ic_passport, int& age) {
    cout << "\n--- Customer Details ---\n";
    
    // Get Name
    cout << "Enter Customer Name: ";
    getline(cin, name);
    
    // Get and validate IC/Passport
    do {
        cout << "Enter IC/Passport Number (must be unique): ";
        getline(cin, ic_passport);
        if (validateICPassport(ic_passport) == false) {
            cout << "Invalid Input: This IC/Passport has already been registered. Please enter a unique one.\n";
        }
    } while (validateICPassport(ic_passport) == false);

    // Get and validate Age
    do {
        cout << "Enter Age: ";
        // Input validation for integer age
        if (!(cin >> age)) {
            cout << "Invalid Input: Age must be a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            age = -1; // Force re-loop
            continue;
        }
        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        if (validateAge(age) == false) {
            cout << "Invalid Input: Age must be greater than 0.\n";
        }
    } while (validateAge(age) == false);
    
    return name;
}


/**
 * @brief Collects and validates purchase details (Product Code, Early Bird, Student Status).
 * @param productCode Output parameter for product code.
 * @param isEarlyBird Output parameter for early bird status.
 * @param isStudent Output parameter for student status.
 */
string getPurchaseDetails(int& productCode, bool& isEarlyBird, bool& isStudent) {
    // --- Product Code and Validation ---
    int index = -1;
    do {
        cout << "\nEnter Product Code: ";
        // Input validation for integer product code
        if (!(cin >> productCode)) {
            cout << "Invalid Input: Product code must be a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            productCode = -1; // Force re-loop
            continue;
        }
        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        
        index = getProductIndex(productCode);
        if (index == -1) {
            cout << "Invalid Input: Product code does not exist. Please refer to the list.\n";
        }
    } while (index == -1);

    // --- Purchase Type (Early Bird) ---
    char ebChoice;
    cout << "Purchase Type (E: Early Bird / N: Normal): ";
    cin >> ebChoice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    isEarlyBird = (tolower(ebChoice) == 'e');
    
    // NOTE: The Early Bird validity against the cut-off date (Nov 15, 2025) is handled in the
    // calculateFinalPrice function, as it is part of the final price logic.

    // --- Student Status ---
    char studentChoice;
    cout << "Are you a Student? (Y/N): ";
    cin >> studentChoice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    isStudent = (tolower(studentChoice) == 'y');
    
    return PRODUCT_NAMES[index];
}


/**
 * @brief Calculates the final price after applying applicable discounts.
 * @param index The array index of the product.
 * @param isEarlyBird True if customer selected Early Bird purchase type.
 * @param age Customer's age.
 * @param isStudent True if customer is a student.
 * @return The final price.
 */
double calculateFinalPrice(int index, bool isEarlyBird, int age, bool isStudent) {
    // Internal comment: Start calculation from base price.
    double finalPrice = BASE_PRICES[index];
    double discountRate = 0.0;
    
    // --- Early Bird Discount Check ---
    if (isEarlyBird) {
        // NOTE: For simplicity in a console C++ program without complex date objects, 
        // a simple date entry and check is performed here.
        string purchaseDateStr;
        cout << "  (EB Check) Enter Purchase Date (DDMMYYYY) for validation: ";
        cin >> purchaseDateStr;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Simple check: check if date is on or before 15 November 2025 (15112025)
        // This is a minimal implementation of date validation as per requirement
        // Actual date comparison logic would be more complex.
        bool isEBValid = false;
        if (purchaseDateStr.length() == 8) {
            // Minimal logic: Only checks if the purchase date is '15112025' or earlier.
            // A more robust solution would require date library functions.
            if (purchaseDateStr.compare("15112025") <= 0) {
                 isEBValid = true;
            }
        }
        
        if (isEBValid) {
            discountRate += EB_DISCOUNTS[index];
            cout << "  -> Early Bird Discount Applied: " << (EB_DISCOUNTS[index] * 100) << "%\n";
        } else {
            cout << "  -> Early Bird Not Valid: Purchase date is after 15 November 2025.\n";
        }
    }
    
    // --- Student or Senior Discount Check ---
    if (age >= 60) {
        // Senior Discount (Age 60+)
        discountRate += SENIOR_DISCOUNTS[index];
        cout << "  -> Senior Discount Applied (Age 60+): " << (SENIOR_DISCOUNTS[index] * 100) << "%\n";
    } else if (isStudent) {
        // Student Discount
        discountRate += STUDENT_DISCOUNTS[index];
        cout << "  -> Student Discount Applied: " << (STUDENT_DISCOUNTS[index] * 100) << "%\n";
    }
    // NOTE: The requirements imply the discounts are cumulative, as they are not explicitly mutually exclusive
    // and the prompt asks to apply "student or senior discount if eligible."
    // Here, Senior discount takes precedence if both age >= 60 AND isStudent. If not 60+, only Student status is checked.
    // The implementation sums the EB discount and the Student/Senior discount.
    
    // Apply total discount
    finalPrice = finalPrice * (1.0 - discountRate);

    // Ensure price is not negative (though highly unlikely with proper rates)
    if (finalPrice < 0) {
        finalPrice = 0.0;
    }
    
    return finalPrice;
}