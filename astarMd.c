#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "struct.h"
#include "gui.h"
#include "mapping.h"
#include "astarMd.h"
#include "labyrinthAPI.h"


int astarMode(Map *L)
{	
	char ** nodes=(char **) malloc(L->width*L->heigth*sizeof(char));
	Node * openlist=initOpenList(L,L->players[0]->X,L->players[0]->Y);
	
	return 1;
}

Node *initOpenList(Map *L,int x, int y) 
{
	Node* N= (Node *) malloc(sizeof(Node));
	N->X=x;
	N->Y=y;
	N->ncase=L->cases[N->Y]+N->X;
	N->cost=0;
	N->heuristic=N->cost;//+dist(L,x,y);
	N->pathParent=NULL;
	return N;
}

Node *newNode(Map *L,int x, int y,Node * parent) //create a new case for a neighbour of c
{
	Node* N= (Node *) malloc(sizeof(Node));
	N->X=x;
	N->Y=y;
	N->ncase=L->cases[N->Y]+N->X;
	N->cost=parent->cost+1;
	N->heuristic=N->cost;//+dist(L,x,y);
	N->pathParent=parent;
	return N;
}

/*Node* add(Node *N1,Node* NodetoAdd)
{
	Node *Nact=N1->first;
	if(N1->heuristic > MtoAdd->heuristic)//pour l'ordre croissant ">"
	{
		MtoAdd->next = M1;
		return MtoAdd;
	}
	else if(Mact->n==MtoAdd->n)
	{
		Mact->c+=MtoAdd->c;
		free(MtoAdd);
		return M1;
	}
	else
	{
		while(Mact->next!=NULL&&Mact->next->n<MtoAdd->n)//pour l'ordre croissant "<"
		{
			Mact=Mact->next;
		}
		if(Mact->next!=NULL&&Mact->next->n==MtoAdd->n)
		{
			Mact->next->c+=MtoAdd->c;
			free(MtoAdd);
		}
		else
		{
			Maillon* next =Mact->next;
			Mact->next = MtoAdd;
			MtoAdd->next = next;
		}
		
		return M1;
	}	
}*/

int distNtoP(Map *L,int P,Node *N)
{
	int dx1=(L->players[P]->X - N->X);
	dx1=(dx1>0)?dx1:-dx1;
	int dx2=(N->X + L->width - L->players[P]->X);
	dx2=(dx2>0)?dx2:-dx2;
	
	int dy1=(L->players[P]->Y - N->Y);
	dy1=(dy1>0)?dy1:-dy1;
	int dy2=(N->Y + L->heigth - L->players[P]->Y);
	dy2=(dy2>0)?dy2:-dy2;
	
	if(dx1<dx2)
	{
		if(dy1<dy2)
			return dx1+dy1;
		else
			return dx1+dy2;
	}
	else	
	{
		if(dy1<dy2)
			return dx2+dy1;
		else
			return dx2+dy2;
	}	
		
}

int distance_to_treasure(Map *L,int x,int y) // renvoie la distance au carré d'un point au trésor pour comparaison des distances
{
	int Xt=L->players[2]->X;
	int Yt=L->players[2]->Y;
	return (Xt-x)*(Xt-x)+(Yt-y)*(Yt-y);
}

/*List * add_to_list(List* list, Case c) //add the case c into list
{
	while(list->next!=NULL)
	{
	}
	
}

Node* check_lowest(List *list) //return the node with the lowest heuristique in list
{
}

int check_presence(Node* node, List *list)
{
}

Node* Astar_case(Map *L, //return the node the player has to go to
{
	List *openlist;
	List *closedlist;
	début boucle tant que openlist non vide
		prendre le plus petit élément de openlist et le mettre dans closedlist
			si noeud=trésor remonter les sources puis renvoyer la case où aller
			si noeud!=trésor rajoutez tous les voisins inexplorés (=pas dans closedlist) du noeud dans openlist si pas déjà dans la liste
	si open list vide = pas de chemin possible
}

*/



	


