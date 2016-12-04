#include "list_parent_double.h"


void createList(List_parent &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_parent alokasi(infotype_parent x) {
    address_parent P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    //P->listanak.first =NULL;
    createList(listanak(P));
    return P;
}

void dealokasi(address_parent &P){
    delete P;
}


void insertFirst(List_parent &L, address_parent P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_parent &L, address_parent P){
    prev(P) = last(L);
    next(last(L)) = P;
    last(L) = P;
}

void insertAfter(address_parent Prec, address_parent P) {
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}

void deleteFirst(List_parent &L, address_parent &P){
    P = first(L);
    if(first(L) != last(L)){
        first(L) = next(P);
        next(P) = NULL;
        prev(first(L)) = NULL;
    }else{
        first(L) = NULL;
        last(L) = NULL;
    }
    //return P;
}

void deleteLast(List_parent &L, address_parent &P){
    P = last(L);
    last(L) = prev(last(L));
    prev(P) = NULL;
    next(last(L)) = NULL;

//    return P;
}

void deleteAfter(address_parent Prec, address_parent &P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P) = NULL;
    next(P) = NULL;

//    return P;
}


void printInfo(List_parent L) {
    address_parent P = first(L);
    while(P !=NULL) {
        cout<<"->"<<info(P).username<<endl;
        cout<<"->"<<info(P).email<<endl;
        cout<<"->"<<info(P).Nama<<endl;
        P = next(P);
    }
}


address_parent findElm(List_parent L, infotype_parent x) {
    address_parent P = first(L);
    while(P != NULL) {
        if(info(P).username==x.username) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}


