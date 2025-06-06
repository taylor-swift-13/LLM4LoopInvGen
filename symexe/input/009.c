
void foo(int i, int j)
/*@
Require i >= 0 && j >= 0
Ensure emp
*/ {



    int x = i;
    int y = j;
    

    while (x != 0) {
    	x--;
    	y--;
    }

    if (i == j) {
    	/*@ y == 0*/
    }
    
}
