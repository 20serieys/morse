CXX=g++
CXXFLAGS=-Wall -ggdb 

all : test main

test : tests.o Dico.o texte_morse.o texte_français.o wave_final.o wave.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main : main.o Dico.o texte_morse.o texte_français.o wave_final.o
	$(CXX) $(CXXFLAGS) $^ -o $@ 

main.o : main.cpp Dico.h texte_morse.h texte_français.h wave_final.h
tests.o : tests.cpp Dico.h texte_morse.h texte_français.h wave_final.h
Dico.o : Dico.cpp Dico.h
texte_morse.o : texte_morse.cpp texte_morse.h Dico.h
texte_français.o : texte_français.cpp texte_français.h Dico.h
wave_final.o : wave_final.cpp wave_final.h
wave.o : wave.cpp wave.h

%.o:%.cpp; $(CXX) $(CXXFLAGS) -o $@ -c $<

clean: 
	rm -f main.o Dico.o texte_morse.o texte_français.o wave_final.o tests.o wave.o
