#ifndef REPAIR_HISTORY_H
#define REPAIR_HISTORY_H

#include <string>

class RepairHistory {
public:
    RepairHistory(int orderId, const std::string& description, const std::string& date, const std::string& technician);

    int getOrderId() const;
    std::string getDescription() const;
    std::string getDate() const;
    std::string getTechnician() const;

private:
    int orderId;
    std::string description;
    std::string date;
    std::string technician;
};

#endif // REPAIR_HISTORY_H