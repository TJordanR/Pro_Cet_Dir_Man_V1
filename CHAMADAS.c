#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include<winsock2.h>

#pragma comment(lib,"ws2_32.lib") //Winsock Library
#include "GETWAY_PROJETO_TESTE1.h"
#include "IP_PROJETO_TESTE1.h"
#include "IPSCANNER.h"

/**
 * Para que serve: ENVIAR EMAIL VIA TERMINAL CMD
 * Objetivo: TRASMITIR DADOS POR EMAIL VIA TERMINAL
 *
 * O que falta: CRIAR O CODIGO FONTE!
 * O que falta: UTILIZAR BIBLIOTECAS COMPATIVEIS COM SMTP
 * O que falta: UTILIZAR ESTRUTURA COMPATIVES COM 32 e 64 BITYS
 */

/**
 * Pasta: C:\Users\fribal\Documentos\CodeBlocks
 * Author: Tiago Jordan
 *
 * Created on 00/00/2018, 14:45
 *
 * Versão: V 1.0
 *
 */

 void CHAMDAS_GUETS(int argc , char *argv[])
{
    WSADATA wsa;
    SOCKET s;

    int   lpBuffer[16] = {get1,get2,get3,get4};
    int recebe[0] = {get1,get2,get3,get4};

    int adress_2(const char * get1);
    struct sockaddr_in server;
    char *message , server_reply[2000];
    int recv_size;

    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        main();
        return 1;
    }

    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    }

        char enderaco[17];
	    FILE *pp;
        char url [] = "C:\\IP.IP";
        pp = fopen(url,"r");
        pp = fopen(url, (enderaco, "r"));
        fscanf(pp, "%s", recebe);
        //printf("\n%s\n", recebe);

        /// PONTEIRO DE IP GETEWAY
        RET_GATEWAY_ADRESS1 = recebe;

    server.sin_addr.s_addr  = inet_addr(RET_GATEWAY_ADRESS1);
    server.sin_family =  AF_INET;
    server.sin_port = htons( 80 );
    if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
        main();
        return 1;
    }
    message = "GET / HTTP/1.1\r\n\r\n";
    if( send(s , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        main();
        return 1;
    }
    //puts("Data Send\n");
    ///Receive a reply from the server
    if((recv_size = recv(s , server_reply , 2000 , 0)) == SOCKET_ERROR)
    {
        puts("recv failed");
        main();
    }

    //puts("Reply received\n");
    ///Add a NULL terminating character to make it a proper string before printing
    server_reply[recv_size] = '\0';
    puts(server_reply);

    /// PONTEIRO DE DADOS
    MAX_TAM_GET1 = (server_reply);
    SANVA_ARQUIVO();
}

void SANVA_ARQUIVO()
{
    char caminho[] = "f:\\IP.ARQ1";
    FILE *arquivo;
    arquivo = fopen(caminho, "w");
    fprintf(arquivo, "%s", MAX_TAM_GET1);
    fclose(arquivo);
    system("cls");
    GETWAY();
}


 void EQUIPAMENTO_GETS2w()
{
    int s1, z1, g1, x=0;
    int lop1=0;
    char car1[20];
    char nome;
    char *dados1;
    char *manipula1;
    dados1 = malloc(s1 * sizeof(char *));
    manipula1 = malloc(z1 * sizeof(char *));

    char caminho[] = "f:\\IP.ARQ1";
    FILE *arquivo;
    arquivo = fopen(caminho, "r");
    fprintf(arquivo, "%s", MAX_TAM_GET1);

    while( (nome=fgetc(arquivo))!= EOF)
    {
        lop1++;
        dados1[lop1] = nome;
        manipula1[lop1] = nome;
    }

    while(lop1++, lop1 <= 9999)
    {
        if(manipula1[lop1] == 'G')
        {
            printf("G");
            dados1[lop1] = 'G';
        }else
        if(manipula1[lop1] == 'g')
        {
            printf("g");
            dados1[lop1] = 'g';
        }else
        if(manipula1[lop1] == 'o')
        {
            printf("o");
            dados1[lop1] = 'o';
        }else
        if(manipula1[lop1] == 'l')
        {
            printf("l");
            dados1[lop1] = 'l';
        }else
        if(manipula1[lop1] == 'e')
        {
            printf("e\n");
            dados1[lop1] = 'e';
        }
        if(lop1 == 9998)
        {
            chamas_geteway = '1';
            printf("Fim da contagem!\n");
        }
    }
}

 void menu_chamadas()
 {
     int chama;
     printf("chama chamou!!!!\n\n\n\n\n");
     printf("%d", chamas_geteway);

     /// CHAMADAS DE GETEWAY
     if(chamas_geteway == 1)
     {
         chama = '1';
     }

     switch (chama)
     {
     case '1':
         printf("Resultado chamou!!\n\n");
         resultado();
         break;

     }


 }

 void resultado()
{
    char caminho[] = "f:\\IP.ARQ1";
    int a;
    FILE *arquivo;
    arquivo = fopen(caminho, "r");
    printf("FIM DA LEITURA DE ARQUIVO!\n");
    printf("Deseja finalisar a leitura se sim 1 se nao 2 \n");
    scanf("%d", &a);
    if(a == 1)
    {
        fclose(arquivo);
        printf("fim de arquivo! \n");
        system("pause");
        system("cls");
        main();
    }
    if(a == 2)
    {
        printf("Arquivo nao fechado! \n");
        system("pause");
        system("cls");
        resultado();
    }
    if(a > 2)
    {
        printf("Erro na selecao!\n");
        main();
    }

}
