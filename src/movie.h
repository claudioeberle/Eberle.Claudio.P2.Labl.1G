

#ifndef MOVIE_H_
#define MOVIE_H_

typedef struct{

	int idPeli;
	char titulo[30];
	char genero[30];
	int duracion;

}eMovie;

#endif /* MOVIE_H_ */


eMovie* pelicula_new(void);
eMovie* pelicula_newParametros(char* idPeli, char* titulo, char* genero, char* duracion);

int mostrarPeliculaFila(eMovie* peli);

int setIdPelicula(eMovie* peli, int idPeli);
int setTituloPelicula(eMovie* peli, char* titulo);
int setGeneroPelicula(eMovie* peli, char* genero);
int setDuracionPelicula(eMovie* peli, int duracion);

int getIdPelicula(eMovie* peli, int* idPeli);
int getTituloPelicula(eMovie* peli, char* titulo);
int getGeneroPelicula(eMovie* peli, char* genero);
int getDuracionPelicula(eMovie* peli, int* duracion);

int getIdPeliculaStr(eMovie* peli, char* idPeli);
int getDuracionPeliculaStr(eMovie* peli, char* duracion);

void* duracion(eMovie* peli);

int filtroComedy(eMovie* element);
int filtroDrama(eMovie* element);
int filtroDocumentary(eMovie* element);
int filtroAnimation(eMovie* element);
int filtroAdventure(eMovie* element);
int filtroMusical(eMovie* element);
int filtroHorror(eMovie* element);

int ordenarPorGenero(void* a, void* b);
int ordenarPorDuracion(void* a, void* b);
