#include "PatientRegister.h"

void PatientRegister::addPatient (const Patient& patient) {
    if (!isPatientInRegister(patient.getRegistrationNumber())) {
        patients.push_back(patient);
    } else {
        throw std::invalid_argument("Patient with the same registration number already exists.");
    }
}

void PatientRegister::removePatient(int registrationNumber) {
    auto it = std::remove_if(patients.begin(), patients.end(),
                             [registrationNumber](const Patient& p) { return p.getRegistrationNumber() == registrationNumber; });
    if (it != patients.end()) {
        patients.erase(it, patients.end());
    } else {
        throw std::invalid_argument("Patient not found");
    }
}

int PatientRegister::getNumberOfPatients() const {
    return patients.size();
}

bool PatientRegister::isPatientInRegister(int registrationNumber) const {
    return std::any_of(patients.begin(), patients.end(),
                       [registrationNumber](const Patient& p) { return p.getRegistrationNumber() == registrationNumber; });
}

Patient PatientRegister::getPatient(int registrationNumber) const {
    auto it = std::find_if(patients.begin(), patients.end(),
                           [registrationNumber](const Patient& p) { return p.getRegistrationNumber() == registrationNumber; });
    if (it != patients.end()) {
        return *it;
    } else {
        throw std::invalid_argument("Patient not found");
    }
}

Patient PatientRegister::operator[](int registrationNumber) const {
    return getPatient(registrationNumber);
}

bool PatientRegister::hasNoDuplicatePatients() const {
    std::vector<int> registrationNumbers;
    for (const auto& patient : patients) {
        if (std::find(registrationNumbers.begin(), registrationNumbers.end(), patient.getRegistrationNumber()) != registrationNumbers.end()) {
            return false;
        }
        registrationNumbers.push_back(patient.getRegistrationNumber());
    }
    return true;
}

std::vector<Patient> PatientRegister::getAllPatients() const {
    return patients;
}