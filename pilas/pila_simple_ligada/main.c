#include <stdio.h>
#include <stdlib.h>

#include "pila.h"

int main() {
    Pila *pila = crear_pila();
    Nodo *nodo_extraido = NULL;  // Puntero a nodo a extraer
    int opcion, id;
    limpiar_pantalla();

    do {
        menu(&opcion);

        switch (opcion) {
            case 1:  // agregar nodo
                id = lee_numero("\n\tIntroduce id para el nodo: ");
                limpiar_pantalla();
                Nodo *nuevo_nodo = crear_nodo(id);
                if (nuevo_nodo == NULL) {
                    printf("\n\t***NO SE PUDO CREAR EL NODO***\n\n");                
                    return 1;
                } else {
                    apilar(pila, nuevo_nodo);
                    printf("\tNodo agregado: [%d]\n\n", id);
                }
                break;

            case 2:  // eliminar nodo
                limpiar_pantalla();
                nodo_extraido = extraer_nodo(pila);
                if (nodo_extraido == NULL) {
                    printf("No hay nada que extraer...\n\n");
                } else {
                    printf("Se extrajo el nodo[%d]\n\n", nodo_extraido->id);
                }
                break;

            case 3:  // eliminar nodo
                if (pila->primero == NULL) {  // si NULL esta vacia
                    limpiar_pantalla();
                    printf("*** La PILA esta vacia ***\n\n");
                } else {
                    limpiar_pantalla();
                    eliminar_nodo(pila);
                    printf("Ultimo Nodo eliminado\n");
                }
                break;

            case 4:  // imprimir cola
                limpiar_pantalla();
                imprimir_pila(pila);
                break;

            case 5:  // recuperar nodo_extraido
                if (nodo_extraido != NULL) {
                    limpiar_pantalla();
                    apilar(pila, nodo_extraido);
                    printf("Nodo [%d] se recupero a la pila\n\n", nodo_extraido->id);
                    nodo_extraido = NULL;
                } else {
                    limpiar_pantalla();
                    printf("No se encontro nodo a recuperar...\n\n");
                }
                break;

            case 6:  // salir
                printf("\n\n\tSaliendo...\n");
                break;

            default:
                limpiar_pantalla();
                printf("*** Opcion invalida ***\n");
                break;
        }
    } while (opcion != 6);

    return 0;
}
