#pragma once
#include "Senzor.h"
class Accelerometer: public Sensor
{
public:
	Accelerometer(uint16_t id, Type type, const std::string& timestamp, bool status, float xAcceleration, float yAcceleration, float zAcceleration);
private:
	float m_xAcceleration;
	float m_yAcceleration;
	float m_zAcceleration;

private:
	static const float kMinValidValue;
	static const float kMaxValidValue;
};

