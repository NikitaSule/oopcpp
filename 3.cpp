#include <iostream>
#include <vector>
#include <string>

class Person {
    std::string name;
    std::string date_of_birth;
    std::string contact_info;
};

class Patient : public Person {
    int patient_id;
    std::vector<MedicalRecord> medical_records;

public:
    void scheduleAppointment() {}
};

class Doctor : public Person {
    std::string specialization;
    std::vector<Appointment> appointments;

public:
    void setAppointment() {}
};

class Appointment {
    std::string date;
    std::string time;
    Patient patient;
    Doctor doctor;
};

class MedicalRecord {
    Patient patient;
    Doctor doctor;
    std::string diagnosis;
    std::string treatment;
};

class Clinic {
public:
    void manageAppointments() {}
    void managePatients() {}
    void manageDoctors() {}
};

int main() {
    return 0;
}