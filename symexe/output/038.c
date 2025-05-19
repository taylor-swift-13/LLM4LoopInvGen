
void foo(int n)
/*@ 
Require emp
Ensure emp
*/
{
  int x=0;
  int y=0;
  int i=0;
  
 
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while(i<n) {
    i++;
    x++;
    if(i%2 == 0) y++;
  }
  
 /*@ (i%2 == 0) => (x==2*y) */
}
