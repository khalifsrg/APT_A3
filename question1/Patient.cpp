#include <string>
#include <vector>
#include "Patient.h"

/// @brief Constructor
/// @param name Name of the Patient
/// @param dateOfBirth Date of Birth of thfe Patient
/// @param registrationNumber Patient's Assigned Registration Number
Patient::Patient(const std::string& name, const std::string& dateOfBirth, int registrationNumber)
    : name(name), dateOfBirth(dateOfBirth), registrationNumber(registrationNumber) {}

//Getters
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
/// @brief Append the new AdmissionEntry to the end of the AdmissionHistory vector
/// @param entry The AdmissionEntry Object to be appended to the vector
void Patient::addAdmissionEntry(const AdmissionEntry& entry) {
    admissionHistory.push_back(entry);
}

/// @brief Overload operator to assist in outputting the personal details of the patient
/// @param os Output stream where the patient details will be printed
/// @param patient The patient object that contains the details to be printed
/// @return Return the output stream with the appended details
std::ostream& operator<<(std::ostream& os, const Patient& patient) {
    os << "Name: " << patient.name << ", Date of Birth: " << patient.dateOfBirth
       << ", Registration Number: " << patient.registrationNumber << "\nAdmission History:\n";
    for (const auto& entry : patient.admissionHistory) {
        os << entry << "\n";
    }
    return os;
}



