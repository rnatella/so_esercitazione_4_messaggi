#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{

    /* Coda "OK TO SEND" */

    key_t ok_key = /* TBD: Definire una chiave per "OK TO SEND" */

    int ok_id = /* TBD: Ottenere la coda per i messaggi "OK TO SEND" */

    if (ok_id < 0)
    {
        perror("Errore creazione coda messaggi");
        exit(1);
    }

    /* Coda "REQUEST TO SEND" */

    key_t req_key = /* TBD: Definire una chiave per "REQUEST TO SEND" */

    int req_id = /* TBD: Ottenere la coda per i messaggi "REQUEST TO SEND" */

    if (req_id < 0)
    {
        perror("Errore creazione coda messaggi");
        exit(1);
    }


    for (int i = 0; i < 2; i++)
    {
        /* TBD: Avviare 2 processi server */
    }


    for (int i = 0; i < 4; i++)
    {
        /* TBD: Avviare 4 processi client */
    }



    printf("[%d] In attesa di terminazione...\n", getpid());

    /* TBD: Attendere la terminazione di tutti i processi */



    printf("[%d] Deallocazione code\n", getpid());

    /* TBD: Deallocazione delle code */


    return 0;
}