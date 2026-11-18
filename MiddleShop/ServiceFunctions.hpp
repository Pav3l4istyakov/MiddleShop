#ifndef _SERVICEFUNCTIONS_HPP
#define _SERVICEFUNCTIONS_HPP
#include<Windows.h>
#include<string>
#include<iostream>
#include<iomanip>

void Getline(std::wstring& str);
bool IsNumber(std::wstring& str);
bool IsNotSameName(const std::wstring& chooseName,std::wstring* nameArr, size_t commonSize);
__forceinline void Err();


template <class ArrType>
void FillArray(ArrType* dynamicArr, ArrType* staticArr, size_t commonSize)
{
	for (size_t i = 0; i < commonSize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}

#endif // !_SERVICEFUNCTIONS_HPP

