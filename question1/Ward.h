#ifndef WARD_H
#define WARD_H

#include "Patient.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <stdexcept>

class Ward {
private:
    std::unordered_map<std::string, std::vector<Patient>> wards;

public:
    Ward();

    void addPatientToWard(const Patient& patient, const std::string& wardName);

    void removePatientFromWard(int registrationNumber, const std::string& wardName);

    int getTotalNumberOfPatients() const;

    int getNumberOfPatientsInWard(const std::string& wardName) const;

    std::string getWardOfPatient(int registrationNumber) const;

    std::vector<Patient> operator[](const std::string& wardName) const;
};

#endif