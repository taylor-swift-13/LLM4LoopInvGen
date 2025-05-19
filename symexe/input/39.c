int unknown();
void foo(int n)  
/*@ Require  n > 0
   Ensure emp
*/ 
    {

    int c = 0;

    while (unknown()){
        
        if(c == n) {
            c = 1;
        }
        else {
            c = c + 1;
        }
    }
           
    /*@   (c == n) => (c <= n) */
    

  

}