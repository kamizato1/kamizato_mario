#pragma once
#include"define.h"


class BoxCollider
{
protected:

	DATA location;
	DATA size;

public:

	bool HitBox(BoxCollider* bc);

	DATA GetLocation(void)const;
	DATA GetSize(void)const;
};

