#ifndef MENUCODING_H_INCLUDED
#define MENUCODING_H_INCLUDED

#include "list_parent_double.h"
#include "list_child_singlecircular.h"


#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

//punya parent
void createList(List_parent &L);
void insertFirst(List_parent &L, address_parent P);
void insertLast(List_parent &L, address_parent P);
void insertAfter(address_parent Prec, address_parent P);
void deleteFirst(List_parent &L, address_parent &P);
void deleteLast(List_parent &L, address_parent &P);
void deleteAfter(address_parent Prec, address_parent &P);
address_parent alokasi(infotype_parent x);
void dealokasi(address_parent &P);
address_parent findElm(List_parent L, infotype_parent x);
void printInfo(List_parent L);


//punya child
void createList(List_child &L);
void insertFirst(List_child &L, address_child P);
void insertAfter(List_child &L, address_child Prec, address_child P);
void insertLast(List_child &L, address_child P);
void deleteFirst(List_child &L, address_child &P);
void deleteLast(List_child &L, address_child &P);
void deleteAfter(List_child &L, address_child Prec, address_child &P);
address_child alokasi(infotype_child x);
void dealokasi(address_child &P);
address_child findElm(List_child L, infotype_child x);
void printInfo(List_child L);


void createAll();
void mainMenu(); //List_parent &L1, List_child &L2
void clrscr();
void registUser(); //List_parent &L
void Login(); //List_parent &L1, List_child &L2
void menuUser(); //List_parent &L1, List_child &L2
void loginAdmin(); //List_parent &L1, List_child &L2
void menuAdmin(); //List_parent &L1, List_child &L2
void PengajuanSIM();



#endif // MENUCODING_H_INCLUDED
