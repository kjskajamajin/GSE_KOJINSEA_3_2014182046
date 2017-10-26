#include "stdafx.h"
#include "Object.h"


CObj::CObj()
{
	memset(&m_Position,0,sizeof(m_Position));
	memset(&m_Color, 0, sizeof(m_Color));
	m_Speed.x = 10.0f;
	m_Speed.y = 0.0f;
	m_Speed.z = 0.0f;	
	Life = 0;
	LifeTime = 0;
}
CObj::~CObj()
{
}
INFO CObj::GetPosition()
{
	return m_Position;
}
INFO CObj::GetColor()
{
	return m_Color;
}

void CObj::Update()
{
	m_Position.x += m_Speed.x;
	m_Position.y += m_Speed.y;
	m_Position.z += m_Speed.z;
}


