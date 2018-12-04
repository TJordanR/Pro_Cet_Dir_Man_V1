#include <stdio.h>
#include <stdlib.h>
#include "IP_PROJETO_TESTE1.h"
#include "MASCARA_PROJETO_TESTE1.h"
#include "MAC_PROJETO_TESTE1.h"
#include "GETWAY_PROJETO_TESTE1.h"


void CONFIGURACAO()
{
    printf("\n-----------------------------------------------\n");
    printf("CONFIGURACAO NETWORKS!\n");
    printf("IP DEFINIDO:%d.%d.%d.%d\n",ret_ip1,ret_ip2,ret_ip3,ret_ip4);
    printf("MASCARA DEFINIDA:%d.%d.%d.%d\n",ret_mascara1,ret_mascara2,ret_mascara3,ret_mascara4);
    printf("MASCARA FILTRADA:%d.%d.%d.%d\n",mascara_rede1,mascara_rede2,mascara_rede3,mascara_rede4);
    printf("MAC ADRESS:%d:%d:%d:%d:%d:%d\n",mac1,mac2,mac3,mac4,mac5,mac6);
    printf("DNS:%d.%d.%d.%d\n",get1,get2,get3,get4);
    printf("GETWAY:%d.%d.%d.%d\n",get1,get2,get3,get4);
    printf("\n-----------------------------------------------\n");

    main();
}
