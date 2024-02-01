#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include <vector>
#include "Car.h"

using CarPointer = std::shared_ptr<Car>;
using CarPointerContainer = std::vector<CarPointer>;
using EngineContainer = std::vector<Engine>;

void CreateObjects(CarPointerContainer& carData, EngineContainer& engineData);
int FindHorsePowerByCarId( CarPointerContainer& carData , std::string carId );
std::vector<Car> FindAbove80Torque(CarPointerContainer& carData);


#endif // FUNCTIONALITIES_H