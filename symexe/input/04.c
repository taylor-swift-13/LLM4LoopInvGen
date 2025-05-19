
void foo(int x,int y)  
/*@ Require emp 
   Ensure emp
*/ 
{

  x = -50;
  
  while( x < 0 ) {
	x = x + y;
	y++;
  }

  /*@ y > 0 */
}

