#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#include "registro.h"

void client(int id_coda_registro_richieste, int id_coda_registro_risposte) {

    printf("Client: Avvio...\n");

    srand(getpid());

    int id_server = (rand() % 2) + 1; // Sceglie un server a caso

    printf("Client: Invio messaggio QUERY (id_server=%d)\n", id_server);

    /* TBD: Inviare un messaggio di tipo QUERY al registro,
     *      tramite la coda "id_coda_registro_richieste"
     */



    printf("Client: Attesa messaggio di risposta dal registro...\n");

    /* TBD: Ricevere il messaggio di risposta dal registro,
     *      tramite la coda "id_coda_registro_risposte".
     *      Effettuare una ricezione selettiva, indicando "id_server"
     *      come valore del campo "tipo" che si vuole ricevere.
     */

    int id_coda_server = /* TBD: prelevare lo ID della coda dal messaggio RESULT */

    printf("Client: Ricevuto messaggio di risposta dal registro (id_server=%d, id_coda=%d)\n", id_server, id_coda_server);



    for(int i = 0; i<3; i++) {

        int valore = rand() % 11;

        printf("Client: Invio messaggio SERVICE (id_server=%d, id_coda=%d, valore=%d)\n", id_server, id_coda_server, valore);

        /* TBD: Inviare un messaggio di tipo SERVICE al server, inserendovi il valore */

        sleep(1);
    }

    printf("Client: Uscita\n");
}
