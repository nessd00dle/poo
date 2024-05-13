#include<iostream>
#include "Colision.h"
Colision::Colision(double _cx, double _cz, double _cy, double _crx, double _crz, double _cry) {
	cx = _cx;
	cz = _cz;
	cy = _cy;
	crx = _crx;
	crz = _crz;
	cry = _cry;
	
	

}
bool Colision::Hitbox(double x, double z,double y) {
	if (x > cx - crx && x < cx + crx) {
		if (y > cy - cry && y <cy + cry) {
			if (z > cz - crz && z < cz + crz)
			{
				return true;
			}
		}
	}
	return false;
}
