#include <iostream>
#include <stdio.h>
using namespace std;

struct nodo{
	char dato;
	nodo *sgte;
	nodo *anterior;
};

int nuevonodo(nodo *&lista,char n)
{	nodo *nuevo_nodo = new nodo();
	nodo *aux1 = lista;
	nodo *aux2;
	nuevo_nodo->dato = n;
	int cont=0;
	
	while (aux1!=NULL)
	{	aux2=aux1;
		aux1=aux1->sgte;
		cont++ ;
	}
	if (lista==NULL)
	{	lista=nuevo_nodo;
		lista->anterior=NULL;
	}
	else	aux2->sgte=nuevo_nodo;
	nuevo_nodo->sgte=aux1;
	nuevo_nodo->anterior=aux2;
	return cont;
}

void remover(nodo *&lista){
	nodo *aux=lista;
	nodo *aux2=lista->anterior;
	int n=aux2->dato;
	cout<<n<<endl;
	if ((aux2)!=NULL)
	{	int x=(lista->anterior)->dato;
		cout<<x<<endl;
		(lista->anterior)->sgte=aux->sgte;
		lista=aux->sgte;
		delete aux;
	}
	else
	{	lista=aux->sgte;
		delete aux;
	}
}

void movercabeza(nodo *&lista, char n){
	if (n=='>'){lista=lista->sgte;}
	else if(n=='<'){
		if((lista->anterior)!=NULL){
			lista=lista->anterior;
		}
	}	
}

void arreglo(char arr[][100],int n){
	int cont=0;
	char x;
	while(cont<=n-1){
		for(int i=0;i<100;i++){cin>>x;
	
		arr[cont][i]=x;
			if(x=='!'){
			break;
			}
		}
	cont++;	
	}
}

void mostrarlista(nodo *&lista){
	nodo *aux=lista;
	char x;
	for(;aux->sgte!=NULL;aux=aux->sgte){
		x=aux->dato;
		cout<<x;
	}
	x=aux->dato;
	cout<<x;
}

void removertodalista(nodo *&lista){
	nodo *aux=lista;
	nodo *aux2=aux;
	while(aux2!=NULL){
		aux=aux2;
		aux2=aux->sgte;
		delete aux;
		
	}
	delete aux2;
	lista=NULL;	
	
}