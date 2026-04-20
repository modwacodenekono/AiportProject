#pragma once
#include <string>
using namespace std;

//Aiport class used to store and return values. It follows incapsulation and other OOP principles
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
    double coordinatesX; 
    double coordinatesY; 

public:
	Aiport();

    // Set function to make one instance of a class
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

    // Display all information about one single aiport
    void print() const;
};