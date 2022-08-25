#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define EXPAND(x) x



#ifdef i386
	#define TARGET_ARCH i386
#else
	#error "Unknown Architecture..."
#endif




// Additional options
#ifndef KERNEL_CS
	#define KERNEL_CS 0x08
#endif
