
int unknown();

void foo()
{
 int x = 1;
 int y = 1;

 
            
    /* >>> LOOP INVARIANT TO FILL <<< 
       >>> PRECONDITION OF THE LOOP : (y == 1) * (x == 1) <<< */
    
            /*@
          loop invariant  ((y == 1)&&(x == 1)) || (x == y && x >= 1) ;
          loop invariant  ((y == 1)&&(x == 1)) || (y >= 1 && x == y) ;
            */
            while(unknown()) {
   int t1 = x;
   int t2 = y;
   x = t1 + t2;
   y = t1 + t2;
 }
            
 /*@ assert y >= 1 ;*/
}
