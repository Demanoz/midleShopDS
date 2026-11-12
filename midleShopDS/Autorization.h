#ifndef _AUTHORIZATION_HPP_
#define _AUTHORIZATION_HPP_

#include "ServiceFunction.h"
#include "Accounts.h"
#include "Storage.h"

void Start();
bool Login();
void SuperAdminMenu();
void AdminMenu();
void UserMenu();

#endif // !_AUTHORIZATION_HPP_