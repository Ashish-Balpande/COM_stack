#include "com.h"

uint32_t sdu_binary[16];
int remainder, count=0;
uint16_t sdu = 0;

void rx_com(hrh_buf hrh3){
    printf("\nData in COM\nPCIid : %d \nsdu : %d \n", hrh3.pciId, hrh3.sdu);

    sdu = hrh3.sdu;
    //unpack(hrh3.sdu);
}



Std_ReturnType Com_ReciveSignal(uint8_t sigId, uint16_t *sig1[16])
{
    binary(sdu);
    printf("count : %d\n", count);
    for(int i=count; i>=0; i--){
        printf("%d", sdu_binary[i]);
    }

    // swap array
    uint16_t bin_arr[16];
    for(int i=15, j=0; i>=0; i--, j++){
        bin_arr[j]=sdu_binary[i];
    }

    uint8_t len;
    uint8_t pos;
    uint16_t size_byte=0;
    uint16_t temp=0;
    uint16_t signal0[4];
    uint16_t signal1[8];
    uint16_t signal2[16];

    Sig_Id(sigId, &pos, &len);
    printf("\n\nSignal Id %d: pos=%d, len=%d\n", sigId, pos, len);

    if((len>=1) && (len<=4)){
        size_byte=0;            //0.5 byte / 1 nibble
    }
    else if((len>=5) && (len<=8)){
        size_byte=1;
    }
    else if((len>=9) && (len<=16)){
        size_byte=2;
    }
    printf("\nsize of byte: %d\n",size_byte);

    switch(size_byte){
        case 0:printf("\n1 Nibble Signal: ");
                for(int i=0; i<16; i++){
                    if(i>=pos){
                        signal0[temp]=bin_arr[i];
                        sig1[temp]=signal0[temp];
                        printf("%d",signal0[temp]);
                        temp++;
                    }
                    if((pos+len-1)==i){
                        break;
                    }
                }
                break;

        case 1: printf("\n1 Byte signal: ");
                for(int i=0; i<16; i++){
                    if(i>=pos){
                        signal1[temp]=bin_arr[i];
                        sig1[temp]=signal1[temp];
                        printf("%d",signal1[temp]);
                        temp++;
                    }
                    if((pos+len-1)==i){
                        break;
                    }
                }
                break;

        case 2: printf("\n2 Byte signal: ");
                for(int i=0; i<16; i++){
                    if(i>=pos){
                        signal2[temp]=bin_arr[i];
                        sig1[temp]=signal2[temp];
                        printf("%d",signal2[temp]);
                        temp++;
                    }
                    if((pos+len-1)==i){
                        break;
                    }
                }
                break;
    }
    printf("\n");

    printf("\nReturn Signal in COM....\n");
    for(int i=0; i<16; i++){
            printf("%d", sig1[i]);
        }

    return E_OK;
}

void unpack(uint16_t sdu){               //01010101

    binary(sdu);
    printf("count : %d\n", count);
    for(int i=count; i>=0; i--){
        printf("%d", sdu_binary[i]);
    }

    // swap array
    uint16_t bin_arr[16];
    for(int i=15, j=0; i>=0; i--, j++){
        bin_arr[j]=sdu_binary[i];
    }
//====================================================


/*    uint16_t len;
    uint16_t pos;
    uint16_t size_byte=0;
    uint16_t temp=0;
    uint16_t signal0[4];
    uint16_t signal1[8];
    uint16_t signal2[16];

    printf("\n\nEnter the position of signal :");
    scanf("%d", &pos);
    printf("Enter the Length of signal(in bit) :");
    scanf("%d", &len);

    if((len>=1) && (len<=4)){
        size_byte=0;            //0.5 byte / 1 nibble
    }
    else if((len>=5) && (len<=8)){
        size_byte=1;
    }
    else if((len>=9) && (len<=16)){
        size_byte=2;
    }
    printf("\nsize of byte: %d\n",size_byte);

    switch(size_byte){
        case 0:printf("\n1 Nibble Signal: ");
                for(int i=0; i<16; i++){
                    if(i>=pos){
                        signal0[temp]=bin_arr[i];
                        printf("%d",signal0[temp]);
                        temp++;
                    }
                    if((pos+len-1)==i){
                        break;
                    }
                }
                break;

        case 1: printf("\n1 Byte signal: ");
                for(int i=0; i<16; i++){
                    if(i>=pos){
                        signal1[temp]=bin_arr[i];
                        printf("%d",signal1[temp]);
                        temp++;
                    }
                    if((pos+len-1)==i){
                        break;
                    }
                }
                break;

        case 2: printf("\n2 Byte signal: ");
                for(int i=0; i<16; i++){
                    if(i>=pos){
                        signal2[temp]=bin_arr[i];
                        printf("%d",signal2[temp]);
                        temp++;
                    }
                    if((pos+len-1)==i){
                        break;
                    }
                }
                break;
    }
    printf("\n");
*/
}

int binary(int decimal_num){
    while (decimal_num != 0) {
        remainder = decimal_num % 2;
        decimal_num /= 2;
        count++;
        sdu_binary[count-1] = remainder;
    }
}

uint16_t signals_buf[16];
uint16_t sig_bits=0;
uint16_t sig_size[16];
uint16_t sig_size[16];
uint8_t counter=0;

void tx_com(uint16_t sig_buff, uint8_t flag)
{
    printf("In COM\nsignal: %d\n", sig_buff);
    printf("flag: %d\n", flag);

    bit_counter(sig_buff);
    printf("bits of sig : %d\n", sig_bits);

    if(flag==0){
        tx_sig_packing();
    }
}

void tx_sig_packing()
{
    printf("Packing the signals...");

    for(int i=0; i<16; i++){
        printf("%d", sig_size[i]);
    }
}

void bit_counter(uint16_t sig_buff){
    while (sig_buff != 0) {
        remainder = sig_buff % 2;
        sig_buff /= 2;
        sig_bits++;

    }
    sig_size[counter]=sig_bits;
    counter++;
    sig_bits=0;
}

void Sig_Id(uint8_t sigId, uint8_t *pos, uint8_t *len)
{
    switch(sigId)
    {
        case 1: *pos = 0;
                 *len = 3;
                 break;
        case 2: *pos = 3;
                 *len = 5;
                 break;
        case 3: *pos = 8;
                 *len = 1;
                 break;
        case 4: *pos = 9;
                 *len = 6;
                 break;
        case 5: *pos = 15;
                 *len = 1;
                 break;
        default: printf("Signal Id is not Match");
                 break;
    }

}

//
