#include "Engine.h"

std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
    os << "_engineNumber: " << rhs._engineNumber << "\n";
    os << " _engineType: " << static_cast<int>(rhs._engineType) << "\n";
    os << " _engineHorsePower: " << rhs._engineHorsePower << "\n";
    os << " _engineTorque: " << rhs._engineTorque << "\n";
    return os;
}

Engine::Engine(std::string engineNumber, EngineType engineType, int engineHorsePower, int engineTorque) : _engineNumber(engineNumber), _engineType(engineType), _engineHorsePower(engineHorsePower), _engineTorque(engineTorque)
{
}
