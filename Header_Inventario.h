#include<stdio.h>
#include<string.h>
#define IVA 0.15

int verificarcodigo(struct producto*num, int cod, int i){
    int devolver=0;
    for(int a=0; a<i; a++){ //Comparar con todos los codigos anteriores
        if(num[i-a-1].codigo==cod){
            devolver=1;
        }
    }
    return devolver; 
}

void llenarestructura (struct producto *num, int num_productos){
    for(int i=0; i<num_productos; i++){ //Recorrer el arreglo e ir llenándolo
        getchar();  //Usamos para evitar problemas con el buffer
        printf("\nINGRESE LOS DATOS DEL PRODUCTO %d",i+1);

        printf("\nIngrese el nombre del producto: ");
        fgets(num[i].nombre,sizeof(num[i].nombre),stdin);
        num[i].nombre[strcspn(num[i].nombre,"\n")]='\0';

        CD:
        printf("Ingrese el código del producto: ");
        scanf("%d",&num[i].codigo);
        getchar();
        int v=verificarcodigo(num,num[i].codigo,i); //Llamar a la función que veirifca códigos repetidos
        if(v==1){
            printf("\n¡Dos productos no pueden tener el mismo código!\n");
            goto CD; //Si se repiten, volver a llenar
        }

        printf("Ingrese la cantidad en stock: ");
        scanf("%d",&num[i].stock);
        getchar();

        printf("Ingrese el precio del producto: ");
        scanf("%f",&num[i].precio);
    }
}

int eliminarproducto(struct producto *num, int codigo, int num_productos, int eliminar){ 
    int retorno=0; //Devolvemos un valor para indicar que se complete a acción
    for(int i=0; i<num_productos; i++){ //Recorremos el arreglo
        if(codigo==num[i].codigo){ //Hasta encontrar la coincidencia y eliminar
            if(num[i].stock>=eliminar){ //Solo se puede eliminar hasta que el stock quede en 0
                num[i].stock-=eliminar;
                retorno =1;
            }
        }
    }
    return retorno;
}

int agregarproducto(struct producto *num, int codigo, int num_productos, int agregar){
    int retorno=0; //Valor de retorno
    for(int i=0; i<num_productos; i++){ //Recorremos hasta encontrar y agregar
        if(codigo==num[i].codigo){
            num[i].stock+=agregar;
            retorno =1;
        }
    }
    return retorno;
}

void mostrarinventario(struct producto *num, int num_productos){
    printf("El estado actual del inventario es:\n");
    printf("\n\t\t\tNOMBRE\t\t\tCÓDIGO\t\t\tSTOCK\t\t\tPRECIO");
    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    for(int i=0; i<num_productos; i++){
        printf("\nPRODUCTO %d",i+1);
        printf("\t\t%s",num[i].nombre);
        printf("\t\t\t%d",num[i].codigo);
        printf("\t\t\t%d",num[i].stock);
        printf("\t\t\t%.2f $",num[i].precio);
    }
}

void venta(struct producto*num, int num_productos){
    int codigo, cantidad;
    float iva, pagar, subtotal;
    printf("\nIngrese el código del producto: ");
    scanf("%d",&codigo);
    CA:
    printf("¿Cuántos de este producto va a vender?: ");
    scanf("%d",&cantidad);
    if(cantidad<=0){ //No podemos vender -1 manzanas o 0 aguas
        printf("\nCantidad ingresada no válida, ingrese nuevamente\n");
        goto CA; 
    }

    for(int i=0; i<num_productos; i++){  //Recorremos el arreglo
        if(codigo==num[i].codigo){   //Encontramos el producto a vender
            if(cantidad<=num[i].stock){   //Debe haber suficiente stock
                eliminarproducto(num, codigo, num_productos, cantidad);  //Eliminamos lo vendido
                printf("\n¡Venta realizada con éxito!");
                subtotal=num[i].precio*cantidad;   //Calculamos precio añadiendo el iva
                iva=subtotal*IVA;
                pagar=subtotal+iva;
                printf("\n\nPRECIO UNITARIO: %.2f\nSUBTOTAL: %.2f\nIVA: %.2f\nTOTAL A PAGAR: %.2f\n",num[i].precio,subtotal,iva,pagar);
            }
            else{
                printf("\nNo hay suficiente stock para esta venta\n");
            }
        }
    }
}