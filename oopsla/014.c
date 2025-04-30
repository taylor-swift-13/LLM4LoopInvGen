
int unknown();


/*@ requires m > 0;*/
void foo() {
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
