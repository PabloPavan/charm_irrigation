CHARMDIR = /home/pablo/charm
CHARMC = $(CHARMDIR)/bin/charmc $(OPTS)
default: Irrigacao

Irrigacao : main.o Irrigacao.o
	$(CHARMC) -language charm++ -o Irrigacao main.o Irrigacao.o

main.o : main.C main.h main.decl.h main.def.h Irrigacao.decl.h
	$(CHARMC) -o main.o main.C

main.decl.h main.def.h : main.ci
	$(CHARMC) main.ci
Irrigacao.o : Irrigacao.C Irrigacao.h Irrigacao.decl.h Irrigacao.def.h main.decl.h
	$(CHARMC) -o Irrigacao.o Irrigacao.C
Irrigacao.decl.h Irrigacao.def.h : Irrigacao.ci
	$(CHARMC) Irrigacao.ci
clean:
	rm -f main.decl.h main.def.h main.o Irrigacao.decl.h Irrigacao.def.h
	rm Irrigacao.o Irrigacao charmrun