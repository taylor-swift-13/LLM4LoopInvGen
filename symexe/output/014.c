
int unknown()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/;


void foo(int m)  
/*@ Require m > 0
   Ensure emp
*/ 
    {
  int a = 0;

  int j = 1;
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((m@pre > 0) => ((1 <= m@pre) => (((j == 1)&&(a == 0)&&(m == m@pre)) || (-j <= a && a <= j))) ) &&
((m@pre > 0) => ((!(1 <= m@pre)) => ((j == 1)&&(a == 0)&&(m == m@pre)))) &&
((m@pre > 0) => (m == m@pre))
    */
                for(j = 1; j <= m ; j++){
    if(unknown()) 
       a++;
    else
       a--; 
  }
  /*@ a>= -m && a <= m*/
}
