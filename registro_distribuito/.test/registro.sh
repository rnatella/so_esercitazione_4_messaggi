#!/bin/bash

source $(dirname "$0")/../../.test/test.sh

BINARY=programma
OUTPUT=/tmp/output.txt
TIMEOUT=30
SKIPPED=0


init_feedback "Esercizio registro distribuito"

compile_and_run $BINARY $OUTPUT $TIMEOUT


perl -n -e '
if(/Server:\sInvio\smessaggio\sBIND\s\(id_server=(\d+),\sid_coda=(\d+)\)/) { $server{$1}=$2; }
if(/Registro:\sRicevuto\smessaggio\sBIND\s\(id_server=(\d+),\sid_coda=(\d+)\)/) { if(! exists $server{$1} || $server{$1}!=$2) { exit(1); } }
if(/Registro:\sRicevuto\smessaggio\sQUERY\s\(id_server=(\d+)\)/) { $query=$1; }
if(/Registro:\sInvio\smessaggio\sRESULT\s\(id_coda=(\d+)\)/) { if($server{$query}!=$1) { exit(1); } }
if(/Client:\sInvio\smessaggio\sSERVICE\s\(id_server=(\d+),\sid_coda=(\d+),\svalore=(\d+)\)/) { push @requests,$3; }
if(/Server:\sRicevuto\smessaggio\sSERVICE\s\(id_server=(\d+),\svalore=(\d+)\)/) { if(! exists $server{$1}) { exit(1); } push @received,$2; $total++; }
if(/Server:\sRicevuto\smessaggio\sEXIT\s\(id_server=(\d+)\)/) { $exit{$1}=1; }
END { if(! exists $exit{0} || ! exists $exit{1}) { exit(1); }  if($#requests!=$#received) { exit(1); }  @s1=sort @requests; @s2=sort @received; for $i(0..$#s1) { if($s1[$i]!=$s2[$i]) { exit(1); } } if($total<9) { exit(1); } }
' $OUTPUT

if [ $? -ne 0 ]
then
    failure "L'esecuzione non invia correttamente i messaggi"
fi


static_analysis


success


