#include "app.h"

uint32_t sig1[16];
uint16_t sig2[16];

void Runnable_1()
{
    int8_t check = 1;
    while(check){

    uint16_t sigId;
    printf("\n\nEnter the signal Id:");
    scanf("%d", &sigId);

    uint8_t noti1 = RTE_Read(sigId, &sig1[0]);

    if(noti1==E_OK)
    {
        printf("\n\nSuccefully Returned\n");
        printf("Signal is in APP : ", sig1);
        for(int i=0; i<16; i++){
            printf("%d", sig1[i]);
        }
    }
    else{
        printf("Not Returned\n");
    }

    printf("\n\n***************************************************\nTry again(0/1): ");
    scanf("%d", &check);

    //sig1= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<16;i++)
    {
        sig1[i]='\0';
    }

}
}


/*
void tx_app()
{
    int flag=1;
    uint16_t sig_buff;

    while(flag){
        printf("\nEnter the signal:");
        scanf("%d",&sig_buff);

        printf("Are you want to add signal again(1/0 for Y/N)?: ");
        scanf("%d",&flag);

        tx_rte(sig_buff, flag);
    }
}
*/
