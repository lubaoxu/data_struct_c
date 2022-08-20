#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "Data.h"



// construct
Data::Data() {
	this->m_nWeight = 0;
	this->m_pBand = NULL;
	std::cout << "Data() " << this << " " << m_nWeight <<  std::endl;
}

Data::Data(int nWeight) {
	this->m_nWeight = nWeight;
	this->m_pBand = NULL;
	std::cout << "Data(int nWeight) " << this << " " << m_nWeight <<std::endl;
}

Data::Data(int nWeight, char* pBand) {
	this->m_nWeight = nWeight;
	this->m_pBand = pBand;
	std::cout << "Data(int nWeight, char* pBand) " << this << " " << m_nWeight << std::endl;
}

// copy constructor  ¿½±´¹¹Ôìº¯Êý
Data::Data(const Data& other) {
	this->m_nWeight = other.m_nWeight;
	if (other.m_pBand != NULL) {
		int length = strlen(other.m_pBand);
		this->m_pBand = (char*)malloc(sizeof(char) * length + 1);
		memset(this->m_pBand, 0, length+1);
		strcpy(this->m_pBand, other.m_pBand);
	}
	std::cout << "Data(const Data& other) " << this << " " << m_nWeight << std::endl;
}


// destruct	
Data::~Data() {
	std::cout << "~Data() " << this << " " << m_nWeight << std::endl; 
	this->m_nWeight = 0;
	this->m_pBand = NULL;
}