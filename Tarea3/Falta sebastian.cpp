#include <iostream>
#include <stdio.h>
using namespace std;
struct nodo{
	char dato;
	nodo *sgte;
	nodo *anterior;
};

int nuevonodo(nodo *&,char n);
void moveraux(nodo *&,char);
void asignarvalor(nodo *&,int n);
void remover(nodo *&);
void arreglo(char [][100],int n);
void mostrarlista(nodo *&);
void removertodalista(nodo *&lista);
int comandos(char ,int *&,char arr[72]);
void bucle(nodo *&aux, int *&,char arr[72]);

int main(){
	char letras[72]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','u','v','x','y','z'};
	nodo *instrucciones=NULL;
	int salida[100];
	int *p=salida;
	char arr[100][100];
	char z;
	int x;
	int g;
	char s=' ';
	cin>>x;
	arreglo(arr,x);
	while (s!='s'){	
		cin>>s;
		if(s=='c'){cin>>g;
			if(instrucciones!=NULL){
				removertodalista(instrucciones);
				for(int i=0;i<100;i++ ){
				z=arr[g][i];
				nuevonodo(instrucciones,z);
				if(z=='!')
					{
					break;
					}
				}
			}
			else{
				for(int i=0;i<100;i++ ){
				z=arr[g][i];
				nuevonodo(instrucciones,z);
				if(z=='!')
					{
					break;
					}
				}
				}
	
			}
		
		if(s=='m')
			{
			if(instrucciones==NULL){
			cout<<"Sin instrucciones"<<endl;
			}
			else{
				mostrarlista(instrucciones);
				}
			}
		if(s=='e'){
				nodo *aux=instrucciones;
				char x=aux->dato;
				while((aux->dato)!='!'){
					comandos(x,p,letras);
					bucle(aux,p,letras);
					aux=aux->sgte;
					x=aux->dato;
					
					}
				}
		}
	return 0;
	}
	

	




int nuevonodo(nodo *&lista,char n){
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

void moveraux(nodo *&lista, char n){
	nodo *aux=lista;
	if (n=='>'){aux=aux->sgte;
	}
	
	else if(n=='<'){
		if((aux->anterior)!=NULL){
			aux=aux->anterior;
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

int comandos(char x,int *&ptr,char arr[]){
	if (x=='>'){
		++ptr;
		}
	else if(x=='<'){
		--ptr;
		}
	else if(x=='+'){
		++(*ptr);
		}
	else if(x=='-'){
		--(*ptr);
		}
	else if(x=='.'){
		cout<<*ptr<<endl;
		}
	else if(x==':'){
		char z;
		z=arr[*ptr];
		cout<<z;
		}
	else if(x=='!'){
		return 0;
		}
}

void bucle(nodo *&aux,int *&p,char arr[]){
	char x=aux->dato;
	int z=*p;
	if(x=='['){
		nodo *aux2=aux;
		
		while(z!=0){
			aux=aux->sgte;
			x=aux->dato;
			
			comandos(x,p,arr);
			if (x==']'){
				aux=aux2;
				x=aux->dato;
				
				
				}
			z=*p;
			
			}
		while((aux->dato)!=']'){
			x=aux->dato;
			aux=aux->sgte;
			
			
			}
		}
}



