#ifndef MASCARA_PROTOCOLO_TESTE1_H_INCLUDED
#define MASCARA_PROTOCOLO_TESTE1_H_INCLUDED

/// CHAMADA PARA AUTENTICAÇÃO DA MASCARA
#define CHAMADA_CONFIGURA_MASCARA_AUTENTICA
CHAMADA_CONFIGURA_MASCARA_AUTENTICA *CHAMA_MASCARA_CONF;
#define MAX_TAM_MASCARA_ENT_INI
#define MAX_TAM_MASCARA_ENT_END
MAX_TAM_MASCARA_ENT_INI *max_tam_mascara_ent_ini;
MAX_TAM_MASCARA_ENT_END *max_tam_mascara_ent_end;
// CONDICIONAL DE TAMANHOS MAXIMO E MINIMOS DA MASCARA
#if CHAMA_MASCARA_CONF > 0
*max_tam_mascara_ent_ini = 0;
*max_tam_mascara_ent_end = 256;
#endif // CHAMADA_CONFIGURA_MASCARA_AUTENTICA


/// CONDICIONAS DE RETORNO COM ERRO
#define RETORNO_DE_ERRO_MASCARA
RETORNO_DE_ERRO_MASCARA *RETORNO_ERRO_MASCARA;
#define RET_ERRO_MAX_MASCARA1
#define RET_ERRO_MAX_MASCARA2
#define RET_ERRO_MAX_MASCARA3
#define RET_ERRO_MAX_MASCARA4
RET_ERRO_MAX_MASCARA1 *ret_erro_max_mascara1;
RET_ERRO_MAX_MASCARA2 *ret_erro_max_mascara2;
RET_ERRO_MAX_MASCARA3 *ret_erro_max_mascara3;
RET_ERRO_MAX_MASCARA4 *ret_erro_max_mascara4;
// CONDICIONAS DE RETORNO COM ERRO
#ifdef RETORNO_ERRO_MASCARA > 0
#if RETORNO_ERRO_MASCARA  == 1 /// RETORNO ERRO
*ret_erro_max_mascara1;
#endif // RETORNO_ERRO_MASCARA
#if RETORNO_ERRO_MASCARA  == 2 /// RETORNO ERRO
*ret_erro_max_mascara2;
#endif // RETORNO_ERRO_MASCARA
#if RETORNO_ERRO_MASCARA  == 3 /// RETORNO ERRO
*ret_erro_max_mascara3;
#endif // RETORNO_ERRO_MASCARA
#if RETORNO_ERRO_MASCARA  == 4 /// RETORNO ERRO
*ret_erro_max_mascara4;
#endif // RETORNO_ERRO_MASCARA
#endif // RETORNO_DE_ERRO_MASCARA


/// ARMAZENAR OS NUMERICOS DA MASCARA EM ORDEM PARA SER UTILIZADO
#define RET_MASCARA1
#define RET_MASCARA2
#define RET_MASCARA3
#define RET_MASCARA4
RET_MASCARA1 *ret_mascara1;
RET_MASCARA2 *ret_mascara2;
RET_MASCARA3 *ret_mascara3;
RET_MASCARA4 *ret_mascara4;
#define VALIDAR_MASCARA
// VALIDADOR DA MASCARA
#ifdef VALIDAR_MASCARA  > 1
#define RETORNO_MASCARA_VALIDADO1
RETORNO_MASCARA_VALIDADO1 *retorno_mascara_validado;
#endif // VALIDAR_MASCARA


#define CONTADOR
CONTADOR *contador;
#define MASCARA1
MASCARA1 *MASC;

//ALOCAMENTO BINARIO 0
#define QUANTIDADE_BINARIOS_0
QUANTIDADE_BINARIOS_0 *quant_0;
#define BIM10
#define BIM20
#define BIM30
#define BIM40
#define BIM50
#define BIM60
#define BIM70
#define BIM80

//ALOCAMENTO BINARIO 1
#define QUANTIDADE_BINARIOS_1
QUANTIDADE_BINARIOS_1 *quant_1;
#define BIM11
#define BIM21
#define BIM31
#define BIM41
#define BIM51
#define BIM61
#define BIM71
#define BIM81

//ALOCAMENTO BINARIO 2
#define QUANTIDADE_BINARIOS_2
QUANTIDADE_BINARIOS_2 *quant_2;
#define BIM12
#define BIM22
#define BIM32
#define BIM42
#define BIM52
#define BIM62
#define BIM72
#define BIM82

//ALOCAMENTO BINARIO 3
#define QUANTIDADE_BINARIOS_3
QUANTIDADE_BINARIOS_3 *quant_3;
#define BIM13
#define BIM23
#define BIM33
#define BIM43
#define BIM53
#define BIM63
#define BIM73
#define BIM83

/// OCTETO DE ENTRADA 1
BIM10 * bin_10;
BIM20 * bin_20;
BIM30 * bin_30;
BIM40 * bin_40;
BIM50 * bin_50;
BIM60 * bin_60;
BIM70 * bin_70;
BIM80 * bin_80;
/// OCTETO DE ENTRADA 2
BIM11 * bin_11;
BIM21 * bin_21;
BIM31 * bin_31;
BIM41 * bin_41;
BIM51 * bin_51;
BIM61 * bin_61;
BIM71 * bin_71;
BIM81 * bin_81;
/// OCTETO DE ENTRADA 3
BIM12 * bin_12;
BIM22 * bin_22;
BIM32 * bin_32;
BIM42 * bin_42;
BIM52 * bin_52;
BIM62 * bin_62;
BIM72 * bin_72;
BIM82 * bin_82;
/// OCTETO DE ENTRADA 4
BIM13 * bin_13;
BIM23 * bin_23;
BIM33 * bin_33;
BIM43 * bin_43;
BIM53 * bin_53;
BIM63 * bin_63;
BIM73 * bin_73;
BIM83 * bin_83;

#define CONTA_MASCARA
CONTA_MASCARA *cont_mas;

/// FALTA FAZER A MASCARA DE REDE
#define MASCARA_DE_REDE1
MASCARA_DE_REDE1 * mascara_rede1;
#define MASCARA_DE_REDE2
MASCARA_DE_REDE2 * mascara_rede2;
#define MASCARA_DE_REDE3
MASCARA_DE_REDE3 * mascara_rede3;
#define MASCARA_DE_REDE4
MASCARA_DE_REDE4 * mascara_rede4;

/// CALSSE DE REDE MASTER
#define CLASSE_A
CLASSE_A *classe_a;
#define CLASSE_B
CLASSE_B *classe_b;
#define CLASSE_C
CLASSE_C *classe_c;
#define CLASSE_D
CLASSE_D *classe_d;

/// CLASSE DE REDE A
#define CLASSE_A1
CLASSE_A1 *classe_a1;
#define CLASSE_A2
CLASSE_A2 *classe_a2;
#define CLASSE_A3
CLASSE_A3 *classe_a3;
#define CLASSE_A4
CLASSE_A4 *classe_a4;
#define CLASSE_A5
CLASSE_A5 *classe_a5;

/// CLASSE DE REDE B
#define CLASSE_B1
CLASSE_B1 *classe_b1;
#define CLASSE_B2
CLASSE_B2 *classe_b2;
#define CLASSE_B3
CLASSE_B3 *classe_b3;
#define CLASSE_B4
CLASSE_B4 *classe_b4;
#define CLASSE_B5
CLASSE_B5 *classe_b5;

/// CLASSE DE REDE C
#define CLASSE_C1
CLASSE_C1 *classe_c1;
#define CLASSE_C2
CLASSE_C2 *classe_c2;
#define CLASSE_C3
CLASSE_C3 *classe_c3;
#define CLASSE_C4
CLASSE_C4 *classe_c4;
#define CLASSE_C5
CLASSE_C5 *classe_c5;

/// CLASSE DE REDE D
#define CLASSE_D1
CLASSE_D1 *classe_d1;
#define CLASSE_D2
CLASSE_D2 *classe_d2;
#define CLASSE_D3
CLASSE_D3 *classe_d3;
#define CLASSE_D4
CLASSE_D4 *classe_d4;
#define CLASSE_D5
CLASSE_D5 *classe_d5;



#endif // MASCARA_PROTOCOLO_TESTE1_H_INCLUDED
