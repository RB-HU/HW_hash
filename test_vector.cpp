#include <cstdlib>   // include's C's <stdlib.h>
#include <cstring>   // Does not do our cstring.h this includes C's <string.h>
#include <iostream>  // for C++ printing
#include "./catch.hpp"

#include "./Vector.hpp"

#include <stdexcept>

using namespace std;

TEST_CASE("basic ctor", "[ctor]") {
  Vector v;

  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);

  Vector v2(5);
  REQUIRE(v2.Capacity() == 5);
  REQUIRE(v2.Length() == 0);
  REQUIRE(v2.Data() != nullptr);
}

TEST_CASE("basic push", "[push_back]") {
  Vector v;

  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);

  v.PushBack("testing");
  v.PushBack("omelas");
  v.PushBack("cookie");

  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 3);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "testing");
  REQUIRE(v.Data()[1] == "omelas");
  REQUIRE(v.Data()[2] == "cookie");
}

TEST_CASE("complex push", "[push_back]") {
  // basic push:
  Vector v;

  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);

  v.PushBack("testing");
  v.PushBack("omelas");
  v.PushBack("cookie");

  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 3);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "testing");
  REQUIRE(v.Data()[1] == "omelas");
  REQUIRE(v.Data()[2] == "cookie");

  // additional push tests:
  v.PushBack("hello");
  v.PushBack("world");
  v.PushBack("CIT");
  v.PushBack("5950");
  v.PushBack("Computer");
  v.PushBack("Systems");
  v.PushBack("Programming");

  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 10);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "testing");
  REQUIRE(v.Data()[1] == "omelas");
  REQUIRE(v.Data()[2] == "cookie");
  REQUIRE(v.Data()[3] == "hello");
  REQUIRE(v.Data()[4] == "world");
  REQUIRE(v.Data()[5] == "CIT");
  REQUIRE(v.Data()[6] == "5950");
  REQUIRE(v.Data()[7] == "Computer");
  REQUIRE(v.Data()[8] == "Systems");
  REQUIRE(v.Data()[9] == "Programming");

  v.PushBack("testing");

  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 11);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "testing");
  REQUIRE(v.Data()[1] == "omelas");
  REQUIRE(v.Data()[2] == "cookie");
  REQUIRE(v.Data()[3] == "hello");
  REQUIRE(v.Data()[4] == "world");
  REQUIRE(v.Data()[5] == "CIT");
  REQUIRE(v.Data()[6] == "5950");
  REQUIRE(v.Data()[7] == "Computer");
  REQUIRE(v.Data()[8] == "Systems");
  REQUIRE(v.Data()[9] == "Programming");
  REQUIRE(v.Data()[10] == "testing");

  v.PushBack("testing");
  v.PushBack("adding");
  v.PushBack("elements");
  v.PushBack("to");
  v.PushBack("the");
  v.PushBack("end");
  v.PushBack("of");
  v.PushBack("a");
  v.PushBack("vector");

  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 20);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "testing");
  REQUIRE(v.Data()[1] == "omelas");
  REQUIRE(v.Data()[2] == "cookie");
  REQUIRE(v.Data()[3] == "hello");
  REQUIRE(v.Data()[4] == "world");
  REQUIRE(v.Data()[5] == "CIT");
  REQUIRE(v.Data()[6] == "5950");
  REQUIRE(v.Data()[7] == "Computer");
  REQUIRE(v.Data()[8] == "Systems");
  REQUIRE(v.Data()[9] == "Programming");
  REQUIRE(v.Data()[10] == "testing");
  REQUIRE(v.Data()[11] == "testing");
  REQUIRE(v.Data()[12] == "adding");
  REQUIRE(v.Data()[13] == "elements");
  REQUIRE(v.Data()[14] == "to");
  REQUIRE(v.Data()[15] == "the");
  REQUIRE(v.Data()[16] == "end");
  REQUIRE(v.Data()[17] == "of");
  REQUIRE(v.Data()[18] == "a");
  REQUIRE(v.Data()[19] == "vector");

  v.PushBack("object");

  REQUIRE(v.Capacity() == 40);
  REQUIRE(v.Length() == 21);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "testing");
  REQUIRE(v.Data()[1] == "omelas");
  REQUIRE(v.Data()[2] == "cookie");
  REQUIRE(v.Data()[3] == "hello");
  REQUIRE(v.Data()[4] == "world");
  REQUIRE(v.Data()[5] == "CIT");
  REQUIRE(v.Data()[6] == "5950");
  REQUIRE(v.Data()[7] == "Computer");
  REQUIRE(v.Data()[8] == "Systems");
  REQUIRE(v.Data()[9] == "Programming");
  REQUIRE(v.Data()[10] == "testing");
  REQUIRE(v.Data()[11] == "testing");
  REQUIRE(v.Data()[12] == "adding");
  REQUIRE(v.Data()[13] == "elements");
  REQUIRE(v.Data()[14] == "to");
  REQUIRE(v.Data()[15] == "the");
  REQUIRE(v.Data()[16] == "end");
  REQUIRE(v.Data()[17] == "of");
  REQUIRE(v.Data()[18] == "a");
  REQUIRE(v.Data()[19] == "vector");
  REQUIRE(v.Data()[20] == "object");

  Vector v2(5);
  REQUIRE(v2.Capacity() == 5);
  REQUIRE(v2.Length() == 0);
  REQUIRE(v2.Data() != nullptr);

  v2.PushBack("testing");
  v2.PushBack("omelas");
  v2.PushBack("cookie");

  REQUIRE(v2.Capacity() == 5);
  REQUIRE(v2.Length() == 3);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.Data()[0] == "testing");
  REQUIRE(v2.Data()[1] == "omelas");
  REQUIRE(v2.Data()[2] == "cookie");

  v2.PushBack("hello");
  v2.PushBack("world");
  REQUIRE(v2.Capacity() == 5);
  REQUIRE(v2.Length() == 5);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.Data()[0] == "testing");
  REQUIRE(v2.Data()[1] == "omelas");
  REQUIRE(v2.Data()[2] == "cookie");
  REQUIRE(v2.Data()[3] == "hello");
  REQUIRE(v2.Data()[4] == "world");

  v2.PushBack("CIT");
  REQUIRE(v2.Capacity() == 10);
  REQUIRE(v2.Length() == 6);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.Data()[0] == "testing");
  REQUIRE(v2.Data()[1] == "omelas");
  REQUIRE(v2.Data()[2] == "cookie");
  REQUIRE(v2.Data()[3] == "hello");
  REQUIRE(v2.Data()[4] == "world");
  REQUIRE(v2.Data()[5] == "CIT");

  v2.PushBack("5950");
  v2.PushBack("Computer");
  v2.PushBack("Systems");
  v2.PushBack("Programming");
  REQUIRE(v2.Capacity() == 10);
  REQUIRE(v2.Length() == 10);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.Data()[0] == "testing");
  REQUIRE(v2.Data()[1] == "omelas");
  REQUIRE(v2.Data()[2] == "cookie");
  REQUIRE(v2.Data()[3] == "hello");
  REQUIRE(v2.Data()[4] == "world");
  REQUIRE(v2.Data()[5] == "CIT");
  REQUIRE(v2.Data()[6] == "5950");
  REQUIRE(v2.Data()[7] == "Computer");
  REQUIRE(v2.Data()[8] == "Systems");
  REQUIRE(v2.Data()[9] == "Programming");

  v2.PushBack("testing");
  REQUIRE(v2.Capacity() == 20);
  REQUIRE(v2.Length() == 11);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.Data()[0] == "testing");
  REQUIRE(v2.Data()[1] == "omelas");
  REQUIRE(v2.Data()[2] == "cookie");
  REQUIRE(v2.Data()[3] == "hello");
  REQUIRE(v2.Data()[4] == "world");
  REQUIRE(v2.Data()[5] == "CIT");
  REQUIRE(v2.Data()[6] == "5950");
  REQUIRE(v2.Data()[7] == "Computer");
  REQUIRE(v2.Data()[8] == "Systems");
  REQUIRE(v2.Data()[9] == "Programming");
  REQUIRE(v2.Data()[10] == "testing");

  v2.PushBack("testing");
  v2.PushBack("adding");
  v2.PushBack("elements");
  v2.PushBack("to");
  v2.PushBack("the");
  v2.PushBack("end");
  v2.PushBack("of");
  v2.PushBack("a");
  v2.PushBack("vector");

  REQUIRE(v2.Capacity() == 20);
  REQUIRE(v2.Length() == 20);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.Data()[0] == "testing");
  REQUIRE(v2.Data()[1] == "omelas");
  REQUIRE(v2.Data()[2] == "cookie");
  REQUIRE(v2.Data()[3] == "hello");
  REQUIRE(v2.Data()[4] == "world");
  REQUIRE(v2.Data()[5] == "CIT");
  REQUIRE(v2.Data()[6] == "5950");
  REQUIRE(v2.Data()[7] == "Computer");
  REQUIRE(v2.Data()[8] == "Systems");
  REQUIRE(v2.Data()[9] == "Programming");
  REQUIRE(v2.Data()[10] == "testing");
  REQUIRE(v2.Data()[11] == "testing");
  REQUIRE(v2.Data()[12] == "adding");
  REQUIRE(v2.Data()[13] == "elements");
  REQUIRE(v2.Data()[14] == "to");
  REQUIRE(v2.Data()[15] == "the");
  REQUIRE(v2.Data()[16] == "end");
  REQUIRE(v2.Data()[17] == "of");
  REQUIRE(v2.Data()[18] == "a");
  REQUIRE(v2.Data()[19] == "vector");

  v2.PushBack("object");

  REQUIRE(v2.Capacity() == 40);
  REQUIRE(v2.Length() == 21);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.Data()[0] == "testing");
  REQUIRE(v2.Data()[1] == "omelas");
  REQUIRE(v2.Data()[2] == "cookie");
  REQUIRE(v2.Data()[3] == "hello");
  REQUIRE(v2.Data()[4] == "world");
  REQUIRE(v2.Data()[5] == "CIT");
  REQUIRE(v2.Data()[6] == "5950");
  REQUIRE(v2.Data()[7] == "Computer");
  REQUIRE(v2.Data()[8] == "Systems");
  REQUIRE(v2.Data()[9] == "Programming");
  REQUIRE(v2.Data()[10] == "testing");
  REQUIRE(v2.Data()[11] == "testing");
  REQUIRE(v2.Data()[12] == "adding");
  REQUIRE(v2.Data()[13] == "elements");
  REQUIRE(v2.Data()[14] == "to");
  REQUIRE(v2.Data()[15] == "the");
  REQUIRE(v2.Data()[16] == "end");
  REQUIRE(v2.Data()[17] == "of");
  REQUIRE(v2.Data()[18] == "a");
  REQUIRE(v2.Data()[19] == "vector");
  REQUIRE(v2.Data()[20] == "object");

  Vector v3(3);
  REQUIRE(v3.Capacity() == 3);
  REQUIRE(v3.Length() == 0);
  REQUIRE(v3.Data() != nullptr);

  v3.PushBack("testing");
  v3.PushBack("omelas");
  v3.PushBack("cookie");

  REQUIRE(v3.Capacity() == 3);
  REQUIRE(v3.Length() == 3);
  REQUIRE(v3.Data() != nullptr);
  REQUIRE(v3.Data()[0] == "testing");
  REQUIRE(v3.Data()[1] == "omelas");
  REQUIRE(v3.Data()[2] == "cookie");

  v3.PushBack("hello");
  REQUIRE(v3.Capacity() == 6);
  REQUIRE(v3.Length() == 4);
  REQUIRE(v3.Data() != nullptr);
  REQUIRE(v3.Data()[0] == "testing");
  REQUIRE(v3.Data()[1] == "omelas");
  REQUIRE(v3.Data()[2] == "cookie");
  REQUIRE(v3.Data()[3] == "hello");

  v3.PushBack("world");
  REQUIRE(v3.Capacity() == 6);
  REQUIRE(v3.Length() == 5);
  REQUIRE(v3.Data() != nullptr);
  REQUIRE(v3.Data()[0] == "testing");
  REQUIRE(v3.Data()[1] == "omelas");
  REQUIRE(v3.Data()[2] == "cookie");
  REQUIRE(v3.Data()[3] == "hello");
  REQUIRE(v3.Data()[4] == "world");

  v3.PushBack("CIT");
  REQUIRE(v3.Capacity() == 6);
  REQUIRE(v3.Length() == 6);
  REQUIRE(v3.Data() != nullptr);
  REQUIRE(v3.Data()[0] == "testing");
  REQUIRE(v3.Data()[1] == "omelas");
  REQUIRE(v3.Data()[2] == "cookie");
  REQUIRE(v3.Data()[3] == "hello");
  REQUIRE(v3.Data()[4] == "world");
  REQUIRE(v3.Data()[5] == "CIT");

  v3.PushBack("5950");
  v3.PushBack("Computer");
  v3.PushBack("Systems");
  v3.PushBack("Programming");
  REQUIRE(v3.Capacity() == 12);
  REQUIRE(v3.Length() == 10);
  REQUIRE(v3.Data() != nullptr);
  REQUIRE(v3.Data()[0] == "testing");
  REQUIRE(v3.Data()[1] == "omelas");
  REQUIRE(v3.Data()[2] == "cookie");
  REQUIRE(v3.Data()[3] == "hello");
  REQUIRE(v3.Data()[4] == "world");
  REQUIRE(v3.Data()[5] == "CIT");
  REQUIRE(v3.Data()[6] == "5950");
  REQUIRE(v3.Data()[7] == "Computer");
  REQUIRE(v3.Data()[8] == "Systems");
  REQUIRE(v3.Data()[9] == "Programming");

  v3.PushBack("testing");
  v3.PushBack("testing");
  v3.PushBack("adding");
  v3.PushBack("elements");
  v3.PushBack("to");
  v3.PushBack("the");
  v3.PushBack("end");
  v3.PushBack("of");
  v3.PushBack("a");
  v3.PushBack("vector");
  v3.PushBack("object");

  REQUIRE(v3.Capacity() == 24);
  REQUIRE(v3.Length() == 21);
  REQUIRE(v3.Data() != nullptr);
  REQUIRE(v3.Data()[0] == "testing");
  REQUIRE(v3.Data()[1] == "omelas");
  REQUIRE(v3.Data()[2] == "cookie");
  REQUIRE(v3.Data()[3] == "hello");
  REQUIRE(v3.Data()[4] == "world");
  REQUIRE(v3.Data()[5] == "CIT");
  REQUIRE(v3.Data()[6] == "5950");
  REQUIRE(v3.Data()[7] == "Computer");
  REQUIRE(v3.Data()[8] == "Systems");
  REQUIRE(v3.Data()[9] == "Programming");
  REQUIRE(v3.Data()[10] == "testing");
  REQUIRE(v3.Data()[11] == "testing");
  REQUIRE(v3.Data()[12] == "adding");
  REQUIRE(v3.Data()[13] == "elements");
  REQUIRE(v3.Data()[14] == "to");
  REQUIRE(v3.Data()[15] == "the");
  REQUIRE(v3.Data()[16] == "end");
  REQUIRE(v3.Data()[17] == "of");
  REQUIRE(v3.Data()[18] == "a");
  REQUIRE(v3.Data()[19] == "vector");
  REQUIRE(v3.Data()[20] == "object");

  for (int i = 21; i < 100; i++) {
    std::string test_string = "test";
    test_string += i;
    v3.PushBack(test_string);
  }
  REQUIRE(v3.Capacity() == 192);
  REQUIRE(v3.Length() == 100);
  REQUIRE(v3.Data() != nullptr);
  REQUIRE(v3.Data()[0] == "testing");
  REQUIRE(v3.Data()[1] == "omelas");
  REQUIRE(v3.Data()[2] == "cookie");
  REQUIRE(v3.Data()[3] == "hello");
  REQUIRE(v3.Data()[4] == "world");
  REQUIRE(v3.Data()[5] == "CIT");
  REQUIRE(v3.Data()[6] == "5950");
  REQUIRE(v3.Data()[7] == "Computer");
  REQUIRE(v3.Data()[8] == "Systems");
  REQUIRE(v3.Data()[9] == "Programming");
  REQUIRE(v3.Data()[10] == "testing");
  REQUIRE(v3.Data()[11] == "testing");
  REQUIRE(v3.Data()[12] == "adding");
  REQUIRE(v3.Data()[13] == "elements");
  REQUIRE(v3.Data()[14] == "to");
  REQUIRE(v3.Data()[15] == "the");
  REQUIRE(v3.Data()[16] == "end");
  REQUIRE(v3.Data()[17] == "of");
  REQUIRE(v3.Data()[18] == "a");
  REQUIRE(v3.Data()[19] == "vector");
  REQUIRE(v3.Data()[20] == "object");
  for (int i = 21; i < 100; i++) {
    std::string test_string = "test";
    test_string += i;
    REQUIRE(v3.Data()[i] == test_string);
  }
}

TEST_CASE("basic pop", "[pop_back]") {
  Vector v;

  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);

  v.PushBack("testing");
  v.PushBack("omelas");
  v.PushBack("cookie");
  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 3);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "testing");
  REQUIRE(v.Data()[1] == "omelas");
  REQUIRE(v.Data()[2] == "cookie");

  std::optional<string> just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 2);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "testing");
  REQUIRE(v.Data()[1] == "omelas");
  REQUIRE(just_popped == "cookie");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 1);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "testing");
  REQUIRE(just_popped == "omelas");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(just_popped == "testing");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(just_popped == std::nullopt);
}

TEST_CASE("complex pop", "[pop_back]") {
  Vector v(5);

  REQUIRE(v.Capacity() == 5);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);

  std::optional<string> just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 5);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(just_popped == std::nullopt);

  v.PushBack("testing");
  REQUIRE(v.Capacity() == 5);
  REQUIRE(v.Length() == 1);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "testing");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 5);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(just_popped == "testing");

  v.PushBack("omelas");
  v.PushBack("cookie");
  REQUIRE(v.Capacity() == 5);
  REQUIRE(v.Length() == 2);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "omelas");
  REQUIRE(v.Data()[1] == "cookie");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 5);
  REQUIRE(v.Length() == 1);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(just_popped == "cookie");

  v.PushBack("hello");
  v.PushBack("world");
  v.PushBack("CIT");
  v.PushBack("5950");
  REQUIRE(v.Capacity() == 5);
  REQUIRE(v.Length() == 5);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "omelas");
  REQUIRE(v.Data()[1] == "hello");
  REQUIRE(v.Data()[2] == "world");
  REQUIRE(v.Data()[3] == "CIT");
  REQUIRE(v.Data()[4] == "5950");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 5);
  REQUIRE(v.Length() == 4);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(just_popped == "5950");

  v.PushBack("Computer");
  v.PushBack("Systems");
  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 6);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "omelas");
  REQUIRE(v.Data()[1] == "hello");
  REQUIRE(v.Data()[2] == "world");
  REQUIRE(v.Data()[3] == "CIT");
  REQUIRE(v.Data()[4] == "Computer");
  REQUIRE(v.Data()[5] == "Systems");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 5);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(just_popped == "Systems");

  v.PushBack("Programming");
  v.PushBack("testing");
  v.PushBack("testing");
  v.PushBack("adding");
  v.PushBack("elements");
  v.PushBack("to");
  v.PushBack("the");
  v.PushBack("end");
  v.PushBack("of");
  v.PushBack("a");
  v.PushBack("vector");
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 16);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "omelas");
  REQUIRE(v.Data()[1] == "hello");
  REQUIRE(v.Data()[2] == "world");
  REQUIRE(v.Data()[3] == "CIT");
  REQUIRE(v.Data()[4] == "Computer");
  REQUIRE(v.Data()[5] == "Programming");
  REQUIRE(v.Data()[6] == "testing");
  REQUIRE(v.Data()[7] == "testing");
  REQUIRE(v.Data()[8] == "adding");
  REQUIRE(v.Data()[9] == "elements");
  REQUIRE(v.Data()[10] == "to");
  REQUIRE(v.Data()[11] == "the");
  REQUIRE(v.Data()[12] == "end");
  REQUIRE(v.Data()[13] == "of");
  REQUIRE(v.Data()[14] == "a");
  REQUIRE(v.Data()[15] == "vector");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 15);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "omelas");
  REQUIRE(v.Data()[1] == "hello");
  REQUIRE(v.Data()[2] == "world");
  REQUIRE(v.Data()[3] == "CIT");
  REQUIRE(v.Data()[4] == "Computer");
  REQUIRE(v.Data()[5] == "Programming");
  REQUIRE(v.Data()[6] == "testing");
  REQUIRE(v.Data()[7] == "testing");
  REQUIRE(v.Data()[8] == "adding");
  REQUIRE(v.Data()[9] == "elements");
  REQUIRE(v.Data()[10] == "to");
  REQUIRE(v.Data()[11] == "the");
  REQUIRE(v.Data()[12] == "end");
  REQUIRE(v.Data()[13] == "of");
  REQUIRE(v.Data()[14] == "a");
  REQUIRE(just_popped == "vector");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 14);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "omelas");
  REQUIRE(v.Data()[1] == "hello");
  REQUIRE(v.Data()[2] == "world");
  REQUIRE(v.Data()[3] == "CIT");
  REQUIRE(v.Data()[4] == "Computer");
  REQUIRE(v.Data()[5] == "Programming");
  REQUIRE(v.Data()[6] == "testing");
  REQUIRE(v.Data()[7] == "testing");
  REQUIRE(v.Data()[8] == "adding");
  REQUIRE(v.Data()[9] == "elements");
  REQUIRE(v.Data()[10] == "to");
  REQUIRE(v.Data()[11] == "the");
  REQUIRE(v.Data()[12] == "end");
  REQUIRE(v.Data()[13] == "of");
  REQUIRE(just_popped == "a");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 13);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "omelas");
  REQUIRE(v.Data()[1] == "hello");
  REQUIRE(v.Data()[2] == "world");
  REQUIRE(v.Data()[3] == "CIT");
  REQUIRE(v.Data()[4] == "Computer");
  REQUIRE(v.Data()[5] == "Programming");
  REQUIRE(v.Data()[6] == "testing");
  REQUIRE(v.Data()[7] == "testing");
  REQUIRE(v.Data()[8] == "adding");
  REQUIRE(v.Data()[9] == "elements");
  REQUIRE(v.Data()[10] == "to");
  REQUIRE(v.Data()[11] == "the");
  REQUIRE(v.Data()[12] == "end");
  REQUIRE(just_popped == "of");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 12);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "omelas");
  REQUIRE(v.Data()[1] == "hello");
  REQUIRE(v.Data()[2] == "world");
  REQUIRE(v.Data()[3] == "CIT");
  REQUIRE(v.Data()[4] == "Computer");
  REQUIRE(v.Data()[5] == "Programming");
  REQUIRE(v.Data()[6] == "testing");
  REQUIRE(v.Data()[7] == "testing");
  REQUIRE(v.Data()[8] == "adding");
  REQUIRE(v.Data()[9] == "elements");
  REQUIRE(v.Data()[10] == "to");
  REQUIRE(v.Data()[11] == "the");
  REQUIRE(just_popped == "end");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 11);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "omelas");
  REQUIRE(v.Data()[1] == "hello");
  REQUIRE(v.Data()[2] == "world");
  REQUIRE(v.Data()[3] == "CIT");
  REQUIRE(v.Data()[4] == "Computer");
  REQUIRE(v.Data()[5] == "Programming");
  REQUIRE(v.Data()[6] == "testing");
  REQUIRE(v.Data()[7] == "testing");
  REQUIRE(v.Data()[8] == "adding");
  REQUIRE(v.Data()[9] == "elements");
  REQUIRE(v.Data()[10] == "to");
  REQUIRE(just_popped == "the");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 10);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "omelas");
  REQUIRE(v.Data()[1] == "hello");
  REQUIRE(v.Data()[2] == "world");
  REQUIRE(v.Data()[3] == "CIT");
  REQUIRE(v.Data()[4] == "Computer");
  REQUIRE(v.Data()[5] == "Programming");
  REQUIRE(v.Data()[6] == "testing");
  REQUIRE(v.Data()[7] == "testing");
  REQUIRE(v.Data()[8] == "adding");
  REQUIRE(v.Data()[9] == "elements");
  REQUIRE(just_popped == "to");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 9);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "omelas");
  REQUIRE(v.Data()[1] == "hello");
  REQUIRE(v.Data()[2] == "world");
  REQUIRE(v.Data()[3] == "CIT");
  REQUIRE(v.Data()[4] == "Computer");
  REQUIRE(v.Data()[5] == "Programming");
  REQUIRE(v.Data()[6] == "testing");
  REQUIRE(v.Data()[7] == "testing");
  REQUIRE(v.Data()[8] == "adding");
  REQUIRE(just_popped == "elements");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 8);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "omelas");
  REQUIRE(v.Data()[1] == "hello");
  REQUIRE(v.Data()[2] == "world");
  REQUIRE(v.Data()[3] == "CIT");
  REQUIRE(v.Data()[4] == "Computer");
  REQUIRE(v.Data()[5] == "Programming");
  REQUIRE(v.Data()[6] == "testing");
  REQUIRE(v.Data()[7] == "testing");
  REQUIRE(just_popped == "adding");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 7);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "omelas");
  REQUIRE(v.Data()[1] == "hello");
  REQUIRE(v.Data()[2] == "world");
  REQUIRE(v.Data()[3] == "CIT");
  REQUIRE(v.Data()[4] == "Computer");
  REQUIRE(v.Data()[5] == "Programming");
  REQUIRE(v.Data()[6] == "testing");
  REQUIRE(just_popped == "testing");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 6);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "omelas");
  REQUIRE(v.Data()[1] == "hello");
  REQUIRE(v.Data()[2] == "world");
  REQUIRE(v.Data()[3] == "CIT");
  REQUIRE(v.Data()[4] == "Computer");
  REQUIRE(v.Data()[5] == "Programming");
  REQUIRE(just_popped == "testing");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 5);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "omelas");
  REQUIRE(v.Data()[1] == "hello");
  REQUIRE(v.Data()[2] == "world");
  REQUIRE(v.Data()[3] == "CIT");
  REQUIRE(v.Data()[4] == "Computer");
  REQUIRE(just_popped == "Programming");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 4);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "omelas");
  REQUIRE(v.Data()[1] == "hello");
  REQUIRE(v.Data()[2] == "world");
  REQUIRE(v.Data()[3] == "CIT");
  REQUIRE(just_popped == "Computer");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 3);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "omelas");
  REQUIRE(v.Data()[1] == "hello");
  REQUIRE(v.Data()[2] == "world");
  REQUIRE(just_popped == "CIT");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 2);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "omelas");
  REQUIRE(v.Data()[1] == "hello");
  REQUIRE(just_popped == "world");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 1);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "omelas");
  REQUIRE(just_popped == "hello");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(just_popped == "omelas");

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(just_popped == std::nullopt);

  just_popped = v.PopBack();
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(just_popped == std::nullopt);

  Vector v2(5);

  REQUIRE(v2.Capacity() == 5);
  REQUIRE(v2.Length() == 0);
  REQUIRE(v2.Data() != nullptr);

  v2.PushBack("testing");
  v2.PushBack("omelas");
  REQUIRE(v2.Capacity() == 5);
  REQUIRE(v2.Length() == 2);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.Data()[0] == "testing");
  REQUIRE(v2.Data()[1] == "omelas");

  just_popped = v2.PopBack();
  REQUIRE(v2.Capacity() == 5);
  REQUIRE(v2.Length() == 1);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(just_popped == "omelas");

  just_popped = v2.PopBack();
  REQUIRE(v2.Capacity() == 5);
  REQUIRE(v2.Length() == 0);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(just_popped == "testing");

  just_popped = v2.PopBack();
  REQUIRE(v2.Capacity() == 5);
  REQUIRE(v2.Length() == 0);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(just_popped == std::nullopt);

  v2.PushBack("cookie");
  v2.PushBack("hello");
  v2.PushBack("world");
  v2.PushBack("CIT");
  v2.PushBack("5950");
  v2.PushBack("Computer");
  v2.PushBack("Systems");
  v2.PushBack("Programming");
  REQUIRE(v2.Capacity() == 10);
  REQUIRE(v2.Length() == 8);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.Data()[0] == "cookie");
  REQUIRE(v2.Data()[1] == "hello");
  REQUIRE(v2.Data()[2] == "world");
  REQUIRE(v2.Data()[3] == "CIT");
  REQUIRE(v2.Data()[4] == "5950");
  REQUIRE(v2.Data()[5] == "Computer");
  REQUIRE(v2.Data()[6] == "Systems");
  REQUIRE(v2.Data()[7] == "Programming");

  just_popped = v2.PopBack();
  REQUIRE(v2.Capacity() == 10);
  REQUIRE(v2.Length() == 7);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(just_popped == "Programming");

  just_popped = v2.PopBack();
  REQUIRE(v2.Capacity() == 10);
  REQUIRE(v2.Length() == 6);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(just_popped == "Systems");

  just_popped = v2.PopBack();
  REQUIRE(v2.Capacity() == 10);
  REQUIRE(v2.Length() == 5);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(just_popped == "Computer");

  just_popped = v2.PopBack();
  REQUIRE(v2.Capacity() == 10);
  REQUIRE(v2.Length() == 4);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(just_popped == "5950");

  just_popped = v2.PopBack();
  REQUIRE(v2.Capacity() == 10);
  REQUIRE(v2.Length() == 3);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(just_popped == "CIT");
  REQUIRE(v2.Data()[0] == "cookie");
  REQUIRE(v2.Data()[1] == "hello");
  REQUIRE(v2.Data()[2] == "world");

  v2.PushBack("testing");
  v2.PushBack("testing");
  v2.PushBack("adding");
  v2.PushBack("elements");
  v2.PushBack("to");
  v2.PushBack("the");
  v2.PushBack("end");
  v2.PushBack("of");
  v2.PushBack("a");
  v2.PushBack("vector");
  v2.PushBack("object");
  REQUIRE(v2.Capacity() == 20);
  REQUIRE(v2.Length() == 14);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.Data()[0] == "cookie");
  REQUIRE(v2.Data()[1] == "hello");
  REQUIRE(v2.Data()[2] == "world");
  REQUIRE(v2.Data()[3] == "testing");
  REQUIRE(v2.Data()[4] == "testing");
  REQUIRE(v2.Data()[5] == "adding");
  REQUIRE(v2.Data()[6] == "elements");
  REQUIRE(v2.Data()[7] == "to");
  REQUIRE(v2.Data()[8] == "the");
  REQUIRE(v2.Data()[9] == "end");
  REQUIRE(v2.Data()[10] == "of");
  REQUIRE(v2.Data()[11] == "a");
  REQUIRE(v2.Data()[12] == "vector");
  REQUIRE(v2.Data()[13] == "object");

  just_popped = v2.PopBack();
  REQUIRE(v2.Capacity() == 20);
  REQUIRE(v2.Length() == 13);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(just_popped == "object");

  just_popped = v2.PopBack();
  REQUIRE(v2.Capacity() == 20);
  REQUIRE(v2.Length() == 12);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(just_popped == "vector");

  just_popped = v2.PopBack();
  REQUIRE(v2.Capacity() == 20);
  REQUIRE(v2.Length() == 11);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(just_popped == "a");
  REQUIRE(v2.Data()[0] == "cookie");
  REQUIRE(v2.Data()[1] == "hello");
  REQUIRE(v2.Data()[2] == "world");
  REQUIRE(v2.Data()[3] == "testing");
  REQUIRE(v2.Data()[4] == "testing");
  REQUIRE(v2.Data()[5] == "adding");
  REQUIRE(v2.Data()[6] == "elements");
  REQUIRE(v2.Data()[7] == "to");
  REQUIRE(v2.Data()[8] == "the");
  REQUIRE(v2.Data()[9] == "end");
  REQUIRE(v2.Data()[10] == "of");

  Vector v3(3);
  REQUIRE(v3.Capacity() == 3);
  REQUIRE(v3.Length() == 0);
  REQUIRE(v3.Data() != nullptr);

  v3.PushBack("testing");
  v3.PushBack("omelas");
  v3.PushBack("cookie");
  v3.PushBack("hello");
  v3.PushBack("world");
  v3.PushBack("CIT");
  v3.PushBack("5950");
  v3.PushBack("Computer");
  v3.PushBack("Systems");
  v3.PushBack("Programming");
  v3.PushBack("testing");
  v3.PushBack("testing");
  v3.PushBack("adding");
  v3.PushBack("elements");
  v3.PushBack("to");
  v3.PushBack("the");
  v3.PushBack("end");
  v3.PushBack("of");
  v3.PushBack("a");
  v3.PushBack("vector");
  v3.PushBack("object");
  REQUIRE(v3.Capacity() == 24);
  REQUIRE(v3.Length() == 21);
  REQUIRE(v3.Data() != nullptr);
  REQUIRE(v3.Data()[0] == "testing");
  REQUIRE(v3.Data()[1] == "omelas");
  REQUIRE(v3.Data()[2] == "cookie");
  REQUIRE(v3.Data()[3] == "hello");
  REQUIRE(v3.Data()[4] == "world");
  REQUIRE(v3.Data()[5] == "CIT");
  REQUIRE(v3.Data()[6] == "5950");
  REQUIRE(v3.Data()[7] == "Computer");
  REQUIRE(v3.Data()[8] == "Systems");
  REQUIRE(v3.Data()[9] == "Programming");
  REQUIRE(v3.Data()[10] == "testing");
  REQUIRE(v3.Data()[11] == "testing");
  REQUIRE(v3.Data()[12] == "adding");
  REQUIRE(v3.Data()[13] == "elements");
  REQUIRE(v3.Data()[14] == "to");
  REQUIRE(v3.Data()[15] == "the");
  REQUIRE(v3.Data()[16] == "end");
  REQUIRE(v3.Data()[17] == "of");
  REQUIRE(v3.Data()[18] == "a");
  REQUIRE(v3.Data()[19] == "vector");
  REQUIRE(v3.Data()[20] == "object");

  just_popped = v3.PopBack();
  REQUIRE(v3.Capacity() == 24);
  REQUIRE(v3.Length() == 20);
  REQUIRE(v3.Data() != nullptr);
  REQUIRE(v3.Data()[0] == "testing");
  REQUIRE(v3.Data()[1] == "omelas");
  REQUIRE(v3.Data()[2] == "cookie");
  REQUIRE(v3.Data()[3] == "hello");
  REQUIRE(v3.Data()[4] == "world");
  REQUIRE(v3.Data()[5] == "CIT");
  REQUIRE(v3.Data()[6] == "5950");
  REQUIRE(v3.Data()[7] == "Computer");
  REQUIRE(v3.Data()[8] == "Systems");
  REQUIRE(v3.Data()[9] == "Programming");
  REQUIRE(v3.Data()[10] == "testing");
  REQUIRE(v3.Data()[11] == "testing");
  REQUIRE(v3.Data()[12] == "adding");
  REQUIRE(v3.Data()[13] == "elements");
  REQUIRE(v3.Data()[14] == "to");
  REQUIRE(v3.Data()[15] == "the");
  REQUIRE(v3.Data()[16] == "end");
  REQUIRE(v3.Data()[17] == "of");
  REQUIRE(v3.Data()[18] == "a");
  REQUIRE(v3.Data()[19] == "vector");
  REQUIRE(just_popped == "object");

  for (int i = 20; i < 100; i++) {
    std::string test_string = "test";
    test_string += i;
    v3.PushBack(test_string);
  }
  REQUIRE(v3.Capacity() == 192);
  REQUIRE(v3.Length() == 100);
  REQUIRE(v3.Data() != nullptr);
  REQUIRE(v3.Data()[0] == "testing");
  REQUIRE(v3.Data()[1] == "omelas");
  REQUIRE(v3.Data()[2] == "cookie");
  REQUIRE(v3.Data()[3] == "hello");
  REQUIRE(v3.Data()[4] == "world");
  REQUIRE(v3.Data()[5] == "CIT");
  REQUIRE(v3.Data()[6] == "5950");
  REQUIRE(v3.Data()[7] == "Computer");
  REQUIRE(v3.Data()[8] == "Systems");
  REQUIRE(v3.Data()[9] == "Programming");
  REQUIRE(v3.Data()[10] == "testing");
  REQUIRE(v3.Data()[11] == "testing");
  REQUIRE(v3.Data()[12] == "adding");
  REQUIRE(v3.Data()[13] == "elements");
  REQUIRE(v3.Data()[14] == "to");
  REQUIRE(v3.Data()[15] == "the");
  REQUIRE(v3.Data()[16] == "end");
  REQUIRE(v3.Data()[17] == "of");
  REQUIRE(v3.Data()[18] == "a");
  REQUIRE(v3.Data()[19] == "vector");
  for (int i = 20; i < 100; i++) {
    std::string test_string = "test";
    test_string += i;
    REQUIRE(v3.Data()[i] == test_string);
  }

  for (int i = 99; i >= 20; i--) {
    just_popped = v3.PopBack();
    std::string test_string = "test";
    test_string += i;
    REQUIRE(just_popped == test_string);
  }
  REQUIRE(v3.Capacity() == 192);
  REQUIRE(v3.Length() == 20);
  REQUIRE(v3.Data() != nullptr);
  REQUIRE(v3.Data()[0] == "testing");
  REQUIRE(v3.Data()[1] == "omelas");
  REQUIRE(v3.Data()[2] == "cookie");
  REQUIRE(v3.Data()[3] == "hello");
  REQUIRE(v3.Data()[4] == "world");
  REQUIRE(v3.Data()[5] == "CIT");
  REQUIRE(v3.Data()[6] == "5950");
  REQUIRE(v3.Data()[7] == "Computer");
  REQUIRE(v3.Data()[8] == "Systems");
  REQUIRE(v3.Data()[9] == "Programming");
  REQUIRE(v3.Data()[10] == "testing");
  REQUIRE(v3.Data()[11] == "testing");
  REQUIRE(v3.Data()[12] == "adding");
  REQUIRE(v3.Data()[13] == "elements");
  REQUIRE(v3.Data()[14] == "to");
  REQUIRE(v3.Data()[15] == "the");
  REQUIRE(v3.Data()[16] == "end");
  REQUIRE(v3.Data()[17] == "of");
  REQUIRE(v3.Data()[18] == "a");
  REQUIRE(v3.Data()[19] == "vector");

  for (int i = 19; i > 0; i--) {
    just_popped = v3.PopBack();
  }
  REQUIRE(v3.Capacity() == 192);
  REQUIRE(v3.Length() == 1);
  REQUIRE(v3.Data() != nullptr);
  REQUIRE(v3.Data()[0] == "testing");
  REQUIRE(just_popped == "omelas");

  just_popped = v3.PopBack();
  REQUIRE(v3.Capacity() == 192);
  REQUIRE(v3.Length() == 0);
  REQUIRE(v3.Data() != nullptr);
  REQUIRE(just_popped == "testing");

  just_popped = v3.PopBack();
  REQUIRE(v3.Capacity() == 192);
  REQUIRE(v3.Length() == 0);
  REQUIRE(v3.Data() != nullptr);
  REQUIRE(just_popped == std::nullopt);
}

TEST_CASE("basic operator[]", "[operator]") {
  Vector v;

  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);

  v.PushBack("testing");
  v.PushBack("omelas");
  v.PushBack("cookie");

  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 3);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v[0] == "testing");
  REQUIRE(v[1] == "omelas");
  REQUIRE(v[2] == "cookie");

  REQUIRE_THROWS_AS(v.At(4), out_of_range);
  REQUIRE_THROWS_AS(v.At(100), out_of_range);
  REQUIRE_THROWS_AS(v.At(-1), out_of_range);
}

TEST_CASE("complex operator[]", "[operator]") {
  Vector v;

  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);
  REQUIRE_THROWS_AS(v[0], out_of_range);
  REQUIRE_THROWS_AS(v[100], out_of_range);
  REQUIRE_THROWS_AS(v[-1], out_of_range);

  v.PushBack("testing");
  v.PushBack("omelas");
  v.PushBack("cookie");
  v.PushBack("hello");
  v.PushBack("world");
  v.PushBack("CIT");
  v.PushBack("5950");
  v.PushBack("Computer");
  v.PushBack("Systems");
  v.PushBack("Programming");
  v.PushBack("testing");
  v.PushBack("testing");
  v.PushBack("adding");
  v.PushBack("elements");
  v.PushBack("to");
  v.PushBack("the");
  v.PushBack("end");
  v.PushBack("of");
  v.PushBack("a");
  v.PushBack("vector");

  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 20);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v[0] == "testing");
  REQUIRE(v[1] == "omelas");
  REQUIRE(v[2] == "cookie");
  REQUIRE(v[3] == "hello");
  REQUIRE(v[4] == "world");
  REQUIRE(v[5] == "CIT");
  REQUIRE(v[6] == "5950");
  REQUIRE(v[7] == "Computer");
  REQUIRE(v[8] == "Systems");
  REQUIRE(v[9] == "Programming");
  REQUIRE(v[10] == "testing");
  REQUIRE(v[11] == "testing");
  REQUIRE(v[12] == "adding");
  REQUIRE(v[13] == "elements");
  REQUIRE(v[14] == "to");
  REQUIRE(v[15] == "the");
  REQUIRE(v[16] == "end");
  REQUIRE(v[17] == "of");
  REQUIRE(v[18] == "a");
  REQUIRE(v[19] == "vector");
  REQUIRE_THROWS_AS(v[20], out_of_range);
  REQUIRE_THROWS_AS(v[100], out_of_range);
  REQUIRE_THROWS_AS(v[-1], out_of_range);

  v.PopBack();
  REQUIRE_THROWS_AS(v[19], out_of_range);

  Vector v2(5);

  REQUIRE(v2.Capacity() == 5);
  REQUIRE(v2.Length() == 0);
  REQUIRE(v2.Data() != nullptr);

  v2.PushBack("testing");
  v2.PushBack("omelas");
  v2.PushBack("cookie");
  v2.PushBack("hello");
  v2.PushBack("world");
  REQUIRE(v2.Capacity() == 5);
  REQUIRE(v2.Length() == 5);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2[0] == "testing");
  REQUIRE(v2[1] == "omelas");
  REQUIRE(v2[2] == "cookie");
  REQUIRE(v2[3] == "hello");
  REQUIRE(v2[4] == "world");
  REQUIRE_THROWS_AS(v2[5], out_of_range);
  REQUIRE_THROWS_AS(v2[100], out_of_range);
  REQUIRE_THROWS_AS(v2[-1], out_of_range);

  v2.PushBack("CIT");
  REQUIRE(v2.Capacity() == 10);
  REQUIRE(v2.Length() == 6);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2[0] == "testing");
  REQUIRE(v2[1] == "omelas");
  REQUIRE(v2[2] == "cookie");
  REQUIRE(v2[3] == "hello");
  REQUIRE(v2[4] == "world");
  REQUIRE(v2[5] == "CIT");

  v2.PushBack("5950");
  v2.PushBack("Computer");
  v2.PushBack("Systems");
  v2.PushBack("Programming");
  v2.PushBack("testing");
  REQUIRE(v2.Capacity() == 20);
  REQUIRE(v2.Length() == 11);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2[0] == "testing");
  REQUIRE(v2[1] == "omelas");
  REQUIRE(v2[2] == "cookie");
  REQUIRE(v2[3] == "hello");
  REQUIRE(v2[4] == "world");
  REQUIRE(v2[5] == "CIT");
  REQUIRE(v2[6] == "5950");
  REQUIRE(v2[7] == "Computer");
  REQUIRE(v2[8] == "Systems");
  REQUIRE(v2[9] == "Programming");
  REQUIRE(v2[10] == "testing");
  REQUIRE_THROWS_AS(v2[11], out_of_range);
  REQUIRE_THROWS_AS(v2[100], out_of_range);
  REQUIRE_THROWS_AS(v2[-1], out_of_range);

  for (int i = 0; i < 10; i++) {
    v2.PopBack();
  }
  REQUIRE(v2.Capacity() == 20);
  REQUIRE(v2.Length() == 1);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2[0] == "testing");
  REQUIRE_THROWS_AS(v2[1], out_of_range);
  REQUIRE_THROWS_AS(v2[100], out_of_range);
  REQUIRE_THROWS_AS(v2[-1], out_of_range);

  v2.PopBack();
  REQUIRE(v2.Capacity() == 20);
  REQUIRE(v2.Length() == 0);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE_THROWS_AS(v2[0], out_of_range);
  REQUIRE_THROWS_AS(v[100], out_of_range);
  REQUIRE_THROWS_AS(v[-1], out_of_range);
}

TEST_CASE("basic at", "[at]") {
  Vector v;

  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);

  v.PushBack("testing");
  v.PushBack("omelas");
  v.PushBack("cookie");

  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 3);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.At(0) == "testing");
  REQUIRE(v.At(1) == "omelas");
  REQUIRE(v.At(2) == "cookie");

  REQUIRE_THROWS_AS(v.At(4), out_of_range);
  REQUIRE_THROWS_AS(v.At(100), out_of_range);
  REQUIRE_THROWS_AS(v.At(-1), out_of_range);
}

TEST_CASE("complex at", "[at]") {
  Vector v;

  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);
  REQUIRE_THROWS_AS(v.At(0), out_of_range);
  REQUIRE_THROWS_AS(v.At(100), out_of_range);
  REQUIRE_THROWS_AS(v.At(-1), out_of_range);

  v.PushBack("testing");
  v.PushBack("omelas");
  v.PushBack("cookie");
  v.PushBack("hello");
  v.PushBack("world");
  v.PushBack("CIT");
  v.PushBack("5950");
  v.PushBack("Computer");
  v.PushBack("Systems");
  v.PushBack("Programming");
  v.PushBack("testing");
  v.PushBack("testing");
  v.PushBack("adding");
  v.PushBack("elements");
  v.PushBack("to");
  v.PushBack("the");
  v.PushBack("end");
  v.PushBack("of");
  v.PushBack("a");
  v.PushBack("vector");

  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 20);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.At(0) == "testing");
  REQUIRE(v.At(1) == "omelas");
  REQUIRE(v.At(2) == "cookie");
  REQUIRE(v.At(3) == "hello");
  REQUIRE(v.At(4) == "world");
  REQUIRE(v.At(5) == "CIT");
  REQUIRE(v.At(6) == "5950");
  REQUIRE(v.At(7) == "Computer");
  REQUIRE(v.At(8) == "Systems");
  REQUIRE(v.At(9) == "Programming");
  REQUIRE(v.At(10) == "testing");
  REQUIRE(v.At(11) == "testing");
  REQUIRE(v.At(12) == "adding");
  REQUIRE(v.At(13) == "elements");
  REQUIRE(v.At(14) == "to");
  REQUIRE(v.At(15) == "the");
  REQUIRE(v.At(16) == "end");
  REQUIRE(v.At(17) == "of");
  REQUIRE(v.At(18) == "a");
  REQUIRE(v.At(19) == "vector");
  REQUIRE_THROWS_AS(v.At(20), out_of_range);
  REQUIRE_THROWS_AS(v.At(100), out_of_range);
  REQUIRE_THROWS_AS(v.At(-1), out_of_range);

  v.PopBack();
  REQUIRE_THROWS_AS(v.At(19), out_of_range);

  Vector v2(5);

  REQUIRE(v2.Capacity() == 5);
  REQUIRE(v2.Length() == 0);
  REQUIRE(v2.Data() != nullptr);

  v2.PushBack("testing");
  v2.PushBack("omelas");
  v2.PushBack("cookie");
  v2.PushBack("hello");
  v2.PushBack("world");
  REQUIRE(v2.Capacity() == 5);
  REQUIRE(v2.Length() == 5);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.At(0) == "testing");
  REQUIRE(v2.At(1) == "omelas");
  REQUIRE(v2.At(2) == "cookie");
  REQUIRE(v2.At(3) == "hello");
  REQUIRE(v2.At(4) == "world");
  REQUIRE_THROWS_AS(v2.At(5), out_of_range);
  REQUIRE_THROWS_AS(v2.At(100), out_of_range);
  REQUIRE_THROWS_AS(v2.At(-1), out_of_range);

  v2.PushBack("CIT");
  REQUIRE(v2.Capacity() == 10);
  REQUIRE(v2.Length() == 6);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.At(0) == "testing");
  REQUIRE(v2.At(1) == "omelas");
  REQUIRE(v2.At(2) == "cookie");
  REQUIRE(v2.At(3) == "hello");
  REQUIRE(v2.At(4) == "world");
  REQUIRE(v2.At(5) == "CIT");

  v2.PushBack("5950");
  v2.PushBack("Computer");
  v2.PushBack("Systems");
  v2.PushBack("Programming");
  v2.PushBack("testing");
  REQUIRE(v2.Capacity() == 20);
  REQUIRE(v2.Length() == 11);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.At(0) == "testing");
  REQUIRE(v2.At(1) == "omelas");
  REQUIRE(v2.At(2) == "cookie");
  REQUIRE(v2.At(3) == "hello");
  REQUIRE(v2.At(4) == "world");
  REQUIRE(v2.At(5) == "CIT");
  REQUIRE(v2.At(6) == "5950");
  REQUIRE(v2.At(7) == "Computer");
  REQUIRE(v2.At(8) == "Systems");
  REQUIRE(v2.At(9) == "Programming");
  REQUIRE(v2.At(10) == "testing");
  REQUIRE_THROWS_AS(v2.At(11), out_of_range);
  REQUIRE_THROWS_AS(v2.At(100), out_of_range);
  REQUIRE_THROWS_AS(v2.At(-1), out_of_range);

  for (int i = 0; i < 10; i++) {
    v2.PopBack();
  }
  REQUIRE(v2.Capacity() == 20);
  REQUIRE(v2.Length() == 1);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.At(0) == "testing");
  REQUIRE_THROWS_AS(v2.At(1), out_of_range);
  REQUIRE_THROWS_AS(v2.At(100), out_of_range);
  REQUIRE_THROWS_AS(v2.At(-1), out_of_range);

  v2.PopBack();
  REQUIRE(v2.Capacity() == 20);
  REQUIRE(v2.Length() == 0);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE_THROWS_AS(v2.At(0), out_of_range);
  REQUIRE_THROWS_AS(v.At(100), out_of_range);
  REQUIRE_THROWS_AS(v.At(-1), out_of_range);
}

TEST_CASE("basic copy constructor", "[copy_ctor]") {
  Vector original;

  // Empty copy
  Vector empty_copy(original);
  REQUIRE(empty_copy.Length() == original.Length());
  REQUIRE(empty_copy.Capacity() == original.Capacity());

  original.PushBack("alpha");
  original.PushBack("beta");
  original.PushBack("gamma");

  // Copy with values
  Vector copy_of_original(original);
  REQUIRE(copy_of_original.Length() == original.Length());
  REQUIRE(copy_of_original.Capacity() >= original.Length());
  REQUIRE(copy_of_original.At(0) == original.At(0));
  REQUIRE(copy_of_original.At(1) == original.At(1));
  REQUIRE(copy_of_original.At(2) == original.At(2));

  // Memory independence
  REQUIRE(original.Data() != copy_of_original.Data());

  // Deep copy
  original.PushBack("delta");
  REQUIRE(original.Length() == 4);
  REQUIRE(copy_of_original.Length() == 3);
  original.PopBack();
  original.PopBack();
  REQUIRE(copy_of_original.At(2) == "gamma");
  REQUIRE(copy_of_original.Length() == 3);
  copy_of_original.At(0) = "changed";
  REQUIRE(copy_of_original.At(0) != original.At(0));
  REQUIRE(copy_of_original.At(0) == "changed");
  REQUIRE(original.At(0) == "alpha");

  // Copy vector with initial capacity
  Vector preallocated(20);
  preallocated.PushBack("hello");
  preallocated.PushBack("world");
  REQUIRE(preallocated.Length() == 2);
  REQUIRE(preallocated.Capacity() == 20);
  Vector copy_of_preallocated(preallocated);
  REQUIRE(copy_of_preallocated.Length() == 2);
  REQUIRE(copy_of_preallocated.Capacity() == 20);
  REQUIRE(copy_of_preallocated.At(0) == "hello");
  REQUIRE(copy_of_preallocated.At(1) == "world");
  REQUIRE(copy_of_preallocated.Data() != preallocated.Data());

  // Test reserve with copy
  original.Reserve(10);
  Vector reserved_copy(original);
  REQUIRE(reserved_copy.Capacity() >= 10);
  REQUIRE(reserved_copy.Length() == original.Length());

  // Larger vector copy
  Vector large_vec;
  for (size_t i = 0; i < 50; ++i) {
    large_vec.PushBack("Item" + std::to_string(i));
  }
  Vector large_copy(large_vec);
  REQUIRE(large_copy.Length() == 50);
  bool identical = true;
  for (size_t i = 0; i < 50; ++i) {
    if (large_copy.At(i) != large_vec.At(i)) {
      identical = false;
      break;
    }
  }
  REQUIRE(identical == true);
}

TEST_CASE("complex copy constructor", "[copy_ctor]") {
  Vector original;
  for (size_t i = 0; i < 100; ++i) {
    original.PushBack("Item" + std::to_string(i));
  }

  // Create three chained copies
  Vector copy1(original);
  Vector copy2(copy1);
  Vector copy3(copy2);

  // Modify original
  original.PushBack("gamma");
  REQUIRE(original.Length() == 101);
  REQUIRE(copy1.Length() == 100);
  REQUIRE(copy2.Length() == 100);
  REQUIRE(copy3.Length() == 100);

  // Modify copy1
  copy1.PushBack("delta");
  REQUIRE(copy1.Length() == 101);
  REQUIRE(copy1.At(100) == "delta");
  REQUIRE(copy2.Length() == 100);
  REQUIRE(copy3.Length() == 100);
  REQUIRE(original.Length() == 101);

  // Modify copy2
  copy2.At(0) = "changed";
  REQUIRE(copy2.At(0) == "changed");
  REQUIRE(copy1.At(0) == "Item0");
  REQUIRE(copy3.At(0) == "Item0");
  REQUIRE(original.At(0) == "Item0");

  // Modify copy3
  copy3.PushBack("epsilon");
  REQUIRE(copy3.Length() == 101);
  REQUIRE(copy3.At(100) == "epsilon");
  REQUIRE(copy2.Length() == 100);
  REQUIRE(copy1.Length() == 101);
  REQUIRE(original.Length() == 101);

  // Verify original and copies remain independent
  REQUIRE(copy1.Data() != original.Data());
  REQUIRE(copy2.Data() != copy1.Data());
  REQUIRE(copy3.Data() != copy2.Data());
  REQUIRE(copy3.Data() != original.Data());

  // Complex Strings
  Vector large_vec;
  for (size_t i = 0; i < 100; ++i) {
    std::string large_string(1000, 'A' + (i % 26));
    large_vec.PushBack(large_string);
  }
  Vector large_copy(large_vec);
  REQUIRE(large_copy.Data() != large_vec.Data());
  REQUIRE(large_copy.Length() == large_vec.Length());

  bool identical = true;
  for (size_t i = 0; i < large_vec.Length(); ++i) {
    if (large_copy.At(i) != large_vec.At(i)) {
      identical = false;
      break;
    }
  }
  REQUIRE(identical == true);

  // Copy a large vector with initial capacity
  Vector large_preallocated(200);
  for (size_t i = 0; i < 150; ++i) {
    large_preallocated.PushBack("BigItem" + std::to_string(i));
  }

  REQUIRE(large_preallocated.Length() == 150);
  REQUIRE(large_preallocated.Capacity() == 200);
  Vector large_preallocated_copy(large_preallocated);
  REQUIRE(large_preallocated_copy.Length() == 150);
  REQUIRE(large_preallocated_copy.Capacity() == 200);
  identical = true;
  for (size_t i = 0; i < 150; ++i) {
    if (large_preallocated_copy.At(i) != large_preallocated.At(i)) {
      identical = false;
    }
  }
  REQUIRE(identical == true);
  REQUIRE(large_preallocated_copy.Data() != large_preallocated.Data());
}

TEST_CASE("basic erase", "[erase]") {
  Vector v;

  // Erase from an empty vector
  REQUIRE_THROWS(v.Erase(0));
  REQUIRE_THROWS(v.Erase(1));

  v.PushBack("first");
  v.PushBack("second");
  v.PushBack("third");
  v.PushBack("fourth");

  // Erase from the front
  size_t returned_index = v.Erase(0);
  REQUIRE(returned_index == 0);
  REQUIRE(v.Length() == 3);
  REQUIRE(v.At(0) == "second");
  REQUIRE(v.At(1) == "third");
  REQUIRE(v.At(2) == "fourth");

  // Erase from the middle
  returned_index = v.Erase(1);
  REQUIRE(returned_index == 1);
  REQUIRE(v.Length() == 2);
  REQUIRE(v.At(0) == "second");
  REQUIRE(v.At(1) == "fourth");

  // Erase the last element
  returned_index = v.Erase(1);
  REQUIRE(returned_index == 0);
  REQUIRE(v.Length() == 1);
  REQUIRE(v.At(0) == "second");

  // Erase the last remaining element
  returned_index = v.Erase(0);
  REQUIRE(v.Length() == 0);

  // Attempt to erase from an empty vector again
  REQUIRE_THROWS(v.Erase(0));

  // Refill and erase from the middle multiple times
  v.PushBack("alpha");
  v.PushBack("beta");
  v.PushBack("gamma");
  v.PushBack("delta");

  returned_index = v.Erase(2);  // Erase "gamma"
  REQUIRE(returned_index == 2);
  REQUIRE(v.Length() == 3);
  REQUIRE(v.At(2) == "delta");

  returned_index = v.Erase(1);  // Erase "beta"
  REQUIRE(returned_index == 1);
  REQUIRE(v.Length() == 2);
  REQUIRE(v.At(0) == "alpha");
  REQUIRE(v.At(1) == "delta");

  // Out-of-bounds erase
  REQUIRE_THROWS(v.Erase(2));
  REQUIRE_THROWS(v.Erase(-2));
  REQUIRE_THROWS(v.Erase(100));

  // Erase all elements one by one
  returned_index = v.Erase(0);  // Erase "alpha"
  REQUIRE(returned_index == 0);
  REQUIRE(v.Length() == 1);
  REQUIRE(v.At(0) == "delta");

  returned_index = v.Erase(0);  // Erase "delta"
  REQUIRE(v.Length() == 0);
  REQUIRE_THROWS(v.Erase(0));

  // Erase in a preallocated vector
  Vector preallocated(5);
  REQUIRE(preallocated.Capacity() == 5);
  REQUIRE(preallocated.Length() == 0);
  REQUIRE_THROWS(preallocated.Erase(0));
  REQUIRE_THROWS(preallocated.Erase(4));

  preallocated.PushBack("alpha");
  preallocated.PushBack("beta");
  preallocated.PushBack("gamma");
  REQUIRE(preallocated.Capacity() == 5);
  REQUIRE(preallocated.Length() == 3);

  // Erase middle element
  returned_index = preallocated.Erase(1);
  REQUIRE(returned_index == 1);
  REQUIRE(preallocated.Length() == 2);
  REQUIRE(preallocated.At(0) == "alpha");
  REQUIRE(preallocated.At(1) == "gamma");
  REQUIRE_THROWS(preallocated.At(2));  // out of bounds

  // Erase last element
  returned_index = preallocated.Erase(1);  // remove "gamma"
  REQUIRE(returned_index == 0);
  REQUIRE(preallocated.Length() == 1);
  REQUIRE(preallocated.At(0) == "alpha");

  // Erase only remaining element
  returned_index = preallocated.Erase(0);  // remove "alpha"
  REQUIRE(preallocated.Length() == 0);
  REQUIRE_THROWS(preallocated.Erase(0));
}

TEST_CASE("complex erase", "[erase]") {
  Vector v;
  for (int i = 0; i < 10; i++) {
    std::string item = "Item" + std::to_string(i);
    v.PushBack(item);
  }
  REQUIRE(v.Length() == 10);
  REQUIRE(v.Capacity() == 10);

  // Erase last element repeatedly
  for (int i = 9; i >= 0; --i) {
    size_t returned_index = v.Erase(i);
    REQUIRE(returned_index == i - 1);
    REQUIRE(v.Length() == static_cast<size_t>(i));
    if (i > 0) {
      REQUIRE(v.At(i - 1) == "Item" + std::to_string(i - 1));
    }
    REQUIRE(v.Capacity() == 10);
  }
  REQUIRE(v.Length() == 0);
  REQUIRE_THROWS(v.Erase(0));
  REQUIRE_THROWS(v.Erase(5));

  // 2. Large vector and erase first element repeatedly
  for (int i = 0; i < 1000; ++i) {
    v.PushBack("Item" + std::to_string(i));
  }
  REQUIRE(v.Length() == 1000);

  for (int i = 0; i < 1000; ++i) {
    size_t returned_index = v.Erase(0);
    REQUIRE(v.Length() == static_cast<size_t>(999 - i));
    if (v.Length() != 0) {
      REQUIRE(returned_index == 0);
      REQUIRE(v.At(0) == "Item" + std::to_string(i + 1));
    }
  }
  REQUIRE(v.Length() == 0);

  // 3. Erase from random indices
  for (int i = 0; i < 50; ++i) {
    v.PushBack("Item" + std::to_string(i));
  }
  REQUIRE(v.Length() == 50);
  std::vector<size_t> random_indices = {5, 10, 0, 21, 32, 42, 15, 25};
  for (size_t index : random_indices) {
    REQUIRE(v.Length() > index);
    size_t returned_index = v.Erase(index);
    REQUIRE(returned_index == index);
  }

  // Verify remaining vector (cross check with std::vector)
  std::vector<std::string> remaining_values = {};
  for (int i = 0; i < 50; ++i) {
    remaining_values.push_back("Item" + std::to_string(i));
  }
  for (int i = 0; i < random_indices.size(); ++i) {
    remaining_values.erase(remaining_values.begin() + random_indices[i]);
  }
  for (size_t i = 0; i < remaining_values.size(); ++i) {
    REQUIRE(remaining_values[i] == v[i]);
  }

  // 4. Refill and erase non-sequentially
  Vector v2;

  for (int i = 0; i < 10; ++i) {
    v2.PushBack("EdgeItem" + std::to_string(i));
  }
  REQUIRE(v2.Length() == 10);

  v2.PushBack("Extra1");
  v2.PushBack("Extra2");
  REQUIRE(v2.Length() == 12);

  v2.PopBack();  // Removes "Extra2"
  REQUIRE(v2.Length() == 11);

  REQUIRE(v2.Erase(5) == 5);  // Removes "EdgeItem5"
  REQUIRE(v2.Length() == 10);

  v2.PushBack("Extra3");
  REQUIRE(v2.Length() == 11);

  REQUIRE(v2.Erase(2) == 2);  // Removes "EdgeItem2"
  REQUIRE(v2.Length() == 10);

  v2.PopBack();  // Removes "Extra3"
  REQUIRE(v2.Length() == 9);

  REQUIRE(v2.Erase(0) == 0);  // Removes "EdgeItem0"
  REQUIRE(v2.Length() == 8);

  std::vector<std::string> expected_values = {
      "EdgeItem1", "EdgeItem3", "EdgeItem4", "EdgeItem6",
      "EdgeItem7", "EdgeItem8", "EdgeItem9", "Extra1"};
  REQUIRE(v2.Length() == expected_values.size());
  for (size_t i = 0; i < expected_values.size(); ++i) {
    REQUIRE(v2.At(i) == expected_values[i]);
  }

  // Erase after reserve on a larger vector
  Vector v3(1000);
  REQUIRE(v3.Capacity() == 1000);
  REQUIRE(v3.Length() == 0);

  // Fill it with 600 items
  for (int i = 0; i < 600; ++i) {
    v3.PushBack("Item" + std::to_string(i));
  }
  REQUIRE(v3.Length() == 600);
  REQUIRE(v3.Capacity() == 1000);

  // Erase a middle element (e.g. index 250)
  size_t returned_index = v3.Erase(250);
  REQUIRE(returned_index == 250);
  REQUIRE(v3.Length() == 599);
  REQUIRE(v3.At(250) == "Item251");

  // Erase the last element
  returned_index = v3.Erase(v3.Length() - 1);
  REQUIRE(returned_index == 598 - 1);
  REQUIRE(v3.Length() == 598);
  REQUIRE(v3.Capacity() == 1000);

  // Erase all elements
  while (v3.Length() > 0) {
    v3.Erase(v3.Length() - 1);
  }
  REQUIRE(v3.Length() == 0);
  REQUIRE(v3.Capacity() == 1000);
  REQUIRE_THROWS(v3.Erase(0));
}

TEST_CASE("basic reserve", "[reserve]") {
  Vector v;

  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);

  v.Reserve(20);
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);
  v.PushBack("stumpy");

  v.Reserve(16);
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 1);
  REQUIRE(v.Data() != nullptr);

  v.PushBack("toes");
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 2);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "stumpy");
  REQUIRE(v.Data()[1] == "toes");

  v.Reserve(20);
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 2);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "stumpy");
  REQUIRE(v.Data()[1] == "toes");
}

TEST_CASE("complex reserve", "[reserve]") {
  Vector v(4);
  REQUIRE(v.Capacity() == 4);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);

  v.PushBack("fish");
  v.PushBack("fishball");

  REQUIRE(v.Capacity() == 4);
  REQUIRE(v.Length() == 2);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "fish");
  REQUIRE(v.Data()[1] == "fishball");

  v.Reserve(7);
  REQUIRE(v.Capacity() == 7);
  REQUIRE(v.Length() == 2);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "fish");
  REQUIRE(v.Data()[1] == "fishball");

  v.Reserve(6);
  REQUIRE(v.Capacity() == 7);
  REQUIRE(v.Length() == 2);
  REQUIRE(v.Data() != nullptr);

  v.Reserve(0);
  REQUIRE(v.Capacity() == 7);
  REQUIRE(v.Length() == 2);
  REQUIRE(v.Data() != nullptr);

  v.PushBack("rain");
  v.PushBack("alarm");
  v.PushBack("tree");
  v.PushBack("very big tree");
  v.PushBack(" ");
  v.PushBack("fish with eyes");

  REQUIRE(v.Capacity() == 14);
  REQUIRE(v.Length() == 8);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "fish");
  REQUIRE(v.Data()[1] == "fishball");
  REQUIRE(v.Data()[2] == "rain");
  REQUIRE(v.Data()[3] == "alarm");
  REQUIRE(v.Data()[4] == "tree");
  REQUIRE(v.Data()[5] == "very big tree");
  REQUIRE(v.Data()[6] == " ");
  REQUIRE(v.Data()[7] == "fish with eyes");

  v.Reserve(12);
  REQUIRE(v.Capacity() == 14);
  REQUIRE(v.Length() == 8);
  REQUIRE(v.Data() != nullptr);

  Vector v2;
  REQUIRE(v2.Capacity() == 10);
  REQUIRE(v2.Length() == 0);
  REQUIRE(v2.Data() != nullptr);
  for (int i = 0; i < 4; ++i) {
    v2.PushBack("string " + std::to_string(i));
  }

  REQUIRE(v2.Capacity() == 10);
  REQUIRE(v2.Length() == 4);
  REQUIRE(v2.Data() != nullptr);
  for (int i = 0; i < 4; ++i) {
    REQUIRE(v2.Data()[i] == "string " + std::to_string(i));
  }

  v2.Reserve(500);
  REQUIRE(v2.Capacity() == 500);
  REQUIRE(v2.Length() == 4);
  REQUIRE(v2.Data() != nullptr);

  for (int i = 4; i < 499; i++) {
    v2.PushBack("string " + std::to_string(i));
  }

  REQUIRE(v2.Capacity() == 500);
  REQUIRE(v2.Length() == 499);

  v2.Reserve(480);
  REQUIRE(v2.Capacity() == 500);
  REQUIRE(v2.Length() == 499);
  REQUIRE(v2.Data() != nullptr);

  v2.Reserve(501);
  REQUIRE(v2.Capacity() == 501);
  REQUIRE(v2.Length() == 499);
  REQUIRE(v2.Data() != nullptr);
  for (int i = 0; i < 499; i++) {
    REQUIRE(v2.Data()[i] == "string " + std::to_string(i));
  }

  v2.Reserve(502);
  v2.Reserve(4);
  v2.Reserve(600);
  v2.Reserve(550);
  REQUIRE(v2.Capacity() == 600);
  REQUIRE(v2.Length() == 499);
  REQUIRE(v2.Data() != nullptr);

  v2.Reserve(603);

  REQUIRE(v2.Capacity() == 603);
  REQUIRE(v2.Length() == 499);
  REQUIRE(v2.Data() != nullptr);

  for (int i = 0; i < 499; i++) {
    REQUIRE(v2.Data()[i] == "string " + std::to_string(i));
  }

  for (int i = 499; i < 605; ++i) {
    v2.PushBack("string " + std::to_string(i));
  }
  REQUIRE(v2.Capacity() == 1206);
  REQUIRE(v2.Length() == 605);
  for (int i = 0; i < 605; i++) {
    REQUIRE(v2.Data()[i] == "string " + std::to_string(i));
  }
  v2.Reserve(604);
  REQUIRE(v2.Capacity() == 1206);
  v2.Reserve(1206);
  REQUIRE(v2.Capacity() == 1206);
  v2.Reserve(1207);
  REQUIRE(v2.Capacity() == 1207);
  for (int i = 0; i < 605; i++) {
    REQUIRE(v2.Data()[i] == "string " + std::to_string(i));
  }
}

TEST_CASE("basic insert", "[insert]") {
  Vector v;
  size_t index;

  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 0);
  REQUIRE(v.Data() != nullptr);

  index = v.Insert(0, "Egg sandwich./n");

  REQUIRE(index == 0);
  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 1);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "Egg sandwich./n");

  index = v.Insert(1, "bad squirrel");

  REQUIRE(index == 1);
  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 2);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "Egg sandwich./n");
  REQUIRE(v.Data()[1] == "bad squirrel");

  index = v.Insert(0, "okay");

  REQUIRE(index == 0);
  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 3);
  REQUIRE(v.Data() != nullptr);
  REQUIRE(v.Data()[0] == "okay");
  REQUIRE(v.Data()[1] == "Egg sandwich./n");
  REQUIRE(v.Data()[2] == "bad squirrel");

  Vector v2;
  REQUIRE(v2.Capacity() == 10);
  REQUIRE(v2.Length() == 0);
  REQUIRE(v2.Data() != nullptr);

  v2.PushBack("chestnut");
  v2.PushBack("walnut");
  v2.PushBack("peanut");
  v2.PushBack("applenut");

  REQUIRE(v2.Capacity() == 10);
  REQUIRE(v2.Length() == 4);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.Data()[0] == "chestnut");
  REQUIRE(v2.Data()[1] == "walnut");
  REQUIRE(v2.Data()[2] == "peanut");
  REQUIRE(v2.Data()[3] == "applenut");

  index = v2.Insert(3, "hazelnut");
  REQUIRE(index == 3);
  REQUIRE(v2.Capacity() == 10);
  REQUIRE(v2.Length() == 5);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.Data()[0] == "chestnut");
  REQUIRE(v2.Data()[1] == "walnut");
  REQUIRE(v2.Data()[2] == "peanut");
  REQUIRE(v2.Data()[3] == "hazelnut");
  REQUIRE(v2.Data()[4] == "applenut");

  index = v2.Insert(3, "candlenut");
  REQUIRE(index == 3);
  REQUIRE(v2.Capacity() == 10);
  REQUIRE(v2.Length() == 6);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.Data()[0] == "chestnut");
  REQUIRE(v2.Data()[1] == "walnut");
  REQUIRE(v2.Data()[2] == "peanut");
  REQUIRE(v2.Data()[3] == "candlenut");
  REQUIRE(v2.Data()[4] == "hazelnut");
  REQUIRE(v2.Data()[5] == "applenut");

  index = v2.Insert(0, "coconut");
  REQUIRE(index == 0);
  index = v2.Insert(0, "donut");
  REQUIRE(index == 0);
  REQUIRE(v2.Capacity() == 10);
  REQUIRE(v2.Length() == 8);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.Data()[0] == "donut");
  REQUIRE(v2.Data()[1] == "coconut");
  REQUIRE(v2.Data()[2] == "chestnut");
  REQUIRE(v2.Data()[3] == "walnut");
  REQUIRE(v2.Data()[4] == "peanut");
  REQUIRE(v2.Data()[5] == "candlenut");
  REQUIRE(v2.Data()[6] == "hazelnut");
  REQUIRE(v2.Data()[7] == "applenut");

  index = v2.Insert(8, "doughnut");
  REQUIRE(index == 8);
  REQUIRE(v2.Capacity() == 10);
  REQUIRE(v2.Length() == 9);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.Data()[0] == "donut");
  REQUIRE(v2.Data()[1] == "coconut");
  REQUIRE(v2.Data()[2] == "chestnut");
  REQUIRE(v2.Data()[3] == "walnut");
  REQUIRE(v2.Data()[4] == "peanut");
  REQUIRE(v2.Data()[5] == "candlenut");
  REQUIRE(v2.Data()[6] == "hazelnut");
  REQUIRE(v2.Data()[7] == "applenut");
  REQUIRE(v2.Data()[8] == "doughnut");

  Vector v3;
  REQUIRE(v3.Capacity() == 10);
  REQUIRE(v3.Length() == 0);
  REQUIRE(v3.Data() != nullptr);

  v3.Reserve(5);
  REQUIRE(v3.Capacity() == 10);
  REQUIRE(v3.Length() == 0);

  v3.Reserve(32);
  REQUIRE(v3.Capacity() == 32);
  REQUIRE(v3.Length() == 0);

  v3.Reserve(65);
  REQUIRE(v3.Capacity() == 65);
  REQUIRE(v3.Length() == 0);

  v3.Reserve(1044);
  REQUIRE(v3.Capacity() == 1044);
  REQUIRE(v3.Length() == 0);

  v3.Reserve(3000);
  REQUIRE(v3.Capacity() == 3000);
  REQUIRE(v3.Length() == 0);

  for (int i = 0; i < 3001; ++i) {
    v3.PushBack("thing " + std::to_string(i));
  }
  REQUIRE(v3.Capacity() == 6000);
  REQUIRE(v3.Length() == 3001);
  REQUIRE(v3.Data() != nullptr);
  for (int i = 0; i < 3001; ++i) {
    REQUIRE(v3.Data()[i] == "thing " + std::to_string(i));
  }
}

TEST_CASE("complex insert", "[insert]") {
  Vector v;
  size_t index;

  for (int i = 0; i < 9; ++i) {
    v.PushBack("count " + std::to_string(i));
  }

  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 9);
  REQUIRE(v.Data() != nullptr);
  for (int i = 0; i < 9; ++i) {
    REQUIRE(v.Data()[i] == "count " + std::to_string(i));
  }

  index = v.Insert(9, "count 9");
  REQUIRE(index == 9);
  REQUIRE(v.Capacity() == 10);
  REQUIRE(v.Length() == 10);
  REQUIRE(v.Data() != nullptr);
  for (int i = 0; i < 10; ++i) {
    REQUIRE(v.Data()[i] == "count " + std::to_string(i));
  }

  index = v.Insert(10, "count 10");
  REQUIRE(index == 10);
  REQUIRE(v.Capacity() == 20);
  REQUIRE(v.Length() == 11);
  REQUIRE(v.Data() != nullptr);
  for (int i = 0; i < 11; ++i) {
    REQUIRE(v.Data()[i] == "count " + std::to_string(i));
  }

  REQUIRE_THROWS_AS(v.Insert(12, "12 out of bounds"), out_of_range);
  REQUIRE_THROWS_AS(v.Insert(21, "21 out of bounds"), out_of_range);
  REQUIRE_THROWS_AS(v.Insert(24, "24 out of bounds"), out_of_range);
  REQUIRE_THROWS_AS(v.Insert(2824, "2824 out of bounds"), out_of_range);

  Vector v2(1);
  REQUIRE(v2.Capacity() == 1);
  REQUIRE(v2.Length() == 0);
  REQUIRE(v2.Data() != nullptr);

  for (int i = 0; i < 1000; ++i) {
    index = v2.Insert(i, "boom boom " + std::to_string(i));
    REQUIRE(index == i);
  }

  REQUIRE(v2.Capacity() == 1024);
  REQUIRE(v2.Length() == 1000);
  REQUIRE(v2.Data() != nullptr);
  REQUIRE(v2.Data()[0] == "boom boom 0");
  REQUIRE(v2.Data()[12] == "boom boom 12");
  REQUIRE(v2.Data()[419] == "boom boom 419");
  REQUIRE(v2.Data()[732] == "boom boom 732");
  REQUIRE(v2.Data()[999] == "boom boom 999");

  Vector v3(13);
  REQUIRE(v3.Capacity() == 13);
  REQUIRE(v3.Length() == 0);
  REQUIRE(v3.Data() != nullptr);

  for (int i = 0; i < 13; ++i) {
    index = v3.Insert(0, "choom choom " + std::to_string(i));
    REQUIRE(index == 0);
  }
  REQUIRE(v3.Capacity() == 13);
  REQUIRE(v3.Length() == 13);

  v3.Insert(0, "choom choom 13");
  REQUIRE(v3.Capacity() == 26);
  REQUIRE(v3.Length() == 14);

  for (int i = 14; i < 571; ++i) {
    index = v3.Insert(0, "choom choom " + std::to_string(i));
    REQUIRE(index == 0);
  }
  REQUIRE(v3.Capacity() == 832);
  REQUIRE(v3.Length() == 571);
  REQUIRE(v3.Data() != nullptr);

  int val = 570;
  for (int i = 0; i < 571; ++i) {
    REQUIRE(v3.Data()[i] == "choom choom " + std::to_string(val));
    val--;
  }

  Vector v4(1);
  REQUIRE(v4.Capacity() == 1);
  REQUIRE(v4.Length() == 0);
  REQUIRE(v4.Data() != nullptr);

  index = v4.Insert(0, "elem 0");
  REQUIRE(v4.Capacity() == 1);
  REQUIRE(v4.Length() == 1);

  index = v4.Insert(1, "elem 1");
  REQUIRE(v4.Capacity() == 2);
  REQUIRE(v4.Length() == 2);

  v4.Insert(2, "elem 2");
  REQUIRE(v4.Capacity() == 4);
  REQUIRE(v4.Length() == 3);

  v4.Insert(3, "elem 3");
  v4.Insert(4, "elem 4");
  REQUIRE(v4.Capacity() == 8);
  REQUIRE(v4.Length() == 5);

  v4.Insert(5, "elem 5");
  v4.Insert(6, "elem 6");
  v4.Insert(7, "elem 7");
  v4.Insert(8, "elem 8");
  REQUIRE(v4.Capacity() == 16);
  REQUIRE(v4.Length() == 9);
  for (int i = 0; i < 9; ++i) {
    REQUIRE(v4.Data()[i] == "elem " + std::to_string(i));
  }
  REQUIRE_THROWS_AS(v4.Insert(10, "10 out of bounds"), out_of_range);
  REQUIRE_THROWS_AS(v4.Insert(14, "14 out of bounds"), out_of_range);

  Vector v5(5);
  REQUIRE(v5.Insert(0, "num 0") == 0);
  REQUIRE(v5.Insert(1, "num 1") == 1);
  REQUIRE(v5.Insert(2, "num 3") == 2);
  REQUIRE(v5.Insert(3, "num 5") == 3);
  REQUIRE(v5.Insert(4, "num 8") == 4);

  REQUIRE(v5.Capacity() == 5);
  REQUIRE(v5.Length() == 5);

  REQUIRE(v5.Insert(3, "num 4") == 3);
  REQUIRE(v5.Insert(5, "num 7") == 5);
  REQUIRE(v5.Insert(5, "num 6") == 5);
  REQUIRE(v5.Insert(2, "num 2") == 2);

  REQUIRE(v5.Capacity() == 10);
  REQUIRE(v5.Length() == 9);
  for (int i = 0; i < 9; ++i) {
    REQUIRE(v5.Data()[i] == "num " + std::to_string(i));
  }

  REQUIRE(v5.Insert(9, "num 12") == 9);
  REQUIRE(v5.Insert(9, "num 9") == 9);
  REQUIRE(v5.Insert(10, "num 11") == 10);
  REQUIRE(v5.Insert(10, "num 10") == 10);
  REQUIRE(v5.Insert(0, "num -2") == 0);
  REQUIRE(v5.Insert(1, "num -1") == 1);

  REQUIRE(v5.Capacity() == 20);
  REQUIRE(v5.Length() == 15);

  for (int i = 0; i < 15; ++i) {
    REQUIRE(v5.Data()[i] == "num " + std::to_string(i - 2));
  }
}

TEST_CASE("basic find", "[find]") {
  Vector v;

  REQUIRE(v.Find("omelas") == -1);

  v.PushBack("testing");
  v.PushBack("omelas");
  v.PushBack("cookie");
  v.PushBack("omelas");
  v.PushBack("porcupine");

  REQUIRE(v.Find("omelas") == 1);
  REQUIRE(v.Find("porcupine") == 4);
  REQUIRE(v.Find("Omelas") == -1);
}

TEST_CASE("basic contains", "[contains]") {
  Vector v;

  REQUIRE_FALSE(v.Contains("omelas"));

  v.PushBack("testing");
  v.PushBack("omelas");
  v.PushBack("cookie");
  v.PushBack("omelas");
  v.PushBack("porcupine");

  REQUIRE(v.Contains("omelas"));
  REQUIRE(v.Contains("porcupine"));
  REQUIRE_FALSE(v.Contains("Omelas"));
}

TEST_CASE("basic move constructor", "[move_ctor]") {
  Vector original;
  Vector original2;

  // Empty copy
  Vector empty_copy(std::move(original2));
  REQUIRE(empty_copy.Length() == 0);
  REQUIRE(empty_copy.Capacity() >= 0);

  original.PushBack("alpha");
  original.PushBack("beta");
  original.PushBack("gamma");

  auto og_data = original.Data();

  // Copy with values
  Vector copy_of_original(std::move(original));
  REQUIRE(copy_of_original.Length() == 3);
  REQUIRE(copy_of_original.Capacity() >= 3);
  REQUIRE(copy_of_original.At(0) == "alpha");
  REQUIRE(copy_of_original.At(1) == "beta");
  REQUIRE(copy_of_original.At(2) == "gamma");

  // Memory moved
  REQUIRE(og_data == copy_of_original.Data());
}

TEST_CASE("basic assignment", "[op_equals]") {
  Vector original;

  // Empty copy
  Vector empty_copy;
  empty_copy = original;
  REQUIRE(empty_copy.Length() == original.Length());
  REQUIRE(empty_copy.Capacity() == original.Capacity());

  original.PushBack("alpha");
  original.PushBack("beta");
  original.PushBack("gamma");

  // Copy with values
  Vector copy_of_original(empty_copy);
  copy_of_original = original;

  REQUIRE(copy_of_original.Length() == original.Length());
  REQUIRE(copy_of_original.Capacity() >= original.Length());
  REQUIRE(copy_of_original.At(0) == original.At(0));
  REQUIRE(copy_of_original.At(1) == original.At(1));
  REQUIRE(copy_of_original.At(2) == original.At(2));

  // Memory independence
  REQUIRE(original.Data() != copy_of_original.Data());

  // Deep copy
  original.PushBack("delta");
  REQUIRE(original.Length() == 4);
  REQUIRE(copy_of_original.Length() == 3);
  original.PushBack("new value");
  REQUIRE(copy_of_original.At(2) == "gamma");
  REQUIRE(copy_of_original.Length() == 3);
  copy_of_original.At(0) = "changed";
  REQUIRE(copy_of_original.At(0) != original.At(0));
  REQUIRE(copy_of_original.At(0) == "changed");
  REQUIRE(original.At(0) == "alpha");

  // Copy Vector with initial capacity
  Vector preallocated(20);
  preallocated.PushBack("hello");
  preallocated.PushBack("world");
  REQUIRE(preallocated.Length() == 2);
  REQUIRE(preallocated.Capacity() == 20);
  Vector copy_of_preallocated(empty_copy);
  copy_of_preallocated = preallocated;
  REQUIRE(copy_of_preallocated.Length() == 2);
  REQUIRE(copy_of_preallocated.Capacity() == 20);
  REQUIRE(copy_of_preallocated.At(0) == "hello");
  REQUIRE(copy_of_preallocated.At(1) == "world");
  REQUIRE(copy_of_preallocated.Data() != preallocated.Data());

  // Test reserve with copy
  empty_copy = original;

  // Larger Vector copy
  Vector large_vec;
  for (size_t i = 0; i < 50; ++i) {
    large_vec.PushBack("Item" + std::to_string(i));
  }
  Vector large_copy(10);
  large_copy = large_vec;
  REQUIRE(large_copy.Length() == 50);
  bool identical = true;
  for (size_t i = 0; i < 50; ++i) {
    if (large_copy.At(i) != large_vec.At(i)) {
      identical = false;
      break;
    }
  }
  REQUIRE(identical == true);

  // assign to self
  Vector& ref = preallocated;
  preallocated = ref;
  REQUIRE(preallocated.Length() == 2);
  REQUIRE(preallocated.Capacity() == 20);
  REQUIRE(preallocated.Data()[0] == "hello");
  REQUIRE(preallocated.Data()[1] == "world");
}

TEST_CASE("basic move assignment", "[op_move]") {
  Vector original;

  // Empty copy
  Vector empty_copy;
  empty_copy = original;
  REQUIRE(empty_copy.Length() == original.Length());
  REQUIRE(empty_copy.Capacity() == original.Capacity());

  original.PushBack("alpha");
  original.PushBack("beta");
  original.PushBack("gamma");

  auto og_data = original.Data();

  // Copy with values
  Vector copy_of_original(empty_copy);
  copy_of_original = std::move(original);

  REQUIRE(copy_of_original.Length() == 3);
  REQUIRE(copy_of_original.Capacity() >= 3);
  REQUIRE(copy_of_original.At(0) == "alpha");
  REQUIRE(copy_of_original.At(1) == "beta");
  REQUIRE(copy_of_original.At(2) == "gamma");

  // Memory independence
  REQUIRE(original.Data() != copy_of_original.Data());
  REQUIRE(og_data == copy_of_original.Data());

  // Copy Vector with initial capacity
  Vector preallocated(20);
  preallocated.PushBack("hello");
  preallocated.PushBack("world");
  REQUIRE(preallocated.Length() == 2);
  REQUIRE(preallocated.Capacity() == 20);
  Vector copy_of_preallocated(empty_copy);
  copy_of_preallocated = std::move(preallocated);
  REQUIRE(copy_of_preallocated.Length() == 2);
  REQUIRE(copy_of_preallocated.Capacity() == 20);
  REQUIRE(copy_of_preallocated.At(0) == "hello");
  REQUIRE(copy_of_preallocated.At(1) == "world");
  REQUIRE(copy_of_preallocated.Data() != preallocated.Data());

  // assign to self
  Vector& ref = copy_of_preallocated;
  copy_of_preallocated = std::move(ref);
  REQUIRE(copy_of_preallocated.Length() == 2);
  REQUIRE(copy_of_preallocated.Capacity() == 20);
  REQUIRE(copy_of_preallocated.Data()[0] == "hello");
  REQUIRE(copy_of_preallocated.Data()[1] == "world");
}
