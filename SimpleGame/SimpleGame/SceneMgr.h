#pragma once
#include <cstdlib>
#include <iostream>

#include "Renderer.h"
#include "CObj.h"

#define OBJECT_BUILDING
#define OBJECT_CHARACTER
#define OBJECT_BULLET
#define OBJECT_ARROW


class SceneMgr
{
public:
	SceneMgr(int width, int height);
	~SceneMgr();

public:
	int		AddObj(float x, float y );
	void	Update(float felapsedTime);
	void	Render();
	void	Release();

private:
	bool ObjCollision(float minX, float minY, float maxX, float maxY, float minX1, float minY1, float maxX1, float maxY1);
	void Collision();
	list<CObj*> m_pObject;
	list<CObj*>* m_Bullet;
	Renderer *m_renderer;
	int m_windowWidth;
	int m_windowHeight;
};

