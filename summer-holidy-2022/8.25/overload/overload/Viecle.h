#pragma once
class Viecle
{
public:
	 virtual void run();  //  重载

	 int m_i;  // sizeof 字节对齐     可否让程序不对齐那？  
	 int m_j;
	 int m_k;
	 int m_l;
	 char m_m;
	 int m_n;
};

