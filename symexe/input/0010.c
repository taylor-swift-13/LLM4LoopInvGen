
void foo(int i, int j) 
/*@
Require 0 <= i && i < 1000000 && j >= 0
Ensure emp
*/{


    int x = i;
    int y = j;
    int z = 0;
    

    while (x != 0) {
    	x--;
    	y -= 2;
    	z++;
    }

    if (i == j) {
    	/*@  y == -z*/
    }

}
