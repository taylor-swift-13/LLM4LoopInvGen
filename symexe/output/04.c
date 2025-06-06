
void foo(int x,int y)  
/*@ Require emp 
   Ensure emp
*/ 
{

  x = -50;
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (((y == y@pre)&&(x == -50)) || 
    (x == -50 + (y - y@pre) * (y@pre + y - 1) / 2)) &&
(((y == y@pre)&&(x == -50)) || 
    (y == y@pre + (y - y@pre)))
    */
    
  while( x < 0 ) {
    x = x + y;
    y++;
  }

  /*@ y > 0 */
}

