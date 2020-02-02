
 
kompilator=g++
standard=-std=c++14
optymalizacja=-O3
errors=-pedantic-errors
# optymalizacja=
# debug=-g
debug=
profilowanie=-pg

.PHONY: clean

__ : main
	./main   
	            
	            
main : main.o funkcje.o
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors) -o $@ $^ 		            
	            
main.o : main.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors) -c -o $@ $^ 

funkcje.o : funkcje.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors) -c -o $@ $^ 
		
	
profil : main.cpp 
	if [ -f main ]; then rm main ; fi ;
	$(kompilator) $(standard) $(profilowanie) -o main main.cpp 
	./main
	gprof main > profil.txt
	
	
clean : 	
	for f in `ls *.o` ; do  if [ -f $$f ] ; then rm $$f  ; fi;   done;
	if [ -f main ] ; then rm main ; fi ;

