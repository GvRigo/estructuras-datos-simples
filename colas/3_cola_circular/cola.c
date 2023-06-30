#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "cola.h"

void menu (int *opcion){
    printf("\t*** COLA CIRCULAR ***\n");
    printf("1. Agregar nodo\n");
    printf("2. Extraer nodo\n");
    printf("3. Eliminar nodo\n");
    printf("4. Imprimir cola\n");
    printf("5. Recuperar nodo\n");
    printf("6. Salir\n");
    *opcion = lee_numero("Seleccione una opcion: ");
}

// Funcion para crear un nuevo nodo | El anterior del primer Nodo siempre sera NULL
Nodo *crear_nodo(int id) {
    // Reservamos memoria para el nuevo nodo utilizando malloc
    Nodo *nuevo_nodo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo_nodo == NULL) {
        return NULL; // No se pudo reservar memoria para el nodo
    }
    // Asignamos el identificador al nodo
    nuevo_nodo->id = id;
    // Establecemos el puntero al siguiente nodo en NULL
    nuevo_nodo->sig = NULL;
    // Devolvemos el nuevo nodo
    return nuevo_nodo;
}

/*********************************************************************
* la cola es el penultimo, para evitar usar cabecera con inicio y final *
*********************************************************************/
void insertar_nodo(Nodo **cola, Nodo *nuevo_nodo) {
    if (*cola == NULL) {  // Si la cola está vacía
        // El nuevo nodo se convierte en el primero y unico de la cola
        nuevo_nodo->sig = nuevo_nodo;
        *cola = nuevo_nodo;  // El puntero a la cola apunta al nuevo nodo
    } else {  // Si la cola no esta vacia
        // El nuevo nodo se inserta despues del ultimo nodo actual
        nuevo_nodo->sig = (*cola)->sig;  // El puntero siguiente del nuevo nodo apunta al primer nodo actual
        (*cola)->sig = nuevo_nodo;  // El puntero siguiente del ultimo nodo actual apunta al nuevo nodo
        *cola = nuevo_nodo;  // El puntero a la cola apunta al nuevo nodo
    }
}

// Funcion para imprimir la cola circular
void imprimir_cola(Nodo *cola) {
    if (cola == NULL) {
        printf("*** La cola esta vacia ***\n\n");
    } else {
        Nodo *actual = cola;  // igualamos el actual como el primero de la cola
        printf("* COLA: ");
        do {
            printf("%d -> ", actual->sig->id);
            actual = actual->sig;
        } while (actual != cola); // se detiene cuando se llega a la cola nuevamente. penultimo
        printf("Primero[%d]\n\n", actual->sig->id);
    }
}

// Extraer el primer nodo de la cola circular
Nodo *extraer_nodo(Nodo **cola) {
    if (*cola == NULL) {
        return NULL; // La cola esta vacia
    } // recordamos que en cola_circular, la cola es el penultimo nodo
    Nodo *nodo_extraer = (*cola)->sig; // apunta al sig del sig de la cola, que es el primero
    (*cola)->sig = nodo_extraer->sig; // ahora la cola apunta al segundo
    nodo_extraer->sig = NULL; // el ex-inicio no apuntara a nada
    return nodo_extraer;  // lo retornamos para guardarlo en temporal
}

// Funcion para eliminar el primer elemento de la cola
void eliminar_nodo(Nodo** cola) {
    // Si la cola esta vacia, no hacemos nada
    if ((*cola)->sig == NULL) {
        return;
    }
    Nodo* temp = (*cola)->sig;  // seleccionamos el primer nodo de la cola
    (*cola)->sig = temp->sig;  // actualizamos el sig del ultimo como el segundo
    if (*cola == temp) {  // si es igual entonces solo hay uno
       *cola = NULL; 
    }

    // Liberamos la memoria del primer nodo de la cola
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
