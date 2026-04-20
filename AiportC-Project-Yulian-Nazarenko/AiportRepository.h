#pragma once
#include "Aiport.h"
#include <vector>
#include <map>
#include <utility>
using namespace std;

// Aiport repository class which works as a logic class
class AiportRepository {
private:
    // Vector which stores all aiports
    vector<Aiport> aiports;

public:
    // Methods to work with csv
    void loadFromCsv();
    void saveToCsv() const;

    // Search methods
    const Aiport* findAirportById(const string& key) const;
    vector<Aiport> searchByIsoCountry(const string& text) const;
    vector<Aiport> searchByName(const string& text) const;
    vector<Aiport> searchByIataCode(const string& text) const;

    map<string, int> countAirportsByType() const;

    void addAirport(const string& id, const string& type, const string& name, int elevation, const string& continent, const string& isoCountry, const string& isoRegion, const string& municipality, const string& icaoCode, const string& iataCode, const string& gpsCode, const string& localCode, double x, double y);

    // Distance calculation methods
    double distanceBetweenAirports(const string& a1, const string& a2) const;
    std::pair<const Aiport*, double> findNearestAirport(const string& id) const;
    vector<Aiport> airportsWithinRadius(const string& id, double radiusKm) const;

    // Elevation calculation methods
    const Aiport* findHighestElevation() const;
    const Aiport* findLowestElevation() const;

    // Data analythis and sorting
    vector<Aiport> airportsWithMissingIata() const;
    map<string, vector<Aiport>> groupByMunicipality() const;
    vector<Aiport> sortAirports(int mode, bool ascending = true) const;
};