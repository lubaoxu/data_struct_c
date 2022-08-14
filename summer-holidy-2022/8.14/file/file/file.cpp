#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	FILE* pFileToWrite = fopen("lbx.txt", "w");
	char szData[] = "lbx \nHello world";
	fwrite(szData, sizeof(szData), 1, pFileToWrite);
	fclose(pFileToWrite);


	FILE* pFileToRead = fopen("lbx.txt", "r");
	char szDataRead[100] = {0};
	fread(szDataRead, sizeof(szDataRead), 1, pFileToWrite);
	printf("result\n%s\n", szData);
	fclose(pFileToWrite);


	return 0;
}