
int unknown1()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/ 
;
int unknown2()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/ ;

void foo()
 
/*@ Require emp 
   Ensure emp
*/ 
    {
  int w = 1;
  int z = 0;
  int x = 0;
  int y = 0;

  
  while(unknown1()) {
	  
    while(unknown2()){
      if(w%2 == 1) x++;
      if(z%2 == 0) y++;
    }
    z = x + y;
    w = z + 1;
  }

   /*@  x == y */
}
