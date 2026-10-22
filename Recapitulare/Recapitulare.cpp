# pragma once
#include <iostream>
#include <vector>
#include "Senzor.h"
#include "SenzorType.h"
#include <fstream>
#include "Thermometer.h"
#include "Accelerometer.h"

/*
You are an engineer processing some sensor data. The sensor data is collected from 2 types of sensors,
a temperature sensor and an accelerometer.
Each sensor reports its own id, type, timestamp of measurement, status and values. The measured
values are:
• temperature by the thermometer (in the [0, 300] range)
• 3-axis acceleration (X, Y, Z axes) by the accelerometer (in the [-10 000, 10 000] range)
Tasks:
1. Read the sensor data from the input file sensors.log into a vector. Use a single class to
represent a sensor measurement.
2. Print only the measurements of the temperature sensors in autumn.
3. Implement comparison functions to sort the data ascending by id or descending by timestamp
and print the sorted vector. Use sorting functions from the standard library. Your code must
contain (either commented or not) at least 3 different ways of implementing/calling comparison
functionality.
Notes:
• id must be stored as a numeric value in class instances
• measurement values must be read into a vector
• no setters allowed (the object is “read-only” or “frozen”)
*/

int main()
{
    std:: vector<Sensor*> sensorData;
    std::ifstream fin("Sensors.log");
    std::string idStr, typeStr, timestampStr, statusStr;
    std::vector<float> values;
    while (!fin.eof())
    {
        fin >> idStr >> typeStr >> timestampStr;
        if (typeStr == "TEMP")
        {
            values.resize(1);
            fin >> values[0];
        }
        else
        {
            values.resize(3);
            fin >> values[0] >> values[1] >> values[2];
        }
        fin >> statusStr;

        uint16_t id = std::stoi(idStr.substr(1));
        Type type = typeStr == "TEMP" ? Type::TEMP : Type::ACCM;
        bool status = statusStr == "OK";
        //sensorData.emplace_back(id, type, timestampStr, status, values);
        if (typeStr == "TEMP")
        {
            //Thermometer* thermometer= new Thermometer(id, type, timestampStr, status, values[0]);
            Sensor* thermometer= new Thermometer(id, type, timestampStr, status, values[0]);
            sensorData.push_back(thermometer);
        }
        else
        {
            Sensor* accelerometer = new Accelerometer(id, type, timestampStr, status, values[0], values[1], values[2]);
            sensorData.push_back(accelerometer);
        }

    }
    std::cout << sensorData[0]->IsMeasurementValid();
}
