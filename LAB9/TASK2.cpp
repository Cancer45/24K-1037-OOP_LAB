#include <iostream>

class SmartDevice
{
    public:
    virtual void turnOn () = 0;
    virtual void turnOff () = 0;
    virtual void getStatus () = 0;
};

class LightBulb : public SmartDevice
{
    bool isOn;
    int brightness;

    public:
    LightBulb (bool isOn = false, int brightness = 0) : isOn(isOn), brightness(brightness) {}

    void turnOn () override
    {
        if (isOn)
        {
            std::cout << "LIGHT ALREADY ON\n";
            return;
        }

        isOn = true;
        std::cout << "LIGHT TURNED ON\n";
    }

    void turnOff () override
    {
        if (!isOn)
        {
            std::cout << "LIGHT ALREADY OFF\n";
            return;
        }

        isOn = false;
        std::cout << "LIGHT TURNED OFF\n";
    }

    void getStatus () override
    {
        std::cout << "LIGHT: ";
        if (isOn)
        std::cout << "ON\n";

        else
        std::cout << "OFF\n";

        std::cout << "BRIGHTNESS: " << brightness;
    }
};

class Thermostat : public SmartDevice
{
     bool isOn;
    double temperature;

    public:
    Thermostat (bool isOn = false, double temperature = 25 /* room temp in Celsius*/) : isOn(isOn), temperature(temperature) {}

    void turnOn () override
    {
        if (isOn)
        {
            std::cout << "THERMOSTAT ALREADY ON\n";
            return;
        }

        isOn = true;
        std::cout << "THERMOSTAT TURNED ON\n";
    }

    void turnOff () override
    {
        if (!isOn)
        {
            std::cout << "THERMOSTAT ALREADY OFF\n";
            return;
        }

        isOn = false;
        std::cout << "THERMOSTAT TURNED OFF\n";
    }

    void getStatus () override
    {
        std::cout << "THERMOSTAT: ";
        if (isOn)
        std::cout << "ON\n";

        else
        std::cout << "OFF\n";

        std::cout << "TEMPERATURE: " << temperature;
    }
};

int main ()
{
    SmartDevice* sdptr;

    LightBulb obj1(1, 75);
    Thermostat obj2;

    sdptr = &obj1;
    
    sdptr -> getStatus();
    sdptr -> turnOn();
    sdptr -> turnOff();

    sdptr = &obj2;

    sdptr -> getStatus();
    sdptr -> turnOff();
    sdptr -> turnOn();
}