#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

//#include "musico.h"
#include "instrumento.h"
#include "orquesta.h"

typedef struct
{
    int idMusico;
    int idOrquesta;
    int idInstrumento;
    char nombre[31];
    char apellido[31];
    int edad;
    int isEmpty;//estado habilitado 0 no habilitado 1
}Musico;

int musicos_baja(Musico* arrayMusico,int limite);
int musicos_initStruct(Musico* arrayMusico, int limite);
int musicos_findEmpty (Musico* arrayMusico,int limite, int* resultado);

int musicos_alta(Musico* arrayMusico, Orquesta* arrayOrquesta,Instrumento* arrayInstrumento,int *id,int limiteMusico,int limiteOrquesta, int limiteInstrumento);
//int musico_alta(Musico* arrayMusico, Orquesta* arrayOrquesta, int* id, int limite);
void musicos_print(Musico* arrayMusico, int limite);
int musicos_findById(char* msj,Musico* arrayMusico,int* idEncontrado, int limite);
void harcodearMusicos(Musico* arrayA, int limite);
int musicos_modificar(Musico* arrayMusico,Orquesta* arrayOrquesta,int limiteOrquesta, int limiteMusico);

#endif // MUSICO_H_INCLUDED
