#pragma once

#include <stdio.h>

class Data
{
public:
	int m_nWeight; // m - > member
	char* m_pBand;

public:
	// construct
	Data();
	Data(int nWeight);
	Data(int nWeight, char* pBand);

	// copy constructor  ¿½±´¹¹Ôìº¯Êý
	Data(const Data & other);

	// destruct
	~Data();
};

