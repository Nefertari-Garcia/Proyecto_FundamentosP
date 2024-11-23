<<<<<<< Updated upstream
#include<stdio.h>
#include <string.h>
=======
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
>>>>>>> Stashed changes

void opcion();
void registro();
void opExitosa();

struct cliente
{
    char nombre[50];
    char apellido[50];
    int numeroCelular;
    int numeroTarjeta;
    char contrasenaNIP[4];
    float saldo;
};


void Data_Account(int *num_tel, int *contra) 
{
<<<<<<< Updated upstream
        printf("\nBuen dia, este es un sistema bancario, porfavor seleccione la accion que quisiera hacer: \n");
        opcion(); 
        return 0;
}

void opcion(){
        int selec;
        printf("\n1. Registrar a un nuevo cliente\n2. Depositar dinero a cuenta propia\n3. Verificar saldo en tarjeta\n4. Transferir dinero a otras cuentas\n5. Recargar tiempo aire\n6. Cambiar NIP\n7. Salir\n");
        printf("\nIngresa tu opcion:\n");
        scanf("%d",&selec);   
        switch (selec)
        {
        case 1:
            registro();
            break;
        
        default:
            printf("Ninguna de las opciones son validas\n");
        }
}



void registro()
{
    system("cls");
    struct cliente nuevoCliente;
    printf("Ingrese su Nombre:\n");
    scanf("%s",nuevoCliente.nombre);
    printf("\nIngrese sus Apellidos:\n");
    scanf("%s",nuevoCliente.apellido);
    printf("\nIngrese su Numero de Celular:\n");
    scanf("%d",&nuevoCliente.numeroCelular);
    printf("\nIngrese su Numero de tarjeta\n");
    scanf("%d",nuevoCliente.numeroTarjeta);
    printf("\nIngrese su Contrasena\n");
    scanf("%s",nuevoCliente.contrasenaNIP);
    opExitosa();
}

void opExitosa(){
    system("cls");
    printf("\n\nOperacion exitosa\n");
    system("pause");
    system("cls");
    opcion();
=======
    printf("Proporcione su numero de Telefono: ");
    if (scanf("%d", num_tel) != 1)  
    {
        printf("Datos No validos, Enviando al inicio.......\n");
        getch();
    }
        int main();

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Proporcione una contrase%ca de su eleccion: ",164);
    if (scanf("%d", contra) != 1) 
    {
        printf("Datos No validos, Enviando al inicio.......\n");
        getch();
    }
        int main();

    
    while ((c = getchar()) != '\n' && c != EOF);
   
}

void Val_Account(int num_tel, int contra, int V_Tel, int V_contra ) 
{

    printf("Proporcione su numero de Telefono: ");
    scanf("%d", &V_Tel);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Proporcione su contrase%ca: ",164);
    scanf("%d", &V_contra);
    
    while ((c = getchar()) != '\n' && c != EOF);

    if ( V_Tel ==  num_tel )
    {
        printf("Telefono encontrado");
    }
    else{
        printf("Telefono no encontrado");
    }

    if ( V_Tel ==  num_tel )
    {
        printf("\nContrase%ca encontrada\n", 164);
    }
    else{
        printf("\nContrase%ca no encontrada\n",164);
    }
    
    if (V_contra != contra ||  V_Tel != num_tel )
    {
        printf("Datos incorrectos, Intente de Nuevo (Precione cualquier tecla para continuar)");
        getch();
    }
    if (V_contra == contra &&  V_Tel == num_tel )
    {
        main_2( V_Tel, V_contra);
    }
    
    int main();
    
}

int main() {
    int salir = 0;
    int num_tel, contra;
    int V_tel, V_contra;
    char opcion;

        while (!salir)
        {
        system("cls");
        printf("Hola, Bienvenido al banco perrin perron\n");
        printf("Elija una opcion:\n A) Crear contrase%ca\n B) Iniciar Seccion\n C) Salir\n\nSeleccion: ",164);
        opcion = getchar();
        fflush(stdin);
        

        switch (opcion) {

            case 'A': case 'a':
                system("cls");
                Data_Account(&num_tel, &contra);
                break;

            case 'B': case 'b':
                system("cls");
                Val_Account(num_tel, contra, &V_tel, &V_contra);
                break;

            case 'C': case 'c':
                salir = 1; 
                break;

            default:
                printf("Opcion no valida\n");
                getch(); 
                break;

        }

        }
    
    getch();
    return 0;
}

int main_2(int V_Tel, int V_contra) {
    int salir = 0;
    char opcion;
    
        while (!salir)
        {
        system("cls");
        printf("Hola, Bienvenido Numero %d al banco perrin perron\n",V_Tel);
        printf("Elija una opcion:\n A) Crear contrase%ca\n B) Iniciar Seccion\n C) Salir\n\nSeleccion: ",164);
        opcion = getchar();
        fflush(stdin);
        

        switch (opcion) {

            case 'A': case 'a':
                system("cls");
                break;

            case 'B': case 'b':
                system("cls");
                break;

            case 'C': case 'c':
                salir = 1; 
                break;

            default:
                printf("Opcion no valida\n");
                getch(); 
                break;

        }

        }
    
    getch();
    return 0;

>>>>>>> Stashed changes
}