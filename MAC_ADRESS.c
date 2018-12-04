#include <stdio.h>
#include <stdlib.h>

#include "MAC_PROJETO_TESTE1.h"

void MAC_ADRESS(void)
{
    printf("\nCONFIGURACAO MAC!\n");
    printf("DIGITE UM NUMERO:");
    scanf("%d", &mac_retorno);
    printf("\nMAC:%d", mac_retorno);
    printf("\n");
    system("pause");
    system("cls");
    main();
}
