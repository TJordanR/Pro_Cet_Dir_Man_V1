#include <stdio.h>
#include <stdlib.h>
#include<winsock2.h>

#pragma comment(lib,"ws2_32.lib") //Winsock Library
#include "GETWAY_PROJETO_TESTE1.h"
#include "IP_PROJETO_TESTE1.h"

/// SABER O IP DO ROTIADOR RADIO SUICHE ANTENA SERVIDOR FIREWALL SERVIDOR DHCP
/// VERIFICAR OS IPs DIPONIVES NA REDE
/// INDICAR O DISTRIBUIDOR DE IPs E FAZER A SOLICITAÇÃO
/// APONTAR O DISTRIBUIDOR DE REDE
/// RECEPICIONAR O DISTRIBUIDOR DE REDE
/// saber qual é meu ip
/// indentificar qual é o ip maximo dentro da faixa de ip
/// subitrair o valor total maximo menos o valor de 254
/// indetificar o valor de retorno broadcast
///

struct chamadas_gets
{
    int *ip_dinamico_host;
    int *ip_scanner_host;
    int *ip_host_necticao;
    int *ip_central_geteway;
    int *ip_teste_geteway;
    int *ip_recepicao_host;
    int *ip_maximo_host_brodcast;
    int *ip_minimo_host_multcast;

};

void GETWAY()
{
    get1 = ret_ip1;
    get2 = ret_ip2;
    get3 = ret_ip3;
    get4 = ret_ip4;

    //if();
    printf("\nCONFIGURACAO GETWAY!\n");
    printf("%d.%d.%d.%d\n", get1,get2,get3,get4);
    //printf("%d", inet_addr(get1&&get2&&get3&&get4));
    confirma_geteway_socket();

}

#define RETORNO_GETEWAY
RETORNO_GETEWAY *ret_geteway;

void confirma_geteway_socket(int argc , char *argv[])
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
        //lpBuffer  == recebe;

        /// PONTEIRO DE IP GETEWAY
        RET_GATEWAY_ADRESS1 = recebe;



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
    message = "GET / HTTP/1.1\r\n\r\n";
    //message = "TRACE /HTTP/1.1\r\n\r\n";
    //message = "HEAD /HTTP/1.1\r\n\r\n";
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
    EQUIPAMENTO_GETS();
}

void EQUIPAMENTO_GETS()
{

    printf("\n\n\n\n");
    printf("#####EQUIPAMENTO GETEWAT COM RETORNO DE DADOS#####\n");
    printf("ROTEADOR.........................................1\n");
    printf("SWITCHES.........................................2\n");
    printf("WIRELESS.........................................3\n");
    printf("SERVER...........................................4\n");
    printf("PPPoE............................................5\n");
    printf("RADIO............................................6\n");
    printf("\n\n\n");

    int s1, z1, g1, x=0;
    int lop1=0;
    int loop=0;
    char car1[20];
    char nome;
    char *dados1;
    char *manipula1;
    dados1 = malloc(s1 * sizeof(char *));
    manipula1 = malloc(z1 * sizeof(char *));
    ret_geteway = malloc(g1 * sizeof(char *));

    char caminho[] = "f:\\IP.ARQ1";
    FILE *arquivo;
    arquivo = fopen(caminho, "r");
    //fprintf(arquivo, "%s", MAX_TAM_GET1);

    while( (nome=fgetc(arquivo))!= EOF)
    {
        lop1++;
        dados1[lop1] = nome;
        //ret_geteway[lop1] = nome;
        manipula1[lop1] = nome;
    }
    struct chamadas_gets ip_get;
    while(lop1++, manipula1[lop1] != EOF)
    {
        nome = manipula1[lop1];
        switch (nome)
        {
            case 'A':
            case 'a':
            ip_get.ip_central_geteway[lop1] = manipula1[lop1];
            printf("A\n");
        }

    }
}
/**
    while(lop1++, lop1 <= 9999)
    {
        if(manipula1[lop1] == 'G')
        {
            if( manipula1[lop1+1] == 'o')
            {
                printf("G");
            }
        }else
        if(manipula1[lop1] == 'o')
        {
            if(manipula1[lop1-1] == 'o')
            {
                if(manipula1[lop1+1] == 'g')
                {
                    printf("o");
                }

            }else
            if(manipula1[lop1-1] == 'g' && manipula1[lop1+1] == 'o')
            {
                printf("o");
            }else
            if(manipula1[lop1-1] == 'G' && manipula1[lop1+1] == 'o')
            {
                printf("o");
            }
            //printf("o");

        }else
        if(manipula1[lop1] == 'g')
        {
            if(manipula1[lop1-3] == 'G')
            {
                printf("g");
            }else
            if(manipula1[lop1+1] == 'o' && manipula1[lop1+3] == 'g')
            {
                printf("g");
            }
        }else
        if(manipula1[lop1] == 'l')
        {
            if(manipula1[lop1-1] == 'g')
            {
                printf("l");
            }
        }else
        if(manipula1[lop1] == 'e')
        {
            if(manipula1[lop1-2] == 'g')
            {
                printf("e\n");
            }
        }else
        if(lop1 == 9999)
        {
            chamas_geteway = '1';
            printf("\nFim da contagem!\n");
            for(loop=0;loop <= 1000; loop++)
            {
                //loop++;
                //dados1[lop1] = nome;
                ret_geteway[loop] = 1;//dados1[loop];
                //manipula1[lop1] = nome;
                printf(".");
            }
            //validador();
        }

    }

}
*/
void validador()
{
    printf("\n\nvalidado ok!\n\n");
    int g1, lop1=0;
    char nome;


    //ret_geteway = malloc(g1 * sizeof(char *));
    while(lop1++, lop1 <= 999)
    {
        printf("%s", ret_geteway[lop1]);
        switch (ret_geteway[lop1])
        {
        case '1':
            printf("1");
            //dados1[lop1] = nome;
            break;
        case '2':
            printf("g");
            //dados1[lop1] = nome;
            break;
        case '3':
            printf("o");
            //dados1[lop1] = nome;
            break;
        case '4':
            printf("l");
            //dados1[lop1] = nome;
            break;
        case '5':
            printf("e\n");
            //dados1[lop1] = nome;
            break;
        }

    }
}


    /*
        //printf("\n%d\n", lop1);

        //dados1[lop1] = nome;
        //manipula1[lop1] = nome;

        switch (manipula1[lop1])
        {
        case 'G':
            printf("G");
            dados1[lop1] = nome;
            break;
        case 'g':
            printf("g");
            dados1[lop1] = nome;
            break;
        case 'o':
            printf("o");
            dados1[lop1] = nome;
            break;
        case 'l':
            printf("l");
            dados1[lop1] = nome;
            break;
        case 'e':
            printf("e\n");
            dados1[lop1] = nome;
            break;

        }
    }
    chamas_geteway = 1;
    menu_chamadas();
    //menu_chamadas();
    //char compara;

    for(lop1=0;dados1[lop1] <= 501; lop1++)
    {

        if(lop1 == 500)
        {
            chamas_geteway = 1;
            menu_chamadas();
        }
        switch (manipula1[lop1])
        {
        case 'G':
            printf("G");
            break;
        case 'g':
            printf("g");
            break;
        case 'o':
            printf("o");
            break;
        case 'l':
            printf("l");
            break;
        case 'e':
            printf("e\n");
            break;
        }
        printf("    %d\n", lop1);
    }*/



void a()
{
    menu_chamadas();
}


void apura()
{

    int s1, z1, x=0;
    int lop1=0;
    char car1[20];
    char nome;
    char *dados1;
    char *manipula1;
    dados1 = malloc(s1 * sizeof(char *));
    manipula1 = malloc(z1 * sizeof(char *));

    char caminho[] = "f:\\IP.ARQ2";
    FILE *arquivo;
    //arquivo = fopen(caminho, "w"); "w" para escrita e "r" para leitura
    arquivo = fopen(caminho, "r");
    fprintf(arquivo, "%s", MAX_TAM_GET1);



    for(lop1=1;lop1<10;lop1++)
    {
        printf("%d  a%c", lop1, dados1[lop1]);
        //printf(" %c\n", manipula1[lop1]);
    }
}
/*
while para goole funcional
while(lop1++, manipula1[lop1]!= 120)//EOF)
    {

            if(manipula1[lop1-1] == 'g' || manipula1[lop1-1] == 'G' &! manipula1[lop1-4] == 'g')
            {
                //printf("\n");
                //printf("%c", manipula1[lop1-1]);
                x = lop1-2;
                if(manipula1[x] == 'o')
                {
                    //printf("%c", manipula1[x]);
                    x = lop1-3;
                    if(manipula1[x] == 'o')
                    {
                        //printf("%c", manipula1[x]);

                    }
                }
            }else
            if(manipula1[x] == 'o' && manipula1[lop1-4] == 'g')
            {
                //printf("%c", manipula1[lop1-4]);
            }else
            if(manipula1[lop1-5] == 'l')
            {
                //printf("%c", manipula1[lop1-5]);
                x = lop1-5;
            }else
            if(manipula1[lop1-6] == 'e' && manipula1[x] == 'l')
            {
                //printf("%c", manipula1[lop1-6]);
                //printf("   %d", lop1);
            }else
            if(lop1 == 19094)
            {
                //printf("\n\n");
               //resultado();
            }

    }
    */

/**


    int s1, z1, x=0;
    int lop1=0;
    char car1[20];
    char nome;
    char *dados1;
    char *manipula1;
    dados1 = malloc(s1 * sizeof(char *));
    manipula1 = malloc(z1 * sizeof(char *));

    char caminho[] = "f:\\IP.ARQ1";
    FILE *arquivo;
    //arquivo = fopen(caminho, "w"); "w" para escrita e "r" para leitura
    arquivo = fopen(caminho, "r");
    fprintf(arquivo, "%s", MAX_TAM_GET1);

    while( (nome=fgetc(arquivo))!= EOF)
    {
        lop1++;
        dados1[lop1] = nome;
    }

    for(lop1=1;lop1<=10;lop1++)
    {
        if(dados1[lop1] == 'H' && dados1[lop1+1] == 'T' && dados1[lop1+2] == 'T' && dados1[lop1+3] == 'P')
        {
            printf("HTTP\n");
        }
    }

    for(lop1=1;lop1<10;lop1++)
    {
        printf("%d  %c\n", lop1, dados1[lop1]);
    }
    printf("\n\n");



      printf("\n\n\nValor da variavel texto = %s\n", texto);
      for (i=0; i<6; i++)
      {
        printf("Valor do elemento %d da string = %c\n",i, texto[i]);
        if(texto[i] == 'i')
        {
            printf("o valor de i foi encontrado! \n");
        }
      }



void EQUIPAMENTO_GETS()
{
    printf("\n\n\n\n");
    printf("#####EQUIPAMENTO GETEWAT COM RETORNO DE DADOS#####\n");
    printf("ROTEADOR.........................................1\n");
    printf("SWITCHES.........................................2\n");
    printf("WIRELESS.........................................3\n");
    printf("SERVER...........................................4\n");
    printf("PPPoE............................................5\n");
    printf("RADIO............................................6\n");
    printf("\n\n\n");
    //printf("%s", MAX_TAM_GET1);



    char *NOME_EQUIPAMENTO[]  = {MAX_TAM_GET1};
    char NOME_EQUIPAMENTO2[]  = {RET_GATEWAY_ADRESS1};
    int num;
    int num2;
    int lop=0;
    int lop2=0;
    int lop3=0;

    NOME_EQUIPAMENTO[num] = malloc(num * sizeof(char*));
    NOME_EQUIPAMENTO2[num2] = malloc(num2 * sizeof(char*));

           for(lop=0;lop<=10;lop++)
           {
                printf("%s", NOME_EQUIPAMENTO[lop]);
                for(int s=0;s<=1;s++)
                {
                    lop3++;
                    if(NOME_EQUIPAMENTO2 < 0)
                    {
                        printf("nomes iguais:");
                        printf("%d\n", lop3);
                    }else
                        printf("\nnomes diferentes de: ");
                        RET_GATEWAY_ADRESS1 = puts("tiago");
                        //return EQUIPAMENTO_GETS();
                    }
           }

           //num++;
           //num2++;
           //NOME_EQUIPAMENTO[1] = 'a';
           //NOME_EQUIPAMENTO2[1] = 'b';
           printf("\n\n");

                printf("%s\n", NOME_EQUIPAMENTO);
                printf("%s\n", NOME_EQUIPAMENTO2);
                printf("%s\n", RET_GATEWAY_ADRESS1);
                RET_GATEWAY_ADRESS1 = puts("tiago");





















    char *NOME_EQUIPAMENTO[4];
    char *NOME_DADOS_HTTP1[50];// = {MAX_TAM_GET1};
    char num;
    char num2;
    num2 == "200 ";
    num == MAX_TAM_GET1;
    NOME_DADOS_HTTP1[500] = malloc(num * sizeof(char*));
    NOME_EQUIPAMENTO[4] = malloc(num * sizeof(char*));
    printf("\n\n\nFIM DESTE CODIGO TIAGO");
    printf("\n\n\n");
    for(int lop=0; lop<=1; lop++)
    {
        NOME_DADOS_HTTP1[lop] = MAX_TAM_GET1;
        printf("%s", NOME_DADOS_HTTP1[lop]);
        while(NOME_DADOS_HTTP1[lop] == "google")
        {
            printf("GOOGLE ENCONTRADO!\n");
        }

    }

    printf("\n\n\n");
}
    */


/**
void confirma_geteway_socket(int argc , char *argv[])
{
    WSADATA wsa;
    SOCKET s;
    int *GetWayMem[MAX_TAM_GET] =  {get1,get2,get3,get4};
    //get1 = 0x01==get1;
    //int *Get_Rec_Mem;// = REC_GET_UNI;
    //Get_Rec_Mem =  sizeof(*REC_GET_UNI = get1, get2, get3, get4);
    //int adress_1;// = 0;
    int adress_2(const char * get1);

    //int *a = {get2};
    //int *b = {get3};
    //int *c = {get4};
    struct sockaddr_in server;
    char *message , server_reply[2000];
    int recv_size;
    //struct GetWay Get;

//    server = malloc(get1 *,get2 *,get3 *,get4 *sizeof(int*));
//    GetWayMem = malloc(  sizeof(get1,get2,get3,get4));
      //GetWayMem = sizeof(*get1,*get2,*get3,*get4);
      //size_t

//    printf("%d", GetWayMem);

    ///printf("%d.%d", get1 && get2); funcional com erro


    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }

    printf("Initialised.\n");

    //Create a socket
    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    }

    printf("Socket created.\n");

    //inet_addr(GetWayMem(struct GetWay *)&GetWayMem);
    ///server.sin_addr.s_addr = get1 && get2;
    //server.sin_addr.s_addr = GetWayMem;
    //printf("%d", get1);
    server.sin_addr.s_addr = ("192.168.0.", get4);
    //server.sin_addr.s_addr = inet_addr();///inet_addr("192.168.0.6"); /// 127.0.0.1:  21  192.168.0.100: 34567
    server.sin_family = AF_INET;
    server.sin_port = htons( 80 );

    //Connect to remote server
    if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }

    puts("Connected");

    //Send some data
    message = "GET / HTTP/1.1\r\n\r\n";
    if( send(s , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
    puts("Data Send\n");

    //Receive a reply from the server
    if((recv_size = recv(s , server_reply , 2000 , 0)) == SOCKET_ERROR)
    {
        puts("recv failed");
    }

    puts("Reply received\n");

    //Add a NULL terminating character to make it a proper string before printing
    server_reply[recv_size] = '\0';
    puts(server_reply);

    main();
    return 0;
}
*/
