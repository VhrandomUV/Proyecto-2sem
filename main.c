#include <stdio.h>

#define P_M2 1500
#define P_M4 2000
#define P_M6 2500



struct Mesas
{
    int cap;
    char ubi[20]; // adentro ; afuera
    int prec;
    char disp[20]; // libre ; ocupado

};





/*estas funciones (adentro y afuera ) se ocuparan de realizar la logica correspondeinte para cada caso*/
void adentro();

void afuera();
/*crea la reserva de la mesa */
void reserva();

/* comprueba si la mesa esta disponible*/
void disponibilidad();

/*menu de opciones*/
void menu();



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
void disponibilidad(){

}

void menu(){
    int opcion;
    printf("Seleccione el tipo de mesa: \n");
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
        }

}