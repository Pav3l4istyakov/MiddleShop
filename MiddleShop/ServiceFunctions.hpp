#ifndef _SERVICEFUNCTIONS_HPP
#define _SERVICEFUNCTIONS_HPP
#include<Windows.h>
#include<string>
#include<iostream>
#include<iomanip>
#include<cwctype>

void Getline(std::wstring& str);
bool IsNumber(std::wstring& str);
bool IsNotSameName(const std::wstring& chooseName,std::wstring* nameArr, size_t commonSize);
void Err();


template <class ArrType>
void FillArray(ArrType* dynamicArr, ArrType* staticArr, size_t commonSize)
{
	for (size_t i = 0; i < commonSize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}

template <class ArrType>
void ArrPushABack(ArrType* &arr, size_t arrSize)
{
	arrSize++;
	ArrType* temp = new ArrType[arrSize];
	for (size_t i = 0; i < arrSize - 1; i++)
	{
		temp[i] = arr[i];
	}
	std::swap(arr, temp);
	delete[]temp;
}

template <class ArrType>
void ArrDeleteByIndex(ArrType*& arr, size_t arrSize, int index)
{
	ArrSize--;
	ArrType* temp = new ArrType[arrSize];
	for (size_t i = 0, j =0; i < arrSize; i++,j++)
	{
		if (j == index)
		{
			j++;
		}
		temp[i] = arr[j];
	}
	std::swap(temp, arr);
	delete[]temp;

}

#endif // !_SERVICEFUNCTIONS_HPP

