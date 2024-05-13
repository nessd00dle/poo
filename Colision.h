#pragma once

class Colision {
private:
	double cx;
	double cz;
	double crx;
	double crz;
	double cy;
	double cry;

public:
	Colision (double _cx, double _cz,double _cy, double _crx, double _crz,double _cry);
	bool Hitbox(double, double,double);

	double getCX() { return cx;}
	double getCz() { return cz;}
	double getCy(){ return cy; }
	double getCrX() { return crx;}
	double getCrz() { return crz;}
	double getCry() { return cry; }
	

	void setcx(double _cx) {cx=_cx; }
	void setcz(double _cz) {cz=_cz; }
	void setcy(double _cy) { cy = _cy; }
	void setcrx(double _crx) {crx= _crx; }
	void setcrz(double _crz) { crz = _crz; }
	void setcry(double _cry) { cry = _cry; }


};