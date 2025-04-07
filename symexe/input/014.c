
int unknown();


void foo()  
/*@ Require m > 0
   Ensure emp
*/ 
    {
  int a = 0;
  int j;
  int m;

  for(j = 1; j <= m ; j++){
    if(unknown()) 
       a++;
    else
       a--; 
  }
  /* assert a>= -m && a <= m;*/
}
