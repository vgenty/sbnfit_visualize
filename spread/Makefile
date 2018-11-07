CC=g++
#CXXFLAGS=-g
CXXFLAGS=$(shell root-config --cflags)

INCFLAGS =-I.

LDFLAGS=$(shell root-config --libs)
LDFLAGS+=-L.
LDFLAGS+=-lDict

SOURCES=spread.cxx
OBJECTS=$(SOURCES:.cxx=.o)
EXECUTABLE=spread
DICTSRC=dict.cxx
DICTSO=libDict.so
LINKDEF=LinkDef.h

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(DICTSO)
	$(CC) -Wl,--no-as-needed $^ -o $@ $(INCFLAGS) $(LDFLAGS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

$(DICTSO) : $(DICTSRC)
	$(CC) -shared -fPIC -o$@ $(CXXFLAGS) $^

$(DICTSRC): $(LINKDEF)
	rootcint -f $@ -c $(CXXFLAGS) -p $^

clean:
	rm *.o *.so dict.cxx *.pcm spread
