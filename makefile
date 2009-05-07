# makefile for Tsuporone's Koyomi environment

CC = gcc
LD = gcc

TARGET1 = tamo
TARGET2 = koyomi
TARGET3 = moon
TARGET4 = igrf

TARGET = $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4)

OBJS1 = birthday.o dates.o ftime.o holiday.o tamo.o maya.o \
        qreki.o wareki.o moon.o tamo_solar.o nepali.o \
        decodeURL.o calendar.o print.o coptic.o tamo_igrf.o \
        campaign.o
OBJS2 = birthday2.o dates2.o ftime.o holiday2.o koyomi.o \
        maya.o qreki2.o wareki2.o phase2.o zen2han.o getstr.o \
        nepali2.o decodeURL.o strcmpi.o
OBJS3 = moon2.o decodeURL.o
OBJS4 = tamo_igrf2.o

BINDIR = $(HOME)/bin
WEBDIR = $(HOME)/public_html/cgi-bin

all: $(TARGET)

allclean: 
	-rm *.o
	-rm $(TARGET1)
	-rm $(TARGET2)
	-rm $(TARGET3)
	-rm $(TARGET4)

clean: 
	-rm *.o

install: $(TARGET1) $(TARGET2) $(TARGET3)
	copy $(TARGET1) $(TARGET1).cgi
	copy $(TARGET1) $(BINDIR)
	copy $(TARGET1).cgi $(WEBDIR)
	copy $(TARGET2) $(BINDIR)
	copy $(TARGET3) $(BINDIR)

$(TARGET1): $(OBJS1)
	$(LD) -o $(TARGET1) $(OBJS1) -lm

$(TARGET2): $(OBJS2)
	$(LD) -o $(TARGET2) $(OBJS2) -lm

$(TARGET3): $(OBJS3)
	$(LD) -o $(TARGET3) $(OBJS3) -lm

$(TARGET4): $(OBJS4)
	$(LD) -o $(TARGET4) $(OBJS4) -lm

tamo_igrf.o: tamo_igrf.c
	$(CC) -DTAMO -c tamo_igrf.c

tamo_igrf2.o: tamo_igrf.c
	$(CC) -DTEST -c tamo_igrf.c -o tamo_igrf2.o

birthday.o: flower.c
	$(CC) -DUNIX -c flower.c -o birthday.o

birthday2.o: birthday.c
	$(CC) -DUNIX -c birthday.c -o birthday2.o

moon.o: tamo_moon.c
	$(CC) -DUNIX -DRIMNET -c tamo_moon.c -o moon.o

moon2.o: moon.c
	$(CC) -DUNIX -c moon.c -o moon2.o

decodeURL.o: decodeURL.c
	$(CC) -c decodeURL.c

ftime.o: ftime.c
	$(CC) -c ftime.c

dates.o: dates.c
	$(CC) -DTAMO -c dates.c

dates2.o: dates.c
	$(CC) -c dates.c -o dates2.o

holiday.o: tamo_func.c
	$(CC) -c tamo_func.c -o holiday.o

holiday2.o: holiday.c
	$(CC) -c holiday.c -o holiday2.o

tamo.o: tamo.c
	$(CC) -c tamo.c

koyomi.o: koyomi.c
	$(CC) -c koyomi.c

maya.o: maya.c
	$(CC) -c maya.c

qreki.o: tamo_qreki.c
	$(CC) -DUNIX -c tamo_qreki.c -o qreki.o

qreki2.o: qreki.c
	$(CC) -DUNIX -c qreki.c -o qreki2.o

wareki.o: tamo_wareki.c
	$(CC) -c tamo_wareki.c -o wareki.o

wareki2.o: wareki.c
	$(CC) -c wareki.c -o wareki2.o

nepali.o: nepali.c
	$(CC) -DTAMO -c nepali.c

nepali2.o: nepali.c
	$(CC) -c nepali.c  -o nepali2.o

coptic.o: coptic.c
	$(CC) -c coptic.c

tamo_solar.o: tamo_solar.c
	$(CC) -c tamo_solar.c

calendar.o: calendar.c
	$(CC) -c calendar.c

print.o: print.c
	$(CC) -DUNIX -DTAMO -c print.c

campaign.o: campaign.c
	$(CC) -c campaign.c

phase2.o: phase2.c
	$(CC) -DUNIX -c phase2.c

strcmpi.o: strcmpi.c
	$(CC) -c strcmpi.c

