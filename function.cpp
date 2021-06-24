#include "funcctions.h"

// hamo
int balance_in_account(int account_number_in_array)
{
    // start of any function
    file.open("data.txt");
    cust.clear();
    while (file >> in.name)
    {
        file >> in.pass >> in.type >> in.balanc;
        cust.push_back(in);
    }
    file.close();
    // end of start
    return cust[account_number_in_array].balanc;
}

void withdraw(int account_number_in_array, int amount)
{
    // start of any function
    file.open("data.txt");
    cust.clear();
    while (file >> in.name)
    {
        file >> in.pass >> in.type >> in.balanc;
        cust.push_back(in);
    }
    file.clear();
    file.close();
    // end of start

     // prossesor
    bool done = true;
    if (cust[account_number_in_array].balanc >= amount)
        cust[account_number_in_array].balanc -= amount;
    else
    {
        done = false;
        cout << "\nYou do not have enought money in you account for this transaction!\n";
    }



    // end of prossesor

    // end of any function
    file.open("data.txt");
    for (int i = 0; i < cust.size(); i++)
    {
        file << cust[i].name << ' ' << cust[i].pass << ' ' << cust[i].type << ' ' << cust[i].balanc << endl;
    }
    file.close();
    // end of end any function

    if(done)
        cout << "\n***********All is done succisfuly***********\n\n";

}

void deposit(int account_number_in_array, int amount)
{
    // start of any function
    file.open("data.txt");
    cust.clear();
    while (file >> in.name)
    {
        file >> in.pass >> in.type >> in.balanc;
        cust.push_back(in);
    }
    file.clear();
    file.close();
    // end of start

     // prossesor

    cust[account_number_in_array].balanc += amount;

    // end of prossesor

    // end of any function
    file.open("data.txt");
    for (int i = 0; i < cust.size(); i++)
    {
        file << cust[i].name << ' ' << cust[i].pass << ' ' << cust[i].type << ' ' << cust[i].balanc << endl;
    }
    file.close();
    // end of end any function

    cout << "\n***********All is done succisfuly***********\n\n";
}
//////////////////////////////////

// ammar

int login(string name, string pass, char& type)
{
    // start of any function
    file.open("data.txt");
    cust.clear();
    while (file >> in.name)
    {
        file >> in.pass >> in.type >> in.balanc;
        cust.push_back(in);
    }
    file.close();
    // end of start

    // prossesor
    for (int i = 0; i < cust.size(); i++)
    {
        if (cust[i].name == name && cust[i].pass == pass)
        {
            type = cust[i].type;
            return i;
        }
    }
    return -1;
    // end of prossesor
}

void list_all_accounts() 
{

    // start of any function
    file.open("data.txt");
    cust.clear();
    while (file >> in.name)
    {
        file >> in.pass >> in.type >> in.balanc;
        cust.push_back(in);
    }
    file.close();
    // end of start
    cout << "\n\n" << "      ~" << "*Name*" << "\t      ~" << "*Pass*" << "\t      ~" << "*Type*" << "\t      ~" << "*Balanc*" << "\n\n";

    for (int i = 0; i < cust.size(); i++)
    {
        cout << "\t" << cust[i].name << "\t|\t" << cust[i].pass << "\t|\t " <<
            cust[i].type << "\t|\t " << cust[i].balanc << endl;
    }
    cout << endl;

    // end of prossesor 
}

bool transfer(int account_number_in_array, int amount, string name)
{
    bool found = false;
    // start of any function
    file.open("data.txt");
    cust.clear();
    while (file >> in.name)
    {
        file >> in.pass >> in.type >> in.balanc;
        cust.push_back(in);
    }
    file.clear();
    file.close();
    // end of start

     // prossesor

    if (cust[account_number_in_array].balanc >= amount && amount >= 0)
    {
        cust[account_number_in_array].balanc -= amount;
        for (int i = 0; i < cust.size(); i++)
        {
            if (cust[i].name == name)
            {
                cust[i].balanc += amount;
                found = true;
            }
        }
    }


    // end of prossesor

    // end of any function
    file.open("data.txt");
    for (int i = 0; i < cust.size(); i++)
    {
        file << cust[i].name << ' ' << cust[i].pass << ' ' << cust[i].type << ' ' << cust[i].balanc << endl;
    }
    file.close();
    // end of end any function
    return found;
}

//////////////////////////////////


// adidas
bool Register()
{
    file.open("data.txt");
    cust.clear();
    while (file >> in.name)
    {

        file >> in.pass >> in.type >> in.balanc;
        cust.push_back(in);
    }
    file.close();

    cout << "Enter your name: ";
    cin >> in.name;
    cout << "Enter your pass: ";
    cin >> in.pass;
    cout << "Enter your type (c/a) : ";
    char inp;
    cin >> inp;
    in.type = toupper(inp);
    
    in.balanc = 0;

    for (int i = 0; i < cust.size(); i++)
    {
        if (cust[i].name == in.name)
        {
            return false;
        }
    }
    file.open("data.txt");

    cust.push_back(in);
    for (int i = 0; i < cust.size(); i++)
    {
        file << cust[i].name << " " << cust[i].pass << " " << cust[i].type << " " << cust[i].balanc << "\n";
    }
    file.close();
    return true;

}

bool add_new_account(string name, string pass, char type)
{
    file.open("data.txt");
    cust.clear();
    while (file >> in.name)
    {

        file >> in.pass >> in.type >> in.balanc;
        cust.push_back(in);
    }
    file.close();

    in.name = name;
    in.pass = pass;
    in.type = toupper(type);
    in.balanc = 0;

    for (int i = 0; i < cust.size(); i++)
    {
        if (cust[i].name == in.name)
        {
            return false;
        }
    }
    file.open("data.txt");

    cust.push_back(in);
    for (int i = 0; i < cust.size(); i++)
    {
        file << cust[i].name << " " << cust[i].pass << " " << cust[i].type << " " << cust[i].balanc << "\n";
    }
    file.close();
    return true;
}
//////////////////////////////////


// omar fayez
void modify_user_name(string name, int check);
void modify_password(string name, int check);
void modify_balance(string name, int check);

void modify_an_account() {

    file.open("data.txt");
    cust.clear();
    while (file >> in.name)
    {
        file >> in.pass >> in.type >> in.balanc;
        cust.push_back(in);
    }
    file.clear();
    file.close();

check_3:
    cout << "Enter the account name that you want to modify\n";
    string name;
    cin >> name;


    bool exist = false;
    int check{};
    for (int i = 0; i < cust.size(); i++)
    {
        if (cust[i].name == name)
        {
            exist = true;
            check = i;
        }
    }
    if (!exist)
    {
        cout << "-------------------------------------------\n";
        cout << "  Wrong... please enter a right username\n";
        cout << "-------------------------------------------\n";

        goto check_3;
    }
    else
    {
        if (cust[check].type == 'C')
        {
            cout << "---------------------------------------------\n";
            cout << "      this account is  a clint account \n";
            cout << "---------------------------------------------\n";

            char selection{};
            do {
                cout << "\toptions\n";
                cout << "1- modify user name\n";
                cout << "2- modify password \n";
                cout << "3- modify balance \n";

            check:
                cout << "\nchoose your operation: ";
                char choose{};
                cin >> choose;
                getline(cin, trash);


                switch (choose)
                {
                case '1':
                    modify_user_name(name, check);
                    break;
                case '2':
                    modify_password(name, check);
                    break;
                case '3':
                    modify_balance(name, check);
                    break;
                default:cout << "Invalid choice \n";
                    goto check;
                    break;
                }
                cout << "DO you want more operations  (Y\\N) \n";
                cin >> selection;
            } while (selection != 'N' && selection != 'n');

        }
        else
        {
            cout << "---------------------------------------------\n";
            cout << "     this account is an  admin account \n";
            cout << "---------------------------------------------\n";
            char selection{};
            do {

                cout << "\toptions\n";
                cout << "1- modify user name\n";
                cout << "2- modify password \n";
            check_2:
                cout << "\nchoose your operation: ";
                char choose{};
                cin >> choose;
                getline(cin, trash);


                switch (choose)
                {
                case '1':
                    modify_user_name(name, check);
                    break;
                case '2':
                    modify_password(name, check);
                    break;
                default:cout << "\nInvalid choice \n";
                    goto check_2;
                    break;
                }
                cout << "DO you want more operations  (Y\\N) \n";
                cin >> selection;
            } while (selection != 'N' && selection != 'n');
        }
    }




    file.open("data.txt");
    for (int i = 0; i < cust.size(); i++)
    {
        file << cust[i].name << " " << cust[i].pass << " " << cust[i].type << " " << cust[i].balanc << endl;
    }
    file.close();
}


void modify_user_name(string name, int check) {
    string new_user_name;
check_4:
    cout << "\nEnter the new username :";
    cin >> new_user_name;
    for (int i = 0; i < cust.size(); i++)
    {
        if (cust[i].name == new_user_name)
        {
            cout << "-------------------------------------------------------";
            cout << "\n\tThis username already exist choose another \n";
            cout << "-------------------------------------------------------";
            goto check_4;

        }
    }
    cout << "----------------------------------------------\n";
    cout << " the new username modified from " << cust[check].name << " to " << new_user_name << endl;
    //cout << cust[check].name;
    cust[check].name = new_user_name;
    //cout<< new_user_name;
    cout << "\n\t     operation succeded\n\n";
    cout << "----------------------------------------------\n";

}

void modify_password(string name, int check) {
    string new_password;

    cout << "Enter the password :";
    cin >> new_password;
    cout << "----------------------------------------------\n";
    cout << " the new password modified from " << cust[check].pass << " to " << new_password << endl;
    cust[check].pass = new_password;

    //   cout << "-----------------------------------\n";
    cout << "\n\t     operation succeded\n\n";
    cout << "----------------------------------------------\n";
}

void modify_balance(string name, int check) {
    int new_Balance;
    cout << "Enter the balance :";
    cin >> new_Balance;
    cout << "----------------------------------------------\n";
    if (new_Balance > cust[check].balanc)
    {
        cout << " the new balance increased from " << cust[check].balanc << " to " << new_Balance << endl;
    }
    else
    {
        cout << " the new balance decreased from " << cust[check].balanc << " to " << new_Balance << endl;
    }
    cust[check].balanc = new_Balance;

    cout << "\n\t     operation succeded\n\n";
    cout << "----------------------------------------------\n";
}

int close_an_account(string name) {

    file.open("data.txt");
    cust.clear();
    while (file >> in.name)
    {
        file >> in.pass >> in.type >> in.balanc;
        cust.push_back(in);
    }
    file.clear();
    file.close();

    int check = -1;
    for (int i = 0; i < cust.size(); i++)
    {
        if (name == cust[i].name)
        {

            // cout << "found it" << endl;
            check = i;
        }
    }

    vector<customer> cust_2;

    for (int i = 0; i < cust.size(); i++)
    {
        if (i == check)
        {
            continue;
        }

        in.name = cust[i].name;
        in.pass = cust[i].pass;
        in.type = cust[i].type;
        in.balanc = cust[i].balanc;
        cust_2.push_back(in);

    }



    ifstream File;

    File.open("data.txt", ifstream::out | ifstream::trunc);

    File.close();

    file.open("data.txt");

    for (int i = 0; i < cust_2.size(); i++)
    {

        file << cust_2[i].name << " " << cust_2[i].pass << " " << cust_2[i].type << " " << cust_2[i].balanc << endl;

    }
    file.close();

    return check;
}

////////////////////////////////////////////