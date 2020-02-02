
 
kompilatorc=gcc
kompilatorcpp=g++
standardc=
standardcpp=-std=c++14
#optymalizacja=-O3
#errors=-pedantic-errors
errors=
optymalizacja=
debug=-g
#debug=
profilowanie=-pg
memorydetector=valgrind
memoryopt=--leak-check=yes

.PHONY: clean

cpp : cpp-main
	./cpp-main 
	$(memorydetector) $(memoryopt) ./cpp-main   
	
c : c-main
	./c-main
	$(memorydetector) $(memoryopt) ./c-main 	
	
cpp-main : main.oo  
	$(kompilatorcpp) $(standardcpp) $(debug) $(optymalizacja) -pedantic-errors -o $@ $^ 
	            
c-main : main.o   
	$(kompilatorc) $(standardc) $(debug) $(optymalizacja) $(errors) -o $@ $^ 


main.oo : main.c
	$(kompilatorcpp) $(standardcpp) $(debug) $(optymalizacja) $(errors) -c -o $@ $^ 

main.o : main.c
	$(kompilatorc) $(standardc) $(debug) $(optymalizacja) $(errors) -c -o $@ $^ 
	            
	
clean : 	
	for f in `ls *.o *.oo *~ ` ; do  if [ -f $$f ] ; then rm $$f  ; fi;   done;
	if [ -f main ] ; then rm main ; fi ;
	if [ -f c-main ] ; then rm c-main ; fi ;
	if [ -f cpp-main ] ; then rm cpp-main ; fi ;
	if [ -d html ] ; then rm -r html; fi ;

