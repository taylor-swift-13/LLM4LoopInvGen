
/*@Inv
  (\at(n, Pre) > 0) ==> (((c == 0) && (n == \at(n, Pre))) || (c <= \at(n, Pre))) &&
  (\at(n, Pre) > 0) ==> (n == \at(n, Pre))
*/
while (1){
    if(c == n) {
        c = 1;
    }
    else {
        c = c + 1;
    }
    
    /*@ assert (c == n) ==> (c <= n); */
}
