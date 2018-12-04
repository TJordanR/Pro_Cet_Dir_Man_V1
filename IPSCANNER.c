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

 #include <stdio.h>
 #include <stdlib.h>
 #include <windows.h>
 #include <string.h>
 #include "IP_PROJETO_TESTE1.h"
 #pragma comment(lib,"ws2_32.lib") //Winsock Library
 #include "GETWAY_PROJETO_TESTE1.h"
 #include "IPSCANNER.h"

 #define MAX_TAM_GET2_
MAX_TAM_GET2_ *MAX_TAM_GET2;

#define RET_GATEWAY_ADRESS2_
RET_GATEWAY_ADRESS2_ *RET_GATEWAY_ADRESS2;


 void IP_SCANNER_TESTE_INTRANET_LOCAL()
 {
     printf("CONFIGURAR!\n");
     system("cls");
     IP_PRIMARIO_MENU();

     /**
     ESTE RECURÇO PINGA NA REDE VARIOS IPS DE FAIXAS ORDENADAS E RECEBE
     UMA RESPOSTA, A RESPOSTA QUE RETORNA VERDADEIRO ENTÃO SALVA A RESPOSTA
     E ENVIA PARA IP_SCANNER PAR AQUE O MESMO COMESSE A VERIFICAR AS POSSIBILIDADES
     DE MAXIMO E MINIMO DE TAMANHO IP
     EXEMPLO

     PING    1.0.0.1  a  127.0.0.1 - OK    |  CLASSE A  |  X    |  VERDADEIRO   |
     PING  128.0.0.1  a  191.0.0.1 - FALED |  CLASSE B  |  NULL |  FALSO        |
     PING  192.0.0.1  a  233.0.0.1 - OK    |  CLASSE C  |  X    |  VERDADEIRO   |
     PING  234.0.0.1  a  239.0.0.1 - FALED |  CLASSE D  |  NULL |  FALSO        |
     PING  240.0.0.1  a  255.0.0.1 - OK    |  CLASSE E  |  X    |  VERDADEIRO   |

     IP    | A  | B   |C   |D   |
     IP    |192 |168  |0   |1   |
     INT   |fx1 |fx2  |fx3 |fx3 |
     define--+----+-----+----+
             |    |     |    |
     case---se---se----se---se
     guarda  |    |     |    |
     retorno-+----+-----+----+
     faixa---+----+-----+----+
     defineIP+----+-----+----+
     end-----+----+-----+----+

     case faixa1_classe_A
     case faixa2_classe_B
     etc...
     case faixa5_classe_D

     case faixa1_classe_A
     ping fx1 fx2(for 1 a 255) fx3(for 1 a 255) fx4(for 1 a 255)
     se ping ok = retorno faixas(fx1, fx2, fx3, fx4)
     se nao
        case faixa2_classe_B
            etc...

     */
 }


#define IP_ATUAL
#define FAIXA_1
FAIXA_1 *faixa_1;
#define FAIXA_2
FAIXA_2 *faixa_2;
#define FAIXA_3
FAIXA_3 *faixa_3;
#define FAIXA_4
FAIXA_4 *faixa_4;

/// SEQUENCIA ALEATORIA DE ARMAZENAR IPS COM SEU CODIGO UNICO DE CONSULTA
#define SEQUENCIA_ALEGO
SEQUENCIA_ALEGO *SEC_ALE;

/// TAMANHO DO CONTADOR DE PESQUISA PARA SEQUENCIA DE LEITURA DE IPS
#define TAMANHO_CONTADOR
TAMANHO_CONTADOR *TAM_CONT;

/// SALVA IP NA MEMORIA PARA CONSULTA DA CLASSE NA FAIXA
#define IP_SCANN_A
IP_SCANN_A *IPSCANN_A;
//IPSCANN_A = 0;
/// SALVA IP NA MEMORIA PARA CONSULTA DA CLASSE NA FAIXA
#define IP_SCANN_B
IP_SCANN_B *IPSCANN_B;

/// CONTADOR DO CASE PARA SELECIONAR A SEQUENCIA
#define CONTADOR_CASE
CONTADOR_CASE *contador_case;

#define MAX_TAM_GET20
MAX_TAM_GET20 *MAX_TAM_GET2;

/// FUNCIONOU AGORA É SO BOTAR AS PRINCIPAIS REDES INTERNAS E BUACAR
void IP_SCANNER_LOCAL_HOST_INTRANET()
{
    IP_PRINCIPAL_MENU();
}
void IP_PRINCIPAL_MENU()
{
    int lop;
    printf("\n\n=========================================================\n");
    for(lop=1;lop<=7;lop++)
    {
        if(contador_case <= 0 || contador_case == NULL || contador_case >= 248)
        {
            contador_case = 1;
            printf("%d", contador_case);
            CHAMDAS_GUETS1();
        }else
            contador_case = contador_case + 1;
            printf(" %d", contador_case);
            CHAMDAS_GUETS1();

    }

    CHAMDAS_GUETS1();
}


 /// ESTRUTURA DO SOCKTES
 void CHAMDAS_GUETS1(int argc , char *argv[])
{
    //printf("CHAMADA DE SOCKTES\n");
    WSADATA wsa;
    SOCKET s;
    int a;
    char b;
    int w;
    int cont;

    int adress_2(const char * get1);
    struct sockaddr_in server;
    char *message , server_reply[2000];
    int recv_size;

    //printf("\nINICIO DE LEITURA WEB SOCKETS\n");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        IP_PRINCIPAL_MENU();
        return 1;
    }

    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("ERRO NA CRIACAO DO SOCKTES: %d\n" , WSAGetLastError());
        IP_PRINCIPAL_MENU();
        /// IR PARA OUTRA ETAPA NESTE CASO PARA OUTRO IP
    }

    /// NESTE CASO FAZER AUTOMATICO PARA QUE A LEITURA DE CONTINUIDADE


    if(contador_case == 1)
    {
            printf("\n1 TESTE 172.217.28.4\n");
            server.sin_addr.s_addr  = inet_addr("172.217.28.4");
    }else
    if(contador_case == 5)
    {
            printf("\n2 DISPARANDO CONTRA 127.0.0.1\n");
            server.sin_addr.s_addr  = inet_addr("127.0.0.1");
    }else
    if(contador_case == 9)
    {
            printf("\n3 DISPARANDO CONTRA 192.168.0.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.0.1");
    }else
    if(contador_case == 13)
    {
            printf("\n4 DISPARANDO CONTRA 172.217.28.4\n");
            server.sin_addr.s_addr  = inet_addr("172.217.28.4");
    }else
    if(contador_case == 17)
    {
            printf("\n5 DISPARANDO CONTRA 192.168.1.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.1.1");
    }else
    if(contador_case == 21)
    {
            printf("\n6 DISPARANDO CONTRA 172.217.28.4\n");
            server.sin_addr.s_addr  = inet_addr("172.217.28.4");
    }
    if(contador_case == 25)
    {
            printf("\n7 DISPARANDO CONTRA 255.255.255.0\n");
            server.sin_addr.s_addr  = inet_addr("255.255.255.0");
    }else
    if(contador_case == 29)
    {
            printf("\n8 DISPARANDO CONTRA 192.168.1.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.1.1");
    }else
    if(contador_case == 33)
    {
            printf("\n9 DISPARANDO CONTRA 172.217.28.4\n");
            server.sin_addr.s_addr  = inet_addr("172.217.28.4");
    }else
    if(contador_case == 37)
    {
            printf("\n10 DISPARANDO CONTRA 192.168.2.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.2.1");
    }else
    if(contador_case == 41)
    {
            printf("\n11 DISPARANDO CONTRA 192.168.3.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.3.1");
    }else
    if(contador_case == 45)
    {
            printf("\n12 DISPARANDO CONTRA 172.217.28.4\n");
            server.sin_addr.s_addr  = inet_addr("172.217.28.4");
    }
    if(contador_case == 49)
    {
            printf("\n13 DISPARANDO CONTRA 172.217.28.4\n");
            server.sin_addr.s_addr  = inet_addr("172.217.28.4");
    }
    if(contador_case == 53)
    {
            printf("\n14 DISPARANDO CONTRA 192.168.4.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.4.1");
    }else
    if(contador_case == 57)
    {
            printf("\n15 DISPARANDO CONTRA 172.217.28.4\n");
            server.sin_addr.s_addr  = inet_addr("172.217.28.4");
    }
    if(contador_case == 61)
    {
            printf("\n16 DISPARANDO CONTRA 192.168.5.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.5.1");
    }else
    if(contador_case == 65)
    {
            printf("\n17 DISPARANDO CONTRA 192.168.6.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.6.1");
    }else
    if(contador_case == 69)
    {
            printf("\n18 DISPARANDO CONTRA 192.168.7.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.7.1");
    }else
    if(contador_case == 73)
    {
            printf("\n19 DISPARANDO CONTRA 192.168.8.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.8.1");
    }else
    if(contador_case == 77)
    {
            printf("\n20 DISPARANDO CONTRA 192.168.9.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.9.1");
    }else
    if(contador_case == 81)
    {
            printf("\n21 DISPARANDO CONTRA 192.168.10.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.10.1");
    }else
    if(contador_case == 85)
    {
            printf("\n22 DISPARANDO CONTRA 192.168.11.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.11.1");
    }else
    if(contador_case == 89)
    {
            printf("\n23 DISPARANDO CONTRA 192.168.12.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.12.1");
    }else
    if(contador_case == 93)
    {
            printf("\n24 DISPARANDO CONTRA 192.168.13.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.13.1");
    }else
    if(contador_case == 97)
    {
            printf("\n25 DISPARANDO CONTRA 192.168.15.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.15.1");
    }else
    if(contador_case == 101)
    {
            printf("\n26 DISPARANDO CONTRA 192.168.16.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.16.1");
    }else
    if(contador_case == 105)
    {
            printf("\n27 DISPARANDO CONTRA 192.168.17.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.17.1");
    }else
    if(contador_case == 109)
    {
            printf("\n28 DISPARANDO CONTRA 192.168.18.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.18.1");
    }else
    if(contador_case == 113)
    {
            printf("\n29 DISPARANDO CONTRA 192.168.19.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.19.1");
    }else
    if(contador_case == 117)
    {
            printf("\n30 DISPARANDO CONTRA 192.168.20.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.20.1");
    }else
    if(contador_case == 121)
    {
            printf("\n31 DISPARANDO CONTRA 192.168.21.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.21.1");
    }else
    if(contador_case == 125)
    {
            printf("\n32 DISPARANDO CONTRA 192.168.22.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.22.1");
    }else
    if(contador_case == 129)
    {
            printf("\n33 DISPARANDO CONTRA 192.168.23.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.23.1");
    }else
    if(contador_case == 133)
    {
            printf("\n34 DISPARANDO CONTRA 192.168.24.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.24.1");
    }else
    if(contador_case == 137)
    {
            printf("\n35 DISPARANDO CONTRA 192.168.25.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.25.1");
    }else
    if(contador_case == 141)
    {
            printf("\n36 DISPARANDO CONTRA 192.168.26.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.26.1");
    }else
    if(contador_case == 145)
    {
            printf("\n37 DISPARANDO CONTRA 192.168.27.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.27.1");
    }else
    if(contador_case == 149)
    {
            printf("\n38 DISPARANDO CONTRA 192.168.28.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.28.1");
    }else
    if(contador_case == 153)
    {
            printf("\n39 DISPARANDO CONTRA 192.168.29.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.29.1");
    }else
    if(contador_case == 157)
    {
            printf("\n40 DISPARANDO CONTRA 192.168.30.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.30.1");
    }else
    if(contador_case == 161)
    {
            printf("\n41 DISPARANDO CONTRA 192.168.31.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.31.1");
    }else
    if(contador_case == 165)
    {
            printf("\n42 DISPARANDO CONTRA 192.168.32.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.32.1");
    }else
    if(contador_case == 169)
    {
            printf("\n43 DISPARANDO CONTRA 192.168.33.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.33.1");
    }else
    if(contador_case == 173)
    {
            printf("\n44 DISPARANDO CONTRA 192.168.34.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.34.1");
    }else
    if(contador_case == 177)
    {
            printf("\n45 DISPARANDO CONTRA 192.168.35.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.35.1");
    }else
    if(contador_case == 181)
    {
            printf("\n46 DISPARANDO CONTRA 192.168.36.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.36.1");
    }else
    if(contador_case == 185)
    {
            printf("\n47 DISPARANDO CONTRA 192.168.37.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.37.1");
    }else
    if(contador_case == 189)
    {
            printf("\n48 DISPARANDO CONTRA 192.168.38.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.38.1");
    }else
    if(contador_case == 193)
    {
            printf("\n49 DISPARANDO CONTRA 192.168.39.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.39.1");
    }else
    if(contador_case == 197)
    {
            printf("\n50 DISPARANDO CONTRA 192.168.40.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.40.1");
    }else
    if(contador_case == 201)
    {
            printf("\n51 DISPARANDO CONTRA 192.168.41.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.41.1");
    }else
    if(contador_case == 205)
    {
            printf("\n52 DISPARANDO CONTRA 192.168.42.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.42.1");
    }else
    if(contador_case == 209)
    {
            printf("\n53 DISPARANDO CONTRA 192.168.43.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.43.1");
    }else
    if(contador_case == 213)
    {
            printf("\n54 DISPARANDO CONTRA 192.168.44.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.44.1");
    }else
    if(contador_case == 217)
    {
            printf("\n55 DISPARANDO CONTRA 192.168.45.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.45.1");
    }else
    if(contador_case == 221)
    {
            printf("\n56 DISPARANDO CONTRA 192.168.46.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.46.1");
    }else
    if(contador_case == 225)
    {
            printf("\n57 DISPARANDO CONTRA 192.168.47.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.47.1");
    }else
    if(contador_case == 229)
    {
            printf("\n58 DISPARANDO CONTRA 192.168.48.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.48.1");
    }else
    if(contador_case == 233)
    {
            printf("\n59 DISPARANDO CONTRA 192.168.49.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.49.1");
    }else
    if(contador_case == 237)
    {
            printf("\n60 DISPARANDO CONTRA 192.168.50.1\n");
            server.sin_addr.s_addr  = inet_addr("192.168.50.1");
    }






        server.sin_family =  AF_INET;
        server.sin_port = htons( 80 );
    //server.sin_addr.s_addr  = inet_addr(RET_GATEWAY_ADRESS);
    //server.sin_family =  AF_INET;
    //server.sin_port = htons( 80 );



    ///ERRO DE CONECSÃO
    if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("ERRO DE CONECSAO\n");
        IP_PRINCIPAL_MENU();
        return 1;
    }

    message = "GET / HTTP/1.1\r\n\r\n";
    //message = "TRACE /HTTP/1.1\r\n\r\n";
    //message = "HEAD /HTTP/1.1\r\n\r\n";


    /// FALAH NA CHAMADA DE MSG
    if( send(s , message , strlen(message) , 0) < 0)
    {
        puts("SEND: FALAH NA CHAMADA DE MSG");
        IP_PRINCIPAL_MENU();
        return 1;
    }


    ///puts("Data Send\n");
    ///Receive a reply from the server
    if((recv_size = recv(s , server_reply , 2000 , 0)) == SOCKET_ERROR)
    {
        puts("recv failed");
        IP_PRINCIPAL_MENU();
    }

    //puts("Reply received\n");
    ///Add a NULL terminating character to make it a proper string before printing
    server_reply[recv_size] = '\0';
    puts(server_reply);

    /// PONTEIRO DE DADOS
    MAX_TAM_GET2 = (server_reply);
    printf("\n=========================================================\n");
    IP_PRINCIPAL_MENU();

}

/**
 void IP_SCANNER_LOCAL_HOST_INTRANET()
 {

    char c;
    int  a;
    system("cls");
    printf(" SCANNER DE IP INTRANET \n");
    printf("deseja iniciar o scanner\n");
    printf("sim: A             nao B\n");
    scanf("%s", &c);
    //c = getch();// = c
    switch (c)
    {
    case 'A':
        printf("chamada de classe!\n");
        DEFINER_CLASSE_IP_SCANNER(); /// INICIA O SCANNER DE IP HOSTES REDE INTERNA
        break;
    case 'B':
        IP_PRIMARIO_MENU(); /// MENU DO LEITOR DE IP
        break;
    case 'C':
        IP_PRIMARIO_CHAMADA();
        break;
    case 'D':
        IP_PRIMARIO_CHAMADA();
        break;
    }
 }
 void DEFINER_CLASSE_IP_SCANNER()
 {
char c;
char A1[] = "1.0.0.1";     char A2[] = "127.0.0.1";   char A3[] = "128.0.0.1";   char A4[] = "191.0.0.1";
char B1[] = "192.0.0.1";   char B2[] = "233.0.0.1";   char B3[] = "234.0.0.1";   char B4[] = "239.0.0.1";
char C1[] = "240.0.0.1";   char C2[] = "255.0.0.1";   char C3[] = "1.1.0.1";     char C4[] = "127.1.0.1";
char D1[] = "128.1.0.1";   char D2[] = "191.1.0.1";   char D3[] = "192.1.0.1";   char D4[] = "233.1.0.1";
char E1[] = "234.1.0.1";   char E2[] = "239.1.0.1";   char E3[] = "240.1.0.1";   char E4[] = "255.1.0.1";
char F1[] = "1.1.1.1";     char F2[] = "127.1.1.1";   char F3[] = "128.1.1.1";   char F4[] = "191.1.1.1";
char G1[] = "192.1.1.1";   char G2[] = "233.1.1.1";   char G3[] = "234.1.1.1";   char G4[] = "239.1.1.1";
char H1[] = "240.1.1.1";   char H2[] = "255.1.1.1";   char H3[] = "1.255.0.1";   char H4[] = "127.255.0.1";
char I1[] = "128.255.0.1"; char I2[] = "191.255.0.1"; char I3[] = "192.255.0.1"; char I4[] = "233.255.0.1";
char J1[] = "234.255.0.1"; char J2[] = "239.255.0.1"; char J3[] = "240.255.0.1"; char J4[] = "255.255.0.1";
char L1[] = "127.0.0.1";   char L2[] = "127.0.0.1";   char L3[] = "127.0.0.1";   char L4[] = "127.0.0.1";

    c = getch("A");//

        switch (c)
        {
        case 'A':
            printf("CASE A DAS CLASSE PARA CHAMADAS\n ");
            char A[] = "127.0.0.1";
            IPSCANN_A = A;
            CHAMDAS_GUETS1();
            break;
        case 'B':

            //IPSCANN_B = recebe;
            break;
        case 'C':

            //IPSCANN_C = recebe;
            break;
        case 'D':

            //IPSCANN_D = recebe;
            break;
        case 'E':

            //IPSCANN_E = recebe;
            break;
        case 'F':

            //IPSCANN_F = recebe;
            break;
        case 'G':

            //IPSCANN_G = recebe;
            break;
        case 'H':

            //IPSCANN_H = recebe;
            break;
        case 'I':

            //IPSCANN_I = recebe;
            break;
        case 'J':

            //IPSCANN_J = recebe;
            break;
        }
 }
 */

/**
 void DEFINER_CLASSE_IP_SCANNER()
 {
    char c;
    char enderaco[17];
    int recebe[0] = {get1,get2,get3,get4};
    FILE *pp;
    printf("\nCLASSES DE IP\n");
    char urla [] = "E:\\ARQUIVOScripts\\CLASSE_A.IP";
            pp = fopen(urla,"r");
            pp = fopen(urla, (enderaco, "r"));
            fscanf(pp, "%s", recebe);
    char urlb [] = "E:\\ARQUIVOScripts\\CLASSE_B.IP";
            pp = fopen(urlb,"r");
            pp = fopen(urlb, (enderaco, "r"));
            fscanf(pp, "%s", recebe);
    char urlc [] = "E:\\ARQUIVOScripts\\CLASSE_C.IP";
            pp = fopen(urlc,"r");
            pp = fopen(urlc, (enderaco, "r"));
            fscanf(pp, "%s", recebe);
    char urld [] = "E:\\ARQUIVOScripts\\CLASSE_D.IP";
            pp = fopen(urld,"r");
            pp = fopen(urld, (enderaco, "r"));
            fscanf(pp, "%s", recebe);
    char urle [] = "E:\\ARQUIVOScripts\\CLASSE_E.IP";
            pp = fopen(urle,"r");
            pp = fopen(urle, (enderaco, "r"));
            fscanf(pp, "%s", recebe);
    char urlf [] = "E:\\ARQUIVOScripts\\CLASSE_F.IP";
            pp = fopen(urlf,"r");
            pp = fopen(urlf, (enderaco, "r"));
            fscanf(pp, "%s", recebe);
    char urlg [] = "E:\\ARQUIVOScripts\\CLASSE_G.IP";
            pp = fopen(urlg,"r");
            pp = fopen(urlg, (enderaco, "r"));
            fscanf(pp, "%s", recebe);
    char urlh [] = "E:\\ARQUIVOScripts\\CLASSE_H.IP";
            pp = fopen(urlh,"r");
            pp = fopen(urlh, (enderaco, "r"));
            fscanf(pp, "%s", recebe);
    char urli [] = "E:\\ARQUIVOScripts\\CLASSE_I.IP";
            pp = fopen(urli,"r");
            pp = fopen(urli, (enderaco, "r"));
            fscanf(pp, "%s", recebe);
    char urlj [] = "E:\\ARQUIVOScripts\\CLASSE_J.IP";
            pp = fopen(urlj,"r");
            pp = fopen(urlj, (enderaco, "r"));
            fscanf(pp, "%s", recebe);

        c = getch("A");//

        switch (c)
        {
        case 'A':
            printf("CASE A DAS CLASSE PARA CHAMADAS\n ");
            IPSCANN_A = recebe;
            CHAMDAS_GUETS1();
            break;
        case 'B':

            IPSCANN_B = recebe;
            break;
        case 'C':

            IPSCANN_C = recebe;
            break;
        case 'D':

            IPSCANN_D = recebe;
            break;
        case 'E':

            IPSCANN_E = recebe;
            break;
        case 'F':

            IPSCANN_F = recebe;
            break;
        case 'G':

            IPSCANN_G = recebe;
            break;
        case 'H':

            IPSCANN_H = recebe;
            break;
        case 'I':

            IPSCANN_I = recebe;
            break;
        case 'J':

            IPSCANN_J = recebe;
            break;
        }
 }
 */
/**
 void CHAMDAS_GUETS1(int argc , char *argv[])
{
    printf("CHAMADA DE SOCKTES\n");
    WSADATA wsa;
    SOCKET s;
    char c;

    int adress_2(const char * get1);
    struct sockaddr_in server;
    char *message , server_reply[2000];
    int recv_size;

    printf("\nINICIO DE LEITURA WEB SOCKETS\n");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        main();
        return 1;
    }

    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("ERRO NA CRIACAO DO SOCKTES: %d" , WSAGetLastError());
        /// IR PARA OUTRA ETAPA NESTE CASO PARA OUTRO IP
    }
    printf("DIGITE O CASE DO SOCKTES A\n");
    /// NESTE CASO FAZER AUTOMATICO PARA QUE A LEITURA DE CONTINUIDADE
        c = getch();//

        switch (c)
        {
        case 'A':
            printf("CLASSE A\n");
            server.sin_addr.s_addr  = inet_addr(IPSCANN_A);

            break;
        case 'B':
            server.sin_addr.s_addr  = inet_addr(IPSCANN_B);

            break;
        case 'C':
            server.sin_addr.s_addr  = inet_addr(IPSCANN_C);

            break;
        case 'D':
            server.sin_addr.s_addr  = inet_addr(IPSCANN_D);

            break;
        case 'E':
            server.sin_addr.s_addr  = inet_addr(IPSCANN_E);

            break;
        case 'F':
            server.sin_addr.s_addr  = inet_addr(IPSCANN_F);

            break;
        case 'G':
            server.sin_addr.s_addr  = inet_addr(IPSCANN_G);

            break;
        case 'H':
            server.sin_addr.s_addr  = inet_addr(IPSCANN_H);

            break;
        case 'I':
            server.sin_addr.s_addr  = inet_addr(IPSCANN_I);

            break;
        case 'J':
            server.sin_addr.s_addr  = inet_addr(IPSCANN_J);

            break;

        }


        server.sin_family =  AF_INET;
        server.sin_port = htons( 80 );
    //server.sin_addr.s_addr  = inet_addr(RET_GATEWAY_ADRESS);
    //server.sin_family =  AF_INET;
    //server.sin_port = htons( 80 );



    ///ERRO DE CONECSÃO
    if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("ERRO DE CONECSAO");
        main();
        return 1;
    }

    message = "GET / HTTP/1.1\r\n\r\n";
    //message = "TRACE /HTTP/1.1\r\n\r\n";
    //message = "HEAD /HTTP/1.1\r\n\r\n";


    /// FALAH NA CHAMADA DE MSG
    if( send(s , message , strlen(message) , 0) < 0)
    {
        puts("SEND: FALAH NA CHAMADA DE MSG");
        main();
        return 1;
    }


    ///puts("Data Send\n");
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
    MAX_TAM_GET2 = (server_reply);


    //message = "GET / HTTP/1.1\r\n\r\n";
    //server_reply[recv_size] = '\0';
    //puts(server_reply);
    //MAX_TAM_GET2 = (server_reply);
}
*/


 //case pata selecionar os ips ou algo do tipo


 /**
 void IP_SCANNER_LOCAL_HOST_INTRANET()
     int ip=1;
     int faixa;
     int loop;
     int dados;
     struct dados;


     for(loop=1;loop <=1; loop++)
     {

        ///ESCRITA DE ARQUIVO
        char url[]="E:\\ARQUIVOScripts\\IPscript.bat";
        FILE *arq;
        /// LIPA O ARQUIVO DE TEXTO PARA GRAVAÇÃO
        arq = fopen(url, "w");
        fprintf(arq, "");

        arq = fopen(url, "a");
         for(loop=1;loop<=5;loop++)
         {
             ip++;
             fprintf(arq, "ping 192.168.0.%d > E:\\ARQUIVOScripts\\IP.%d\n", ip,ip);
         }
         fprintf(arq, "exit");
         system("start E:\\ARQUIVOScripts\\IPscript.bat");


     }
 }
 void retorno(void)
 {
     printf("%d", retorno);
 }
*/

 /**
    //fflush(stdin);
    //setbuf(stdin, 0);
    //fflush(stdout);
    //fflush(ip);
    //fflush(printf);
    //fflush(system);
    //int system(const char*);
 //system("ping 192.168.0.1");

        //system("ping" + printf("ping 192.168.0.%d     \n", ip++));/// funcional teste
        //system ("ping" +(printf("ping 192.168.0.%d",ip++)));
        //system (" ping 192.168.0.1" + retorno(1));
        //printf("%d", retorno(_ip));
        //system (printf("ping 192.168.0.%d", loop)+"ping");
         ///system ("ping" + printf("\nping 192.168.0.%d\n", ip++)); funcional
         ///system (" ping 192.168.0.1"); funcional
         //system("ping" + putchar("ping 192.168.0.1") ); nada
         //system("ping 192.168.0." + putwchar(ip) );
         //system("ping" + putenv("ping 192.168.0.1") ); nada
         //system("ping 192.168.0." + putchar(ip) );


         //putc()
         //putchar()
         //putenv()
         //puts()
         //putw()
         //putwc()
         //putwchar()
 */
