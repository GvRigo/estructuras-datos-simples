#ifndef COLA_H
#define COLA_H

// Definicion de la estructura de nodo
typedef struct Nodo {
    int id;                 // Identificador del nodo
    unsigned prioridad;
    struct Nodo *sig;       // Puntero al siguiente nodo en la cola
} Nodo;


/*Creacion de prototipos de funciones*/
void menu(int *);
Nodo *crear_nodo(int, unsigned);
void insertar_nodo_prioridad(Nodo **, Nodo *);
void imprimir_cola(Nodo *);
Nodo *extraer_nodo (Nodo **);
void eliminar_nodo(Nodo **);
int es_entero(const char *);
int lee_numero(char *);
void limpiar_pantalla();

#endif
