#ifndef PIC_H
#define PIC_H


#define MASTER_PIC_COM	0x20	/* Master PIC Command IO port */
#define MASTER_PIC_DAT	0x21	/* Master PIC Data IO port */

#define SLAVE_PIC_COM	0xA0	/* Slave PIC Command IO port */
#define SLAVE_PIC_DAT	0xA1	/* Slave PIC Data IO port */

#define PIC_ACCEPT	0x20


#include "../../extras/types.h"


void pic_reinit(int master_offset, int slave_offset);
void pic_set_mask(unsigned char master_mask, unsigned char slave_mask);
void pic_accept(bool slave);

#endif
