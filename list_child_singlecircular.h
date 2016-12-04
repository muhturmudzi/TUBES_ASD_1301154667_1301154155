#ifndef LIST_CHILD_SINGLECIRCULAR_H_INCLUDED
#define LIST_CHILD_SINGLECIRCULAR_H_INCLUDED


#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info


//typedef int infotype_child;
typedef struct elmlist_child *address_child;

typedef struct pengajuan infotype_child;
struct pengajuan{
    string alamat;
    string TTL;
    string tinggi;
    string pekerjaan;
    string GolDarah;
    string JenisSim;
    string tanggal_tes;
    string alamat_samsat;
    int id_pengajuan;
    string status_pengajuan;
};

struct elmlist_child {
    infotype_child info;
    address_child next;
};

struct List_child {
    address_child first;
};


/** TIDAK PERLU MODIFIKASI */
void createList(List_child &L);
void insertFirst(List_child &L, address_child P);
void insertAfter(List_child &L, address_child Prec, address_child P);
void insertLast(List_child &L, address_child P);
void deleteFirst(List_child &L, address_child &P);
void deleteLast(List_child &L, address_child &P);
void deleteAfter(List_child &L, address_child Prec, address_child &P);


/** PERLU MODIFIKASI */
address_child alokasi(infotype_child x);
void dealokasi(address_child &P);
address_child findElm(List_child L, infotype_child x);
void printInfo(List_child L);



#endif // LIST_CHILD_SINGLECIRCULAR_H_INCLUDED
