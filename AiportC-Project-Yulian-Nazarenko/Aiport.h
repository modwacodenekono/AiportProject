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
    int getElevationFt() const;
    string getContinent() const;
    string getIsoCountry() const;
    string getIsoRegion() const;
    string getMunicipality() const;
    string getIcaoCode() const;
    string getIataCode() const;
    string getGpsCode() const;
    string getLocalCode() const;
    double getCoordinatesX() const;
    double getCoordinatesY() const;

    void print() const;
};