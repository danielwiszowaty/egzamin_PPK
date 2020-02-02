
 
kompilator=g++
standard=-std=c++14
optymalizacja=-O3
# optymalizacja=
# debug=-g
debug=
profilowanie=-pg


__ : main
	./main   
	            
main : main.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) -pedantic-errors -o $@ $^ 
		
	
profil : main.cpp 
	if [ -f main ]; then rm main ; fi ;
	$(kompilator) $(standard) $(profilowanie) -o main main.cpp 
	./main
	gprof main > profil.txt
	
	
	

