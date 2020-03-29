
KERN_VER = $(shell uname -r)
#KERNELDIR = /lib/modules/$(KERN_VER)/build	


KERNELDIR := /home/linux/linux/
CURRENT_PATH := $(shell pwd)

obj-m := ap3216c.o

build: kernel_modules

kernel_modules:
	$(MAKE) -C $(KERNELDIR) M=$(CURRENT_PATH) modules

clean:
	$(MAKE) -C $(KERNELDIR) M=$(CURRENT_PATH) clean
