/*@ requires x >= y  && y >= 0; */
void foo(int x, int y,int z1,int z2,int z3) {

  int i = 0;
  

  
  while (1) {
    if ( i < y )
    {
    i  = (i + 1);

   
    }
    if(i < y){
     /*@ assert (i >= 0 && i < x); */
    }
  }

  
}