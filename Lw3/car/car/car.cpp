#include "car.h"

bool CCar::SetSpeed(Speed speed)
{
    if (m_gear > 5 || m_gear < -1)
        return false;

    if (speed < 0 || speed > 150)
        return false;

    if (!m_isEngineOn)
        return false;
    if (speed == m_speed)
        return true;

    if (m_gear == 0 && speed > m_speed)
        return false;

    const SpeedInterval speedIntervalForCurrentGear = m_speedIntervals.at(m_gear);
    const Speed minSpeed = speedIntervalForCurrentGear.first;
    const Speed maxSpeed = speedIntervalForCurrentGear.second;

    if (m_gear != 0 && (speed < minSpeed || speed > maxSpeed))
        return false;

    m_speed = speed;

    SetDirection();

    return true;
}

Speed CCar::GetSpeed() const
{
    return m_speed;
}

bool CCar::SetGear(Gear gear)
{
    if (!m_isEngineOn && gear != 0)
        return false;
    if (gear == m_gear)
        return true;

    if (gear == -1 && m_speed != 0)
        return false;
    if (gear == 1 && m_direction == Direction::BACK && m_speed != 0)
        return false;

    const SpeedInterval speedIntervalForNewGear = m_speedIntervals.at(gear);
    const Speed minSpeed = speedIntervalForNewGear.first;
    const Speed maxSpeed = speedIntervalForNewGear.second;

    if (m_speed < minSpeed || m_speed > maxSpeed)
        return false;

    m_gear = gear;

    SetDirection();

    return true;
}

Gear CCar::GetGear() const
{
    return m_gear;
}

bool CCar::TurnOnEngine()
{
    if (m_gear != 0 || m_speed != 0)
        return false;

    m_isEngineOn = true;

    return m_isEngineOn;
}

bool CCar::TurnOffEngine()
{
    if (m_gear != 0 || m_direction != Direction::STAND)
        return false;

    m_isEngineOn = false;

    return true;
}

std::string CCar::GetInfo() const
{
    std::string info;

    std::string engineInfo = m_isEngineOn ? "enabled" : "disabled";

    info.append("Engine status: " + engineInfo + '\n');
    info.append("Direction: " + GetDirection() + '\n');
    info.append("Current speed: " + std::to_string(m_speed) + '\n');
    info.append("Current gear: " + std::to_string(m_gear));

    return info;
}

std::string CCar::GetDirection() const
{
    switch (m_direction)
    {
    case Direction::STAND:
        return "stand";
    case Direction::BACK:
        return "back";
    case Direction::FORWARD:
        return "forward";
    default:
        return "";
    }
}

void CCar::SetDirection()
{
    if (m_gear == -1 && m_speed != 0)
    {
        m_direction = Direction::BACK;

        return;
    }

    if (m_gear == 0 && m_direction == Direction::BACK && m_speed != 0)
    {
        m_direction = Direction::BACK;

        return;
    }

    if (m_speed == 0)
    {
        m_direction = Direction::STAND;

        return;
    }

    m_direction = Direction::FORWARD;
}