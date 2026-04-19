#include "AiportApp.h"
#include <iostream>

using namespace std;

void AiportApp::run() {
	AiportRepository repo;
	repo.loadFromCsv();
	int choice;

    do {
        cout << "\n====== Nottingham SkyRoute Explorer ======\n";
        cout << "1. Search airports by country\n";
        cout << "2. Search airports by name\n";
        cout << "3. Search by IATA code\n";
        cout << "4. Count airports by type\n";
        cout << "5. Add a new airport\n";
        cout << "6. Save changes\n";
        cout << "7. Advanced options (radius search, nearest airport, high/low elevation, etc.)\n";
        cout << "8. Exit\n";
        cout << "Choice: ";
        /*cin >> choice;
        cin.ignore();*/

        while (!(cin >> choice)) { // Keep asking until the user enters a valid number
            cout << "Invalid input. Try again: ";
            cin.clear(); // Reset input errors
            cin.ignore(10000, '\n'); // Remove bad input
        }

        switch (choice) {
            case 1: {
                string text;
                cout << "Title search: ";
                cin.ignore(1000, '\n');
                getline(cin, text);
                auto results = repo.searchByIsoCountry(text);
                
                if (results.empty()) {
                    cout << "\n-----------------------------\n";
                    cout << "Nothing found for: " << text << ". Please check your input." << endl;
                }
                else {
                    for (auto& a : results) {
                        a.print();
                    }
                }
                break;
            }
            case 2: {
                string text;
                cout << "Title search: ";
                cin.ignore(1000, '\n');
                getline(cin, text);
                auto results = repo.searchByName(text);

                if (results.empty()) {
                    cout << "\n-----------------------------\n";
                    cout << "Nothing found for: " << text << ". Please check your input." << endl;
                }
                else {
                    for (auto& a : results) {
                        a.print();
                    }
                }
                break;
            }
            case 3: {
                string text;
                cout << "Title search: ";
                cin.ignore(1000, '\n');
                getline(cin, text);
                auto results = repo.searchByIataCode(text);

                if (results.empty()) {
                    cout << "\n-----------------------------\n";
                    cout << "Nothing found for: " << text << ". Please check your input." << endl;
                }
                else {
                    for (auto& a : results) {
                        a.print();
                    }
                }
                break;
            }
            case 4: {
                // TODO: implement count airports by type
                break;
            }
            case 5: {
                // TODO: implement add a new airport
                break;
            }
            case 6: {
                // TODO: implement save changes
                break;
            }
            case 7: {
                // TODO: implement advanced options
                break;
            }
            case 8: {
                // Exit
                break;
            }
            default: {
                continue;
            }
        }
    } while (choice != 8);
}