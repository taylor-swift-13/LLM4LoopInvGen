
void foo(int x, int y) 
/*@
Require y <= 1000000
Ensure emp
*/
{


	if (y > 0) {
		
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((y@pre > 0 && y@pre <= 1000000) => ((!(x@pre < 100)) => ((y == y@pre)&&(x == x@pre)))) &&
((y@pre > 0 && y@pre <= 1000000) => (y == y@pre))
    */
        while (x < 100) {
            x = x + y;
        }
	}
	
	/*  y <= 0 || (y > 0 && x >= 100)*/

}
