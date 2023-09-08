#include <stdio.h>



void adentro(){
    printf("Adentro");
}

void afuera(){
    printf("Afuera");
}



void menu(){
    int opcion;
    printf("1.- Adentro\n");
    printf("2.- Afuera\n");
    printf("3.- Salir\n");
    scanf("%d", &opcion);


    switch (opcion)
    {
    case 1:
        adentro();
        break;
    case 2:
        afuera();
        break;
    case 3:
        break;
    
    default:
        printf("Opcion no valida");
        menu();
        break;
    }

}


void main(){
    printf("Reservas.... \n");

    menu();

}

