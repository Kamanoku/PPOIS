#include "Warranty.h"

Warranty::Warranty(int warrantyId, const std::string& service, int durationMonths, const std::string& terms)
    : warrantyId(warrantyId), service(service), durationMonths(durationMonths), terms(terms) {
}

int Warranty::getWarrantyId() const {
    return warrantyId;
}

std::string Warranty::getService() const {
    return service;
}

int Warranty::getDurationMonths() const {
    return durationMonths;
}

std::string Warranty::getTerms() const {
    return terms;
}