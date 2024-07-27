#include<stdio.h>
#include<stdint.h>

typedef struct LPDU{
    uint8_t id;
    uint8_t dlc;
    uint32_t sdu;
}lpdu_frame;
