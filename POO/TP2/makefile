#Modele de fichier makefile

RM=rm
ECHO=@echo
COMP=g++
EDL=g++
RMFLAGS=-f
ECHOFLAGS=
COMPFLAGS=-ansi -pedantic -Wall -std=c++11 -g
EDLFLAGS=
INT= Collection.h Trajet.h TrajetSimple.h TrajetCompose.h Catalogue.h
REAL=$(INT:.h=.cpp) main.cpp
OBJ=$(REAL:.cpp=.o)
EXE=demo
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

