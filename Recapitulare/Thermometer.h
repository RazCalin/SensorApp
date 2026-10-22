#pragma once
#include "Senzor.h"

class Thermometer : public Sensor
{
public:
	Thermometer(uint16_t id, Type type, const std::string& timestamp, bool status, float temperature);
	
	bool IsMeasurementValid() const override;

	float GetTemperature()const;

	friend std::ostream& operator<<(std::ostream& out, const Thermometer& t);
private:
	float m_temperature;
private:
	static const float kMinValidValue;
	static const float kMaxValidValue;
};

