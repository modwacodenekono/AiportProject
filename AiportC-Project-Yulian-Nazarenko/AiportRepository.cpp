#include "AiportRepository.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

Aiport::Aiport()
    : aiportId(0), type(""), name(""), elevationFt(0), continent(""), isoCountry(""), isoRegion(""), municipality(""), icaoCode(""), iataCode(""), gpsCode(""), localCode(""), coordinatesX(0.0), coordinatesY(0.0)
{}

void Aiport::set(int aiportId, string type, string name, int elevationFt, string continent, string isoCountry, string isoRegion, string municipality, string icaoCode, string iataCode, string gpsCode, string localCode, double coordinatesX, double coordinatesY)
{
    this->aiportId = aiportId;
    this->type = type;
    this->name = name;
    this->elevationFt = elevationFt;
    this->continent = continent;
    this->isoCountry = isoCountry;
    this->isoRegion = isoRegion;
    this->municipality = municipality;
    this->icaoCode = icaoCode;
    this->iataCode = iataCode;
    this->gpsCode = gpsCode;
    this->localCode = localCode;
    this->coordinatesX = coordinatesX;
    this->coordinatesY = coordinatesY;
}

int Aiport::getId() const { return aiportId; }
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

void Aiport::print() const
{
    std::cout << "Airport[" << aiportId << "] " << name << " (" << iataCode << ")\n";
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
        int id, elevation;
        double coordinatesX, coordinatesY;
        string type, name, continent, isoCountry, isoRegion, municipality, icaoCode, iataCode, gpsCode, localCode;

        try {
            getline(ss, temp, ','); id = stoi(temp);
            getline(ss, type, ',');
            getline(ss, name, ',');
            getline(ss, temp, ','); elevation = stoi(temp);
            getline(ss, continent, ',');
            getline(ss, isoCountry, ',');
            getline(ss, isoRegion, ',');
            getline(ss, municipality, ',');
            getline(ss, icaoCode, ',');
            getline(ss, iataCode, ',');
            getline(ss, gpsCode, ',');
            getline(ss, localCode, ',');
            getline(ss, temp, ','); coordinatesX = stod(temp);
            getline(ss, temp, ','); coordinatesY = stod(temp);

            a.set(id, type, name, elevation, continent, isoCountry, isoRegion, municipality, icaoCode, iataCode, gpsCode, localCode, coordinatesX, coordinatesY);
            aiports.push_back(a);
        }
        catch (...) {
        }
    }
}

void AiportRepository::printFirst() {
    if (!aiports.empty()) {
        aiports[0].print();
    }
}
