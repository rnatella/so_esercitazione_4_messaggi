#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "header.h"

int main() {

	int msg_id_balancer;
	int msg_id_server[TOTALE_SERVER];
	int i;
	pid_t p;
	int status;
	int ret;



	/*
	  TBD: Creare una coda per i messaggi dai client
	  verso il balancer
	*/

	msg_id_balancer = /* TBD */

	if(msg_id_balancer < 0) {

		perror("Errore msgget() coda balancer");
		exit(1);
	}



	/*
	  TBD: Creare 3 code per i messaggi dal balancer verso
	  i server, una coda per ogni server
	*/

	for(i=0; i<TOTALE_SERVER; i++) {

		msg_id_server[i] = /* TBD */

		if(msg_id_server[i] < 0) {

			perror("Errore msgget() coda server");
			exit(1);
		}
	}



	/*
	  TBD: Creare i processi client, passando alla funzione Client()
	  in ingresso lo ID della coda del balancer
	*/

	for(i=0; i<TOTALE_CLIENT; i++) {

		/* TBD */
	}



	/*
	  TBD: Creare i processi server, passando alla funzione Server()
	  in ingresso lo ID della coda di quel server
	*/

	for(i=0; i<TOTALE_SERVER; i++) {

		/* TBD */
	}



	/*
	  TBD: Creare il processo balancer, passando alla funzione Balancer()
	in ingresso gli ID di tutte le code
	*/




	/*
	  TBD: Il processo padre si pone in attesa della terminazione
	  di tutti i processi (client, server e balancer)
	*/

	for(i=0; i<TOTALE_CLIENT+TOTALE_SERVER+1; i++) {

		/* TBD */
	}



	/*
	  TBD: Rimozione delle code dal sistema
	*/



	return 0;

}

  
