#include "AiportRepository.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

Aiport::Aiport(){}

void Aiport::set(string id, string t, string n, int el, string c, string isoC, string isoR, string m, string icao, string iata, string gps, string local, double X, double Y)
{
    aiportId = id;
    type = t;
    name = n;
    elevationFt = el;
    continent = c;
    isoCountry = isoC;
    isoRegion = isoR;
    municipality = m;
    icaoCode = icao;
    iataCode = iata;
    gpsCode = gps;
    localCode = local;
    coordinatesX = X;
	coordinatesY = Y;
}

string Aiport::getId() const { return aiportId; }
string Aiport::getType() const { return type; }
string Aiport::getName() const { return name; }
int Aiport::getElevationFt() const { return elevationFt; }
string Aiport::getContinent() const { return continent; }
string Aiport::getIsoCountry() const { return isoCountry; }
string Aiport::getIsoRegion() const { return isoRegion; }
string Aiport::getMunicipality() const { return municipality; }
string Aiport::getIcaoCode() const { return icaoCode; }
string Aiport::getIataCode() const { return iataCode; }
string Aiport::getGpsCode() const { return gpsCode; }
string Aiport::getLocalCode() const { return localCode; }
double Aiport::getCoordinatesX() const { return coordinatesX; }
double Aiport::getCoordinatesY() const { return coordinatesY; }

int counter = 0; // debug: count CSV parse errors

void Aiport::print() const {
    cout << "-----------------------------\n";
    cout << "Airport ID: " << aiportId << "\n";
    cout << "Type: " << type << "\n";
    cout << "Name: " << name << "\n";
    cout << "Elevation (ft): " << elevationFt << "\n";
    cout << "Continent: " << continent << "\n";
    cout << "Country (ISO): " << isoCountry << "\n";
    cout << "Region: " << isoRegion << "\n";
    cout << "Municipality: " << municipality << "\n";
    cout << "ICAO: " << icaoCode << "  IATA: " << iataCode << "  GPS: " << gpsCode << "  Local: " << localCode << "\n";
    cout << "Coordinates: " << coordinatesX << " , " << coordinatesY << "\n";
}

void AiportRepository::loadFromCsv() {
    ifstream file("airports.csv");
    string line;

    if (!file.is_open()) {
        cout << "Error: airports.csv not found.\n";
        return;
    }

    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string temp;

        Aiport a;
        int elevation = 0;
        double coordinatesX, coordinatesY; 
        string id, type, name, continent, isoCountry, isoRegion, municipality, icaoCode, iataCode, gpsCode, localCode;

        try {
            getline(ss, id, ',');
            getline(ss, type, ',');
            getline(ss, name, ',');
            getline(ss, temp, ','); 
            if (!temp.empty()) {
                elevation = stoi(temp);
            }
            getline(ss, continent, ',');
            getline(ss, isoCountry, ',');
            getline(ss, isoRegion, ',');
            getline(ss, municipality, ',');
            getline(ss, icaoCode, ',');
            getline(ss, iataCode, ',');
            getline(ss, gpsCode, ',');
            getline(ss, localCode, ',');
            getline(ss, temp, ','); coordinatesX = stod(temp);
            getline(ss, temp, ',');
            if (!temp.empty() && temp.back() == '\r') {
                temp.pop_back();
            }
            coordinatesY = stod(temp);

            a.set(id, type, name, elevation, continent, isoCountry, isoRegion, municipality, icaoCode, iataCode, gpsCode, localCode, coordinatesX, coordinatesY);
            aiports.push_back(a);
        }
   //     catch (...) {
			//cout << "Error parsing line: " << line << "\n";
   //     }
        catch (const exception& e) {
            counter++;
			cout << "Error " << e.what() << " parsing line: " << line << "\n";
        } // remove
	}
std::cout << counter << " errors\n";
}


vector<Aiport> AiportRepository::searchByIsoCountry(const string& text) const {
    vector<Aiport> result;
    for (const Aiport& a : aiports) {
        if (a.getIsoCountry().find(text) != string::npos){
            result.push_back(a);
        }
    }
    return result;
}
