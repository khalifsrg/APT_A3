#ifndef PATIENT_H
#define PATIENT_H

#include "AdmissionEntry.h"
#include <string>
#include <vector>
#include <iostream>

class Patient {
private:
    std::string name;
    std::string dateOfBirth;
    int registrationNumber;
    std::vector<AdmissionEntry> admissionHistory;

public:
    // Constructor
    Patient(const std::string& name, const std::string& dateOfBirth, int registrationNumber);

    std::string getName() const;
    
    std::string getDateOfBirth() const;

    int getRegistrationNumber() const;

    std::vector<AdmissionEntry> getAdmissionHistory() const;

    void addAdmissionEntry(const AdmissionEntry& entry);

    friend std::ostream& operator<<(std::ostream& os, const Patient& patient);
    
};

#endif // PATIENT_H