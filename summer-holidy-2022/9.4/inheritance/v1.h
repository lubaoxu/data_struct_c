#pragma once

class V {

public:
	int m_nVal;
	V() {
		m_nVal = 0x12345678;
	}
	virtual ~V() {}
};	

//  –Èƒ‚ºÃ≥–±Ì÷∏’Î  

class VV : virtual public V {
public:
	virtual void func() {}
};