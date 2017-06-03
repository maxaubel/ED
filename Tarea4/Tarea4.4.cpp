#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <fstream>
#include <string>
#include <thread> 

using namespace std;

struct nodo{     //La estructura cuencta con 5 campos, dato es el nombre de la carpeta/archivo, tipo es para saber si la entidad es archivo o carpeta
	int tipo;	
	string dato;	
	nodo *hermano;//Los nodos hermanos representan un lista enlazada.
	nodo *hijo;	//cada nodo se enlazará a su hijo primogenito, se tendra que recorrer la lista hermanos para obtener la información de todos los hijos hermanos.
	nodo *padre; //cada nodo estará enlazado a su padre, o en otras palabras, a la carpeta anterior
};

void insertarnodo(nodo *aux2, nodo *insertar)//función que inserta los hijos de una carpeta.
{	if (aux2 -> hermano == NULL)//si el padre no tiene hijos, lo inserta directamente
	{	aux2 -> hermano = insertar;
	}
	else if(aux2 -> hermano != NULL)//si el padre tiene hijos, recorro la lista que generan sus hijos y se inserta el nuevo hijo al final de la lista hermanos.
	{	for(; aux2 -> hermano != NULL; aux2 = aux2 -> hermano){}
		aux2 -> hermano = insertar;
	}
	return;
}


void lectura(nodo *&arbol,string arch){
	cout << "Cargando Directorio..." << endl; //desde ésta linea hasta la linea antes del while, se genera los nodos iniciales del árbol, nodo home y nodo usuario.
	nodo *aux = new nodo(); //Nodo aux será el padre de cada carpeta/archivo
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
		nodo *aux2;//aux2 será el encargado de recorre la lista de hermanos e insertar el hijo al final de ésta.
		if(texto == "<carpeta>")//cada vez que aparece 'carpeta', se inserta el nodo generado en los hijos del nodo aux y luego aux pasa a ser el nuevo nodo generado
		{	getline(archivo, texto);
			getline(archivo, texto);
			nodo *insertar = new nodo();
			insertar->dato=texto; //se genera el nuevo nodo con los datos correspondientes.
			insertar->padre=aux;// cada nodo tiene como padre a aux.
			insertar->hermano=NULL;
			insertar->hijo=NULL;
			insertar->tipo=0;
			if(aux->hijo==NULL)//si el nodo a insertar es primogenito simplemente se inserta como hijo de aux
			{	aux->hijo=insertar;
				aux=insertar;//aux se transforma en el nodo insertado, ya que cada 'carpeta' es un potencial padre.
			}
			if(aux->hijo!=NULL)//si el nodo a insertar no es primogenito, se debe recorrer la lista hermanos y luego insertar.
			{	aux2=aux->hijo;//aux2 será el primogenito del padre, el auxiliar se usa para no perder la informacion de aux que es el padre de todos.
				insertarnodo(aux2,insertar);//funcion que recorre la lista de hermanos e inserta al final de ésta.
				aux=insertar;//aux se transforma en el nodo insertado, ya que cada 'carpeta' es un potencial padre.
			}
		}
		if(texto=="<archivo>")//los archivos no pueden tener hijos así que aux no se transforma.
		{	getline(archivo, texto);
			getline(archivo, texto);
			nodo *insertar = new nodo();
			insertar->dato=texto;
			insertar->padre=aux;
			insertar->hermano=NULL;
			insertar->hijo=NULL;
			insertar->tipo=1;
			if(aux->hijo!=NULL)//si el nodo a insertar es primogenito simplemente se inserta como hijo de aux
			{	aux2=aux->hijo;
				insertarnodo(aux2,insertar);
			}
			if(aux->hijo==NULL)//si el nodo a insertar no es primogenito, se debe recorrer la lista hermanos y luego insertar.
			{	aux->hijo=insertar;
			}
		}
		if(texto=="</carpeta>")//cuando un padre tiene todos sus hijos listos, auxiliar tiene que volver al padre anterior
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
void print(string texto)
{	cout << texto << endl;
	return;
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
		case 0:			//salir //listo
			return false;
		case 1:			//imprime tipo de elemento
			cout << tipo(cursor->tipo) << cursor->dato << endl;
			*cortar = true;;
			cout << *cortar << endl;	
			return true;

		case 2:			//imprime ruta //listo
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
		case 3:			//imprime hijos //listo
		{	if (cursor->tipo != 1 && cursor->hijo != NULL)
			{	nodo *aux = cursor->hijo;
				cout << aux->dato << endl;
				for(; aux -> hermano != NULL; aux = aux -> hermano) cout << aux->hermano->dato << endl;
			}
			return true;
		}
		case 4:			//entra a un hijo (entidad) //listo
		{	if (/*cursor->tipo != 1 && */cursor->hijo != NULL)
			{	string entidad;
				cin >> entidad;
				cursor = cursor->hijo;
				for(; cursor -> hermano != NULL; cursor = cursor -> hermano)
				{	if (cursor->dato == entidad) break;
				}
			}
			return true;
		}
		case 5:			//regresa al padre //listo
		{	 cursor=cursor->padre;
			return true;
		}
		case 6:			//guarda la entidad en el portapapeles (COPIAR) //revisar
		{	
			portapapeles->hermano = NULL;
			portapapeles->padre = NULL;
			portapapeles->dato = cursor->dato;
			portapapeles->hijo = cursor->hijo;
			*cortar = false;
			return true;
		}
		case 7:			//falta probar //CORTAR
		{	portapapeles = cursor;
			*cortar = true;
			return true;
		}
		case 8:
		{	print("1");
			if(!*cortar)	//Si lo que se quiere pegar fue copiado
			{	print("2");
				if(cursor->hijo == NULL)
				{	cursor->hijo = portapapeles;
					portapapeles->padre = cursor;
				}
				else if (cursor->hijo != NULL)
				{	print("3");
					nodo *aux3;
					aux3 = cursor->hijo;
					for(; aux3->hermano != NULL; aux3 = aux3->hermano)
					{
						if(aux3->dato == aux3->hermano->dato)
						{
							aux3->dato = aux3->dato + "-copia";
						}
					}
					aux3->hermano = portapapeles;
					portapapeles->padre = cursor;
				}
			}
			
			//delete portapapeles->hermano;

			/*
			if (*cortar)		//si el origen de lo pegado fue cortado:
			{	if(portapapeles->hermano == NULL) portapapeles->padre = cursor;
				else if()
			}
			else 			//si el origen de lo pegado fue copiado
			{	insertarnodo(cursor->padre, portapapeles);
			}
			*/
			return true;
		}
		case 9:
		{	if (cursor->hermano == NULL) //si no tiene hermanos
			{	cursor=cursor->padre;
				cursor->hijo = NULL;
			}
			else //si tiene hermanos
			{	
				cursor->padre->hijo = cursor->hermano;

			}
			//cursor = cursor->padre;
			return true;
		}
		case 10:
		{
			cout << "0: Ingresar otro archivo\n1: Imprimir nombre: tipo de entidad\n2: Imprimir ruta\n3: Imprimir elementos dentro de la entidad\n4: Entrar a una entidad\n5: Regresar\n6: Copiar la entidad\n7: Cortar la entidad\n8: Pegar\n9: Eliminar\n";
		}
		case 11:
		{
			cout << portapapeles->dato << endl;
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
		print("hola");
		nodo *portapapeles = new nodo();
		while (ingresarComando(arbol, cursor, &cortar, portapapeles));
   	}while(running);


	return 0;
  
}
