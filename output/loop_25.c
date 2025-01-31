void foo(int v1,int v2,int v3) {
  int c = 0;

   
  
/*@
  loop invariant (1) ==> ( (c == 0)|| ((c > 0) && (c <= 40)) );
  loop invariant v3 == \at(v3, Pre);
  loop invariant v2 == \at(v2, Pre);
  loop invariant v1 == \at(v1, Pre);
*/
while (1) {
  if ( c != 40 )
    {
    c  = c + 1;
    }
  else if ( c == 40 )
    {
    c = 1;
    }
  /*@ assert (c >= 0) && (c <= 40); */
}


 

}