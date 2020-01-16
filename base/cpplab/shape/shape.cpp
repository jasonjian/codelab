#include "shape.hpp"
#include <codelab.hpp>

extern template void test(codelab::shape::shape);

namespace codelab {
namespace shape {


result process_shape(const shape &shape1, const shape &shape2) {
  puts("process_shape()");
  return result();
}

void test(shape pshape) {

  puts("test()");
  process_shape(circle(), triangle());
  puts("something else");
}
} // namespace shape
} // namespace codelab
