/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Geraldine
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LibreriaTpDos.h"
#define MAX_PASAJEROS 2000
#define tam 20

int main() {
	setbuf(stdout,NULL);
	ePasajero listaDePasajeros[MAX_PASAJEROS];
	ePasajero_inicializar(listaDePasajeros, MAX_PASAJEROS);

	int opcion;

	do{
		getInt("\n *******Bienvenido!******* \n Seleccione una de las siguientes opciones"
				"\n 1) ALTA \n 2)MODIFICACION \n 3) BAJA \n 4)INFORMAR",3,0,4, "Error,dato ingresado no valido",&opcion);
		switch(opcion){
			case 1:

				ePasajero_inicializar(listaDePasajeros, MAX_PASAJEROS);
				ePasajero_BuscadorEspacioLibre(listaDePasajeros, tam);
				ePasajero listaDePasajeros[MAX_PASAJEROS];
				ePasajero_alta(listaDePasajeros,20);

				/*printf("Ingrese su nombre");
				scanf("%s",ThePassenger.name);
				//myGets(name,51);
				printf("Ingrese su apellido");
				myGets(ThePassenger.lastname,51);*/
				//FUNCION DE ALTA PIDE LOS DATOS DE VALIDACION

				break;
			case 2:
				//printf("Seleccione usuario a modificar \n");
				//ePasajero_imprimirTodos(listaDePasajeros,tam,OCUPADO);
				ePasajero_BuscarIndexId(listaDePasajeros,tam);
				ePasajero_Modificar(listaDePasajeros,tam);
				break;
			case 3:
				puts("Seleccione un id para dar de baja: ");
				//ePasajero_imprimirTodos(listaDePasajeros,tam,OCUPADO);
				//ePasajero_BuscarIndexId(listaDePasajeros,tam);
				ePasajero_Baja(listaDePasajeros, tam);
				break;
			case 4:

				//printf("este es el id %d",ThePassenger.id);
				//ePasajero_imprimirUno(ThePassenger);
				ePasajero_imprimirTodos(listaDePasajeros,tam,OCUPADO);
				puts("Ids dados de baja");
				ePasajero_imprimirTodosBaja(listaDePasajeros,tam,BAJA);

				break;

			}

		}while(opcion!=5);

	return 0;
}
