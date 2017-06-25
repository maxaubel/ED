#include <iostream>

#include "bubbleSort.h"
#include "quickSort.h"

using namespace std;

void bubble_Sort()
{
	int x;
	cin>>x;
	int Valores[x];
	int Ordenar[x];
	for (int i = 0; i<x ; i++)
	{
		int c,z;
		cin>>c;
		cin>>z;
		Valores[i] = c+z;
		Ordenar[i]= c+z;
	}
	for(int i = 0; i<(x-1);i++)
	{
		for(int j = i + 1; j < x ; j++ )
		{
			int temp;
			if(Ordenar[i]>Ordenar[j]){
				temp = Ordenar[i];
				Ordenar[i] = Ordenar[j];
				Ordenar[j] = temp;
			}
		}
	}
	
	for(int i = 0; i<x ; i++)
	{
		for(int j = 0; j<x; j++)
		{
			if (Ordenar[i] == Valores[j]) cout<<j+1<<" " ;
		}
	}
	return;
}