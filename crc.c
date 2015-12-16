#include "crc.h"
#include <winsock2.h>

#define CRC32_POLY   0x04C11DB7
#define CRC32_POLY_R 0xEDB88320

static uint32_t crc32_table[256];
static uint32_t crc32r_table[256];

void crc32_init(void)
{
        int i, j;
        uint32_t c, cr;
        for (i = 0; i < 256; ++i) {
                cr = i;
                c = i << 24;
                for (j = 8; j > 0; --j) {
                        c = c & 0x80000000 ? (c << 1) ^ CRC32_POLY : (c << 1);
                        cr = cr & 0x00000001 ? (cr >> 1) ^ CRC32_POLY_R : (cr >> 1);
                        }
                crc32_table[i] = c;
                crc32r_table[i] = cr;
                //printf("f[%02X]=%08X\t", i, crc32_table[i]);
                //printf("r[%02X]=%08X\t", i, crc32r_table[i]);
        }
        //printf("\n");
}

uint32_t crc32_stm32(uint32_t init_crc, uint32_t *buf, int len)
{
        uint32_t v;
        uint32_t crc;
        crc = ~init_crc;
        while(len >= 4) {
                v = htonl(*buf++);
                crc = ( crc << 8 ) ^ crc32_table[0xFF & ( (crc >> 24) ^ (v ) )];
                crc = ( crc << 8 ) ^ crc32_table[0xFF & ( (crc >> 24) ^ (v >> 8) )];
                crc = ( crc << 8 ) ^ crc32_table[0xFF & ( (crc >> 24) ^ (v >> 16) )];
                crc = ( crc << 8 ) ^ crc32_table[0xFF & ( (crc >> 24) ^ (v >> 24) )];
                len -= 4;
        }
        if(len) {
                switch(len) {
                        case 1: v = 0xFF000000 & htonl(*buf++); break;
                        case 2: v = 0xFFFF0000 & htonl(*buf++); break;
                        case 3: v = 0xFFFFFF00 & htonl(*buf++); break;
                }
                crc = ( crc << 8 ) ^ crc32_table[0xFF & ( (crc >> 24) ^ (v ) )];
                crc = ( crc << 8 ) ^ crc32_table[0xFF & ( (crc >> 24) ^ (v >> 8) )];
                crc = ( crc << 8 ) ^ crc32_table[0xFF & ( (crc >> 24) ^ (v >> 16) )];
                crc = ( crc << 8 ) ^ crc32_table[0xFF & ( (crc >> 24) ^ (v >> 24) )];
        }
        return ~crc;
}
