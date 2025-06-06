
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
/*@ Inv
    ((0 < n@pre) => (((i == 0) && (y == 0) && (x == 0) && (n == n@pre)) || (x == i))) &&
((0 < n@pre) => (((i == 0) && (y == 0) && (x == 0) && (n == n@pre)) || (y == i/2))) &&
((0 < n@pre) => (((i == 0) && (y == 0) && (x == 0) && (n == n@pre)) || (0 <= i && i <= n))) &&
((!(0 < n@pre)) => ((i == 0) && (y == 0) && (x == 0) && (n == n@pre))) &&
(n == n@pre)
    */
    
  while(i < n) {
    i++;
    x++;
    if(i % 2 == 0) y++;
  }
  
 /*@ (i%2 == 0) => (x==2*y) */
}
