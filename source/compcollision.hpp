#ifndef	__COMPCOLLISION_H__
#define	__COMPCOLLISION_H__

#include "hitbox.hpp"

class Comp_BoundBoxCollision
{
public:
	BoundBox		hbox;
};

class Comp_CircleCollision
{
public:
	BoundCircle		hcirc;
};

#endif	//COMPCOLLISION_H
