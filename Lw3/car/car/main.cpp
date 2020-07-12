#include "car.h"
#include <iostream>

enum class ACTION
{
    ERROR,
    INFO,
    TURN_ENGINE_ON,
    TURN_ENGINE_OFF,
    SET_GEAR,
    GET_GEAR,
    SET_SPEED,
    GET_SPEED,
    EXIT,
};

void PrintMenu()
{
    std::cout << "Choose action:" << std::endl
        << "1: Print info" << std::endl
        << "2: Turn engine on" << std::endl
        << "3: Turn engine off" << std::endl
        << "4: Set gear" << std::endl
        << "5: Get gear" << std::endl
        << "6: Set speed" << std::endl
        << "7: Get speed" << std::endl
        << "8: Exit" << std::endl
        << ">";
}

ACTION GetAction()
{
    int actionNum;
    std::cin >> actionNum;

    if (actionNum < 0 || actionNum > 8)
        return ACTION::ERROR;

    return static_cast<ACTION>(actionNum);
}

int main()
{
    CCar simulatedCar;
    std::cout << "Car simulator started" << std::endl
        << "----------" << std::endl;

    PrintMenu();
    ACTION currAction = GetAction();

    while (currAction != ACTION::EXIT)
    {
        std::cout << "----------" << std::endl;

        switch (currAction)
        {
        case ACTION::INFO:
            std::cout << simulatedCar.GetInfo() << std::endl;

            break;
        case ACTION::TURN_ENGINE_ON:
            if (!simulatedCar.TurnOnEngine())
                std::cout << "Can not turn engine on" << std::endl;
            else
                std::cout << "Engine is enabled" << std::endl;

            break;
        case ACTION::TURN_ENGINE_OFF:
            if (!simulatedCar.TurnOffEngine())
                std::cout << "Can not turn engine off" << std::endl;
            else
                std::cout << "Engine is disabled" << std::endl;

            break;
        case ACTION::SET_GEAR:
            std::cout << "Which gear do you want to set? (not less than -1 and more than 5) >";
            Gear gear;
            std::cin >> gear;

            if (!simulatedCar.SetGear(gear))
                std::cout << "Can not set " << gear << " gear" << std::endl;
            else
                std::cout << "Gear " << gear << " was setted" << std::endl;

            break;
        case ACTION::GET_GEAR:
            std::cout << "Current gear is " << simulatedCar.GetGear() << std::endl;

            break;
        case ACTION::SET_SPEED:
            std::cout << "Which speed do you want to set? (not less than 0 and more than 150) >";
            Speed speed;
            std::cin >> speed;

            if (!simulatedCar.SetSpeed(speed))
                std::cout << "Can not set " << speed << " speed" << std::endl;
            else
                std::cout << "Speed " << speed << " was setted" << std::endl;

            break;
        case ACTION::GET_SPEED:
            std::cout << "Current speed is " << simulatedCar.GetSpeed() << std::endl;

            break;
        }

        if (currAction == ACTION::ERROR)
            std::cout << "Wrong action" << std::endl;

        std::cout << "----------" << std::endl;

        PrintMenu();
        currAction = GetAction();
    }

    std::cout << "----------" << std::endl
        << "Car simulator ended" << std::endl;

    return 0;
}