#include "Define.h"
#include "Enum.h"
#define MAX_OBJECTS_COUNT 50

class CObject
{
public:
	void Init(TeamType teamType, ObjectType objType, Pos pos, float size, Color color, float level);
	void Update(float time);
	ObjectType GetObjType();
	Pos GetPos();
	float GetSize();
	Color GetColor();
	float GetLife();
	float GetLifeTime();
	float GetTime();
	TeamType GetTeamType();
	vector<CObject*> GetBullet();
	vector<CObject*> GetArrow();
	float GetLevel();
	void Move();
	void CreateBullet();
	void CreateArrow();
	bool CheckCollision(CObject* other);

public:
	void SetPos(const Pos pos) { m_pos = pos; }
	int GetCol() { return m_col; }
	int GetRow() { return m_row; }
	void SetSize(float size) { m_size = size; }
	void SetColor(Color color) { m_color = color; }
	void GetDamage(float damage) { m_life -= damage; }
	void Die() { m_life = 0.0f; }

protected:
	Pos m_pos;
	Pos m_vPos;
	float m_size;
	Color m_color;
	float m_life, m_lifeTime;
	float m_time;
	float m_level;
	ObjectType m_objType;
	DWORD m_bulletCreateTime;
	DWORD m_arrowCreateTime;
	TeamType m_teamType;
	vector<CObject*> m_bullet;
	vector<CObject*> m_arrow;
	int m_col, m_row;
};