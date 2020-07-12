#pragma once

#include <unordered_map>
#include <string>

enum class Direction
{
    BACK,
    STAND,
    FORWARD,
};

using Gear = short;
using Speed = short;
using SpeedInterval = std::pair<Speed, Speed>;

class CCar
{
public:
    CCar() = default;
    ~CCar() = default;

    Speed GetSpeed() const;
    bool SetSpeed(Speed speed);

    Gear GetGear() const;
    bool SetGear(Gear gear);

    bool TurnOnEngine();
    bool TurnOffEngine();

    std::string GetInfo() const;
    std::string GetDirection() const;

private:
    bool m_isEngineOn = false;
    Gear m_gear = 0;
    Speed m_speed = 0;
    Direction m_direction = Direction::STAND;

    void SetDirection();

    const std::unordered_map<Gear, SpeedInterval> m_speedIntervals{
        { -1, { 0, 20 } },
        { 0, { 0, 150 } },
        { 1, { 0, 30 } },
        { 2, { 20, 50 } },
        { 3, { 30, 60 } },
        { 4, { 40, 90 } },
        { 5, { 50, 150 } },
    };
};