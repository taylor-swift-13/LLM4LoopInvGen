int unknown();

/*@ requires n > 0; */
void foo(int n,int v1,int v2,int v3)  {

    int c = 0;

    while (unknown()) {
        {
          if (unknown()) {
            if ( c > n )
            {
            c  = c + 1;
            }
          } else {
            if (c == n) 
            {
            c  = 1;
            }
          }
    
        }
    
    }
           
    /*@ assert (c == n) ==> (n > - 1); */
    
 

}