
void foo(int x,int y,int z1,int z2,int z3)
/*@  Require x >= 0 && x <= 2 && y <= 2 && y >= 0
     Ensure emp
*/ {

  
  while (1) {
    
    x  = x + 2;
    y  = y + 2;

  if(x == 4){
    /*@ (y != 0) */
  }

  }



}