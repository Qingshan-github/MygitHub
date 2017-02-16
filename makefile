src=fork.c fork_Pk_vfork.c hell.c

obj=fork fork_Pk_vfork hell
CC=gcc

%.o:%.c
	$(CC) -c $@
