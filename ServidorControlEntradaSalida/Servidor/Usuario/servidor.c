/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "accesoUsrs.h"
#include <stdio.h>

char **
solicitud_entrada_1_svc(char **argp, struct svc_req *rqstp)
{
	static char * result = "solicitud recibida";
	printf("\nSolicitud de entrada con codigo %s\n", *argp);	
	fflush(stdout);

	return &result;
}

char **
solicitud_salida_1_svc(char **argp, struct svc_req *rqstp)
{
	static char * result;
	printf("\nSolicitud de salida con codigo %s\n", *argp);	
	
	return &result;
}
