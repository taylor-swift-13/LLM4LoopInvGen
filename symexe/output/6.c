
/*@Inv
  z == z@pre &&
  size == size@pre &&
  v3 == v3@pre &&
  v2 == v2@pre &&
  v1 == v1@pre
*/
while(x < size) {
    x += 1;
    if(z <= y) {
        y = z;
    }
}

/*@ assert (size > 0) ==> (z >= y);  */
