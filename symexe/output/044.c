

void foo(int k, int flag , int __BLAST_NONDET)
 
/*@ Require emp 
   Ensure emp
*/ 
    {
  int i=0;
  int j=0;
  int n;
 

  if (flag == 1){
     n=1;
  } else {
     n=2;
  }

  i=0;
  
 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while ( i <= k) {
    i++;
    j = j + n;
  }
  /*@  (flag == 1) => (j == i)*/
    
	
}
