#ifndef H_APARTMENT
#define H_APARTMENT

#include "Location.h"

enum AparmentStatus {
    FREE,
    OCCUPIED
};

class Apartment {
public:
    Apartment();
    ~Apartment();
private:
    Location location;
    AparmentStatus status;
    double pricePerDay;
    int start, end;
};

#endif