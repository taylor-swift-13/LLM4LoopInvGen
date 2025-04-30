
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
/*@ Inv emp */ /*0*/ 
 for(j = 1; j <= m ; j++){
    if(unknown()) 
       a++;
    else
       a--; 
  }
  /*@ a>= -m && a <= m*/
}
