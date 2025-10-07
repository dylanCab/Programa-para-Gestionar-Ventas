#include <stdio.h>
#include <string.h>

int main()
{
    char ID[15];
    char name[50];
    int stock;
    float precio;
    char ans[2];
    int venta = 0;
    int ventas = 0;
    float ganancia;
    int accion;
    printf("Bienvenido!\nPor favor, registre su producto\n");
    do
    {
        printf("Ingrese ID del producto:");
        scanf("%s", ID);
        printf("Ingrese el nombre del producto:");
        while (getchar() != '\n')
            ;
        fgets(name, sizeof(name), stdin);
        printf("Ingrese la cantidad en stock:");
        scanf("%d", &stock);
        printf("Ingrese el precio unitario del producto:");
        scanf("%f", &precio);
        printf("Ha introducido los datos correctamente?\nResponda Si o No:");
        scanf("%s", ans);
    } while (strcmp(ans, "Si") != 0);
    do
    {
        printf("\tQue desea realizar?\n\t1 - Registrar venta\n\t2 - Reabastecer el producto\n\t3 - Consultar informacion del producto\n\t4 - Consultar ganancias\n\t5 - Salir del programa\nIngrese un numero:");
        scanf("%d", &accion);
        if (accion < 1 || accion > 5)
        {
            printf("Intentelo nuevamente\n");
        }
        else
        {
            switch (accion)
            {
            case 1:
                printf("Cuantas unidades desea vender?\n");
                scanf("%d", &venta);
                if (venta > stock)
                {
                    printf("Venta negada! No hay suficientes unidades disponibles\nStock actual:%d", stock);
                }
                else
                {
                    stock = stock - venta;
                    ventas = ventas + venta;
                    printf("Venta exitosa!\nStock actual:%d\n", stock);
                }
                printf("Pulse enter para continuar...");
                getchar();
                getchar();
                break;
            case 2:
                printf("Cuantas unidades desea reabastecer?\n");
                scanf("%d", &venta);
                stock = stock + venta;
                printf("Reabastecimiento exitoso!\nStock actual:%d\nPulse enter para continuar...", stock);
                getchar();
                getchar();

                break;
            case 3:
                printf("Que desea consultar?\n\t1 - ID\n\t2 - Nombre del producto\n\t3 - Cantidad en stock\n\t4 - Precio Unitario\nIngrese un numero:");
                int consulta;
                scanf("%d", &consulta);
                switch (consulta)
                {
                case 1:
                    printf("%s\n", ID);
                    break;
                case 2:
                    printf("%s\n", name);
                    break;
                case 3:
                    printf("%d\n", stock);
                    break;
                case 4:
                    printf("%.2f\n", precio);
                    break;
                }
                
                printf("Pulse enter para continuar...");
                getchar();
                getchar();

            case 4:
                ganancia = ventas * precio;
                printf("Unidades vendidas:%d\nIngreso total:%.2f\n", ventas, ganancia);
                printf("Pulse enter para continuar...");
                getchar();
                getchar();

                break;
            case 5:
                printf("Hasta pronto");
                break;
            default:
                break;
            }
            printf("\n\n");
        }

    } while (accion != 5);
}