#include "Authorization.hpp"
#include<fcntl.h>
#include<io.h>






int main()
{
	_setmode(_fileno(stdin),_O_U16TEXT);
	_setmode(_fileno(stdout),_O_U16TEXT);
	Start();

	
	delete[]loginArr;
	delete[]passArr;
	delete[]statusArr;
	delete[]userIdArr;



	if (isStorageCreated)
	{
		delete[]idArr;
		delete[]nameArr;
		delete[]countArr;
		delete[]priceArr;
	}

	return 0;
}