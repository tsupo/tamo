PATH=c:\lcc\bin;%PATH%

kpp moon.c
ren moon.kpp moon_.c
lcc -c -O moon_.c
del moon_.c

lcc -c -O decodeURL.c

lcclnk -o moon.exe moon_.obj decodeURL.obj

if exist moon.obj del moon.obj
if exist moon_.obj del moon_.obj
if exist decodeURL.obj del decodeURL.obj
