#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

static struct customer
{
    string name, pass;
    char type;
    int balanc;
};

static vector<customer> cust;
static customer in;
static fstream file;

static string trash;