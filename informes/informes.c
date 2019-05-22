#ifndef INFORMES_C_INCLUDED
#define INFORMES_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>//para linux
#include "informes.h"
#include "musico.h"
#include "instrumento.h"
#include "orquesta.h"
#include "funciones.h"


int instrumentosQueFueronSolicitadosPorOrquestaDeterminada(Musico* arrayMusicos, Orquesta* arrayOrquesta,Instrumento* arrayInstrumento, int limiteMusico, int limiteOrquesta, int limiteInstrumento)
{
    int retorno=-1;
    int i;
    int auxId;
    int posicion;
    int contador=0;

    if (arrayOrquesta!=NULL && arrayMusicos!= NULL && arrayInstrumento!=NULL && limiteOrquesta>0 && limiteMusico>0 && limiteInstrumento>0)
    {
        orquesta_print(arrayOrquesta,limiteOrquesta);
        getInt("\nIngrese el id de la orquesta para saber que instrumentos solicito: \n","\nError, id no valido.\n",1,limiteOrquesta,3,&auxId);
        if (orquesta_buscarID(arrayOrquesta,limiteOrquesta,auxId,&posicion)==0)
        {
            for (i=0;i<=limiteMusico;i++)
            {
                if (arrayMusicos[i].isEmpty==1)
                continue;

                if (arrayMusicos[i].isEmpty==0)
                {
                    if (arrayMusicos[i].idOrquesta==auxId)
                    {
                        printf ("\nId de instrumento que solicito: %d. \n",arrayMusicos[i].idInstrumento);
                        printf ("Musico que lo toca: %s \n",arrayMusicos[i].nombre);
                        printf ("*************\n");
                        contador++;
                    }
                }
            }
            printf ("\nLa cantidad de instrumentos que solicito esta orquesta es: %d",contador);
            retorno=0;
        }else
            printf ("\nNo se encontro este id.\n");
    }
    return retorno;
}

int orquestasSegunLugar (Orquesta* arrayOrquesta, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    char auxLugar[50];
    //int posicion;

    if (arrayOrquesta!=NULL && limiteOrquesta>0)
    {
        //orquesta_print(arrayOrquesta,limiteOrquesta);
        getString("\nIngrese el nombre del lugar para saber si alguna orquesta se encuentra ahi: \n","\nError, id no valido.\n",5,50,3,auxLugar);
            for (i=0;i<=limiteOrquesta;i++)
            {
                if (arrayOrquesta[i].isEmpty==1)
                continue;

                if (arrayOrquesta[i].isEmpty==0)
                {
                    if (strcmp(arrayOrquesta[i].lugar,auxLugar)==0)
                    {
                        printf ("\nId de orquesta: %d. \n",arrayOrquesta[i].idOrquesta);
                        printf ("Nombre de orquesta: %s .\n",arrayOrquesta[i].nombre);
                        printf ("Tipo de orquesta: %d \n",arrayOrquesta[i].tipo);
                        printf ("Lugar de orquesta: %s \n",arrayOrquesta[i].lugar);
                    }
                }else
                        printf ("\nNo se encontro este lugar.\n");
           }
            retorno=0;
    }
    return retorno;
}


int musicosQueNoSuperan25(Musico* arrayMusicos,int limiteMusicos,Instrumento* arrayInstrumento, int limiteInstrumento)
{
    int retorno=-1;
    int i;
    int j;
    float edad=25;
    float musicosQueNoSuperan=0;

    if (arrayMusicos!=NULL && limiteMusicos>0)
    {

        for (i=0;i<=limiteMusicos;i++)
        {
            if (arrayMusicos[i].isEmpty==1)
                continue;
            if (arrayMusicos[i].isEmpty==0)
            {
                if (arrayMusicos[i].edad<edad)
                {
                    printf ("\nNombre del musico: %s \n",arrayMusicos[i].nombre);
                    printf ("Apellido del musico: %s\n",arrayMusicos[i].apellido);
                    printf ("Id musico: %d \n",arrayMusicos[i].idMusico);
                    printf ("Id instrumento %d \n",arrayMusicos[i].idInstrumento);
                    musicosQueNoSuperan++;

                    for (j=0;j<limiteInstrumento;j++)
                    {
                        if (arrayInstrumento[j].isEmpty==1)
                            continue;
                        if (arrayInstrumento[j].isEmpty==0)
                        {
                            if (arrayMusicos[i].idInstrumento==arrayInstrumento[j].idInstrumento)
                            {
                                printf ("Nombre del instrumento: %s\n",arrayInstrumento[j].nombre);
                            }
                        }
                    }
                }
            }
        }

        printf ("\nLa cantidad de musicos que no superan la edad 25 es: %2.f",musicosQueNoSuperan);
        //printf ("\nEl promedio de la edad de los musicos en todas las orquestas es: %2.f",promedio);
        retorno=0;
    }
    return retorno;
}

int promedio_cantidad_instrumentos_por_orquesta(Instrumento* arrayInstrumento, Orquesta* arrayOrquesta, int limiteInstrumento, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    int contadorInstrumento=0;
    int contadorOrquesta=0;
    float promedio=0;

    if (arrayInstrumento!=NULL && arrayOrquesta!=NULL && limiteInstrumento>0 && limiteOrquesta>0)
    {
        for (i=0;i<=limiteInstrumento;i++)
        {
            if (arrayInstrumento[i].isEmpty==1)
                continue;
            if (arrayInstrumento[i].isEmpty==0)
            {
                contadorInstrumento++;
            }
        }

        for (i=0;i<=limiteOrquesta;i++)
        {
            if (arrayOrquesta[i].isEmpty==1)
                continue;
            if (arrayOrquesta[i].isEmpty==0)
            {
                contadorOrquesta++;
            }
        }
        promedio=contadorInstrumento/contadorOrquesta;
        printf("\nEl promedio de instrumentos por orquesta es: %2.f",promedio);
        retorno=0;
    }
    return retorno;
}

int informes_ordenarOrquestas(OrquestaAuxiliar array[],int size)                              //cambiar musico
{
    int retorno=-1;
    int i;
    OrquestaAuxiliar buffer;
    int flagSwap;
    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for(i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].nombre,array[i+1].nombre) < 0)))
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

int informes_initOrquestaAuxiliar(OrquestaAuxiliar arrayAux[], int sizeArray)
{
    int retorno=-1;
    int i;
    for(i=0;i<sizeArray;i++)
    {
        arrayAux[i].isEmpty = 1;
        strcpy(arrayAux[i].nombre, " ");
    }
    retorno =0;
    return retorno;
}

int informes_orquestaMenosMusicos(Musico* arrayMusicos, OrquestaAuxiliar arrayAux[], Orquesta* arrayOrquesta, int sizeArray)
{
    int retorno=-1;
    int i,j;
    int posicionAuxiliar = 0;
    if(arrayMusicos!= NULL && sizeArray>=0 && arrayAux != NULL && arrayOrquesta!= NULL)
    {
        informes_initOrquestaAuxiliar(arrayAux, sizeArray);
        for(i=0;i<sizeArray;i++)
        {
            if(arrayMusicos[i].isEmpty==1)
                continue;
            else
            {
                arrayAux[posicionAuxiliar].idOrquesta = arrayMusicos[i].idOrquesta;
                arrayAux[posicionAuxiliar].isEmpty = 0;
                for(j=0;j<50;j++)
                {
                    if(arrayAux[posicionAuxiliar].idOrquesta == arrayOrquesta[j].idOrquesta)
                    {
                        strcpy (arrayAux[posicionAuxiliar].nombre, arrayOrquesta[j].nombre);
                        arrayAux[posicionAuxiliar].tipo = arrayOrquesta[j].tipo;
                        break;
                    }
                }
                posicionAuxiliar++;
            }
        }
        retorno =0;
    }
    informes_ordenarOrquestas(arrayAux, sizeArray);
    int contadorSeguidos = 0;
    int contadorAuxiliar = 0;
    char nombreRepetido[20];
    char nombreSeguido[20];
    int tipoSeguido;
    for(i=0;i<sizeArray;i++)
    {
        if(i==0)
        {
            strncpy(nombreRepetido, arrayAux[i].nombre, 20);
            contadorAuxiliar = 1;
            continue;
        }
        if(!strncmp(nombreRepetido, arrayAux[i].nombre, 20))
        {
            contadorAuxiliar++;
        }else{
            if(contadorAuxiliar>contadorSeguidos)
            {
                contadorSeguidos = contadorAuxiliar;
                strncpy(nombreSeguido, arrayAux[i-1].nombre, 20);
                tipoSeguido = arrayAux[i-1].tipo;
            }
            contadorAuxiliar = 0;
            strncpy(nombreRepetido, arrayAux[i].nombre, 20);
        }
        if(arrayAux[i].isEmpty == 1)
        {
            break; //Se hace break porque se sabe que todos estarán llenos hasta llegar a un isEmpty.
        }
    }
    printf("La orquesta con mas musicos es %s, y es de tipo %d, y tiene %d musicos.", nombreSeguido, tipoSeguido, contadorSeguidos);
    return retorno;
}

/*
int musicosNoViento (Musico* arrayMusico, Instrumento* arrayInstrumento, int limiteMusico, int limiteInstrumento)
{
    int i;
    int retorno=-1;

    if (arrayMusico!=NULL && arrayInstrumento!=NULL && limiteMusico>0 && limiteInstrumento>0)
    {

    }
}*/


#endif // INFORMES_C_INCLUDED
