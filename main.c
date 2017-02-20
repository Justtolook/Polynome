/*
Name: Henrik Lammert
Thema: Polynome mit Linearen Listen
Datum: 31.01.2017
Letzte Änderung: 20.02.2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "linliste.h"




l_listtype eingabe() {

    l_listtype lList = l_create();
    int iC;
    int iGrad;
    int iEingabe;
    printf("Bitte geben Sie ihr Polynom ein.\n");
    printf("Welchen max. Grad hat die Funktion?\n");
    scanf("%d", &iGrad);

    for(iC=0;iC<=iGrad;iC++) {
        l_last(&lList,l_create_newelement());   //Neues Listenelement wird erstellt.
        printf("Möchten sie einen Summand des %d. Grades eingeben?\n1=Ja\n0=Nein\n", iGrad-iC);
        scanf("%d", &iEingabe);
        if(iEingabe == 1) {
            l_setcontent(&lList);       //Benutzer kann den Inhalt festlegen.
        }
        //Wenn der Summand nicht vom Benutzer eingegeben wird,
        //wird er von alleine gefüllt. Alle Werte werden auf 0 gesetzt.
        if(iEingabe == 0) {
            lList.actual->ltcontent.iKoeff =0;
            lList.actual->ltcontent.iExpo =0;
            lList.actual->ltcontent.cVar =0;
        }
        printf("\n");
    }
    l_reset(&lList);




    l_reset(&lList);
    return(lList);
}

void ausgabe(l_listtype *lList) {
    l_reset(lList);
    printf("f(%c)=",lList->actual->ltcontent.cVar);
    do {
        if(lList->actual->ltcontent.iKoeff == 0) {  //Wenn der Koeffizient 0 ist, dann muss der Summand
            printf("");                             //nicht ausgegeben werden, da er in jedem Fall 0 ist.
        }
        if((lList->actual->ltcontent.iExpo)==0 && ((lList->actual->ltcontent.cVar)!=0)) { //Ist der Exponent = 0 und ist keine Variable eingegeben,
            printf("%d", lList->actual->ltcontent.iKoeff);                                // reicht es, dass man den Koeffizient ausgibt.
        }
        if((lList->actual->ltcontent.iExpo)==-1) {
            printf("");
        }

        //Ausgabe des ganzen Summanden, wenn der Exponent > 0 ist und eine Variable eingegeben wurde.
        if(((lList->actual->ltcontent.iExpo)>0) && ((lList->actual->ltcontent.cVar)!=0)){
            printf("%d%c^%d",lList->actual->ltcontent.iKoeff, lList->actual->ltcontent.cVar, lList->actual->ltcontent.iExpo);
        }
        if(l_end(*lList)!=1) {
            printf("+");
        }
        l_next(lList);

    }while(l_end(*lList)!=1);
    //Wenn der Koeffizient 0 ist, dann muss der Summand
    //nicht ausgegeben werden, da er in jedem Fall 0 ist.
    if(lList->actual->ltcontent.iKoeff == 0) {
        printf("");
    }
    //Ist der Exponent = 0 und ist keine Variable eingegeben,
    // reicht es, dass man den Koeffizient ausgibt.
    if((lList->actual->ltcontent.iExpo)==0 && ((lList->actual->ltcontent.cVar)!=0)) {
        printf("%d", lList->actual->ltcontent.iKoeff);
    }
    if((lList->actual->ltcontent.iExpo)==-1) {
        printf("");
    }
    //Ausgabe des ganzen Summanden, wenn der Exponent > 0 ist und eine Variable eingegeben wurde.
    if(((lList->actual->ltcontent.iExpo)>0) && ((lList->actual->ltcontent.cVar)!=0)){
            printf("%d%c^%d",lList->actual->ltcontent.iKoeff, lList->actual->ltcontent.cVar, lList->actual->ltcontent.iExpo);
    }


    printf("\n\n");
    l_reset(lList);


}

void ableiten(l_listtype *lList) {
    l_listtype lListAbg= l_create();    //Liste für die Ableitung erstellen

    l_reset(lList);
                                        //Genügend Listenelemente für das Polynom erstellen
    do{
        l_last(&lListAbg,l_create_newelement());
        l_next(lList);
    }while(l_end(*lList)!=1);

    l_last(&lListAbg,l_create_newelement());

    l_reset(lList);
    l_reset(&lListAbg);
                                        //Ableitung
    do{
        //Potenzregel
        (lListAbg.actual->ltcontent.iKoeff)=(lList->actual->ltcontent.iKoeff) * (lList->actual->ltcontent.iExpo);
        //Potenzregel
        (lListAbg.actual->ltcontent.iExpo)=(lList->actual->ltcontent.iExpo)-1;
        //Konstantenregel
        if((lListAbg.actual->ltcontent.iExpo)==-1) {
            (lListAbg.actual->ltcontent.iExpo)=0;
            (lListAbg.actual->ltcontent.iKoeff)=0;
        }
        (lListAbg.actual->ltcontent.cVar)=(lList->actual->ltcontent.cVar);
        l_next(&lListAbg);
        l_next(lList);
    }while(l_end(*lList)!=1);
    //Potenzregel
    (lListAbg.actual->ltcontent.iKoeff)=(lList->actual->ltcontent.iKoeff) * (lList->actual->ltcontent.iExpo);
    //Potenzregel
    (lListAbg.actual->ltcontent.iExpo)=(lList->actual->ltcontent.iExpo)-1;
    //Konstantenregel
    if((lListAbg.actual->ltcontent.iExpo)==-1) {
            (lListAbg.actual->ltcontent.iExpo)=0;
            (lListAbg.actual->ltcontent.iKoeff)=0;
    }
    (lListAbg.actual->ltcontent.cVar)=(lList->actual->ltcontent.cVar);

    l_reset(lList);
    l_reset(&lListAbg);
    printf("Ausgabe der Ableitung von: f'(%c)=",lListAbg.actual->ltcontent.cVar);
    ausgabe(&lListAbg);     //Ausgabe der Ableitung

}

void addition(l_listtype *lList) {
    l_listtype lList1 = l_create(); //erstellen der 2. Liste
    l_listtype lList2 = l_create(); //erstellen der Liste, wo die Lösung gespeichert wird.


    lList1=eingabe(); //Der Benutzer soll das 2. Polynom eingeben
    l_reset(&lList1);
    printf("==> ");
    ausgabe(&lList1);   //2. Polynom wird zur Kontrolle ausgegeben
    l_reset(lList);
    do{
        //Kontrollieren ob Voraussetzungen für addition erfüllt sind
        if((lList->actual->ltcontent.iExpo) == (lList1.actual->ltcontent.iExpo) && (lList->actual->ltcontent.cVar) == (lList1.actual->ltcontent.cVar)) {
            l_last(&lList2,l_create_newelement()); //neues Listenelement erstellen
            lList2.actual->ltcontent.cVar = lList->actual->ltcontent.cVar;
            lList2.actual->ltcontent.iExpo = lList->actual->ltcontent.iExpo;
            //Addition der Koeffizienten
            lList2.actual->ltcontent.iKoeff = lList->actual->ltcontent.iKoeff + lList1.actual->ltcontent.iKoeff;
            l_next(&lList2);
        }
        else { //wenn die Voraussetzungen für eine Addition nicht erfülllt sind, werden beide Summanden gespeichert
            l_last(&lList2,l_create_newelement()); //neues Listenelement erstellen
            lList2.actual->ltcontent.cVar = lList->actual->ltcontent.cVar;
            lList2.actual->ltcontent.iExpo = lList->actual->ltcontent.iExpo;
            lList2.actual->ltcontent.iKoeff = lList->actual->ltcontent.iKoeff;
            l_next(&lList2);
            l_last(&lList2,l_create_newelement()); //neues Listenelement erstellen
            lList2.actual->ltcontent.cVar = lList1.actual->ltcontent.cVar;
            lList2.actual->ltcontent.iExpo = lList1.actual->ltcontent.iExpo;
            lList2.actual->ltcontent.iKoeff = lList1.actual->ltcontent.iKoeff;
            l_next(&lList2);
        }
        l_next(lList);
        l_next(&lList1);
    }while(l_end(*lList)!=1 || l_end(lList1)!=1);
    //Kontrollieren ob Voraussetzungen für addition erfüllt sind
    if((lList->actual->ltcontent.iExpo) == (lList1.actual->ltcontent.iExpo) && (lList->actual->ltcontent.cVar) == (lList1.actual->ltcontent.cVar)) {
        l_last(&lList2,l_create_newelement()); //neues Listenelement erstellen
        lList2.actual->ltcontent.cVar = lList->actual->ltcontent.cVar;
        lList2.actual->ltcontent.iExpo = lList->actual->ltcontent.iExpo;
        //Addition der Koeffizienten
        lList2.actual->ltcontent.iKoeff = lList->actual->ltcontent.iKoeff + lList1.actual->ltcontent.iKoeff;
        l_next(&lList2);
    }
    else { //wenn die Voraussetzungen für eine Addition nicht erfülllt sind, werden beide Summanden gespeichert
        l_last(&lList2,l_create_newelement()); //neues Listenelement erstellen
        lList2.actual->ltcontent.cVar = lList->actual->ltcontent.cVar;
        lList2.actual->ltcontent.iExpo = lList->actual->ltcontent.iExpo;
        lList2.actual->ltcontent.iKoeff = lList->actual->ltcontent.iKoeff;
        l_next(&lList2);
        l_last(&lList2,l_create_newelement()); //neues Listenelement erstellen
        lList2.actual->ltcontent.cVar = lList1.actual->ltcontent.cVar;
        lList2.actual->ltcontent.iExpo = lList1.actual->ltcontent.iExpo;
        lList2.actual->ltcontent.iKoeff = lList1.actual->ltcontent.iKoeff;
        l_next(&lList2);
    }
    l_reset(&lList2);

    printf("Ergebnis:\n\n");
    ausgabe(&lList2);
}

void subtrahieren(l_listtype *lList) {
    l_listtype lList1 = l_create();
    l_listtype lList2 = l_create();


    lList1=eingabe();
    l_reset(&lList1);

    printf("==> ");
    ausgabe(&lList1);
    l_reset(lList);
    do{
        //Kontrollieren ob Voraussetzungen für subtraktion erfüllt sind
        if((lList->actual->ltcontent.iExpo) == (lList1.actual->ltcontent.iExpo) && (lList->actual->ltcontent.cVar) == (lList1.actual->ltcontent.cVar)) {
            l_last(&lList2,l_create_newelement()); //neues Listenelement erstellen
            lList2.actual->ltcontent.cVar = lList->actual->ltcontent.cVar;
            lList2.actual->ltcontent.iExpo = lList->actual->ltcontent.iExpo;
            //Subtraktion der Koeffizienten
            lList2.actual->ltcontent.iKoeff = lList->actual->ltcontent.iKoeff - lList1.actual->ltcontent.iKoeff;
            l_next(&lList2);
        }
        else { //wenn die Voraussetzungen für eine Subtraktion nicht erfülllt sind, werden beide Summanden gespeichert
            l_last(&lList2,l_create_newelement()); //neues Listenelement erstellen
            lList2.actual->ltcontent.cVar = lList->actual->ltcontent.cVar;
            lList2.actual->ltcontent.iExpo = lList->actual->ltcontent.iExpo;
            lList2.actual->ltcontent.iKoeff = lList->actual->ltcontent.iKoeff;
            l_next(&lList2);
            l_last(&lList2,l_create_newelement()); //neues Listenelement erstellen
            lList2.actual->ltcontent.cVar = lList1.actual->ltcontent.cVar;
            lList2.actual->ltcontent.iExpo = lList1.actual->ltcontent.iExpo;
            lList2.actual->ltcontent.iKoeff = lList1.actual->ltcontent.iKoeff;
            l_next(&lList2);
        }
        l_next(lList);
        l_next(&lList1);
    }while(l_end(*lList)!=1 || l_end(lList1)!=1);
    //Kontrollieren ob Voraussetzungen für subtraktion erfüllt sind
    if((lList->actual->ltcontent.iExpo) == (lList1.actual->ltcontent.iExpo) && (lList->actual->ltcontent.cVar) == (lList1.actual->ltcontent.cVar)) {
            l_last(&lList2,l_create_newelement()); //neues Listenelement erstellen
            lList2.actual->ltcontent.cVar = lList->actual->ltcontent.cVar;
            lList2.actual->ltcontent.iExpo = lList->actual->ltcontent.iExpo;
            //Subtraktion der Koeffizienten
            lList2.actual->ltcontent.iKoeff = lList->actual->ltcontent.iKoeff - lList1.actual->ltcontent.iKoeff;
            l_next(&lList2);
        }
        else { //wenn die Voraussetzungen für eine Subtraktion nicht erfülllt sind, werden beide Summanden gespeichert
            l_last(&lList2,l_create_newelement()); //neues Listenelement erstellen
            lList2.actual->ltcontent.cVar = lList->actual->ltcontent.cVar;
            lList2.actual->ltcontent.iExpo = lList->actual->ltcontent.iExpo;
            lList2.actual->ltcontent.iKoeff = lList->actual->ltcontent.iKoeff;
            l_next(&lList2);
            l_last(&lList2,l_create_newelement()); //neues Listenelement erstellen
            lList2.actual->ltcontent.cVar = lList1.actual->ltcontent.cVar;
            lList2.actual->ltcontent.iExpo = lList1.actual->ltcontent.iExpo;
            lList2.actual->ltcontent.iKoeff = lList1.actual->ltcontent.iKoeff;
            l_next(&lList2);
        }
    l_reset(&lList2);
    printf("Ergebnis:\n\n");
    ausgabe(&lList2);
}


int main()
{
    int iOption=0;
    l_listtype lList = l_create();

    printf(">>>Polynome<<<\n");
    printf("ACHTUNG: Bitte geben sie die Summanden vom großen bis kleinen Exponenten ein!\n");
    printf("Die Eingabe von mehreren Summanden ist notwendig.\n");


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
