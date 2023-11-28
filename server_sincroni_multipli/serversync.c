#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "serversync.h"



void send_sinc(int ok_id, int req_id, messaggio * msg)
{

    int ret;

    pid_t pid = getpid();



    printf("[%d] Client: invio request-to-send\n", pid);

    /* TBD: Inviare il messaggio REQUEST TO SEND, includendo il PID del client nel messaggio */

    ret = /* TBD */

    if (ret < 0)
    {
        perror("Errore msgsnd (request-to-send)");
        exit(1);
    }



    printf("[%d] Client: in attesa di ok-to-send...\n", pid);

    /* TBD: Ricevere il messaggio OK TO SEND */

    ret = /* TBD */

    if (ret < 0)
    {
        perror("Errore msgrcv (ok-to-send)");
        exit(1);
    }

    long type = /* TBD: il campo "tipo" del messaggio ricevuto */;
    int id_coda = /* TBD: lo id della coda incluso nel messaggio ricevuto */;

    printf("[%d] Client: ricevuto ok-to-send... type=%ld, id_coda=%d\n", pid, type, id_coda);




    printf("[%d] Client: invio messaggio, coda=%d, type=%ld, valore=%d\n", pid, id_coda, msg->type, msg->val);

    /* TBD: Inviare il messaggio al server */

    ret = /* TBD */

    if (ret < 0)
    {
        perror("Errore msgsnd (coda messaggi)");
        exit(1);
    }

}

void receive_sinc(int msg_id, int ok_id, int req_id, messaggio * msg)
{

    int ret;

    pid_t pid = getpid();



    printf("[%d] Server: in attesa di request-to-send...\n", getpid());

    /* TBD: Ricevere il messaggio REQUEST TO SEND */

    ret = /* TBD */

    if (ret < 0)
    {
        perror("Errore msgrcv (request-to-send)");
        exit(1);
    }

    pid_t pid_client = /* TBD: Il PID del client incluso nel messaggio ricevuto */

    printf("[%d] Server: ricevuto request-to-send, type=%d\n", pid, pid_client);




    long type = /* TBD: il campo "tipo" del messaggio OK TO SEND da inviare */
    int id_coda = /* TBD: lo id della coda del server, da includere nel messaggio OK TO SEND */

    printf("[%d] Server: invio ok-to-send, type=%ld, id_coda=%d\n", pid, type, id_coda);

    /* TBD: Inviare il messaggio OK TO SEND */

    ret = /* TBD */

    if (ret < 0)
    {
        perror("Errore msgsnd (ok-to-send)");
        exit(1);
    }



    printf("[%d] Server: in attesa del messaggio...\n", pid);

    /* TBD: Ricevere il messaggio destinato al server, usando la struct indicata
            dal puntatore "msg" (passato dal chiamante della funzione)
     */

    ret = /* TBD */

    if (ret < 0)
    {
        perror("Errore msgrcv (coda messaggi)");
        exit(1);
    }

    printf("[%d] Server: ricevuto messaggio, type=%ld, valore=%d\n", pid, msg->type, msg->val);

}
