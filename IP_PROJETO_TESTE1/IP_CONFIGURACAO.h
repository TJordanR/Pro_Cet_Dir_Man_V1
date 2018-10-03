#ifndef IP_CONFIGURACAO_H_INCLUDED
#define IP_CONFIGURACAO_H_INCLUDED

#include "IP_PROJETO_TESTE1.h"
#include "IP_PROTOCOLO_TESTE.h"

#define IP_CONFIGURACAO
IP_CONFIGURACAO *IP_ENTRADA;
#ifdef IP_CONFIGURACAO > 0
    #define MAX_TAM_ENT_IP_INI
    #define MAX_TAM_ENT_IP_FIM
    #define ERRO_MAX_TAM_ENT_IP_INI
    #define ERRO_MAX_TAM_ENT_IP_FIM

    #define SALVA_IP_1
    SALVA_IP_1 *salv_ip_1;
    #define SALVA_IP_2
    SALVA_IP_2 *salv_ip_2;
    #define SALVA_IP_3
    SALVA_IP_3 *salv_ip_3;
    #define SALVA_IP_4
    SALVA_IP_4 *salv_ip_4;

    MAX_TAM_ENT_IP_INI *mx_ip_ini = 1;
    MAX_TAM_ENT_IP_FIM *mx_ip_fim = 255;
    ERRO_MAX_TAM_ENT_IP_INI *erro_ip_ini;
    ERRO_MAX_TAM_ENT_IP_FIM *erro_ip_fim;

#else
    printf("\n IP AUTOMATICO DHCP ATIVADO! \n");

#endif


#define MASCARA_CONFIGURACAO
MASCARA_CONFIGURACAO *MASCARA_ENTRADA;
#ifdef MASCARA_CONFIGURACAO !> 0
    #define ENT_BIN_1
    #define ENT_BIN_0
    #define MAX_TAM_ENT_MAS_INI
    #define MAX_TAM_ENT_MAS_FIM
    #define CONTADOR_MASCARA
    #define BIN_MAS_1
    #define BIN_MAS_2
    #define BIN_MAS_3
    #define BIN_MAS_4
    #define BIN_MAS_5
    #define BIN_MAS_6
    #define BIN_MAS_7
    #define BIN_MAS_8
    #define ERRO_MAX_TAM_ENT_MAS_INI
    #define ERRO_MAX_TAM_ENT_MAS_FIM
     ENT_BIN_1 *mas_ent_bin_ini = 1;
     ENT_BIN_0 *mas_ent_bin_fim = 0;
     MAX_TAM_ENT_MAS_INI *max_tam_mas_ini = 1;
     MAX_TAM_ENT_MAS_FIM *max_tam_mas_ent = 255;
     CONTADOR_MASCARA *cont_mas;
     BIN_MAS_1 *bin_1;
     BIN_MAS_2 *bin_2;
     BIN_MAS_3 *bin_3;
     BIN_MAS_4 *bin_4;
     BIN_MAS_5 *bin_5;
     BIN_MAS_6 *bin_6;
     BIN_MAS_7 *bin_7;
     BIN_MAS_8 *bin_8;
    ERRO_MAX_TAM_ENT_MAS_INI *erro_mas_ini;
    ERRO_MAX_TAM_ENT_MAS_FIM *erro_mas_fim;

#else
    printf("\n MASCARA DEFINIDA AUTOMATICAMENTE! \n");

#endif


#define DNS_CONFIGURACAO
DNS_CONFIGURACAO *DNS_ENTRADA;
#ifdef DNS_CONFIGURACAO !> 0

#else
    printf("\n DNS DEFINIDO AUTOMATICAMENTE! \n");

#endif


#define GETWAY_CONFIGURACAO
GETWAY_CONFIGURACAO *GETWAY_ENTRADA;
#ifdef GETWAY_CONFIGURACAO !> 0

#else
    printf("\n GETWAY DEFINIDO AUTOMATICAMENTE! \n");

#endif


#define DHCP_CONFIGURACAO
DHCP_CONFIGURACAO *DHCP_ENTRADA;
#ifdef DHCP_CONFIGURACAO !> 0

#else
    printf("\n DHCP ATIVADO ENTRADA DE IP!\n");

#endif


#define FILE_TRASMITE_TX
FILE_TRASMITE_TX *FILE_TX_ENTRADA;
#ifdef FILE_TRASMITE_TX !> 0

#else
    printf("\n TRASMICAO DE ARQUIVO TX!\n");

#endif

#define FILE_TRASMITE_RX
FILE_TRASMITE_RX *FILE_RX_ENTRADA;
#ifdef FILE_TRASMITE_RX !> 0

#else
    printf("\n RECEPCAO DE ARQUIVO RX!\n");

#endif



#endif // IP_CONFIGURACAO_H_INCLUDED
