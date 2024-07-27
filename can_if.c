#include "can_if.h"

#define PCI_ID  1
#define REQ_DLC 0b0001

#define MIN 0x4
#define MAX 0x6

lpdu_frame lpdu5;
hrh_buf hrh1;

void rx_can_if(lpdu_frame lpdu2){
    printf("\nData in CanIf\nid : %d \ndlc : %d \nsdu : %d \n", lpdu2.id, lpdu2.dlc, lpdu2.sdu);

    lpdu5 = lpdu2;

    rx_sw_filter();
}


void rx_sw_filter(){
    if((lpdu5.id>=MIN) && (lpdu5.id<=MAX)){             //filter s/w id's
        if(lpdu5.dlc == REQ_DLC){                       //filter DLC
            hrh1.pciId = PCI_ID;
            hrh1.sdu = lpdu5.sdu;

            printf("\nData in HRH_BUF\nPCIid : %d \nsdu : %d \n", hrh1.pciId, hrh1.sdu);

            rx_pdur(hrh1);
        }
        else{
            printf("\nDLC is not matched with ReqDLC...!\n");
        }
    }
    else{
        printf("\nS/W ID is not matched with Range of ReqID...!\n");
    }
}
