#include "stdafx.h"
#include "CObj.h"
#include <math.h>
#include "Bullet.h"

CObj::CObj()
{

}

CObj::CObj(float x, float y)
{
	fx = x;
	fy = y;
	fSpeedX = 200.f;
	fSpeedY = 200.f;
	fSize = 20;
	fColor[0] = 1;
	fColor[1] = 1;
	fColor[2] = 1;
	fColor[3] = 1;
	fLife = 10.f;
	fLifeTime = 100000.f;
}

CObj::~CObj()
{

}

void CObj::Update(float felapsedTime)
{
	float elapsedTimes = felapsedTime / 1000.f;

	fx = fx + fSpeedX * elapsedTimes;
	fy = fy + fSpeedY * elapsedTimes;

	if (fx > 250) 
	{
		fSpeedX -= 1.f;
	}
	if (fy > 250)
	{
		fSpeedY -= 1.f;
	}
	if (fx < -250)
	{
		fSpeedX += 1.f;
	}
	if (fy < -250)
	{
		fSpeedY += 1.f;
	}

	/*if (fLife > 0.f)
	{
		fLife -= 0.5f;
	}

	if (fLifeTime > 0.f)
	{
		fLifeTime -= elapsedTimes;
	}*/
}

float CObj::GetLife()
{
	return fLife;
}

float CObj::GetLifeTime()
{
	return fLifeTime;
}

void CObj::SetPos(float x, float y)
{
	fx = x;
	fy = y;
}
