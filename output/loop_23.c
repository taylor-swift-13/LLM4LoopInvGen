void foo() {
  int c = 0;

   
  
/*@
  loop invariant (1) ==> ( (c == 0) || ((c >= 1) && (c <= 40)) );
*/
while (1) {
  if ( c != 40 ) {
    c = c + 1;
  } else if ( c == 40 ) {
    c = 1;
  }

  /*@ assert (c >= 0) && (c <= 40); */
}


 

}
