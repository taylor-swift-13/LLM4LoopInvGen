void foo(int y)  
/*@ Require emp 
   Ensure emp
*/ 
    {
    int x = 1;
    
    
    while (x <= 100) {
        y = 100 - x;
        x = x +1;
    }

    /*@  (y < 100) */

}