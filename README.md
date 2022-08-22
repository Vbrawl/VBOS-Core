***VBOS?***
-----------

VBOS stands for VBrawl's OS (I'm not good with names...) and is (going to be) a general purpose OS. It's going to have server editions and versions with GUI.

It's going to have a lot of features such as, app containerization, 1-process mode, and be more secure than everything else.



***What about the core?***
--------------------------

It's the kernel of VBOS, the main functionality and some drivers are here.


***State***
-----------

We currently have the bootloader and a really basic kernel that, with the help
of some custom drivers, is able to print stuff to the screen.



***Dependencies***
------------------

To be able to build and run this kernel in qemu you have to do the following:

- Install GCC
- Install Qemu x86 arch (Or a Virtual Machine)
- Build Cross-Compiler GCC for i386


***Installing Dependencies***
-----------------------------

1) Installing Gcc, Qemu:

```
sudo apt install gcc qemu-system-i386
```

2) Prepare to Build the Cross-Compiler GCC:

```
# The architecture we are targeting
export TARGET=i386-elf

# Where you want to install the compiler
export PREFIX="$HOME/i386-elf-compiler"

# We need to update the PATH (IMPORTANT!!!)
export PATH="$PREFIX/bin:$PATH"
```

3) Download, Build and Install Binutils (FOR THE CROSS-GCC):

```
# Create a temp-folder
$ mkdir /tmp/binutils
$ cd /tmp/binutils

# Download the source code
$ git clone git://sourceware.org/git/binutils-gdb.git

# Create another folder (for better organization):
mkdir binutils-build
cd binutils-build

# Build and Install
$ ../binutils-gdb/configure --target=$TARGET prefix=$PREFIX --with-sysroot --disable-nls --disable-werror
$ make
$ make install
```

4) Download, Build and Install GCC:

```
# Create a temp-folder
$ mkdir /tmp/gcc_source
$ cd /tmp/gcc_source

# Download the source code
$ git clone git://gcc.gnu.org/git/gcc.git

# Create another folder (for better organization)
$ mkdir gcc-build
$ cd gcc-build

# Build and Install
$ ../gcc/configure --target=$TARGET --prefix=$PREFIX --disable-nls --enable-languages=c,c++ --without-headers
$ make all-gcc
$ make all-target-libgcc
$ make install-gcc
$ make install-target-libgcc
```


- NOTE: For more details see: https://wiki.osdev.org/GCC_Cross-Compiler#The_Build