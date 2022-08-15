#pragma once

struct Data {
	int nNumber;
	char szName[100];

	Data(int nVal, char szVal[]) {
		this->nNumber = nVal;
		memset(szName, 0, sizeof(szName));
		strcpy_s(szName, szVal);
	}

};