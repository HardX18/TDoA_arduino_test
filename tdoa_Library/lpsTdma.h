// lpsTdma.h: Generic TDMA utility defines for LPS algorithms

#ifndef __LPS_TDMA_H__
#define __LPS_TDMA_H__

#ifndef TDMA_NSLOTS_BITS
#ifdef LPS_TDMA_ENABLE
#warning "Number of slots bits for TDMA not defined! Defaulting to 1 (2 slots)."
#endif
#define TDMA_NSLOTS_BITS 1
#endif

#ifndef TDMA_SLOT
#define TDMA_SLOT -1
#endif

#define TDMA_SLOT_BITS 27

#define TDMA_FRAME_BITS (TDMA_SLOT_BITS + TDMA_NSLOTS_BITS)
#define TDMA_SLOT_LEN (1ull<<(unsigned long long)(TDMA_SLOT_BITS+1))
#define TDMA_FRAME_LEN (1ull<<(unsigned long long)(TDMA_FRAME_BITS+1))

#define TDMA_LAST_FRAME(NOW) ( NOW & ~(TDMA_FRAME_LEN-1) )

#endif 

//__LPS_TDMA_H__