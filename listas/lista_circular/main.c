#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main(void) {
    Nodo *lista = NULL; // Puntero que despues apuntara al inicio de la lista
    Nodo *nodo_extraido = NULL;  // Puntero a nodo a extraer
    Nodo *nodo_buscar = NULL;
    int opcion, id, id_duplicar;
    limpiar_pantalla();

    do {
        menu(&opcion);

        switch (opcion) {
            case 1:  // insertar en orden
                id = lee_numero("\n\tIntroduce id para el nodo: ");
                limpiar_pantalla();
                Nodo *nuevo_nodo = crear_nodo(id);
                if (nuevo_nodo == NULL) {
                    printf("\n\t***NO SE PUDO CREAR EL NODO***\n\n");                
                    return 1;
                } else {
                    insertar_orden(&lista, nuevo_nodo);
                    printf("\tNodo agregado: [%d]\n\n", id);
                }
                break;

            case 2:  // duplicar nodo
                if (lista == NULL) {
                    limpiar_pantalla();
                    printf("*** La lista esta vacia ***\n\n");
                } else {
                    id_duplicar = lee_numero("\n\tID a duplicar: ");
                    limpiar_pantalla();
                    if (duplicar_nodo(&lista, id_duplicar) == 0) {
                        limpiar_pantalla();
                        printf("Se duplico el nodo con ID %d\n\n", id_duplicar);
                    } else {
                        limpiar_pantalla();
                        printf("No se encontró un nodo con ID %d\n\n", id_duplicar);
                    }
                
                }
                break;

            case 3:  // extraer nodo
                if (lista == NULL) {  // si NULL esta vacia
                    limpiar_pantalla();
                    printf("*** La lista esta vacia ***\n\n");
                } else {
                    id = lee_numero("\n\tId a extraer: ");
                    limpiar_pantalla();
                    if ((nodo_extraido = extraer_elemento(&lista, id)) != NULL) {  //  !devuelve NULL; si encontró
                        printf("Nodo [%d] extraido\n", nodo_extraido->id);
                    } else {
                        printf("No se encontró el ID [%d], en la lista...\n\n", id);
                    }
                }
                break;

            case 4:  // imprimir lista
                limpiar_pantalla();
                imprimir_lista(lista);
                break;

            case 5: // buscar nodo
                if (lista == NULL) {
                    limpiar_pantalla();
                    printf("*** La lista esta vacia ***\n\n");
                } else {
                    id = lee_numero("\n\tIntroduce el ID a buscar: ");
                    if ((nodo_buscar = buscar(lista, id)) != NULL) {
                        limpiar_pantalla();
                        printf("Se encontró el nodo con ID [%d]\n\n", nodo_buscar->id);
                    } else {
                        limpiar_pantalla();
                        printf("No se encontró el nodo con ID [%d]\n\n", id);
                    }
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
