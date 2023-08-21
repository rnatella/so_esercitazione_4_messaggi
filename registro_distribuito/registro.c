#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "registro.h"

void registro(int id_coda_registro_richieste, int id_coda_registro_risposte) {

    printf("Registro: Avvio...\n");


    /* Questo vettore verrà usato per memorizzare gli ID delle code dei server */
    int id_code_server[2];
    id_code_server[0] = 0;
    id_code_server[1] = 0;


    while(1) {

        printf("Registro: In attesa di messaggi...\n");

        /* TBD: Prelevare un messaggio dalla coda "id_coda_registro_richieste" */


        if(/* TBD: Controllare se il messaggio è di tipo BIND */) {

            int id_server = /* TBD: prelevare lo ID del server dal messaggio */;
            int id_coda = /* TBD: prelevare lo ID della coda dal messaggio */;

            printf("Registro: Ricevuto messaggio BIND (id_server=%d, id_coda=%d)\n", id_server, id_coda);

            if(/* TBD: Controllare che lo ID del server sia 1 oppure 2 */) {
                printf("Registro: ID server non valido\n");
                continue;
            }

            printf("Registro: Registrazione server %d\n", id_server);

            id_code_server[id_server - 1] = /* TBD: memorizzare nello array lo ID della coda di messaggi del server */;

        }
        else if(/* TBD: Controllare se il messaggio è di tipo QUERY */) {

            int id_server = /* TBD: prelevare lo ID del server dal messaggio */;

            printf("Registro: Ricevuto messaggio QUERY (id_server=%d)\n", id_server);

            if(/* TBD: Controllare che lo ID del server sia 1 oppure 2 */) {
                printf("Registro: ID server non valido\n");
                continue;
            }

            int id_coda = id_code_server[id_server - 1];

            if(id_coda == 0) {
                printf("Registro: ID server non registrato\n");
                continue;
            }

            /* TBD: Inviare un messaggio di risposta al client,
             *      tramite la coda "id_coda_registro_risposte".
             *      Nel campo "tipo" della risposta, utilizzare
             *      lo ID del server (valore 1 oppure 2).
             */

            printf("Registro: Invio messaggio di risposta (id_server=%d, id_coda=%d)\n", id_server, id_coda);

        }
        else if(/* TBD: Controllare se il messaggio è di tipo EXIT */) {

            printf("Registro: Ricevuto messaggio EXIT\n");


            for(int i = 0; i<2; i++) {

                if(id_code_server[i] == 0) {
                    continue;
                }

                /* TBD: Inviare un messaggio di tipo EXIT al server,
                 *      tramite la coda "id_code_server[i]"
                 */

                printf("Registro: Invio messaggio EXIT a server %d\n", i);

            }

            printf("Registro: Uscita\n");

            /* TBD: Terminare il processo */

        }
        else {

            printf("Registro: Ricevuto messaggio non riconosciuto\n");
        }
    }
}
