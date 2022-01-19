#include <stdio.h>
#include "structs.h"
#include "funcoes.h"
#include <stdlib.h>
#include "string.h"



int main(void){
int opcao, i, nif, tempo, distancia, ordem;
char codigo[50];

    ME array[100];
    for (i=0; i<100; i++) {
        array[i].ordem = -1;
        array[i].nif = -1;
        array[i].tempo= -1;
        array[i].distancia= -1;
        strcpy(array[i].codigo, "");

    }
    MU array2[100];
        for (i=0; i<100; i++) {
        strcpy(array2[i].codigo, "");
        strcpy(array2[i].tipo, "");
        array2[i].custo = -1;
        array2[i].autonomia = -1;
        }
    int index;

    do {
          opcao = menu();
    switch (opcao) {
    case 1 : readfromfileinsertme(array);
                break;
    case 2 : readfromfileinsertmu(array2);
                break;
             
    case 3 :  for (i=0; array[i].ordem != -1; i++);
            printf("Insira o numero do pedido\n");
            scanf("%d", &ordem);
            printf("Insira o nif\n");
            scanf("%d", &nif);
            printf("Insira o codigo\n");
            scanf("%s", codigo);
            printf("Insira o tempo\n");
            scanf("%d", &tempo);
            printf("Insira a distancia\n");
            scanf("%d", &distancia);
            insertme(array,i, ordem, nif, codigo, tempo, distancia  );
            break;
    case 4 : 
    case 7 : printartudome(array);

    default:
        printf("Tente outra vez");
        break;
    }

    printf("Escreva o numero da opcao desejada.");
    scanf("%d", &opcao);
}while (opcao!=0);
}




/*int main(){
char str[100000];
FILE *fp;
char *x;
fp=fopen("utilizador", "r");
  while(fgets(str, 100000, fp)){
       x=strdup(str);
        printf("%d\n", x);
  }
fclose(fp);
}*/

/*
#include <stdio.h>
#include "funcoes.h"
#include <stdlib.h>

int main(){

    char str[10000];
    FILE *fp;

    fp = fopen("utilizacao", "r");
    
    if (fp = NULL)
    {
        printf("Nao abriu o ficheiro");
    }

    x = readfromfile(fp, str);

    for (int i = 0; i < 10000; i++)
    {
        printf("%d", *x);
    }
    
    fclose(fp);
}
*/
