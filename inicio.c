#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define MAX_NOMBRE 50
#define MAX_CLIENTES 1000
#define MAX_TARJETA 16
#define MAX_NIP 4

void opcion();
void opcion_2();
void registro();
void Inicio_S();
void Radomizer();
void DepoDinero();

int Suma_cliente = 0;
char nombre[MAX_CLIENTES][MAX_NOMBRE];
char apellidos[MAX_CLIENTES][MAX_NOMBRE];
int numeroCelular[MAX_CLIENTES][10];
char numeroTarjeta[MAX_CLIENTES][MAX_TARJETA + 1]; 
int contrasenaNIP[MAX_CLIENTES][MAX_NIP];
float saldo;
int Num_Cliente_Act;

int main(){
    printf("\nBuen dia, este es un sistema bancario. \n");
    Sleep(1500);
    opcion();
    return 0;
}

void opcion() {
    system("cls");
    int selec;
    printf("\n1. Registrar a un nuevo cliente\n2. Iniciar seccion\n3. Salir\n");
    printf("\nIngresa tu opcion:\n");
    scanf("%d", &selec);

    switch (selec) {
        case 1:
            registro();
            break;
        case 2:
            Inicio_S();
            break;
        case 3:
            printf("Saliendo del sistema...\n");
            exit(0);
        default:
            system("cls");
            printf("Caracter no valido\n");
            Sleep(3000);
            opcion();
    }
}

void registro() {
    system("cls");

    if (Suma_cliente < MAX_CLIENTES) {
        
        getchar(); 
        printf("Introduce el Nombre/s del Cliente: ");
        fgets(nombre[Suma_cliente], MAX_NOMBRE, stdin);
        nombre[Suma_cliente][strcspn(nombre[Suma_cliente], "\n")] = 0;

        printf("\nIntroduce los Apellidos del Cliente: ");
        fgets(apellidos[Suma_cliente], MAX_NOMBRE, stdin);
        apellidos[Suma_cliente][strcspn(apellidos[Suma_cliente], "\n")] = 0; 

        printf("\nIntroduce el N%cmero de Celular: ", 163);
        scanf("%10d", &numeroCelular[Suma_cliente][10]); 
        getchar(); 

        printf("\nIntroduce la Contrase%ca NIP (4 d%cgitos): ", 164, 161);
        for (int i = 0; i < MAX_NIP; i++) {
            scanf("%1d", &contrasenaNIP[Suma_cliente][i]);  
        }

        printf("\nGenerando el n%cmero de Tarjeta...... ", 163);
        Sleep(3000);
        Radomizer();
        printf("\nTu n%cmero de tarjeta es: %s\n",163 ,numeroTarjeta[Suma_cliente]);

       
        Suma_cliente++; 
        printf("Tu N%cmero de cliente es %d",163,Suma_cliente);
        printf("\n\033[31mFavor de GUARDAR este Numero al igual del numero de cliente. \033[0m\n");
        system("pause");
        opcion();
        system("cls");
        
    } else {
        printf("No se pueden registrar más clientes.\n");
        Sleep(3000);
        opcion();
    }
}

void Inicio_S() {
    char C_Val;
    system("cls");
    
    char Veri_Num_Tarjeta[MAX_TARJETA + 1]; 
    int Veri_Nip[MAX_NIP]; 
    getchar(); 

    printf("D%cgite su numero de cliente (1 a %d): ", 161, Suma_cliente);
    scanf("%d", &Num_Cliente_Act); 
    getchar(); 

    printf("D%cgite su numero de Tarjeta : ", 161);
    fgets(Veri_Num_Tarjeta, sizeof(Veri_Num_Tarjeta), stdin);
    Veri_Num_Tarjeta[strcspn(Veri_Num_Tarjeta, "\n")] = 0; 

    printf("D%cgite su contrase%ca : ", 161, 164);
    for (int i = 0; i < MAX_NIP; i++) {
        scanf("%1d", &Veri_Nip[i]); 
    }

    // Validación
    if (strcmp(Veri_Num_Tarjeta, numeroTarjeta[Num_Cliente_Act - 1]) != 0 || 
        memcmp(Veri_Nip, contrasenaNIP[Num_Cliente_Act - 1], sizeof(contrasenaNIP[0])) != 0) {
        printf("Datos Incorrectos\n");
        printf("Intentar de Nuevo? (s/n)\n"); 
        scanf(" %c", &C_Val);
        
        if (C_Val == 'S' || C_Val == 's') {
            Inicio_S();
        } else {
            opcion();
        }
        
    }
        printf("Validacion Exitosa");
        Sleep(3000);
        opcion_2();
    }

void Radomizer() 
{
    srand(time(NULL));
    for(int i = 0; i < MAX_TARJETA; i++) 
    {
       numeroTarjeta[Suma_cliente][i] = '0' + rand() % 10; 
    }
   numeroTarjeta[Suma_cliente][MAX_TARJETA] = '\0'; 
}

 void opcion_2()
{
    system("cls");
    int selec;
    printf("Bienvenido %s ",nombre[Num_Cliente_Act - 1]);
    printf("%s que desea hacer hoy?",apellidos[Num_Cliente_Act -1]);
    printf("\n1. Depositar dinero a su cuenta\n2. Traferir Dinero a otras Cuenta\n3. Consultar Saldo de tu cuenta\n4. Cambiar NIP\n5. Recargar Tiempo Aire\n6. Salir\n");
    printf("\nIngresa tu opcion:\n");
    scanf("%d", &selec);

    switch (selec) {
        case 1:
            DepoDinero();
            break;
        case 2:
            Inicio_S();
            break;
        case 3:
            LosDineros();
            break;
        case 4:
            Inicio_S();
            break;
        case 5:
            Inicio_S();
            break;
        case 6:
            printf("Cerrando Seccion\n");
            Sleep(3000);
            opcion();
        default:
            system("cls");
            printf("Caracter no valido\n");
            Sleep(3000);
            opcion();
    }
}

void DepoDinero()
{
    float saldo_2;
        printf("Cuando MXN desea traferir : ");
        scanf("%f",&saldo_2);
        saldo += saldo_2;
        printf("Operacion Exitosa, Se le regresara en breve. . . .");
        Sleep(2000);
        opcion_2();
}

void LosDineros()
{
        printf("Saldo en esta cuenta %.2f",saldo);
        system ("pause");
}