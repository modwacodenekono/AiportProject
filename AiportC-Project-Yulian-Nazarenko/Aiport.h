#pragma once
#include <string>
using namespace std;

class Aiport {
private:
    string aiportId;
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
    double coordinatesX; // single coordinate field (stored as string)
    double coordinatesY; // single coordinate field (stored as string)

public:
	Aiport();

    void set(string id, string t, string n, int el, string c, string isoC, string isoR, string m, string icao, string iata, string gps, string local, double X, double Y);

    string getId() const;
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
};