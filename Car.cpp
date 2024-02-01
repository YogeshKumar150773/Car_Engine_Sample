#include "Car.h"

std::ostream &operator<<(std::ostream &os, const Car &rhs)
{
    os << "_carId: " << rhs._carId << "\n";
    os << " _carBrand: " << rhs._carBrand << "\n";
    os << " _carType: " << static_cast<int>(rhs._carType) << "\n";
    os << " _carPrice: " << rhs._carPrice << "\n";
    os << " _carEngine: " << rhs._carEngine.get() << "\n";                          //this is not getter but this is .get() member function of reference wrapper
    return os;
}

Car::Car(std::string carId, std::string carBrand, CarType carType, RefType carEngine, float carPrice) : _carId(carId), _carBrand(carBrand), _carType(carType), _carEngine(carEngine), _carPrice(carPrice)
{
}