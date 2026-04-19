#include "AiportRepository.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iostream>


//----------Maths----------

static double deg2rad(double deg) { return deg * (3.14159265358979323846 / 180.0); }

// Haversine formula
static double haversine(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371.0; // km
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c;
}




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
    file.close();
std::cout << counter << " errors\n";
}



// Find airport by id
const Aiport* AiportRepository::findAirportById(const string& key) const {
    for (const Aiport& a : aiports) {
        if (a.getId() == key) return &a;
    }
    return nullptr;
}


vector<Aiport> AiportRepository::searchByIsoCountry(const string& text) const {
    vector<Aiport> result;
    for (const Aiport& a : aiports) {
        if (a.getIsoCountry().find(text) != string::npos){
            result.push_back(a);
        }
    }
    return result;
} // simplify these 3 search functions by using a lambda and a common search function?


vector<Aiport> AiportRepository::searchByName(const string& text) const {
    vector<Aiport> result;
    for (const Aiport& a : aiports) {
        if (a.getName().find(text) != string::npos){
            result.push_back(a);
        }
    }
    return result;
}


vector<Aiport> AiportRepository::searchByIataCode(const string& text) const {
    vector<Aiport> result;
    for (const Aiport& a : aiports) {
        if (a.getIataCode().find(text) != string::npos){
            result.push_back(a);
        }
    }
    return result;
}

map<string, int> AiportRepository::countAirportsByType() const {
    map<string, int> aiportTypes;
    for (const Aiport& a : aiports) {
        ++aiportTypes[a.getType()];
    }
    return aiportTypes;
}

void AiportRepository::addAirport(const string& id, const string& type, const string& name, int elevation, const string& continent, const string& isoCountry, const string& isoRegion, const string& municipality, const string& icaoCode, const string& iataCode, const string& gpsCode, const string& localCode, double x, double y) {
    Aiport a;
    a.set(id, type, name, elevation, continent, isoCountry, isoRegion, municipality, icaoCode, iataCode, gpsCode, localCode, x, y);
    aiports.push_back(a);
	a.print();
}


void AiportRepository::saveToCsv() const {
    ofstream file("airports.csv");
    if (!file.is_open()) {
        cout << "Error: unable to open airports.csv for writing.\n";
        return;
    }

    file << "ident,type,name,elevation_ft,continent,iso_country,iso_region,municipality,icao_code,iata_code,gps_code,local_code,coordinatesX,coordinatesY\n";

    for (const Aiport& a : aiports) {
        file << a.getId() << ","
            << a.getType() << ","
            << a.getName() << ","
            << a.getElevationFt() << ","
            << a.getContinent() << ","
            << a.getIsoCountry() << ","
            << a.getIsoRegion() << ","
            << a.getMunicipality() << ","
            << a.getIcaoCode() << ","
            << a.getIataCode() << ","
            << a.getGpsCode() << ","
            << a.getLocalCode() << ","
            << a.getCoordinatesX() << ","
            << a.getCoordinatesY() << "\n";
    }
    file.close();
    cout << "Saved " << aiports.size() << " airports to airports.csv\n"; //remove
}



//advanced features

double AiportRepository::distanceBetweenAirports(const string& a1, const string& a2) const {
    const Aiport* A = findAirportById(a1);
    const Aiport* B = findAirportById(a2);
    if (!A || !B) return -1.0;
    return haversine(A->getCoordinatesX(), A->getCoordinatesY(), B->getCoordinatesX(), B->getCoordinatesY());
}

