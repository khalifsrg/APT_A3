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

/// @brief Overload operator to assist in outputting the Admission history of the patient
/// @param os Output stream where the admission entry details will be printed
/// @param entry The AdmissionEntry object that contains the details to be printed
/// @return Return the output stream with the appended details
std::ostream& operator<<(std::ostream& os, const AdmissionEntry& entry) {
    os << "Admission Date: " << entry.admissionDate << ", Discharge Date: " << entry.dischargeDate << ", Admitted Ward: " << entry.admittedWard;
    return os;
}
