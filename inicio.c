#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void opcion();
void registro();
void opExitosa();
void Transferencia();

struct cliente
{
    char nombre[50];
    char apellido[50];
    int numeroCelular;
    int numeroTarjeta;
    char contrasenaNIP[4];
    float saldo;
};

int main()
{
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
}