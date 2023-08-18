#!/bin/bash

source $(dirname "$0")/../../.test/test.sh

BINARY=main
OUTPUT=/tmp/output.txt
TIMEOUT=30
SKIPPED=0


init_feedback "Esercizio server sincroni multipli"

compile_and_run $BINARY $OUTPUT $TIMEOUT


perl -n -e 'BEGIN { %msg=(); } if(/\[\d+\]\sClient:\sinvio\srequest-to-send,\stype=(\d+)/) { $msg{$1}=(); }  if(/\[\d+\]\sServer:\sricevuto\srequest-to-send,\stype=(\d+)/) { if(! exists $msg{$1}) { exit(1); } }  if(/\[\d+\]\sServer:\sinvio\sok-to-send,\stype=(\d+),\sid_coda=(\d+)/) { $msg{$1}{"coda"} = $2; }  if(/\[(\d+)\]\sClient:\sricevuto\sok-to-send...\stype=(\d+),\sid_coda=(\d+)/) { if($1!=$2 || $msg{$2}{"coda"} != $3) { exit(1); } }  if(/\[\d+\]\sClient:\sinvio\smessaggio,\scoda=(\d+),\stype=(\d+),\svalore=(\d+)/) { $msg{$2}{"val"}=$3; }  if(/\[\d+\]\sServer:\sricevuto\smessaggio,\stype=(\d+),\svalore=(\d+)/) { if(! exists $msg{$1} || $msg{$1}{"val"} != $2) { exit(1); } }' $OUTPUT

if [ $? -ne 0 ]
then
    failure "L'esecuzione non invia correttamente i messaggi"
fi


static_analysis


success


