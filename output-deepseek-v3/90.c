int unknown();

int main(int x,int v1,int v2,int v3) {

    int lock = 1;
    int y = x + 1;

    
/*@
  loop invariant x <= y;
  loop invariant lock == 1 || lock == 0;
  loop invariant v3 == \at(v3, Pre);
  loop invariant v2 == \at(v2, Pre);
  loop invariant v1 == \at(v1, Pre);
  loop invariant x == y ==> lock == 1;
*/
while (x != y) {
    if (unknown()) {
        lock = 1;
        x = y;
    } else {
        lock = 0;
        x = y;
        y = y + 1;
    }
}

    /*@ assert lock == 1;*/
  }