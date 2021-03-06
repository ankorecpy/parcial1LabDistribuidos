/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "enlcSrvdrs.h"


void
comunicacion_servidores_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	char * validar_codigo_usuario_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, comunicacion_servidores, comunicacion_servidores_version, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	validar_codigo_usuario_1_arg = "5";
	result_1 = validar_codigo_usuario_1(&validar_codigo_usuario_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	comunicacion_servidores_1 (host);
exit (0);
}
