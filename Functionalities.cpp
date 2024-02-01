#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "IdNotFoundException.h"
#include "NoMatchingInstanceException.h"

void CreateObjects(CarPointerContainer &carData, EngineContainer &engineData)
{
    engineData.emplace_back(Engine("E101", EngineType::ICT, 400, 111)); // we dont use make_shared here as Engine is created on the stack and doesnt use shared pointer
    carData.emplace_back(std::make_shared<Car>("c101", "Honda", CarType::SEDAN, engineData[0], 890000.0f));
}

/*
    case 1 : Find a match and return
    case 2 : data is empty
    case 3 : no matching ID
*/

int FindHorsePowerByCarId(CarPointerContainer &carData, std::string carId)
{
    // case 2 : empty data
    if (carData.empty()) // this returns a boolean value
    {
        throw EmptyContainerException("Your data is empty!");
    }

    // case 1 : Find a match and return
    for (CarPointer &ptr : carData)
    {
        if (ptr->carId() == carId)
        {
            return ptr->carEngine().get().engineHorsePower();
        }
    }

    // case 3 : no matching ID
    throw IdNotFoundException("ID DEKH KE PASS KARO!");
}

/*
    case 1 : empty input
    case 2 : at least one car with above 80 torque
    case 3 : no car above 80 torque exists
*/

std::vector<Car> FindAbove80Torque(CarPointerContainer &carData)
{
    // case 1 : empty
    if (carData.empty()) // this returns a boolean value
    {
        throw EmptyContainerException("Your data is empty!");
    }

    std::vector<Car> result;

    for (CarPointer &ptr : carData)
    {
        if (ptr->carEngine().get().engineTorque() > 80)
        {
            result.emplace_back(*ptr);
        }
    }

    if (result.empty())
    {
        throw NoMatchingInstanceException("Container has no matching Cars!");
    }

    return result;
}