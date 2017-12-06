#include "stdafx.h"
#include "Define.h"

void CObject::Init(TeamType teamType, ObjectType objType, Pos pos, float size, Color color, float level)
{
	m_teamType = teamType;
	m_objType = objType;
	m_pos = pos;
	m_size = size;
	m_color = color;
	m_lifeTime = LIFE_TIME;
	m_level = level;
	float speed = BULLET_SPEED;

	switch (m_objType)
	{
		case OBJECT_BUILDING:
			speed = BUILDING_SPEED;
			m_life = BUILDING_LIFE;
			m_bulletCreateTime = GetTickCount();
			break;
		case OBJECT_CHARACTER:
			speed = CHARACTER_SPEED;
			m_life = CHARACTER_LIFE;
			m_arrowCreateTime = GetTickCount();
			break;
		case OBJECT_BULLET:
			speed = BULLET_SPEED;
			m_life = BULLET_LIFE;
			break;
		case OBJECT_ARROW:
			speed = ARROW_SPEED;
			m_life = ARROW_LIFE;
			break;
		default:
			break;
	}

	switch (rand() % 2) 
	{
		/*case 0:
			m_vPos.x = speed; m_col = 0; m_row = 2;  break;
		case 1:
			m_vPos.x = -speed; m_col = 0; m_row = 1; break;*/
		case 0:
			m_vPos.y = speed; m_col = 0; m_row = 1; break;
		case 1:
			m_vPos.y = -speed; m_col = 0; m_row = 0; break;
	//	//	case 4: m_vPos.x = speed; m_vPos.y = speed; break;
		//	case 5: m_vPos.x = speed; m_vPos.y = -speed; break;
		//	case 6: m_vPos.x = -speed; m_vPos.y = speed; break;
		//	case 7: m_vPos.x = -speed; m_vPos.y = -speed; break;

	}
}

bool CObject::CheckCollision(CObject* other)
{
	if (((m_pos.x + (m_size / 2)) > (other->GetPos().x - ((other->GetSize() / 2)))) && // Right 
		((m_pos.x - (m_size / 2)) < (other->GetPos().x + (other->GetSize() / 2))) && // Left 
		((m_pos.y + (m_size / 2)) > (other->GetPos().y - (other->GetSize() / 2))) && // Top 
		((m_pos.y - (m_size / 2)) < (other->GetPos().y + (other->GetSize() / 2)))) // Bottom 
	{ 
		if (m_objType == OBJECT_CHARACTER && other->GetObjType() == OBJECT_BUILDING) 
		{
			other->GetDamage(m_life);
			this->Die();
		}

		if (m_objType == OBJECT_BUILDING && other->GetObjType() == OBJECT_CHARACTER) 
		{
			this->GetDamage(other->GetLife());
			other->Die();
		}

		if (m_objType == OBJECT_BUILDING && other->GetObjType() == OBJECT_ARROW) 
		{
			this->GetDamage(other->GetLife());
			other->Die();
		}

		if (m_objType == OBJECT_BUILDING && other->GetObjType() == OBJECT_BULLET) 
		{
			this->GetDamage(other->GetLife());
			other->Die();
		}


		if (m_objType == OBJECT_BULLET && other->GetObjType() == OBJECT_CHARACTER) 
		{
			other->GetDamage(m_life);
			this->Die();
		}
		if (m_objType == OBJECT_CHARACTER && other->GetObjType() == OBJECT_BULLET) 
		{
			this->GetDamage(other->GetLife());
			other->Die();
		}

		if (m_objType == OBJECT_CHARACTER && other->GetObjType() == OBJECT_ARROW) 
		{

			this->GetDamage(other->GetLife());
			other->Die();
		}

		return true;
	}

	return false;
}
void CObject::Move()
{
	if ((m_pos.x + (m_size / 2) > WINDOW_WIDTH / 2) || // End of Right 
		((m_pos.x - (m_size / 2) < WINDOW_WIDTH / 2.0 * -1.0f))) // End of Left 
	{
		m_vPos.x = -m_vPos.x;
		if (m_vPos.x > 0) m_row = 2;
		else m_row = 1;
	}

	if ((m_pos.y + (m_size / 2) > WINDOW_HEIGHT / 2) || // End of Top 
		((m_pos.y - (m_size / 2) < WINDOW_HEIGHT / 2.0 * -1.0f))) // End of Bottom 
	{
		m_vPos.y = -m_vPos.y;
		if (m_vPos.y > 0) m_row = 3;
		else m_row = 0;
	}
	m_pos.x = m_pos.x + m_vPos.x * m_time;
	m_pos.y = m_pos.y + m_vPos.y * m_time;
	m_pos.z = m_pos.z + m_vPos.z * m_time;
	m_col = (m_col + 1) % 4;
}

void CObject::CreateBullet()
{
	CObject* cobj = new CObject();

	if (m_teamType == TEAM_RED) 
		cobj->Init(TEAM_RED, OBJECT_BULLET, m_pos, BULLET_SIZE, m_color, LEVEL_UNDERGROUND);
	else 
		cobj->Init(TEAM_BLUE, OBJECT_BULLET, m_pos, BULLET_SIZE, m_color, LEVEL_UNDERGROUND);

	m_bullet.emplace_back(cobj);
}
void CObject::CreateArrow()
{
	CObject* obj = new CObject();
	if (m_teamType == TEAM_RED) 
		obj->Init(m_teamType, OBJECT_ARROW, m_pos, ARROW_SIZE, Color(0.5f, 0.2f, 0.7f, 1.0f), LEVEL_UNDERGROUND);
	else 
		obj->Init(m_teamType, OBJECT_ARROW, m_pos, ARROW_SIZE, Color(1.0f, 1.0f, 0.0f, 1.0f), LEVEL_UNDERGROUND);

	m_arrow.emplace_back(obj);
}

void CObject::Update(float time)
{
	m_time = time / 1000.0f;
	this->Move();
	//ºôµù
	if (m_objType == OBJECT_BUILDING) 
	{
		if (m_bulletCreateTime + BULLET_CREATE_TIME < GetTickCount()) 
		{
			m_bulletCreateTime = GetTickCount();
			this->CreateBullet();
		}

		for (auto& Building : m_bullet) 
			Building->Update(m_time * 1000.0f);

		vector<CObject*>::iterator iter = m_bullet.begin();
		while (iter != m_bullet.end())
		{
			if ((*iter)->GetLife() <= 0 || (*iter)->GetLifeTime() <= 0) iter = m_bullet.erase(iter);
			else ++iter;
		}
	}

	//Ä³¸¯ÅÍ
	if (m_objType == OBJECT_CHARACTER) 
	{
		if (m_arrowCreateTime + ARROW_CREATE_TIME < GetTickCount()) 
		{
			m_arrowCreateTime = GetTickCount();
			this->CreateArrow();
		}
		for (auto& Character : m_arrow) 
			Character->Update(m_time * 1000.0f);

		vector<CObject*>::iterator iter = m_arrow.begin();

		while (iter != m_arrow.end()) 
		{
			if ((*iter)->GetLife() <= 0 || (*iter)->GetLifeTime() <= 0) iter = m_arrow.erase(iter);
			else ++iter;

		}
	}

	//m_lifeTime -= time;
}

ObjectType CObject::GetObjType()
{
	return m_objType;
}
Pos CObject::GetPos()
{
	return m_pos;
}
float CObject::GetSize()
{
	return m_size;
}
Color CObject::GetColor()
{
	return m_color;
}
float CObject::GetLife()
{
	return m_life;
}
float CObject::GetLifeTime()
{
	return m_lifeTime;
}
float CObject::GetTime()
{
	return m_time;
}
TeamType CObject::GetTeamType()
{
	return m_teamType;
}
vector<CObject*> CObject::GetBullet()
{
	return m_bullet;
}
vector<CObject*> CObject::GetArrow()
{
	return m_arrow;
}
float CObject::GetLevel()
{
	return m_level;
}