#pragma once
class B
{
public:
	int m_nVal;
public:
	B() 
	{	m_nVal = 0x12345678;
	}
};


class C : virtual public B {

};


class D : virtual public B {

};


class CD : public C, public D {

};

class X :  public B {

};

class Y : public B {

};

class XY: public X, public Y {

};

class CDXY : public C, public D, public X, public Y {

};

