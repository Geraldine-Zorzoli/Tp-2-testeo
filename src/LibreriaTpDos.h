/*
 * MiLibreria.h
 *
 *  Created on: 14 abr. 2022
 *      Author: Geraldine
 */

#ifndef LIBRERIATPDOS_H_
#define LIBRERIATPDOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "LibreriaTpDos.c" NO SE LLAMAN ENTRE SI , H LLAMA A C

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

typedef struct {
	char flycode[10];
	int typePassenger;
	int statusFlight;
}eVuelos;

typedef struct {
	int id;
	char name[51];
	char lastname[51];
	int isEmpty;
	int dia;
	int mes;
	int anio;
}ePasajero;

ePasajero ThePassenger; //SOLUCION AL PROBLEMA DE QUE NO ME LEIA LA COCHINA FUNCION

int myGets(char* cadena, int longitud);
int ePasajero_BuscadorEspacioLibre(ePasajero listaDePasajeros[], int tam);
int getInt(char mensaje[], int reintentos, int minimo, int maximo,char mensajeError[], int *pNumeroIngresado);
void ePasajero_imprimirUno(ePasajero p); //antes tenia int solmanete pero daba error se agrego void
int ePasajero_imprimirTodos(ePasajero listaDePasajeros[], int tam, int estado); //puedo usar para imprimir ocupados , libres etc
int ePasajero_inicializar(ePasajero listaDePasajeros[], int tam); //siempre que hay un array hay un tam , va a inicializar todo el array
int ePasajero_alta(ePasajero listaDePasajeros[], int tam); //recibe array t tmno
ePasajero ePasajero_CargarUnProducto();
int ePasajero_Baja(ePasajero listaDePasajeros[], int tam);
int ePasajero_ObtenerIndexLibre(ePasajero listaDePasajeros[], int TAM);
int ePasajero_BuscarIndexId(ePasajero listaDePasajeros[],int tam);
int ePasajero_Modificar(ePasajero listaDePasajeros[], int tam);
ePasajero ePasajero_modificarPasajero();


int ePasajero_imprimirTodosBaja(ePasajero listaDePasajeros[], int tam, int estado);
#endif /* LIBRERIATPDOS_H_ */
