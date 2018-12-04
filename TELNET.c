#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock.h>
#define BACKLOG_MAX 5
#define BUFFER_SIZE 128
#define EXIT_CALL_STRING "#quit"
int aaa=0;
int local_socket = 0;
int remote_length = 0;
int remote_socket = 0;
int message_length = 0;
char message[BUFFER_SIZE];
unsigned short local_port = 80;
unsigned short remote_port = 80;
char remote_ad[32] = ("192.168.0.106");
char remote_ip[32] = ("192.168.0.106");

struct sockaddr_in local_address;
struct sockaddr_in remote_address;


WSADATA wsa_data;


void menu()
{
    if(aaa == 0)
    {
        TELNET_FILE_SYS();
    }
}

/*
    SERVIDOR
    CLIENTE
 */

/* Exibe uma mensagem de erro e termina o programa */
void msg_err_exit(char *msg)
{
    fprintf(stderr, msg);
    system("PAUSE");
    exit(EXIT_FAILURE);
}
void TELNET(int argc, char **argv)
{

// inicia o Winsock 2.0 (DLL), Only for Windows
       if (WSAStartup(MAKEWORD(2, 0), &wsa_data) != 0)
           msg_err_exit("WSAStartup() failed 3.1\n");
       // criando o socket local para o servidor
       local_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
       if (local_socket == INVALID_SOCKET)
       {
           WSACleanup();
           msg_err_exit("socket() failed 3\n");
       }
       printf("Porta local: ");
       printf("%d\n", local_port); /// DEFINE A PORTA DO SERVIDOR TIAGO
       //scanf("%d", &local_port);


       fflush(stdin);
       // zera a estrutura local_address
       memset(&local_address, 0, sizeof(local_address));
       // internet address family
       local_address.sin_family = AF_INET;
       // porta local
       local_address.sin_port = htons(local_port);
       // endereco
       local_address.sin_addr.s_addr = htonl(INADDR_ANY); // inet_addr("127.0.0.1")
       // interligando o socket com o endereço (local)
       if (bind(local_socket, (struct sockaddr *) &local_address, sizeof(local_address)) == SOCKET_ERROR)
          {
               WSACleanup();
               closesocket(local_socket);
               msg_err_exit("bind() failed 4\n");
           }
       // coloca o socket para escutar as conexoes
       if (listen(local_socket, BACKLOG_MAX) == SOCKET_ERROR)
           {
               WSACleanup();
               closesocket(local_socket);
               msg_err_exit("listen() failed 5\n");
           }

       ///remote_length = sizeof(remote_address);
       remote_length = sizeof(remote_address);
       printf("aguardando alguma conexao...\n");
       remote_socket = accept(local_socket, (struct sockaddr *) &remote_address, &remote_length);
       if(remote_socket == INVALID_SOCKET)
           {
               WSACleanup();
               closesocket(local_socket);
               msg_err_exit("accept() failed 6\n");
           }

       printf("conexao estabelecida com %s\n", inet_ntoa(remote_address.sin_addr));
       printf("aguardando mensagens...\n");
        TELNET_FILE_SYS();
}

void TELNET_FILE_SYS(int argc, char **argv)
{

   do
   {
       /// limpa o buffer
       memset(&message, 0, BUFFER_SIZE);

       /// recebe a mensagem do cliente
       message_length = recv(remote_socket, message, BUFFER_SIZE, 0);
       if(message_length == SOCKET_ERROR)
           msg_err_exit("recv() failed 7\n");

       /// exibe a mensagem na tela
       printf("%s ELE: %s\n", inet_ntoa(remote_address.sin_addr), message);

       /// limpa o buffer
            memset(&message, 0, BUFFER_SIZE);
            printf("VOCE: ");
            gets(message);
            fflush(stdin);
            message_length = strlen(message);
                // envia a mensagem para o servidor
                if (send(remote_socket, message, message_length, 0) == SOCKET_ERROR)
                {
                    WSACleanup();
                    closesocket(remote_socket);
                    msg_err_exit("send() failed 2\n");
                }

    }
   while(strcmp(message, EXIT_CALL_STRING)); // sai quando receber um "#quit" do cliente

   //printf("encerrando\n");
   //WSACleanup();
   //closesocket(local_socket);
   //closesocket(remote_socket);


/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //if (WSAStartup(MAKEWORD(2, 0), &wsa_data) != 0)
        //msg_err_exit("WSAStartup() failed 0\n");
        //printf("IP do servidor: ");
        //scanf("%s", remote_ip);
        //fflush(stdin);
        //printf("Porta do servidor: ");
        //scanf("%d", &remote_port);
        //fflush(stdin);
        //remote_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    //if (remote_socket == INVALID_SOCKET)
    //{
    //    WSACleanup();
    //    msg_err_exit("socket() failed 1\n");
    //}
            // preenchendo o remote_address (servidor)
            memset(&remote_address, 0, sizeof(remote_address));
            remote_address.sin_family = AF_INET;
            remote_address.sin_addr.s_addr = inet_addr(remote_ip);
            remote_address.sin_port = htons(remote_port);

            //printf("conectando ao servidor %s...\n", remote_ip);
            //if (connect(remote_socket, (struct sockaddr *) &remote_address, sizeof(remote_address)) == SOCKET_ERROR)
            //{
            //    WSACleanup();
            //    msg_err_exit("connect() failed 2 \n");
            //}
            //printf("digite as mensagens\n");
    ///
        do
        {
            // limpa o buffer
            memset(&message, 0, BUFFER_SIZE);
            printf("msg: ");
            gets(message);
            fflush(stdin);
            message_length = strlen(message);
                // envia a mensagem para o servidor
                if (send(remote_socket, message, message_length, 0) == SOCKET_ERROR)
                {
                    WSACleanup();
                    closesocket(remote_socket);
                    msg_err_exit("send() failed 2\n");
                }

        }
        while(strcmp(message, EXIT_CALL_STRING)); // sai quando enviar um "#quit" para o servidor
        menu();
    //printf("encerrando\n");
    //WSACleanup();
    //closesocket(remote_socket);


/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   return 0;
}
