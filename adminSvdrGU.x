
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
		bool acceso_admin(adminGU credenciales)=1;
		bool ingreso_usuario(usuario usuario_nuevo)=2;
		bool modificar_usuario(usuario usuario_cambio)=3;
		usuario obtener_usuario(string codigo)=4;
		bool eliminar_usuario(string codigo)=5;
	}=1;
}=0x20000003;
		
