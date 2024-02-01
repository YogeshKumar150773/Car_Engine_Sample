#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "IdNotFoundException.h"
#include "NoMatchingInstanceException.h"
#include <iostream>

int main()
{
    CarPointerContainer carData;
    EngineContainer engineData;

    CreateObjects(carData, engineData);

    try
    {
        int ans = FindHorsePowerByCarId(carData, "999");
        std::cout << "Horse Power for given ID : " << ans << std::endl;
    }
    catch (EmptyContainerException &ex)
    {
        std::cout << ex.what() << '\n';
    }
    catch (IdNotFoundException &ex)
    {
        std::cout << ex.what() << '\n';
    }

    std::cout << std::endl;

    try
    {
        std::vector<Car> result = FindAbove80Torque(carData);
        std::cout << "Details of cars above 80 torque are : " << std::endl;
        for (Car &c : result)
        {
            std::cout << c << "\n";
        }
    }
    catch (EmptyContainerException &ex)
    {
        std::cout << ex.what() << '\n';
    }
    catch (IdNotFoundException &ex)
    {
        std::cout << ex.what() << '\n';
    }

    std::cout << std::endl;
}