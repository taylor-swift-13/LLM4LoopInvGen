
int unknown();


/*@ requires m > 0;*/
void foo(int m) {
  int a = 0;
  
  int j = 1;
  for(j = 1; j <= m ; j++){
    if(unknown()) 
       a++;
    else
       a--; 
  }
  /*@ assert a>= -m && a <= m;*/
}
