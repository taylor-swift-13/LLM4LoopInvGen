
void foo(int n, int x, int y) 
/*@
Require n > 0
Ensure emp
*/{
	x = n;
	y = 0;
	


 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x + y == n) &&
(n == n@pre) &&
(x >= 0)
    */
                while (x > 0) {
		x--;  // decreasing instead of increasing
		y++;  // increasing instead of decreasing
	}

	/*@ y == n */

}
