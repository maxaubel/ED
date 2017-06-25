#include <iostream>

#include "quickSort.h"

using namespace std;

void agregar(int a[], int n)
{	for(int i=0; i<n; i++)
		cin >> a[i];
}

void capacidad(int a[], int n, int din)
{	int suma=0, juegos=0;
	for(int i=0; i<n && suma+a[i]<=din; i++)
	{	suma += a[i];
		juegos++;
	}
	cout << juegos << endl;

}

void quick_Sort(int a[], int l, int u)
{	int j;
	if(l<u)
	{	j = partition(a, l, u);
		quick_Sort(a, l, j-1);
		quick_Sort(a, j+1, u);
	}
}
 
int partition(int a[],int l,int u)
{	int v,i,j,aux;
	v = a[l];
	i = l;
	j = u+1;
	do
	{	do
			i++;
		while(a[i]<v && i<=u);
		do
			j--;
		while(v<a[j]);

		if(i<j)
		{
			aux  = a[i];
			a[i] = a[j];
			a[j] = aux;
		}
	}while(i<j);
	a[l] = a[j];
	a[j] = v;
	return(j);
}