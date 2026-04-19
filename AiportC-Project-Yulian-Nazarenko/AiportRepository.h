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
    void addAirport(const Aiport& airport);
    void saveChanges() const;
};