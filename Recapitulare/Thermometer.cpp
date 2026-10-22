#include "Thermometer.h"

const float Thermometer::kMaxValidValue = 300;
const float Thermometer::kMinValidValue = 0;

Thermometer::Thermometer(uint16_t id, Type type, const std::string& timestamp, bool status, float temperature) 
	: Sensor(id, type, timestamp, status)
	, m_temperature(temperature)
{
}
