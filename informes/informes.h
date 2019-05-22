#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "orquesta.h"
#include "instrumento.h"
#include "musico.h"
typedef struct
{
    int idOrquesta;
    int isEmpty;
    //-----------------
    char nombre[31];
    int tipo;
}OrquestaAuxiliar;

int informes_ordenarOrquestas(OrquestaAuxiliar array[],int size);
int informes_orquestaMenosMusicos(Musico* arrayMusicos, OrquestaAuxiliar arrayAux[], Orquesta* arrayOrquesta, int sizeArray);
int informes_initOrquestaAuxiliar(OrquestaAuxiliar arrayAux[], int sizeArray);
int instrumentosQueFueronSolicitadosPorOrquestaDeterminada(Musico* arrayMusicos, Orquesta* arrayOrquesta,Instrumento* arrayInstrumento, int limiteMusico, int limiteOrquesta, int limiteInstrumento);
int orquestasSegunLugar (Orquesta* arrayOrquesta, int limiteOrquesta);

int musicosQueNoSuperan25(Musico* arrayMusicos,int limiteMusicos,Instrumento* arrayInstrumento, int limiteInstrumento);
int promedio_cantidad_instrumentos_por_orquesta(Instrumento* arrayInstrumento, Orquesta* arrayOrquesta, int limiteInstrumento, int limiteOrquesta);
#endif // INFORMES_H_INCLUDED
