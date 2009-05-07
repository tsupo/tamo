PATH=c:\lcc\bin;%PATH%

lcc -DTEST -c -O tamo_igrf.c

lcclnk -o igrf.exe tamo_igrf.obj

if exist tamo_igrf.obj del tamo_igrf.obj
