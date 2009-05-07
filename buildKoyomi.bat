set OLDPATH=%PATH%
PATH=c:\lcc\bin;%PATH%

kpp birthday.c
ren birthday.kpp birthday_.c
lcc -c -O birthday_.c
del birthday_.c

lcc -c -O dates.c

kpp ftime.c
ren ftime.kpp ftime_.c
lcc -c -O ftime_.c
del ftime_.c

kpp holiday.c
ren holiday.kpp holiday_.c
lcc -c -O holiday_.c
del holiday_.c

lcc -c -O koyomi.c

kpp maya.c
ren maya.kpp maya_.c
lcc -c -O maya_.c
del maya_.c

kpp qreki.c
ren qreki.kpp qreki_.c
lcc -DMSDOS -c -O qreki_.c
del qreki_.c

kpp wareki.c
ren wareki.kpp wareki_.c
lcc -c -O wareki_.c
del wareki_.c

lcc -c -O phase2.c

lcc -c -O zen2han.c

lcc -c -O getstr.c

lcc -c -O nepali.c

lcc -c -O decodeURL.c

REM lcc -c -O changeCode.c

lcclnk -o koyomi.exe birthday_.obj dates.obj ftime_.obj holiday_.obj koyomi.obj maya_.obj qreki_.obj wareki_.obj phase2.obj zen2han.obj getstr.obj nepali.obj decodeURL.obj

del *.obj
PATH=%OLDPATH%
set OLDPATH=
