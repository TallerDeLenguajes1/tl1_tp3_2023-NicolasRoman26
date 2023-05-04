#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CLIENTES 5
#define MAX_PRODUCTOS 10

char *TiposProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct {
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
} Producto;

typedef struct {
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
    float TotalAPagar;
} Cliente;

// función que calcula el costo total de un producto
float calcularCostoProducto(Producto *producto) {
    return producto->Cantidad * producto->PrecioUnitario;
}

int main() {
    int i, j, numClientes;
    srand(time(NULL));
    
    // se solicita la cantidad de clientes a ingresar
    printf("Ingrese la cantidad de clientes a cargar (maximo %d): ",MAX_CLIENTES);
    scanf("%d",&numClientes);
    
    // se reserva la memoria dinámica para los clientes
    Cliente *clientes = malloc(sizeof(Cliente) * numClientes);

    // se cargan los datos de los clientes
    for (i = 0; i < numClientes; i++) {
        clientes[i].ClienteID = i+1;

        // se reserva la memoria dinámica para el nombre del cliente
        clientes[i].NombreCliente = malloc(sizeof(char) * 30);
        printf("Ingrese el nombre del cliente %d: ",clientes[i].ClienteID);
        scanf("%s",clientes[i].NombreCliente);

        // se genera aleatoriamente la cantidad de productos a pedir
        clientes[i].CantidadProductosAPedir = rand()%5 + 1;
        clientes[i].Productos = malloc(sizeof(Producto) * clientes[i].CantidadProductosAPedir);

        // se cargan los datos de los productos de cada cliente
        printf("Ingrese los productos correspondientes al cliente %d:\n",clientes[i].ClienteID);
        for (j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            clientes[i].Productos[j].ProductoID = j+1;
            clientes[i].Productos[j].Cantidad = rand()%10 + 1;
            clientes[i].Productos[j].PrecioUnitario = (float)(rand()%91 + 10);  // PrecioUnitario entre 10 y 100
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand()%5];  // TipoProducto aleatorio del arreglo TiposProductos
        }

        // se calcula el total a pagar por el cliente
        clientes[i].TotalAPagar = 0;
        for (j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            clientes[i].TotalAPagar += calcularCostoProducto(&clientes[i].Productos[j]);
        }

        printf("\n");
    }

    // se muestra por pantalla la información de los clientes y sus productos
    printf("Resumen de la carga realizada:\n\n");
    for (i = 0; i < numClientes; i++) {
        printf("Cliente %d\nNombre: %s\nProductos:\n",clientes[i].ClienteID,clientes[i].NombreCliente);
        for (j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            printf("  Producto %d\n  Cantidad: %d\n  Tipo: %s\n  Precio Unitario: %.2f\n",clientes[i].Productos[j].ProductoID,clientes[i].Productos[j].Cantidad,clientes[i].Productos[j].TipoProducto,clientes[i].Productos[j].PrecioUnitario);
        }
        printf("Total a pagar por el cliente: %.2f\n\n",clientes[i].TotalAPagar);
    }

    // liberación de la memoria dinámica reservada
    for (i = 0; i < numClientes; i++) {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
    free(clientes);

    return 0;
}
