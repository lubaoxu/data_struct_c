#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "hashmap.h"

int main()
{
	// 1.创建HashMap
	HashMap* pHashMap = (HashMap*)malloc(sizeof(HashMap));
	memset(pHashMap->lnArray, 0, sizeof(pHashMap->lnArray));

	// 2.循环插入数据
	Data dataArray[] = { 
		Data(101,(char *)"lbx101"),	Data(102,(char*)"lbx102"),	Data(103,(char*)"lbx102"),	Data(104,(char*)"lbx102"),	Data(105,(char*)"lbx102"), 
		Data(106,(char*)"lbx102"),	Data(107,(char*)"lbx102"),	Data(108,(char*)"lbx102"),	Data(109,(char*)"lbx102"),	Data(110,(char*)"lbx102"),
		Data(111,(char*)"lbx102"),  Data(112,(char*)"lbx102"),  Data(113,(char*)"lbx102"),	Data(114,(char*)"lbx102"),	Data(115,(char*)"lbx102"),
		Data(116,(char*)"lbx102"),	Data(117,(char*)"lbx102"),	Data(118,(char*)"lbx102"),	Data(119,(char*)"lbx102"),	Data(120,(char*)"lbx102"),
		Data(121,(char*)"lbx102"),	Data(122,(char*)"lbx102"),  Data(123,(char*)"lbx102"),  Data(124,(char*)"lbx102"),  Data(125,(char*)"lbx102"),
		Data(126,(char*)"lbx102"),  Data(127,(char*)"lbx102"),  Data(128,(char*)"lbx102"),	Data(129,(char*)"lbx102"),  Data(130,(char*)"lbx102"),
		Data(131,(char*)"lbx131"),  Data(132,(char*)"lbx102"),  Data(133,(char*)"lbx102"),  Data(134,(char*)"lbx102"),  Data(135,(char*)"lbx102"),
		Data(136,(char*)"lbx102"),	Data(137,(char*)"lbx102"),	Data(138,(char*)"lbx102"),	Data(139,(char*)"lbx102"),	Data(140,(char*)"lbx102"),
		Data(141,(char*)"lbx102"),	Data(142,(char*)"lbx102"),	Data(143,(char*)"lbx102"),	Data(144,(char*)"lbx102"),	Data(145,(char*)"lbx102"), 
		Data(146,(char*)"lbx102"),	Data(147,(char*)"lbx102"),	Data(148,(char*)"lbx102"),	Data(149,(char*)"lbx102"),	Data(150,(char*)"lbx102")
	};

	for (int i = 0; i < sizeof(dataArray) / sizeof(dataArray[0]); ++i) {
		insert(pHashMap, &(dataArray[i]));
	}	
	
	// 3.根据 key 查找数据
	Data* pResultData = get(pHashMap, 131);
	if (pResultData != NULL) {
		printf("%s:\n", pResultData->szName);
	}

	// 4. 释放HashMap



	return 0;
}