void foo(int y)  
/*@ Require emp 
   Ensure emp
*/ 
    {
    int x = 1;
    
    
    
    while (x <= 10) {
        y = 10 - x;
        x = x +1;
    }

    /*@  (y >= 0) */

}