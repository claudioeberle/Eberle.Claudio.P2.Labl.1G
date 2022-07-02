
#include"LinkedList.h"

#ifndef CONTROLLER_H_
#define CONTROLLER_H_


#include"controller.h"


#endif /* CONTROLLER_H_ */


int controller_loadPelisFromText(LinkedList* listado, char* path);
int controller_savePelisToText(LinkedList* listado, char* path);
int controller_listarPeliculas(LinkedList* listado);
LinkedList* controller_duracion(LinkedList* listado);
int controller_filtrarPorTipo(LinkedList* listado);
LinkedList* controller_mostrarDuraciones(LinkedList* listado);
