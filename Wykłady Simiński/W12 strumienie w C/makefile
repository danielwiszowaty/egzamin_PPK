
 
kompilator=gcc
standard=
errors=-pedantic-errors
optymalizacja=
#optymalizacja=-O3
#debug=-g
debug=
memorydetector=valgrind
memoryopt=--leak-check=yes

.PHONY: clean

__ : main
	./main
#	$(memorydetector) $(memoryopt) ./main     
	
	
main : main.o    
	$(kompilator) $(standard) $(debug) $(optymalizacja) -pedantic-errors -o $@ $^ 
	            

main.o : main.c
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors) -c -o $@ $^ 
	            
 	
########################
		
 
	
clean : 	
	for f in `ls *.o *~ ` ; do  if [ -f $$f ] ; then rm $$f  ; fi;   done;
	if [ -f main ] ; then rm main ; fi ;
	if [ -d html ] ; then rm -r html; fi ;

