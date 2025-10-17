#include <stdio.h>
#include <string.h>

int main()
{
    char ID[30];
    char name[30];
    int stock;
    float precio;
    char ans[2];
    int venta = 0;
    int ventas = 0;
    float ganancia;
    int accion;
    
    void continuar(){
                printf("\nPulse enter para continuar...");
                getchar();
                getchar();
    }
    
    void fget(char array[30]){
        fgets(array,30, stdin);
        array[strcspn(array, "\n")]='\0';
    }
    
    printf("Bienvenido!\nPor favor, registre su producto");
    do
    {
        printf("\nIngrese ID del producto:");
        fget(ID);
        printf("Ingrese el nombre del producto:");
        fget(name);
        printf("Ingrese la cantidad en stock:");
        scanf("%d", &stock);
        printf("Ingrese el precio unitario del producto:");
        scanf("%f", &precio);
        printf("Ha introducido los datos correctamente?\nResponda si o no:");
        scanf("%s", ans);
    } while (strcmp(ans, "si") != 0);
    do
    {
        printf("\nQue desea realizar?\n\t1 - Registrar venta\n\t2 - Reabastecer el producto\n\t3 - Consultar informacion del producto\n\t4 - Consultar ganancias\n\t5 - Salir del programa\nIngrese un numero:");
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
                printf("Cuantas unidades desea vender?\nStock actual:%d\n", stock);
                scanf("%d", &venta);
                if (venta > 0)
                {
                    if (venta > stock)
                    {
                        printf("Venta negada! No hay suficientes unidades disponibles\nStock actual:%d\n", stock);
                    }
                    else
                    {
                        stock = stock - venta;
                        ventas = ventas + venta;
                        ganancia = venta * precio;

                        printf("Venta exitosa!\nStock actual:%d\nVenta total:$%.2f\n", stock, ganancia);
                    }
                }
                else
                {
                    printf("ERROR\nIngrese numeros enteros positivos\n");
                }

                continuar();
                break;
            case 2:
                printf("Cuantas unidades desea agregar?\n");
                scanf("%d", &venta);
                stock = stock + venta;
                printf("Reabastecimiento exitoso!\nStock actual:%d", stock);
                continuar();

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

                continuar();
                break;

            case 4:
                ganancia = ventas * precio;
                printf("Unidades vendidas:%d\nIngreso total:%.2f", ventas, ganancia);
               continuar();

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
