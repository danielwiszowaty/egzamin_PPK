
! funkcje zdefiniowane w fortranie 

function sens_tego_wszystkiego () bind(c)
   USE ISO_C_BINDING
   IMPLICIT NONE
   
   integer(C_INT) :: sens_tego_wszystkiego
   
   
   sens_tego_wszystkiego = 42;
   
   return
end function sens_tego_wszystkiego

