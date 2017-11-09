#pragma once
#include <cstdlib>

class CObj
{
public:
	CObj(float x, float y);
	CObj();
	~CObj();

public:
	float GetLife();
	float GetLifeTime();
	void Update(float felapsedTime);
	void SetPos(float x, float y);
	
public:
	float fx;
	float fy;
	float fSpeedX;
	float fSpeedY;
	float fSize;
	float fColor[4];
	float fLife;
	float fLifeTime;
	//list<CObj*>* m_Bullet;
};

