#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "cola.h"

void menu (int *opcion){
    printf("\t*** COLA CON CABECERA ***\n");
    printf("1. Agregar nodo\n");
    printf("2. Extraer nodo\n");
    printf("3. Eliminar nodo\n");
    printf("4. Imprimir cola\n");
    printf("5. Numero de nodos\n");
    printf("6. Recuperar Nodo\n");
    printf("7. Salir\n");
    *opcion = lee_numero("Seleccione una opción: ");
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


Cola *crear_cola(void) { //Funcion crear cola (se reserva memoria)
    Cola *cola = (Cola*) malloc(sizeof(Cola));
    if (cola == NULL) {
        return NULL;  // No se pudo reservar memoria para el cola
    }
    cola->primero = NULL; // Apuntamos el primero a NULL 
    cola->ultimo = NULL; // Apuntamos el ultimo a NULL
    cola->elementos = 0; // Iniciamos el contador de elementos
    return cola;
}


// Funcion para insertar un nuevo nodo al final de la cola
void insertar_nodo(Cola *cola, Nodo *nuevo_nodo) {
    // Si la cola esta vacia, iniciamos a NULL primero y ultimo
    if (cola->ultimo == NULL) {
        cola->primero = nuevo_nodo;
        cola->ultimo = nuevo_nodo;
    } else {
        cola->ultimo->sig = nuevo_nodo; // actualizamos puntero del nodo
        cola->ultimo = nuevo_nodo; // actualizamos punto ultimo de cola
    }
    cola->elementos++;
}


// Funcion para imprimir la cola
void imprimir_cola(Cola *cola) {
    // Si la cola esta vacia, imprimimos un mensaje indicándolo
    if (cola->primero == NULL) {
        printf("*** La cola esta vacia ***\n\n");
    } else {
        // Si la cola no esta vacia, recorremos la cola
        Nodo *actual = cola->primero;
        printf("* COLA: ");
        while (actual != NULL) {
                printf("%d -> ", actual->id);
            actual = actual->sig;
        }
        // Imprimimos NULL para indicar el final de la cola
        printf("NULL\n\n");
    }
}

// Funcion para eliminar el primer nodo de la cola
void eliminar_nodo(Cola *cola) {
    // Si la cola esta vacia, salimos
    if (cola->primero == NULL) {
        /*printf("*** La cola esta vacia ***\n\n");*/
        return;
    }
    Nodo *nodo = cola->primero;
    int id_nodo = nodo->id;
    cola->primero = nodo->sig;
    free(nodo);
    cola->elementos--;
    if (cola->primero == NULL) {
        cola->ultimo = NULL;
    }
}

// Extraer el primer nodo de la lista enlazada
Nodo *extraer_nodo (Cola *cola) {
    if (cola->primero == NULL) {
        return NULL;  // La lista esta vacia
    }
    Nodo *nodo_extraer = cola->primero;
    cola->primero = nodo_extraer->sig;
    if (cola->primero == NULL) {
        cola->ultimo = NULL;
    }
    cola->elementos--;
    nodo_extraer->sig = NULL;
    return nodo_extraer;
}

int numero_elementos_cola(Cola *cola){
    return cola->elementos;
}


int es_entero(const char *str) {  // se define const para no modificar valor
    for (int i = 0; str[i] != '\0'; i++) {  // Recorremos la cadena
        if (!isdigit(str[i])) {  // Verifica si elemento-indice es digito
            return 0;
        }
    }
    return 1;
}

int lee_numero(char *cadena) {
    char aux[100];
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

//funcion para limpiar pantalla
void limpiar_pantalla() {
    #ifdef _WIN32
        system("cls"); // ejecutando en Windows
    #else
        system("clear"); // ejecutando en Unix/Linux/Mac
    #endif
}
