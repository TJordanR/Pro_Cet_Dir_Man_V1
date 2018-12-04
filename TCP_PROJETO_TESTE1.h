#ifndef TCP_PROTOCOLO_TESTE1_H_INCLUDED
#define TCP_PROTOCOLO_TESTE1_H_INCLUDED

#define SAIR
#define LISTAR
#define SALVAR
#define IP_ADRESS
#define SERVIDOR
#define PING
#define PORTA
#define MSN
#define ARQUIVO
#define ENVIAR
#define RECEBER
SAIR *sai;
LISTAR *listar;
SALVAR salv;
IP_ADRESS *ip_adress;
SERVIDOR *serv;
PING *ping;
PORTA *port;
MSN *msn;
ARQUIVO *arquivo;
ENVIAR *enviar;
RECEBER *receber;

/// SAIR
#if sai > 0
#define SAIR_CONECTION
#endif // sai

/// LISTAR
#if listar > 0
#define LIST_CONECTION
#endif // listar
/// SALVAR

#if salv > 0
#define SALVAR_CONECTION
#endif // salv

/// IP ADRESS
#if ip_adress > 0
#define IP_CONECTION
#endif // ip_adress
/// SERVIDOR

#if serv > 0
#define SERVIDOR_CONECTION
#endif // serv

/// PING
#if ping > 0
#define PING_CONECTION
#endif // ping
/// PORTA
#if porta > 0
#define PORTA_CONECTION
#endif // porta

/// MSN
#if msn > 0
#define MSN_CONECTION
#endif // msn

/// ARQUIVO
#if arquivo > 0
#define ARQUIVO_CONECTION
#endif // arquivo

/// ENVIAR
#if enviar > 0
#define ENVIAR_CONECTION
#endif // enviar

/// RECEBER
#if receber > 0
#define RECEBER_CONECTION
#endif // receber






#endif // TCP_PROTOCOLO_TESTE1_H_INCLUDED
