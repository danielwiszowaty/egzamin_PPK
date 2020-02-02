
program main
   promien = 12.4
   print *, polekola (promien)
end program main 


function polekola (promien)
   real :: polekola, pi   
   pi = acos (-1.0)
   print *, pi
   polekola = pi * (promien ** 2)
   

end function polekola 
