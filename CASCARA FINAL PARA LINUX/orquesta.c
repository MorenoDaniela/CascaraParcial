#ifndef ORQUESTA_C_INCLUDED
#define ORQUESTA_C_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "orquesta.h"
#include <stdio_ext.h>//para linux

#include "funciones.h"

#define TRIES 3

int orquesta_initStruct(Orquesta* arrayOrquesta, int limite)
{
    int retorno = -1;
    int i;
    if (arrayOrquesta!=NULL && limite>0)
    {
        for (i = 0; i < limite; i++)
        {
            arrayOrquesta[i].isEmpty = 1;
            retorno=0;
        }
    }
    return retorno;
}

int orquesta_findEmpty (Orquesta* arrayOrquesta,int limite, int* resultado)
{
    int retorno=-1;
    int i;
    if (arrayOrquesta!=NULL && limite>=0 && resultado!=NULL)
    {
        for (i=0;i<=limite;i++)
        {
            if (arrayOrquesta[i].isEmpty==1)
            {
                *resultado=i;
                retorno=0;
                break;
            }
            //retorno = 1;
        }
    }
    return retorno;
}

int orquesta_alta(Orquesta* arrayOrquesta,int *id, int limite)
{
    int auxTipo;
    int retorno=-1;
    int lugarVacio;
    __fpurge(stdin);
    //fflush(stdin);
    if (limite>0 && id!=NULL )
    {
        if(orquesta_findEmpty(arrayOrquesta,limite,&lugarVacio)!=-1)
        {
            if (
                getName("\nIngrese nombre de la orquesta: \n","Error, nombre no valido.\n",3,30,TRIES,arrayOrquesta[lugarVacio].nombre)==0 &&
                getString("\nIngrese lugar: \n","Error, lugar no valido.\n",3,30,TRIES,arrayOrquesta[lugarVacio].lugar)==0 &&
                getInt("Ingrese tipo de orquesta: 1-Sinfonica. 2-Filarmonica.3-Camara\n","Error, tipo de orquesta no valido\n",1,3,TRIES,&auxTipo)==0 )
            {
               arrayOrquesta[lugarVacio].idOrquesta=*id;
                (*id)++;
                arrayOrquesta[lugarVacio].tipo=auxTipo;
               arrayOrquesta[lugarVacio].isEmpty=0;
               printf("\nSe cargaron con exito los datos.\n");
               retorno=0;
            }else
                {
                    printf("\nNo se pudo cargar con exito.\n");
                }
        }else
        {
            printf("No hay espacio vacio.\n");
        }
    }
    return retorno;
}

void orquesta_print(Orquesta* arrayOrquesta, int limite)
{
    int i;
    for (i=0;i<=limite;i++)
    {
        if (arrayOrquesta[i].isEmpty==0)
        {
            printf ("\n********************************************");
            printf ("\nNombre de la orquesta: %s ",arrayOrquesta[i].nombre);
            printf ("\nLugar de la orquesta: %s ",arrayOrquesta[i].lugar);
            printf ("\nTipo de orquesta: %d",arrayOrquesta[i].tipo);
            printf ("\nId de la orquesta: %d ",arrayOrquesta[i].idOrquesta);
            printf ("\nPosicion: %d ",i);
            printf ("\nEstado : %d \n",arrayOrquesta[i].isEmpty);
        }
    }
}

int orquesta_findById(char* msj,Orquesta* arrayOrquesta,int* idEncontrado, int limite)
{
    int i;
    int retorno=1;
    int auxOrquesta;
    //revisar limite aca abajo
    if (msj!=NULL && arrayOrquesta !=NULL && idEncontrado!=NULL && limite>0)
    {
        if (getInt(msj,"\nOpcion no valida.\n",0,limite,TRIES,&auxOrquesta)==0)
        {
            for (i=0;i<=limite;i++)
            {
                if (arrayOrquesta[i].isEmpty==0)
                {
                    if (arrayOrquesta[i].idOrquesta == auxOrquesta)
                    {
                        retorno=0;
                        *idEncontrado=i;
                        break;
                    }
                }
            }
        }
    }
    return retorno;
}

int orquesta_baja(Orquesta* arrayOrquesta,int limite)
{
    int posicion;
    int retorno=-1;
    if (arrayOrquesta!=NULL && limite>0)
    {
        orquesta_print(arrayOrquesta,limite);
        switch (orquesta_findById("\nIngrese el id del orquesta a dar de baja: \n",arrayOrquesta,&posicion,limite))
        {
            case 0:
            if (arrayOrquesta[posicion].isEmpty==0)
            {
                arrayOrquesta[posicion].isEmpty=1;
                printf ("\nSe borro el id: %d \n",arrayOrquesta[posicion].idOrquesta);
                retorno=0;
            }
            break;
            case 1:
                printf ("\nNo se encontro el id.\n");
                break;
            default:
                printf ("\nNo encontro el id.\n");
                break;
        }
    }
    return retorno;
}

void harcodearOrquestas(Orquesta* arrayOrquesta, int limite)
{
    strcpy(arrayOrquesta[0].nombre,"BBB");
    strcpy(arrayOrquesta[0].lugar,"DDD");
    arrayOrquesta[0].isEmpty=0;
    arrayOrquesta[0].idOrquesta=1;
    arrayOrquesta[0].tipo=1;

    strcpy(arrayOrquesta[1].nombre,"BBB");
    strcpy(arrayOrquesta[1].lugar,"CCC");
    arrayOrquesta[1].isEmpty=0;
    arrayOrquesta[1].idOrquesta=3;
    arrayOrquesta[0].tipo=3;

    strcpy(arrayOrquesta[2].nombre,"CCC");
    strcpy(arrayOrquesta[2].lugar,"BBB");
    arrayOrquesta[2].isEmpty=0;
    arrayOrquesta[2].idOrquesta=5;
    arrayOrquesta[0].tipo=2;
}

/*
int musicos_modificar(Musico* arrayMusico,Orquesta* arrayOrquesta,int limiteOrquesta, int limiteMusico)
{
    int retorno=-1;
    int posicion;
    int opcion;
    int idOrquesta;
    int auxEdad;//
    if (arrayMusico!=NULL && limiteMusico>0 && limiteOrquesta>0 && arrayOrquesta!=NULL)
    {
        musicos_print(arrayMusico,limiteMusico);
        //musico_findById("Ingrese el id del autor a modificar",arrayMusico,&posicion,limite);
        //posicion=musico_getId(msj,arrayMusico,limite);
        if (musicos_findById("Ingrese el id del musico a modificar: \n",arrayMusico,&posicion,limiteMusico)==0)
        {
            while (opcion!=3)
            {
                getInt("\n1-Modificar edad.\n2-Modificar id de orquesta.\n3-Salir de modificacion.\n","Opcion no valida\n",1,3,TRIES,&opcion);
                system("cls");//
                //system("clear");
                fflush(stdin);
                //__fpurge(stdin);
                switch(opcion)
                {
                    case 1:
                    if (getInt("Ingrese nuevo edad: \n","Edad no valido.\n",18,200,TRIES,&auxEdad)==0)
                    {
                        arrayMusico[posicion].edad=auxEdad;
                        printf ("Modificacion con exito.\n");
                    }else
                        {
                            printf ("Modificacion sin exito.\n");
                        }
                    break;
                    case 2:
                    if (orquesta_findById("\nIngrese nuevo id del orquesta:\n",arrayOrquesta,&idOrquesta,limiteOrquesta)==0)
                    {
                        arrayMusico[posicion].idOrquesta=idOrquesta;
                        //strncpy(arrayMusico[posicion].apellido,&auxApellido,sizeof(auxApellido));
                        printf ("Modificacion con exito.\n");
                    }else
                        {
                            printf ("Modificacion sin exito.\n");
                        }
                        break;
                    case 3:
                        break;
                }//fin switch
            }
            retorno=0;//fin while
        }else
            printf("\nNo se encontro el id.\n");
    }
    return retorno;
}*/

#endif // ORQUESTA_C_INCLUDED
