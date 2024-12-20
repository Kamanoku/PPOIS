#pragma once
#include <string>
#include "Technician.h"
#include "RepairOrder.h"

class Schedule {
private:
    int id;
    std::string date;
    std::string timeSlot;
    Technician technician;   // Ассоциация: расписание связано с техником
    RepairOrder repairOrder; // Ассоциация: расписание связано с заказом

public:
    Schedule(int id, const std::string& date, const std::string& timeSlot, const Technician& technician, const RepairOrder& repairOrder);

    int getId() const;
    std::string getDate() const;
    std::string getTimeSlot() const;
    Technician getTechnician() const;
    RepairOrder getRepairOrder() const;

    void setDate(const std::string& date);
    void setTimeSlot(const std::string& timeSlot);
    void setTechnician(const Technician& technician);
    void setRepairOrder(const RepairOrder& repairOrder);

    void printDetails() const;
};
