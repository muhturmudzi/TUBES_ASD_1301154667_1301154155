#ifndef LIST_PARENT_DOUBLE_H_INCLUDED
#define LIST_PARENT_DOUBLE_H_INCLUDED

#include <iostream>
#include "list_child_singlecircular.h"

using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define listanak(P) P->listanak

//typedef string infotype_parent;
typedef struct elmlist_parent *address_parent;

typedef struct account infotype_parent;
struct account{
    string username;
    string email;
    string Nama;
    string password;
    string NoHp;
    string JenisKelamin;
};

struct elmlist_parent{
    infotype_parent info;
    address_parent next;
    address_parent prev;
    List_child listanak;
};

struct List_parent{
    address_parent first;
    address_parent last;
};

/** TIDAK PERLU MODIFIKASI */
void createList(List_parent &L);
void insertFirst(List_parent &L, address_parent P);
void insertLast(List_parent &L, address_parent P);
void insertAfter(address_parent Prec, address_parent P);
void deleteFirst(List_parent &L, address_parent &P);
void deleteLast(List_parent &L, address_parent &P);
void deleteAfter(address_parent Prec, address_parent &P);


/** PERLU MODIFIKASI */
address_parent alokasi(infotype_parent x);
void dealokasi(address_parent &P);
address_parent findElm(List_parent L, infotype_parent x);
void printInfo(List_parent L);




#endif // LIST_PARENT_DOUBLE_H_INCLUDED
