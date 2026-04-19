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
                cout << "Country search: ";
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
                cout << "Name search: ";
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
                cout << "IATA code search: ";
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
                auto counts = repo.countAirportsByType();
                if (counts.empty()) {
                    cout << "No airports loaded.\n";
                } else {
                    cout << "Airport counts by type:\n";
                    for (const auto& p : counts) {
                        cout << p.first << " -> " << p.second << "\n";
                    }
                }
                break;
            }
            case 5: {
                {
                    cin.ignore(1000, '\n');
                    string id, type, name, continent, isoCountry, isoRegion, municipality, icaoCode, iataCode, gpsCode, localCode, temp;
                    int elevation = 0;
                    double x = 0.0, y = 0.0;

                    cout << "Enter airport id: ";
                    getline(cin, id);
                    cout << "Enter type: ";
                    getline(cin, type);
                    cout << "Enter name: ";
                    getline(cin, name);
                    cout << "Enter elevation (ft): ";
                    getline(cin, temp);
                    if (!temp.empty()) {
                        try { elevation = stoi(temp); } catch(...) { elevation = 0; }
                    }
                    cout << "Enter continent: "; getline(cin, continent);
                    cout << "Enter ISO country: "; getline(cin, isoCountry);
                    cout << "Enter ISO region: "; getline(cin, isoRegion);
                    cout << "Enter municipality: "; getline(cin, municipality);
                    cout << "Enter ICAO code: "; getline(cin, icaoCode);
                    cout << "Enter IATA code: "; getline(cin, iataCode);
                    cout << "Enter GPS code: "; getline(cin, gpsCode);
                    cout << "Enter local code: "; getline(cin, localCode);
                    cout << "Enter coordinate X (latitude): "; getline(cin, temp);
                    if (!temp.empty()) { try { x = stod(temp); } catch(...) { x = 0.0; } }
                    cout << "Enter coordinate Y (longitude): "; getline(cin, temp);
                    if (!temp.empty()) { try { y = stod(temp); } catch(...) { y = 0.0; } }

                    repo.addAirport(id, type, name, elevation, continent, isoCountry, isoRegion, municipality, icaoCode, iataCode, gpsCode, localCode, x, y);
                    cout << "Airport added.\n";
                }
                break;
            }
            case 6: {
				repo.saveToCsv();
				cout << "Changes saved to aiports.csv\n";
                break;
            }
            case 7: {
                {
                    int sub;
                    do {
                        cout << "\n--- Advanced options ---\n";
                        cout << "1. Calculate distance between airports\n";
                        cout << "2. Find nearest airport to a given location\n";
                        cout << "3. List all airports within a radius\n";
                        cout << "4. Highest and lowest elevation airports\n";
                        cout << "5. Airports with missing IATA codes\n";
                        cout << "6. Group airports by municipality\n";
                        cout << "7. Sorting\n";
                        cout << "8. Back\n";
                        cout << "Choice: ";
                        while (!(cin >> sub)) { cout << "Invalid input. Try again: "; cin.clear(); cin.ignore(10000,'\n'); }
                        cin.ignore(1000, '\n');
                        switch (sub) {
                        case 1: {
                            cout << "Enter ID of first airport: ";
                            string a1; getline(cin, a1);
                            cout << "Enter ID of second airport: ";
                            string a2; getline(cin, a2);
                            double d = repo.distanceBetweenAirports(a1, a2);
                            if (d < 0) {
                                cout << "One or both airports not found.\n";
                            } else {
                                cout << "Distance between '" << a1 << "' and '" << a2 << "' = " << d << " km\n";
                            }
                            break;
                        }
                        case 2: {
                            cout << "Enter latitude: ";
                            double lat; cin >> lat;
                            cout << "Enter longitude: ";
                            double lon; cin >> lon;
                            cin.ignore(1000, '\n');
                            break;
                        }
                        case 3: {
                            cout << "Enter latitude: ";
                            double lat;
                            cin >> lat;
                            cout << "Enter longitude: ";
                            double lon; cin >> lon;
                            cin.ignore(1000, '\n');
                            break;
                        }
                        case 4: {
                            break;
                        }
                        case 5: {
                            break;
                        }
                        case 6: {
                            break;
                        }
                        case 7: {
                            break;
                        }
                        case 8: {
                            break;
                        }
                        default: {
                            cout << "Invalid input. Try again: ";
                            continue;
                        }
                        }
                    } while (sub != 8);
                }
                break;
            }
            case 8: {
				cout << "Thank you for using Nottingham SkyRoute Explorer. Goodbye!\n";
                return;
            }
            default: {
                cout << "Invalid input. Try again: ";
                continue;
            }
        }
    } while (choice != 8);
}