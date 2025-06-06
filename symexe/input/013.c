
int unknown()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/;

void foo(int flag)  
/*@ Require emp 
   Ensure emp
*/ 
    {
   int j = 2; 
   int k = 0;

   
   while(unknown()){ 
     if (flag)
       j = j + 4;
     else {
       j = j + 2;
       k = k + 1;
     }
   }
   /*@  (k != 0 ) => (j == 2 * k + 2 ) */
}
