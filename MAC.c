#include <stdio.h>
#include <stdlib.h>

#include "MAC_PROJETO_TESTE1.h"

void MAC()
{
    int mac;
    system("cls");
    printf("\nCONFIGURACAO MAC!\n");
    printf("\nDIGITE OS VALORES DE HEXDECIMAL:\n");
   // printf("MAC:");
   // scanf("%d", &mac);
   // mac_adress = mac;
   // printf("\nMAC DEFINIDO COM SUCESSO: %d\n", mac_adress);
   // printf("\nMAC DEFINIDO COM SUCESSO: %d\n", mac_adress_automatico);

    char mac_adress_define;
    ///mac_adress_define = getch();

    for(int a=0;a<=6;a++)
    {

        if(a == 1){
            scanf("%d", &mac);
            mac1 = mac;
            if(a == 1){system("cls"); printf("%d:", mac1);}
        }
        if(a == 2){
            scanf("%d", &mac);
            mac2 = mac;
            if(a == 2){system("cls"); printf("%d:%d:", mac1, mac2);}
        }
        if(a == 3){
            scanf("%d", &mac);
            mac3 = mac;
            if(a == 3){system("cls"); printf("%d:%d:%d:", mac1, mac2, mac3);}
        }
        if(a == 4){
            scanf("%d", &mac);
            mac4 = mac;
            if(a == 4){system("cls"); printf("%d:%d:%d:%d:", mac1, mac2, mac3, mac4);}
        }
        if(a == 5){
            scanf("%d", &mac);
            mac5 = mac;
            if(a == 5){system("cls"); printf("%d:%d:%d:%d:%d:", mac1, mac2, mac3, mac4, mac5);}
        }
        if(a == 6){
            scanf("%d", &mac);
            mac6 = mac;
            if(a == 6){system("cls"); printf("%d:%d:%d:%d:%d:%d", mac1, mac2, mac3, mac4, mac5, mac6);}
        }

    }

    main();

}


/**
    char mac1[1],mac2[2],mac3[3],mac4[4],mac5[5],mac6[6],mac7[7],mac8[8],mac9[9],mac10[10],mac11[11],mac12[12],mac13[13],mac14[14],mac15[15],mac16[16];
    char chama;
    char *dados;
    int lop;
    int x;

    dados = malloc( sizeof(char *));

    printf("\nCONFIGURACAO MAC!\n");
    printf("\nDIGITE OS VALORES DE HEXDECIMAL:\n");
    printf("MAC:");

    system("cls");

    //for(lop=1;lop<=1855; lop++)
    //{
    //    printf("%c",dados[lop]);
    //}

    for(lop=1;lop<=12;lop++)
    {
        chama = getch();
            switch(chama)
            {
                case'1':
                    mac1[1] = '61';
                    break;
                case'2':
                    mac2[2] = '62';
                    break;
                case'3':
                    mac3[3] = '63';
                    break;
                case'4':
                    mac4[4] = '64';
                    break;
                case'5':
                    mac5[5] = '65';
                    break;
                case'6':
                    mac6[6] = '66';
                    break;
                case'7':
                    mac7[7] = '67';
                    break;
                case'8':
                    mac8[8] = '68';
                    break;
                case'9':
                    mac9[9] = '69';
                    break;
                case'0':
                    mac10[10] = '0';
                    break;
                case'A':
                case'a':
                    mac11[11] = '10';
                    break;
                case'b':
                    mac12[12] = '20';
                    break;
                case'c':
                    mac13[13] = '30';
                    break;
                case'd':
                    mac14[14] = '40';
                    break;
                case'e':
                    mac15[15] = '50';
                break;
                case'f':
                    mac16[16] = '60';
                    break;
            }
            if(lop ==   1){printf("MAC:%c", mac1[1]);}else
            if(lop ==   2){printf("%c",     mac1[2]);}else
            if(lop ==   3){printf("%c",     mac1[3]);}else
            if(lop ==   4){printf("%c",     mac1[4]);}else
            if(lop ==   5){printf("%c",     mac1[5]);}else
            if(lop ==   6){printf("%c",     mac1[6]);}else
            if(lop ==   7){printf("%c",     mac1[7]);}else
            if(lop ==   8){printf("%c",     mac1[8]);}else
            if(lop ==   9){printf("%c",     mac1[9]);}else
            if(lop ==  10){printf("%c",     mac1[10]);}else
            if(lop ==  11){printf("%c",     mac1[11]);}else
            if(lop ==  12){printf("%c",     mac1[12]);}


    }


}
*/

