#include <stdio.h>
#include <stdlib.h>


#define P_M2 1500
#define P_M4 2000
#define P_M6 2500
#define CANT_MESAS 3
int prices[CANT_MESAS] = {P_M2, P_M4, P_M6};


int precio = 0;

struct Mesas
{
    int cap;
    int prec;
    char *disp; // libre ; ocupado
    char *ubi; // adentro ; afuera
};
struct Mesas mesa[2][CANT_MESAS];



void menu();

int num_personas();

void generador();

void reserva();

void continuar();

void estadistica();



void main(){
printf("Reservas.... \n");
    generador();    
    menu();
    printf("coto final: $%d\n", precio);
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
        reserva(0);
        break;
    case 2:
        reserva(1);
        break;
    case 3:
        break;
    
    default:
        printf("Opcion no valida\n");
        menu();
        }
    
}

int num_personas(){
    int n_personas;
    printf("ingrese cuntas personas comeran en la mesa (de 1 a 6 perosnas): ");
    scanf("%d", &n_personas);

    n_personas = n_personas + n_personas%2;
    if (n_personas >= 2 && n_personas <= 6){
        return(n_personas);
    }
    
    else
        printf("numero no valido\n");
        num_personas();
        
    
}



void generador(){
    int i = 0;
    int n = 2;
    int * ptr;
    ptr = (int*)malloc(CANT_MESAS*sizeof(int));
    
    for (i = 0; i < CANT_MESAS; i++){
        ptr[i] = prices[i];
    }
    

    
    for(i = 0; i < CANT_MESAS; i++){
        mesa[0][i].ubi = "adentro";
        mesa[0][i].cap = n;
        n +=2;
        mesa[0][i].disp ="libre";
        mesa[0][i].prec = ptr[i];
        
        
    }

    n =2;
    for(i = 0; i < CANT_MESAS; i++){
        mesa[1][i].ubi = "afuera";
        mesa[1][i].cap = n;
        n +=2;
        mesa[1][i].disp  = "libre";
        mesa[1][i].prec = ptr[i];
        
        
    }
    free(ptr);
}


void reserva(int ubi){
    int n = num_personas();
    int reserva = 0;
    

    for(int i = 0; i<CANT_MESAS; i++){
        if(mesa[ubi][i].cap == n && mesa[ubi][i].disp == "libre"){
            mesa[ubi][i].disp = "ocupado";
            reserva  = 1;
            precio += mesa[ubi][i].prec;
            
        }
        
    }
    if (reserva == 1){
            printf("mesa reservada\n");
            printf("total: %d \n", precio);
                   
        }
    else
        printf("no se  en contro una mesa con esas caracteristicas \n ");


    estadistica();


    
        
continuar();

}


void continuar(){
    int opcion;
    printf("Quiere seguir usando el programa? \n1.Si\n2.No\n");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        menu();
        

    case 2:
        
        break;
    
    default:
        printf("opcion invalida \n");
        continuar();
    }
}

void estadistica(){
    int i = 0;
    int cont_adentro = 0;
    int cont_afuera = 0;
    

    for (i = 0; i<CANT_MESAS; i++){

        if (mesa[0][i].disp == "ocupado"){
            cont_adentro ++;       
            
        }
        
    }

    for (i = 0; i<CANT_MESAS; i++){

        if (mesa[1][i].disp == "ocupado"){
            cont_afuera ++ ;
            
        }
        
    }

   

    
    float porcent_afuera = cont_afuera * 100 / CANT_MESAS;
    float porcent_adentro = cont_adentro * 100 / CANT_MESAS;
    float porcent_total = (cont_adentro + cont_afuera) * 100 / (CANT_MESAS * 2);

    printf("mesas interiores ocupadas: %.2f%% \n", porcent_adentro);
    printf("mesas exteriores ocupadas: %.2f%% \n", porcent_afuera);
    printf("total de mesa ocupadas: %.2f%% \n", porcent_total);
}
