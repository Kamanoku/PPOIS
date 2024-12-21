#ifndef WARRANTY_H
#define WARRANTY_H

#include <string>

class Warranty {
public:
    Warranty(int warrantyId, const std::string& service, int durationMonths, const std::string& terms);

    int getWarrantyId() const;
    std::string getService() const;
    int getDurationMonths() const;
    std::string getTerms() const;

private:
    int warrantyId;
    std::string service;
    int durationMonths;
    std::string terms;
};

#endif 
