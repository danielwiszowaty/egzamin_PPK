
 
kompilator=g++
standard=-std=c++14
optymalizacja=-O3
errors=-pedantic-errors
# optymalizacja=
# debug=-g
debug=
profilowanie=-pg
memory=memory/nvwa

.PHONY: clean

__ : main
	./main   

	
main : main.o funkcje.o \
       bool_array.o  file_line_reader.o  mmap_reader_base.o  debug_new.o   mem_pool_base.o     static_mem_pool.o
	$(kompilator) $(standard) $(debug) $(optymalizacja) -pedantic-errors -o $@ $^ 
	            

main.o : main.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors) -c -o $@ $^ 
	            
funkcje.o : funkcje.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors) -c -o $@ $^ 
	
# kompilacja biblioteki do kontroli uzycia pamieci

bool_array.o : $(memory)/bool_array.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors)  -c -o $@ $^ 	

file_line_reader.o : $(memory)/file_line_reader.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors)  -c -o $@ $^ 

mmap_reader_base.o : $(memory)/mmap_reader_base.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors)  -c -o $@ $^ 

debug_new.o : $(memory)/debug_new.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors)  -c -o $@ $^ 
	
static_mem_pool.o : $(memory)/static_mem_pool.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors)  -c -o $@ $^ 		

mem_pool_base.o : $(memory)/mem_pool_base.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors) -c -o $@ $^ 		


########################
		
 
	
clean : 	
	for f in `ls *.o *~ ` ; do  if [ -f $$f ] ; then rm $$f  ; fi;   done;
	if [ -f main ] ; then rm main ; fi ;
	if [ -d html ] ; then rm -r html; fi ;

