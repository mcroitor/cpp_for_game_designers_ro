CXX 		= g++

BINDIR 		= bin
SRCDIR 		= source
OBJDIR 		= obj

APP			= visual

CXXFLAGS 	= -c -std=c++20
LDFLAGS 	= $(BINDIR)/event.dll

SRC			=
SRC			+= engine.cpp
#SRC			+= event.cpp
SRC			+= main.cpp
SRC			+= painter.cpp
SRC			+= scenario.cpp
SRC			+= scene.cpp

OBJ			=
OBJ			+= $(OBJDIR)/engine.o
#OBJ			+= $(OBJDIR)/event.o
OBJ			+= $(OBJDIR)/main.o
OBJ			+= $(OBJDIR)/painter.o
OBJ			+= $(OBJDIR)/scenario.o
OBJ			+= $(OBJDIR)/scene.o

all: prepare libevent build tests

libevent: $(OBJDIR)/event.o
#	 ar rvs $(BINDIR)/libevent.a $(OBJDIR)/event.o
	$(CXX) $(OBJDIR)/event.o -o $(BINDIR)/event.dll -shared

prepare:
	@echo "create necessary directories"
	mkdir -p $(BINDIR) $(OBJDIR)
	@echo "done directories creation"

build: $(OBJ)
	$(CXX) -o $(BINDIR)/$(APP) $(OBJ) $(LDFLAGS)
	@echo "end build"

$(OBJDIR)/engine.o:
	$(CXX) -o $(OBJDIR)/engine.o $(CXXFLAGS) $(SRCDIR)/engine.cpp

$(OBJDIR)/event.o:
	$(CXX) -o $(OBJDIR)/event.o $(CXXFLAGS) $(SRCDIR)/event.cpp

$(OBJDIR)/main.o:
	$(CXX) -o $(OBJDIR)/main.o $(CXXFLAGS) $(SRCDIR)/main.cpp

$(OBJDIR)/painter.o:
	$(CXX) -o $(OBJDIR)/painter.o $(CXXFLAGS) $(SRCDIR)/painter.cpp

$(OBJDIR)/scenario.o:
	$(CXX) -o $(OBJDIR)/scenario.o $(CXXFLAGS) $(SRCDIR)/scenario.cpp

$(OBJDIR)/scene.o:
	$(CXX) -o $(OBJDIR)/scene.o $(CXXFLAGS) $(SRCDIR)/scene.cpp

tests:
	@echo "start tests"
	@echo "end tests"

clean:
	@echo "remove all object files and apps"
	rm -rf $(OBJDIR)/* $(BINDIR)/*
	@echo "end"

run:
	$(BINDIR)/$(APP)

help:
	@echo "usage:"
	@echo "   make [all]  - compile project"
	@echo "   make clean  - remove object files and apps"
	@echo "   make run    - run app"
	@echo "   make tests  - run tests"
	@echo "   make help   - show this help"