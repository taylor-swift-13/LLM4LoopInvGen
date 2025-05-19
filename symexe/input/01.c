
int unknown()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/ ;

void foo()
 
/*@ Require emp 
   Ensure emp
*/ 
    {
 int x = 1;
 int y = 1;

 while(unknown()) {
   int t1 = x;
   int t2 = y;
   x = t1 + t2;
   y = t1 + t2;
 }
 /*@  y >= 1 */
}

