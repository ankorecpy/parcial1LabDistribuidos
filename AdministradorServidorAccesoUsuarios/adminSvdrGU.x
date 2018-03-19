
struct adminSvdrGU {
	char * login;
	char * clave;
};

struct usuario {
	char * codigo;
	char * nombres;
	char * apellidos;
	char * rol;
};

typedef struct adminSvdrGU adminGU;
typedef struct usuario usuario;

program gestion_usuarios {
	version gestion_usuarios_version {
		int acceso_admin(adminGU credenciales)=1;
		int ingreso_usuario(usuario usuario_nuevo)=2;
		int modificar_usuario(usuario usuario_cambio)=3;
		usuario obtener_usuario(string codigo)=4;
		int eliminar_usuario(string codigo)=5;
	}=1;
}=0x20000003;
		
