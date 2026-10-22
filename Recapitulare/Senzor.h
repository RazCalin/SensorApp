#pragma once
#include <string>
#include "SenzorType.h"
#include <vector>
class Sensor
{
public:
	Sensor(uint16_t id, Type type, const std::string& timestamp, bool status);
	bool IsMeasurementValid();
private:
	uint16_t m_id;
	Type m_type;
	std::string m_timestamp;
	bool m_status;
};

