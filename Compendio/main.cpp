#include "interprete.h"
#include "TDA.h"
using namespace std;
#include <iostream>
#include <stdio.h>
#include <bitset>
#include <string>
#include <math.h> 
#define MAX 500

int main()
{	int NrProgramas = 0;
	cin >> NrProgramas;
	char A[NrProgramas][MAX];
	for (int f = 0; f < NrProgramas; f++)
	{	for (int C = 0; C < MAX; C++)
		{	cin >> A[f][C];
			if (A[f][C] == '!') break;
		}
	}
}