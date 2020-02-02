
 
kompilator=gcc
standard=
#optymalizacja=-O3
errors=-pedantic-errors
optymalizacja=
debug=-g
#debug=
profilowanie=-pg
memory=memory/nvwa

.PHONY: clean

__ : main
	./main    
#	valgrind --leak-check=yes ./main
	
	
main : main.o funkcje.o 
	$(kompilator) $(standard) $(debug) $(optymalizacja) -pedantic-errors -o $@ $^ 
	            

main.o : main.c
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors) -c -o $@ $^ 
	            
funkcje.o : funkcje.c
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors) -c -o $@ $^ 
	

########################
		
 
	
clean : 	
	for f in `ls *.o *~ ` ; do  if [ -f $$f ] ; then rm $$f  ; fi;   done;
	if [ -f main ] ; then rm main ; fi ;
	if [ -d html ] ; then rm -r html; fi ;

