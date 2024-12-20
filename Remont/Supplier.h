#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>

class Supplier {
public:
    Supplier(int supplierId, const std::string& name, const std::string& contactInfo);

    int getSupplierId() const;
    std::string getName() const;
    std::string getContactInfo() const;

private:
    int supplierId;
    std::string name;
    std::string contactInfo;
};

#endif // SUPPLIER_H