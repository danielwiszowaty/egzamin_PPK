kompilator=clang++
#kompilator=g++
standard=-std=c++14
optymalizacja=-O3
errors=-pedantic-errors
#address=-fsanitize=address
leak=-fsanitize=leak
#debug=-g
debug=

.PHONY: clean

__ : main
	./main   
	
	
main : main.o  
	$(kompilator) $(standard) $(address) $(leak) $(debug) $(optymalizacja) -pedantic-errors -o $@ $^ 
	            

main.o : main.cpp
	$(kompilator) $(standard) $(address) $(leak) $(debug) $(optymalizacja) $(errors) -c -o $@ $^ 
	            
	
clean : 	
	for f in `ls *.o *~ ` ; do  if [ -f $$f ] ; then rm $$f  ; fi;   done;
	if [ -f main ] ; then rm main ; fi ;
	if [ -d html ] ; then rm -r html; fi ;

