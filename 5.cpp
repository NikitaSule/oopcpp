#include <iostream>
#include <string>
#include <vector>

class Vehicle {
protected:
    std::string license_plate;
    int capacity;
    std::string vehicle_type;

public:
    Vehicle(std::string plate, int cap, std::string type)
        : license_plate(plate), capacity(cap), vehicle_type(type) {}

    virtual void displayInfo() {
        std::cout << "License Plate: " << license_plate << std::endl;
        std::cout << "Capacity: " << capacity << std::endl;
        std::cout << "Vehicle Type: " << vehicle_type << std::endl;
    }
};

class Bus : public Vehicle {
private:
    std::string route_number;
    std::string current_location;

public:
    Bus(std::string plate, int cap, std::string type, std::string route, std::string location)
        : Vehicle(plate, cap, type), route_number(route), current_location(location) {}

    void displayInfo() override {
        Vehicle::displayInfo();
        std::cout << "Route Number: " << route_number << std::endl;
        std::cout << "Current Location: " << current_location << std::endl;
    }
};

class Train : public Vehicle {
private:
    std::string train_number;
    int carriages;

public:
    Train(std::string plate, int cap, std::string type, std::string train, int cars)
        : Vehicle(plate, cap, type), train_number(train), carriages(cars) {}

    void displayInfo() override {
        Vehicle::displayInfo();
        std::cout << "Train Number: " << train_number << std::endl;
        std::cout << "Carriages: " << carriages << std::endl;
    }
};

class Route {
private:
    std::string route_number;
    std::string start_location;
    std::string end_location;
    std::vector<Vehicle*> vehicles;
    std::string schedule;

public:
    Route(std::string route, std::string start, std::string end, std::string sch)
        : route_number(route), start_location(start), end_location(end), schedule(sch) {}

    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }
};

class Passenger {
private:
    std::string name;
    std::string ticket_id;
    std::vector<std::string> travel_history;

public:
    Passenger(std::string n, std::string ticket) : name(n), ticket_id(ticket) {}

    void addTravelHistory(std::string location) {
        travel_history.push_back(location);
    }
};

class TransportCompany {
public:
    void addVehicleToRoute(Vehicle* vehicle, Route* route) {
        route->addVehicle(vehicle);
    }

    void sellTicketToPassenger(Passenger* passenger, std::string ticket_id) {
        passenger->addTravelHistory(ticket_id);
    }
};

int main() {
    Bus bus("ABC123", 50, "Bus", "101", "Station A");
    Train train("XYZ789", 200, "Train", "A1", 8);
    
    Route route1("101", "Station A", "Station B", "8:00");
    TransportCompany company;
    company.addVehicleToRoute(&bus, &route1);
    company.addVehicleToRoute(&train, &route1);

    Passenger passenger("Alice", "T123");
    company.sellTicketToPassenger(&passenger, "T123");

    return 0;
}