#include "AdmissionEntry.h"

// Constructor
AdmissionEntry::AdmissionEntry(const std::string& admissionDate, const std::string& admittedWard, const std::string& dischargeDate)
    : admissionDate(admissionDate), dischargeDate(dischargeDate), admittedWard(admittedWard) {}

// Getters
std::string AdmissionEntry::getAdmissionDate() const {
    return admissionDate;
}

std::string AdmissionEntry::getDischargeDate() const {
    return dischargeDate;
}

std::string AdmissionEntry::getAdmittedWard() const {
    return admittedWard;
}

// Setters
void AdmissionEntry::setDischargeDate(const std::string& dischargeDate) {
    this->dischargeDate = dischargeDate;
}

// Overload operator<<
std::ostream& operator<<(std::ostream& os, const AdmissionEntry& entry) {
    os << "Admission Date: " << entry.admissionDate << ", Discharge Date: " << entry.dischargeDate << ", Admitted Ward: " << entry.admittedWard;
    return os;
}
