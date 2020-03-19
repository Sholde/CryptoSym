# variable

CC = gcc

EXEC = app.exe
ARCHIVE = BOUTON_Nicolas-HADJAB_LYNDA
TAR = tar.gz

SRCDIR = src
OBJDIR = obj
BINDIR = bin

DEPS = $(wildcard $(SRCDIR)/*.h)
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

FLAG = -Wall -g3

# make

all: compil

compil: $(OBJ)
	@ $(CC) -o $(BINDIR)/$(EXEC) $(OBJ)
	@ echo "Linking complete!"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	@ $(CC) -c -o $@ $< $(FLAG)
	@ echo "Compiled "$@" successfully!"

run:
	@ ./$(BINDIR)/$(EXEC)
	

clean:
	@ if [ $(ARCHIVE).$(TAR) ]; then rm -f $(ARCHIVE).$(TAR); echo "Archive removed!"; fi
	@ rm -f $(OBJDIR)/*
	@ echo "Object files removed!"
	@ rm -f $(BINDIR)/*
	@ echo "Executable removed!"
	
package: clean
	@ tar -czvf $(ARCHIVE).$(TAR) *
	@ echo "Archive created!"
	
config:
	@ mkdir src
	@ mkdir bin
	@ mkdir obj
	@ touch src/main.c
