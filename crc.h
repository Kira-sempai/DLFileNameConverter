#ifndef __CRC_H
#define __CRC_H

typedef unsigned __int32 uint32_t;

#ifdef __cplusplus
extern "C"
{
#endif

void crc32_init(void);
uint32_t crc32_stm32(uint32_t init_crc, uint32_t *buf, int len);

#ifdef __cplusplus
}
#endif

#endif //__CRC_H
