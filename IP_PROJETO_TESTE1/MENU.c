
#include<stdio.h>
#include<stdlib.h>
#include "IP_PROJETO_TESTE1.h"
#include "IP_PROTOCOLO_TESTE.h"
#include "IP_CONFIGURACAO.h"

void menu_networks1(void)
{
    system("cls");
    printf("===================================================\n");
    printf("              CONFIGURACAO NETWORK                 \n");
    printf("===================================================\n");
    printf("configurar ip........................1 \n");
    printf("ip automaticamente...................2 \n");
    printf("configurar mascara...................3 \n");
    printf("configurar dns.......................4 \n");
    printf("configurar getway....................5 \n");
    char escolha;
    int retorno_conf;
    escolha = getch();

    switch (escolha)
    {
    case '1':
        printf("\nconfigurar ip!\n");
        retorno_conf = 0;
        IP_ENTRADA = retorno_conf;
        ///configura_ip();
        break;
    case '2':
        printf("\nip automatico!\n");
        break;
    case '3':
        printf("\nconfigurar mascara!\n");
        break;
    case '4':
        printf("\nconfigurar dns!\n");
        break;
    case '5':
        printf("\nconfigurar getway\n");
        break;

    default:
        break;
    }

}

