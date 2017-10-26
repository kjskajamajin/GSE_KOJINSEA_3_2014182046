#pragma once

class Cobj
{
private:
	INFO m_Position;
	INFO m_Color;
	INFO m_Speed;

public:
	Cobj();
	~Cobj();
	
	INFO GetPosition();
	INFO GetColor();

	INFO GetSpeed;
	
	void SetPosition(float x, float y, float z) { m_Position.x = x, m_Position.y = y, m_Position.z = z; }
	void Update();

};