#include <stdio.h>
#include <stdlib.h>

#include "MASCARA_PROJETO_TESTE1.h"
#include "IP_PROJETO_TESTE1.h"

/// MENU DE CONFIGURAÇÃO DA MASCARA DE REDE
void MENU_MASCARA()
{

    system("cls");
    printf("\n==============================================\n");
    printf("\n          MENU COFIGURACAO MASCARA            \n");
    printf("\n==============================================\n");
    printf("DEFINIR MASCARA...............................1OK\n");
    printf("DEFINIR MASCARA AUTOMATICAMENTE...............2\n");
    printf("VER CONFIGURACORS.............................3\n");

    char chama_menu;
    chama_menu = getch();// = c;

    switch (chama_menu)
    {
        case '1':
            MASCARA();
            break;
        case '2':
            /// MASCARA DE REDE AUTOMATICA
            MASCARA_AUTOMATICA();
            break;
        case '3':
            //CHAMA_IP_CONF = 1;
            //IP_PRIMARIO_CHAMADA();
            break;
        case '4':
            //CHAMA_IP_CONF = 1;
            //IP_PRIMARIO_CHAMADA();
            break;
        default:
        break;
    }
}

/// DEFINIR MASCARA MANUAL
/// FILTROS DE TAMANHOS
void MASCARA()
{
    int ip;
    int *dados;
    int lop;
    int autentica = 1;
    printf("\nDEFINA A MASCARA DE REDE!\n");
    printf("DIGITE UM NUMERO:\n");

    CHAMA_MASCARA_CONF == 1; //RESPONSAVEL POR TRAZER AS CONDICIONAS DA BIBLIOTECA PARA ENTRADA

    dados = malloc(lop * sizeof(int *));
    dados = malloc(ip  * sizeof(int *));

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
                ret_erro_max_mascara1 = dados[lop];
                RETORNO_ERRO_MASCARA = 1; // PARAMETRO QUE ENVIA QUAL ERRO FOI

            }else
            //if(dados[lop] >= max_tam_ip_ent_end && (ip != max_tam_ip_ent_ini))
            if(dados[lop] >= 256)
            {
                ///CONDICIONAL ERRO RETORNO
                printf("\nERRO, O NUMERO INFORMADO E INVALIDO! MAIOR QUE 255\n");
                ret_erro_max_mascara1 = dados[lop];
                RETORNO_ERRO_MASCARA = 1; // PARAMETRO QUE ENVIA QUAL ERRO FOI

            }else
            printf("%d.",dados[lop]);
            ret_mascara1 = dados[lop];

        }else
        if(lop == 2)
        {

            //if(dados[lop] >= max_tam_ip_ent_end && (ip != max_tam_ip_ent_ini))
            if(dados[lop] >= 256)
            {
                ///CONDICIONAL ERRO RETORNO
                printf("\nERRO, O NUMERO INFORMADO E INVALIDO! MAIOR QUE 255\n");
                ret_erro_max_mascara2 = dados[lop];
                RETORNO_ERRO_MASCARA = 2; // PARAMETRO QUE ENVIA QUAL ERRO FOI

            }else
            printf("%d.%d.",dados[lop-1], dados[lop]);
            ret_mascara2 = dados[lop];

        }else
        if(lop == 3)
        {

            //if(dados[lop] >= max_tam_ip_ent_end && (ip != max_tam_ip_ent_ini))
            if(dados[lop] >= 256)
            {
                ///CONDICIONAL ERRO RETORNO
                printf("\nERRO, O NUMERO INFORMADO E INVALIDO! MAIOR QUE 255\n");
                ret_erro_max_mascara3 = dados[lop];
                RETORNO_ERRO_MASCARA = 3; // PARAMETRO QUE ENVIA QUAL ERRO FOI

            }else
            printf("%d.%d.%d.",dados[lop-2], dados[lop-1], dados[lop]);
            ret_mascara3 = dados[lop];

        }else
        if(lop == 4)
        {

            //if(dados[lop] >= max_tam_ip_ent_end && (ip != max_tam_ip_ent_ini))
            if(dados[lop] >= 256)
            {
                ///CONDICIONAL ERRO RETORNO
                printf("\nERRO, O NUMERO INFORMADO E INVALIDO! MAIOR QUE 255\n");
                ret_erro_max_mascara4 = dados[lop];
                RETORNO_ERRO_MASCARA = 4; // PARAMETRO QUE ENVIA QUAL ERRO FOI
            }else
            printf("%d.%d.%d.%d",dados[lop-3], dados[lop-2], dados[lop-1], dados[lop]);
            ret_mascara4 = dados[lop];
        }else
        printf("\n");
    }

    /// IMPRIME OS ERRO QUE OCORRERAM DURANTE A DEFINIÇÃO DO IP
    if(RETORNO_ERRO_MASCARA ==1||RETORNO_ERRO_MASCARA==2||RETORNO_ERRO_MASCARA==3||RETORNO_ERRO_MASCARA==4)
    {
        printf("\nErro %d.%d.%d.%d",ret_erro_max_mascara1,ret_erro_max_mascara2,ret_erro_max_mascara3,ret_erro_max_mascara4);
    }

    printf("\n%d\n",      CHAMA_MASCARA_CONF);

    /// FILTRO DA MASCARA DE REDE E RETORNO DE BINARIOS
    MASCARA_BINARIOS();
}

/// FILTRO DA MASCARA DE REDE
/// RETORNO DE BINARIOS
void MASCARA_BINARIOS()
{
    printf("\nCONFIGURACAO MASCARA!\n");
    printf("\n%d\n", MASC);

    ///calculo_mascara()
    //system("cls");
    printf("\nip2:%d.%d.%d.%d\n",ret_mascara1,ret_mascara2,ret_mascara3,ret_mascara4); /// para validar os numeros salvos!
    system("pause");

    int masc;
    int n2;
    int b10,b20,b30,b40,b50,b60,b70,b80;
    int b11,b21,b31,b41,b51,b61,b71,b81;
    int b12,b22,b32,b42,b52,b62,b72,b82;
    int b13,b23,b33,b43,b53,b63,b73,b83;
    int lop;
    int *dados;
    /// ALOCAMENTO DE MEMORIA
    dados = malloc(lop * sizeof(int *));
    dados = malloc(n2 * sizeof(int *));

    /// OCTETO DE CHAMADA 1
    bin_10 = malloc(b10 * sizeof(int *)); /// bin_1[B] = malloc(b1 * sizeof(int *));
    bin_20 = malloc(b20 * sizeof(int *));
    bin_30 = malloc(b30 * sizeof(int *));
    bin_40 = malloc(b40 * sizeof(int *));
    bin_50 = malloc(b50 * sizeof(int *));
    bin_60 = malloc(b60 * sizeof(int *));
    bin_70 = malloc(b70 * sizeof(int *));
    bin_80 = malloc(b80 * sizeof(int *));

    /// OCTETO DE CHAMADA 2
    bin_11 = malloc(b11 * sizeof(int *)); /// bin_1[B] = malloc(b1 * sizeof(int *));
    bin_21 = malloc(b21 * sizeof(int *));
    bin_31 = malloc(b31 * sizeof(int *));
    bin_41 = malloc(b41 * sizeof(int *));
    bin_51 = malloc(b51 * sizeof(int *));
    bin_61 = malloc(b61 * sizeof(int *));
    bin_71 = malloc(b71 * sizeof(int *));
    bin_81 = malloc(b81 * sizeof(int *));

    /// OCTETO DE CHAMADA 3
    bin_12 = malloc(b12 * sizeof(int *)); /// bin_1[B] = malloc(b1 * sizeof(int *));
    bin_22 = malloc(b22 * sizeof(int *));
    bin_32 = malloc(b32 * sizeof(int *));
    bin_42 = malloc(b42 * sizeof(int *));
    bin_52 = malloc(b52 * sizeof(int *));
    bin_62 = malloc(b62 * sizeof(int *));
    bin_72 = malloc(b72 * sizeof(int *));
    bin_82 = malloc(b82 * sizeof(int *));

    /// OCTETO DE CHAMADA 4
    bin_13 = malloc(b13 * sizeof(int *)); /// bin_1[B] = malloc(b1 * sizeof(int *));
    bin_23 = malloc(b23 * sizeof(int *));
    bin_33 = malloc(b33 * sizeof(int *));
    bin_43 = malloc(b43 * sizeof(int *));
    bin_53 = malloc(b53 * sizeof(int *));
    bin_63 = malloc(b63 * sizeof(int *));
    bin_73 = malloc(b73 * sizeof(int *));
    bin_83 = malloc(b83 * sizeof(int *));

    printf("\n\n");

    ///CALCULO PARA OBTER A SEQUENCIA CORRETA DAS POSIÇÕES DE BITS DE ENVIO DA MASCARA
    for(cont_mas=0; cont_mas<=5; cont_mas++)
        {
            if(cont_mas = 1)
            {
                    masc = ret_mascara1; // BUSCA NA BIBLIOTECA O NUMERO DIGITADO
                    for(lop=0;masc >= 1 ;lop++)
                    {
                        if(lop == 0)
                        {

                        } else
                        {
                            masc = masc / 2;
                            printf("Mas %d", masc);
                            if(masc%2 == 0){printf("    Bin 0\n"); n2 = 0; dados[lop] = n2;}
                            else{printf("    Bin 1\n"); n2 = 1; dados[lop] = n2;}
                        }
                    }
                    printf("%d\n", lop);// QUANTIDADE DE BITS
                    quant_0 = lop;/// DEFINE DE OS VALORES DOS BINARIOS 8

                    ///IMPRIMIR A ORDEM CORRETA DE BINARIOS PARA CONTAGEM E VALIDAÇÃO
                    for(lop=7;lop >= 0 ;lop--)
                    {
                        printf("%d", dados[lop]);
                            if(lop == 7){  if(dados[lop] == 1){bin_10 = 128;}else{bin_10 = 0;}  }
                            if(lop == 6){  if(dados[lop] == 1){bin_20 = 64;} else{bin_20 = 0;}  }
                            if(lop == 5){  if(dados[lop] == 1){bin_30 = 32;} else{bin_30 = 0;}  }
                            if(lop == 4){  if(dados[lop] == 1){bin_40 = 16;} else{bin_40 = 0;}  }
                            if(lop == 3){  if(dados[lop] == 1){bin_50 =  8;} else{bin_50 = 0;}  }
                            if(lop == 2){  if(dados[lop] == 1){bin_60 =  4;} else{bin_60 = 0;}  }
                            if(lop == 1){  if(dados[lop] == 1){bin_70 =  2;} else{bin_70 = 0;}  }
                            if(lop == 0){  if(dados[lop] == 1){bin_80 =  1;} else{bin_80 = 0;}  }
                    }

                    printf("\n\n");
            }
            if(cont_mas = 1)
            {
                masc = ret_mascara2; // BUSCA NA BIBLIOTECA O NUMERO DIGITADO
                for(lop=0;masc >= 1 ;lop++)
                    {
                        if(lop == 0)
                        {

                        } else
                        {
                            masc = masc / 2;
                            printf("Mas %d", masc);
                            if(masc%2 == 0){printf("    Bin 0\n"); n2 = 0; dados[lop] = n2;}
                            else{printf("    Bin 1\n"); n2 = 1; dados[lop] = n2;}
                        }
                    }
                    printf("%d\n", lop);// QUANTIDADE DE BITS
                    quant_1 = lop;/// DEFINE DE OS VALORES DOS BINARIOS 8

                    ///IMPRIMIR A ORDEM CORRETA DE BINARIOS PARA CONTAGEM E VALIDAÇÃO
                    for(lop=7;lop >= 0 ;lop--)
                    {
                        printf("%d", dados[lop]);
                            if(lop == 7){  if(dados[lop] == 1){bin_11 = 128;}else{bin_11 = 0;}  }
                            if(lop == 6){  if(dados[lop] == 1){bin_21 = 64;} else{bin_21 = 0;}  }
                            if(lop == 5){  if(dados[lop] == 1){bin_31 = 32;} else{bin_31 = 0;}  }
                            if(lop == 4){  if(dados[lop] == 1){bin_41 = 16;} else{bin_41 = 0;}  }
                            if(lop == 3){  if(dados[lop] == 1){bin_51 =  8;} else{bin_51 = 0;}  }
                            if(lop == 2){  if(dados[lop] == 1){bin_61 =  4;} else{bin_61 = 0;}  }
                            if(lop == 1){  if(dados[lop] == 1){bin_71 =  2;} else{bin_71 = 0;}  }
                            if(lop == 0){  if(dados[lop] == 1){bin_81 =  1;} else{bin_81 = 0;}  }
                    }
                    printf("\n\n");
            }
            if(cont_mas = 2)
            {
                    masc = ret_mascara3; // BUSCA NA BIBLIOTECA O NUMERO DIGITADO
                    for(lop=0;masc >= 1 ;lop++)
                    {
                        if(lop == 0)
                        {

                        } else
                        {
                            masc = masc / 2;
                            printf("Mas %d", masc);
                            if(masc%2 == 0){printf("    Bin 0\n"); n2 = 0; dados[lop] = n2;}
                            else{printf("    Bin 1\n"); n2 = 1; dados[lop] = n2;}
                        }
                    }
                    printf("%d\n", lop);// QUANTIDADE DE BITS
                    quant_2 = lop;/// DEFINE DE OS VALORES DOS BINARIOS 8

                    ///IMPRIMIR A ORDEM CORRETA DE BINARIOS PARA CONTAGEM E VALIDAÇÃO
                    for(lop=7;lop >= 0 ;lop--)
                    {
                        printf("%d", dados[lop]);
                            if(lop == 7){  if(dados[lop] == 1){bin_12 = 128;}else{bin_12 = 0;}  }
                            if(lop == 6){  if(dados[lop] == 1){bin_22 = 64;} else{bin_22 = 0;}  }
                            if(lop == 5){  if(dados[lop] == 1){bin_32 = 32;} else{bin_32 = 0;}  }
                            if(lop == 4){  if(dados[lop] == 1){bin_42 = 16;} else{bin_42 = 0;}  }
                            if(lop == 3){  if(dados[lop] == 1){bin_52 =  8;} else{bin_52 = 0;}  }
                            if(lop == 2){  if(dados[lop] == 1){bin_62 =  4;} else{bin_62 = 0;}  }
                            if(lop == 1){  if(dados[lop] == 1){bin_72 =  2;} else{bin_72 = 0;}  }
                            if(lop == 0){  if(dados[lop] == 1){bin_82 =  1;} else{bin_82 = 0;}  }
                    }
                    printf("\n\n");
            }
            if(cont_mas = 3)
            {
                    masc = ret_mascara4; // BUSCA NA BIBLIOTECA O NUMERO DIGITADO
                    for(lop=0;masc >= 1 ;lop++)
                    {
                        if(lop == 0)
                        {

                        } else
                        {
                            masc = masc / 2;
                            printf("Mas %d", masc);
                            if(masc%2 == 0){printf("    Bin 0\n"); n2 = 0; dados[lop] = n2;}
                            else{printf("    Bin 1\n"); n2 = 1; dados[lop] = n2;}
                        }
                    }
                    printf("%d\n", lop);// QUANTIDADE DE BITS
                    quant_3 = lop;/// DEFINE DE OS VALORES DOS BINARIOS 8

                    ///IMPRIMIR A ORDEM CORRETA DE BINARIOS PARA CONTAGEM E VALIDAÇÃO
                    for(lop=7;lop >= 0 ;lop--)
                    {
                        printf("%d", dados[lop]);
                            if(lop == 7){  if(dados[lop] == 1){bin_13 = 128;}else{bin_13 = 0;}  }
                            if(lop == 6){  if(dados[lop] == 1){bin_23 = 64;} else{bin_23 = 0;}  }
                            if(lop == 5){  if(dados[lop] == 1){bin_33 = 32;} else{bin_33 = 0;}  }
                            if(lop == 4){  if(dados[lop] == 1){bin_43 = 16;} else{bin_43 = 0;}  }
                            if(lop == 3){  if(dados[lop] == 1){bin_53 =  8;} else{bin_53 = 0;}  }
                            if(lop == 2){  if(dados[lop] == 1){bin_63 =  4;} else{bin_63 = 0;}  }
                            if(lop == 1){  if(dados[lop] == 1){bin_73 =  2;} else{bin_73 = 0;}  }
                            if(lop == 0){  if(dados[lop] == 1){bin_83 =  1;} else{bin_83 = 0;}  }
                    }
                    printf("\n\n");
            }
        }

        if(cont_mas = 5)
        {
            printf("FIM DA CONTAGEM MASCARA!");
        }

        /// SOMA DE VALORES DA MASCARA MANUAL E ORDENAÇÃO DE BINARIOS
        MASCARA_DEFINIDA();

}

/// SOMA DA MASCARA MANUAL
/// ORDENAÇÃO DE BINARIOS
void MASCARA_DEFINIDA()
{
    //system("cls");
    int lop, lop1, lop2;
    int calculo,a,b,c,d,e,f,g,h,i,j,l,m,n,o,p;
    a = malloc( sizeof(int *));
    b = malloc( sizeof(int *));
    c = malloc( sizeof(int *));
    d = malloc( sizeof(int *));
    e = malloc( sizeof(int *));
    f = malloc( sizeof(int *));
    g = malloc( sizeof(int *));
    h = malloc( sizeof(int *));
    printf("\n\n\nIMPRIMIR BINARIOS DA MASCARA!\n");
    ///IMPRIMIR A ORDEM CORRETA DE BINARIOS PARA CONTAGEM E VALIDAÇÃO
    for(lop1=1;lop1<=4;lop1++)
    {

        if(lop1 == 1)
        {
            for(lop=7;lop >= 0 ;lop--)
            {
                /// RESGATA POSICAO DE BITS
                if(lop == 7){  printf("%d|",bin_10);  }
                if(lop == 6){  printf("%d|",bin_20);  }
                if(lop == 5){  printf("%d|",bin_30);  }
                if(lop == 4){  printf("%d|",bin_40);  }
                if(lop == 3){  printf("%d|",bin_50);  }
                if(lop == 2){  printf("%d|",bin_60);  }
                if(lop == 1){  printf("%d|",bin_70);  }
                if(lop == 0){  printf("%d",bin_80);  }
            }
                a = bin_10;b = bin_20;c = bin_30;d = bin_40;e = bin_50;f = bin_60;g = bin_70;h = bin_80;
                i = a+b;j = i+c;l = j+d;m = l+e;n = m+f;o = n+g;p = o+h;
                mascara_rede1 = p; /// VALOR DA MASCARA FILTRADA
                printf("\nMASCARA DE REDE:%d|\n\n", p);
        }else
        if(lop1 == 2)
        {
            for(lop=7;lop >= 0 ;lop--)
            {
                /// RESGATA POSICAO DE BITS
                if(lop == 7){  printf("%d|",bin_11);  }
                if(lop == 6){  printf("%d|",bin_21);  }
                if(lop == 5){  printf("%d|",bin_31);  }
                if(lop == 4){  printf("%d|",bin_41);  }
                if(lop == 3){  printf("%d|",bin_51);  }
                if(lop == 2){  printf("%d|",bin_61);  }
                if(lop == 1){  printf("%d|",bin_71);  }
                if(lop == 0){  printf("%d", bin_81);  }
            }
                a = bin_11;b = bin_21;c = bin_31;d = bin_41;e = bin_51;f = bin_61;g = bin_71;h = bin_81;
                i = a+b;j = i+c;l = j+d;m = l+e;n = m+f;o = n+g;p = o+h;
                mascara_rede2 = p;/// VALOR DA MASCARA FILTRADA
                printf("\nMASCARA DE REDE:%d|\n\n", p);
        }else
        if(lop1 == 3)
        {
            for(lop=7;lop >= 0 ;lop--)
            {
                /// RESGATA POSICAO DE BITS
                if(lop == 7){  printf("%d|",bin_12);  }
                if(lop == 6){  printf("%d|",bin_22);  }
                if(lop == 5){  printf("%d|",bin_32);  }
                if(lop == 4){  printf("%d|",bin_42);  }
                if(lop == 3){  printf("%d|",bin_52);  }
                if(lop == 2){  printf("%d|",bin_62);  }
                if(lop == 1){  printf("%d|",bin_72);  }
                if(lop == 0){  printf("%d", bin_82);  }
            }
                a = bin_12;b = bin_22;c = bin_32;d = bin_42;e = bin_52;f = bin_62;g = bin_72;h = bin_82;
                i = a+b;j = i+c;l = j+d;m = l+e;n = m+f;o = n+g;p = o+h;
                mascara_rede3 = p;/// VALOR DA MASCARA FILTRADA
                printf("\nMASCARA DE REDE:%d|\n\n", p);
        }else
        if(lop1 == 4)
        {
            for(lop=7;lop >= 0 ;lop--)
            {
                /// RESGATA POSICAO DE BITS
                if(lop == 7){  printf("%d|",bin_13);  }
                if(lop == 6){  printf("%d|",bin_23);  }
                if(lop == 5){  printf("%d|",bin_33);  }
                if(lop == 4){  printf("%d|",bin_43);  }
                if(lop == 3){  printf("%d|",bin_53);  }
                if(lop == 2){  printf("%d|",bin_63);  }
                if(lop == 1){  printf("%d|",bin_73);  }
                if(lop == 0){  printf("%d", bin_83);  }
            }
                a = bin_13;b = bin_23;c = bin_33;d = bin_43;e = bin_53;f = bin_63;g = bin_73;h = bin_83;
                i = a+b;j = i+c;l = j+d;m = l+e;n = m+f;o = n+g;p = o+h;
                mascara_rede4 = p;/// VALOR DA MASCARA FILTRADA
                printf("\nMASCARA DE REDE:%d|\n\n", p);
        }

    }

    /// DEFINIÇÃO DE CLASSES DA MASCARA DE REDE
    CLASSES_DE_REDE();
}

/// CLASSES DA MASCARA MANUAL
/// RETORNO DA MASCARA MANUAL
void CLASSES_DE_REDE()
{
    int lop;

    for(lop=0;lop<=4;lop++)
    {
        if(lop == 1)
        {
            if(ret_mascara1 >=   1 && ret_mascara1 <= 127){classe_a1 = 127; classe_a = classe_a1;}else
            if(ret_mascara1 >= 128 && ret_mascara1 <= 191){classe_a2 = 191; classe_a = classe_a2;}else
            if(ret_mascara1 >= 192 && ret_mascara1 <= 233){classe_a3 = 233; classe_a = classe_a3;}else
            if(ret_mascara1 >= 224 && ret_mascara1 <= 239){classe_a4 = 239; classe_a = classe_a4;}else
            if(ret_mascara1 >= 240 && ret_mascara1 <= 255){classe_a5 = 255; classe_a = classe_a5;}
        }else
        if(lop == 2)
        {
            if(ret_mascara2 >=   1 && ret_mascara2 <= 127){classe_b1 = 127; classe_b = classe_b1;}else
            if(ret_mascara2 >= 128 && ret_mascara2 <= 191){classe_b2 = 191; classe_b = classe_b2;}else
            if(ret_mascara2 >= 192 && ret_mascara2 <= 233){classe_b3 = 233; classe_b = classe_b3;}else
            if(ret_mascara2 >= 224 && ret_mascara2 <= 239){classe_b4 = 239; classe_b = classe_b4;}else
            if(ret_mascara2 >= 240 && ret_mascara2 <= 255){classe_b5 = 255; classe_b = classe_b5;}
        }else
        if(lop == 3)
        {
            if(ret_mascara3 >=   1 && ret_mascara3 <= 127){classe_c1 = 127; classe_c = classe_c1;}else
            if(ret_mascara3 >= 128 && ret_mascara3 <= 191){classe_c2 = 191; classe_c = classe_c2;}else
            if(ret_mascara3 >= 192 && ret_mascara3 <= 233){classe_c3 = 233; classe_c = classe_c3;}else
            if(ret_mascara3 >= 224 && ret_mascara3 <= 239){classe_c4 = 239; classe_c = classe_c4;}else
            if(ret_mascara3 >= 240 && ret_mascara3 <= 255){classe_c5 = 255; classe_c = classe_c5;}
        }else
        if(lop == 4)
        {
            if(ret_mascara4 >=   1 && ret_mascara4 <= 127){classe_d1 = 127; classe_d = classe_d1;}else
            if(ret_mascara4 >= 128 && ret_mascara4 <= 191){classe_d2 = 191; classe_d = classe_d2;}else
            if(ret_mascara4 >= 192 && ret_mascara4 <= 233){classe_d3 = 233; classe_d = classe_d3;}else
            if(ret_mascara4 >= 224 && ret_mascara4 <= 239){classe_d4 = 239; classe_d = classe_d4;}else
            if(ret_mascara4 >= 240 && ret_mascara4 <= 255){classe_d5 = 255; classe_d = classe_d5;}
        }

    }

    printf("\n\nCLASSES DE REDE:%d.%d.%d.%d",classe_a,classe_b,classe_c,classe_d);

    /// RETORNO PARA O MENU PRINCIPAL
    main();
}

/// MASCARA DE REDE AUTOMATICA
/// RETORNO DA MASCARA AUTOMATICA
void MASCARA_AUTOMATICA()
{
    int lop;

    for(lop=0;lop<=4;lop++)
    {
        if(lop == 1)
        {
            if(ret_ip1 >=   1 && ret_ip1 <= 127){classe_a1 = 127; classe_a = classe_a1;}else
            if(ret_ip1 >= 128 && ret_ip1 <= 191){classe_a2 = 191; classe_a = classe_a2;}else
            if(ret_ip1 >= 192 && ret_ip1 <= 233){classe_a3 = 233; classe_a = classe_a3;}else
            if(ret_ip1 >= 224 && ret_ip1 <= 239){classe_a4 = 239; classe_a = classe_a4;}else
            if(ret_ip1 >= 240 && ret_ip1 <= 255){classe_a5 = 255; classe_a = classe_a5;}
            /// DEFINICAO DE RETORNO DA MASCARA
            if(ret_ip1 >=   1 && ret_ip1 <= 127){classe_a1 = 127; ret_mascara1 = classe_a1;}else
            if(ret_ip1 >= 128 && ret_ip1 <= 191){classe_a2 = 191; ret_mascara1 = classe_a2;}else
            if(ret_ip1 >= 192 && ret_ip1 <= 233){classe_a3 = 233; ret_mascara1 = classe_a3;}else
            if(ret_ip1 >= 224 && ret_ip1 <= 239){classe_a4 = 239; ret_mascara1 = classe_a4;}else
            if(ret_ip1 >= 240 && ret_ip1 <= 255){classe_a5 = 255; ret_mascara1 = classe_a5;}
        }else
        if(lop == 2)
        {
            if(ret_ip2 >=   1 && ret_ip2 <= 127){classe_b1 = 127; classe_b = classe_b1;}else
            if(ret_ip2 >= 128 && ret_ip2 <= 191){classe_b2 = 191; classe_b = classe_b2;}else
            if(ret_ip2 >= 192 && ret_ip2 <= 233){classe_b3 = 233; classe_b = classe_b3;}else
            if(ret_ip2 >= 224 && ret_ip2 <= 239){classe_b4 = 239; classe_b = classe_b4;}else
            if(ret_ip2 >= 240 && ret_ip2 <= 255){classe_b5 = 255; classe_b = classe_b5;}
            /// DEFINICAO DE RETORNO DA MASCARA
            if(ret_ip2 >=   1 && ret_ip2 <= 127){classe_b1 = 127; ret_mascara2 = classe_b1;}else
            if(ret_ip2 >= 128 && ret_ip2 <= 191){classe_b2 = 191; ret_mascara2 = classe_b2;}else
            if(ret_ip2 >= 192 && ret_ip2 <= 233){classe_b3 = 233; ret_mascara2 = classe_b3;}else
            if(ret_ip2 >= 224 && ret_ip2 <= 239){classe_b4 = 239; ret_mascara2 = classe_b4;}else
            if(ret_ip2 >= 240 && ret_ip2 <= 255){classe_b5 = 255; ret_mascara2 = classe_b5;}
        }else
        if(lop == 3)
        {
            if(ret_ip3 >=   1 && ret_ip3 <= 127){classe_c1 = 127; classe_c = classe_c1;}else
            if(ret_ip3 >= 128 && ret_ip3 <= 191){classe_c2 = 191; classe_c = classe_c2;}else
            if(ret_ip3 >= 192 && ret_ip3 <= 233){classe_c3 = 233; classe_c = classe_c3;}else
            if(ret_ip3 >= 224 && ret_ip3 <= 239){classe_c4 = 239; classe_c = classe_c4;}else
            if(ret_ip3 >= 240 && ret_ip3 <= 255){classe_c5 = 255; classe_c = classe_c5;}
            /// DEFINICAO DE RETORNO DA MASCARA
            if(ret_ip3 >=   1 && ret_ip3 <= 127){classe_c1 = 127; ret_mascara3 = classe_c1;}else
            if(ret_ip3 >= 128 && ret_ip3 <= 191){classe_c2 = 191; ret_mascara3 = classe_c2;}else
            if(ret_ip3 >= 192 && ret_ip3 <= 233){classe_c3 = 233; ret_mascara3 = classe_c3;}else
            if(ret_ip3 >= 224 && ret_ip3 <= 239){classe_c4 = 239; ret_mascara3 = classe_c4;}else
            if(ret_ip3 >= 240 && ret_ip3 <= 255){classe_c5 = 255; ret_mascara3 = classe_c5;}
        }else
        if(lop == 4)
        {
            if(ret_ip4 >=   1 && ret_ip4 <= 127){classe_d1 = 127; classe_d = classe_d1;}else
            if(ret_ip4 >= 128 && ret_ip4 <= 191){classe_d2 = 191; classe_d = classe_d2;}else
            if(ret_ip4 >= 192 && ret_ip4 <= 233){classe_d3 = 233; classe_d = classe_d3;}else
            if(ret_ip4 >= 224 && ret_ip4 <= 239){classe_d4 = 239; classe_d = classe_d4;}else
            if(ret_ip4 >= 240 && ret_ip4 <= 255){classe_d5 = 255; classe_d = classe_d5;}
            /// DEFINICAO DE RETORNO DA MASCARA
            if(ret_ip4 >=   1 && ret_ip4 <= 127){classe_d1 = 127; ret_mascara4 = classe_d1;}else
            if(ret_ip4 >= 128 && ret_ip4 <= 191){classe_d2 = 191; ret_mascara4 = classe_d2;}else
            if(ret_ip4 >= 192 && ret_ip4 <= 233){classe_d3 = 233; ret_mascara4 = classe_d3;}else
            if(ret_ip4 >= 224 && ret_ip4 <= 239){classe_d4 = 239; ret_mascara4 = classe_d4;}else
            if(ret_ip4 >= 240 && ret_ip4 <= 255){classe_d5 = 255; ret_mascara4 = classe_d5;}
        }

    }

    printf("\n\nCLASSES DE REDE:%d.%d.%d.%d",classe_a,classe_b,classe_c,classe_d);

    /// CONFIGURAÇÃO DE BINARIOS AUTOMATICA
    MASCARA_BINARIOS_AUTOMATICA();
}

/// FILTRO DA MASCARA DE REDE
/// RETORNO DE BINARIOS
void MASCARA_BINARIOS_AUTOMATICA()
{
    printf("\nCONFIGURACAO MASCARA!\n");

    //system("cls");
    printf("\nip2:%d.%d.%d.%d\n",ret_mascara1,ret_mascara2,ret_mascara3,ret_mascara4); /// para validar os numeros salvos!
    system("pause");

    int masc;
    int n2;
    int b10,b20,b30,b40,b50,b60,b70,b80;
    int b11,b21,b31,b41,b51,b61,b71,b81;
    int b12,b22,b32,b42,b52,b62,b72,b82;
    int b13,b23,b33,b43,b53,b63,b73,b83;
    int lop;
    int *dados;
    /// ALOCAMENTO DE MEMORIA
    dados = malloc(lop * sizeof(int *));
    dados = malloc(n2 * sizeof(int *));

    /// OCTETO DE CHAMADA 1
    bin_10 = malloc(b10 * sizeof(int *)); /// bin_1[B] = malloc(b1 * sizeof(int *));
    bin_20 = malloc(b20 * sizeof(int *));
    bin_30 = malloc(b30 * sizeof(int *));
    bin_40 = malloc(b40 * sizeof(int *));
    bin_50 = malloc(b50 * sizeof(int *));
    bin_60 = malloc(b60 * sizeof(int *));
    bin_70 = malloc(b70 * sizeof(int *));
    bin_80 = malloc(b80 * sizeof(int *));

    /// OCTETO DE CHAMADA 2
    bin_11 = malloc(b11 * sizeof(int *)); /// bin_1[B] = malloc(b1 * sizeof(int *));
    bin_21 = malloc(b21 * sizeof(int *));
    bin_31 = malloc(b31 * sizeof(int *));
    bin_41 = malloc(b41 * sizeof(int *));
    bin_51 = malloc(b51 * sizeof(int *));
    bin_61 = malloc(b61 * sizeof(int *));
    bin_71 = malloc(b71 * sizeof(int *));
    bin_81 = malloc(b81 * sizeof(int *));

    /// OCTETO DE CHAMADA 3
    bin_12 = malloc(b12 * sizeof(int *)); /// bin_1[B] = malloc(b1 * sizeof(int *));
    bin_22 = malloc(b22 * sizeof(int *));
    bin_32 = malloc(b32 * sizeof(int *));
    bin_42 = malloc(b42 * sizeof(int *));
    bin_52 = malloc(b52 * sizeof(int *));
    bin_62 = malloc(b62 * sizeof(int *));
    bin_72 = malloc(b72 * sizeof(int *));
    bin_82 = malloc(b82 * sizeof(int *));

    /// OCTETO DE CHAMADA 4
    bin_13 = malloc(b13 * sizeof(int *)); /// bin_1[B] = malloc(b1 * sizeof(int *));
    bin_23 = malloc(b23 * sizeof(int *));
    bin_33 = malloc(b33 * sizeof(int *));
    bin_43 = malloc(b43 * sizeof(int *));
    bin_53 = malloc(b53 * sizeof(int *));
    bin_63 = malloc(b63 * sizeof(int *));
    bin_73 = malloc(b73 * sizeof(int *));
    bin_83 = malloc(b83 * sizeof(int *));

    printf("\n\n");

    ///CALCULO PARA OBTER A SEQUENCIA CORRETA DAS POSIÇÕES DE BITS DE ENVIO DA MASCARA
    for(cont_mas=0; cont_mas<=5; cont_mas++)
        {
            if(cont_mas = 1)
            {
                    masc = ret_mascara1; // BUSCA NA BIBLIOTECA O NUMERO DIGITADO
                    for(lop=0;masc >= 1 ;lop++)
                    {
                        if(lop == 0)
                        {

                        } else
                        {
                            masc = masc / 2;
                            printf("Mas %d", masc);
                            if(masc%2 == 0){printf("    Bin 0\n"); n2 = 0; dados[lop] = n2;}
                            else{printf("    Bin 1\n"); n2 = 1; dados[lop] = n2;}
                        }
                    }
                    printf("%d\n", lop);// QUANTIDADE DE BITS
                    quant_0 = lop;/// DEFINE DE OS VALORES DOS BINARIOS 8

                    ///IMPRIMIR A ORDEM CORRETA DE BINARIOS PARA CONTAGEM E VALIDAÇÃO
                    for(lop=7;lop >= 0 ;lop--)
                    {
                        printf("%d", dados[lop]);
                            if(lop == 7){  if(dados[lop] == 1){bin_10 = 128;}else{bin_10 = 0;}  }
                            if(lop == 6){  if(dados[lop] == 1){bin_20 = 64;} else{bin_20 = 0;}  }
                            if(lop == 5){  if(dados[lop] == 1){bin_30 = 32;} else{bin_30 = 0;}  }
                            if(lop == 4){  if(dados[lop] == 1){bin_40 = 16;} else{bin_40 = 0;}  }
                            if(lop == 3){  if(dados[lop] == 1){bin_50 =  8;} else{bin_50 = 0;}  }
                            if(lop == 2){  if(dados[lop] == 1){bin_60 =  4;} else{bin_60 = 0;}  }
                            if(lop == 1){  if(dados[lop] == 1){bin_70 =  2;} else{bin_70 = 0;}  }
                            if(lop == 0){  if(dados[lop] == 1){bin_80 =  1;} else{bin_80 = 0;}  }
                    }

                    printf("\n\n");
            }
            if(cont_mas = 1)
            {
                masc = ret_mascara2; // BUSCA NA BIBLIOTECA O NUMERO DIGITADO
                for(lop=0;masc >= 1 ;lop++)
                    {
                        if(lop == 0)
                        {

                        } else
                        {
                            masc = masc / 2;
                            printf("Mas %d", masc);
                            if(masc%2 == 0){printf("    Bin 0\n"); n2 = 0; dados[lop] = n2;}
                            else{printf("    Bin 1\n"); n2 = 1; dados[lop] = n2;}
                        }
                    }
                    printf("%d\n", lop);// QUANTIDADE DE BITS
                    quant_1 = lop;/// DEFINE DE OS VALORES DOS BINARIOS 8

                    ///IMPRIMIR A ORDEM CORRETA DE BINARIOS PARA CONTAGEM E VALIDAÇÃO
                    for(lop=7;lop >= 0 ;lop--)
                    {
                        printf("%d", dados[lop]);
                            if(lop == 7){  if(dados[lop] == 1){bin_11 = 128;}else{bin_11 = 0;}  }
                            if(lop == 6){  if(dados[lop] == 1){bin_21 = 64;} else{bin_21 = 0;}  }
                            if(lop == 5){  if(dados[lop] == 1){bin_31 = 32;} else{bin_31 = 0;}  }
                            if(lop == 4){  if(dados[lop] == 1){bin_41 = 16;} else{bin_41 = 0;}  }
                            if(lop == 3){  if(dados[lop] == 1){bin_51 =  8;} else{bin_51 = 0;}  }
                            if(lop == 2){  if(dados[lop] == 1){bin_61 =  4;} else{bin_61 = 0;}  }
                            if(lop == 1){  if(dados[lop] == 1){bin_71 =  2;} else{bin_71 = 0;}  }
                            if(lop == 0){  if(dados[lop] == 1){bin_81 =  1;} else{bin_81 = 0;}  }
                    }
                    printf("\n\n");
            }
            if(cont_mas = 2)
            {
                    masc = ret_mascara3; // BUSCA NA BIBLIOTECA O NUMERO DIGITADO
                    for(lop=0;masc >= 1 ;lop++)
                    {
                        if(lop == 0)
                        {

                        } else
                        {
                            masc = masc / 2;
                            printf("Mas %d", masc);
                            if(masc%2 == 0){printf("    Bin 0\n"); n2 = 0; dados[lop] = n2;}
                            else{printf("    Bin 1\n"); n2 = 1; dados[lop] = n2;}
                        }
                    }
                    printf("%d\n", lop);// QUANTIDADE DE BITS
                    quant_2 = lop;/// DEFINE DE OS VALORES DOS BINARIOS 8

                    ///IMPRIMIR A ORDEM CORRETA DE BINARIOS PARA CONTAGEM E VALIDAÇÃO
                    for(lop=7;lop >= 0 ;lop--)
                    {
                        printf("%d", dados[lop]);
                            if(lop == 7){  if(dados[lop] == 1){bin_12 = 128;}else{bin_12 = 0;}  }
                            if(lop == 6){  if(dados[lop] == 1){bin_22 = 64;} else{bin_22 = 0;}  }
                            if(lop == 5){  if(dados[lop] == 1){bin_32 = 32;} else{bin_32 = 0;}  }
                            if(lop == 4){  if(dados[lop] == 1){bin_42 = 16;} else{bin_42 = 0;}  }
                            if(lop == 3){  if(dados[lop] == 1){bin_52 =  8;} else{bin_52 = 0;}  }
                            if(lop == 2){  if(dados[lop] == 1){bin_62 =  4;} else{bin_62 = 0;}  }
                            if(lop == 1){  if(dados[lop] == 1){bin_72 =  2;} else{bin_72 = 0;}  }
                            if(lop == 0){  if(dados[lop] == 1){bin_82 =  1;} else{bin_82 = 0;}  }
                    }
                    printf("\n\n");
            }
            if(cont_mas = 3)
            {
                    masc = ret_mascara4; // BUSCA NA BIBLIOTECA O NUMERO DIGITADO
                    for(lop=0;masc >= 1 ;lop++)
                    {
                        if(lop == 0)
                        {

                        } else
                        {
                            masc = masc / 2;
                            printf("Mas %d", masc);
                            if(masc%2 == 0){printf("    Bin 0\n"); n2 = 0; dados[lop] = n2;}
                            else{printf("    Bin 1\n"); n2 = 1; dados[lop] = n2;}
                        }
                    }
                    printf("%d\n", lop);// QUANTIDADE DE BITS
                    quant_3 = lop;/// DEFINE DE OS VALORES DOS BINARIOS 8

                    ///IMPRIMIR A ORDEM CORRETA DE BINARIOS PARA CONTAGEM E VALIDAÇÃO
                    for(lop=7;lop >= 0 ;lop--)
                    {
                        printf("%d", dados[lop]);
                            if(lop == 7){  if(dados[lop] == 1){bin_13 = 128;}else{bin_13 = 0;}  }
                            if(lop == 6){  if(dados[lop] == 1){bin_23 = 64;} else{bin_23 = 0;}  }
                            if(lop == 5){  if(dados[lop] == 1){bin_33 = 32;} else{bin_33 = 0;}  }
                            if(lop == 4){  if(dados[lop] == 1){bin_43 = 16;} else{bin_43 = 0;}  }
                            if(lop == 3){  if(dados[lop] == 1){bin_53 =  8;} else{bin_53 = 0;}  }
                            if(lop == 2){  if(dados[lop] == 1){bin_63 =  4;} else{bin_63 = 0;}  }
                            if(lop == 1){  if(dados[lop] == 1){bin_73 =  2;} else{bin_73 = 0;}  }
                            if(lop == 0){  if(dados[lop] == 1){bin_83 =  1;} else{bin_83 = 0;}  }
                    }
                    printf("\n\n");
            }
        }

        if(cont_mas = 5)
        {
            printf("FIM DA CONTAGEM MASCARA!");
        }

        /// RETORNO PARA O MENU PRINCIPAL
        main();
}

/**
BINARIO MASCARA = 8 & NUMERO DIGITADO MAIOR QUE OU IGUAL A 128 & BIN_10 == 0 ENTÃO CASE PARA CORREÇÃO
BINARIO MASCARA = 1 & NUMERO DIGIRADO MENOR QUE OU IGUAL A  11 & BIN_70 == 0 ENTÃO CASE PARA CORRECAO
EXEMPLO:
LOP(LOP=7;LOP >=0; LOP--)
{
    IF(LOP == 0)
    {
        MASCARA / 2 = IMPA
        SE FOR == 0
        SALVA = 1
        ELSE
        SALVA = 0
    }ELSE
    IF(SLVA = 0 && CALVA >= 128)
    {
        CASE '1':
        SAVAS = 1;
        BREAK;
    }

}
*/

/*
#include <stdio.h>
#include <stdlib.h>

#include "MASCARA_PROJETO_TESTE1.h"
#include "IP_PROJETO_TESTE1.h"

void MASCARA()
{
    printf("\nCONFIGURACAO MASCARA!\n");
    printf("\n%d\n", MASC);

    ///calculo_mascara()
    //system("cls");
    printf("\nip2:%d.%d.%d.%d\n",ret_ip1,ret_ip2,ret_ip3,ret_ip4); /// para validar os numeros salvos!
    system("pause");

    int masc;
    int n2;
    int b10,b20,b30,b40,b50,b60,b70,b80;
    int b11,b21,b31,b41,b51,b61,b71,b81;
    int b12,b22,b32,b42,b52,b62,b72,b82;
    int b13,b23,b33,b43,b53,b63,b73,b83;
    int lop;
    int *dados;
    /// ALOCAMENTO DE MEMORIA
    dados = malloc(lop * sizeof(int *));
    dados = malloc(n2 * sizeof(int *));

    /// OCTETO DE CHAMADA 1
    bin_10 = malloc(b10 * sizeof(int *)); /// bin_1[B] = malloc(b1 * sizeof(int *));
    bin_20 = malloc(b20 * sizeof(int *));
    bin_30 = malloc(b30 * sizeof(int *));
    bin_40 = malloc(b40 * sizeof(int *));
    bin_50 = malloc(b50 * sizeof(int *));
    bin_60 = malloc(b60 * sizeof(int *));
    bin_70 = malloc(b70 * sizeof(int *));
    bin_80 = malloc(b80 * sizeof(int *));

    /// OCTETO DE CHAMADA 2
    bin_11 = malloc(b11 * sizeof(int *)); /// bin_1[B] = malloc(b1 * sizeof(int *));
    bin_21 = malloc(b21 * sizeof(int *));
    bin_31 = malloc(b31 * sizeof(int *));
    bin_41 = malloc(b41 * sizeof(int *));
    bin_51 = malloc(b51 * sizeof(int *));
    bin_61 = malloc(b61 * sizeof(int *));
    bin_71 = malloc(b71 * sizeof(int *));
    bin_81 = malloc(b81 * sizeof(int *));

    /// OCTETO DE CHAMADA 3
    bin_12 = malloc(b12 * sizeof(int *)); /// bin_1[B] = malloc(b1 * sizeof(int *));
    bin_22 = malloc(b22 * sizeof(int *));
    bin_32 = malloc(b32 * sizeof(int *));
    bin_42 = malloc(b42 * sizeof(int *));
    bin_52 = malloc(b52 * sizeof(int *));
    bin_62 = malloc(b62 * sizeof(int *));
    bin_72 = malloc(b72 * sizeof(int *));
    bin_82 = malloc(b82 * sizeof(int *));

    /// OCTETO DE CHAMADA 4
    bin_13 = malloc(b13 * sizeof(int *)); /// bin_1[B] = malloc(b1 * sizeof(int *));
    bin_23 = malloc(b23 * sizeof(int *));
    bin_33 = malloc(b33 * sizeof(int *));
    bin_43 = malloc(b43 * sizeof(int *));
    bin_53 = malloc(b53 * sizeof(int *));
    bin_63 = malloc(b63 * sizeof(int *));
    bin_73 = malloc(b73 * sizeof(int *));
    bin_83 = malloc(b83 * sizeof(int *));

    printf("\n\n");

    ///CALCULO PARA OBTER A SEQUENCIA CORRETA DAS POSIÇÕES DE BITS DE ENVIO DA MASCARA
    for(cont_mas=0; cont_mas<=5; cont_mas++)
        {
            if(cont_mas = 1)
            {
                    masc = ret_ip1;
                    for(lop=0;masc >= 1 ;lop++)
                    {
                        if(lop == 0)
                        {
                            printf("Mas %d", masc);
                            if(masc%2 == 0){printf("    Bin 0\n"); n2 = 0; dados[lop] = n2;}
                            else{printf("    Bin 1\n"); n2 = 1; dados[lop] = n2;}
                            masc = masc / 2;

                        } else
                        {
                            masc = masc / 2;
                            printf("Mas %d", masc);
                            if(masc%2 == 0){printf("    Bin 0\n"); n2 = 0; dados[lop] = n2;}
                            else{printf("    Bin 1\n"); n2 = 1; dados[lop] = n2;}
                        }
                    }
                    printf("%d\n", lop);
                    for(lop=7;lop >= 0 ;lop--)
                    {

                            if(lop == 7){  if(dados[lop] == 1){bin_10 = 128;}else{bin_10 = 0;}  }
                            if(lop == 6){  if(dados[lop] == 1){bin_20 = 64;} else{bin_20 = 0;}  }
                            if(lop == 5){  if(dados[lop] == 1){bin_30 = 32;} else{bin_30 = 0;}  }
                            if(lop == 4){  if(dados[lop] == 1){bin_40 = 16;} else{bin_40 = 0;}  }
                            if(lop == 3){  if(dados[lop] == 1){bin_50 =  8;} else{bin_50 = 0;}  }
                            if(lop == 2){  if(dados[lop] == 1){bin_60 =  4;} else{bin_60 = 0;}  }
                            if(lop == 1){  if(dados[lop] == 1){bin_70 =  2;} else{bin_70 = 0;}  }
                            if(lop == 0){  if(dados[lop] == 1){bin_80 =  1;} else{bin_80 = 0;}  }
                            printf("%d\n", dados[lop]);
                    }
            }
            if(cont_mas = 1)
            {
                masc = ret_ip2;
                for(lop=0;masc >= 1 ;lop++)
                    {
                        if(lop == 0)
                        {
                            printf("Mas %d", masc);
                            if(masc%2 == 0){printf("    Bin 0\n"); n2 = 0; dados[lop] = n2;}
                            else{printf("    Bin 1\n"); n2 = 1; dados[lop] = n2;}
                            masc = masc / 2;

                        } else
                        {
                            masc = masc / 2;
                            printf("Mas %d", masc);
                            if(masc%2 == 0){printf("    Bin 0\n"); n2 = 0; dados[lop] = n2;}
                            else{printf("    Bin 1\n"); n2 = 1; dados[lop] = n2;}
                        }
                    }
                    printf("%d\n", lop);
                    for(lop=7;lop >= 0 ;lop--)
                    {

                            if(lop == 7){  if(dados[lop] == 1){bin_11 = 128;}else{bin_11 = 0;}  }
                            if(lop == 6){  if(dados[lop] == 1){bin_21 = 64;} else{bin_21 = 0;}  }
                            if(lop == 5){  if(dados[lop] == 1){bin_31 = 32;} else{bin_31 = 0;}  }
                            if(lop == 4){  if(dados[lop] == 1){bin_41 = 16;} else{bin_41 = 0;}  }
                            if(lop == 3){  if(dados[lop] == 1){bin_51 =  8;} else{bin_51 = 0;}  }
                            if(lop == 2){  if(dados[lop] == 1){bin_61 =  4;} else{bin_61 = 0;}  }
                            if(lop == 1){  if(dados[lop] == 1){bin_71 =  2;} else{bin_71 = 0;}  }
                            if(lop == 0){  if(dados[lop] == 1){bin_81 =  1;} else{bin_81 = 0;}  }
                            printf("%d\n", dados[lop]);
                    }
            }
            if(cont_mas = 2)
            {
                    masc = ret_ip3;
                    for(lop=0;masc >= 1 ;lop++)
                    {
                        if(lop == 0)
                        {
                            printf("Mas %d", masc);
                            if(masc%2 == 0){printf("    Bin 0\n"); n2 = 0; dados[lop] = n2;}
                            else{printf("    Bin 1\n"); n2 = 1; dados[lop] = n2;}
                            masc = masc / 2;

                        } else
                        {
                            masc = masc / 2;
                            printf("Mas %d", masc);
                            if(masc%2 == 0){printf("    Bin 0\n"); n2 = 0; dados[lop] = n2;}
                            else{printf("    Bin 1\n"); n2 = 1; dados[lop] = n2;}
                        }
                    }
                    printf("%d\n", lop);
                    for(lop=7;lop >= 0 ;lop--)
                    {

                            if(lop == 7){  if(dados[lop] == 1){bin_12 = 128;}else{bin_12 = 0;}  }
                            if(lop == 6){  if(dados[lop] == 1){bin_22 = 64;} else{bin_22 = 0;}  }
                            if(lop == 5){  if(dados[lop] == 1){bin_32 = 32;} else{bin_32 = 0;}  }
                            if(lop == 4){  if(dados[lop] == 1){bin_42 = 16;} else{bin_42 = 0;}  }
                            if(lop == 3){  if(dados[lop] == 1){bin_52 =  8;} else{bin_52 = 0;}  }
                            if(lop == 2){  if(dados[lop] == 1){bin_62 =  4;} else{bin_62 = 0;}  }
                            if(lop == 1){  if(dados[lop] == 1){bin_72 =  2;} else{bin_72 = 0;}  }
                            if(lop == 0){  if(dados[lop] == 1){bin_82 =  1;} else{bin_82 = 0;}  }
                            printf("%d\n", dados[lop]);
                    }
            }
            if(cont_mas = 3)
            {
                    masc = ret_ip4;
                    for(lop=0;masc >= 1 ;lop++)
                    {
                        if(lop == 0)
                        {
                            printf("Mas %d", masc);
                            if(masc%2 == 0){printf("    Bin 0\n"); n2 = 0; dados[lop] = n2;}
                            else{printf("    Bin 1\n"); n2 = 1; dados[lop] = n2;}
                            masc = masc / 2;
                        } else
                        {
                            masc = masc / 2;
                            printf("Mas %d", masc);
                            if(masc%2 == 0){printf("    Bin 0\n"); n2 = 0; dados[lop] = n2;}
                            else{printf("    Bin 1\n"); n2 = 1; dados[lop] = n2;}
                        }
                    }
                    printf("%d\n", lop);
                    for(lop=7;lop >= 0 ;lop--)
                    {

                            if(lop == 7){  if(dados[lop] == 1){bin_13 = 128;}else{bin_13 = 0;}  }
                            if(lop == 6){  if(dados[lop] == 1){bin_23 = 64;} else{bin_23 = 0;}  }
                            if(lop == 5){  if(dados[lop] == 1){bin_33 = 32;} else{bin_33 = 0;}  }
                            if(lop == 4){  if(dados[lop] == 1){bin_43 = 16;} else{bin_43 = 0;}  }
                            if(lop == 3){  if(dados[lop] == 1){bin_53 =  8;} else{bin_53 = 0;}  }
                            if(lop == 2){  if(dados[lop] == 1){bin_63 =  4;} else{bin_63 = 0;}  }
                            if(lop == 1){  if(dados[lop] == 1){bin_73 =  2;} else{bin_73 = 0;}  }
                            if(lop == 0){  if(dados[lop] == 1){bin_83 =  1;} else{bin_83 = 0;}  }
                            printf("%d\n", dados[lop]);
                    }
            }
        }

        ///IMPRIMIR A ORDEM CORRETA DE BINARIOS PARA CONTAGEM E VALIDAÇÃO
        for(lop=7;lop >= 0 ;lop--)
        {
            printf("Binarios:%d\n", dados[lop]);
        }
        printf("\n");

        if(cont_mas = 5)
        {
            printf("FIM DA CONTAGEM MASCARA!");
        }


}

*/

/**
///CONTADOR DE MASCARA REVERSO CONSOLIDADOS DE CALCULO BINARIO EM BITS
        // OCTETO DE ENTRADA 1
        for(contador = 1; contador <= 4; contador++)
        {
            if(contador == 1)
            {
                for(lop=7;lop >= 0 ;lop--)
                {

                        if(lop == 7){  if(dados[lop] == 1){bin_10 = 128;}else{bin_10 = 0;}  }
                        if(lop == 6){  if(dados[lop] == 1){bin_20 = 64;} else{bin_20 = 0;}  }
                        if(lop == 5){  if(dados[lop] == 1){bin_30 = 32;} else{bin_30 = 0;}  }
                        if(lop == 4){  if(dados[lop] == 1){bin_40 = 16;} else{bin_40 = 0;}  }
                        if(lop == 3){  if(dados[lop] == 1){bin_50 =  8;} else{bin_50 = 0;}  }
                        if(lop == 2){  if(dados[lop] == 1){bin_60 =  4;} else{bin_60 = 0;}  }
                        if(lop == 1){  if(dados[lop] == 1){bin_70 =  2;} else{bin_70 = 0;}  }
                        if(lop == 0){  if(dados[lop] == 1){bin_80 =  1;} else{bin_80 = 0;}  }
                        printf("%d", dados[lop]);
                }
                //printf("\n\n%d%d%d%d%d%d%d%d\n\n",bin_10,bin_20,bin_30,bin_40,bin_50,bin_60,bin_70,bin_80);
            }else
            if(contador == 2)
            {
                for(lop=7;lop >= 0 ;lop--)
                {

                        if(lop == 7){  if(dados[lop] == 1){bin_11 = 128;}else{bin_11 = 0;}  }
                        if(lop == 6){  if(dados[lop] == 1){bin_21 = 64;} else{bin_21 = 0;}  }
                        if(lop == 5){  if(dados[lop] == 1){bin_31 = 32;} else{bin_31 = 0;}  }
                        if(lop == 4){  if(dados[lop] == 1){bin_41 = 16;} else{bin_41 = 0;}  }
                        if(lop == 3){  if(dados[lop] == 1){bin_51 =  8;} else{bin_51 = 0;}  }
                        if(lop == 2){  if(dados[lop] == 1){bin_61 =  4;} else{bin_61 = 0;}  }
                        if(lop == 1){  if(dados[lop] == 1){bin_71 =  2;} else{bin_71 = 0;}  }
                        if(lop == 0){  if(dados[lop] == 1){bin_81 =  1;} else{bin_81 = 0;}  }
                        printf("%d", dados[lop]);
                }
                //printf("\n\n%d%d%d%d%d%d%d%d\n\n",bin_11,bin_21,bin_31,bin_41,bin_51,bin_61,bin_71,bin_81);
            }else
            if(contador == 3)
            {
                for(lop=7;lop >= 0 ;lop--)
                {

                        if(lop == 7){  if(dados[lop] == 1){bin_12 = 128;}else{bin_12 = 0;}  }
                        if(lop == 6){  if(dados[lop] == 1){bin_22 = 64;} else{bin_22 = 0;}  }
                        if(lop == 5){  if(dados[lop] == 1){bin_32 = 32;} else{bin_32 = 0;}  }
                        if(lop == 4){  if(dados[lop] == 1){bin_42 = 16;} else{bin_42 = 0;}  }
                        if(lop == 3){  if(dados[lop] == 1){bin_52 =  8;} else{bin_52 = 0;}  }
                        if(lop == 2){  if(dados[lop] == 1){bin_62 =  4;} else{bin_62 = 0;}  }
                        if(lop == 1){  if(dados[lop] == 1){bin_72 =  2;} else{bin_72 = 0;}  }
                        if(lop == 0){  if(dados[lop] == 1){bin_82 =  1;} else{bin_82 = 0;}  }
                        printf("%d", dados[lop]);
                }
                //printf("\n\n%d%d%d%d%d%d%d%d\n\n",bin_12,bin_22,bin_32,bin_42,bin_52,bin_62,bin_72,bin_82);
            }else
            if(contador == 4)
            {
                for(lop=7;lop >= 0 ;lop--)
                {

                        if(lop == 7){  if(dados[lop] == 1){bin_13 = 128;}else{bin_13 = 0;}  }
                        if(lop == 6){  if(dados[lop] == 1){bin_23 = 64;} else{bin_23 = 0;}  }
                        if(lop == 5){  if(dados[lop] == 1){bin_33 = 32;} else{bin_33 = 0;}  }
                        if(lop == 4){  if(dados[lop] == 1){bin_43 = 16;} else{bin_43 = 0;}  }
                        if(lop == 3){  if(dados[lop] == 1){bin_53 =  8;} else{bin_53 = 0;}  }
                        if(lop == 2){  if(dados[lop] == 1){bin_63 =  4;} else{bin_63 = 0;}  }
                        if(lop == 1){  if(dados[lop] == 1){bin_73 =  2;} else{bin_73 = 0;}  }
                        if(lop == 0){  if(dados[lop] == 1){bin_83 =  1;} else{bin_83 = 0;}  }
                        printf("%d", dados[lop]);
                }
                //printf("\n\n%d%d%d%d%d%d%d%d\n\n",bin_13,bin_23,bin_33,bin_43,bin_53,bin_63,bin_73,bin_83);
            }

        }
        printf("\n%d%d%d%d%d%d%d%d\n",bin_10,bin_20,bin_30,bin_40,bin_50,bin_60,bin_70,bin_80);
        printf("\n%d%d%d%d%d%d%d%d\n",bin_11,bin_21,bin_31,bin_41,bin_51,bin_61,bin_71,bin_81);
        printf("\n%d%d%d%d%d%d%d%d\n",bin_12,bin_22,bin_32,bin_42,bin_52,bin_62,bin_72,bin_82);
        printf("\n%d%d%d%d%d%d%d%d\n",bin_13,bin_23,bin_33,bin_43,bin_53,bin_63,bin_73,bin_83);
*/
