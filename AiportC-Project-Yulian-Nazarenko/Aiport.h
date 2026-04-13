#pragma once
#include <string>
using namespace std;

class Aiport {
private:
    int aiportId;
    string type;
    string name;
    int elevationFt;
    string continent;
    string isoCountry;
    string isoRegion;
    string municipality;
    string icaoCode;
    string iataCode;
    string gpsCode;
    string localCode;
    double coordinatesX;
    double coordinatesY; // good names?

public:
    Aiport();
    void set(int aiportId, string type, string name, int elevationFt, string continent, string isoCountry, string isoRegion, string municipality, string icaoCode, string iataCode, string gpsCode, string localCode, double coordinatesX, double coordinatesY);

    int getId() const;
    string getType() const;
    string getName() const;
    string getElevationFt() const;
    double getContinent() const;
    string getIsbn() const;
    string getLanguage() const;
    int getPgaes() const;
    int getYear() const;

    void print() const;
};