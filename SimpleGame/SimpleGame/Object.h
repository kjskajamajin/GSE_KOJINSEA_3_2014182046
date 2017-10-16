#pragma once

class CObj
{
private:

public:
	INFO	m_tInfo;
	vector<float> vfSpeed;
public:
	CObj();
	~CObj();

public:
	void Update();
	void DrawRect();
};

