
void foo(int x, int y) 
/*@
Require y <= 1000000
Ensure emp
*/
{


	if (y > 0) {
		
		while (x < 100) {
			x = x + y;
		}
	}
	
	/*  y <= 0 || (y > 0 && x >= 100)*/

}
