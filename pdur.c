#include "pdur.h"


void rx_pdur(hrh_buf hrh2){
    printf("\nData in PDUR\nPCIid : %d \nsdu : %d \n", hrh2.pciId, hrh2.sdu);

    switch(hrh2.pciId){
        case 1: rx_com(hrh2);
                //printf("COM...!\n");
                break;
        case 2: //DEM(hrh2);
            break;
    }

}

