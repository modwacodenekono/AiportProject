#pragma once
#include "Aiport.h"
#include <vector>
#include <map>
#include <set>

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
    void saveChanges() const;
};