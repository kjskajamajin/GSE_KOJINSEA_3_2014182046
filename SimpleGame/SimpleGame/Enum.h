#pragma once


enum ObjectType
{
	OBJECT_BUILDING,
	OBJECT_CHARACTER,
	OBJECT_BULLET,
	OBJECT_ARROW
};

enum TeamType
{
	TEAM_RED,
	TEAM_BLUE
};

struct Pos
{
	float x, y, z;
	Pos() {};
	Pos(float fX, float fY, float fZ)
	{
		x = fX;
		y = fY;
		z = fZ;
	}
};

struct Color
{
	float r, g, b, a;
	Color() {};
	Color(float fR, float fG, float fB, float fA)
	{
		r = fR;
		g = fG;
		b = fB;
		a = fA;
	}
};
