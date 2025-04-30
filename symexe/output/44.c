
/*@Inv
  n > 0 => n == n@pre
*/
while (1) {
    if(c > n) {
        c = c + 1; // Incrementing c
    }
    else if(c == n){
        c = 1; // Resetting c
    }
       
    /*@ assert (n <= -1) ==> (c != n ); */
}
