#include "Senzor.h"

Sensor::Sensor(uint16_t id, Type type, const std::string& timestamp, bool status)
	:m_id{ id },
	m_type{type},
	m_timestamp{timestamp},
	m_status{status}
{

}

bool Sensor::IsMeasurementValid()
{
	/*if (m_type == Type::TEMP)
		return m_values[0] <= 300 && m_values[0] >= 0;
	return m_values[0] <= 10000 && m_values[0] >= -10000 &&
		m_values[1] <= 10000 && m_values[1] >= -10000 &&
		m_values[2] <= 10000 && m_values[2] >= -10000;*/
	return false;
}
