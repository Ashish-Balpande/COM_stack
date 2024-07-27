#include "rte.h"

                        //data, pos, len
Std_ReturnType RTE_Read(uint8_t sigId, uint16_t *sig1[16])
{
    Com_ReciveSignal(sigId, &sig1[0]);

    printf("\nReturn Signal in RTE....\n");
    for(int i=0; i<16; i++){
            printf("%d", sig1[i]);
        }
    return E_OK;
}



/*
void tx_rte(uint16_t sig_buff, uint8_t flag)
{
    printf("In RTE\nsignal: %d\n", sig_buff);
    printf("flag: %d\n", flag);

    tx_com(sig_buff, flag);
}
*/
