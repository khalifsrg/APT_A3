#include "PatientRegister.h"

/// @brief Add a patient to the register
/// @param patient Patient object to be added to the register vector
/// @throws Invalid argument if registration number already assigned to another patient
void PatientRegister::addPatient (const Patient& patient) {
    if (!checkPatientInRegister(patient.getRegistrationNumber())) {
        patients.push_back(patient);
    } else {
        throw std::invalid_argument("Patient with the same registration number already exists.");
    }
}

/// @brief Remove a patient from the register
/// @param registrationNumber Patient's unique number to be used to find their profile
/// @throws Invalid argument if registration number does not exist
void PatientRegister::removePatient(int registrationNumber) {
    auto it = std::remove_if(patients.begin(), patients.end(),
                             [registrationNumber](const Patient& p) { return p.getRegistrationNumber() == registrationNumber; });
    if (it != patients.end()) {
        patients.erase(it, patients.end());
    } else {
        throw std::invalid_argument("Patient does not exist");
    }
}

/// @brief Getter for the number of patients in the vector
/// @return The number of patients stored in the vector
int PatientRegister::getNumberOfPatients() const {
    return patients.size();
}

/// @brief Check that a patient is currently registered
/// @param registrationNumber Object to be checked within the vector
/// @return True if patient is registered, otherwise false
bool PatientRegister::checkPatientInRegister(int registrationNumber) const {
    return std::any_of(patients.begin(), patients.end(),
                       [registrationNumber](const Patient& p) { return p.getRegistrationNumber() == registrationNumber; });
}

/// @brief Getter for patient within the PatientRegister
/// @param registrationNumber Object to be checked within the vector 
/// @return Desired patient's details
/// @throws Invalid argument if patient does not exist
Patient PatientRegister::getPatient(int registrationNumber) const {
    auto it = std::find_if(patients.begin(), patients.end(),
                           [registrationNumber](const Patient& p) { return p.getRegistrationNumber() == registrationNumber; });
    if (it != patients.end()) {
        return *it;
    } else {
        throw std::invalid_argument("Patient does not exist");
    }
}

/// @brief Operator to assist in outputting the getPatient() function
/// @param registrationNumber Object to identify the desired patient
/// @return Result of getPatient() function
Patient PatientRegister::operator[](int registrationNumber) const {
    return getPatient(registrationNumber);
}

/// @brief Check that there are no duplicatfe patients within the register
/// @return True if there are no duplicates, otherwise return false
bool PatientRegister::checkNoDuplicatePatients() const {
    std::vector<int> registrationNumbers;
    for (const auto& patient : patients) {
        if (std::find(registrationNumbers.begin(), registrationNumbers.end(), patient.getRegistrationNumber()) != registrationNumbers.end()) {
            return false;
        }
        registrationNumbers.push_back(patient.getRegistrationNumber());
    }
    return true;
}

/// @brief Getter for all patients within register
/// @return Return all the patients within the register
std::vector<Patient> PatientRegister::getAllPatients() const {
    return patients;
}