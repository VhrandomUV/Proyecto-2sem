// Brandon Villalobos S2, Javier Maturana S2, Felipe Astudillo S1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// precios mesas
#define P_M2 1500
#define P_M4 2000
#define P_M6 2500

// cantidad de mesas total
#define CANT_MESAS_T 6
// cabtidad de mesas adentro y afuera
#define MESAS_ADENTRO 3
#define MESAS_AFUERA 3

// sirve para almacenar el costo total de la/s reserva/s
int precio = 0;


struct Mesas
{
    int cap;      // capaciad
    int prec;     // precio
    char ubi[10]; // adentro ; afuera
    char disp[7]; // libre ; ocupado
};
struct Mesas mesa[CANT_MESAS_T];

// menu principal
void menu();

// extraee el num de personas que comeran en un mesas
int num_personas();

// genera las mesas y sus caracteristicas
void generador();

// hace la reserva
void reserva();

// pregunta si quiere continuar el peograma
void continuar();
// genera las estadisticas
void estadistica();

void main()
{

    printf("Reservas.... \n");
    
    generador();
    menu();
    printf("costo final: $%d\n", precio);
}

void menu()
{

    int opcion;
    printf("Seleccione el tipo de mesa: \n");
    printf("1.- Adentro\n");
    printf("2.- Afuera\n");
    printf("3.- Salir\n");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        reserva("adentro");
        break;
    case 2:
        reserva("afuera");
        break;
    case 3:
        break;

    default:
        printf("Opcion no valida\n");
        menu();
    }
}

int num_personas()
{
    int n_personas;
    printf("ingrese cuantas personas comeran en la mesa (de 1 a 6 personas): ");
    scanf("%d", &n_personas);

    n_personas = n_personas + n_personas % 2;
    if (n_personas >= 2 && n_personas <= 6)
    {
        return (n_personas);
    }

    else
        printf("numero no valido\n");
    num_personas();
}

void generador()
{
    FILE *archivo;
    int i = 0;

    archivo = fopen("mesas.txt", "r");

    while (i < CANT_MESAS_T)
    {
        fscanf(archivo, "%d %d %s %s", &mesa[i].cap, &mesa[i].prec, mesa[i].ubi, mesa[i].disp);
        i++;
    }
    i = 0;
    while (i < CANT_MESAS_T)
    {
        printf("%d %d %s %s\n", mesa[i].cap, mesa[i].prec, mesa[i].ubi, mesa[i].disp);
        i++;
    }

    fclose(archivo);
    // free(ptr);
}

void reserva(char *ubi)
{
    FILE *archivo;
    int n = num_personas();
    int reserva = 0;
    int i = 0;
    archivo = fopen("mesas.txt", "w+");

    i = 0;
    while (i < CANT_MESAS_T)
    {
        if ((mesa[i].cap == n) && (strcmp("libre", mesa[i].disp) == 0) && (strcmp(ubi, mesa[i].ubi)==0))
        {
            printf("CONDICION\n");
            strcpy(mesa[i].disp, "ocupado");
            fprintf(archivo, "%d %d %s %s\n", mesa[i].cap, mesa[i].prec, mesa[i].ubi, mesa[i].disp);
            precio += mesa[i].prec;
            reserva = 1;
        }

        else
        {
            fprintf(archivo, "%d %d %s %s\n", mesa[i].cap, mesa[i].prec, mesa[i].ubi, mesa[i].disp);
        }

        ++i;
    }

    fclose(archivo);

    if (reserva == 1)
    {
        printf("mesa reservada\n");
        printf("total: %d \n", precio);
    }
    else
    {
        printf("no se  en contro una mesa con esas caracteristicas \n");
    }

    estadistica();

    continuar();
}

void continuar()
{
    int opcion;
    printf("Quiere seguir usando el programa? \n1.Si\n2.No\n");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        generador();
        menu();

    case 2:

        break;

    default:
        printf("opcion invalida \n");
        continuar();
    }
}

void estadistica()
{
    int i = 0;
    int cont_adentro = 0;
    int cont_afuera = 0;
    int cont_cap2=0;
    int cont_cap4=0;
    int cont_cap6=0;

    while (i < CANT_MESAS_T)
    {
        printf("%d %d %s %s\n", mesa[i].cap, mesa[i].prec, mesa[i].ubi, mesa[i].disp);
        i++;
    }

    for (i = 0; i < CANT_MESAS_T; i++)
    {

        if ((strcmp("ocupado", mesa[i].disp) == 0) && (strcmp("adentro", mesa[i].ubi) == 0))
        {
            cont_adentro++;
        }
        if ((strcmp("ocupado", mesa[i].disp) == 0) && (strcmp("afuera", mesa[i].ubi) == 0))
        {
            cont_afuera++;
        }

        if ((strcmp("ocupado", mesa[i].disp) == 0) && (mesa[i].cap == 2)){
            cont_cap2++;
         }
        if ((strcmp("ocupado", mesa[i].disp) == 0) && (mesa[i].cap == 4)){
            cont_cap4++;
        }
        if ((strcmp("ocupado", mesa[i].disp) == 0) && (mesa[i].cap == 6)){
            cont_cap6++;
        }
    }
    


        


    float porcent_cap2 = cont_cap2 * 100 / 2;
    float porcent_cap4 = cont_cap4 * 100 /2;
    float porcent_cap6 = cont_cap6 * 100 / 2;
    
    float porcent_afuera = cont_afuera * 100 / MESAS_AFUERA;
    float porcent_adentro = cont_adentro * 100 / MESAS_ADENTRO;
    float porcent_total = (cont_adentro + cont_afuera) * 100 / (CANT_MESAS_T);

    printf("Mesas para 2 personas ocupadas: %.2f%%\n", porcent_cap2);
    printf("Mesas para 4 personas ocupadas: %.2f%%\n", porcent_cap4);
    printf("Mesas para 6 personas ocupadas: %.2f%%\n", porcent_cap6);

    printf("mesas interiores ocupadas: %.2f%% \n", porcent_adentro);
    printf("mesas exteriores ocupadas: %.2f%% \n", porcent_afuera);

    printf("total de mesa ocupadas: %.2f%% \n", porcent_total);
    
}
