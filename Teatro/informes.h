#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "orquesta.h"
#include "instrumento.h"
#include "musico.h"

/*listar todas las orquestas que solicitaron un instrumento determinado
orquesta que mas musicos tiene//orquesta mas solicitada
orquesta que menos musicos tiene//orquesta menos solicitada
instrumento mas solicitado
instrumento menos solicitado
listar todos los instrumentos que fueron solicitados por una orquesta determinada

*/
int cantidad_tipos_orquesta (Orquesta* arrayOrquesta, int limiteOrquesta);
int cantidad_tipos_instrumento (Instrumento* arrayInstrumento, int limiteInstrumento);
int cantidadOrquestas(Orquesta* arrayOrquesta, int limiteOrquesta);
int cantidadInstrumentos(Instrumento* arrayInstrumento, int limiteInstrumento);
int cantidadMusicos(Musico* arrayMusico, int limiteMusico);
int cantidad_tipos_orquesta_y_nombres (Orquesta* arrayOrquesta, int limiteOrquesta);
int cantidad_tipos_instrumento_y_nombres (Instrumento* arrayInstrumento, int limiteInstrumento);
int promedio_edad_musicos(Musico* arrayMusicos,int limiteMusicos);
int promedio_cantidad_musicos_por_orquesta(Musico* arrayMusico, Orquesta* arrayOrquesta, int limiteMusico, int limiteOrquesta);
int musicos_segun_instrumento (Musico* arrayMusicos, Instrumento* arrayInstrumento, int limiteMusico, int limiteInstrumento);//instrumento segun orquesta hacer
int musicos_segun_orquesta (Musico* arrayMusicos, Orquesta* arrayOrquesta, int limiteMusico, int limiteOrquesta);//instrumento segun musico hacer
int musicos_ordenarDobleCriterio (Musico* arrayMusico, int limite, int orderFirst, int orderSecond);

#endif // INFORMES_H_INCLUDED
