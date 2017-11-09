#include "stdafx.h"
#include "SceneMgr.h"
#include "Bullet.h"

SceneMgr::SceneMgr(int width, int height)
{
	m_renderer = new Renderer(width, height);

	if (!m_renderer->IsInitialized())
	{
		std::cout << "SceneMgr::Renderer could not be initialized.. \n";
	}

	m_windowWidth = width;
	m_windowHeight = height;
}

void SceneMgr::Render()
{
	//Obj Render
	m_renderer->DrawSolidRect(0.f, 0.f, 0.f, m_windowWidth, 0.f, 0.f, 0.f, 0.4f);

	list<CObj*>::iterator iter_begin = m_pObject.begin();
	list<CObj*>::iterator iter_end = m_pObject.end();

	for (; iter_begin != iter_end; ++iter_begin)
	{
		m_renderer->DrawSolidRect(
			(*iter_begin)->fx,
			(*iter_begin)->fy,
			0,
			(*iter_begin)->fSize,
			(*iter_begin)->fColor[0],
			(*iter_begin)->fColor[1],
			(*iter_begin)->fColor[2],
			(*iter_begin)->fColor[3]
		);
	}
	// Bullet Render
	
}

SceneMgr::~SceneMgr()
{
}

int SceneMgr::AddObj(float x, float y)
{
	CObj *pObject = new CObj(x, y);
	m_pObject.push_back(pObject);

	return 0;
}

void SceneMgr::Update(float felapsedTime)
{
	Collision();

	list<CObj*>::iterator iter_begin = m_pObject.begin();
	list<CObj*>::iterator iter_end = m_pObject.end();

	for (; iter_begin != iter_end; ++iter_begin)
	{
		(*iter_begin)->Update(felapsedTime);
	}
}

void SceneMgr::Collision()
{
	bool Collision = false;

	list<CObj*>::iterator iter_begin_1 = m_pObject.begin();
	list<CObj*>::iterator iter_end_1 = m_pObject.end();

	for (; iter_begin_1 != iter_end_1; ++iter_begin_1)
	{
		Collision = false;
		if ((*iter_begin_1) != NULL)
		{
			list<CObj*>::iterator iter_begin_2 = m_pObject.begin();
			list<CObj*>::iterator iter_end_2 = m_pObject.end();

			for (; iter_begin_2 != iter_end_2; ++iter_begin_2)
			{
				if ((*iter_begin_1) == (*iter_begin_2))
					continue;

				if (*iter_begin_2 != NULL)
				{
					float minX, minY;
					float maxX, maxY;
					float minX1, minY1;
					float maxX1, maxY1;

					minX = (*iter_begin_1)->fx - (*iter_begin_1)->fSize / 2.f;
					minY = (*iter_begin_1)->fy - (*iter_begin_1)->fSize / 2.f;
					maxX = (*iter_begin_1)->fx + (*iter_begin_1)->fSize / 2.f;
					maxY = (*iter_begin_1)->fy + (*iter_begin_1)->fSize / 2.f;
					minX1 = (*iter_begin_2)->fx - (*iter_begin_2)->fSize / 2.f;
					minY1 = (*iter_begin_2)->fy - (*iter_begin_2)->fSize / 2.f;
					maxX1 = (*iter_begin_2)->fx + (*iter_begin_2)->fSize / 2.f;
					maxY1 = (*iter_begin_2)->fy + (*iter_begin_2)->fSize / 2.f;
					if (ObjCollision(minX, minY, maxX, maxY, minX1, minY1, maxX1, maxY1))
					{
						Collision = true;
					}
				}
			}
			if (Collision == true)
			{
				(*iter_begin_1)->fColor[0] = 1;
				(*iter_begin_1)->fColor[1] = 0;
				(*iter_begin_1)->fColor[2] = 0;
				(*iter_begin_1)->fColor[3] = 1;
			}
			else
			{
				(*iter_begin_1)->fColor[0] = 1;
				(*iter_begin_1)->fColor[1] = 1;
				(*iter_begin_1)->fColor[2] = 1;
				(*iter_begin_1)->fColor[3] = 1;
			}
		}
	}
}

bool SceneMgr::ObjCollision(float minX, float minY, float maxX, float maxY, float minX1, float minY1, float maxX1, float maxY1)
{
	if (minX > maxX1)
		return false;
	if (maxX < minX1)
		return false;

	if (minY > maxY1)
		return false;
	if (maxY < minY1)
		return false;

	return true;
}

void SceneMgr::Release()
{
	list<CObj*>::iterator iter_begin = m_pObject.begin();
	list<CObj*>::iterator iter_end = m_pObject.end();
	
	for (iter_begin; iter_begin != iter_end; ++iter_begin)
	{
		delete *iter_begin;
	}
}
