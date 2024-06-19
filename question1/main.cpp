/*
Khalif Pirtondi Siregar (s3895242)

Design and Justification:
- The code that has been produced to handle the hospital functions were implemented through the use of C++14 STL ordered container, specifically a vector.
- This choice has provided a platform for dynamic resizing, which is important in this case as the number of patients is fluctuative.
- I chose vectors in C++ as they allow for efficient access and modification of the elements, which is helpful in situations that require adding, removing and searching for patients.

- The patient data within the Patient class is encapsulated, which provides an organised and straighforward structure. This assists in storing individual patient details such as name, age, and registration number.
- The Patient class promotes encapsulation and data integrity through the methods which ensure that data is modified in a controlled manner.

- Utilising STL algorithms I implemented methods in the PatientRegister class for adding, removing, and retrieving patients, which ensures efficiency and readability.
- std::find_if is implemented to assist in locating patients from the register
- std::remove_if is implemented to assist in removing patients from the register
- Methods to check for duplicate patients are included, enhancing the overall functionality of this class.
- These approaches have provided useful utilities for managing and validating patient data.

- Error Handling was implemented through the use of exceptions.
- This approach ensures that errors are caught and handled appropriately, preventing the program from crashing unexpectedly.

- The AdmissionEntry class was included to manage individual hospital admission records for patients. 
- This class encapsulates the details of each admission, such as the admission date, discharge date, and the reason for admission. 
- By including this class, the system can keep track of a patient's hospital history in a structured manner. 
- The AdmissionEntry class allows for the addition of multiple admissions for each patient, providing a comprehensive view of their medical history. This is crucial for ensuring that all relevant medical information is readily accessible and organized, which is essential for effective patient care and record-keeping.

In summary, the overall design of my program puts a focuses on:
- the implementation of a vector to handle the functionaility of the program due to its dynamic nature and efficiency,
- encapsulation of patient data within dedicated classes,
- employing STL algorithms and exceptions to create a robust and maintainable codebase.
And the inclusion of the AdmissionEntry class further enhances the overall system by providing a structured and efficient strategy to manage and track patient admisions.
*/

#include <iostream>
#include "Patient.h"
#include "PatientRegister.h"
#include "Ward.h"

int main() {
    try {

        // Sample register Created for Testing
        PatientRegister newRegister;

        // Sample Admission Entries Created
        AdmissionEntry entry1("01-01-2021", "05-01-2021", "Ward A");
        AdmissionEntry entry2("10-01-2022", "15-01-2022", "Ward B");
        AdmissionEntry entry3("22-02-2023", "24-03-2023", "Ward C");

        // Sample Patients Created + Assigning Admission History to Patients
        Patient p1("John Doe", "10-2-1965", 1234567);
        p1.addAdmissionEntry(entry1);
        Patient p2("Jane Smith", "5-6-1970", 2345678);
        p2.addAdmissionEntry(entry2);
        Patient p3("Alice Johnson", "8-6-1999", 7587898);
        p3.addAdmissionEntry(entry3);

        // Sample Patients Added to Register
        newRegister.addPatient(p1);
        newRegister.addPatient(p2);
        newRegister.addPatient(p3);

        // Sample Ward Created + Assigning Patients to Wards
        Ward ward;
        ward.addPatientToWard(p1, "Ward A");
        ward.addPatientToWard(p2, "Ward B");
        ward.addPatientToWard(p3, "Ward C");


        // Listing out the Patients in Ward A
        std::cout << "Patients in Ward A:" << std::endl;
        for (const auto& patient : ward["Ward A"]) {
            std::cout << patient << std::endl;
        }

        // Listing out the Patients in Ward B
        std::cout << "Patients in Ward B:" << std::endl;
        for (const auto& patient : ward["Ward B"]) {
            std::cout << patient << std::endl;
        }

        // Listing out the Patients in Ward C
        std::cout << "Patients in Ward C:" << std::endl;
        for (const auto& patient : ward["Ward C"]) {
            std::cout << patient << std::endl;
        }

        // Display number of patients
        std::cout << "Number of patients: " << newRegister.getNumberOfPatients() << std::endl;

        // Check if a specific patient is in the register
        int regNumberToCheck = 1234567; // Checking if John Doe exists
        if (newRegister.checkPatientInRegister(regNumberToCheck)) {
            std::cout << "Patient with registration number: " << regNumberToCheck << " is in the register." << std::endl;
        } else {
            std::cout << "Patient with registration number: " << regNumberToCheck << " is not in the register." << std::endl;
        }

        int regNumberToRemove = 1234567; // Removing John Doe
        newRegister.removePatient(regNumberToRemove);

        /// Checking if the number of patients have changed after removing a patient
        std::cout << "Number of patients after removal: " << newRegister.getNumberOfPatients() << std::endl;

        // Check for duplicate patients
        if (newRegister.checkNoDuplicatePatients()) {
            std::cout << "No duplicate patients found in the register." << std::endl;
        } else {
            std::cout << "Duplicate patients found in the register." << std::endl;
        }


    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}


