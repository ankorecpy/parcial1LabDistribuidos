# Creado por: Alejandro Méndez Astudillo.

# ============= CONSIDERACIONES IMPORTANTES ==================
# $1 nombre de interfaz sin extension .x
# $2 nombre de la carpeta con rol de cliente sin '/' al final
# $3 nombre de la carpeta con rol de servidor sin '/' al final
# ============================================================

# Generacion de archivo de cabecera, stubs, etc
rpcgen $1.x

# Copia de archivos del cliente
cp $1.x $2
cp $1.h $2
cp $1_clnt.c $2
cp $1_xdr.c $2

# Generacion de plantilla del cliente
rpcgen -Sc $1.x > $2/cliente.c
chmod 600 $2/cliente.c

# Generacion de makefile del cliente
rpcgen -Sm $1.x > $2/makeC
chmod 600 $2/makeC

# Copia de archivos del servidor 
cp $1.x $3
cp $1.h $3
cp $1_svc.c $3
cp $1_xdr.c $3

# Generacion de plantilla del servidor 
rpcgen -Ss $1.x > $3/servidor.c
chmod 600 $3/servidor.c

# Generacion de makefile del servidor 
rpcgen -Sm $1.x > $3/makeS
chmod 600 $3/makeS

# Eliminacion de copias de archivos ya distribuidos
rm $1.h $1_xdr.c $1_clnt.c $1_svc.c

