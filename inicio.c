#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>


#define MAX_NOMBRE 50
#define MAX_CLIENTES 1000

void opcion();
void registro();
void DepoDinero();
void Radomizer();

int Suma_cliente = 0;
char nombre[MAX_CLIENTES][MAX_NOMBRE];
char apellidos[MAX_CLIENTES][MAX_NOMBRE];
int numeroCelular;
int numeroTarjeta [16];
int contrasenaNIP[4];
float saldo;


int main()
{
    printf("\nBuen dia, este es un sistema bancario. (Presiona cualquier tecla para entrar al menu.) \n");
    getch();
    opcion();
    return 0;
}

void opcion()
{
    system("cls");
    int selec;
    printf("\n1. Registrar a un nuevo cliente\n2. Depositar dinero a cuenta propia\n3. Verificar saldo en tarjeta\n4. Transferir dinero a otras cuentas\n5. Recargar tiempo aire\n6. Cambiar NIP\n7. Salir\n");
    printf("\nIngresa tu opcion:\n");
    scanf("%d", &selec);


    switch (selec) {
        case 1:
            registro();
            break;
        case 2:
            DepoDinero();
            break;
        case 3:
            // Implementar lógica para verificar saldo
            break;
        case 4:
            // Implementar lógica para transferir dinero
            break;
        case 5:
            // Implementar lógica para recargar tiempo aire
            break;
        case 6:
            // Implementar lógica para cambiar NIP
            break;
        case 7:
            printf("Saliendo del sistema...\n");
            return;
        default:
            system("cls");
            printf("Caracter no valido\n");
            Sleep(3000);
            system("cls");
            opcion();
    }
}

void registro() 
{
    system("cls");
    if (Suma_cliente <= MAX_CLIENTES) 
    {

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("Introduce el Nombre/s del Cliente: ");
        fgets(nombre[Suma_cliente], MAX_NOMBRE, stdin);
        nombre[Suma_cliente][strcspn(nombre[Suma_cliente], "\n")] = 0; 

        printf("\nIntroduce los Apellidos del Cliente: ");
        fgets(apellidos[Suma_cliente], MAX_NOMBRE, stdin);
        apellidos[Suma_cliente][strcspn(apellidos[Suma_cliente], "\n")] = 0; 

        printf("\nIntroduce el N%cmero de Celular: ",163);
        scanf("%d", &numeroCelular);
        getchar(); 

        printf("\nGenerando el n%cmero de Tarjeta: ",163);
        Radomizer();
        printf("\n\033[1;31mGuardar este Numero ya que es el numero de tu tarjeta (Enter para continuar)\033[0m\n");
        getchar();
        
        printf("Introduce la Contrase%ca NIP (4 d%cgitos): ",164,161);
        scanf("%4d", contrasenaNIP);
        getchar(); 

        printf("\nIntroduce el Saldo inicial: ");
        scanf("%f", &saldo);
        getchar(); 

        Suma_cliente++;
        printf("\n\nRegistro exitoso.\n");
        getch();
        opcion();
    } else {
        printf("No se pueden registrar más clientes.\n");
        getch();
        opcion();
    }
     getch();
}
    


void DepoDinero();
{
    printf("D%cgite su Numero de Tarjeta",161);
}

void Radomizer()
{
  srand(time(NULL));
  int i;
  for( i= 0; i <= 16; i++)
  {
    numeroTarjeta [i] = rand()%10;
  }
  for (i= 0; i < 16; i++)
  {
    printf("%d",numeroTarjeta [i]);
  }
  
}
