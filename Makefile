obj-m:=1a.o p1.o p2.o
KDIR= /lib/modules/$(shell uname -r)/build/
all:
   make -C $(KDIR) M =$(shell pwd) modules
clean:
    make -C $(KDIR) M =$(shell pwd) modules
