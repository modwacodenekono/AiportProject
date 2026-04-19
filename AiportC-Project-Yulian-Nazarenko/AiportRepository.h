#pragma once
#include "Aiport.h"
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;


class AiportRepository {
private:
    vector<Aiport> aiports;

public:
    void loadFromCsv();

    vector<Aiport> searchByIsoCountry(const string& text) const;
    vector<Aiport> searchByName(const string& text) const;
    vector<Aiport> searchByIataCode(const string& text) const;
    map<string, int> countAirportsByType() const;
    void addAirport(const string& id, const string& type, const string& name, int elevation, const string& continent, const string& isoCountry, const string& isoRegion, const string& municipality, const string& icaoCode, const string& iataCode, const string& gpsCode, const string& localCode, double x, double y);
    void saveToCsv() const;

    const Aiport* findAirportById(const string& key) const;

    // Calculate great-circle distance (km) between two airports identified by id
    // Returns negative value if one of the airports is not found
    double distanceBetweenAirports(const string& a1, const string& a2) const;
    // Find nearest airport to given id. Returns pair {pointer, distance_km} or {nullptr, -1.0}
    std::pair<const Aiport*, double> findNearestAirport(const string& id) const;
};