


void foo(int n) 
/*@
Require 0 < n
Ensure emp
*/{
	int k = 0;
	int i = 0;


	while (i < n) {
		i++;
		k++;
	}
	int j = n;

	while (j > 0) {
		
		j--;
		k--;
        /*@  k>0 */
	}

}