#include<stdio.h>
#include<stdint.h>

#define Std_ReturnType int
#define E_OK 1
#define E_NOK 0

typedef struct HRH{
    uint8_t pciId;
    uint32_t sdu;
}hrh_buf;

typedef struct HTH{
    uint8_t pciId;
    uint32_t sdu;
}hth_buf;
