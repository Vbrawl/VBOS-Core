#include "pic.h"
#include "../../drivers/ports.h"


/* These constants were copy-pasted from "https://wiki.osdev.org/8259_PIC" */

#define ICW1_ICW4	0x01		/* ICW4 (not) needed */
#define ICW1_SINGLE	0x02		/* Single (cascade) mode */
#define ICW1_INTERVAL4	0x04		/* Call address interval 4 (8) */
#define ICW1_LEVEL	0x08		/* Level triggered (edge) mode */
#define ICW1_INIT	0x10		/* Initialization - required! */

#define ICW4_8086	0x01		/* 8086/88 (MCS-80/85) mode */
#define ICW4_AUTO	0x02		/* Auto (normal) EOI */
#define ICW4_BUF_SLAVE	0x08		/* Buffered mode/slave */
#define ICW4_BUF_MASTER	0x0C		/* Buffered mode/master */
#define ICW4_SFNM	0x10		/* Special fully nested (not) */



void pic_reinit(int master_offset, int slave_offset) {
	port_bout(MASTER_PIC_COM, ICW1_INIT | ICW1_ICW4);
	port_bout(SLAVE_PIC_COM, ICW1_INIT | ICW1_ICW4);

	io_wait();

	port_bout(MASTER_PIC_DAT, master_offset);
	port_bout(SLAVE_PIC_DAT, slave_offset);

	io_wait();

	port_bout(MASTER_PIC_DAT, 4);
	port_bout(SLAVE_PIC_DAT, 2);

	io_wait();

	port_bout(MASTER_PIC_DAT, ICW4_8086);
	port_bout(SLAVE_PIC_DAT, ICW4_8086);

	io_wait();

	port_bout(MASTER_PIC_DAT, 0);
	port_bout(SLAVE_PIC_DAT, 0);
}


void pic_set_mask(unsigned char master_mask, unsigned char slave_mask) {

	master_mask = master_mask & 0xFD;

	port_bout(MASTER_PIC_DAT, master_mask);
	port_bout(SLAVE_PIC_DAT, slave_mask);
}


void pic_accept(bool slave) {
	if(slave) port_bout(SLAVE_PIC_COM, PIC_ACCEPT);
	port_bout(MASTER_PIC_COM, PIC_ACCEPT);
}
