#include "Thermometer.h"
#include <format>
const float Thermometer::kMaxValidValue = 300;
const float Thermometer::kMinValidValue = 0;

Thermometer::Thermometer(uint16_t id, Type type, const std::string& timestamp, bool status, float temperature) 
	: Sensor(id, type, timestamp, status)
	, m_temperature(temperature)
{
}

bool Thermometer::IsMeasurementValid() const
{
	return m_temperature >= kMinValidValue && m_temperature <= kMaxValidValue;
}

float Thermometer::GetTemperature() const
{
	return m_temperature;
}

std::ostream& operator<<(std::ostream& out, const Thermometer& t)
{
	return out << std::format(
		"Thermometer: id={}, type={}, timestamp(={}, status={}, temperature={} ",
		t.GetId()  
	);
}
