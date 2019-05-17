#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h> //INCLUIR ENTIDADES NO OLVIDAR

#include "orquesta.h"

#include "musico.h"

#include "instrumento.h"

//#include "fantasma.h"
#include "funciones.h"

#define TRIES 3
#define MAX_ORQUESTA 50
#define MAX_MUSICO 1000
#define MAX_INSTRUMENTO 20
//#define MAX_ESTRUCTURACUATRO 10

int main()
{

    Orquesta orquestas [MAX_ORQUESTA];//MODIFICAR ACA TODO
    Musico musicos [MAX_MUSICO];//
    Instrumento instrumentos[MAX_INSTRUMENTO];//
    //Prestamo STRUCT_CUATRO[MAX_ESTRUCTURACUATRO];//

    //menu principal
    int opcion;
    //flagspara menus
    int flagOrquesta=0;
    int flagMusico=0;
    int flagInstrumento=0;
    //int flagCuatro=0;
    //submenus
    int opcionOrquesta;
    int opcionMusico;
    int opcionInstrumento;
    //int opcionCuatro;
    //ids de 4 struct
    int idOrquesta=0;
    int idMusico=0;
    int idInstrumento=0;
    //int idCuatro=0;


    orquesta_initStruct(orquestas,MAX_ORQUESTA);

    musicos_initStruct(musicos,MAX_MUSICO);

    instrumento_initStruct(instrumentos,MAX_INSTRUMENTO);

    //cuatro_initStruct(STRUCT_CUATRO,MAX_ESTRUCTURACUATRO);

    harcodearOrquestas(orquestas,MAX_ORQUESTA);

    harcodearMusicos(musicos,MAX_MUSICO);
    harcodearInstrumento(instrumentos,MAX_INSTRUMENTO);


    //harcodearSTRUCT_CUATRO(STRUCT_CUATRO,MAX_ESTRUCTURACUATRO);

    flagOrquesta=1;
    flagMusico=1;
    flagInstrumento=1;
    //flagCuatro=1;

    while(opcion!=4)
    {
        getInt("\n**TEATRO**\n1-Orquestas.\n2-Musicos.\n3-Instrumentos.\n\n4-Salir.\n","\nError, opcion invalida.\n",1,4,TRIES,&opcion);
        system("clear");
        //system("cls");//
        switch(opcion)
        {
        case 1:
            do
            {
                getInt("\n ORQUESTAS.\n1-Alta.\n2-Baja.\n3-Listar.\n4-Salir.\n","Error, opcion incorrecta.\n",1,4,TRIES,&opcionOrquesta);
                system("clear");
                __fpurge(stdin);
                //system("cls");
                //fflush(stdin);
                switch (opcionOrquesta)
                {
                case 1:
                    if (orquesta_alta(orquestas,&idOrquesta,MAX_ORQUESTA)==0)
                    {
                        flagOrquesta++;
                    }
                    break;
                case 2:
                    if(flagOrquesta>0)
                    {
                        orquesta_baja(orquestas,MAX_ORQUESTA);
                    }else
                        printf("\nNo se puede dar de baja sin dar de alta.\n");
                    break;
                case 3:
                    if (flagOrquesta>0)
                    {
                        //orquesta_ordenarDobleCadena(orquestas,MAX_ORQUESTA);
                        orquesta_print(orquestas,MAX_ORQUESTA);
                    }
                    else
                        printf("\nNo hay lista.\n");
                    break;
                case 4:
                    break;
                }
            }while (opcionOrquesta!=4);//fin orquesta cambiar si opciones son menos, mirar getint
            break;
        case 2:
            do
            {
                getInt("\n MUSICOS.\n1-Alta.\n2-Modificar.\n3-Baja.\n4-Listar.\n5-Salir.\n","Error, opcion incorrecta.\n",1,5,TRIES,&opcionMusico);
                system("clear");
                __fpurge(stdin);
                //system("cls");
                switch (opcionMusico)
                {
                case 1:
                    if(musicos_alta(musicos,orquestas,instrumentos,&idMusico,MAX_MUSICO,MAX_ORQUESTA,MAX_INSTRUMENTO)==0)
                    {
                    //int musico_alta(Musico* arrayMusico, Orquesta* arrayOrquesta,Instrumento* arrayInstrumento,int *id,int limiteMusico,int limiteOrquesta, int limiteInstrumento)
                    //int musico_alta(Musico* arrayMusicos, Orquesta* arrayOrquesta, int* id, int limite);
                        flagMusico++;
                    }
                    break;
                case 2:
                    if (flagMusico>0 && flagOrquesta>0 && flagInstrumento>0)
                    {
                        musicos_print(musicos,MAX_MUSICO);
                        musicos_modificar(musicos,orquestas,MAX_ORQUESTA,MAX_MUSICO);
                    }else
                        printf("\nNo se puede modificar sin dar de alta.\n");
                    break;
                case 3:
                    if (flagMusico>0 && flagOrquesta>0 && flagInstrumento>0)
                    {
                        musicos_baja(musicos,MAX_MUSICO);
                    }else
                        printf("\nNo se puede dar de baja sin dar de alta.\n");
                    break;
                case 4:
                    if (flagMusico>0 && flagOrquesta>0 && flagInstrumento>0)
                    {
                        //musico_ordenarTitulo(musicos,MAX_MUSICO);
                        musicos_print(musicos,MAX_MUSICO);
                    }else
                        printf("\nNo hay lista.\n");
                    break;
                case 5:
                    break;
                }
            }while (opcionMusico!=5);//fin musico cambiar si opciones son menos, mirar getint
            break;
        case 3:
            do
            {
                getInt("\nINSTRUMENTOS.\n1-Alta.\n2-Baja.\n3-Listar.\n4-Salir.\n","Error, opcion incorrecta.\n",1,4,TRIES,&opcionInstrumento);
                system("clear");
                __fpurge(stdin);
                //system("cls");
                switch (opcionInstrumento)
                {
                case 1:
                    if(instrumento_alta(instrumentos,&idInstrumento,MAX_INSTRUMENTO)==0)
                    {
                        flagInstrumento++;
                    }
                    break;
                case 2:
                    if (flagInstrumento>0)
                    {
                        instrumento_baja(instrumentos,MAX_INSTRUMENTO);
                    }else
                        printf("\nNo se puede dar de baja sin dar de alta.\n");
                    break;
                case 3:
                    if (flagInstrumento>0)
                    {
                        //instrumento_ordenarDobleCadena(instrumentos,MAX_INSTRUMENTO);
                        instrumento_print(instrumentos,MAX_INSTRUMENTO);
                    }else
                        printf("\nNo hay lista.\n");
                    break;
                case 5:
                    break;
                }
            }while (opcionInstrumento!=4);//fin instrumento cambiar si opciones son menos, mirar getint
            break;
        case 4:
            break;
        }
    }
    return 0;
}
