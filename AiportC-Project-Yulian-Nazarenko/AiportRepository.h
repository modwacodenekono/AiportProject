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
};