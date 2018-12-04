#include <stdio.h>
#include <stdlib.h>
#include<winsock2.h>

//#pragma comment(lib,"ws2_32.lib") //Winsock Library
//#include "GETWAY_PROJETO_TESTE1.h"
//#include "IP_PROJETO_TESTE1.h"

/// SABER O IP DO ROTIADOR RADIO SUICHE ANTENA SERVIDOR FIREWALL SERVIDOR DHCP
/// VERIFICAR OS IPs DIPONIVES NA REDE
/// INDICAR O DISTRIBUIDOR DE IPs E FAZER A SOLICITAÇÃO
/// APONTAR O DISTRIBUIDOR DE REDE
/// RECEPICIONAR O DISTRIBUIDOR DE REDE
/// saber qual é meu ip
/// indentificar qual é o ip maximo dentro da faixa de ip
/// subitrair o valor total maximo menos o valor de 254
/// indetificar o valor de retorno broadcast
/**
void HTTP()
{
    get1 = ret_ip1;
    get2 = ret_ip2;
    get3 = ret_ip3;
    get4 = ret_ip4;

    //if();
    printf("\n          PROTOCOLO HTTP V 1.0 TESTE!        \n");
    printf("PARA SITE OU IP:")
    printf("%d.%d.%d.%d\n", get1,get2,get3,get4);
    printf("TIPOS DE REQUISICAO PARA O SITE!\n");
    printf("GET...........................................1\n");
    printf("HEAD..........................................2\n");
    printf("PUT...........................................3\n");
    printf("DELETE........................................4\n");
    printf("TRACE.........................................5\n");
    printf("OPTIONS.......................................6\n");
    printf("CONNECT.......................................7\n");

    // GET
    // HEAD
    // POST
    // PUT
    // DELETE
    // TRACE
    // OPTIONS
    // CONNECT


    //printf("%d", inet_addr(get1&&get2&&get3&&get4));
    HTTP_REQUISICAO();

}

/// RETORNO DA ESTRUTURA DE CHAMADA PARA LEITURA E COMPARAÇÃO DE LEAYALT
#define MAX_TAM_GET
MAX_TAM_GET *MAX_TAM_GET1;

void HTTP_REQUISICAO(int argc , char *argv[])
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

    //printf("Initialised.\n");

    ///Create a socket
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
        printf("\n%s\n", recebe);
        lpBuffer  == recebe;

    //printf("Socket created.\n");
    ///server.sin_addr.s_addr  = inet_addr(lpBuffer);
    server.sin_addr.s_addr  = inet_addr(RET_GATEWAY_ADRESS1);
    server.sin_family =  AF_INET;
    server.sin_port = htons( 80 );

    ///Connect to remote server
    if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
        main();
        return 1;
    }

    //puts("Connected");

    ///Send some data
    //message = "GET / HTTP/1.1\r\n\r\n";
    //message = "TRACE /HTTP/1.1\r\n\r\n";
    message = "HEAD /HTTP/1.1\r\n\r\n";
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

    ///Add a NULL terminating character to make it a proper string before printing
    server_reply[recv_size] = '\0';
    puts(server_reply);

    return 0;
}
*/
