#Modele de fichier makefile

RM=rm
ECHO=echo
COMP=g++
EDL=g++
RMFLAGS=-f
ECHOFLAGS=
COMPFLAGS=-DMAP -Wall
EDLFLAGS=
INT=Ensemble.h Module.h
REAL=$(INT:.h=.cpp)
OBJ=$(REAL:.cpp=.o)
EXE=a.out
CLEAN=efface

.PHONY:$(CLEAN)

$(EXE): $(OBJ)
	$(ECHO) $(ECHOFLAGS) "EDL de demo"
	$(EDL) -o $(EXE) $(OBJ)

%.o: %.cpp %.h
	$(ECHO) $(ECHOFLAGS) "compil de <$<>"
	$(COMP) $(COMPFLAGS) -c $<

$(CLEAN):
	$(RM) $(RMFLAGS) $(EXE) $(OBJ)

