#include "util.h"


std::string GBKToUTF8(std::string& strGBK)
{
	std::string strOutUTF8 = "";
	WCHAR * str1;
	int n = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, NULL, 0);
	str1 = new WCHAR[n];
	MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, str1, n);
	n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL);
	char * str2 = new char[n];
	WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, NULL, NULL);
	strOutUTF8 = str2;
	delete[]str1;
	str1 = NULL;
	delete[]str2;
	str2 = NULL;
	return strOutUTF8;
}

std::string UTF8ToGBK(const std::string& strUTF8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8.c_str(), -1, NULL, 0);
	unsigned short * wszGBK = new unsigned short[len + 1];
	memset(wszGBK, 0, len * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, (LPCTSTR)strUTF8.c_str(), -1, LPWSTR(wszGBK), len);

	len = WideCharToMultiByte(CP_ACP, 0, LPWSTR(wszGBK), -1, NULL, 0, NULL, NULL);
	char *szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, LPWSTR(wszGBK), -1, szGBK, len, NULL, NULL);
	//strUTF8 = szGBK;     
	std::string strTemp(szGBK);
	delete[]szGBK;
	delete[]wszGBK;
	return strTemp;
}


int Rand_int(int nMin, int nMax)
{

	if (nMin == nMax)
	{
		return nMin;
	}

	if (nMax < nMin)
	{
		int nTemp = nMin;
		nMin = nMax;
		nMax = nTemp;
	}

	static double g_fRandMax1 = 1.0 / (double)(((int64_t)RAND_MAX) + 1LL);

	int xRand = rand();
	return (nMin + int(((double)xRand*g_fRandMax1)*(nMax - nMin + 1)));
}

int Rand_int_mirror(int nMin, int nMax)
{
	int nVal = Rand_int(nMin, nMax);
	if (nMin >= 0 && nMax >= 0)
	{
		if (Rand_int(1, 100) <= 50)
		{
			return 0 - nVal;
		}
	}
	else if (nMin<0 && nMax<0)
	{
		if (Rand_int(1, 100) <= 50)
		{
			return 0 - nVal;
		}
	}
	return nVal;
}
