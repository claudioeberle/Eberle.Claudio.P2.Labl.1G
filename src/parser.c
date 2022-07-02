

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "movie.h"

int parser_pelisFromText(FILE* pFile, LinkedList* listado)
{
	int retorno = 0;
	int cant = 0;

	char buffer[4][100];
	char falsaLectura[1000];

	//id_peli, titulo, genero, duracion

	if(pFile != NULL && listado != NULL)
	{
		eMovie* peli = NULL;

		fscanf(pFile, "%s", falsaLectura);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

			peli = pelicula_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

			if(peli == NULL)
			{
				printf("falló la carga de la pelicula con id: %s\n", buffer[0]);
			}
			else
			{
				ll_add(listado, peli);
				cant++;
				retorno = 1;
			}
		}
		system("clear");
		printf("\n Se agregaron %d peliculas al Sistema\n", cant);
	}
	return retorno;
}


int parser_pelisToText(FILE* pFile, LinkedList* listado)
{
	int retorno = 0;
	char buffer[4][50];
	char header[]= "id_peli,titulo,genero,duracion\n";
	eMovie* peli = NULL;
	int tam;
	int cant = 0;

	if(pFile != NULL && listado != NULL)
	{
		fprintf(pFile, "%s", header);

		tam = ll_len(listado);

		for( int i = 0; i < tam; i++)
		{
			peli = (eMovie*)ll_get(listado, i);

			if( getIdPeliculaStr(peli, buffer[0])&&
				getTituloPelicula(peli, buffer[1]) &&
				getGeneroPelicula(peli, buffer[2]) &&
				getDuracionPeliculaStr(peli, buffer[3]))
			{

				fprintf(pFile, "%s,%s,%s,%s\n",buffer[0],
											   buffer[1],
											   buffer[2],
											   buffer[3]);
				cant++;
			}
			/*
			printf("%s\n", buffer[0]);
			printf("%s\n", buffer[1]);
			printf("%s\n", buffer[2]);
			printf("%s\n", buffer[3]);
			*/

		}
		system("clear");
		printf("\n Se guardaron %d peliculas en archivo\n", cant);
	}
	return retorno;
}
