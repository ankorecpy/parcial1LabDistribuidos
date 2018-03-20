/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */
		
#include "adminSvdrGU.h"

usuario capturarDatosUsuario() {
	usuario auxUsuario;	
	printf("\nCodigo: ");
	scanf("%s", auxUsuario.codigo);
	printf("\nMonbres: ");
	scanf("%s", auxUsuario.nombres);
	printf("\nApellidos: ");
	scanf("%s", auxUsuario.apellidos);
	printf("\nRol: ");
	scanf("%s", auxUsuario.rol);
	return auxUsuario;
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

	int adminAccesado = 0, opcion = -1;
	do {
		while (adminAccesado == 0) {
			system("clear");
			printf("\nLogin: ");
			scanf("%s", (acceso_admin_1_arg).login);
			printf("Clave: ");
			scanf("%s", (acceso_admin_1_arg).clave);
			result_1 = acceso_admin_1(&acceso_admin_1_arg, clnt);
			if (result_1 == (int *) NULL) {
				clnt_perror (clnt, "call failed");
			} else {
				adminAccesado = (*result_1);
			}
		} 
		printf("\n=============== MENU ===============\n");
		printf("\n1. Ingresar usuario.");
		printf("\n2. Modificar usuario.");
		printf("\n3. Borrar usuario.");
		printf("\n\nOpcion > ");
		scanf("%d", &opcion);
		switch (opcion) {
			case 0:
				adminAccesado = 0;
			break;
			case 1:
				
				result_2 = ingreso_usuario_1(&ingreso_usuario_1_arg, clnt);
				if (result_2 == (int *) NULL) {
					clnt_perror (clnt, "call failed");
				} else {
					
				}
			break;
			case 2:
				//PARA EL MODIFICAR CAMPOS ESPECIFICOS DE USUARIO SE USA EL OBTENER USUARIO
				
				/*
				result_4 = obtener_usuario_1(&obtener_usuario_1_arg, clnt);
				if (result_4 == (usuario *) NULL) {
					clnt_perror (clnt, "call failed");
				}
				*/
				result_3 = modificar_usuario_1(&modificar_usuario_1_arg, clnt);
				if (result_3 == (int *) NULL) {
					clnt_perror (clnt, "call failed");
				}
			break;
			case 3:			
				result_5 = eliminar_usuario_1(&eliminar_usuario_1_arg, clnt);
				if (result_5 == (int *) NULL) {
					clnt_perror (clnt, "call failed");
				}
			break;
			default:
				printf("\nopcion incorrecta, intente de nuevo");
			break;
		}
		
		
		

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
