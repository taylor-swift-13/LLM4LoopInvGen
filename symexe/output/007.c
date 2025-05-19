


void foo(int n) 
/*@
Require 0 < n
Ensure emp
*/{
	int k = 0;
	int i = 0;



 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (i < n) {
		i++;
		k++;
	}
	int j = n;


 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    (0 <= j && j <= n) &&
(k == j)
    */
        while (j > 0) {
		j--;
		k--;
        /*@ Inv
    (assert k>0)
    */
	}

}