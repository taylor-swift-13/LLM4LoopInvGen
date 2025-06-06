
void foo(int n)
/*@ 
Require emp
Ensure emp
*/
{
  int x=0;
  int y=0;
  int i=0;
  
 
  while(i<n) {
    i++;
    x++;
    if(i%2 == 0) y++;
  }
  
 /*@ (i%2 == 0) => (x==2*y) */
}
