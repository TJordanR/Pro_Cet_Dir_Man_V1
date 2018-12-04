#include <stdio.h>
#include <stdlib.h>
/// FAZER O RETORNO DO ERRO   OK
/// DIFERENCIAR MAIOR QUE MENOR QUE 255 1 OK
///
#include "IP_PROJETO_TESTE1.h"

int IP_PRIMARIO_MENU(void)
{
    system("cls");
    printf("\n\n");
    printf("#####SCANNER DE IP LOCAL HOSTE FAIXA DE INTRANET#####\n");
    printf("IP LOCAL MANUAL: 1  AUTOMATICO: 2...................0\n");
    printf("IP SCANNER LOCAL....................................1\n");
    printf("IP EXTERNO HTTP.....................................2\n");
    printf("FAIXAS DE IP........................................3\n");
    printf("MAXIMO MINIMO.......................................4\n");
    printf("MAQUINAS............................................5\n");
    printf("RADIOS..............................................6\n");
    printf("RETORNO HTTP........................................7\n");
    printf("\n\n\n");

    char c;
    c = getch();// = c;

    switch (c)
    {
    case '0':
        IP_PRIMARIO_CHAMADA(); /// DIGITAR O IP MANUAL
        break;
    case '1':
        IP_SCANNER_LOCAL_HOST_INTRANET(); /// CHAMA O SCANNEAMENTO AUTOMATICO DE HOSTES DA REDE
        break;
    case '2':
        printf("Desculpas em manutencao cod: 10\n");
        IP_PRIMARIO_MENU();
        break;
    case '3':
        printf("Desculpas em manutencao cod: 10\n");
        IP_PRIMARIO_MENU();
        break;
    case '4':
        printf("Desculpas em manutencao cod: 10\n");
        IP_PRIMARIO_MENU();
        break;
    case '5':
        printf("Desculpas em manutencao cod: 10\n");
        IP_PRIMARIO_MENU();
        break;
    case '6':
        printf("Desculpas em manutencao cod: 10\n");
        IP_PRIMARIO_MENU();
        break;
    case '7':
        printf("Desculpas em manutencao cod: 10\n");
        IP_PRIMARIO_MENU();
        break;
    case '8':
        printf("Desculpas em manutencao cod: 10\n");
        IP_PRIMARIO_MENU();
        break;
    case '9':
        printf("Desculpas em manutencao cod: 10\n");
        IP_PRIMARIO_MENU();
        break;
    case 'A':
    case 'a':
        printf("Desculpas em manutencao cod: 10\n");
        IP_PRIMARIO_MENU();
        break;

    default:
        break;
    }
}

void IP_PRIMARIO_CHAMADA(void)
{

    int ip;
    int *dados;
    int lop;
    int autentica = 1;
    printf("\nCOMFIGURACAO IP!\n");
    printf("DIGITE UM NUMERO:\n");

    CHAMA_IP_CONF == 1; //RESPONSAVEL POR TRAZER AS CONDICIONAS DA BIBLIOTECA PARA ENTRADA

    dados = malloc(lop * sizeof(int *));
    dados = malloc(ip  * sizeof(int *));

    ///ESCRITA DE ARQUIVO
    char url[]="c:\\IP.IP";
    FILE *arq;
    char a = '.';

    for (lop=1;lop<=4;lop++ )
    {
        scanf("%d", &ip);
        dados[lop] = ip;
        system("cls");
        if(lop == 1)
        {
            // CONDICIONAL QUE VERIFICA SE O INICIO É MENOR QUE 1 E MAIOR QUE 255
            //if(dados[lop] <= max_tam_ip_ent_ini)
            if(dados[lop] <= 0)
            {
                ///CONDICIONAL ERRO RETORNO
                printf("\nERRO, O NUMERO INFORMADO E INVALIDO! MENOR QUE 1\n");
                ret_erro_max_ip1 = dados[lop];
                RETORNO_ERRO = 1; // PARAMETRO QUE ENVIA QUAL ERRO FOI

            }else
            //if(dados[lop] >= max_tam_ip_ent_end && (ip != max_tam_ip_ent_ini))
            if(dados[lop] >= 256)
            {
                ///CONDICIONAL ERRO RETORNO
                printf("\nERRO, O NUMERO INFORMADO E INVALIDO! MAIOR QUE 255\n");
                ret_erro_max_ip1 = dados[lop];
                RETORNO_ERRO = 1; // PARAMETRO QUE ENVIA QUAL ERRO FOI

            }else

            /// SALVAR ARQUIVO NA BIBLIOTECA PARA RETORNO
            printf("%d.",dados[lop]);
            ret_ip1 = dados[lop];
            /// LIPA O ARQUIVO DE TEXTO PARA GRAVAÇÃO
            arq = fopen(url, "w");
            fprintf(arq, "%d", ret_ip1);
            /// ADICIONANDO PONTO "."
            arq = fopen(url, "a");
            fprintf(arq, "%c", a );

        }else
        if(lop == 2)
        {

            //if(dados[lop] >= max_tam_ip_ent_end && (ip != max_tam_ip_ent_ini))
            if(dados[lop] >= 256)
            {
                ///CONDICIONAL ERRO RETORNO
                printf("\nERRO, O NUMERO INFORMADO E INVALIDO! MAIOR QUE 255\n");
                ret_erro_max_ip2 = dados[lop];
                RETORNO_ERRO = 2; // PARAMETRO QUE ENVIA QUAL ERRO FOI

            }else

            /// SALVAR ARQUIVO NA BIBLIOTECA PARA RETORNO
            printf("%d.%d.",dados[lop-1], dados[lop]);
            ret_ip2 = dados[lop];
            /// GRAVA NO ARQUIVO DEPOIS DA LEITURA DE TEXTO
            arq = fopen(url, "a");
            fprintf(arq, "%d", ret_ip2);
            /// ADICIONANDO PONTO "."
            arq = fopen(url, "a");
            fprintf(arq, "%c", a );

        }else
        if(lop == 3)
        {

            //if(dados[lop] >= max_tam_ip_ent_end && (ip != max_tam_ip_ent_ini))
            if(dados[lop] >= 256)
            {
                ///CONDICIONAL ERRO RETORNO
                printf("\nERRO, O NUMERO INFORMADO E INVALIDO! MAIOR QUE 255\n");
                ret_erro_max_ip3 = dados[lop];
                RETORNO_ERRO = 3; // PARAMETRO QUE ENVIA QUAL ERRO FOI

            }else
            /// SALVAR ARQUIVO NA BIBLIOTECA PARA RETORNO
            printf("%d.%d.%d.",dados[lop-2], dados[lop-1], dados[lop]);
            ret_ip3 = dados[lop];
            /// GRAVA NO ARQUIVO DEPOIS DA LEITURA DE TEXTO
            arq = fopen(url, "a");
            fprintf(arq, "%d", ret_ip3);
            /// ADICIONANDO PONTO "."
            arq = fopen(url, "a");
            fprintf(arq, "%c", a );

        }else
        if(lop == 4)
        {

            //if(dados[lop] >= max_tam_ip_ent_end && (ip != max_tam_ip_ent_ini))
            if(dados[lop] >= 256)
            {
                ///CONDICIONAL ERRO RETORNO
                printf("\nERRO, O NUMERO INFORMADO E INVALIDO! MAIOR QUE 255\n");
                ret_erro_max_ip4 = dados[lop];
                RETORNO_ERRO = 4; // PARAMETRO QUE ENVIA QUAL ERRO FOI
            }else

            /// SALVAR ARQUIVO NA BIBLIOTECA PARA RETORNO
            printf("%d.%d.%d.%d",dados[lop-3], dados[lop-2], dados[lop-1], dados[lop]);
            ret_ip4 = dados[lop];
            /// GRAVA NO ARQUIVO DEPOIS DA LEITURA DE TEXTO
            arq = fopen(url, "a");
            fprintf(arq, "%d", ret_ip4);
            /// FINALIZA O PROCESSO DE GRAVAÇÃO DE ARQUIVO
            a = getc(arq);
            int fclose(FILE*);
            if(arq != EOF){
                    int fclose(FILE*);
            }
            //arq = fclose(arq);

        }else
        printf("\n");
    }

    /// IMPRIME OS ERRO QUE OCORRERAM DURANTE A DEFINIÇÃO DO IP
    if(RETORNO_ERRO == 1 || RETORNO_ERRO == 2 || RETORNO_ERRO == 3 || RETORNO_ERRO == 4 )
    {
        printf("\nErro %d.%d.%d.%d",ret_erro_max_ip1,ret_erro_max_ip2,ret_erro_max_ip3,ret_erro_max_ip4);
    }

    printf("\n%d\n",      CHAMA_IP_CONF);
    main();
    //printf("%d\n", max_tam_ip_ini);
}

