#include <stdio.h>
#include <stdlib.h>
#include "IP_PROJETO_TESTE1.h"
#include "DNS_PROJETO_TESTE1.h"
/**
 SALVAR O IP                                    OK KECHE DE MEMORIA
 SALVAR O DNS                                   ?
 SALVAR O MAC                                   OK KECHE DE MEMORIA
 SALVAR GETWAY                                  ?
 SALVAR A MASCARA                               OK KECHE DE MEMORIA
 DEFINIR MASCARA AUTOMATICAMENTE ATRAVES DO IP  OK
 FAZER O CALCULO DA MASCARA                     OK
 SALVAR NOS PARAMETROS                          OK KECHE DE MEMORIA
 *QUANDO DEFINIR O NUMERO DA MASCARA SE MENOR   OK
 *QUE 8 BITS SALVAR OS ZEROS RETORNANDO PARA    OK
 *AS CASAS DECIMAIS NA BIBLIOTECA               OK
 *CONFIRMAR SE DEFINE SOZINHO SEM NECESSIDADE   OK
 *DE CONDICIONAIS DE RETORNO PAR BIBLIOTECA!    OK

*/
 int main(void)
{
    //char url[]="c:\\IP.IP";
    //FILE *arq;
    //arq = fopen(url, "+a");
    //arq = fclose(arq);
    printf("\n==============================================\n");
    printf("\n          MENU COFIGURACAO NETWOKS           \n");
    printf("\n==============================================\n");
    printf("DEFINIR IP....................................1OK\n");
    printf("DEFINIR MASCARA...............................2OK\n");
    printf("DEFINIR GETWAY................................3OK\n");
    printf("DEFINIR DNS...................................4\n");
    printf("DEFINIR MAC...................................5OK\n");
    printf("DEFINIR TELNET................................6OK\n");
    printf("DEFINIR UDP...................................7OK\n");
    printf("DEFINIR FTP...................................8OK\n");
    printf("DEFINIR TCP...................................9OK\n");
    printf("DEFINIR CONFIGURACAO GERAL....................AOK\n");
    printf("TESTE DE PING.................................11\n");
    printf("TESTE DE IP...................................12\n");
    printf("TESTE DE DNS..................................13\n");
    printf("TESTE DE GETWAY...............................14\n");

    char c;
    c = getch();// = c;

    switch (c)
    {
    case '1':
        CHAMA_IP_CONF = 1;
        IP_PRIMARIO_MENU();
        break;
    case '2':
        MENU_MASCARA();
        break;
    case '3':
        CHAMDAS_GUETS();
        break;
    case '4':
        DNS();
        break;
    case '5':
        MAC();
        break;
    case '6':
        TELNET();
        break;
    case '7':
        UDP();
        break;
    case '8':
        FTP();
        break;
    case 'A':
    case 'a':
        CONFIGURACAO();
        break;

    default:
        break;
    }

}

/**
#include "DNS.h"
#include "FTP.h"
#include "GETWAY.h"
#include "IP.h"
#include "MAC.h"
#include "MASCARA.h"
#include "TCP.h"
#include "UDP.h"
*/
