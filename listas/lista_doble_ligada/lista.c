#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "lista.h"

void menu (int *opcion){
    printf("*** LISTA DOBLEMENTE ENLAZADA ***\n");
    printf("1. Insertar nodo en orden\n");
    printf("2. Duplicar nodo\n");
    printf("3. Extraer nodo\n");
    printf("4. Imprimir lista\n");
    printf("5. Buscar nodo\n");
    printf("6. Salir\n");
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
    nuevo_nodo->ant = NULL;
    // Devolvemos el nuevo nodo
    return nuevo_nodo;
}


void insertar_orden(Nodo **cabeza, Nodo *nuevo_nodo) {
    if (*cabeza == NULL) {
        *cabeza = nuevo_nodo;
    } else if (nuevo_nodo->id < (*cabeza)->id) {
        nuevo_nodo->sig = *cabeza;
        (*cabeza)->ant = nuevo_nodo;
        *cabeza = nuevo_nodo;
    } else {
        Nodo *actual = *cabeza;
        while (actual->sig != NULL && actual->sig->id < nuevo_nodo->id) {
            actual = actual->sig;
        }
        nuevo_nodo->sig = actual->sig;
        if (actual->sig != NULL) {
            actual->sig->ant = nuevo_nodo;
        }
        actual->sig = nuevo_nodo;
        nuevo_nodo->ant = actual;
    }
}


Nodo *extraer_elemento(Nodo **cabeza, int id) {
    if (*cabeza == NULL) {
        return NULL;
    }
    
    Nodo* actual = *cabeza;
    while (actual != NULL && actual->id != id) {
        actual = actual->sig;
    }
    
    if (actual != NULL) {  // No se llego al final y se encontró
        if (actual == *cabeza) {  // por si es el primero
            *cabeza = actual->sig;
        } else {
            actual->ant->sig = actual->sig;  // saltamos el nodo a extraer
        }
        if (actual->sig != NULL) {
            actual->sig->ant = actual->ant;
        }
        actual->sig = NULL;
        actual->ant = NULL;
        return actual;
    }
    return NULL; // Si no encontro nada
  
}


Nodo *buscar(Nodo *cabeza, int id) {
    if (cabeza == NULL) {
        return NULL;        
    }
    Nodo *actual = cabeza;
    while (actual != NULL) {
        if (actual->id == id) {
            return actual; // se encontró el nodo
        }
        actual = actual->sig;
    }
    return NULL; // no se encontró el nodo
}


int duplicar_nodo(Nodo **cabeza, int id) {
    Nodo* actual = *cabeza;
    while (actual != NULL) {
        if (actual->id == id) {
            Nodo *nuevo_nodo = crear_nodo(id);
            nuevo_nodo->id = actual->id;
            nuevo_nodo->sig = NULL;
            nuevo_nodo->ant = NULL;
            insertar_orden(cabeza, nuevo_nodo);
            return 0;
        }
        actual = actual->sig;
    }
    return 1;
}

// Funcion para imprimir la cola
void imprimir_lista(Nodo *lista) {
    // Si la cola esta vacia, imprimimos un mensaje indicándolo
    if (lista == NULL) {
        printf("*** La lista esta vacia ***\n\n");
    } else {
        // Si la cola no esta vacia, recorremos la cola e imprimimos los identificadores de cada nodo
        Nodo *actual = lista;
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
