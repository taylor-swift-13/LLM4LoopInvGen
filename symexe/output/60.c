
/*@Inv
  (\at(n, Pre) > 0) => (((c == 0) && (v3 == v3@pre) && (v2 == v2@pre) && (v1 == v1@pre) && (n == n@pre)) || (PLACE_HOLDER_c)) &&
  (\at(n, Pre) > 0) => (v3 == v3@pre) &&
  (\at(n, Pre) > 0) => (v2 == v2@pre) &&
  (\at(n, Pre) > 0) => (v1 == v1@pre) &&
  (\at(n, Pre) > 0) => (n == n@pre)
*/
while (1) {
    if(c != n){
        c = c + 1;
    } else if(c == n) {
        c = 1;
    }
    /*@ assert ((c < 0) && (c > n)) ==> (c == n); */
}
