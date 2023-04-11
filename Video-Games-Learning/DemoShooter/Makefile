CC      = gcc

LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer

CFLAGS  =

SOURCES =   main.c \
            draw.c \
            game.c \
            init.c \
            inputs.c \
            log.c

OBJECTS =   $(SOURCES:.c=.o)

EXEC    =   RType

all:        $(EXEC)

$(EXEC):    $(OBJECTS)
			$(CC) -o $(EXEC) $(CFLAGS) $(SOURCES) $(LDFLAGS)

clean:
			rm -f *~ *.o $(EXEC)

mrproper:   clean
			rm -f $(EXEC)

re:         mrproper all


