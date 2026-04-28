#include "Vector.hpp"
#include <optional>
#include <stdexcept>
#include <string>

// TODO: add the include for corresponding hpp

// TODO: finish the rest

// @brief Creates an empty Vector with default capacity
// @post m_length == 0, m_capacity == k_default_capacity
Vector::Vector()
    : m_data{new std::string[k_default_capacity]},
      m_length{0},
      m_capacity{k_default_capacity} {}

// @brief Constructor with specified initial capacity
// @param initial_capacity The initial capacity to reserve
// @post m_length == 0, m_capacity == initial_capacity
// @throws std::bad_alloc if memory allocation fails
Vector::Vector(size_t initial_capacity)
    : m_data{new std::string[initial_capacity]},
      m_length{0},
      m_capacity{initial_capacity} {}

// @brief creates a deep copy of another Vector
// @param other The Vector to be copied
// @post Creates an independent copy with same length and capacity
// @throws std::bad_alloc if memory allocation fails
Vector::Vector(const Vector& other)
    : m_data{new std::string[other.m_capacity]},
      m_length{other.m_length},
      m_capacity{other.m_capacity} {
  for (size_t i{0}; i < m_length; ++i) {
    m_data[i] = other.m_data[i];
  }
}

// @brief Transfers ownership of resources
// @param other The Vector to move from
// @post other is left in empty state
// @note noexcept guarantees exception safety
Vector::Vector(Vector&& other) noexcept
    : m_data{other.m_data},
      m_length{other.m_length},
      m_capacity{other.m_capacity} {
  other.m_data = nullptr;
  other.m_length = 0;
  other.m_capacity = 0;
}

// Frees dynamically allocated memory
// @post All resources are released
Vector::~Vector() {
  delete[] m_data;
}
// @brief Copy assignment operator
// @param other The Vector to be copied
// @return Reference to this Vector
// @post Handles self-assignment correctly
// @throws std::bad_alloc if memory allocation fails
Vector& Vector::operator=(const Vector& other) {
  if (this != &other) {
    std::string* new_data{new std::string[other.m_capacity]};
    for (size_t i{0}; i < other.m_length; ++i) {
      new_data[i] = other.m_data[i];
    }
    delete[] m_data;
    m_data = new_data;
    m_length = other.m_length;
    m_capacity = other.m_capacity;
  }
  return *this;
}
// @brief Move assignment operator
// @param other The Vector to move from
// @return Reference to this Vector
// @post other is left in empty state
Vector& Vector::operator=(Vector&& other) noexcept {
  if (this != &other) {
    delete[] m_data;
    m_data = other.m_data;
    m_length = other.m_length;
    m_capacity = other.m_capacity;

    other.m_data = nullptr;
    other.m_length = 0;
    other.m_capacity = 0;
  }
  return *this;
}

// @brief Returns the number of elements in the Vector
// @return Current number of elements
size_t Vector::Length() const {
  return m_length;
}

// @brief Returns the current capacity of the Vector
// @return Current allocated capacity
size_t Vector::Capacity() const {
  return m_capacity;
}

// @brief Returns a pointer to the array
// @return Pointer to the dynamically allocated array
std::string* Vector::Data() {
  return m_data;
}

// @brief Reserves capacity for at least new_cap elements
// @param new_cap The new capacity to reserve
// @post If new_cap > m_capacity, reallocates and m_capacity = new_cap
// @throws std::bad_alloc if memory allocation fails
void Vector::Reserve(size_t new_cap) {
  if (new_cap <= m_capacity) {
    return;
  }

  std::string* new_data{new std::string[new_cap]};
  if (new_data != nullptr && new_cap >= m_length) {
    for (size_t i{0}; i < m_length; ++i) {
      new_data[i] = m_data[i];
    }
  }

  delete[] m_data;
  m_data = new_data;
  m_capacity = new_cap;
}

// @brief Adds an element to the end of the Vector
// @param element The string to add
// @post element is appended, m_length increases by 1
// @throws std::bad_alloc if memory allocation fails during reallocation
void Vector::PushBack(const std::string& element) {
  if (m_length >= m_capacity) {
    const size_t next_cap{(m_capacity == 0) ? 1 : m_capacity * 2};
    Reserve(next_cap);
  }
  m_data[m_length] = element;
  m_length++;
}

// @brief Removes and returns the last element
// @return The last element if Vector is non-empty, otherwise std::nullopt
// @post If Vector is not empty, m_length decreases by 1
std::optional<std::string> Vector::PopBack() {
  if (m_length == 0) {
    return std::nullopt;
  }
  std::string last_element{m_data[m_length - 1]};
  m_length--;
  return last_element;
}

// @brief Subscript operator
// @param index Position of element to access
// @return Reference to the element at the specified position
// @throws std::out_of_range if index >= m_length
std::string& Vector::operator[](size_t index) {
  if (index >= m_length) {
    throw std::out_of_range{"Vector::operator[] index out of range"};
  }
  return m_data[index];
}
// @brief Subscript operator
// @param index Position of element to access
// @return Const reference to the element at the specified position
// @throws std::out_of_range if index >= m_length
const std::string& Vector::operator[](size_t index) const {
  if (index >= m_length) {
    throw std::out_of_range{"Vector::operator[] index out of range"};
  }
  return m_data[index];
}
// @brief Bounds-checked element access
// @param index Position of element to access
// @return Reference to the element at the specified position
// @throws std::out_of_range if index >= m_length
std::string& Vector::At(size_t index) {
  if (index >= m_length) {
    throw std::out_of_range{"Vector::At index out of range"};
  }
  return m_data[index];
}
// @brief Bounds-checked element access
// @param index Position of element to access
// @return Const reference to the element at the specified position
// @throws std::out_of_range if index >= m_length
const std::string& Vector::At(size_t index) const {
  if (index >= m_length) {
    throw std::out_of_range{"Vector::At index out of range"};
  }
  return m_data[index];
}

// @brief Inserts an element at the specified position
// @param index Position to insert at
// @param element The string to insert
// @return The index where element was inserted
// @post element is inserted at index, subsequent elements shifted right
// @throws std::out_of_range if index > m_length
// @throws std::bad_alloc if memory allocation fails
size_t Vector::Insert(size_t index, const std::string& element) {
  if (index > m_length) {
    throw std::out_of_range{"Vector::Insert index out of range"};
  }

  if (m_length >= m_capacity) {
    const size_t next_cap{(m_capacity == 0) ? 1 : m_capacity * 2};
    Reserve(next_cap);
  }

  if (m_length < m_capacity && m_data != nullptr) {
    for (size_t i{m_length}; i > index; --i) {
      m_data[i] = m_data[i - 1];
    }

    m_data[index] = element;
    m_length++;
  }
  return index;
}
// @brief Erases an element at the specified position
// @param index Position to erase
// @return The index of the element after the erased one
// @post Element at index is removed, subsequent elements shifted left,
// @throws std::out_of_range if index >= m_length
size_t Vector::Erase(size_t index) {
  if (index >= m_length) {
    throw std::out_of_range{"Vector::Erase index out of range"};
  }

  for (size_t i{index}; i < m_length - 1; ++i) {
    m_data[i] = m_data[i + 1];
  }

  m_length--;
  if (index == m_length) {
    return index - 1;
  }
  return index;
}
// @brief Finds the first occurrence of target
// @param target The string to search for
// @return Index of first occurrence if found
ssize_t Vector::Find(const std::string& target) const {
  for (size_t i{0}; i < m_length; ++i) {
    if (m_data[i] == target) {
      return static_cast<ssize_t>(i);
    }
  }
  return -1;
}
// @brief Checks if the Vector contains target
// @param target The string to search for
// @return true if target is found
bool Vector::Contains(const std::string& target) const {
  return Find(target) != -1;
}
