#pragma once
#include "Header.h"

// return -1 if no account exist or password is incorect and index of array if the account exist
int login(string name, string pass, char& type);
// done 

bool add_new_account(string name, string pass, char type);

void modify_an_account();

int close_an_account(string name);

void list_all_accounts();

int balance_in_account(int account_number_in_array);

void withdraw(int account_number_in_array, int amount);

void deposit(int account_number_in_array, int amount);

bool transfer(int account_number_in_array, int amount, string name);

bool Register();