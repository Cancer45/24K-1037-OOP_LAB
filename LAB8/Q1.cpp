#include <iostream>

class Device
{
    protected:
    std::string device_ID, device_type;
    double power_rating;
    bool status;

    public:
    Device () {}
    Device (std::string device_ID, std::string device_type, double power_rating, bool status) : device_ID(device_ID), device_type(device_type), power_rating(power_rating), status(status) {}

    void turnON ()
    {
        if (status)
        {
            std::cout << "DEVICE " << device_ID << "ALREADY ON";
            return;
        }

        status = true;
        std::cout << "DEVICE " << device_ID << "TURNED ON";
    }

    void turnOFF()
    {
        if (!status)
        {
            std::cout << "DEVICE " << device_ID << "ALREADY OFF";
            return;
        }

        status = false;
        std::cout << "DEVICE " << device_ID << "TURNED OFF";
    }

    double calculatePowerUsage (int hours)
    {
        return power_rating * hours;
    }

    std::string getDeviceType ()
    {
        return device_type;
    }

    friend std::ostream& operator<<(std::ostream& output_stream, const Device& device) {
        output_stream << "Device ID: " << device.device_ID << "\n"
           << "Device Type: " << device.device_type << "\n"
           << "Power Rating: " << device.power_rating << "W\n"
           << "Status: " << (device.status ? "ON" : "OFF") << "\n";
        return output_stream;
    }
};

class Light : public Device
{
    public:
    Light () {}
    Light (std::string device_ID, std::string device_type, double power_rating, bool status) : Device(device_ID, device_type, power_rating, status) {}
};

class Fan : public Device
{
    int speed_factor;

    public:
    Fan () {}
    Fan (std::string device_ID, std::string device_type, double power_rating, bool status, int speed_factor) : Device(device_ID, device_type, power_rating, status), speed_factor(speed_factor % 5) {}

    double calculatePowerUsage (int hours)
    {
        return power_rating * hours * speed_factor;
    } 
};

class AC : public Device
{
    int current_temp, desired_temp;

    public:
    AC () {}
    AC (std::string device_ID, std::string device_type, double power_rating, bool status) : Device(device_ID, device_type, power_rating, status), current_temp(current_temp), desired_temp(desired_temp) {}

    void turnON (int intitial_temp)
    {
        if (status)
        {
            std::cout << "AC " << device_ID << "ALREADY ON";
            return;
        }

        status = true;
        desired_temp = (intitial_temp % 15) + 16;
        std::cout << "AC " << device_ID << "TURNED ON";
    }

    double calculatePowerUsage (int hours)
    {
        return power_rating * hours * (1 - (current_temp - desired_temp) / 100);
    }
};

class SecuritySys : public Device
{
    bool camera_status;
    std::string intrusion_alerts, security_logs, system_diagnostics;

    public:
    SecuritySys () {}
    SecuritySys (std::string device_ID, std::string device_type, double power_rating, bool status, int speed_factor, std::string security_logs) : Device(device_ID, device_type, power_rating, status), security_logs(security_logs) {}


    void turnOFF(User user)
    {
        if (!status)
        {
            std::cout << "DEVICE " << device_ID << "ALREADY OFF";
            return;
        }

        status = false;
        std::cout << "DEVICE " << device_ID << "TURNED OFF";
    }

    friend class User;
    friend class maintanenceTool;
};

class MaintanenceTool
{

};

class User
{
    std::string user_ID, user_role;
    int access_lvl; //0 is regular user; 1 is maintanence staff

    public:
    User () {}
    User (std::string user_ID, std::string user_role, int access_lvl) : user_ID(user_ID), user_role(user_role), access_lvl(access_lvl) {}

    void viewAccessibleDevices (Device* all_devices, int num_devices)
    {
        for (int i = 0; i < num_devices; i++)
        {
            if (all_devices[i].getDeviceType() == "SecuritySys")
            {
                if (access_lvl)
                std::cout << all_devices[i];
                continue;
            }

            std::cout << all_devices[i];
        }
    }

    void accessSecurityLogs (SecuritySys& ss)
    {
        if (access_lvl)
        {
            std::cout << "\nSECURITY LOGS" << std::endl << ss.security_logs << std::endl;
        }
    }
};
