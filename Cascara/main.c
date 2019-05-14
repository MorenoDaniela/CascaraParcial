#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h> INCLUIR ENTIDADES 4 O 3
#include "funciones.h"
#define TRIES 3
#define MAX_ESTRUCTURAUNO 10
#define MAX_ESTRUCTURADOS 10
#define MAX_ESTRUCTURATRES 10
#define MAX_ESTRUCTURACUATRO 10
int main()
{
    Autor STRUCT_UNO [MAX_ESTRUCTURAUNO];
    Libro STRUCT_DOS [MAX_ESTRUCTURADOS];
    Socio STRUCT_TRES[MAX_ESTRUCTURATRES];
    Prestamo STRUCT_CUATRO[MAX_ESTRUCTURACUATRO];
    int opcion;
    int flagUno=0;
    int flagDos=0;
    int flagTres=0;
    int flagCuatro=0;
    int opcionUno;
    int opcionDos;
    int opcionTres;
    int opcionCuatro;
    int idUno=0;
    int idDos=0;
    int idTres=0;
    int idCuatro=0;

    /*
    uno_initStruct(STRUCT_UNO,MAX_ESTRUCTURAUNO);
    dos_initStruct(STRUCT_DOS,MAX_ESTRUCTURADOS);
    tres_initStruct(STRUCT_TRES,MAX_ESTRUCTURATRES);
    cuatro_initStruct(STRUCT_CUATRO,MAX_ESTRUCTURACUATRO);

    /*
    harcodearSTRUCT_UNO(STRUCT_UNO,MAX_ESTRUCTURAUNO);
    harcodearSTRUCT_DOS(STRUCT_DOS,MAX_ESTRUCTURADOS);
    harcodearSTRUCT_TRES(STRUCT_TRES,MAX_ESTRUCTURATRES);
    harcodearSTRUCT_CUATRO(STRUCT_CUATRO,MAX_ESTRUCTURACUATRO);
    flagUno=1;
    flagDos=1;
    flagTres=1;
    flagCuatro=1;*/

    while(opcion!=5)
    {
        getInt("\n**MENU**\n1-STRUCT_UNO.\n2-STRUCT_DOS.\n3-STRUCT_TRES.\n4-STRUCT_CUATRO.\n5-Salir.\n","\nError, opcion invalida.\n",1,5,TRIES,&opcion);
        system("cls");//system("clear");
        switch(opcion)
        {
        case 1:
            do
            {
                getInt("\n STRUCT_UNO.\n1-Alta.\n2-Modificar.\n3-Baja.\n4-Listar.\n5-Salir.\n","Error, opcion incorrecta.\n",1,5,TRIES,&opcionUno);
                system("clear");
                __fpurge(stdin);
                //system("cls");
                //fflush(stdin);
                switch (opcionUno)
                {
                case 1:
                    if (uno_alta(STRUCT_UNO,&idUno,MAX_ESTRUCTURAUNO)==0)
                    {
                        flagUno++;
                    }
                    break;
                case 2:
                    if (flagUno>0)
                    {
                        uno_modificar(STRUCT_UNO,MAX_ESTRUCTURAUNO);
                    }else
                        printf("\nNo se puede modificar sin dar de alta.\n");
                    break;
                case 3:
                    if(flagUno>0)
                    {
                        uno_baja(STRUCT_UNO,MAX_ESTRUCTURAUNO);
                    }else
                        printf("\nNo se puede dar de baja sin dar de alta.\n");
                    break;
                case 4:
                    if (flagUno>0)
                    {
                        uno_ordenarDobleCadena(STRUCT_UNO,MAX_ESTRUCTURAUNO);
                        uno_print(STRUCT_UNO,MAX_ESTRUCTURAUNO);
                    }
                    else
                        printf("\nNo hay lista.\n");
                    break;
                case 5:
                    break;
                }
            }while (opcionUno!=5);//fin uno cambiar si opciones son menos, mirar getint
            break;
        case 2:
            do
            {
                getInt("\n STRUCT_DOS.\n1-Alta.\n2-Modificar.\n3-Baja.\n4-Listar.\n5-Salir.\n","Error, opcion incorrecta.\n",1,5,TRIES,&opcionDos);
                system("clear");
                __fpurge(stdin);
                //system("cls");
                switch (opcionDos)
                {
                case 1:
                    if(dos_alta(STRUCT_DOS,STRUCT_UNO,&idDos,MAX_ESTRUCTURAUNO,MAX_ESTRUCTURATRES)==0)
                    {
                        flagDos++;
                    }
                    break;
                case 2:
                    if (flagDos>0 && flagUno>0)
                    {
                        dos_print(STRUCT_DOS,MAX_ESTRUCTURADOS);
                        dos_modificar(STRUCT_DOS,STRUCT_UNO,MAX_ESTRUCTURAUNO,MAX_ESTRUCTURADOS);
                    }else
                        printf("\nNo se puede modificar sin dar de alta.\n");
                    break;
                case 3:
                    if (flagDos>0 && flagUno>0)
                    {
                        dos_baja(STRUCT_DOS,MAX_ESTRUCTURADOS);
                    }else
                        printf("\nNo se puede dar de baja sin dar de alta.\n");
                    break;
                case 4:
                    if (flagDos>0 && flagUno>0)
                    {
                        dos_ordenarTitulo(STRUCT_DOS,MAX_ESTRUCTURADOS);
                        dos_print(STRUCT_DOS,MAX_ESTRUCTURADOS);
                    }else
                        printf("\nNo hay lista.\n");
                    break;
                case 5:
                    break;
                }
            }while (opcionDos!=5);//fin dos cambiar si opciones son menos, mirar getint
            break;
        case 3:
            do
            {
                getInt("\n STRUCT_TRES.\n1-Alta.\n2-Modificar.\n3-Baja.\n4-Listar.\n5-Salir.\n","Error, opcion incorrecta.\n",1,5,TRIES,&opcionTres);
                system("clear");
                __fpurge(stdin);
                //system("cls");
                switch (opcionTres)
                {
                case 1:
                    if(tres_alta(STRUCT_TRES,&idTres,MAX_ESTRUCTURATRES)==0)
                    {
                        flagTres++;
                    }
                    break;
                case 2:
                    if (flagTres>0)
                    {
                        tres_print(STRUCT_TRES,MAX_ESTRUCTURATRES);
                        tres_modificar(STRUCT_TRES,MAX_ESTRUCTURATRES);
                    }else
                        printf("\nNo se puede modificar sin dar de alta.\n");
                    break;
                case 3:
                    if (flagTres>0)
                    {
                        tres_baja(STRUCT_TRES,MAX_ESTRUCTURATRES);
                    }else
                        printf("\nNo se puede dar de baja sin dar de alta.\n");
                    break;
                case 4:
                    if (flagTres>0)
                    {
                        tres_ordenarDobleCadena(STRUCT_TRES,MAX_ESTRUCTURATRES);
                        tres_print(STRUCT_TRES,MAX_ESTRUCTURATRES);
                    }else
                        printf("\nNo hay lista.\n");
                    break;
                case 5:
                    break;
                }
            }while (opcionTres!=5);//fin tres cambiar si opciones son menos, mirar getint
            break;
        case 4:
            do
            {
                getInt("\n STRUCT_CUATRO.\n1-Alta.\n2-Listar.\n3-Salir.\n","Error, opcion incorrecta.\n",1,3,TRIES,&opcionCuatro);
                system("clear");
                __fpurge(stdin);
                //system("cls");
                //fflush(stdin);
                switch (opcionCuatro)
                {
                case 1:
                    if (cuatro_alta(STRUCT_CUATRO,STRUCT_DOS,STRUCT_TRES,&idCuatro,MAX_ESTRUCTURACUATRO,MAX_ESTRUCTURADOS,MAX_ESTRUCTURATRES)==0)
                    {
                        flagCuatro++;
                    }
                    break;
                case 2:
                    if (flagCuatro>0 && flagUno>0 && flagDos>0)
                    {
                        //cuatro_ordenarDobleCadena(STRUCT_CUATRO,MAX_ESTRUCTURACUATRO);
                        cuatro_print(STRUCT_CUATRO,MAX_ESTRUCTURACUATRO);
                    }else
                        printf("\nNo hay lista.\n");
                    break;
                case 3:
                    break;
                }
            }while (opcionCuatro!=3);//fin cuatro cambiar si opciones son menos, mirar getint
            break;
        case 5:
            break;
        }
    }
    return 0;
}
