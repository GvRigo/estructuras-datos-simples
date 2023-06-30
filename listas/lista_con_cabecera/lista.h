#ifndef LISTA_H
#define LISTA_H

// Definicion de la estructura de nodo
typedef struct Nodo {
    int id;                 // Identificador del nodo
    struct Nodo *sig;       // Puntero al siguiente nodo en la lista
} Nodo;

typedef struct Cabecera {
    Nodo *inicio;
    Nodo *fin;
    unsigned contador;
} Cabecera;


/*Creacion de prototipos de funciones*/
void menu(int *);
Nodo *crear_nodo(int);
Cabecera *crear_cabecera(void);
void insertar_orden(Cabecera *, Nodo *);
Nodo *extraer_elemento(Cabecera *, int);
Nodo *buscar(Cabecera *, int);
int duplicar_nodo(Cabecera *, int);
int tamanio_lista(Cabecera *);
void copiar_lista(Cabecera *, Nodo **);
void imprimir_lista(Cabecera *);
int es_entero(const char *);
int lee_numero(char *);
void limpiar_pantalla();

#endif
