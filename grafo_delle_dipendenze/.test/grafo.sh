#!/bin/bash

source $(dirname "$0")/../../.test/test.sh

BINARY=start
OUTPUT=/tmp/output.txt
TIMEOUT=30
SKIPPED=0


init_feedback "Esercizio grafo delle dipendenze"

compile_and_run $BINARY $OUTPUT $TIMEOUT


perl -n -e 'if(/\[P1\]\sOPERANDI:\sa=(\d+),\sb=(\d+),\sc=(\d+),\sd=(\d+),\se=(\d+),\sf=(\d+),\sg=(\d+),\sh=(\d+)/) { ($a,$b,$c,$d,$e,$f,$g,$h)=($1,$2,$3,$4,$5,$6,$7,$8); }  if(/\[P2\] OPERANDI:\sa=(\d+),\sb=(\d+)/){ if($1!=$a || $2!=$b) { exit(1); } }  if(/\[P3\]\sOPERANDI:\sc=(\d+),\sd=(\d+),\se=(\d+),\sf=(\d+)/){ if($1!=$c || $2!=$d || $3!=$e || $4!=$f) { exit(1); } }  if(/\[P4\]\sOPERANDI:\sg=(\d+),\sh=(\d+)/) { if($1!=$g || $2!=$h) { exit(1); } }  if(/\[P5\]\sOPERANDI:\sc=(\d+),\sd=(\d+)/) { if($1!=$c || $2!=$d) { exit(1); } }  if(/\[P2\]\sRISULTATO:\s(\d+)/) { $r1=$1; } if(/\[P3\]\sRISULTATO:\s(\d+)/) { $r2=$1; } if(/\[P4\]\sRISULTATO:\s(\d+)/) { $r3=$1; } if(/\[P5\]\sRISULTATO:\s(\d+)/) { $r4=$1; } if(/\[P6\]\sRISULTATO:\s(\d+)/) { $r5=$1; }  if(/\[P3\]\sRISULTATI\sINTERMEDI:\sr4=(\d+), r5=(\d+)/) { if($1!=$r4 || $2!=$r5) { exit(1); } } if(/\[P1\]\sRISULTATI\sINTERMEDI:\sr1=(\d+),\sr2=(\d+),\dr3=(\d+)/) { if($1!=$r1 || $2!=$r2 || $3!=$r3) { exit(1); } }' $OUTPUT

if [ $? -ne 0 ]
then
    failure "L'esecuzione non invia correttamente i messaggi"
fi


static_analysis


success


