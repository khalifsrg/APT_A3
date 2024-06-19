#include "Ward.h"

Ward::Ward() {
    wards["Ward A"] = std::vector<Patient>();
    wards["Ward B"] = std::vector<Patient>();
    wards["Ward C"] = std::vector<Patient>();
    wards["Ward D"] = std::vector<Patient>();
    wards["Ward E"] = std::vector<Patient>();
}

void Ward::addPatientToWard(const Patient& patient, const std::string& wardName) {
    if (wards.find(wardName) != wards.end()) {
        // Ensure the patient is not in any other ward
        for (auto& [ward, patients] : wards) {
            auto it = std::find_if(patients.begin(), patients.end(),
                                   [patient](const Patient& p) { return p.getRegistrationNumber() == patient.getRegistrationNumber(); });
            if (it != patients.end()) {
                throw std::invalid_argument("Patient is already in a ward");
            }
        }
        wards[wardName].push_back(patient);
    } else {
        throw std::invalid_argument("Ward not found");
    }
}

void Ward::removePatientFromWard(int registrationNumber, const std::string& wardName) {
    if (wards.find(wardName) != wards.end()) {
        auto& patients = wards[wardName];
        auto it = std::remove_if(patients.begin(), patients.end(),
                                 [registrationNumber](const Patient& p) { return p.getRegistrationNumber() == registrationNumber; });
        if (it != patients.end()) {
            patients.erase(it, patients.end());
        } else {
            throw std::invalid_argument("Patient not found in the specified ward");
        }
    } else {
        throw std::invalid_argument("Ward not found");
    }
}

// Get the number of patients in all wards
int Ward::getTotalNumberOfPatients() const {
    int total = 0;
    for (const auto& [ward, patients] : wards) {
        total += patients.size();
    }
    return total;
}

// Get the number of patients in a specific ward
int Ward::getNumberOfPatientsInWard(const std::string& wardName) const {
    if (wards.find(wardName) != wards.end()) {
        return wards.at(wardName).size();
    } else {
        throw std::invalid_argument("Ward not found");
    }
}

// Get the ward that a patient is in
std::string Ward::getWardOfPatient(int registrationNumber) const {
    for (const auto& [ward, patients] : wards) {
        auto it = std::find_if(patients.begin(), patients.end(),
                               [registrationNumber](const Patient& p) { return p.getRegistrationNumber() == registrationNumber; });
        if (it != patients.end()) {
            return ward;
        }
    }
    throw std::invalid_argument("Patient not found in any ward");
}

// Overload operator[] to retrieve the collection of all patients in a given ward
std::vector<Patient> Ward::operator[](const std::string& wardName) const {
    if (wards.find(wardName) != wards.end()) {
        return wards.at(wardName);
    } else {
        throw std::invalid_argument("Ward not found");
    }
}