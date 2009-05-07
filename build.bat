set OLDPATH=%PATH%
PATH=c:\lcc\bin;%PATH%


kpp flower.c
ren flower.kpp birthday_.c
lcc -c -O birthday_.c
del birthday_.c

lcc -DTAMO -c -O dates.c

kpp ftime.c
ren ftime.kpp ftime_.c
lcc -c -O ftime_.c
del ftime_.c

kpp tamo_func.c
ren tamo_func.kpp holiday_.c
lcc -c -O holiday_.c
del holiday_.c

lcc -c -O tamo.c

kpp maya.c
ren maya.kpp maya_.c
lcc -c -O maya_.c
del maya_.c

kpp tamo_qreki.c
ren tamo_qreki.kpp qreki_.c
lcc -DMSDOS -c -O qreki_.c
del qreki_.c

kpp tamo_wareki.c
ren tamo_wareki.kpp wareki_.c
lcc -c -O wareki_.c
del wareki_.c

lcc -DTAMO -c -O nepali.c

lcc -c -O coptic.c

kpp tamo_moon.c
ren tamo_moon.kpp moon_.c
lcc -c -O moon_.c
del moon_.c

lcc -c -O tamo_solar.c

lcc -DTAMO -c -O tamo_igrf.c

kpp calendar.c
ren calendar.kpp calendar_.c
lcc -c -O calendar_.c
del calendar_.c

lcc -c -O decodeURL.c

lcc -DTAMO -c -O print.c

kpp campaign.c
ren campaign.kpp camp_.c
lcc -c -O camp_.c
del camp_.c

lcc -c -O bmt.c

lcclnk -o tamo.exe birthday_.obj dates.obj ftime_.obj holiday_.obj tamo.obj maya_.obj qreki_.obj wareki_.obj moon_.obj tamo_solar.obj nepali.obj decodeURL.obj calendar_.obj print.obj coptic.obj tamo_igrf.obj camp_.obj bmt.obj

del *.obj
PATH=%OLDPATH%
set OLDPATH=
