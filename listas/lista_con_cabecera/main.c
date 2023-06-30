#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main(void) {
    Cabecera *cabecera = crear_cabecera(); // Puntero que despues apuntara al inicio de la lista
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
                    insertar_orden(cabecera, nuevo_nodo);
                    printf("\tNodo agregado: [%d]\n\n", id);
                }
                break;

            case 2:  // duplicar nodo
                if (cabecera->inicio == NULL) {
                    limpiar_pantalla();
                    printf("*** La lista esta vacia ***\n\n");
                } else {
                    id_duplicar = lee_numero("\n\tID a duplicar: ");
                    limpiar_pantalla();
                    if (duplicar_nodo(cabecera, id_duplicar) == 0) {
                        limpiar_pantalla();
                        printf("Se duplico el nodo con ID [%d]\n\n", id_duplicar);
                    } else {
                        limpiar_pantalla();
                        printf("No se encontró un nodo con ID [%d]\n\n", id_duplicar);
                    }
                
                }
                break;

            case 3:  // extraer nodo
                if (cabecera->inicio == NULL) {  // si NULL esta vacia
                    limpiar_pantalla();
                    printf("*** La lista esta vacia ***\n\n");
                } else {
                    id = lee_numero("\n\tId a extraer: ");
                    limpiar_pantalla();
                    if ((nodo_extraido = extraer_elemento(cabecera, id)) != NULL) {  //  !devuelve NULL; si encontró
                        printf("Nodo [%d] extraido\n", nodo_extraido->id);
                    } else {
                        printf("No se encontró el ID [%d], en la lista...\n\n", id);
                    }
                }
                break;

            case 4:  // imprimir lista
                limpiar_pantalla();
                imprimir_lista(cabecera);
                break;

            case 5:
                limpiar_pantalla();
                printf("Cantidad de elementos en lista: [%d]\n\n", tamanio_lista(cabecera));
                break;

            case 6: // buscar nodo
                if (cabecera->inicio == NULL) {
                    limpiar_pantalla();
                    printf("*** La lista esta vacia ***\n\n");
                } else {
                    id = lee_numero("\n\tIntroduce el ID a buscar: ");
                    if ((nodo_buscar = buscar(cabecera, id)) != NULL) {
                        limpiar_pantalla();
                        printf("Se encontró el nodo con ID [%d]\n\n", nodo_buscar->id);
                    } else {
                        limpiar_pantalla();
                        printf("No se encontró el nodo con ID [%d]\n\n", id);
                    }
                }
                break;

            case 7:  // salir
                printf("\n\n\tSaliendo...\n");
                break;

            default:
                limpiar_pantalla();
                printf("*** Opcion invalida ***\n");
                break;
        }
    } while (opcion != 7);

    return 0;
}
