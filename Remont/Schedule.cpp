#include "Schedule.h"
#include <iostream>

Schedule::Schedule(int id, const std::string& date, const std::string& timeSlot, const Technician& technician, const RepairOrder& repairOrder)
    : id(id), date(date), timeSlot(timeSlot), technician(technician), repairOrder(repairOrder) {
}

int Schedule::getId() const { return id; }
std::string Schedule::getDate() const { return date; }
std::string Schedule::getTimeSlot() const { return timeSlot; }
Technician Schedule::getTechnician() const { return technician; }
RepairOrder Schedule::getRepairOrder() const { return repairOrder; }

void Schedule::setDate(const std::string& date) { this->date = date; }
void Schedule::setTimeSlot(const std::string& timeSlot) { this->timeSlot = timeSlot; }
void Schedule::setTechnician(const Technician& technician) { this->technician = technician; }
void Schedule::setRepairOrder(const RepairOrder& repairOrder) { this->repairOrder = repairOrder; }

void Schedule::printDetails() const {
    std::cout << "Schedule ID: " << id << "\n"
        << "Date: " << date << "\n"
        << "Time Slot: " << timeSlot << "\n"
        << "Technician: " << technician.getName() << "\n"
        << "Repair Order ID: " << repairOrder.getId() << "\n";
}
