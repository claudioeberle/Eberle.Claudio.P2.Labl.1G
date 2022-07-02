
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "movie.h"
#include "ioput.h"

eMovie* pelicula_new(void)
{
	eMovie* nuevaPelicula = NULL;

	nuevaPelicula = (eMovie*)malloc(sizeof(eMovie));

	if(nuevaPelicula != NULL)
	{
		nuevaPelicula->idPeli = 0;
		strcpy(nuevaPelicula->titulo, "");
		strcpy(nuevaPelicula->genero, "");
		nuevaPelicula->duracion = 0;
	}
	return nuevaPelicula;
}


eMovie* pelicula_newParametros(char* idPeli, char* titulo, char* genero, char* duracion)
{
	eMovie* nuevaPeli = NULL;


	if(idPeli != NULL && titulo != NULL && genero != NULL && duracion != NULL )
	{
		nuevaPeli = pelicula_new();

		if(nuevaPeli == NULL)
		{
			perror("No se consiguió memoria para el alta de pelicula\n");
		}
		else
		{
			if( !( setIdPelicula(nuevaPeli, atoi(idPeli)) &&
					setTituloPelicula(nuevaPeli, titulo) &&
					setGeneroPelicula(nuevaPeli, genero) &&
					setDuracionPelicula(nuevaPeli, atoi(duracion))))
			{
				perror("No se consiguió cargar los datos de la pelicula\n");
				free(nuevaPeli);
				nuevaPeli = NULL;
			}

		}
	}
	return nuevaPeli;
}

/**********************************************************************************/

int mostrarPeliculaFila(eMovie* peli)
{
	int retorno = 0;

	if(peli != NULL)
	{
		printf("%02d   %-30s   %-15s        %d\n", peli->idPeli, peli->titulo, peli->genero, peli->duracion);

		retorno = 1;
	}
	return retorno;
}

/**********************************************************************************/


int setIdPelicula(eMovie* peli, int idPeli)
{
	int retorno = 0;
	if(peli != NULL)
	{
		peli->idPeli = idPeli;
		retorno = 1;
	}
	return retorno;
}

int setTituloPelicula(eMovie* peli, char* titulo)
{
	int retorno = 0;
	if(peli != NULL && titulo != NULL)
	{
		strcpy(peli->titulo, titulo);
		retorno = 1;
	}
	return retorno;
}

int setGeneroPelicula(eMovie* peli, char* genero)
{
	int retorno = 0;
	if(peli != NULL && genero != NULL)
	{
		strcpy(peli->genero, genero);
		retorno = 1;
	}
	return retorno;
}

int setDuracionPelicula(eMovie* peli, int duracion)
{
	int retorno = 0;
	if(peli != NULL)
	{
		peli->duracion = duracion;
		retorno = 1;
	}
	return retorno;
}


/**********************************************************************************/


int getIdPelicula(eMovie* peli, int* idPeli)
{
	int retorno = 0;
	if(peli != NULL)
	{
		*idPeli = peli->idPeli;
		retorno = 1;
	}
	return retorno;
}

int getTituloPelicula(eMovie* peli, char* titulo)
{
	int retorno = 0;
	if(peli != NULL && titulo != NULL)
	{
		strcpy(titulo, peli->titulo);
		retorno = 1;
	}
	return retorno;
}

int getGeneroPelicula(eMovie* peli, char* genero)
{
	int retorno = 0;
	if(peli != NULL && genero != NULL)
	{
		strcpy(genero, peli->genero);
		retorno = 1;
	}
	return retorno;
}

int getDuracionPelicula(eMovie* peli, int* duracion)
{
	int retorno = 0;
	if(peli != NULL)
	{
		*duracion = peli->duracion;
		retorno = 1;
	}
	return retorno;
}

/**********************************************************************************/

int getIdPeliculaStr(eMovie* peli, char* idPeli)
{
	int retorno = 0;
	int aux = 0;

	if(peli != NULL && idPeli != NULL)
	{
		getIdPelicula(peli, &aux);
		sprintf(idPeli, "%d", aux);
		retorno = 1;
	}
	return retorno;
}

int getDuracionPeliculaStr(eMovie* peli, char* duracion)
{
	int retorno = 0;
	int aux = 0;

	if(peli != NULL && duracion != NULL)
	{
		getDuracionPelicula(peli, &aux);
		sprintf(duracion, "%d", aux);
		retorno = 1;
	}
	return retorno;
}

/**********************************************************************************/


void* duracion(eMovie* peli)
{
	int retorno = 0;

	if(peli != NULL)
	{
		peli->duracion = randomNumber(100, 240);
		retorno = 1;
	}
	return peli;
}


int filtroComedy(eMovie* element)
{
	int retorno = 0;

	if(strcmp(element->genero, "Comedy") == 0)
	{
		retorno = 1;
	}
	return retorno;
}

int filtroDrama(eMovie* element)
{
	int retorno = 0;

	if(strcmp(element->genero, "Drama") == 0)
	{
		retorno = 1;
	}
	return retorno;
}

int filtroDocumentary(eMovie* element)
{
	int retorno = 0;

	if(strcmp(element->genero, "Documentary") == 0)
	{
		retorno = 1;
	}
	return retorno;
}

int filtroAnimation(eMovie* element)
{
	int retorno = 0;

	if(strcmp(element->genero, "Animation") == 0)
	{
		retorno = 1;
	}
	return retorno;
}

int filtroAdventure(eMovie* element)
{
	int retorno = 0;

	if(strcmp(element->genero, "Adventure") == 0)
	{
		retorno = 1;
	}
	return retorno;
}

int filtroMusical(eMovie* element)
{
	int retorno = 0;

	if(strcmp(element->genero, "Musical") == 0)
	{
		retorno = 1;
	}
	return retorno;
}

int filtroHorror(eMovie* element)
{
	int retorno = 0;

	if(strcmp(element->genero, "Horror") == 0)
	{
		retorno = 1;
	}
	return retorno;
}

int ordenarPorGenero(void* a, void* b)
{
	int retorno = 0;

	if(a != NULL && b != NULL)
	{
		eMovie* peli1 = (eMovie*)a;
		eMovie* peli2 = (eMovie*)b;

		if(strcmp(peli1->genero, peli2->genero) == 0)
		{
			retorno = 0;
		}
		else if(strcmp(peli1->genero, peli2->genero) > 0)
		{
			retorno = 1;
		}
		else
		{
			retorno = -1;
		}

	}
	return retorno;
}

int ordenarPorDuracion(void* a, void* b)
{
	int retorno = 0;

	if(a != NULL && b != NULL)
	{
		eMovie* peli1 = (eMovie*)a;
		eMovie* peli2 = (eMovie*)b;

		if(peli1->duracion == peli2->duracion)
		{
			retorno = 0;
		}
		else if(peli1->duracion > peli2->duracion)
		{
			retorno = 1;
		}
		else
		{
			retorno = -1;
		}
	}
	return retorno;
}
