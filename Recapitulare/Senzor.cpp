#include "Senzor.h"

Sensor::Sensor(uint16_t id, Type type, const std::string& timestamp, bool status)
	:m_id{ id },
	m_type{type},
	m_timestamp{timestamp},
	m_status{status}
{

}

uint16_t Sensor::GetId() const
{
	return m_id;
}

Type Sensor::GetType() const
{
	return m_type;
}

std::string Sensor::GetTimestamp() const
{
	return m_timestamp;
}

bool Sensor::GetStatus() const
{
	return m_status;
}

