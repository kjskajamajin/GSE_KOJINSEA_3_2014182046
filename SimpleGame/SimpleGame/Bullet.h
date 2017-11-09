#pragma once
#include "CObj.h"
class Bullet :
	public CObj
{
public:
	Bullet();
	~Bullet();

public:
	void Initiallize();
	int Update();
	void Release();
	

public:
	float	fbx;
	float	fby;
	float	fbsize;
	float	fbspeed;
	bool	bDead;
};

