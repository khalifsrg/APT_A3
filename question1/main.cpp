#include <iostream>
#include "Patient.h"
#include "PatientRegister.h"
#include "Ward.h"

int main() {
    // Create patients
    Patient p1("John Doe", "10-2-1965", 1234567);
    Patient p2("Jane Smith", "5-6-1970", 2345678);

    // Create a ward and add patients
    Ward ward;
    ward.addPatientToWard(p1, "Ward A");
    ward.addPatientToWard(p2, "Ward B");

    // List patients in Ward A
    std::cout << "Patients in Ward A:" << std::endl;
    for (const auto& patient : ward["Ward A"]) {
        std::cout << patient << std::endl;
    }

    // List patients in Ward B
    std::cout << "Patients in Ward B:" << std::endl;
    for (const auto& patient : ward["Ward B"]) {
        std::cout << patient << std::endl;
    }

    return 0;
}

