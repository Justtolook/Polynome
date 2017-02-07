/***************************************************************************
Implementation der Funktionen zur Linearen Liste
Autor: S. Hohmann
Datum: Jan 2011/aktualisiert2017
***************************************************************************/
#include "linliste.h"

/*IMPLEMENTATION
(*-------------------------------------------------------------------------*)
(*     Vom Nutzer des ADT muss zu Beginn seines Anwenderprogramms          *)
(*     wunschgem‰ﬂ <l_elementtype>  vorgegeben werden !!!                  *)
(*-------------------------------------------------------------------------*)
*/
/******************************************************************************
Die Funktion l_inhaltsetzen(..) dem l_elementtyp anpassen,
d.h. die entsprechenden Inhalte vom Benutzer einlesen
Es werden die Inhalte des aktuellen Listenelementes ¸berschrieben
******************************************************************************/
void l_setcontent(l_listtype *lList )
{
      // vom Benutzer einzugeben:
      printf("Variable: ");
      scanf(" %c",&lList->actual->ltcontent.cVar);
      printf("Exponent: ");
      scanf("%d",&lList->actual->ltcontent.iExpo);
      printf("Koeffizient:");
      scanf("%d",&lList->actual->ltcontent.iKoeff);
}


/****************************************************************************
!!! WICHTIG !!!! Ab hier nichts mehr ver‰ndern!!!
****************************************************************************/
/*
(*-------------------------------------------------------------------------*)
(* hier wird Speicher f¸r ein neues leeres Listenelement reserviert und    *)
(* die Funktion l_inhaltsetzen aufgerufen                                  *)
(*-------------------------------------------------------------------------*)
*/
l_objecttype l_create_newelement()
{
        l_objecttype ltbasisnew;
        if((ltbasisnew = (l_objecttype) malloc(sizeof(struct l_basisobjecttype)))==NULL)
        {
            printf("Fehler bei der Speicherreservierung!");
            getchar();
            exit(1);
        }
        else
        {
            ltbasisnew->pltnext=NULL;
        }
        return(ltbasisnew);

}
/*
(*-------------------------------------------------------------------------*)
(* hier wird eine leere Lineare Liste initialisiert                        *)
(*-------------------------------------------------------------------------*)
*/
l_listtype l_create ()
{
  l_listtype lList;

  lList.head    = NULL ;                // Liste ist `leer`
  lList.actual = NULL ;                // es gibt kein aktuelles Element
  return(lList);
}
/*
(*-------------------------------------------------------------------------*)
(* hier wird ¸berpr¸ft, ob die Liste `leer` ist                            *)
(*-------------------------------------------------------------------------*)
*/
int l_empty (l_listtype lList )
{
	  return(lList.head == NULL);
}

/*
(*-------------------------------------------------------------------------*)
(* hier wird ¸berpr¸ft, ob man am Ende der Liste steht         *)
(*-------------------------------------------------------------------------*)
*/
int l_end (l_listtype lList )
{
  if(!l_empty( lList ))
  {	if(lList.actual->pltnext == NULL )
			return(1);
      else
	      return(0);
  }
  else
	 return(1);
}
/*
(*-------------------------------------------------------------------------*)
(* hier wird das aktuelle Listenelement durch den Inhalt der zweiten       *)
(* Variablen des Prozeduraufrufs ersetzt                                   *)
(*-------------------------------------------------------------------------*)
*/
void l_update (l_listtype *lList , l_elementtype newelement)
{
  if(! l_empty( *lList ))
	  lList->actual->ltcontent = newelement;
}
/*
(*-------------------------------------------------------------------------*)
(* auf die zweite Variable des Prozeduraufrufs wird der Inhalt des aktu-   *)
(* ellen Listenelementes abgelegt                                          *)
(*-------------------------------------------------------------------------*)
*/
l_elementtype * l_getcontent (l_listtype lList)
{
  if(!l_empty(lList))
  	  return(&lList.actual->ltcontent);
  else
      return NULL;
}

/*
(*-------------------------------------------------------------------------*)
(* das (logisch) erste Element der Liste wird zum aktuellen Element        *)
(*-------------------------------------------------------------------------*)
*/
void l_reset (l_listtype *lList )
{
  if(!l_empty(*lList))
	 lList->actual = lList->head;
}
/*
(*-------------------------------------------------------------------------*)
(* das (logisch) n‰chste Element der Liste wird zum aktuellen Element      *)
(*-------------------------------------------------------------------------*)
*/
void l_next (l_listtype *lList )
{
  if(! l_empty( *lList ))
	  if(! l_end ( *lList ))
			lList->actual = lList->actual->pltnext;
}
/*
(*-------------------------------------------------------------------------*)
(* der Inhalt der zweiten Variablen des Prozeduraufrufs wird als logisch   *)
(* letztes Element an das Ende der Liste plaziert                          *)
(*-------------------------------------------------------------------------*)
*/
void l_last (l_listtype *lList , l_objecttype newelement )
{
    if(l_empty ( *lList ))
		lList->head = newelement;
	else
	{
		while(! l_end ( *lList ))
            l_next ( lList );
        lList->actual->pltnext = newelement;
    }
	lList->actual = newelement;
}

/*
(*-------------------------------------------------------------------------*)
(* der Inhalt der zweiten Variablen wird vor das aktuelle Listenelement    *)
(* eingef¸gt und automatisch zum aktuellen Element.                        *)
(* bei `leerer` Liste wird stattdessen l_last aufgerufen                   *)
(*-------------------------------------------------------------------------*)
*/
void l_insert (l_listtype *lList , l_objecttype newelement )
{
    l_objecttype ltprevious ;

    if((ltprevious = (l_objecttype ) malloc(sizeof(struct l_basisobjecttype)))==NULL)
    {
        printf("Fehler bei der Speicherreservierung!");
        getchar();
        exit(1);
    }
    if(!l_empty(*lList))
	{
		if(lList->actual == lList->head)
		{
			newelement->pltnext = lList->actual;
			lList->head = newelement;
		}
		else
		{
			ltprevious = lList->head;
			while(ltprevious->pltnext != lList->actual)
			{
				ltprevious = ltprevious->pltnext;
			}
			newelement->pltnext = lList->actual;
			ltprevious->pltnext = newelement;
        }
		lList->actual = newelement ;
    }
	else
	{
	    l_last ( lList , newelement );
    }
    free(ltprevious);
}
/*
(*-------------------------------------------------------------------------*)
(* das aktuelle Element wird gelˆscht und es wird l_reset durchgef¸hrt     *)
(*-------------------------------------------------------------------------*)
*/
void l_delete (l_listtype *lList)
{
	l_objecttype ltprevious;

     if((ltprevious = (l_objecttype) malloc(sizeof(struct l_basisobjecttype)))==NULL)
    {
        printf("Fehler bei der Speicherreservierung!");
        getchar();
        exit(1);
    }

	if(!l_empty(*lList))
	{
			if( lList->actual == lList->head)
				lList->head = lList->actual->pltnext;
			else
			{
				ltprevious = lList->head ;
				while(ltprevious->pltnext != lList->actual)
				{
				    ltprevious = ltprevious->pltnext;
				}
				ltprevious->pltnext  =  lList->actual->pltnext;
			}
			l_reset(lList);
	}
	free(ltprevious);
}
