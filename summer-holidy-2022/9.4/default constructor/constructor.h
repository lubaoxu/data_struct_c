#pragma once		

// C++���Ĭ�ϳ�Ա����

class constructor
{
private:
	double m_dNumber;
	double m_dSum;
public:
	constructor();		//1.Ĭ�Ϲ��캯��
	~constructor();		//2.Ĭ����������
	constructor(const constructor& other);	//3.Ĭ�Ͽ������캯��
	constructor& operator=(const constructor& other);	//4.Ĭ�ϸ�ֵ����������
	constructor* operator&();	//5.Ĭ��ȡ��ַ����������

};

