int unknown()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/;

void foo()
 
/*@ Require emp 
   Ensure emp
*/ 
    {
  int x = 0;
  int y = 0;
  int z = 0;
  int k = 0;

  while(unknown())
  {
     if(k%3 == 0){
        x++;
     }
      
     y++;
     z++;
     k = x+y+z;
  }

  /*@  x == y && y == z */
 
}
