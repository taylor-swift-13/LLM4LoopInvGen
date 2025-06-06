

void foo(int n, int m)
 
/*@ Require n >=0 && m >=0 && m < n 
   Ensure emp
*/ 
{
 
  int x = 0; 
  int y = m;
 
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while(x < n) {
    x++;
    if(x > m) y++;
  }
  /*@  y==n */
}