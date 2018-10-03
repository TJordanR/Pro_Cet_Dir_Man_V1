/*
** OBJETIVO: INDENTIFICAR OS NUMERO DE IP DIGITADOS
** # PEGAR NUMERICO DE IP DIGITADOS OU ACESSADOS POR REDE OU ATRAVES DO USUARIO
** # E SALVALOS DE MODO QUE FIQUE UM HISTORICO EDITAVEL E LIMPO DOS IPs
** # COM BASE EM ACESSO INTENO NA REDE OU ATRAVES DE SITES COM IPs DE FORA DA FAIXA DE REDE INTERNA
** # COM UM MENUR ACESSIVEL E GERAÇÃO DE ARQUIVO DE EXPORTAÇÃO OU IMPORTAÇÃO DO MESMO
** O QUE FALTA?
** # LER O IP QUE FOI DIGITADO                                      OK
** # SALVAR EM ARQUIVO PARA LEITURA                                 OK
** # ISOLAR OS NUMERICOS                                            FALTA
** # SALVAR NA MEMORIA E NO BUFF DO SISTEMA                         FALTA
** # MANIPULAR NA MEMORIA E NO BOFF PARA USO E SALVAR EM ARQUIVO    FALTA
** # ACRECENTAR A MASCARA E FAZER A CONVERSAO PARA BINARIO          FALTA
** # ACRECENTAR O GETWAE DE BUSCA                                   FALTA
** # DEFINIR O SE É DHCP COM IP AUTOMATICO OU ESTATICO              FALTA
** ESCRITO: POR TIAGO JORDAN R
** VERSAO:
** DATA:
*/
///===============================================================================================================///
#include <stdio.h>
#include <stdlib.h>
#include "IP_PROJETO_TESTE1.h"
#include "IP_PROTOCOLO_TESTE.h"
/*
 TCP (Transmission Control Protocol - Protocolo de Controle de Transmissão)
 IP (Internet Protocol - Protocolo de Internet, ou ainda, protocolo de interconexão).
*/
void ip_inicial()
{
    char c[100000];
    char url[] = "C:\\CONVERTE_IP\\CONVERTE_IP.IP";
    FILE *  ARQUIVO;
    ARQUIVO = fopen(url, "w");

    printf("DIGITE UM NUMERO DE IP! \n");
    gets(c);
    ///fprintf(ARQUIVO,"%s", c);
    ///printf("\nIP SALVO!");
    configura();

}
///===============================================================================================================///
void configura()
{
    int retorno;
    int config;
    int mas;
    int por;
    retorno = IP_RETORNO;
    config = IP_CONFIG;
    if(retorno = 100)
    {
        printf("\nO VALOR DE RETORNO E 100\n");
        printf("DIGITE A MASCARA DE REDE! \n");
        scanf("%d", &mas);
        ip_mas = mas;

    }else
    printf("ERRO NO VALOR DE RETONO! \n");
    if(config = 100)
    {
        printf("A CONFIGURACAO DO IP E 100\n");
        printf("DIGITE A PORTA DE ENTRADA! \n");
        scanf("%d", &por);
        ip_por = por;

    }else
    printf("ERRO NA CONFIGURACAO!\n");

    puxa_configuracao();

}
///===============================================================================================================///
void puxa_configuracao()
{

    printf("=======================================\n\n");
    printf("configuracao mascara: %d\n", ip_mas);
    printf("configuracao porta:   %d\n", ip_por);
    printf("=======================================\n\n");
    protocolos();
}
void protocolos()
{

    char escolha;
    printf("ESCOLHA O PROTUCOLA DE REDE! \n");
    printf("TCP = 1, UDP = 2, FTP = 3 \n");
    ///scanf("%d", &escolha);

    escolha = getch();
    switch (escolha)
    {
    case '1':
        pt_tcp = 1;
        pt_udp == 0; pt_ftp == 0;
        ///chamada_teste_v1();
        ///direcionamento_rede();
        break;
    case '2':
        pt_udp = 1;
        pt_tcp == 0; pt_ftp == 0;
        direcionamento_rede();
        break;
    case '3':
        pt_ftp = 1;
        pt_tcp == 0; pt_udp == 0;
        direcionamento_rede();
        break;
    default:
        break;
    }

}
///===============================================================================================================///
void direcionamento_rede()
{
    int tam_max_tcp = 10000;
    int tam_max_udp = 1000;
    int tam_max_ftp = 100;

    printf("protocolo escolhido foi");
    if(pt_tcp > 0)
    {
        printf(" TCP \n");
        pro_tam = tam_max_tcp;
    }else
    if(pt_udp > 0)
    {
        printf(" UDP \n");
        pro_tam = tam_max_udp;
    }else
    if(pt_ftp > 0)
    {
        printf(" FTP \n");
        pro_tam = tam_max_ftp;
    }
    tamanho_pacote_protocolo();
}
///===============================================================================================================///
void tamanho_pacote_protocolo()
{
    int busca_dhcp;
    printf("TAMANHO MAXIMO DO PACOTE DE ENTRADA: %d \n\n", pro_tam);
    printf("BUSCAR O IP AUTOMATICAMENTO DIGITE 1 SE NAO DIGITE QUALQUER NUMERO!\n");
    scanf("%d", &busca_dhcp);
    if(busca_dhcp == 1)
    {
        define_ip_dhcp();
    }else
    printf("CONTINUAR PROGRAMANDO! \n");
}
///===============================================================================================================///
void define_ip_dhcp()
{
    int dhcp;
    int *busca;
    int ip_automatico;
    int lop;

    printf("BUSCA AUTOMATICA DE IP FAVOR AGUARDE A BUSCA! \n");
    busca = malloc(lop * sizeof(int *));

    for(lop=1;lop<=255;lop++)
    {
        busca[lop] = lop;
    }
    for(lop=0;lop<=255;lop++)
    {

        printf("BUSCA DE IP 192.168.0.");
        printf("%d\n", busca[lop]);

    }
    ///chamada_teste_v1();
    system("pause");

}
///===============================================================================================================///





int main()
{
    //ip_inicial();
    chamada_teste_v();
    //configura_ip();
    //menu_networks();
    return 0;
}












/*
void ler_ip()
{
    int a=0;
    char c[1000000];
    FILE * ARQUIVO;
    ARQUIVO = fopen("C:\\CONVERTE_IP\\CONVERTE_IP.IP", "r");
    for(a=0;a<=100;a++)
    {
        fprintf(ARQUIVO,"%s",c);
    }

}
*/
