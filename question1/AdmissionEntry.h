#ifndef ADMISSIONENTRY_H
#define ADMISIONENTRY_H

#include <string>
#include <iostream>

class AdmissionEntry {
private: 
    std::string admissionDate;
    std::string dischargeDate;
    std::string admittedWard;

public:
    AdmissionEntry(const std::string& admissionDate, const std::string& admittedWard, const std::string& dischargeDate = "");

    std::string getAdmissionDate() const;
    std::string getDischargenDate() const;
    std::string getAdmittedWard() const;

    void setDischargeDate (const std::string& dischargeDate);

    friend std::ostream& operator<<(std::ostream& os, const AdmissionEntry& entry);
};

#endif // ADMISSIONENTRY_H