#include "Supplier.h"

Supplier::Supplier(int supplierId, const std::string& name, const std::string& contactInfo)
    : supplierId(supplierId), name(name), contactInfo(contactInfo) {
}

int Supplier::getSupplierId() const {
    return supplierId;
}

std::string Supplier::getName() const {
    return name;
}

std::string Supplier::getContactInfo() const {
    return contactInfo;
}