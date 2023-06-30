#ifndef PILA_C
#define PILA_C

// Definicion de la estructura de nodo
typedef struct Nodo {
    int id;                 // Identificador del nodo
    struct Nodo *sig;       // Puntero al siguiente nodo en la cola
} Nodo;

// Definir la estructura de la pila
typedef struct Pila {
    struct Nodo *primero;  // puntero al primer elemento de la pila en salir
} Pila;

/*Creacion de prototipos de funciones*/
void menu(int *);
Nodo *crear_nodo(int);
Pila *crear_pila(void);
void apilar(Pila *, Nodo *);
Nodo *extraer_nodo (Pila *);
void imprimir_pila(Pila *);
void eliminar_nodo(Pila *);
int es_entero(const char *);
int lee_numero(char *);
void limpiar_pantalla();

#endif
