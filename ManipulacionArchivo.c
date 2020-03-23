#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "ManipulacionArchivo.h"
Facultad *crearFacultad(){
    Facultad *nuevaFacultad;
    nuevaFacultad = (Facultad *)malloc(MAX_FACULTADES*sizeof(Facultad));
    if(nuevaFacultad == NULL){
        printf("No hay espacio suficiente para crear nuevaFacultad");
        exit(0);
    }
    for(int i = 0; i <= MAX_FACULTADES; i++){
        nuevaFacultad[i].cafeteria = (Cafeteria *)malloc(MAX_CAFETERIAS*sizeof(Cafeteria));
        if(nuevaFacultad[i].cafeteria == NULL){
            printf("No hay espacio suficiente para crear cafeteria");
            exit(0);
        }
    }
    for (int i = 0; i <= MAX_FACULTADES; i++){
        for(int x = 0; x <= MAX_CAFETERIAS; x++){
            nuevaFacultad[i].cafeteria[x].platillo = (Platillo *)malloc(MAX_PLATILLOS*sizeof(Platillo));
            if(nuevaFacultad->cafeteria->platillo == NULL){
                printf("No hay espacio suficiente para crear platillo");
                exit(0);
            }
        }
    }
    return nuevaFacultad;
}
//Llenar Archivo de Texto(Extra)
void LlenarArchivo(){
    Lectura lectura;
    FILE *ptr;
    ptr = fopen("Cafeterias-Facultades-CU/Menus.txt","a+");
    for(int n = 0; n < 16; n++){
        printf("\nNombre de la Facutad: ");
        __fpurge(stdin);
        fgets(lectura.nombreFacultad, MAX_TEXT, stdin);
        strtok(lectura.nombreFacultad, "\n");
        printf("\tNombre Cafeteria: ");
        __fpurge(stdin);
        fgets(lectura.nombreCafeteria,MAX_TEXT,stdin);
        strtok(lectura.nombreCafeteria, "\n");
        for(int i = 0; i < MAX_PLATILLOS; i++){
            __fpurge(stdin);
            printf("\t\tNombre Platillo: ");
            fgets(lectura.nombrePlatillo[i],MAX_TEXT,stdin);
            strtok(lectura.nombrePlatillo[i], "\n");
            __fpurge(stdin);
            printf("\t\tID del platillo: ");
            scanf("%i",&(lectura.idPlatillo[i]));
            printf("\t\tPrecio del platillo: ");
            scanf("%f",&(lectura.precio[i]));
        }
        fwrite(&lectura,sizeof(Lectura),1,ptr);
    }
    fclose(ptr);
}
//Obtener Datos del Archivo
void ObtenerDatos(Facultad *facultad){
    Lectura lectura;
    int cont = 1, count = 0, i = 0,j = 0, x = 0;
    FILE *ptr;
    ptr = fopen("Cafeterias-Facultades-CU/Menus.txt","r");
    while(!feof(ptr)){
        fread(&lectura,sizeof(Lectura),1,ptr);
        if(count < 18){
            cont++;
            if(cont == 2){
                strcpy(facultad[x].nombreFacultad, lectura.nombreFacultad);
                cont = 0;
                i = 0;
                x++;
            }
            strcpy(facultad[(x-1)].cafeteria[i].nombreCafeteria, lectura.nombreCafeteria);
            for(int j = 0; j < MAX_PLATILLOS; j++){
                strcpy(facultad[(x-1)].cafeteria[i].platillo[j].nombrePlatillo,lectura.nombrePlatillo[j]);
                facultad[(x-1)].cafeteria[i].platillo[j].idPlatillo = lectura.idPlatillo[j];
                facultad[(x-1)].cafeteria[i].platillo[j].precio = lectura.precio[j];
            }
            i++;
        }
        count++;
    }
    fclose(ptr);
}
//Lista Todo las Facultades con sus cafeterias y menus (Prueba)
void listarEstructura(Facultad *facultad){
    for(int i = 0; i < MAX_FACULTADES; i++){
        printf("Nombre de la Facutad: %s\n",facultad[i].nombreFacultad);
        for(int j = 0; j < MAX_CAFETERIAS; j++){
            printf("\tNombre Cafeteria: %s\n",facultad[i].cafeteria[j].nombreCafeteria);
            for(int x = 0; x < MAX_PLATILLOS; x++){
                printf("\t\t-----------------------------------\n");
                printf("\t\tNombre Platillo: %s\n",facultad[i].cafeteria[j].platillo[x].nombrePlatillo);
                printf("\t\tID Platillo: %i\n",facultad[i].cafeteria[j].platillo[x].idPlatillo);
                printf("\t\tPrecio Platillo: %.2f\n",facultad[i].cafeteria[j].platillo[x].precio);
                printf("\t\t-----------------------------------\n");
            }
        }
    }
}
void PausarPantalla(){
    printf("Selecciona Cualquier Tecla para continuar.");
    getchar();
    getchar();
}
void BuscarFacultad(Facultad facultad){
    printf("\nNombre de la Facutad: %s\n",facultad.nombreFacultad);
    for(int j = 0; j < MAX_CAFETERIAS; j++){
        printf("\tNombre Cafeteria: %s\n",facultad.cafeteria[j].nombreCafeteria);
        printf("\t\t-------Menu de la cafeteria-------\n");
        for(int x = 0; x < MAX_PLATILLOS; x++){
            printf("\t\t-----------------------------------\n");
            printf("\t\tNombre Platillo: %s\n",facultad.cafeteria[j].platillo[x].nombrePlatillo);
            printf("\t\tID Platillo: %i\n",facultad.cafeteria[j].platillo[x].idPlatillo);
            printf("\t\tPrecio Platillo: %.2f\n",facultad.cafeteria[j].platillo[x].precio);
            printf("\t\t-----------------------------------\n");
        }
    }
}
void LiberarMD(Facultad *facultad){
    for (int i = 0; i < MAX_FACULTADES; i++){
        for(int x = 0; x < MAX_CAFETERIAS; x++){
            free(facultad[i].cafeteria[x].platillo);
        }
    }
    for (int i = 0; i < MAX_FACULTADES; i++){
        free(facultad[i].cafeteria);
    }
    free(facultad);
}
void generarorden(Facultad facultad){
    int opcion, codigo;
    FILE *ptr;
    printf("Las cafeterias de la facultad son: \n");
    for(int j = 0; j < MAX_CAFETERIAS; j++){
        printf("\t%d): %s\n",j+1,facultad.cafeteria[j].nombreCafeteria);
    }
    printf("Seleccione el numero de su cafeteria de eleccion: ");
    scanf("%d", &opcion);
    system("clear");
    printf("Las cafeterias de la facultad son: \n");
    for(int x = 0; x < MAX_PLATILLOS; x++){
        printf("\t\t-----------------------------------\n");
        printf("\t\tNombre Platillo: %s\n",facultad.cafeteria[(opcion-1)].platillo[x].nombrePlatillo);
        printf("\t\tID Platillo: %i\n",facultad.cafeteria[(opcion-1)].platillo[x].idPlatillo);
        printf("\t\tPrecio Platillo: %.2f\n",facultad.cafeteria[(opcion-1)].platillo[x].precio);
        printf("\t\t-----------------------------------\n");
    }
    printf("Seleccione el numero del platillo que quiere comer: ");
    scanf("%d", &codigo);
    ptr = fopen("Tickets/tickets.txt", "w+");   
    fprintf(ptr, " Con este ticket Puedes ir a recoger tu \nplatillo en la cafeteria que solicitaste\n");
    fprintf(ptr, "         Datos de su pedido \n");
    fprintf(ptr, "---------------------------------------\n");
    fprintf(ptr, "Facultad: %s\n", facultad.nombreFacultad);
    fprintf(ptr, "\tCafeteria: %s\n", facultad.cafeteria[(opcion-1)].nombreCafeteria);
    fprintf(ptr, "\t\tNombre del platillo: %s\n", facultad.cafeteria[(opcion-1)].platillo[(codigo-1)].nombrePlatillo);
    fprintf(ptr, "\t\tID del platillo: %i\n", facultad.cafeteria[(opcion-1)].platillo[(codigo-1)].idPlatillo);
    fprintf(ptr, "\t\tPrecio: $%.2f\n", facultad.cafeteria[(opcion-1)].platillo[(codigo-1)].precio);
    fprintf(ptr, "---------------------------------------\n");
    fprintf(ptr, "Recoga su pedido dentro de 10 minutos.\n");
    fprintf(ptr, "Que tenga un excelente día.\n");
    fclose(ptr);
}
void leerticket(){
    int cont=0;
    int i,j;
    char aux;
    FILE *ptr;
    ptr=fopen("Tickets/tickets.txt", "r");
    if (ptr==NULL){
        printf("Error al abrir el archivo");
        exit(1);
    }
    while((aux = fgetc(ptr)) != EOF){
		printf("%c",aux);
    }
    fclose(ptr);
}
