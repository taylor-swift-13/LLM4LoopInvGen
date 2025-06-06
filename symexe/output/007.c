


void foo(int n) 
/*@
Require 0 < n
Ensure emp
*/{
	int k = 0;
	int i = 0;



 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre) => ((0 < n@pre) => (((i == 0)&&(k == 0)&&(n == n@pre)) || (k == i))) ) &&
((0 < n@pre) => ((0 < n@pre) => (((i == 0)&&(k == 0)&&(n == n@pre)) || (i <= n))) ) &&
((0 < n@pre) => ((!(0 < n@pre)) => ((i == 0)&&(k == 0)&&(n == n@pre)))) &&
((0 < n@pre) => (n == n@pre))
    */
    
	while (i < n) {
		i++;
		k++;
	}
	int j = n;


 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    ((i <= j) && (0 < n@pre => (!(0 < n@pre) => i == 0 && k == 0 && j == n@pre) && (0 < n@pre => j == n@pre) && 0 < n@pre) => ((j > 0) => (((n == j)) || (k == j))) ) &&
((i <= j) && (0 < n@pre => (!(0 < n@pre) => i == 0 && k == 0 && j == n@pre) && (0 < n@pre => j == n@pre) && 0 < n@pre) => ((!(j > 0)) => ((n == j)))) &&
((k == i) && (0 < n@pre => 0 < n@pre => i == 0 && k == 0) => ((n@pre > 0) => (((j == n@pre)) || (k == j))) ) &&
((k == i) && (0 < n@pre => 0 < n@pre => i == 0 && k == 0) => ((!(n@pre > 0)) => ((j == n@pre)))) &&
((i >= j && (0 < n@pre => 0 < n@pre => i == 0 && k == 0) => ((n@pre > 0) => (((j == n@pre)) || (k == j))) ) &&
((i >= j && (0 < n@pre => 0 < n@pre => i == 0 && k == 0) => ((!(n@pre > 0)) => ((j == n@pre))))
    */
    
	while (j > 0) {
		j--;
		k--;
        /*@ assert k>0; */
	}

}