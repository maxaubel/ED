#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <fstream>
#include <string>
#include <thread> 

using namespace std;

struct nodo{
	int tipo;
	string dato;
	nodo *hermano;
	nodo *hijo;
	nodo *padre;
};

void insertarnodo(nodo *aux2, nodo *insertar)
{	if (aux2 -> hermano == NULL)
	{	aux2 -> hermano = insertar;
	}
	else if(aux2 -> hermano != NULL)
	{	for(; aux2 -> hermano != NULL; aux2 = aux2 -> hermano){}
		aux2 -> hermano = insertar;
	}
	return;
}


void lectura(nodo *&arbol,string arch){
	cout << "Cargando Directorio..." << endl;
	nodo *aux = new nodo();
	ifstream archivo;
	archivo.open(arch, ios::in);
	string texto;
	arbol->dato="home";
	arbol->tipo=2;
	getline(archivo, texto);
	getline(archivo, texto);
	getline(archivo, texto);
	getline(archivo,texto);
	nodo *usuario=new nodo();
	usuario->dato=texto;
	usuario->padre=arbol;
	usuario->hijo=NULL;
	usuario->hermano=NULL;
	usuario->tipo=0;
	arbol->hijo=usuario;
	aux = arbol->hijo;
	while(!archivo.eof())
	{	getline(archivo,texto);
		nodo *aux2;
		if(texto == "<carpeta>")
		{	getline(archivo, texto);
			getline(archivo, texto);
			nodo *insertar = new nodo();
			insertar->dato=texto;
			insertar->padre=aux;
			insertar->hermano=NULL;
			insertar->hijo=NULL;
			insertar->tipo=0;
			if(aux->hijo==NULL)
			{	aux->hijo=insertar;
				aux=insertar;
			}
			if(aux->hijo!=NULL)
			{	aux2=aux->hijo;
				insertarnodo(aux2,insertar);
				aux=insertar;
			}
		}
		if(texto=="<archivo>")
		{	getline(archivo, texto);
			getline(archivo, texto);
			nodo *insertar = new nodo();
			insertar->dato=texto;
			insertar->padre=aux;
			insertar->hermano=NULL;
			insertar->hijo=NULL;
			insertar->tipo=1;
			if(aux->hijo!=NULL)
			{	aux2=aux->hijo;
				insertarnodo(aux2,insertar);
			}
			if(aux->hijo==NULL)
			{	aux->hijo=insertar;
			}
		}
		if(texto=="</carpeta>")
		{	aux=aux->padre;
		}
	}
	archivo.close();
	cout << "Arbol Cargado." << endl;
}

string ingresarArch()
{	string nombre;
	cout << "Ingrese nombre archivo de carga:"<< endl;
	cin >> nombre;
	ifstream archivo;
	archivo.open(nombre,ios::in);
	while(archivo.fail())
	{	cout << "ERROR: No se pudo abrir el archivo" << endl;
		cout << "Ingrese nombre archivo de carga:"<< endl;
		cin >> nombre;
		archivo.open(nombre,ios::in);
	}
	return nombre;
}

string tipo(int tipo)
{	switch (tipo)
	{	case 0: return "Carpeta: ";
		case 1: return "Archivo: ";
		case 3: return "Carpeta: ";
	}
	return "";
}

bool ingresarComando(nodo *&arbol, nodo *&cursor, bool *cortar, nodo *&portapapeles)
{	int comando;
	cin >> comando;
	switch (comando)
	{
		case 0:			//salir
			return false;
		case 1:			//imprime tipo de elemento
			cout << tipo(cursor->tipo) << cursor->dato << endl;
			return true;
		case 2:			//imprime ruta
		{	nodo *aux = cursor;
			string ruta = "/home/";
			string ruta2 = "";
			while(aux->tipo != 2)
			{	ruta2 =  aux->dato + "/" + ruta2;
				aux = aux->padre;
			}
			ruta = ruta + ruta2;
			cout << ruta << endl;
			return true;
		}
		case 3:			//imprime hijos
		{	nodo *aux = cursor->hijo;
			cout << "hola" << endl;
			cout << aux->dato << endl;
			for(; aux -> hermano != NULL; aux = aux -> hermano) cout << aux->hermano->dato << endl;
			
			return true;
		}
		case 4:			//entra a un hijo (entidad)
		{	string entidad;
			cin >> entidad;
			cursor = cursor->hijo;
			for(; cursor -> hermano != NULL; cursor = cursor -> hermano)
				if (cursor->dato == entidad) break;

			return true;
		}
		case 5:			//regresa al padre
			cursor=cursor->padre;
			return true;
		case 6:			//falta probar //guarda la entidad en el portapapeles (COPIAR)
		{	
			portapapeles = cursor;
			portapapeles->hermano = NULL;
			*cortar = false;
			return true;
		}
		case 7:			//falta probar //CORTAR
		{	
			*cortar = true;
			portapapeles = cursor;
			return true;
		}
		case 8:
		{	if (cortar)
			{	nodo *father = new nodo();
				father = portapapeles->padre;
				nodo *hermanoEnPotencia = father->hijo;

				if (hermanoEnPotencia == portapapeles)
				{	(portapapeles->padre)->hijo = portapapeles->hermano;
				}
				else
				{	nodo *aux = portapapeles;
					for(; aux->hijo != NULL; aux = aux->hijo) {}
					for(; aux->padre != NULL; aux = aux->padre)
					{	nodo *aux2;
						for(; aux2->hermano != NULL; aux2 = aux2->hermano)
						{	delete aux2->hijo;
						}
					}
				}
			}
			else
			{	nodo *father = cursor->padre;
				nodo *hermanoEnPotencia = father->hijo;
				hermanoEnPotencia = cursor;
				for(; cursor -> hermano != NULL; cursor= cursor -> hermano)
				{	if (cursor->dato == portapapeles->dato) portapapeles->dato = portapapeles->dato + " - copia";
				}
				cursor = portapapeles;

			}
			return true;
		}
		case 9:
		{
			//bla bla bla bla
			return true;
		}
		case -1:
		{
			cout << "0: Ingresar otro archivo\n1: Imprimir nombre: tipo de entidad\n2: Se imprimir ruta\n3: Se imprimira elementos dentro de la entidad\n4: Entrar a una entidad\n5: Regresar\n6: Copia la entidad donde se esta actualmente.\n7: Corta la entidad donde se esta actualmente.\n8: Pegar la entidad actual.\n9: Elimina la entidad actual\n";
		}
		default: return true;
	}
}



int main()
{
	nodo *arbol=new nodo();
	bool cortar = false;
	bool running = true;
	bool loading = true;
	//thread myThread = new thread(new threadstart(Loading));
	//myThread .Start();
	
	do {
     	nodo *arbol=new nodo();
		lectura(arbol,ingresarArch());
		nodo *cursor = arbol;
		nodo *portapapeles = new nodo();
		while (ingresarComando(arbol, cursor, &cortar, portapapeles));
   	}while(running);


	return 0;
  
}






