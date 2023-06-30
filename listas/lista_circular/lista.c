#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "lista.h"

void menu (int *opcion){
    printf("*** LISTA SIMPLE ENLAZADA ***\n");
    printf("1. Insertar nodo en orden\n");
    printf("2. Duplicar nodo\n");
    printf("3. Extraer nodo especifico\n");
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
        // la lista esta vacia
        *cabeza = nuevo_nodo;
        nuevo_nodo->ant = nuevo_nodo->sig = nuevo_nodo;
        // Si la lista está vacía, se asigna el nuevo nodo como cabeza y se hace
        // que apunte a sí mismo en ambas direcciones, ya que es el único nodo de la lista.
    } else if (nuevo_nodo->id < (*cabeza)->id) {
        // el nuevo nodo debe ser el primer elemento de la lista
        Nodo *ultimo = (*cabeza)->ant;
        // Se obtiene el último nodo de la lista actual, que será el que quede 
        // antes del nuevo nodo en la lista.
        nuevo_nodo->sig = *cabeza;
        // El siguiente del nuevo nodo será la cabeza actual de la lista.
        nuevo_nodo->ant = ultimo;
        // El anterior del nuevo nodo será el último nodo de la lista actual.
        (*cabeza)->ant = nuevo_nodo;
        // El anterior de la cabeza actual apunta ahora al nuevo nodo.
        ultimo->sig = nuevo_nodo;
        // El siguiente del último nodo de la lista actual apunta ahora al nuevo nodo.
        *cabeza = nuevo_nodo;
        // El nuevo nodo se convierte en la cabeza de la lista.
    } else {
        // Caso 3: buscar el lugar adecuado para insertar el nuevo nodo
        Nodo *actual = (*cabeza)->sig;
        // Se comienza a buscar el lugar adecuado para insertar el nuevo nodo
        // desde el segundo nodo de la lista, ya que el primer nodo se ha descartado
        // en la condición anterior.
        while (actual != *cabeza && actual->id < nuevo_nodo->id) {
            actual = actual->sig;
            // Se recorre la lista avanzando al siguiente nodo, mientras que
            // el id del nodo actual sea menor al id del nuevo nodo.
        }
        nuevo_nodo->sig = actual;
        // El siguiente del nuevo nodo será el nodo actual.
        nuevo_nodo->ant = actual->ant;
        // El anterior del nuevo nodo será el anterior del nodo actual.
        actual->ant->sig = nuevo_nodo;
        // El siguiente del anterior del nodo actual será el nuevo nodo.
        actual->ant = nuevo_nodo;
        // El anterior del nodo actual apuntará ahora al nuevo nodo.
    }
}


Nodo* extraer_elemento(Nodo** cabeza, int id) {
    if (*cabeza == NULL) {
        return NULL;
    }
    Nodo* elemento_extraido = NULL;
    if ((*cabeza)->id == id) {
        elemento_extraido = *cabeza;
        *cabeza = (*cabeza)->sig;
        if (*cabeza != NULL) {
            (*cabeza)->ant = elemento_extraido->ant;
        }
        elemento_extraido->ant->sig = elemento_extraido->sig;
    } else {
        Nodo* aux = *cabeza;
        while (aux->sig != NULL && aux->sig->id != id) {
            aux = aux->sig;
        }
        if (aux->sig != NULL) {
            elemento_extraido = aux->sig;
            aux->sig = elemento_extraido->sig;
            if (elemento_extraido->sig != NULL) {
                elemento_extraido->sig->ant = aux;
            }
        }
    }
    if (elemento_extraido != NULL) {
        elemento_extraido->ant = elemento_extraido->sig = NULL;
    }
    return elemento_extraido;
}


Nodo* buscar(Nodo* cabeza, int id) {
    if (cabeza == NULL) {
        return NULL;
    }
    Nodo* actual = cabeza;

    while (actual != NULL) {
        if (actual->id == id) {
            return actual;
        }
        actual = actual->sig;
        if (actual == cabeza) {  // se llegó al final y se regresó al primer nodo
            break;
        }
    }

    return NULL;  // el nodo no fue encontrado
}


int duplicar_nodo(Nodo **cabeza, int id) {
    Nodo *nodo_a_duplicar = buscar(*cabeza, id);
    if (nodo_a_duplicar == NULL) {
        return 1;
    }
    Nodo *nuevo_nodo = crear_nodo(id);
    insertar_orden(cabeza, nuevo_nodo);
    return 0;
}


// Función para imprimir la lista doblemente ligada circular
void imprimir_lista(Nodo* cabeza) {
    if (cabeza == NULL) {
        printf("*** La lista esta vacia ***\n\n");
    } else {
        Nodo* actual = cabeza;
        printf("* LISTA: ");
        do {
            printf("%d -> ", actual->id);
            actual = actual->sig;
        } while (actual != cabeza);
        printf("Primero[%d]\n\n", cabeza->id);
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
