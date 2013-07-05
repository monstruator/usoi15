#
#  Makefile for USOI driver
#

all: MO3AK

MO3AK: main.o globals.o tcpip.o device.o handbuf0.o handbuf1.o handbuf2.o \
		handbuf3.o handbuf4.o handbuf5.o handbuf6.o handtout.o \
        handcmd.o handcmd32.o handcmd3a.o led.o
	cc -ms -o MO3AK main.o globals.o tcpip.o device.o handbuf0.o handbuf1.o \
        handbuf2.o handbuf3.o handbuf4.o handbuf5.o handbuf6.o handtout.o \
        handcmd.o handcmd32.o handcmd3a.o led.o
	usemsg MO3AK usemsg

main.o: main.c globals.h
	cc -ms -c -o main.o main.c

globals.o: globals.c globals.h
	cc -ms -c -o globals.o globals.c

tcpip.o: tcpip.c
	cc -ms -c -o tcpip.o tcpip.c

device.o: device.c
	cc -ms -c -o device.o device.c

handbuf0.o: handbuf0.c globals.h
	cc -ms -c -o handbuf0.o handbuf0.c

handbuf1.o: handbuf1.c globals.h
	cc -ms -c -o handbuf1.o handbuf1.c

handbuf2.o: handbuf2.c globals.h
	cc -ms -c -o handbuf2.o handbuf2.c

handbuf3.o: handbuf3.c globals.h
	cc -ms -c -o handbuf3.o handbuf3.c

handbuf4.o: handbuf4.c globals.h
	cc -ms -c -o handbuf4.o handbuf4.c

handbuf5.o: handbuf5.c globals.h
	cc -ms -c -o handbuf5.o handbuf5.c

handbuf6.o: handbuf6.c globals.h
	cc -ms -c -o handbuf6.o handbuf6.c

handtout.o: handtout.c globals.h
	cc -ms -c -o handtout.o handtout.c

handcmd.o: handcmd.c globals.h
	cc -ms -c -o handcmd.o handcmd.c

handcmd32.o: handcmd32.c globals.h
	cc -ms -c -o handcmd32.o handcmd32.c

handcmd3a.o: handcmd3a.c globals.h
	cc -ms -c -o handcmd3a.o handcmd3a.c

led.o: led.c globals.h
	cc -ms -c -o led.o led.c

clean:
	rm -f *.o *.err *.i

spotless: clean
	rm -f MO3AK

