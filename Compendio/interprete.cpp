#include "interprete.h"
#include "TDA.h"
using namespace std;
#include <iostream>
#include <stdio.h>
#include <bitset>
#include <string>
#include <math.h> 
#define MAX 500

void Crear()
{	nodo *instrucciones = NULL;
	char arr[100][100];
	char z;
	int x;
	int g;
	char s=' ';
	while(s!='s')
	{	cin>>x;
		arreglo(arr,x);
	}
	while (s!='s')
	{	cin>>s;
		if(s=='c')
		{	cin>>g;
			if(instrucciones!=NULL)
			{	removertodalista(instrucciones);
				for(int i=0;i<100;i++ ){
					z=arr[g][i];
					nuevonodo(instrucciones,z);
					if(z=='!')	break;
				}
			}
			else
			{	for(int i=0;i<100;i++ )
				{	z=arr[g][i];
					nuevonodo(instrucciones,z);
					if(z=='!')	break;
				}
			}

		if(s == 'm')
			{
			if(instrucciones==NULL)	cout<<"Sin instrucciones"<<endl;
			else	mostrarlista(instrucciones);
			}
		}
	}
	return;
}

int Dicc()
{	char Dict[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U','V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', ':', '+', '-', '<', '>', '[', ']', '!' };
	return 1;
}