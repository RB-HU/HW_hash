// TODO: add a header guard
#ifndef VECTOR_HPP_
#define VECTOR_HPP_
#include <cstddef>
#include <optional>
#include <stdexcept>
#include <string>




// Vector is a class that represents
// an ordered list of strings as a dynamically resizable array.
//
// For simplicity, we are having the vector only store strings
class Vector {
 public:
  // constructors:

  // 0-arg constructor.
  // Constructs an Vector with initial capacity 10
  // The initial length will be 0 and the Vector contains no initial elements
  Vector();

  // 1-arg construcor
  // Constructs an Vector with the specified initial capacity
  // The initial size will be 0 and the Vector contains no initial elements
  explicit Vector(size_t initial_capacity);

  // copy constructor
  // Takes in another Vector by const-reference
  // contructs a new Vector as an independent copy of the
  // passed in Vector
  Vector(const Vector& other);

  // Move constructor
  // Takes in another Vector vector by R-reference
  // takes ownership of the data of other
  Vector(Vector&& other) noexcept;

  // assignment op
  Vector& operator=(const Vector& other);

  // move assignment op
  Vector& operator=(Vector&& other) noexcept;

  // Destructor
  // Deallocates any allocated resources
  ~Vector();

  // Returns the current number of elements in the Vector
  [[nodiscard]] size_t Length() const;

  // returns access to the underlying dynamically allocated array
  // that the Vector object manages.
  [[nodiscard]] std::string* Data();

  // Returns the current capacity of the Vector
  [[nodiscard]] size_t Capacity() const;

  // Requests that the Vector capacity be at least enough to contain `new_cap`
  // elements.
  //
  // If `new_cap` is greater than the current Vector capacity, the function
  // causes the container to reallocate its storage increasing its capacity to n
  // (or greater).
  //
  // In all other cases, the function call does not cause a reallocation and the
  // Vector capacity is not affected. This function has no effect on the Vector
  // size and cannot alter its elements.
  void Reserve(size_t new_cap);

  // Adds a new elemnt to the end of the Vector, after the current last element.
  // This means that the number of elements goes up by 1, but the capacity may
  // stay the same. If the new size would be greater than the capacity, then the
  // capcity should be increased and the space used for storage should be
  // re-allocated to support the new capacity and values in the oringal storage
  // are copied to the new storage.
  //
  // For our implmentation, you should double the capacity when you reallocate.
  void PushBack(const std::string& element);

  // removes the value from the end of the Vector and returns it.
  // If there are no elemennts in the Vector, then it returns std::nullopt
  std::optional<std::string> PopBack();

  // Returns a reference to the value at the specified index
  // If the index is out of the bounds of the array, then it
  // throws an `out_of_range` exception.
  //
  // Indexes start at 0, just as they do in a normal array.
  [[nodiscard]] std::string& operator[](size_t index);
  [[nodiscard]] const std::string& operator[](size_t index) const;

  // Returns a reference to the value at the specified index
  // If the index is out of the bounds of the array, then it
  // throws an `out_of_range` exception.
  //
  // Indexes start at 0, just as they do in a normal array.
  [[nodiscard]] std::string& At(size_t index);
  [[nodiscard]] const std::string& At(size_t index) const;

  // Given an index and a value, inserts the specified value at the specified
  // index in the Vector. This extends the existing Vector to insert the
  // new element. Any values at or after the specified index before insertion
  // will be shifted "up" an index for the insertion.
  // For example, if we inserted value 3 at index 2, on the Vector {1, 5, 2, 8}
  // then the Vector should look like {1, 5, 3, 2, 8} after insertion.
  //
  // If the new size would be greater than the capacity, then the capcity
  // should be increased and the space used for storage should be re-allocated
  // to support the new capacity and values in the oringal storage are copied
  // to the new storage.
  //
  // For our implmentation, you should double the capacity when you reallocate.
  //
  // The index can be in the range of [0, length] (inclusive of both).
  // This means that when index == length, we are inserting the element to the
  // back of the Vector.
  //
  // If the index is out of the bounds of the Vector (except if index == length)
  // then it throws an `out_of_range` exception.
  //
  // Returns the index of the newly inserted element
  size_t Insert(size_t index, const std::string& element);

  // Given an index, erases the value at the specified index
  // This means the length of the Vector decreases and any elements past
  // the erased element are "shifted down". Capacity remains unchanged.
  //
  // If the index is out of the bounds of the Vector, then it
  // throws an `out_of_range` exception.
  //
  // The function should return the index we erased at or if we erased the
  // end of the Vector, then the length - 1 is returned
  size_t Erase(size_t index);

  // Given a string, returns the lowest index that it can be found out
  // within the Vector. If the target cannot be found, then -1 is returned.
  //
  // Returns the index of the target or  -1 if not found.
  [[nodiscard]] ssize_t Find(const std::string& target) const;

  // Given a string, returns the whether or not it can be found out
  // within the Vector.
  //
  // Returns true iff the target can be found, false otherwise.
  [[nodiscard]] bool Contains(const std::string& target) const;

 private:
  std::string* m_data;
  size_t m_length;
  size_t m_capacity;

  static constexpr size_t k_default_capacity = 10;
};
#endif // VECTOR_HPP_
