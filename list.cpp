#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) diset Nil
    */
    //------------- YOUR CODE HERE -------------
    first(L)=NULL;
    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = NULL;
    //------------- YOUR CODE HERE -------------
    P=new elmlist;
    info(P).ID = x.ID;
    info(P).location = x.location;
    info(P).name = x.name;
    next(P)=NULL;
    prev(P)=NULL;
    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //------------- YOUR CODE HERE -------------
    delete P;
    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //------------- YOUR CODE HERE -------------
    if(first(L)!=NULL){
        next(P)=first(L);
        prev(P)=prev(first(L));
        next(prev(first(L)))=P;
        prev(first(L))=P;
        first(L)=P;
    }else {
        first(L)=P;
        next(P)=P;
        prev(P)=P;
    }
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //------------- YOUR CODE HERE -------------
    if(first(L)==NULL){
        insertFirst(L, P);
    } else {
        next(P)=first(L);
        prev(P)=prev(first(L));
        next(prev(first(L)))=P;
        prev(first(L))=P;
    }
    //----------------------------------------
}

address findElmByID(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //------------- YOUR CODE HERE -------------
    while(next(P)!=first(L) && info(P).ID!=x.ID){
        P=next(P);
    }
    //----------------------------------------
    return P;
}

address findElmByName(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //------------- YOUR CODE HERE -------------
    while(next(P)!=first(L) && info(P).name!=x.name){
        P=next(P);
    }
    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    if(next(P)==first(L)){
        P=first(L);
        next(P)=NULL;
        prev(P)=NULL;
        first(L)=NULL;
    } else {
        next(prev(first(L)))=next(P);
        first(L)=next(P);
        next(prev(first(L)))=first(L);
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    P=first(L);
    if(next(P)==P){
        deleteFirst(L, P);
    } else {
        first(L)=next(first(L));
        next(prev(P))=first(L);
        prev(first(L))=prev(P);
        next(P)=NULL;
        prev(P)=NULL;
    }
    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //------------- YOUR CODE HERE -------------
    next(P)=next(Prec);
    prev(next(P))=P;
    next(Prec)=P;
    prev(next(Prec))=Prec;
    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    P=next(Prec);
    next(Prec)=next(P);
    next(prev(first(L)))=first(L);
    //----------------------------------------
}

