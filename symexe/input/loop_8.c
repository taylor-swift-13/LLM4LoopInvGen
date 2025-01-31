
void foo(int x,int y)
/*@  Require x >= 0 && x <= 10 && y <= 10 && y >= 0
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