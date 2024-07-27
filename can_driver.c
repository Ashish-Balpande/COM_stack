#include "can_driver.h"


lpdu_frame lpdu1;

void rx_can_driver(){
    uint32_t frame;

    //printf("Enter the frame :");
    //scanf("%d", &frame);                      //  id    dlc     sdu

    frame = 0b011000010101101111001010;                 //0b0110  0001  01010101;

    rx_filter(frame);
}

void rx_filter(uint32_t frame){
    int size=24;
    uint32_t frameId = frame;
    uint8_t mask_id = (frameId>>size-4)&0x0f;
    uint32_t frameDlc = frame;
    uint8_t mask_dlc = (frameDlc>>size-8)&0x0f;
    uint32_t frameSDU = frame;
    uint16_t mask_sdu = (frameSDU)&0xffff;

    printf("id : %d \ndlc : %d \nsdu : %d \n", mask_id, mask_dlc, mask_sdu);

    if((mask_id>=0x2) && (mask_id<=0x9)){
        lpdu1.id    =   mask_id;
        lpdu1.dlc   =   mask_dlc;
        lpdu1.sdu   =   mask_sdu;

        printf("\nData in Can Driver\nid : %d \ndlc : %d \nsdu : %d \n", lpdu1.id, lpdu1.dlc, lpdu1.sdu);

        rx_can_if(lpdu1);
    }
    else{
        printf("ID is not matched...!\n");
    }

}



