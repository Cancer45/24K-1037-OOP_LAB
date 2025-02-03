#include <iostream>

using namespace std;

class Smartphone
{
    string model, company, resolution;
    int RAM, ROM, storage;

    public:
    //getters
    string getModel ()
    {
        return model;
    }

    string getCompany ()
    {
        return company;
    }

    string getResolution ()
    {
        return resolution;
    }

    int getRAM ()
    {
        return RAM;
    }

    int getROM ()
    {
        return ROM;
    }

    int getStorage ()
    {
        return storage;
    }

    //setters
    void setStorage (int strg)
    {
        storage = strg;
    }

    void setRAM (int ram)
    {
        RAM = ram;
    }

    void setROM (int rom)
    {
        ROM = rom;
    }

    void setCompany (string cmp)
    {
        company = cmp;
    }

    void setModel (string mdl)
    {
        model = mdl;
    }

    void setResolution (string res)
    {
        resolution = res;
    }

    //methods
    void callPhone ()
    {
        cout << "Calling Phone..." << endl;
    }

    void connectWIFI ()
    {
        cout << "Connecting to WIFI..." << endl;
    }

    void sendMsg ()
    {
        cout << "Sending Message..." << endl;
    }

    void browse ()
    {
        cout << "Browsing the Internet..." << endl;
    }
};

int main() 
{

    Smartphone phone1, phone2;

    
    phone1.setModel("Galaxy S21");
    phone1.setCompany("Samsung");
    phone1.setResolution("1080x2400");
    phone1.setRAM(8);
    phone1.setROM(128);
    phone1.setStorage(256);

    
    phone2.setModel("iPhone 13");
    phone2.setCompany("Apple");
    phone2.setResolution("1170x2532");
    phone2.setRAM(6);
    phone2.setROM(128);
    phone2.setStorage(512);

    
    cout << "Phone 1: " << phone1.getModel() << " (" << phone1.getCompany() << ")" << endl;
    phone1.callPhone();
    phone1.connectWIFI();
    phone1.sendMsg();
    phone1.browse();
    
    cout << endl;

    
    cout << "Phone 2: " << phone2.getModel() << " (" << phone2.getCompany() << ")" << endl;
    phone2.callPhone();
    phone2.connectWIFI();
    phone2.sendMsg();
    phone2.browse();

    return 0;
}
