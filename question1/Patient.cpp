#include <string>
#include <vector>
#include "Patient.h"

Patient::Patient(const std::string& name, const std::string& dateOfBirth, int registrationNumber)
    : name(name), dateOfBirth(dateOfBirth), registrationNumber(registrationNumber) {}

std::string Patient::getName() const {
        return name;
    }
    
std::string Patient::getDateOfBirth() const {
    return dateOfBirth;
}
int Patient::getRegistrationNumber() const {
    return registrationNumber;
}
std::vector<AdmissionEntry> Patient::getAdmissionHistory() const {
    return admissionHistory;
}

void Patient::addAdmissionEntry(const AdmissionEntry& entry) {
    admissionHistory.push_back(entry);
}

// Overload operator<<
std::ostream& operator<<(std::ostream& os, const Patient& patient) {
    os << "Name: " << patient.name << ", Date of Birth: " << patient.dateOfBirth
       << ", Registration Number: " << patient.registrationNumber << "\nAdmission History:\n";
    for (const auto& entry : patient.admissionHistory) {
        os << entry << "\n";
    }
    return os;
}



