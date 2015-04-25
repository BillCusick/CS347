#Author: William Cusick
#Makefile for the ticket executables
#I pledge my honor that I have abided by the Stevens Honor System

WORKER = worker_interface.c
USER = user_interface.c
RECEIPT = receipt_printer.c
WEIGH = weigh_bin.c
TALLIER = tallier.c
OBJ1 = $(WORKER:.c=.o)
OBJ2 = $(USER:.c=.o)
OBJ3 = $(RECEIPT:.c=.o)
OBJ4 = $(WEIGH:.c=.o)
OBJ5 = $(TALLIER:.c=.o)
RM = rm -f

all: worker user receipt weigh tallier
worker: $(OBJ1)
user: $(OBJ2)
receipt: $(OBJ3)
weigh: $(OBJ4)
tallier: $(OBJ5)
clean:
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.core
	-$(RM) *.swp
	-$(RM) \#*
fclean: clean
	-$(RM) worker
	-$(RM) user
	-$(RM) receipt
	-$(RM) weigh
re: fclean all
