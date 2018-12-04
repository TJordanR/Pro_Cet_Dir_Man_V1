#include <stdio.h>
#include <stdlib.h>

#include "IP_PROJETO_TESTE1.h"
#include "DNS_PROJETO_TESTE1.h"

void DNS()
{

}

void DNS_DEFINIDO()
{
    int ent;
    int *dados;
    int *num;
    int lop;

//    scanf("%d", &DNS_CONFIG);
    dados = malloc(ent * sizeof(int *));
    for(lop=1;lop<=4;lop++)
    {
        //system("cls");
        printf("DIGITE UM NUMERO:");
        scanf("%d", &ent);

        if(lop == 1){ if(ent <=   0){ printf("\nERRO DNS MENOR QUE 1!    \n");}else dados[lop] = ent; }else
        if(lop == 2){ if(ent >= 256){ printf("\nERRO DNS MAIOR QUE 255 1!\n");}else dados[lop] = ent; }else
        if(lop == 3){ if(ent >= 256){ printf("\nERRO DNS MAIOR QUE 255 2!\n");}else dados[lop] = ent; }else
        if(lop == 4){ if(ent >= 256){ printf("\nERRO DNS MAIOR QUE 255 3!\n");}else dados[lop] = ent; }
    }


    /// FALTA SAVAR NO KECHE DA BIBLIOTECA O DNS PARA COLSULTA


    system("pause");
    system("cls");
    printf("DNS:");
    for(lop=1;lop<=4;lop++)
    {
        if(lop == 4){  printf("%d.%d.%d.%d",dados[lop-3],dados[lop-2],dados[lop-1],dados[lop]); }

    }
}

void DNS_AUTOMATICO()
{

}

void DNS_TESTE()
{

}
