
const MAX_LOGIN = 16;
const MAX_CLAVE = 16;

const MAX_CODIGO = 9;
const MAX_NOMBRES = 20;
const MAX_APELLIDOS = 20;
const MAX_ROL = 15;

struct adminSvdrGU {
	char login[MAX_LOGIN];
	char clave[MAX_CLAVE];
};

struct usuario {
	char codigo[MAX_CODIGO];
	char nombres[MAX_NOMBRES];
	char apellidos[MAX_APELLIDOS];
	char rol[MAX_ROL];
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
		
