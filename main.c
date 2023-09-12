#include <stdio.h>


/*estas funciones (adentro y afuera ) se ocuparan de realizar la logica correspondeinte para cada caso*/
void adentro();

void afuera();
/*crea la reserva de la mesa */
void reserva();

/*menu de opciones*/
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
        printf("Opcion no valida\n");
        menu();
        break;
    }

}


void main(){
    printf("Reservas.... \n");

    menu();

}

void adentro(){
    printf("Adentro");
}

void afuera(){
    printf("Afuera");
}

void reserva(){



}