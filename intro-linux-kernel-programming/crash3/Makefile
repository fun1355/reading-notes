ifeq ($(KERNELRELEASE),)

KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

.PHONY: build clean

build:
		$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
		rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c
	    rm -f modules.order Module.symvers

else

$(info Building with KERNELRELEASE = ${KERNELRELEASE})
obj-m := crash3.o

endif