#ifndef TDA_H
#define TDA_H


struct nodo{
	char dato;
	nodo *sgte;
	nodo *anterior;
};

char CharToInt(char);
int nuevonodo(nodo *&,char n);
void movercabeza(nodo *&,int);
void asignarvalor(nodo *&,int n);
void remover(nodo *&);
void arreglo(char [][100],int n);
void mostrarlista(nodo *&);
void removertodalista(nodo *&lista);

#endif