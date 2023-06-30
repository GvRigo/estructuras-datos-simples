#ifndef COLA_H
#define COLA_H

// Definicion de la estructura de nodo
typedef struct Nodo {
    int id;                 // Identificador del nodo
    struct Nodo *sig;       // Puntero al siguiente nodo en la cola
} Nodo;

typedef struct Cola {
    Nodo *primero;
    Nodo *ultimo;
    unsigned elementos;
} Cola;


/*Creacion de prototipos de funciones*/
void menu(int *);
Nodo *crear_nodo(int);
Cola *crear_cola(void);
void insertar_nodo(Cola *, Nodo *);
void imprimir_cola(Cola *);
void eliminar_nodo(Cola *);
Nodo *extraer_nodo (Cola *);
int numero_elementos_cola(Cola *);
int es_entero(const char *);
int lee_numero(char *);
void limpiar_pantalla();

#endif
