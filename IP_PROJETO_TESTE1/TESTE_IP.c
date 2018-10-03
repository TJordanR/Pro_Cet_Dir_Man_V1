/*
** OBJETIVO
** # TESTAR UM IP COM PING
** # SALVAR O ARQUIVO COM O PING
** # LER O ARQUIVO COM O PING
** # DETERMINAR SE O IP ESTA SENDO USADO
** O QUE FALTA
** # CRIAR UM ARQUIVO BAT
** # CRIAR COMANDO DE GRAVA플O COM O IP PARA EXECUTAR
** # FAZER O PROGRAMA EXECUTAR O BAT
** # FAZER O BAT SALVAR OS DADOS RECEBIDO E LER
** # TRAZER O ARQUIVO SALVO PELO BAT E LER NA TELA
** ESCRITO: POR TIAGO JORDAN R
** VERSAO: 1.0
** DATA: 29/09/2018
*/
///https://www.iana.org/assignments/protocol-numbers/protocol-numbers.xhtml
///=====================================================================================///

#include<stdio.h>
#include<stdlib.h>
#include "IP_PROJETO_TESTE1.h"
#include "IP_PROTOCOLO_TESTE.h"
#include "IP_CONFIGURACAO.h"


chamada_teste_v()
{
    system("cls");
    printf("====================================================\n");
    printf("              CONFIGURACAO NETWORK                  \n");
    printf("====================================================\n");
    printf("configurar ip.....................................1 \n");
    printf("ip automaticamente................................2 \n");
    printf("configurar mascara................................3 \n");
    printf("configurar dns....................................4 \n");
    printf("configurar getway.................................5 \n");
    char escolha;
    int retorno_conf;
    escolha = getch();

    switch (escolha)
    {
    case '1':
        printf("\nconfigurar ip!\n");
            retorno_conf = 0;
            IP_ENTRADA = retorno_conf;
            configura_ip();
        break;
    case '2':
        printf("\nip automatico!\n");
        break;
    case '3':
        printf("\nconfigurar mascara!\n");
            cont_mas = 0;
            configura_mascara();
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

char endereco_ip[16];

void configura_ip()
{
    int ip;
    int *a;
    int b,c,d,e;
    int lop=1;
    a = malloc(lop * sizeof(int *));
    a = malloc(ip * sizeof(int *));
    salv_ip_1 = malloc(b * sizeof(int *));
    salv_ip_2 = malloc(c * sizeof(int *));
    salv_ip_3 = malloc(d * sizeof(int *));
    salv_ip_4 = malloc(e * sizeof(int *));

    printf("digite o numero do ip!\n");

    for(lop=1;lop<=4;lop++)
    {
        scanf("%d",&ip);
        a[lop] = ip;
        system("cls");
        if(lop == 1)
        {
            salv_ip_1 = a[lop];
            printf("%d.", a[lop]);
            if(a[lop] >= mx_ip_ini) { a[lop] = ip; }
            else
            {
                printf("ERRO O IP DIGITADO E INVALIDO! \n");
                erro_ip_ini = a[lop];
                erro_ip();
            }
             if(a[lop] <= mx_ip_fim) { a[lop] = ip; }
            else
            {
                printf("ERRO O IP DIGITADO E INVALIDO! \n");
                erro_ip_fim = a[lop];
                erro_ip();
            }
        }else
        if(lop == 2)
        {
            salv_ip_2 = a[lop];
            printf("%d.%d.", a[lop-1],a[lop]);
            if(a[lop] <= mx_ip_fim){}
            else
            printf("ERRO O IP DIGITADO E INVALIDO! \n");
        }else
        if(lop == 3)
        {
            salv_ip_3 = a[lop];
            printf("%d.%d.%d.", a[lop-2],a[lop-1],a[lop]);
            if(a[lop] <= mx_ip_fim){}
            else
            printf("ERRO O IP DIGITADO E INVALIDO! \n");
        }else
        if(lop == 4)
        {
            salv_ip_4 = a[lop];
            printf("%d.%d.%d.%d", a[lop-3],a[lop-2],a[lop-1],a[lop]);
            if(a[lop] <= mx_ip_fim){}
            else
            printf("ERRO O IP DIGITADO E INVALIDO! \n");
        }
    }
    system("cls");
    printf("\n\n");
    for(lop=1;lop<=4;lop++)
    {
        printf("%d",a[lop]);
        if(lop == 4)
        {
            salva_ip();
        }
    }
    printf("\n");
    system("pause");

}
void erro_ip()
{
    if(erro_ip_fim > 255)
    {
        system("cls");
        printf("ERRO AO DIGITAR O IP!\n");
        printf("O NUMERO FINAL DIGITADO FOI: %d\n",   erro_ip_fim);
        system("pause");
        erro_ip_fim == NULL;
        return NULL;
    }else
    if(erro_ip_ini < 1)
    {
        printf("ERRO AO DIGITAR O IP!\n");
        printf("O NUMERO INICIAL DIGITADO FOI: %d\n", erro_ip_ini);
        system("pause");
        erro_ip_ini == NULL;
        return NULL;
    }
}
void salva_ip()
{
    printf("\n\n\nO IP FOI CONFIGURADO COM SUCESSO!\n\n");
    char nome[] = "200.221.011.100";
    char url[] = "C:\\CONVERTE_IP\\CONFIGURA_IP.IP";
    system("pause");
    FILE *ARQUIVO;
    ARQUIVO = fopen(url, "r");
    if(ARQUIVO != EOF)
    fprintf(ARQUIVO,"%s", nome);
    fclose(ARQUIVO);
    system("cls");
    printf("%d.%d.%d.%d\n",salv_ip_1,salv_ip_2,salv_ip_3,salv_ip_4); /// para validar os numeros salvos!
    system("pause");
    chamada_teste_v();
}

///CONFIGURA플O DE MASCARA DE REDE
void configura_mascara()
{
    ///calculo_mascara()
    //system("cls");
    printf("\nip2:%d.%d.%d.%d\n",salv_ip_1,salv_ip_2,salv_ip_3,salv_ip_4); /// para validar os numeros salvos!
    system("pause");

    int masc;
    int n2;
    int lop;
    int *dados;

    dados = malloc(lop * sizeof(int *));
    dados = malloc(n2 * sizeof(int *));

        if(cont_mas == 0)
        {
            masc = salv_ip_1;
            printf("\nM%d\n",masc);
            printf("C1: %d\n", cont_mas);
        }

    printf("\n");
    ///CALCULO PARA OBTER A SEQUENCIA CORRETA DAS POSI합ES DE BITS DE ENVIO DA MASCARA
    for(lop=0;masc >= 1 ;lop++)
    {
        if(lop == 0)
        {
            printf("Mas %d", masc);
            if(masc%2 == 0){printf("    Bin 0\n"); n2 = 0; dados[lop] = n2;}
            else{printf("    Bin 1\n"); n2 = 1; dados[lop] = n2;}
            masc = masc / 2;

        } else
        {
            masc = masc / 2;
            printf("Mas %d", masc);
            if(masc%2 == 0){printf("    Bin 0\n"); n2 = 0; dados[lop] = n2;}
            else{printf("    Bin 1\n"); n2 = 1; dados[lop] = n2;}
        }
    }
        printf("%d\n", lop);

        ///IMPRIMIR A ORDEM CORRETA DE BINARIOS PARA CONTAGEM E VALIDA플O
        for(lop=7;lop >= 0 ;lop--)
        {
            printf("Binarios:%d\n", dados[lop]);
        }
        printf("\n");

        ///CONTADOR DE MASCARA REVERSO CONSOLIDADOS DE CALCULO BINARIO EM BITS
        for(lop=7;lop >= 0 ;lop--)
        {
            if(dados[lop] == 1)
            {
                if(lop == 7){bin_1 = 128;}else{bin_1 = 0;}
                if(lop == 6){bin_2 = 64;} else{bin_2 = 0;}
                if(lop == 5){bin_3 = 32;} else{bin_3 = 0;}
                if(lop == 4){bin_4 = 16;} else{bin_4 = 0;}
                if(lop == 3){bin_5 =  8;} else{bin_5 = 0;}
                if(lop == 2){bin_6 =  4;} else{bin_6 = 0;}
                if(lop == 1){bin_7 =  2;} else{bin_7 = 0;}
                if(lop == 0){bin_8 =  1;} else{bin_8 = 0;}

            }
            printf("%d", dados[lop]);
        }
}

void configura_mascara1()
{
    printf("\nMASCARA SALVA COM SUCESSO! \n");
    system("pause");
}



