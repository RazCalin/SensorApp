#pragma once
#include <string>
#include "SenzorType.h"
#include <vector>
class Sensor
{
public:
	Sensor(uint16_t id, Type type, const std::string& timestamp, bool status);
	virtual bool IsMeasurementValid() const = 0;

	uint16_t GetId()const;
	Type GetType()const;
	std::string GetTimestamp()const;
	bool GetStatus()const;
private:
	uint16_t m_id;
	Type m_type;
	std::string m_timestamp;
	bool m_status;
};

