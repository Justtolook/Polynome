/***************************************************************************************************
Header-Datei   Lineare Liste
!!!!    l_elementtype muss vom Benutzer angepasst werden
Autor: Shohmann
Datum: 01.2011/aktualisiert 2017
***************************************************************************************************/
#ifndef LINLISTE_H
#define LINLISTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Vom Benutzer angelegter Elementtyp
// Hier für Polynomverarbeitung
typedef struct
{
    unsigned char cVar;
    int iExpo;
    int iKoeff;
}l_elementtype;

// rekursiv definierte Struktur
// Listenobjekte bestehend aus einem Elementtyp und einem Verweis auf ein weiteres Listenobjekt
struct l_basisobjecttype
{
	l_elementtype ltcontent ;
	struct l_basisobjecttype *pltnext ;
};

//Um sich das struct zu sparen wird der Pointer auf die Struktur mit einem eigenen Datentyp definiert
typedef struct l_basisobjecttype *l_objecttype;

// Die eigentliche Liste besteht aus einem Zeiger auf den Listenanfang: kopf
// und einem Zeiger auf das gerade betrachtete Listenelement: aktuell
typedef  struct
{
	 l_objecttype head , actual;
}l_listtype;

// Vom Benutzer anzupassende Funktion zur Eingabe der Elementwerte des aktuellen Elementes
void l_setcontent(l_listtype *lList );


// Der Inhalt des aktuellen Elements wird zurück gegeben
l_elementtype * l_getcontent (l_listtype lList) ;

// Neues Listenelement erzeugen
//l_basisobjecttype *l_create_newelement(int iBenutzer, unsigned char cV, int iE, int iK);

// Listenoperationen - Funktionen zur Erzeugung und Veränderung einer Liste
// Neues leeres Listenelement erzeugen
l_objecttype l_create_newelement();

// Neue Liste erzeugen
l_listtype l_create () ;

// Überprüfung auf leere Liste!
// Gibt 1 zurück, falls die Liste leer ist
int l_empty (l_listtype lList ) ;

// Überprüfung, ob das Ende der Liste erreicht ist!
// Gibt 1 zurück, falls das aktuelle Element das letzte Element ist
int l_end (l_listtype lList ) ;

// Der Inhalt des aktuellen Elements wird durch newelement ersetzt
void l_update (l_listtype *lList , l_elementtype newelement ) ;

// Das aktuelle Element wird gelöscht. Das neue aktuelle Element ist das erste Element
void l_delete (l_listtype *lList ) ;

// Das aktuelle Element wird auf den Listenanfang zurückgesetzt
void l_reset (l_listtype *lList ) ;

// Das aktuelle Element wird auf den Nachfolger gesetzt
void l_next (l_listtype *lList ) ;

// Das Element newelement wird ans Ende der Liste gehängt
void l_last (l_listtype *lList , l_objecttype newelement) ;

// Das Element newelement wird vor dem aktuellen Element eingefügt
void l_insert (l_listtype *lList , l_objecttype newelement ) ;

#endif /* LINLISTE_H */
