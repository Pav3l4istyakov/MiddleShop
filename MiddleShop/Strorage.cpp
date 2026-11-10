#include "Strorage.hpp"


size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countAr = nullptr;
double* priceArr = nullptr;

void CreateStorage(int mode)
{
	const size_t static staticSize = 10;
	size_t idArrStatic[staticSize]{ 1,2,4,5,6,7,8,9,10 };
	std::wstring nameArrStatic[staticSize]
	{
	  L"Michael Jackson - Triller", L"Mettalica - Ride The Lighting", L"Rammstein - Rosenrot", L"The Prodigy - Experience"
	  
	};
	size_t countArrStatic[staticSize];
	double priceArrStatic[staticSize];

}
