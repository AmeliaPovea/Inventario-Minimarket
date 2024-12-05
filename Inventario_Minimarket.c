#include"Header_Inventario.h"

struct producto{
    char nombre[30];
    int codigo;
    int stock;
    float precio;
};

int main(){
    
    int opcion_menu, num_productos,venta_productos;
    int cod_eliminar, cod_agregar, agregar, eliminar;
    int valor;
    MP:
    printf("\n************************************************ MINI MARKET ************************************************");
    printf("\n----------------------------------------- BIENVENIDO AL SISTEMA DE INVENTARIOS -------------------------------");
    //Desplegar menu de opciones
    printf("\n\n1. LLENAR INVENTARIO");
    printf("\n2. VISUALIZAR EL INVENTARIO");
    printf("\n3. REALIZAR UNA VENTA");
    printf("\n4. ELIMINAR UN PRODUCTO");
    printf("\n5. AÑADIR UN PRODUCTO");
    printf("\n6. SALIR DEL PROGRAMA");
    printf("\n\n¿QUÉ ACCIÓN DESEA REALIZAR?: ");
    scanf("%d",&opcion_menu);

    switch(opcion_menu){
        case 1:
            printf("\n\n******************************************** LLENAR INVENTARIO ********************************************\n\n");
            printf("\n¿Cuántos productos deseas ingresar?: ");
            scanf("%d",&num_productos); //Asigna este tamaño al arreglo
            struct producto num[num_productos];
            llenarestructura(num,num_productos); //Llamar función
        break;
        case 2:
            
            mostrarinventario(num, num_productos); //Llamar función
        break;
        case 3:
            printf("\n\n************************************************** VENTAS *************************************************\n\n");
            venta(num, num_productos); //Llamar función 
        break;
        case 4:
            printf("\n\n******************************************** ELIMINAR PRODUCTO ********************************************\n\n");
            printf("\nIngrese el código del producto que desea eliminar: ");
            scanf("%d",&cod_eliminar);
            EL:
            printf("\n¿Cuántos productos desea eliminar?: ");
            scanf("%d",&eliminar);
            if(eliminar<=0){ //No podemos sumar cantidades negativas
                printf("\nIngrese una cantidad válida");
                goto EL;
            }
            valor=eliminarproducto(num,cod_eliminar,num_productos,eliminar); //Asigno el valor de retorno a una variable
            if(valor==1)
                printf("¡Su producto ha sido modificado exitosamente!");
            if(valor==0)
                printf("\nNO ES POSIBLE REALIZAR ESTA ACCION");
        break;
        case 5:
            printf("\n\n******************************************** AGREGAR PRODUCTO *********************************************\n\n");
            printf("\nIngrese el código del producto que deseas agregar: ");
            scanf("%d",&cod_agregar);
            AG:
            printf("\n¿Cuántos productos desea agregar?: ");
            scanf("%d",&agregar);
            if(agregar<=0){ //No podemos sumar cantidades negativas
                printf("\nIngrese una cantidad válida");
                goto AG;
            }
            valor=agregarproducto(num,cod_agregar,num_productos,agregar); //Asigno el valor de retorno a una variable
            if(valor==1)
                printf("¡Su producto ha sido modificado exitosamente!");
            if(valor==0)
                printf("\nNO ES POSIBLE REALIZAR ESTA ACCION");
        break;
    }
    if(opcion_menu!=6){
        goto MP;
    }
    else
        printf("\n\n******************************************** FIN DEL PROGRAMA *********************************************\n\n");
    return 1;
}
