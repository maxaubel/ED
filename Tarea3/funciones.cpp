#include "funciones.h"
using namespace std;
#include <iostream>
#include <stdio.h>
#include <bitset>
#include <string>
#include <math.h> 
#define MAX 30




void parte1()
{
	float P;
	int L;
	cin >> L;
	int A[MAX];
	for(int j=0; j < L; j++) cin >> A[j];
	cin >> P;
	Ordenar(A, L);
	if (A[0] <= P && P <= A[L-1]) //Verifica, si es posible, sin tener que buscar coincidencias
	{	cout << "condicion se cumple";
		{	for(int i = L-1; 0 < i; i--) //Recorre el binario
			{

			}
		}	
	}
	else cout << "0" << endl;
	return;
}

////////////////////////////////////////////////////////////////
int convertarraytoint( int array[], int limit ) {
  int result = 0;
  int invertarray[limit];
  for (int j=0; j <= limit; j++){
    invertarray[j] = array[limit-j];
  }
  for (int i=0; i <= limit; i++)
  {
    result *= 10;
    result += invertarray[i];
  }
  return result;
}

int binary(int number) 
{	int binarynum[1000];
	int count = 0;
	for ( int i = 0; number > 0 ; i ++ ) 
	{	binarynum[i] = number % 2;
		number = number / 2;
		count++;
	}

	int finalbinary = convertarraytoint(binarynum,count);
	return finalbinary;
	
}
//////////////////////////////////////////////////////////////////////

void parte2()
{	cout<<"nada por ahora"<<endl;
	return;
}


void Ordenar(int arr[], int n) //O(n^2)
{	bool interc = true;
	int j = 0;
	int tmp;
	while (interc) 
	{	interc = false;
		j++;
		for (int i = 0; i < n - j; i++) 
		{	if (arr[i] > arr[i + 1]) 
			{	tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				interc = true;
			}
		}
	}
}