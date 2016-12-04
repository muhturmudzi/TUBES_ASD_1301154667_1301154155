#include "list_child_singlecircular.h"

void createList(List_child &L) {
    /**
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
}

address_child alokasi(infotype_child x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address_child P;
    P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    //createList(child(P));
    return P;
}

void dealokasi(address_child &P){
    delete P;
}


void insertFirst(List_child &L, address_child P) {
    /**
    * IS : List_child L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_child L
    *      next dari last elemen menunjuk ke first elemen
    */
    address_child Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertAfter(List_child &L, address_child Prec, address_child P){
    next(P) = next(Prec);
    next(Prec) = P;
}

void insertLast(List_child &L, address_child P){
    address_child Q;
    Q = first(L);
    next(Q) = P;
}

void deleteFirst(List_child &L, address_child &P){
    P = first(L);
    first(L) = next(P);
    next(P) = NULL;

    //return P;
}

void deleteLast(List_child &L, address_child &P){
    address_child Q;
    Q = first(L);
    P = next(Q);
    next(Q) = NULL;

    //return P;
}

void deleteAfter(List_child &L, address_child Prec, address_child &P){
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;

    //return P;
}


void printInfo(List_child L) {
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_child P = first(L);
    cout<<"A";
    if(first(L)!=NULL) {
        do {
            cout<<"B";
            cout<<info(P).id_pengajuan<<endl;
            cout<<info(P).alamat<<endl;
            cout<<info(P).TTL<<endl;
            cout<<info(P).tinggi<<endl;
            cout<<info(P).pekerjaan<<endl;
            cout<<info(P).GolDarah<<endl;
            cout<<info(P).JenisSim<<endl;
            cout<<info(P).tanggal_tes<<endl;
            cout<<info(P).alamat_samsat<<endl;
            cout<<info(P).status_pengajuan<<endl;

            //printInfo(child(P));
            P = next(P);
        } while(P!=first(L));
    }
}

address_child findElm(List_child L, infotype_child x) {
    /**
    * IS : List_child L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_child P = first(L);
    do {
        if(P->info.id_pengajuan == x.id_pengajuan) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}
