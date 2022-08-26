#ifndef PIC_H
#define PIC_H


#define MASTER_PIC_COM	0x20	/* Master PIC Command IO port */
#define MASTER_PIC_DAT	0x21	/* Master PIC Data IO port */

#define SLAVE_PIC_COM	0xA0	/* Slave PIC Command IO port */
#define SLAVE_PIC_DAT	0xA1	/* Slave PIC Data IO port */



void pic_reinit(int master_offset, int slave_offset);



#endif
