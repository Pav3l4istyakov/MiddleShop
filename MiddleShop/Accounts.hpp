#ifndef _ACCOUNTS_HPP
#define _ACCOUNTS_HPP
#include "ServiceFunctions.hpp"
extern std::wstring* loginArr;
extern std::wstring* passArr;
extern std::wstring* statusArr;
extern unsigned int* userIdArr;
extern double* fineArr;
extern double* awardArr;
 
extern size_t userSize;
extern size_t currentId;
extern std::wstring currentStatus;

extern size_t maxLogin;
extern size_t minLogin;
extern size_t maxPass;
extern size_t minPass;

extern bool isSetCreated;

extern std::unordered_set<wchar_t> loginSymbols;
extern std::unordered_set<wchar_t> PassSymbols;

void ChangeAccounts();
void CreateNewAccount();

void CreateSet();
bool CheckLogin(const std::wstring& login);
bool CheckPass(const std::wstring& pass);
            

#endif // !_ACCOUNTS_HPP
