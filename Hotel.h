#ifndef H_HOTEL
#define H_HOTEL

#include <vector>
#include <string>

#include "Apartment.h"

using namespace std;

class Hotel {
public:
    Hotel();
    ~Hotel();

    void saveData(const std::string &filePath) const;
    void loadData(const std::string &filePath);
private:
    vector<Apartment> apartment;
};

#endif