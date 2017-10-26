#include "stdafx.h"
#include "Object.h"


Cobj::Cobj()
{
	memset(&m_Position,0,sizeof(m_Position));
	memset(&m_Color, 0, sizeof(m_Color));
	m_Speed.x = 10.0f;
	m_Speed.y = 0.0f;
	m_Speed.z = 0.0f;	
}
Cobj::~Cobj()
{
}
INFO Cobj::GetPosition()
{
	return m_Position;
}
INFO Cobj::GetColor()
{
	return m_Color;
}

void Cobj::Update()
{
	m_Position.x += m_Speed.x;
	m_Position.y += m_Speed.y;
	m_Position.z += m_Speed.z;
}


