/*
Name: Henrik Lammert
Thema: Polynome mit Linearen Listen
Datum: 31.01.2017
Letzte Änderung: 14.02.2017
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
    l_reset(&lList);
    return(lList);
}

void ausgabe(l_listtype *lList) { //verbessern?
    printf(">Ausgabe<\n\n");
    l_reset(lList);
    printf("f(%c)=",lList->actual->ltcontent.cVar);
    do {
        printf("%d%c^%d",lList->actual->ltcontent.iKoeff, lList->actual->ltcontent.cVar, lList->actual->ltcontent.iExpo);
        if(l_end(*lList)!=1) {
            printf("+");
        }
        l_next(lList);

    }while(l_end(*lList)!=1);
    printf("%d%c^%d",lList->actual->ltcontent.iKoeff, lList->actual->ltcontent.cVar, lList->actual->ltcontent.iExpo);
    if(l_end(*lList)!=1) {
        printf("+");
    }
    printf("\n\n");
    l_reset(lList);


}

void ableiten(l_listtype *lList) {
    l_listtype lListAbg= l_create();

    l_reset(lList);

    do{
        l_last(&lListAbg,l_create_newelement());
    }while(l_end(*lList));

    l_last(&lListAbg,l_create_newelement());

    l_reset(lList);
    l_reset(&lListAbg);
    do{
        (lListAbg.actual->ltcontent.iKoeff)=(lList->actual->ltcontent.iKoeff) * (lList->actual->ltcontent.iExpo);
        (lListAbg.actual->ltcontent.iExpo)=(lList->actual->ltcontent.iExpo)-1;
        (lListAbg.actual->ltcontent.cVar)=(lList->actual->ltcontent.cVar);
        l_next(&lListAbg);
        l_next(lList);
    }while(l_end(*lList)!=1);
    (lListAbg.actual->ltcontent.iKoeff)=(lList->actual->ltcontent.iKoeff) * (lList->actual->ltcontent.iExpo);
    (lListAbg.actual->ltcontent.iExpo)=(lList->actual->ltcontent.iExpo)-1;
    (lListAbg.actual->ltcontent.cVar)=(lList->actual->ltcontent.cVar);

    l_reset(lList);
    l_reset(&lListAbg);
    printf("f'(%c)=",lListAbg.actual->ltcontent.cVar);
    do{
        if((lListAbg.actual->ltcontent.iExpo)==0) {
            printf("%d", lListAbg.actual->ltcontent.iKoeff);
        }
        if((lListAbg.actual->ltcontent.iExpo)==-1) {
            printf(" ");
        }
        if((lListAbg.actual->ltcontent.iExpo)>0){
            printf("%d%c^%d",lListAbg.actual->ltcontent.iKoeff, lListAbg.actual->ltcontent.cVar, lListAbg.actual->ltcontent.iExpo);
        }

        if(l_end(lListAbg)!=1 || ((lListAbg.actual->ltcontent.iExpo)!=-1)) {
            printf("+");
        }
        l_next(&lListAbg);
    }while(l_end(lListAbg)!=1);

    if((lListAbg.actual->ltcontent.iExpo)==0) {
            printf("%d", lListAbg.actual->ltcontent.iKoeff);
    }
    if((lListAbg.actual->ltcontent.iExpo)==-1) {
        printf(" ");
    }
    if((lListAbg.actual->ltcontent.iExpo)>0){
            printf("%d%c^%d",lListAbg.actual->ltcontent.iKoeff, lListAbg.actual->ltcontent.cVar, lListAbg.actual->ltcontent.iExpo);
    }

}

void addition(l_listtype *lList) {
    l_listtype lList1 = l_create();
    l_listtype lList2 = l_create();


    lList1=eingabe();
    l_reset(&lList1);
    ausgabe(&lList1);
    l_reset(lList);
    do{
        if((lList->actual->ltcontent.iExpo) == (lList1.actual->ltcontent.iExpo) && (lList->actual->ltcontent.cVar) == (lList1.actual->ltcontent.cVar)) {
            l_last(&lList2,l_create_newelement());
            lList2.actual->ltcontent.cVar = lList->actual->ltcontent.cVar;
            lList2.actual->ltcontent.iExpo = lList->actual->ltcontent.iExpo;
            lList2.actual->ltcontent.iKoeff = lList->actual->ltcontent.iKoeff + lList1.actual->ltcontent.iKoeff;
            l_next(&lList2);
        }
        else {
            l_last(&lList2,l_create_newelement());
            lList2.actual->ltcontent.cVar = lList->actual->ltcontent.cVar;
            lList2.actual->ltcontent.iExpo = lList->actual->ltcontent.iExpo;
            lList2.actual->ltcontent.iKoeff = lList->actual->ltcontent.iKoeff;
            l_next(&lList2);
            l_last(&lList2,l_create_newelement());
            lList2.actual->ltcontent.cVar = lList1.actual->ltcontent.cVar;
            lList2.actual->ltcontent.iExpo = lList1.actual->ltcontent.iExpo;
            lList2.actual->ltcontent.iKoeff = lList1.actual->ltcontent.iKoeff;
            l_next(&lList2);
        }
        l_next(lList);
        l_next(&lList1);
    }while(l_end(*lList)!=1);
    if((lList->actual->ltcontent.iExpo) == (lList1.actual->ltcontent.iExpo) && (lList->actual->ltcontent.cVar) == (lList1.actual->ltcontent.cVar)) {
        l_last(&lList2,l_create_newelement());
        lList2.actual->ltcontent.cVar = lList->actual->ltcontent.cVar;
        lList2.actual->ltcontent.iExpo = lList->actual->ltcontent.iExpo;
        lList2.actual->ltcontent.iKoeff = lList->actual->ltcontent.iKoeff + lList1.actual->ltcontent.iKoeff;
        l_next(&lList2);
    }
    else {
        l_last(&lList2,l_create_newelement());
        lList2.actual->ltcontent.cVar = lList->actual->ltcontent.cVar;
        lList2.actual->ltcontent.iExpo = lList->actual->ltcontent.iExpo;
        lList2.actual->ltcontent.iKoeff = lList->actual->ltcontent.iKoeff;
        l_next(&lList2);
        l_last(&lList2,l_create_newelement());
        lList2.actual->ltcontent.cVar = lList1.actual->ltcontent.cVar;
        lList2.actual->ltcontent.iExpo = lList1.actual->ltcontent.iExpo;
        lList2.actual->ltcontent.iKoeff = lList1.actual->ltcontent.iKoeff;
        l_next(&lList2);
    }
    l_reset(&lList2);
    ausgabe(&lList2);
}

void subtrahieren(l_listtype *lList) {
    l_listtype lList1 = l_create();
    l_listtype lList2 = l_create();


    lList1=eingabe();
    l_reset(&lList1);
    ausgabe(&lList1);
    l_reset(lList);
    do{
        if((lList->actual->ltcontent.iExpo) == (lList1.actual->ltcontent.iExpo) && (lList->actual->ltcontent.cVar) == (lList1.actual->ltcontent.cVar)) {
            l_last(&lList2,l_create_newelement());
            lList2.actual->ltcontent.cVar = lList->actual->ltcontent.cVar;
            lList2.actual->ltcontent.iExpo = lList->actual->ltcontent.iExpo;
            lList2.actual->ltcontent.iKoeff = lList->actual->ltcontent.iKoeff - lList1.actual->ltcontent.iKoeff;
            l_next(&lList2);
        }
        else {
            l_last(&lList2,l_create_newelement());
            lList2.actual->ltcontent.cVar = lList->actual->ltcontent.cVar;
            lList2.actual->ltcontent.iExpo = lList->actual->ltcontent.iExpo;
            lList2.actual->ltcontent.iKoeff = lList->actual->ltcontent.iKoeff;
            l_next(&lList2);
            l_last(&lList2,l_create_newelement());
            lList2.actual->ltcontent.cVar = lList1.actual->ltcontent.cVar;
            lList2.actual->ltcontent.iExpo = lList1.actual->ltcontent.iExpo;
            lList2.actual->ltcontent.iKoeff = lList1.actual->ltcontent.iKoeff;
            l_next(&lList2);
        }
        l_next(lList);
        l_next(&lList1);
    }while(l_end(*lList)!=1);
    if((lList->actual->ltcontent.iExpo) == (lList1.actual->ltcontent.iExpo) && (lList->actual->ltcontent.cVar) == (lList1.actual->ltcontent.cVar)) {
            l_last(&lList2,l_create_newelement());
            lList2.actual->ltcontent.cVar = lList->actual->ltcontent.cVar;
            lList2.actual->ltcontent.iExpo = lList->actual->ltcontent.iExpo;
            lList2.actual->ltcontent.iKoeff = lList->actual->ltcontent.iKoeff + lList1.actual->ltcontent.iKoeff;
            l_next(&lList2);
        }
        else {
            l_last(&lList2,l_create_newelement());
            lList2.actual->ltcontent.cVar = lList->actual->ltcontent.cVar;
            lList2.actual->ltcontent.iExpo = lList->actual->ltcontent.iExpo;
            lList2.actual->ltcontent.iKoeff = lList->actual->ltcontent.iKoeff;
            l_next(&lList2);
            l_last(&lList2,l_create_newelement());
            lList2.actual->ltcontent.cVar = lList1.actual->ltcontent.cVar;
            lList2.actual->ltcontent.iExpo = lList1.actual->ltcontent.iExpo;
            lList2.actual->ltcontent.iKoeff = lList1.actual->ltcontent.iKoeff;
            l_next(&lList2);
        }
    l_reset(&lList2);
    ausgabe(&lList2);
}


int main()
{
    int iOption=0;
    l_listtype lList = l_create();

    printf(">>>Polynome<<<\n");
    printf("ACHTUNG: Bitte geben sie die Summanden vom großen bis kleinen Exponenten ein!\n");


    lList=eingabe();
    ausgabe(&lList);

    printf("\n\n");
    l_reset(&lList);


    printf("Was moechten Sie machen?\n");
    printf("1 Ableiten\n");
    printf("2 Polynome addieren\n");
    printf("3 Polynome subtrahieren\n");
    scanf("%d", &iOption);

    switch(iOption) {
    case 1: ableiten(&lList);break;
    case 2: addition(&lList);break;
    case 3: subtrahieren(&lList);break;
    }


    return 0;
}
