#include "stdafx.h"
#include "Object.h"
#include "Renderer.h"

CObj::CObj()
{
	m_tInfo.a = 0;
	m_tInfo.b = 0;
	m_tInfo.r = 0;
	m_tInfo.g = 0;
	m_tInfo.size = 10;
	m_tInfo.x = 0;
	m_tInfo.y = 0;
	m_tInfo.z = 0;
	
}


CObj::~CObj()
{

}

void CObj::Update()
{
	m_tInfo.x = m_tInfo.x  * 10;
	m_tInfo.y = m_tInfo.y * 10;
	m_tInfo.z = m_tInfo.z * 10;

}