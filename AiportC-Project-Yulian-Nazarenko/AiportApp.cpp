#include "AiportApp.h"
#include <iostream>

using namespace std;

void AiportApp::run() {
	//AiportRepository repo;
	//repo.loadFromCsv();
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
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case choice == 1:

                break;
            
            case choice == 2:
                
                break;

            case choice == 3:
                
                break;

            case choice == 4:
                
                break;

            case choice == 5:
                
                break;

            case choice == 6:
                
                break;

            case choice == 7:
                
                break;

            case choice == 8:
                
                break;
            
            
        }
    } while (choice != 8);
}