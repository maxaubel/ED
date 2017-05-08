#include <iostream>
#include <stdio.h>
using namespace std;
struct nodo{
	int dato;
	nodo *sgte;
	nodo *anterior;
};

int nuevonodo(nodo *&,int n);
void movercabeza(nodo *&,int);
void asignarvalor(nodo *&,int n);
void remover(nodo *&);


int main(){
	nodo *instrucciones=NULL;
	cout<<nuevonodo(instrucciones,3)<<endl;
	cout<<nuevonodo(instrucciones, 43)<<endl;
	cout<<nuevonodo(instrucciones,25)<<endl;
	cout<<nuevonodo(instrucciones,3)<<endl;

	cout<<nuevonodo(instrucciones,3)<<endl;
	

	
	

	return 0;
}

int nuevonodo(nodo *&lista,int n){
	nodo *nuevo_nodo=new nodo();
	nodo *aux1= lista;
	nodo *aux2;
	nuevo_nodo->dato=n;
	int cont=0;
	
	while(aux1!=NULL)
	{
		aux2=aux1;
		aux1=aux1->sgte;
		cont++ ;
	}
	if(lista==NULL)
	{
		lista=nuevo_nodo;
		lista->anterior=NULL;
	}
	else
	{
		aux2->sgte=nuevo_nodo;
	}
	nuevo_nodo->sgte=aux1;
	nuevo_nodo->anterior=aux2;
	return cont;
	}

void remover(nodo *&lista){
	nodo *aux=lista;
	nodo *aux2=lista->anterior;
	int n=aux2->dato;
	cout<<n<<endl;
	if ((aux2)!=NULL){
		int x=(lista->anterior)->dato;
		cout<<x<<endl;
		(lista->anterior)->sgte=aux->sgte;
		lista=aux->sgte;
		delete aux;
	}
	else{
		lista=aux->sgte;
		delete aux;
	}
}

void movercabeza(nodo *&lista, int n){
	if (n==0){lista=lista->sgte;}
	else{
		if((lista->anterior)!=NULL){
			lista=lista->anterior;
		}
	}
	
}



