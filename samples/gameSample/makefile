CC=/mingw64/bin/g++
CFLAGS=-c -Wall -I./headers
LDFLAGS=-std=c++14

BINDIR=./bin
OBJDIR=./obj
SRCDIR=./src

SRCFILES=${SRCDIR}/direction.cpp ${SRCDIR}/game.cpp ${SRCDIR}/gamecharacter.cpp \
	${SRCDIR}/hero.cpp ${SRCDIR}/map.cpp ${SRCDIR}/main.cpp ${SRCDIR}/monster.cpp ${SRCDIR}/tui.cpp
OBJFILES=${OBJDIR}/direction.o ${OBJDIR}/game.o ${OBJDIR}/gamecharacter.o \
	${OBJDIR}/hero.o ${OBJDIR}/map.o ${OBJDIR}/main.o ${OBJDIR}/monster.o ${OBJDIR}/tui.o

APP=game.exe

all: prepare compile build

prepare:
	@echo "create / recreate dir structure ..."
	mkdir -p ${BINDIR}
	mkdir -p ${OBJDIR}
	@echo "done"

compile: ${OBJFILES}

${OBJDIR}/direction.o:
	${CC} ${CFLAGS} ${SRCDIR}/direction.cpp -o ${OBJDIR}/direction.o

${OBJDIR}/game.o: ${SRCDIR}/direction.cpp
	${CC} ${CFLAGS} ${SRCDIR}/game.cpp -o ${OBJDIR}/game.o

${OBJDIR}/gamecharacter.o: ${SRCDIR}/gamecharacter.cpp
	${CC} ${CFLAGS} ${SRCDIR}/gamecharacter.cpp -o ${OBJDIR}/gamecharacter.o

${OBJDIR}/hero.o: ${SRCDIR}/hero.cpp
	${CC} ${CFLAGS} ${SRCDIR}/hero.cpp -o ${OBJDIR}/hero.o

${OBJDIR}/map.o: ${SRCDIR}/map.cpp
	${CC} ${CFLAGS} ${SRCDIR}/map.cpp -o ${OBJDIR}/map.o

${OBJDIR}/main.o: ${SRCDIR}/main.cpp
	${CC} ${CFLAGS} ${SRCDIR}/main.cpp -o ${OBJDIR}/main.o

${OBJDIR}/monster.o: ${SRCDIR}/monster.cpp
	${CC} ${CFLAGS} ${SRCDIR}/monster.cpp -o ${OBJDIR}/monster.o

${OBJDIR}/tui.o: ${SRCDIR}/tui.cpp
	${CC} ${CFLAGS} ${SRCDIR}/tui.cpp -o ${OBJDIR}/tui.o

build:
	@echo "build..."
	${CC} -o ${BINDIR}/${APP} ${OBJFILES} ${LDFLAGS}
	@echo "build done"

clean:
	rm -rf ${OBJFILES} ${BINDIR}/${APP}

run:
	${BINDIR}/${APP} stage01.txt