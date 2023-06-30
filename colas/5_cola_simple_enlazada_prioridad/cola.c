#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "cola.h"

void menu (int *opcion){
    printf("*** COLAS CON PRIORIDAD ***\n");
    printf("1. Agregar nodo con priorida\n");
    printf("2. Extraer nodo\n");
    printf("3. Eliminar nodo\n");
    printf("4. Imprimir cola\n");
    printf("5. Recuperar nodo\n");
    printf("6. Salir\n");
    *opcion = lee_numero("Seleccione una opcion: ");
}

// Funcion para crear un nuevo nodo
Nodo *crear_nodo(int id, unsigned prioridad) {
    // Reservamos memoria para el nuevo nodo utilizando malloc
    Nodo *nuevo_nodo = (Nodo*) malloc(sizeof(Nodo));
    if (nuevo_nodo == NULL) {
        return NULL;  // No se pudo reservar memoria para el nodo
    }
    // Asignamos el identificador al nodo
    nuevo_nodo->id = id;
    // Asignamos prioridad al nodo
    nuevo_nodo->prioridad = prioridad;
    // Establecemos el puntero al siguiente nodo en NULL
    nuevo_nodo->sig = NULL;
    // Devolvemos el nuevo nodo
    return nuevo_nodo;
}

// Funcion para insertar un nuevo nodo con prioridad en la cola
void insertar_nodo_prioridad(Nodo **cola, Nodo *nuevo_nodo) {
    // Si cola vacia: nuevo nodo se convierte cabeza de la cola
    if (*cola == NULL) {
        *cola = nuevo_nodo;
    } else {
        // Si la cola no esta vacia, buscamos donde insertar el nuevo nodo
        Nodo *anterior = NULL;
        Nodo *actual = *cola;
        while (actual != NULL && nuevo_nodo->prioridad >= actual->prioridad) {
            anterior = actual;
            actual = actual->sig;
        }
        // Insertamos el nuevo nodo entre el nodo anterior y el nodo actual
        if (anterior == NULL) {
            // El nuevo nodo es la nueva cabeza de la cola
            nuevo_nodo->sig = *cola;
            *cola = nuevo_nodo;
        } else {
            anterior->sig = nuevo_nodo;
            nuevo_nodo->sig = actual;
        }
    }
}

/*// Funcion para insertar un nuevo nodo al final de la cola*/
/*void insertar_nodo_priorida(Nodo **cola, Nodo *nuevo_nodo) {*/
    /*// Si cola vacia: nuevo nodo se convierte cabeza de la cola*/
    /*if (*cola == NULL) {*/
        /**cola = nuevo_nodo;*/
    /*} else {*/
        /*// Si la cola no esta vacia, buscamos el ultimo nodo en la cola*/
        /*Nodo *actual = *cola;*/
        /*while (actual->sig != NULL) {*/
            /*while (nuevo_nodo->prioridad < actual->prioridad) {*/

            
            /*}*/

            /*if (nuevo_nodo->prioridad > actual->prioridad ) {*/
                /*actual->sig = nuevo_nodo;*/
            /*}*/
            /*actual = actual->sig;*/
        /*}*/
        /*// Establecemos el puntero al siguiente nodo del último nodo en la cola*/
        /*actual->sig = nuevo_nodo;*/
    /*}*/
/*}*/


// Funcion para imprimir la cola
void imprimir_cola(Nodo *cola) {
    // Si la cola esta vacia, imprimimos un mensaje indicándolo
    if (cola == NULL) {
        printf("*** La cola esta vacia ***\n\n");
    } else {
        // Si la cola no esta vacia, recorremos la cola e imprimimos los identificadores de cada nodo
        Nodo *actual = cola;
        printf("* COLA: ");
        while (actual != NULL) {
            printf("%d|%d -> ", actual->id, actual->prioridad);
            actual = actual->sig;
        }
        // Imprimimos NULL para indicar el final de la cola
        printf("NULL\n\n");
    }
}

// Extraer el primer nodo de la lista enlazada
Nodo *extraer_nodo (Nodo **cola) {
    if (*cola == NULL) {
        return NULL;  // La lista esta vacia
    }
    Nodo *nodo_extraer = *cola;  // apunta al primero cola que es el primero
    *cola = nodo_extraer->sig;  // ahora la cola empieza en el segundo
    nodo_extraer->sig = NULL;  // el exprimero no apuntara a nada
    return nodo_extraer;
}

// Funcion para eliminar el primer nodo de la cola
void eliminar_nodo(Nodo **cola) {
    // Si la cola esta vacia, imprimimos un mensaje indicándolo
    if (*cola == NULL) {
        return;
    } else {
        // Si la cola no esta vacia, eliminamos el primer nodo de la cola
        Nodo *temp = *cola;
        *cola = (*cola)->sig;
        free(temp);
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


//funcion para limipiar pantalla
void limpiar_pantalla() {
    #ifdef _WIN32
        system("cls"); // ejecutando en Windows
    #else
        system("clear"); // ejecutando en Unix/Linux/Mac
    #endif
}
