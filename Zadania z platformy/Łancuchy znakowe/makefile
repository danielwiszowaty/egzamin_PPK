kompilator=gcc
standard=-std=c11
#optymalizacja=-O3
errors=-pedantic-errors
optymalizacja=
debug=-g
#debug=
profilowanie=-pg
#memory=-fsanitize=leak

.PHONY: clean

__ : main
	./main    
#	valgrind --leak-check=yes ./main
	
	
main : main.o
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(memory) -pedantic-errors -o $@ $^ 
	            

main.o : main.c
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors) $(memory) -c -o $@ $^ 
	

########################
		
 
	
clean : 	
	for f in `ls *.o *~ ` ; do  if [ -f $$f ] ; then rm $$f  ; fi;   done;
	if [ -f main ] ; then rm main ; fi ;
	if [ -d html ] ; then rm -r html; fi ;

