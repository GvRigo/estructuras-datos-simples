#ifndef COLA_H
#define COLA_H

// Definicion de la estructura de nodo
typedef struct Nodo {
    int id;                 // Identificador del nodo
    struct Nodo *sig;       // Puntero al siguiente
    struct Nodo *ant;       // Puntero al anterior
} Nodo;


/*Creacion de prototipos de funciones*/
void menu(int *);
Nodo *crear_nodo(int);
void insertar_nodo(Nodo **, Nodo *);
void imprimir_cola(Nodo *);
Nodo *extraer_nodo (Nodo **);
void eliminar_nodo(Nodo **);
int es_entero(const char *);
int lee_numero(char *);
void limpiar_pantalla();

#endif
