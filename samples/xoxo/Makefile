CXX = gcc
CXXFLAGS = -O3 -c
LDFLAGS = -lstdc++

OBJDIR = ./obj
BINDIR = ./bin

APP = xoxo

all: dirs clean compile link

dirs:
	@echo create structure
	mkdir -p ${OBJDIR}
	mkdir -p ${BINDIR}
	@echo done

clean:
	@echo remove obj and exe files
	rm -drf ${OBJDIR}/*
	rm -drf ${BINDIR}/*.exe
	@echo done

compile: ${OBJDIR}/board.o ${OBJDIR}/engine.o ${OBJDIR}/player.o ${OBJDIR}/main.o

${OBJDIR}/board.o:
	${CXX} board.cpp -o${OBJDIR}/board.o ${CXXFLAGS}

${OBJDIR}/engine.o:
	${CXX} engine.cpp -o${OBJDIR}/engine.o ${CXXFLAGS}

${OBJDIR}/player.o:
	${CXX} player.cpp -o${OBJDIR}/player.o ${CXXFLAGS}

${OBJDIR}/main.o:
	${CXX} main.cpp -o${OBJDIR}/main.o ${CXXFLAGS}

link:
	@echo link
	${CXX} ${OBJDIR}/board.o ${OBJDIR}/engine.o ${OBJDIR}/player.o ${OBJDIR}/main.o  \
	${LDFLAGS} -o${BINDIR}/${APP}
	@echo done
