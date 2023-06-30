#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "lista.h"

void menu (int *opcion){
    printf("*** LISTA CON CABECERA ***\n");
    printf("1. Insertar nodo en orden\n");
    printf("2. Duplicar nodo\n");
    printf("3. Extraer nodo\n");
    printf("4. Imprimir lista\n");
    printf("5. Numero de nodos\n");
    printf("6. Buscar nodo\n");
    printf("7. Salir\n");
    *opcion = lee_numero("Seleccione una opcion: ");
}

// Funcion para crear un nuevo nodo
Nodo *crear_nodo(int id) {
    // Reservamos memoria para el nuevo nodo utilizando malloc
    Nodo *nuevo_nodo = (Nodo*) malloc(sizeof(Nodo));
    if (nuevo_nodo == NULL) {
        return NULL;  // No se pudo reservar memoria para el nodo
    }
    // Asignamos el identificador al nodo
    nuevo_nodo->id = id;
    // Establecemos el puntero al siguiente nodo en NULL
    nuevo_nodo->sig = NULL;
    // Devolvemos el nuevo nodo
    return nuevo_nodo;
}


Cabecera *crear_cabecera(void) { //Funcion crear cola (se reserva memoria)
    Cabecera *cabecera = (Cabecera*) malloc(sizeof(Cabecera));
    if (cabecera == NULL) {
        return NULL;  // No se pudo reservar memoria para el cola
    }
    cabecera->inicio = NULL; // Apuntamos el primero a NULL 
    cabecera->fin = NULL; // Apuntamos el ultimo a NULL
    cabecera->contador = 0; // Iniciamos el contador de elementos
    return cabecera;
}


void insertar_orden(Cabecera *cabecera, Nodo *nuevo_nodo) {
    Nodo *actual, *previo = NULL;
    actual = cabecera->inicio;
    while (actual != NULL && actual->id < nuevo_nodo->id) {
        previo = actual;
        actual = actual->sig;
    }
    if (previo == NULL) {
        nuevo_nodo->sig = cabecera->inicio;
        cabecera->inicio = nuevo_nodo;
    } else {
        nuevo_nodo->sig = previo->sig;
        previo->sig = nuevo_nodo;
    }
    if (nuevo_nodo->sig == NULL) {
        cabecera->fin = nuevo_nodo;
    }
    cabecera->contador++;
}

Nodo *extraer_elemento(Cabecera *cabecera, int id) {
    Nodo *actual, *previo = NULL;
    actual = cabecera->inicio;
    while (actual != NULL && actual->id != id) {
        previo = actual;
        actual = actual->sig;
    }
    if (actual == NULL) {
        return NULL;
    }
    if (previo == NULL) {
        cabecera->inicio = actual->sig;
    } else {
        previo->sig = actual->sig;
    }
    if (actual->sig == NULL) {
        cabecera->fin = previo;
    }
    cabecera->contador--;
    return actual;
}



Nodo *buscar(Cabecera *cabecera, int id) {
    Nodo *actual;
    actual = cabecera->inicio;
    while (actual != NULL && actual->id != id) {
        actual = actual->sig;
    }
    return actual;
}

int duplicar_nodo(Cabecera *cabecera, int id) {
    Nodo *nodo = buscar(cabecera, id);
    if (nodo == NULL) {
        return 1;
    }
    Nodo *nuevo_nodo = crear_nodo(nodo->id);
    insertar_orden(cabecera, nuevo_nodo);
    return 0;
}

int tamanio_lista(Cabecera *cabecera){
    return cabecera->contador;
}

// Funcion para imprimir la cola
void imprimir_lista(Cabecera *cabecera) {
    // Si la cola esta vacia, imprimimos un mensaje indicándolo
    if (cabecera->inicio == NULL) {
        printf("*** La lista esta vacia ***\n\n");
    } else {
        // Si la lista no esta vacia, recorremos e imprimimos los identificadores de cada nodo
        Nodo *actual = cabecera->inicio;
        printf("* LISTA: ");
        while (actual != NULL) {
            printf("%d -> ", actual->id);
            actual = actual->sig;
        }
        // Imprimimos NULL para indicar el final de la cola
        printf("NULL\n\n");
    }
}


int es_entero(const char *str) {  // se define const para no modificar valor
    for (int i = 0; str[i] != '\0'; i++) {  // Recorremos la cadena
        if (!isdigit(str[i])) {  // Verifica si elemento_del_indice es digito
            return 0;
        }
    }
    return 1;
}


int lee_numero(char *cadena) {
    char aux[10];
    int id;
    do {
        printf("%s", cadena);
        scanf("%s", aux);

        if (!es_entero(aux)) {
        printf("\t  Ingrese un numero valido!!\n");
        }
    } while (!es_entero(aux));

    id = atoi(aux);  // convertimos de cadena a entero
    return id;
}


//funcion para limipiar pantalla
void limpiar_pantalla(void) {
    #ifdef _WIN32
        system("cls"); // ejecutando en Windows
    #else
        system("clear"); // ejecutando en Unix/Linux/Mac
    #endif
}
