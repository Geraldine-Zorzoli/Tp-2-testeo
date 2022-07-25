/*
 * MiLibreria.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Geraldine
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LibreriaTpDos.h"

static int ePasajero_ObtenerIdUnico(void);
static int ePasajero_ObtenerIdUnico(){
	static int idIncremental = 1;
	ThePassenger.id =idIncremental;

	return idIncremental++;
}


int myGets(char* cadena, int longitud){
	/*scanf("%s",buffer); NO ES SEGURO , HAY QUE ELIMINARLO NO CONTROLA CUANDO DESBORDAN EL LIMITE DE LONG
		fgets(cadena, longitud, stdin)
		cadena[strlen(cadena) - 1] = '\0';
		return 0;
		EN LA CLASE 8 DE YOUTUBE SE HIZO LA MISMA FUNCION*/
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
        fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString),stdin) != NULL)
		{
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
			}
		if(strnlen(bufferString, sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena, bufferString, longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
	}


int ePasajero_BuscadorEspacioLibre(ePasajero listaDePasajeros[],int tam){
	int rtn = 0;
	int flag = 0;
	int i;

	if (listaDePasajeros != NULL) {
		if (tam > 0) {
			//ESTA OK
			for (i = 0; i < tam; i++) {
				if (listaDePasajeros[i].isEmpty == LIBRE) {
					flag = 1;
					rtn = i;
					break;
				}
			}

			if (flag == 0) {
				rtn = -1;
			}
		} else {
			rtn = -2;
		}
	} else {
		rtn = -3;
	}

	return rtn;
}

int ePasajero_ObtenerIndexLibre(ePasajero listaDePasajeros[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (listaDePasajeros != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (listaDePasajeros[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}


int getInt(char mensaje[], int reintentos, int minimo, int maximo,char mensajeError[], int *pNumeroIngresado) {
	int retorno = -1;
	int auxiliarInt;
	int retornoScanf;

	if (mensaje != NULL && minimo < maximo && mensajeError != NULL
			&& pNumeroIngresado != NULL && reintentos > 0) {
		printf("%s", mensaje);
		retornoScanf = scanf("%d", &auxiliarInt);
	}
	do {
		//printf("\n Quedan : %d reintentos \n",reintentos);
		if (retornoScanf != 1 || auxiliarInt > maximo || auxiliarInt < minimo) {
			printf("%s", mensajeError);
			retornoScanf = scanf("%d", &auxiliarInt);
			reintentos--;
		} else {
			reintentos = 0;
			*pNumeroIngresado = auxiliarInt;
			retorno = 0;
		}

	} while (reintentos > 0);

	return retorno;
}

ePasajero ePasajero_CargarUnProducto(){

	ePasajero ThePassenger;

	//Validacion nombre completo

	printf("Ingrese su nombre");
	scanf("%s",ThePassenger.name);
	//myGets(name,51);
	printf("Ingrese su apellido");
	myGets(ThePassenger.lastname,51);

	//Validacion fecha de nacimiento
	getInt("ingrese su dia de nacimiento",3,1,31, "Error, dato ingresado no valido",&ThePassenger.dia);
	getInt("ingrese su mes de nacimiento",3,1,12, "Error, dato ingresado no valido",&ThePassenger.mes);
	getInt("ingrese su año de nacimiento",3,1900,3000, "Error, dato ingresado no valido",&ThePassenger.anio);
	return ThePassenger;
}

int ePasajero_inicializar(ePasajero listaDePasajeros[], int tam){
	int rtn=0;
	int i;

	if(listaDePasajeros != NULL){
		if( tam > 0){//ESTA TODO BIEN si es asi recorremos todo el array
		for(i=0; i>tam; i++){//3
			listaDePasajeros[i].isEmpty = LIBRE; //LE ASIGNO EL VALOR LIBRE A TODOS LOS CASILLEROS
			}
		}else{
		 rtn = -2;
				}
			}else{
				rtn = -1;
			}
			return rtn;
	}
void ePasajero_imprimirUno(ePasajero ThePassenger) {
	printf("ID : %d \n"
			"Nombre: %s \nApellido: %s \n", ThePassenger.id, ThePassenger.name,ThePassenger.lastname);
}


int ePasajero_alta(ePasajero listaDePasajeros[], int tam){
		int rtn=0;
		int indexLibre;
		ePasajero auxiliarPasajero; //para que no sobreescriba el original
		//retorna un index libre si encontro o un -1 si no encontro
		indexLibre = ePasajero_BuscadorEspacioLibre(listaDePasajeros, tam);//1ro busca espacio libre si encuentra pasa al if


		if(listaDePasajeros != NULL){
			if (tam > 0){
			//ESTA  BIEN si es asi recorremos el array
					if(indexLibre>=0){
						//DATOS NO GENERICOS
						auxiliarPasajero = ePasajero_CargarUnProducto();
						//CAMBIO A ESTADO OCUPADO
						auxiliarPasajero.id = ePasajero_ObtenerIdUnico();
						auxiliarPasajero.isEmpty = OCUPADO;

						//Si esta seguro
						listaDePasajeros[indexLibre] = auxiliarPasajero; //COPIA AUXILIAR A
						rtn=indexLibre;

					}else{
						//ARRAY LLENO
						rtn = -3;
						}
					} else {
						//LEN MAL DEFINIDO
					rtn = -2;
					}
				} else {
					//array nulo
					rtn = -1;
				}
				return rtn;
	}
//FUNCION NUEVA , VERIFICAR
int ePasajero_Baja(ePasajero listaDePasajeros[], int tam) {
	int rtn = 0;
	int indexBaja;

	if (listaDePasajeros != NULL) {
		if (tam > 0) {
			//ESTA  BIEN si es asi recorremos el array
			//if(indexBaja>=0)
			{
				indexBaja = ePasajero_BuscarIndexId(listaDePasajeros, tam);
				if (indexBaja < 0) {
					puts("No existe el id seleccionado");
					rtn = -1;
				} else {
					//SIGNIFICA QUE ENCONTRO EL ID
					listaDePasajeros[indexBaja].isEmpty = BAJA;
				}
			}
		}else {
			//ARRAY LLENO
			rtn = -3;
		}
	} else {
		//LEN MAL DEFINIDO
		rtn = -2;
	}
	return rtn;
}


int ePasajero_imprimirTodos(ePasajero listaDePasajeros[], int tam, int estado) {
	int rtn = 1;
	int i;

	if (listaDePasajeros != NULL) {
		if (tam > 0) {
			//ESTA TODO BIEN
			for (i = 0; i < tam; i++) {
				if (listaDePasajeros[i].isEmpty == OCUPADO) { //CAMBIE "ESTADO" A OCUPADO
					ePasajero_imprimirUno(listaDePasajeros[i]);
				}
			}
		} else {
			rtn = -2;
		}
	} else {
		rtn = -1;
	}

	return rtn;

}


int ePasajero_Modificar(ePasajero listaDePasajeros[], int tam) {
	int rtn = 0;
	int indexModificacion;
	ePasajero auxiliarPasajero; //hay que declararlo puntero

	//listaDePasajeros = auxiliarPasajero; //para que no sobreescrirla

	if (listaDePasajeros != NULL) {
		if (tam > 0) {
			//BUSCA UN INDEX POR ID - RETORNA -1 SI NO ENCUENTRA EL ID EN EL ARRAY
			indexModificacion = ePasajero_BuscarIndexId(listaDePasajeros,tam);
			if (indexModificacion < 0) {
				puts("HUBO UN ERROR BUSCANDO EL INDEX");
				rtn = -1;
			} else {
				auxiliarPasajero = listaDePasajeros[indexModificacion]; //Si el auxiliar es = index entonces modifico
				//MODIFICAR UN PRODUCTO
				auxiliarPasajero = ePasajero_modificarPasajero(auxiliarPasajero);
				//EXTRA - PREGUNTO SI DESEA CONFIRMAR - REEMPLAZO LA COPIA POR EL ORIGINAL
				listaDePasajeros[indexModificacion] = auxiliarPasajero;
			}

		} else {
			// LEN MAL DEFINIDO
			rtn = -2;
		}
	} else {
		// ARRAY NULO
		rtn = -3;
	}

	return rtn;
}



int ePasajero_BuscarIndexId(ePasajero listaDePasajeros[], int tam) {
	int rtn = 0;
	int flag = 0;
	int i;
	int buscarId;
	int idBusqueda;

	if (listaDePasajeros != NULL) {
		if (tam > 0) {

			//significa que al menos hay algo cargado

			ePasajero_imprimirTodos(listaDePasajeros, tam, OCUPADO);
			//IMPRIME LISTA DE OCUPADOS

			//PEDIR UN ID
			buscarId = getInt("Ingrese id a modificar", 3, 0, tam,"Dato ingresado no valido", &idBusqueda);

			for (i = 0; i < tam; i++) {
				if (listaDePasajeros[i].isEmpty == OCUPADO) {
					if (listaDePasajeros[i].id == idBusqueda) {
						flag = 1;
						rtn = buscarId; //retorno index del id que estoy buscando
						break;
					}
				}

			}
			if (flag == 0) {
				rtn = -1;
			}
		} else {
			rtn = -2;
		}
	} else {
		rtn = -3;
	}
	return rtn;
}

ePasajero ePasajero_modificarPasajero(ePasajero ThePassenger){
	int opcion;
	getInt("1) Nombre 2) Apellido \n",3,0,2,"Dato ingresado no valido",&opcion);

	switch(opcion)
	{

		case 1:
			puts("Ingrese nombre");
			myGets(ThePassenger.name,51);

			break;
		case 2:
			puts("Ingrese apellido");
			myGets(ThePassenger.lastname,51);
			break;

	}
	return ThePassenger;
}



int ePasajero_imprimirTodosBaja(ePasajero listaDePasajeros[], int tam, int estado) {
	int rtn = 1;
	int i;

	if (listaDePasajeros != NULL) {
		if (tam > 0) {
			//ESTA TODO BIEN
			for (i = 0; i < tam; i++) {
				if (listaDePasajeros[i].isEmpty == BAJA) { //CAMBIE "ESTADO" A OCUPADO
					ePasajero_imprimirUno(listaDePasajeros[i]);
				}
			}
		} else {
			rtn = -2;
		}
	} else {
		rtn = -1;
	}

	return rtn;

}

