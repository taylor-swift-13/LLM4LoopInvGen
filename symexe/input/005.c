
void foo(int n, int x, int y) 
/*@
Require n > 0
Ensure emp
*/{
	x = n;
	y = 0;
	

	while (x > 0) {
		x++;
		y--;
	}

	/*@ y == n */

}
