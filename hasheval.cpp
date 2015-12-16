#include "hasheval.h"
#include "crc.h"

void init()
{
	crc32_init();
}

uint32_t hash(const QByteArray &a)
{
	auto l = QByteArray(a);
	return crc32_stm32(0, reinterpret_cast<uint32_t *>(l.data()), l.size());
}
