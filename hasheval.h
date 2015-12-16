#ifndef __HASHEVAL_H
#define __HASHEVAL_H

#include <QByteArray>

typedef unsigned __int32 uint32_t;

void init();
uint32_t hash(const QByteArray &a);

#endif //__HASHEVAL_H
