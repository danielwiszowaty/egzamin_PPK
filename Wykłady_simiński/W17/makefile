
 
kompilatorc=gcc
kompilatorcpp=g++
kompilatorf=gfortran
kompilatorada=gcc
standardc=
standardcpp=-std=c++14
standardf=

#optymalizacja=-O3
#errors=-pedantic-errors
errors=
optymalizacja=
# debug=-g
debug=
profilowanie=-pg
memory=memory/nvwa

.PHONY: clean

__ : main
	./main   
	
	
main : main.oo funkcje-c++.o funkcje-c.o funkcje-fortran.o  \
# debug_new.o static_mem_pool.o mem_pool_base.o bool_array.o static_mem_pool.o
	$(kompilatorcpp) $(standardcpp) $(debug) $(optymalizacja) $(errors) -o $@ $^ 
	            
main.oo : main.cpp
	$(kompilatorcpp) $(standardcpp) $(debug) $(optymalizacja) $(errors) -c -o $@ $^ 
	            
funkcje-c++.o : funkcje-c++.cpp
	$(kompilatorcpp) $(standardcpp) $(debug) $(optymalizacja) $(errors) -c -o $@ $^ 
	
funkcje-fortran.o : funkcje-fortran.f90
	$(kompilatorf) $(standardf) $(debug) $(optymalizacja) $(errors) -ffree-form -c -o $@ $^ 
	
funkcje.aoo : funkcje.adb
	$(kompilatorada) $(standardf) $(debug) $(optymalizacja) $(errors)  -c -o $@ $^ 


funkcje-c.o : funkcje-c.c
	$(kompilatorc) $(standardc) $(debug) $(optymalizacja) $(errors) -c -o $@ $^ 

	

########################
		
 
	
clean : 	
	for f in `ls *.o *.oo *.fo *~ ` ; do  if [ -f $$f ] ; then rm $$f  ; fi;   done;
	if [ -f main ] ; then rm main ; fi ;
	if [ -f c-main ] ; then rm c-main ; fi ;
	if [ -f cpp-main ] ; then rm cpp-main ; fi ;
	if [ -d html ] ; then rm -r html; fi ;

