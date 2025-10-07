#include <stdio.h>
#include <string.h>

int main() {
    char ID[15];
    char name[15];
    int stock;
    float precio;
    char ans[2];
    int venta;
    float ganancia;
    int accion;
printf("Bienvenido!\nPor favor, registre su producto\n");
do{
printf("Ingrese ID del producto:");
scanf("%s", &ID);
printf("Ingrese el nombre del producto:");
scanf("%s", &name);
printf("Ingrese la cantidad en stock:");
scanf("%d", &stock);
printf("Ingrese el precio unitario del producto:");
scanf("%f", &precio);
printf("Ha introducido los datos correctamente?\nResponda Si o No:");
scanf("%s",&ans);
}while(strcmp(ans, "Si")!=0);
do{
printf("¿Que desea realizar?\n1 - Vender el producto\n2 - Reabastecer el producto\n3 - Consultar informacion del producto\n4 - Consultar ganancias\n5 - Salir del programa\n Ingrese un numero:");

do{
scanf("%d", &accion);
if(accion<1||accion>5){
    printf("Intentelo nuevamente");
}
}while(accion<1||accion>5);

switch(accion){
    case 1:
        printf("¿Cuantas unidades desea vender?\n");
        scanf("%d", &venta);
        if(venta>stock){
            printf("Venta negada! No hay suficientes unidades disponibles\nStock actual:%d", stock);
            
        }else{
            stock=stock-venta;
            printf("Venta exitosa!\nStock actual:%d", stock);
        }
            
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        printf("Hasta pronto");
        break;
    default:
        break;
}
printf("\n\n");
}while(accion!=5);

}