/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "adminSvdrGU.h"

void capturarCredenciales(adminGU * credencial) {
	(*credencial).login = (char *)malloc(sizeof(char) * 50);
	(*credencial).clave = (char *)malloc(sizeof(char) * 50);
	printf("\nLogin: ");
	scanf("%s", (*credencial).login);
	printf("\nClave: ");
	scanf("%s", (*credencial).clave);
}

void informarResultadoOperacion(CLIENT * clnt, int * resultado, int valorExito, char * mensajeExito, char * mensajeFallo) {
	if (resultado == (int *)NULL) {
		clnt_perror (clnt, "call failed");
	} else {
		if ((*resultado) == valorExito) {
			printf("\n%s\n", mensajeExito);
		} else {
			printf("\n%s\n", mensajeFallo); 
		}
	}
}

void
gestion_usuarios_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	adminGU  acceso_admin_1_arg;
	int  *result_2;
	usuario  ingreso_usuario_1_arg;
	int  *result_3;
	usuario  modificar_usuario_1_arg;
	usuario  *result_4;
	char * obtener_usuario_1_arg;
	int  *result_5;
	char * eliminar_usuario_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, gestion_usuarios, gestion_usuarios_version, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	int opcion = -1, auxCredencial = 0;
	result_1 = 0;	
	do {			
		while (auxCredencial == 0) {			
			capturarCredenciales(&acceso_admin_1_arg);
			result_1 = acceso_admin_1(&acceso_admin_1_arg, clnt);
			printf("\nEnviando Login %s, Clave %s", acceso_admin_1_arg.login, acceso_admin_1_arg.clave);
			informarResultadoOperacion(clnt, result_1, 1, "Acceso Concedido", "Acceso denegado, intente de nuevo");				
			auxCredencial = (*result_1);
		}
		/*
		result_2 = ingreso_usuario_1(&ingreso_usuario_1_arg, clnt);
		if (result_2 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		result_3 = modificar_usuario_1(&modificar_usuario_1_arg, clnt);
		if (result_3 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		result_4 = obtener_usuario_1(&obtener_usuario_1_arg, clnt);
		if (result_4 == (usuario *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		result_5 = eliminar_usuario_1(&eliminar_usuario_1_arg, clnt);
		if (result_5 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}*
		* */
	} while (opcion != 0);
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
	gestion_usuarios_1 (host);
exit (0);
}