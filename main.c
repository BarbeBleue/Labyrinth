#include <stdio.h>
#include <stdlib.h>

#include "gui.h"
#include "struct.h"
#include "mapping.h"




Path Astar(Map *L,int P1, int P2); //return the shortest path beetween P1 and P2 
Path Astarpp(Map L,int P1, int P2); //return the shortest path beetween P1 and P2 taking the change of map into account, evaluatng the advantages with evaluate();

int crowFly(Map *L,int P1,int P2);//evaluate the distance beetween P1 and P2(of the map L) as the crows flies 
int evaluate(Map *L);//Return the






int main()
{
	Map *L=initMap();
	t_move move;
	int choice=0;
	while(choice!=-1)
	{
		choice=GUI(L,choice);
		switch(choice)
		{
			case 30:
				getMap(L);
			break;
			
			case 40:
			case 41:
			case 42:
			case 43:
				move.type=choice%4;
				moveP(L,0,move);
			break;
			
			
		}
	}

	return 0;
}


