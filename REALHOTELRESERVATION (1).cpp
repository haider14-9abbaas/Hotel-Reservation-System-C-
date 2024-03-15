#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function to display a welcome message
void displayWelcomeMessage() {
    cout << "*******************************" << endl;
    cout << "Welcome to The BeachSide GateWay Resort" << endl;
    cout << "*******************************" << endl;
}

// Function to display room type options
void displayRoomOptions() {
    cout << "Room Types:" << endl;
    cout << "1. AC Room" << endl;
    cout << "2. Non-AC Room" << endl;
}

// Function to calculate and display tax
double calculateAndDisplayTax(double subtotal) {
    const double TAX_RATE = 0.1; // 10% tax rate
    double tax = subtotal * TAX_RATE;
    
    cout << fixed << setprecision(2); // Set precision for displaying currency
    cout << "Tax (10%): $" << tax << endl;

    return tax;
}

int main() {
    char choice;
    double AC_RATE = 100.0;
    double NON_AC_RATE = 150.0;
    double grandTotal = 0.0;

    do {
        displayWelcomeMessage();

        // Get reservation details from the user
        string customerName;
        int roomType, numNights;

        cout << "\nEnter your name: ";
        getline(cin, customerName);

        displayRoomOptions();
        
        cout << "Choose Room Type (1 for AC, 2 for Non-AC): ";
        cin >> roomType;

        // Input validation for room type
        while (roomType != 1 && roomType != 2) {
            cout << "Invalid room type. Enter 1 for AC or 2 for Non-AC: ";
            cin >> roomType;
        }

        cout << "Enter number of nights: ";
        cin >> numNights;

        // Input validation for non-negative nights
        while (numNights < 0) {
            cout << "Invalid number of nights. Enter a non-negative value: ";
            cin >> numNights;
        }

        // Calculate total amount
        double roomRate = (roomType == 1) ? AC_RATE : NON_AC_RATE;
        double subtotal = numNights * roomRate;

        // Display individual reservation receipt
        cout << "\nReservation Receipt:" << endl;
        cout << "Name: " << customerName << endl;
        cout << "Room Type: " << ((roomType == 1) ? "AC" : "Non-AC") << endl;
        cout << "Nights: " << numNights << endl;
        cout << "Room Rate: $" << roomRate << endl;
        cout << "Subtotal: $" << subtotal << endl;

        // Calculate and display tax
        double tax = calculateAndDisplayTax(subtotal);

        // Calculate and display total amount
        double totalAmount = subtotal + tax;
        cout << "Total: $" << totalAmount << endl;

        // Add the total amount to the grand total
        grandTotal += totalAmount;

        // Ask if the user wants to make another reservation
        cout << "\nDo you want to make another reservation? (Enter 'y' for yes, 'n' for no): ";
        cin >> choice;

        // Input validation for 'y' or 'n'
        while (tolower(choice) != 'y' && tolower(choice) != 'n') {
            cout << "Invalid choice. Enter 'y' for yes or 'n' for no: ";
            cin >> choice;
        }

        // Consume newline character from previous input
        cin.ignore();

    } while (tolower(choice) == 'y');

    // Display grand total
    cout << "\nGrand Total: $" << grandTotal << endl;
    cout << "Thank you for visiting BeachSide GateWay Resort" << endl;

    return 0;
}

