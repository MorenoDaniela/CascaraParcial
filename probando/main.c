#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main()
{
    int numero;
    float numeroF;
    char dni[12];//EL DNI CON PUNTOS
    char texto[50];
    char cuit[20];//CUIT CON DOS GUIONES
    char mail[50];
    char alfanu[40];
    char telefono[17];
    char nombre[51];
    char apellido[51];
    char letra;
    char sexo;
    //char fecha[25];
    fflush(stdin);
    getInt("Ingrese numero int: ","Error.",1,200,3,&numero);
    fflush(stdin);
    getFloat("Ingrese numero float: ","Error.",1,200,3,&numeroF);
    fflush(stdin);
    getDni("Ingrese dni:  ","Error.",9,11,3,dni);
    fflush(stdin);
    getString("Ingrese texto: ","Error.",5,200,3,texto);
    fflush(stdin);
    getCuit("Ingrese cuit: ","Error.",11,14,3,cuit);
    fflush(stdin);
    getEmail("Ingrese mail: ","Error.",5,50,3,mail);
    fflush(stdin);
    getAlfanumerico("Ingrese alfa: ","Error.",5,50,3,alfanu);
    fflush(stdin);
    getTelefono("Ingrese telefono: ","Error.",8,16,3,telefono);
    fflush(stdin);
    getName("Ingrese nombre: ","Error.",3,20,3,nombre);
    fflush(stdin);
    getApellido("Ingrese apellido: ","Error.",3,25,3,apellido);
    fflush(stdin);
    getChar("Ingrese letra: ","Error.",'A','Z',3,&letra);
    fflush(stdin);
    getSex("Ingrese sexo: ","error.",1,1,3,&sexo);
    fflush(stdin);
    //getFecha("Ingrese fecha: ","Error.",1,2020,3,fecha);

    printf("\nInt: %d",numero);
    printf("\nFloat: %f",numeroF);
    printf("\nDNI: %s",dni);
    printf("\nTEXTO: %s",texto);
    printf("\nCUIT: %s",cuit);
    printf("\nEmail: %s",mail);
    printf("\nALFA: %s",alfanu);
    printf("\nTELEFONO: %s",telefono);
    printf("\nNOMBRE: %s",nombre);
    printf("\nApellido: %s",apellido);
    printf("\nSEXO: %c",sexo);
    printf("\nLETRA: %c",letra);
    //printf("FECHA: %s",fecha);

}
