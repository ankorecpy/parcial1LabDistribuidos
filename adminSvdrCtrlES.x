
struct adminSvdrCES {
	char * login;
	char * clave;
};

struct usuarios_ingreados {
	char * codigo;
	char * hora;
	char * fecha;
};

typedef adminSvdrCES adminES;
typedef usuarios_ingresados usr_ingresado;

program control_entrada_salida {
	version control_entrada_salida_version {
		bool acceso_admin(adminEs credenciales)=1;
		usr_ingresado * listar_usuarios()=2;
	}=;
}=0x20000004;
		
