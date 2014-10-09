TARGET=cacu
CC=gcc
CFLAGS= -Iaddsrc -Isubsrc -O2
#OBJS=addsrc/add.o subsrc/sub.o make_main.o
#VPATH=subsrc:.
DIRS = subsrc addsrc .
FILES = $(foreach dir, $(DIRS),$(wildcard $(dir)/*.c))
#OBJS=sub.o make_main.o
OBJS = $(patsubst %.c,%.o,$(FILES))
#RM= rm -f
#export OBJSDIR = $(shell pwd)/.objs

#$(TARGET):add.o sub.o make_main.o
#	gcc -o cacu addsrc/add.o subsrc/sub.o make_main.o
#$(TARGET):$(OBJS)
#$(TARGET):$(OBJSDIR) $(OBJS)
$(TARGET):$(OBJS)
#	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS)
#	$(CC) -o $@  $^ $(CFLAGS)
#	$(MAKE) -C addsrc
#	$(CC) -o $(TARGET) $(OBJSDIR)/*.o $(CFLAGS)
#add.o:addsrc/add.c addsrc/add.h
#	gcc -c -o addsrc/add.o addsrc/add.c
#sub.o:subsrc/sub.c subsrc/sub.h
#	gcc -c -o subsrc/sub.o subsrc/sub.c

#make_main.o:%o:%c addsrc/add.h subsrc/sub.h
#	gcc -c  $< -o $@ -Iaddsrc -Isubsrc

#$(OBJS):%o:%c
#	$(CC) $< -c $(CFLAGS) -o $(OBJSDIR)/$@
	$(CC) -o $(TARGET) $(OBJS)

#$(OBJSDIR):
#	mkdir -p ./$@

clean:
#	rm -f cacu addsrc/add.o subsrc/sub.o make_main.o
			-$(RM)	$(TARGET)
			-$(RM)  $(OBJS)
#	-$(RM) $(OBJSDIR)/*.o
