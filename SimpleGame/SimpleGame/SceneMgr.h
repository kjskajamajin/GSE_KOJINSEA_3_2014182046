#pragma once
#define MAX_OBJ_COUNT

class Object;
class SceneMgr
{
private:
	Object* m_obj[MAX_OBJ_COUNT];

public:
	void Update();
	void Renderer();
	void Release();
	void CollisionTest();
public:
	SceneMgr();
	~SceneMgr();
};

