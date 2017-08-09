/*
Here are some class-independent utility methods

*/

#ifndef Utils_H
#define Utils_H

// a 'map'-like method that works with more than just ints
template <class X, class M, class N, class O, class Q>
X mapper(X x, M in_min, N in_max, O out_min, Q out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


#endif
