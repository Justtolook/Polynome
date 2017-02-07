/*
Name: Henrik Lammert
Thema: Polynome mit Linearen Listen
Datum: 31.01.2017
Letzte Änderung: 07.02.2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "linliste.h"


l_listtype eingabe() {

    l_listtype lList = l_create();
    int iAgain;
    printf("Bitte geben Sie ihr Polynom ein.\n");
    do
    {
        l_last(&lList,l_create_newelement());
        l_setcontent(&lList);
        printf("Moechten Sie noch ein Summand eingeben?\n Ja -> 1\n Nein -> 0\n");
        scanf("%d", &iAgain);
        printf("\n");
    }while(iAgain==1);

    return(lList);
}

void ausgabe(l_listtype *lList) { //TODO: vollständige ausgabe
    int iC;
    int iL;
    printf(">Ausgabe2<\n\n");
    l_reset(lList);
    printf("f(%c)=",lList->actual->ltcontent.cVar);
    do {
        printf("%d%c^%d",lList->actual->ltcontent.iKoeff, lList->actual->ltcontent.cVar, lList->actual->ltcontent.iExpo);
        if(l_end(*lList)!=1) {
            printf("+");
        }
        l_next(lList);

    }while(l_end(*lList)!=1);
    printf("\n\n");
    l_reset(lList);


}

void ableiten(l_listtype *lList) { //TODO: Ableitung in neue List speichern
    l_listtype lListAbg;


    do{
        (lListAbg.actual->ltcontent.iKoeff)=(lList->actual->ltcontent.iKoeff) * (lList->actual->ltcontent.iExpo);
        (lListAbg.actual->ltcontent.iExpo)=(lList->actual->ltcontent.iExpo)--;
        (lListAbg.actual->ltcontent.cVar)=(lList->actual->ltcontent.cVar);
        l_next(lList);
    }while(l_end(*lList)!=1);
    (lListAbg.actual->ltcontent.iKoeff)=(lList->actual->ltcontent.iKoeff) * (lList->actual->ltcontent.iExpo);
    (lListAbg.actual->ltcontent.iExpo)=(lList->actual->ltcontent.iExpo)--;
    (lListAbg.actual->ltcontent.cVar)=(lList->actual->ltcontent.cVar);

    l_reset(lList);
    do{
        if((lListAbg.actual->ltcontent.iExpo)==0) {
            printf("%d", lList->actual->ltcontent.iKoeff);
        }
        if((lListAbg.actual->ltcontent.iExpo)==-1) {
            printf(" ");
        }
        if((lListAbg.actual->ltcontent.iExpo)>0){
            printf("%d%c^%d",lListAbg.actual->ltcontent.iKoeff, lListAbg.actual->ltcontent.cVar, lListAbg.actual->ltcontent.iExpo);
        }

        if(l_end(*lList)!=1 || ((lListAbg.actual->ltcontent.iExpo)!=-1)) {
            printf("+");
        }
        l_next(lList);
    }while(l_end(*lList)!=1);
    if((lListAbg.actual->ltcontent.iExpo)==0) {
            printf("%d", lList->actual->ltcontent.iKoeff);
    }
    if((lListAbg.actual->ltcontent.iExpo)==-1) {
        printf(" ");
    }
    if((lListAbg.actual->ltcontent.iExpo)>0){
            printf("%d%c^%d",lListAbg.actual->ltcontent.iKoeff, lListAbg.actual->ltcontent.cVar, lListAbg.actual->ltcontent.iExpo);
    }


    printf("");

}

void division(l_listtype *lList) {
    l_listtype lList1 = l_create();
    l_listtype lList2 = l_create();

    lList1=eingabe();
    lList2=eingabe();

}


int main()
{
    int iAgain=0;
    int iC=0;
    int iL;
    int iOption=0;
    l_listtype lList = l_create();

    printf(">>>Polynome<<<\n");
    /*
    printf("Bitte geben Sie ihr Polynom ein.\n");
    do
    {
        l_last(&lList,l_create_newelement());
        l_setcontent(&lList);
        printf("Moechten Sie noch ein Summand eingeben?\n Ja -> 1\n Nein -> 0\n");
        scanf("%d", &iAgain);
        printf("\n");
        iC++;
    }while(iAgain==1);
    */

    lList=eingabe();
    ausgabe(&lList);

    printf("\n\n");

    printf(">Ausgabe<\n\n");
    l_reset(&lList);
    printf("f(%c)=",lList.actual->ltcontent.cVar);
    for(iL=0;iL<iC;iL++) {
        printf("%d%c^%d",lList.actual->ltcontent.iKoeff, lList.actual->ltcontent.cVar, lList.actual->ltcontent.iExpo);
        if(l_end(lList)!=1) {
            printf("+");
        }
        l_next(&lList);
    }
    printf("\n\n");
    l_reset(&lList);


    printf("Was moechten Sie machen?\n");
    printf("1 Ableiten\n");
    printf("2 Polynomdivision\n");
    scanf("%d", &iOption);

    switch(iOption) {
    case 1: ableiten(&lList);
    }


    return 0;
}
