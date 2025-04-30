
/*@Inv
  (\at(x, Pre) != \at(x, Pre) + 1) ==> (((y == \at(x, Pre) + 1) && (lock == 1) && (v3 == \at(v3, Pre)) && (v2 == \at(v2, Pre)) && (v1 == \at(v1, Pre)) && (x == \at(x, Pre))) || (lock == 1)) &&
  (\at(x, Pre) != \at(x, Pre) + 1) ==> (((y == \at(x, Pre) + 1) && (lock == 1) && (v3 == \at(v3, Pre)) && (v2 == \at(v2, Pre)) && (v1 == \at(v1, Pre)) && (x == \at(x, Pre))) || (y >= x)) &&
  (!(\at(x, Pre) != \at(x, Pre) + 1) ==> ((y == \at(x, Pre) + 1) && (lock == 1) && (v3 == \at(v3, Pre)) && (v2 == \at(v2, Pre)) && (v1 == \at(v1, Pre)) && (x == \at(x, Pre))) &&
  v3 == \at(v3, Pre) &&
  v2 == \at(v2, Pre) &&
  v1 == \at(v1, Pre)
*/
while (x != y) {
    if ( 1 ) {
        lock  = 1;
        x  = y;
    } else {
        lock  = 0;
        x  = y;
        y  = y + 1;
    }
}

/*@ assert lock == 1;*/
