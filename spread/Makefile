CC=g++
#CXXFLAGS=-g
CXXFLAGS=$(shell root-config --cflags)

INCFLAGS =-I.

LDFLAGS1=$(shell root-config --libs)
LDFLAGS2=-L.
LDFLAGS2+=-lDict

SOURCES=spread.cxx
OBJECTS=$(SOURCES:.cxx=.o)
EXECUTABLE=spread
DICTSRC=dict.cxx
DICTSO=libDict.so
LINKDEF=LinkDef.h

all: $(DICTSO) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $^ -o $@ $(INCFLAGS) -Wl,--as-needed $(LDFLAGS1) -Wl,--no-as-needed $(LDFLAGS2)

$(OBJECTS): $(SOURCES)
	$(CC) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

$(DICTSO) : $(DICTSRC)
	$(CC) -shared -fPIC -o$@ $(CXXFLAGS) $^

$(DICTSRC): $(LINKDEF)
	rootcint -f $@ -c $(CXXFLAGS) -p $^

clean:
	rm *.o *.so dict.cxx *.pcm spread
