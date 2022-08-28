# VBOS?
VBOS stands for VBrawl's OS (I'm not good with names...) and is (going to be) a general purpose OS. It's going to have server editions and versions with GUI.

It's going to have a lot of features such as, app containerization, 1-process mode, and be more secure than everything else.



# What about the core?
It's the kernel of VBOS, the main functionality and some drivers are here.


# State
Recreating the whole OS in object oriented programming (with C, yeah)

Already finished the `screen` driver and moved `vga` to `drivers/screen_dependencies/`

If you are not sure how that's possible see the link below.

* https://github.com/Vbrawl/Classes-In-C



# Dependencies
To be able to build and run this kernel in qemu you have to do the following:

- Install GCC
- Install Qemu x86 arch (Or a Virtual Machine)
- Build Cross-Compiler GCC for i386


# Installing Dependencies
1) Installing Gcc, Qemu and Nasm:

```
sudo apt install gcc qemu-system-i386 nasm
```

2) Prepare to Build the Cross-Compiler GCC:

```
# The architecture we are targeting
$ export TARGET=i386-elf

# Where you want to install the compiler
$ export PREFIX="$HOME/i386-elf-compiler"

# We need to update the PATH (IMPORTANT!!!)
$ export PATH="$PREFIX/bin:$PATH"
```

3) Download, Build and Install Binutils (FOR THE CROSS-GCC):

```
# Create a temp-folder
$ mkdir /tmp/binutils
$ cd /tmp/binutils

# Download the source code
$ curl -O http://ftp.gnu.org/gnu/binutils/binutils-2.24.tar.gz
$ tar -xf binutils-2.24.tar.gz

# Create another folder (for better organization):
$ mkdir binutils-build
$ cd binutils-build

# Build and Install
$ ../binutils-2.24/configure --target=$TARGET prefix=$PREFIX --enable-interwork --with-sysroot --disable-nls --disable-werror 2>&1 | tee configure.log
$ make all install 2>&1 | tee make.log
```

4) Download, Build and Install GCC:

```
# Install GCC building dependencies
$ sudo apt install libgmp10 libmpfr6 libmpc-dev

# Create a temp-folder
$ mkdir /tmp/gcc_source
$ cd /tmp/gcc_source

# Download the source code
$ curl -O https://ftp.gnu.org/gnu/gcc/gcc-4.9.1/gcc-4.9.1.tar.bz2
$ tar -xf gcc-4.9.1.tar.bz2

# Create another folder (for better organization)
$ mkdir gcc-build
$ cd gcc-build

# Build and Install
$ ../gcc-4.9.1/configure --target=$TARGET --prefix=$PREFIX --disable-nls --enable-languages=c --disable-libssp --without-headers
$ make all-gcc
$ make all-target-libgcc
$ make install-gcc
$ make install-target-libgcc
```


- NOTE: For more details see: https://wiki.osdev.org/GCC_Cross-Compiler#The_Build
