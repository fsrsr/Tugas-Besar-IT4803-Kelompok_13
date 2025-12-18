#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <iostream>
#include "Keyword.h"
#include "Paper.h"
using namespace std;

void menuAdmin(ListKeyword &LK, ListPaper &LP);
void menuUser(ListKeyword &LK, ListPaper &LP);
void menuRelation(ListKeyword &LK, ListPaper &LP);

#endif // MAIN_H_INCLUDED
