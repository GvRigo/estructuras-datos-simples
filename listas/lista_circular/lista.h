#ifndef COLA_H
#define COLA_H

// Definicion de la estructura de nodo
typedef struct Nodo {
    int id;                 // Identificador del nodo
    struct Nodo *sig;       // Puntero al siguiente nodo en la cola
    struct Nodo *ant;
} Nodo;

/*Creacion de prototipos de funciones*/
void menu(int *);
Nodo *crear_nodo(int);
void insertar_orden(Nodo **, Nodo *);
Nodo *extraer_elemento(Nodo **, int);
Nodo *buscar(Nodo *, int);
int duplicar_nodo(Nodo **, int);
void imprimir_lista(Nodo *);
int es_entero(const char *);
int lee_numero(char *);
void limpiar_pantalla();

#endif
