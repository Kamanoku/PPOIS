#include "RepairHistory.h"

RepairHistory::RepairHistory(int orderId, const std::string& description, const std::string& date, const std::string& technician)
    : orderId(orderId), description(description), date(date), technician(technician) {
}

int RepairHistory::getOrderId() const {
    return orderId;
}

std::string RepairHistory::getDescription() const {
    return description;
}

std::string RepairHistory::getDate() const {
    return date;
}

std::string RepairHistory::getTechnician() const {
    return technician;
}