

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"controller.h"
#include"LinkedList.h"
#include"parser.h"


int controller_loadPelisFromText(LinkedList* listado, char* path)
{
	int retorno = 0;

	if(listado != NULL && path != NULL)
	{
		FILE* file = fopen(path, "r");

		if(file == NULL)
		{
			perror("No se ha podido leer el archivo de texto de peliculas\n");
		}
		else
		{
			if(parser_pelisFromText(file, listado))
			{
				retorno = 1;
			}
		}
		fclose(file);
	}
	return retorno;
}

int controller_savePelisToText(LinkedList* listado, char* path)
{
	int retorno = 0;

	if(listado != NULL && path != NULL)
	{
		FILE* pFile = fopen(path, "w");

		if(pFile == NULL)
		{
			printf("No se pudo crear/abrir el archivo de texto de peliculas\n");
		}
		else
		{
			parser_pelisToText(pFile, listado);
		}
	}
	return retorno;

}

int controller_listarPeliculas(LinkedList* listado)
{
	int retorno = 0;
	eMovie* peli = NULL;
	int tam;

	if(listado != NULL)
	{
		tam = ll_len(listado);

		if(tam)
		{
			system("clear");
			printf("LISTADO DE PELICULAS\n");
			printf("-----------------------------------------------------------------------------\n");
			printf("  ID    TITULO                          GENERO             DURACION\n");
			printf("-----------------------------------------------------------------------------\n");

			for(int i = 0; i < tam; i++)
			{
				peli = ll_get(listado, i);

				mostrarPeliculaFila(peli);
			}
		}
		else
		{
			system("clear");
			printf("\nNo hay elementos para mostrar en el Sistema\n");
		}
		retorno = 1;
	}
	return retorno;
}

LinkedList* controller_duracion(LinkedList* listado)
{
	LinkedList* aux = NULL;

	if(listado != NULL)
	{

		aux = ll_map(listado, (void*)duracion);

		if(listado != NULL)
		{
			printf("Se actualizaron las duraciones de las peliculas\n");
		}

	}
	return aux;
}

int controller_filtrarPorTipo(LinkedList* listado)
{
	int retorno = 0;
	int idGenero;
	char path[50];
	LinkedList* listadoAux = NULL;


	if(listado != NULL)
	{
		printf("ID      GENERO\n");
		printf("--------------------\n");
		printf("1      Comedy\n");
		printf("2      Drama\n");
		printf("3      Documentary\n");
		printf("4      Animation\n");
		printf("5      Adventure\n");
		printf("6      Musical\n");
		printf("7      Horror\n");
		get_int("Por favor elija el id del genero: ", "Dato Incorrecto\n", 1, 7, &idGenero);

		switch(idGenero)
		{
			case 1:
				listadoAux = ll_filter(listado, (void*)filtroComedy);
				break;
			case 2:
				listadoAux = ll_filter(listado, (void*)filtroDrama);
				break;
			case 3:
				listadoAux = ll_filter(listado, (void*)filtroDocumentary);
				break;
			case 4:
				listadoAux = ll_filter(listado, (void*)filtroAnimation);
				break;
			case 5:
				listadoAux = ll_filter(listado, (void*)filtroAdventure);
				break;
			case 6:
				listadoAux = ll_filter(listado, (void*)filtroMusical);
				break;
			case 7:
				listadoAux = ll_filter(listado, (void*)filtroHorror);
				break;
		}

		cargaPath(path, 50, "Ingrese el nombre de nuevo archivo: ", "Dato Incorrecto");

		controller_savePelisToText(listadoAux, path);

		if(listadoAux != NULL)
		{
			retorno = 1;
		}

	}
	return retorno;
}

LinkedList* controller_mostrarDuraciones(LinkedList* listado)
{
	LinkedList* listadoAux = NULL;

	if(listado != NULL)
	{
		listadoAux = ll_clone(listado);

		if(listadoAux != NULL)
		{
			ll_sort(listadoAux, ordenarPorDuracion, 0);
			ll_sort(listadoAux, ordenarPorGenero, 1);
		}

		controller_listarPeliculas(listadoAux);
	}
	return listadoAux;
}
