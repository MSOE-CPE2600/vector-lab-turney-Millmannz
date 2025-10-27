CC=gcc
CFLAGS=-c -Wall -Wextra
LDFLAGS= 
SOURCES= input.c vector_math.c vector_helper.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=lab7
all: $(SOURCES) $(EXECUTABLE)
# pull in dependency info for *existing* .o files
-include $(OBJECTS:.o=.d)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@ 
.c.o:
	$(CC) $(CFLAGS) $< -o $@
	$(CC) -MM $< > $*.d
clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *.d