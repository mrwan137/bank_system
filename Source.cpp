#include "funcctions.h";


int main()
{
	cout << endl << endl;
	cout << "			************************************************************************\n";
	cout << "			*                                                                      *\n";
	cout << "			*       \\    /\\    /  ____  |       ____    ___    /\\    /\\     ____   *\n";
	cout << "			*        \\  /  \\  /  |____  |	   |       |   |  /  \\  /  \\   |____   *\n";
	cout << "			*         \\/    \\/   |____  |____  |____   |___| /    \\/    \\  |____   *\n";
	cout << "			*                                                                      *\n";
	cout << "			************************************************************************\n\n";
start:
	cout << "1. login\n2. register\nchoose your operation\n";
	
	char operation;
	cin >> operation;
		getline(cin, trash);
	if (operation != '1' && operation != '2')
	{
		cout << "enter a valid operation\n\n";
		goto start;
	}
	if (operation == '1')
	{
		cout << "\nEnter the user name\n";
		string name, pass;
		cin >> name;
		cout << "\nEnter the password\n";
		cin >> pass;
		char type;
		int logNum = login(name, pass, type);
		if (logNum == -1)
		{
			cout << "\nthe useer name or password is incorect\n\n";
			goto start;
		}
		else
		{
			cout << "\n\n************************************************************************\n";
			cout << "*                                                                      *\n";
			cout << "*                    you login successfully                            *\n";
			cout << "*                                                                      *\n";
			cout << "************************************************************************\n\n";

			// for admins loged in
			if (type == 'A')
			{
			admin_oper:
				cout << "\n1. Add a New Account\n2. Modify An Account\n3. Close An Account\n4. List All Accounts\n5. log out\n\ncoose your operation\n";
				cin >> operation;
				getline(cin, trash);

				switch (operation)
				{
				case '1':
					cout << "\nenter the name of new account\n";
					cin >> name;
					cout << "\nenter the password of new account\n";
					cin >> pass;
					cout << "\nenter the type of new account\n";
					char ntype;
					cin >> ntype;
					bool isAdd;
					isAdd = add_new_account(name, pass, ntype);
					if (isAdd)
						cout << "\naccount added succisfuly\n";
					else
						cout << "\nthere are account with the same name\n";
					break;
				case '2':
					modify_an_account();
					break;
				case '3':
					cout << "\nenter the name of account you want to close\n";
					cin >> name;
					if (close_an_account(name) == -1)
					{
						cout << "\n---------------------------------------------\n";
						cout << "\n\tthis account does not exist\t" << endl;
						cout << "\n---------------------------------------------\n";
					}
					else
					{
						cout << "\n---------------------------------------------\n";
						cout << "\n\tthe account closed successfully\t" << endl;
						cout << "\n---------------------------------------------\n";
					}
					break;
				case '4':
					list_all_accounts();
					break;
				case '5':
					goto start;
					break;
				default:
					cout << "\nEnter a valid operation\n";
				}
				goto admin_oper;
			}
			// for clints loged in
			else
			{
			clint_oper:
				cout << "\n1. Balance Enquiry\n2. Withdraw Amount\n3. Deposit Amount\n4. Transfer moeny to another account\n5. log out\n\nchoose your operation\n";
				cin >> operation;
				getline(cin, trash);

				int amount, balance;
				switch (operation)
				{
				case '1':
					balance = balance_in_account(logNum);
					cout << "\n---------------------------------------------\n";
					cout << "\n\tYour balance is\t" << balance << endl;
					cout << "\n---------------------------------------------\n";
					break;
				case '2':
					cout << "\nenter the ammount to withdraw\n";
					cin >> amount;
					withdraw(logNum, amount);
					break;
				case '3':
					cout << "\nEnter the ammount to deposit\n";
					cin >> amount;
					deposit(logNum, amount);
					break;
				case '4':
					//while (true)
					{
						cout << "\nEnter the name of account you want to send for\n";
						string name_for_send;
						cin >> name_for_send;
						cout << "\nEnter the ammount to send for " << name_for_send << endl;
						cin >> amount;
						bool isTransfer = transfer(logNum, amount, name_for_send);
						if (isTransfer)
						{
							cout << "\nThe transfer is done succisfuly\n\n";
							goto clint_oper;
						}
						else
							cout << "\nAccount not found or the balnce is less than the transfer amount please retry again\n\n";
						
						goto clint_oper;
					}
					break;
				case '5':
					goto start;
					break;
				default:
					cout << "\nEnter a valid operation\n";
				}
				goto clint_oper;
			}
		}
	}
	else
	{
		bool isRegs = Register();
		if (isRegs)
		{
			cout << "\n\n************************************************************************\n";
			cout << "*                                                                      *\n";
			cout << "*              Your registration done successfully                      *\n";
			cout << "*                                                                      *\n";
			cout << "************************************************************************\n\n";
		}
		else
			{
				cout << "\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
				cout << "x                                                                      x\n";
				cout << "x       There is an account with the same name please try again        x\n";
				cout << "x                                                                      x\n";
				cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n";
			}
	}

	cout << "\n********************************************************************\n\n";
	goto start;
}