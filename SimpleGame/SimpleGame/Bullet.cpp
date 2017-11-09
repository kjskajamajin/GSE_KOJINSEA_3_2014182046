#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::~Bullet()
{
	Release();
}

int Bullet::Update()
{
	if (bDead == true)
		return 1;

	return 0;
}

void Bullet::Initiallize()
{
	fbx = 0;
	fby = 0;
	fbsize = 10;
	fbspeed = 300;
	bDead = false;
}

void Bullet::Release()
{

}