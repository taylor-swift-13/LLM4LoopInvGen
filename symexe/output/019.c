
/*@
requires n >= 0;
requires m >= 0;
requires m < n;
*/
void foo(int n, int m)
{
 
  int x = 0; 
  int y = m;
 
  
            
    /* >>> LOOP INVARIANT TO FILL <<< 
       >>> PRECONDITION OF THE LOOP : \at(n, Pre) >= 0 && \at(m, Pre) >= 0 && \at(m, Pre) < \at(n, Pre) && (y == \at(m, Pre)) * (x == 0) * (m == \at(m, Pre)) * (n == \at(n, Pre)) <<< */
    
            /*@
          loop invariant  (\at(n, Pre) >= 0 && \at(m, Pre) >= 0 && \at(m, Pre) < \at(n, Pre)) ==> ((0 < \at(n, Pre)) ==> (((y == \at(m, Pre))&&(x == 0)&&(m == \at(m, Pre))&&(n == \at(n, Pre))) || ((0 < x) && (x <= \at(n, Pre))))) ;
          loop invariant  (\at(n, Pre) >= 0 && \at(m, Pre) >= 0 && \at(m, Pre) < \at(n, Pre)) ==> ((0 < \at(n, Pre)) ==> (((y == \at(m, Pre))&&(x == 0)&&(m == \at(m, Pre))&&(n == \at(n, Pre))) || ((x <= \at(m, Pre) && y == \at(m, Pre)) || (x > \at(m, Pre) && y == x)))) ;
          loop invariant (\at(n, Pre) >= 0 && \at(m, Pre) >= 0 && \at(m, Pre) < \at(n, Pre)) ==> ((!(0 < \at(n, Pre))) ==> ((y == \at(m, Pre))&&(x == 0)&&(m == \at(m, Pre))&&(n == \at(n, Pre))));
          loop invariant (\at(n, Pre) >= 0 && \at(m, Pre) >= 0 && \at(m, Pre) < \at(n, Pre)) ==> (m == \at(m, Pre));
          loop invariant (\at(n, Pre) >= 0 && \at(m, Pre) >= 0 && \at(m, Pre) < \at(n, Pre)) ==> (n == \at(n, Pre));
            */
            while(x < n) {
    x++;
    if(x > m) y++;
  }
            
  /*@ assert y==n; */
}
