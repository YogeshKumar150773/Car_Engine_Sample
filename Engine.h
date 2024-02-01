#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include "EngineType.h"

class Engine
{
private:
    const std::string _engineNumber{""};
    const EngineType _engineType{EngineType::HYBRID};
    int _engineHorsePower{0};
    int _engineTorque{0};

public:
    Engine() = default;
    Engine(const Engine &) = default;
    Engine(Engine &&) = default;
    Engine &operator=(const Engine &) = delete;
    Engine &operator=(Engine &&) = delete;
    ~Engine() = default;

    Engine(std::string engineNumber, EngineType engineType, int engineHorsePower, int engineTorque);

    std::string engineNumber() const { return _engineNumber; }
    EngineType engineType() const { return _engineType; }
    int engineHorsePower() const { return _engineHorsePower; }
    int engineTorque() const { return _engineTorque; }
    void setEngineTorque(int engineTorque) { _engineTorque = engineTorque; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};

#endif // ENGINE_H