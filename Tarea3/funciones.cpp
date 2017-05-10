#include "funciones.h"
using namespace std;
#include <iostream>
#include <stdio.h>
#include <bitset>
#include <string>
#include <math.h> 
#define MAX 500

void NewProg()
{
	int NrProgramas = 0;
	cin >> NrProgramas;
	char A[NrProgramas][MAX];
	for (int f = 0; f < NrProgramas; f++)
	{	for (int C = 0; C < MAX; C++)
		{	cin >> A[f][C];
			if (A[f][C] == '!') break;
		}
	}

	for (int f = 0; f < NrProgramas; f++)
	{	for (int C = 0; C < MAX; C++)
		{	cout << A[f][C]; 
			if (A[f][C] == '!') break;
		}
		cout << endl;
	} 
	return;
}



