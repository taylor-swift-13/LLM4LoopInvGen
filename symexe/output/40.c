
/*@Inv
  (\at(n, Pre) > 0) ==> (c >= 0 && c <= n + 1) &&
  (\at(n, Pre) > 0) ==> (n == \at(n, Pre))
*/
while (1) {
    if(c > n) {
        c = c + 1;
    }
    else if (c == n){
        c = 1;
    }
    /*@ assert (c != n) ==> (c >= 0); */
}
