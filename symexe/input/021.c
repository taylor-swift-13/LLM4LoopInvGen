int unknown()
/*@ Require emp 
   Ensure __return <= INT_MAX && __return > INT_MIN
*/;

void foo(int n,int j,int v)  
/*@ Require n >0 && n < 10
   Ensure emp
*/ 
    {
  int c1 = 4000;
  int c2 = 2000;
  int i = 0;
  int k = 0;
 
  while( i < n ) {
    i++;
    if(unknown() % 2 == 0) {
        v = 0;
    }
    else v = 1;
    
    if( v == 0 ){
      k += c1;
    }else {
      k += c2;
    }
  }
  
  /*@  k > n */
}

