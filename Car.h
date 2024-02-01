#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <functional>
#include "CarType.h"
#include "Engine.h"

using RefType = std::reference_wrapper<Engine>;

class Car
{
private:
    const std::string _carId{""};
    const std::string _carBrand{""};
    const CarType _carType{CarType::SEDAN};
    float _carPrice{0.0f};
    RefType _carEngine;

public:
    Car() = delete;             // cant make a default car
    Car(const Car &) = default; // a function is there that says
    Car(Car &&) = delete;
    Car &operator=(const Car &) = delete;
    Car &operator=(Car &&) = delete;
    ~Car() = default;

    Car(std::string carId, std::string carBrand, CarType carType, RefType carEngine, float carPrice);

    std::string carId() const { return _carId; }
    std::string carBrand() const { return _carBrand; }
    CarType carType() const { return _carType; }
    float carPrice() const { return _carPrice; }
    void setCarPrice(float carPrice) { _carPrice = carPrice; }
    RefType carEngine() const { return _carEngine; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H