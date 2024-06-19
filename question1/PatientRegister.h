#ifndef PATIENTREGISTER_H
#define PATIENTREGISTER_H

#include "Patient.h"
#include <vector>
#include <algorithm>
#include <stdexcept>

class PatientRegister {
private:
    std::vector<Patient> patients;
public:
    void addPatient(const Patient& patient);

    void removePatient(int registrationNumber);

    int getNumberOfPatients() const;

    bool isPatientInRegister(int registrationNumber) const;

    Patient getPatient(int regisrationNumber) const;

    Patient operator[](int registrationNumber) const;

    bool hasNoDuplicatePatients() const;

    std::vector<Patient> getAllPatients() const;
};

#endif // PATIENTREGISTER_H