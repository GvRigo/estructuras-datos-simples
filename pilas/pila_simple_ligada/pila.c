#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "pila.h"

void menu (int *opcion){
    printf("*** PILA SIMPLEMENTE LIGADA ***\n");
    printf("1. Agregar nodo\n");
    printf("2. Extraer nodo\n");
    printf("3. Eliminar nodo\n");
    printf("4. Imprimir pila\n");
    printf("5. Recuperar nodo\n");
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
    // Devolvemos el nuevo nodo
    return nuevo_nodo;
}

Pila *crear_pila(void) {
    Pila *pila = (Pila*) malloc(sizeof(Pila));  // reservamos memoria para la pila
    if (pila == NULL) {  // no se pudo reservar
        return NULL;    
    }
    pila->primero = NULL;  // inicializamos puntero primero de pila a NULL
    return pila;
}

// Función para apilar un elemento a la pila
void apilar(Pila *pila, Nodo *nuevoNodo) {
    nuevoNodo->sig = pila->primero;
    pila->primero = nuevoNodo;
}

// Función para desapilar un elemento de la pila
Nodo *extraer_nodo(Pila* pila) {
    if (pila->primero == NULL) {
        return NULL;
    }
    Nodo *temp = pila->primero;
    pila->primero = temp->sig;
    temp->sig = NULL;
    return temp;
}

// Funcion para imprimir la pila
void imprimir_pila(Pila *pila) {
    // Si la cola esta vacia, imprimimos un mensaje indicándolo
    if (pila->primero == NULL) {
        printf("*** La PILA esta vacia ***\n\n");
    } else {
        // Si la pila no esta vacia, recorremos la pila e imprimimos los identificadores de cada nodo
        Nodo *actual = pila->primero;
        printf("* PILA: ");
        while (actual != NULL) {
            printf("%d -> ", actual->id);
            actual = actual->sig;
        }
        // Imprimimos NULL para indicar el final de la cola
        printf("NULL\n\n");
    }
}

/*Funcion eliminar nodo pila*/
void eliminar_nodo(Pila *pila) {
    if (pila->primero == NULL) {  // si pila esta vacia
        return;
    }
    Nodo *temp = pila->primero;
    pila->primero = temp->sig;
    free(temp);
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
    char aux[100];
    int id;
    do {
        printf("%s", cadena);  // Imprime la cadena que pasamos de parametro
        scanf("%s", aux);

        if (!es_entero(aux)) {
        printf("\t  Ingrese un numero valido!!\n");
        }
    } while (!es_entero(aux));

    id = atoi(aux);  // convertimos de cadena a entero
    return id;
}


//funcion para limipiar pantalla
void limpiar_pantalla() {
    #ifdef _WIN32
        system("cls"); // ejecutando en Windows
    #else
        system("clear"); // ejecutando en Unix/Linux/Mac
    #endif
}
