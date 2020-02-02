
 
 
kompilatorc=gcc
kompilatorcpp=g++
standardc=
standardcpp=-std=c++14
optymalizacja=-O3
errors=-pedantic-errors
# optymalizacja=
# debug=-g
debug=
profilowanie=-pg
memorydetector=valgrind
memoryopt=--leak-check=yes

.PHONY: clean

__ : main
	./main 
#	$(memorydetector) $(memoryopt)  ./main      
	
	
main : main.o funkcje.o  
	$(kompilatorc) $(standardc) $(debug) $(optymalizacja) -pedantic-errors -o $@ $^ 

main.o : main.c
	$(kompilatorc) $(standardc) $(debug) $(optymalizacja) $(errors) -trigraphs -Wvariadic-macros -c -o $@ $^ 
	            
funkcje.o : funkcje.c
	$(kompilatorc) $(standardc) $(debug) $(optymalizacja) $(errors) -c -o $@ $^ 
	
	
cpp : cpp-main
	./cpp-main 
#	$(memorydetector) $(memoryopt) ./cpp-main     
	
	
cpp-main : main.oo funkcje.oo  
	$(kompilatorcpp) $(standardcpp) $(debug) $(optymalizacja) $(errors) -o $@ $^ 
	
main.oo : main.c
	$(kompilatorcpp) $(standardcpp) $(debug) $(optymalizacja) $(errors) -c -o $@ $^ 
	            
funkcje.oo : funkcje.c
	$(kompilatorcpp) $(standardcpp) $(debug) $(optymalizacja) $(errors) -c -o $@ $^ 
			
	
 
########################
		
 
	
clean : 	
	for f in `ls *.o *.oo *~ ` ; do  if [ -f $$f ] ; then rm $$f  ; fi;   done;
	if [ -f main ] ; then rm main ; fi ;
	if [ -f cpp-main ] ; then rm cpp-main ; fi ;
	if [ -d html ] ; then rm -r html; fi ;

