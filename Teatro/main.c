#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio_ext.h> //INCLUIR ENTIDADES NO OLVIDAR
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"
#include "informes.h"
#include "funciones.h"
#define SORT_UP 1
#define SORT_DOWN 0
#define TRIES 3
#define MAX_ORQUESTA 50
#define MAX_MUSICO 1000
#define MAX_INSTRUMENTO 20

int main()
{
    Orquesta orquestas [MAX_ORQUESTA];
    orquesta_initStruct(orquestas,MAX_ORQUESTA);
    int idOrquesta=1;
    int flagOrquesta=0;

    Musico musicos [MAX_MUSICO];
    musicos_initStruct(musicos,MAX_MUSICO);
    int idMusico=1;
    int flagMusico=0;

    Instrumento instrumentos[MAX_INSTRUMENTO];
    instrumento_initStruct(instrumentos,MAX_INSTRUMENTO);
    int idInstrumento=1;
    int flagInstrumento=0;

    int opcion;
    int opcionInformes;
    int aux;

    harcodearTODO(musicos,MAX_MUSICO,instrumentos,MAX_INSTRUMENTO,orquestas,MAX_ORQUESTA);

    flagOrquesta=1;
    flagMusico=1;
    flagInstrumento=1;

    while(opcion!=12)
    {
        getInt("\n**TEATRO**\n-ORQUESTAS-\n1-Alta de orquesta.\n2-Baja de Orquesta.\n3-Listar Orquestas.\n"
               "-MUSICOS-\n4-Alta de musico.\n5-Modificar musico.\n6-Baja de musico.\n7-Listar musico.\n"
               "INSTRUMENTOS-\n8-Alta instrumento.\n9-Baja instrumento.\n10-Listar instrumento.\n"
               "\n11-INFORMES\n\n12-Salir.\n","\nError, opcion invalida.\n",1,12,TRIES,&opcion);
        //system("clear");
        system("cls");
        switch(opcion)
        {
        case 1:
                if (orquesta_alta(orquestas,&idOrquesta,MAX_ORQUESTA)==0)
                    flagOrquesta++;
            break;
        case 2:
                if(flagOrquesta>0)
                {
                    if (orquesta_baja(orquestas,MAX_ORQUESTA,&aux)==0)
                    {
                        musicos_bajaPorOrquesta(musicos,MAX_MUSICO,aux);
                    }
                }else
                    printf("\nNo se puede dar de baja sin dar de alta.\n");
            break;
        case 3:
                if (flagOrquesta>0)
                {
                    orquesta_print(orquestas,MAX_ORQUESTA);
                }
                else
                    printf("\nNo hay lista.\n");
            break;
        case 4:
                if (flagOrquesta>0 && flagInstrumento>0)
                {
                    if(musicos_alta(musicos,orquestas,instrumentos,&idMusico,MAX_MUSICO,MAX_ORQUESTA,MAX_INSTRUMENTO)==0)
                    {
                        flagMusico++;
                    }
                }else
                    printf("\nNo se puede dar de alta un musico sin antes haber dado de alta al menos una orquesta y un instrumento.\n");
            break;
        case 5:
                if (flagMusico>0 && flagOrquesta>0 && flagInstrumento>0)
                {
                    musicos_modificar(musicos,orquestas,MAX_ORQUESTA,MAX_MUSICO);
                }else
                    printf("\nNo se puede modificar sin dar de alta.\n");
            break;
        case 6:
                if (flagMusico>0 && flagOrquesta>0 && flagInstrumento>0)
                {
                    musicos_baja(musicos,MAX_MUSICO);
                }else
                    printf("\nNo se puede dar de baja sin dar de alta.\n");
            break;
        case 7:
                if (flagMusico>0 && flagOrquesta>0 && flagInstrumento>0)
                {
                    musico_print(musicos,MAX_MUSICO,instrumentos,MAX_INSTRUMENTO);
                }else
                    printf("\nNo hay lista.\n");
            break;
        case 8:
                if(instrumento_alta(instrumentos,&idInstrumento,MAX_INSTRUMENTO)==0)
                {
                    flagInstrumento++;
                }
            break;
        case 9:
                if (flagInstrumento>0)
                {
                    instrumento_baja(instrumentos,MAX_INSTRUMENTO);
                }else
                    printf("\nNo se puede dar de baja sin dar de alta.\n");
            break;
        case 10:
                if (flagInstrumento>0)
                {
                    instrumento_print(instrumentos,MAX_INSTRUMENTO);

                }else
                    printf("\nNo hay lista.\n");
            break;
        case 11:
            do
            {
                getInt("\nINFORMES\n1-Cantidad de orquestas de cada tipo.\n2-Cantidad de instrumentos por tipo\n3-Cantidad de orquestas en total.\n"
                       "4-Cantidad de instrumentos en total.\n5-Cantidad musicos en total.\n6-Cantidad de orquestas de cada tipo y nombres.\n"
                       "7-Cantidad de instrumentos por tipo y nombres\n8-Promedio de la edad de los musicos de todas las orquestas.\n"
                       "9-Promedio cantidad de musicos por orquesta\n10-Musicos que usan un instrumento.\n"
                       "11-Musicos que componen una orquesta.\n12-Ordenar musicos por nombre y edad.\n\n15-Salir de informes\n","\nError, opcion invalida\n",1,15,TRIES,&opcionInformes);
                //system("clear");
                //__fpurge(stdin);
                system("cls");
                fflush(stdin);
                switch (opcionInformes)
                {
                    case 1://poner flags aca en los case
                        cantidad_tipos_orquesta(orquestas,MAX_ORQUESTA);
                        break;
                    case 2:
                        cantidad_tipos_instrumento(instrumentos,MAX_INSTRUMENTO);
                        break;
                    case 3:
                        cantidadOrquestas(orquestas,MAX_ORQUESTA);
                        break;
                    case 4:
                        cantidadInstrumentos(instrumentos,MAX_INSTRUMENTO);
                        break;
                    case 5:
                        cantidadMusicos(musicos,MAX_MUSICO);
                        break;
                    case 6:
                        cantidad_tipos_orquesta_y_nombres(orquestas,MAX_ORQUESTA);
                        break;
                    case 7:
                        cantidad_tipos_instrumento_y_nombres(instrumentos,MAX_INSTRUMENTO);
                        break;
                    case 8:
                        promedio_edad_musicos(musicos,MAX_MUSICO);
                        break;
                    case 9:
                        promedio_cantidad_musicos_por_orquesta(musicos,orquestas,MAX_MUSICO,MAX_ORQUESTA);
                        break;
                    case 10:
                        musicos_segun_instrumento(musicos,instrumentos,MAX_MUSICO,MAX_INSTRUMENTO);
                        break;
                    case 11:
                        musicos_segun_orquesta(musicos,orquestas,MAX_MUSICO,MAX_ORQUESTA);
                        break;
                    case 12:
                        musicos_ordenarDobleCriterio(musicos,MAX_MUSICO,SORT_DOWN,SORT_UP);
                        musicos_print(musicos,MAX_MUSICO);
                        break;
                    default:
                        printf ("Opcion invalida.\n");
                        break;
                }
            }while(opcionInformes!=15);
            break;
        }
    }
    return 0;
}
