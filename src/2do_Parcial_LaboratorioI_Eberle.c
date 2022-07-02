/*
 ============================================================================
 Name        : 2do_Parcial_LaboratorioI_Eberle.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "ioput.h"
#include "controller.h"
#include "movie.h"

int main() {

	setbuf(stdout,NULL);

	char salir = 'n';
	int opcion;

	LinkedList* listadoPeliculas = ll_newLinkedList();
	LinkedList* listadoAux = NULL;

	if(listadoPeliculas == NULL)
	{
		perror("No se ha conseguido memoria para iniciar el Programa\n");
		exit(1);
	}


	do
	{
		opcion = menu();

		switch(opcion)
		{
			case 1:

				controller_loadPelisFromText(listadoPeliculas, "movies.csv");
				break;

			case 2:

				controller_listarPeliculas(listadoPeliculas);
				break;

			case 3:

				listadoPeliculas = controller_duracion(listadoPeliculas);
				break;

			case 4:

				controller_filtrarPorTipo(listadoPeliculas);
				break;

			case 5:

				listadoAux = controller_mostrarDuraciones(listadoPeliculas);
				break;

			case 6:

				controller_savePelisToText(listadoAux, "movies.csv");
				break;

			case 7:
				ll_deleteLinkedList(listadoAux);
				ll_deleteLinkedList(listadoPeliculas);
				salir = 's';
				break;

		}

	}while(salir != 's');

	return 0;
}
