#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Declaración de funciones
void opcion();
void registro();
void opExitosa();
void Transferencia();
void recargarTiempoAire();

// Estructura para almacenar clientes
struct cliente
{
    char nombre[50];
    char apellido[50];
    int numeroCelular;
    int numeroTarjeta;
    char contrasenaNIP[5]; // Incluye espacio para el terminador nulo
    float saldo;
}s[10];

int totalClientes = 0; // Contador de clientes registrados

int main()
{
    printf("\nBuen dia, este es un sistema bancario, por favor seleccione la accion que quisiera hacer: \n");
    opcion(); 
    return 0;
}

void opcion()
{
    int selec;
    printf("\n1. Registrar a un nuevo cliente\n2. Depositar dinero a cuenta propia\n3. Verificar saldo en tarjeta\n4. Transferir dinero a otras cuentas\n5. Recargar tiempo aire\n6. Cambiar NIP\n7. Salir\n");
    printf("\nIngresa tu opcion:\n");
    scanf("%d", &selec);   
    switch (selec)
    {
        case 1:
            registro();
            break;
        case 4:
            Transferencia();
            break;
        case 5:
            recargarTiempoAire();
            break;
        default:
            printf("Ninguna de las opciones son validas\n");
            break;
    }
}

void registro()
{
    if (totalClientes >= 10)
    {
        printf("\nNo se pueden registrar más clientes.\n");
        system("pause");
        opcion();
    }

    struct cliente nuevoCliente;
    printf("Ingrese su Nombre:\n");
    scanf("%s", nuevoCliente.nombre);
    printf("\nIngrese sus Apellidos:\n");
    scanf("%s", nuevoCliente.apellido);
    printf("\nIngrese su Numero de Celular:\n");
    scanf("%d", &nuevoCliente.numeroCelular);
    printf("\nIngrese su Numero de tarjeta:\n");
    scanf("%d", &nuevoCliente.numeroTarjeta);
    printf("\nIngrese su NIP (4 digitos):\n");
    scanf("%s", nuevoCliente.contrasenaNIP);
    nuevoCliente.saldo = 3500; // Saldo inicial

    s[totalClientes] = nuevoCliente;
    totalClientes++;
    opExitosa();
}

void opExitosa()
{
    system("cls");
    printf("\n\nOperacion exitosa\n");
    system("pause");
    system("cls");
    opcion();
}

void Transferencia()
{
    int i, celltrans, nip, aux = 0;
    float valor;

    system("cls");
    printf("Ingrese Numero de Telefono:  ");
    scanf("%i", &celltrans);

    printf("Ingrese su NIP: ");
    scanf("%i", &nip);

    for (i = 0; i < totalClientes; i++)
    {
        if (celltrans == s[i].numeroCelular && atoi(s[i].contrasenaNIP) == nip)
        {
            do
            {
                printf("Ingrese valor a transferir: $");
                scanf("%f", &valor);
            } while (valor > s[i].saldo);

            s[i].saldo -= valor;
            aux = 1;
            break;
        }
    }

    if (aux == 0)
    {
        printf("\nError al realizar transferencia.\n");
    }
    else
    {
        printf("\nTransferencia realizada con exito.\n");
    }

    system("pause");
    system("cls");
    opcion();
}

void recargarTiempoAire()
{
    int i, celltrans, nip, aux = 0;
    float montoRecarga;
    int compania, celularRecarga;

    system("cls");
    printf("Ingrese su Numero de Telefono: ");
    scanf("%i", &celltrans);

    printf("Ingrese su NIP: ");
    scanf("%i", &nip);

    for (i = 0; i < totalClientes; i++)
    {
        if (celltrans == s[i].numeroCelular && atoi(s[i].contrasenaNIP) == nip)
        {
            printf("\nBienvenido, %s %s\n", s[i].nombre, s[i].apellido);
            printf("Saldo disponible: $%.2f\n", s[i].saldo);

            printf("\nSeleccione la compania de tiempo aire:\n1. AT&T\n2. Telcel\n3. Movistar\n");
            scanf("%d", &compania);

            if (compania < 1 || compania > 3)
            {
                printf("\nCompania no valida. Regresando al menu.\n");
                system("pause");
                opcion();
                return;
            }

            printf("\nIngrese el monto a recargar:\n");
            scanf("%f", &montoRecarga);

            if (montoRecarga > s[i].saldo)
            {
                printf("\nError: Saldo insuficiente. Intente de nuevo.\n");
                system("pause");
                opcion();
                return;
            }

            printf("\nIngrese el numero de celular al que desea recargar:\n");
            scanf("%d", &celularRecarga);

            printf("\nConfirme los datos:\n");
            printf("Compania: %s\n", (compania == 1) ? "AT&T" : (compania == 2) ? "Telcel" : "Movistar");
            printf("Numero recargado: %d\n", celularRecarga);
            printf("Monto a recargar: $%.2f\n", montoRecarga);
            printf("Saldo restante despues de la recarga: $%.2f\n", s[i].saldo - montoRecarga);
            printf("\n¿Es correcto? (1. Si / 2. No): ");

            int confirmar;
            scanf("%d", &confirmar);

            if (confirmar == 1)
            {
                s[i].saldo -= montoRecarga;
                printf("\nRecarga exitosa!\n");
                printf("Numero recargado: %d\n", celularRecarga);
                printf("Monto recargado: $%.2f\n", montoRecarga);
                printf("Nuevo saldo: $%.2f\n", s[i].saldo);
            }
            else
            {
                printf("\nReingresando los datos...\n");
                recargarTiempoAire();
            }

            system("pause");
            system("cls");
            opcion();
            return;
        }
    }

    printf("\nDatos incorrectos. Intente de nuevo.\n");
    system("pause");
    opcion();
}
