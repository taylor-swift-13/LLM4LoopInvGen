

void foo(int n)
{
 int k=1;
 int i=1;
 int j=0;
 
 while(i < n) {
  j = 0;
  while(j < i) {
      k += (i-j);
      j++;
  }
  i++;
 }
 /*@ assert k >= n */;
 
}
