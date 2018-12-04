#ifndef IP_PROJETO_TESTE1_H_INCLUDED
#define IP_PROJETO_TESTE1_H_INCLUDED

/// CHAMADA PARA AUTENTICAÇÃO
#define CHAMADA_CONFIGURA_IP_AUTENTICA
CHAMADA_CONFIGURA_IP_AUTENTICA *CHAMA_IP_CONF;
#define MAX_TAM_IP_ENT_INI
#define MAX_TAM_IP_ENT_END
MAX_TAM_IP_ENT_INI *max_tam_ip_ent_ini;
MAX_TAM_IP_ENT_END *max_tam_ip_ent_end;
// CONDICIONAL DE TAMANHOS MAXIMO E MINIMOS DE IP
#if CHAMA_IP_CONF > 0
*max_tam_ip_ent_ini = 0;
*max_tam_ip_ent_end = 256;
#endif // CHAMADA_CONFIGURA_IP_AUTENTICA


/// CONDICIONAS DE RETORNO COM ERRO
#define RETORNO_DE_ERRO
RETORNO_DE_ERRO *RETORNO_ERRO;
#define RET_ERRO_MAX_IP1
#define RET_ERRO_MAX_IP2
#define RET_ERRO_MAX_IP3
#define RET_ERRO_MAX_IP4
RET_ERRO_MAX_IP1 *ret_erro_max_ip1;
RET_ERRO_MAX_IP2 *ret_erro_max_ip2;
RET_ERRO_MAX_IP3 *ret_erro_max_ip3;
RET_ERRO_MAX_IP4 *ret_erro_max_ip4;
// CONDICIONAS DE RETORNO COM ERRO
#ifdef RETORNO_ERRO > 0
#if RETORNO_ERRO == 1 /// RETORNO ERRO
*ret_erro_max_ip1;
#endif // RETORNO_ERRO
#if RETORNO_ERRO == 2 /// RETORNO ERRO
*ret_erro_max_ip2;
#endif // RETORNO_ERRO
#if RETORNO_ERRO == 3 /// RETORNO ERRO
*ret_erro_max_ip3;
#endif // RETORNO_ERRO
#if RETORNO_ERRO == 4 /// RETORNO ERRO
*ret_erro_max_ip4;
#endif // RETORNO_ERRO
#endif // RETORNO_DE_ERRO


/// ARMAZENAR OS NUMERICOS DOS IPs EM ORDEM PARA SER UTILIZADO
#define RET_IP1
#define RET_IP2
#define RET_IP3
#define RET_IP4
RET_IP1 *ret_ip1;
RET_IP2 *ret_ip2;
RET_IP3 *ret_ip3;
RET_IP4 *ret_ip4;
#define VALIDAR_IP
// VALIDADOR DE IP
#ifdef VALIDAR_IP > 1
#define RETORNO_IP_VALIDADO
RETORNO_IP_VALIDADO *retorno_ip_validado;
#endif // VALIDAR_IP

#endif // IP_PROJETO_TESTE1_H_INCLUDED
