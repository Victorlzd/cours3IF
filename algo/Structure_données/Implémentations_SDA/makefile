#Modele de fichier makefile

RM=rm
ECHO=echo
COMP=g++
EDL=g++
RMFLAGS=-f
ECHOFLAGS=
COMPFLAGS=
EDLFLAGS=
INT=pile.h
REAL=$(INT:.h=.c):main.c
OBJ=$(REAL:.cpp=.o)
EXE=a.out
CLEAN=efface

.PHONY:$CLEAN

$(EXE): $(OBJ)
	$(ECHO) $(ECHOFLAGS) "EDL de demo"
	$(EDL) -o $(EXE) $(OBJ)

%.o: %.c %.h
	$(ECHO) $(ECHOFLAGS) "compil de <$<>"
	$(COMPIL) $(COMPFLAGS) -c $<

$(CLEAN):
	$(RM) $(RMFLAGS) $(EXE) $(OBJ)

