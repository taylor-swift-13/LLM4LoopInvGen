
void foo(int x,int y)  
/*@ Require emp 
   Ensure emp
*/ 
{
  int x, y;

  x = -50;
  
  while( x < 0 ) {
	x = x + y;
	y++;
  }
  /*@ y > 0 */
}

