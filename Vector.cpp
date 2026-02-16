#include <stdexcept>
#include "Vector.hpp"
#include <algorithm>
#include <string>

// TODO: add the include for corresponding hpp

// TODO: finish the rest
Vector::Vector()
    : m_data{new std::string[k_default_capacity]},
      m_length{0},
      m_capacity{k_default_capacity} {}

Vector::Vector(size_t initial_capacity)
    : m_data{new std::string[initial_capacity]},
      m_length{0},
      m_capacity{initial_capacity} {}

Vector::Vector(const Vector& other)
    : m_data{new std::string[other.m_capacity]},
      m_length{other.m_length},
      m_capacity{other.m_capacity} {
  for (size_t i{0}; i < m_length; ++i) {
    m_data[i] = other.m_data[i];
  }
}

Vector::Vector(Vector&& other) noexcept
    : m_data{other.m_data},
      m_length{other.m_length},
      m_capacity{other.m_capacity} {
  other.m_data = nullptr;
  other.m_length = 0;
  other.m_capacity = 0;
}

Vector::~Vector() {
  delete[] m_data;
}

// --- Assignment Operators ---

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

// --- Accessors ---

size_t Vector::Length() const {
  return m_length;
}

size_t Vector::Capacity() const {
  return m_capacity;
}

std::string* Vector::Data() {
  return m_data;
}

// --- Modifiers ---

void Vector::Reserve(size_t new_cap) {
  if (new_cap <= m_capacity) {
    return;
  }

  std::string* new_data{new std::string[new_cap]};
  for (size_t i{0}; i < m_length; ++i) {
    // Use std::move to avoid expensive string copies during reallocation
    new_data[i] = std::move(m_data[i]);
  }

  delete[] m_data;
  m_data = new_data;
  m_capacity = new_cap;
}

void Vector::PushBack(const std::string& element) {
  if (m_length >= m_capacity) {
    size_t next_cap{(m_capacity == 0) ? 1 : m_capacity * 2};
    Reserve(next_cap);
  }
  m_data[m_length] = element;
  m_length++;
}

std::optional<std::string> Vector::PopBack() {
  if (m_length == 0) {
    return std::nullopt;
  }
  std::string last_element{std::move(m_data[m_length - 1])};
  m_length--;
  return last_element;
}

// --- Indexing ---

std::string& Vector::operator[](size_t index) {
  if (index >= m_length) { 
    throw std::out_of_range{"Vector::operator[] index out of range"};
  }
  return m_data[index];
}

const std::string& Vector::operator[](size_t index) const {
  if (index >= m_length) { 
    throw std::out_of_range{"Vector::operator[] index out of range"};
  }
  return m_data[index];
}

std::string& Vector::At(size_t index) {
  if (index >= m_length) {
    throw std::out_of_range{"Vector::At index out of range"};
  }
  return m_data[index];
}

const std::string& Vector::At(size_t index) const {
  if (index >= m_length) {
    throw std::out_of_range{"Vector::At index out of range"};
  }
  return m_data[index];
}

// --- Advanced Operations ---

size_t Vector::Insert(size_t index, const std::string& element) {
  if (index > m_length) {
    throw std::out_of_range{"Vector::Insert index out of range"};
  }

  if (m_length >= m_capacity) {
    size_t next_cap{(m_capacity == 0) ? 1 : m_capacity * 2};
    Reserve(next_cap);
  }

  // Shift elements up to make room for the new element
  for (size_t i{m_length}; i > index; --i) {
    m_data[i] = std::move(m_data[i - 1]);
  }

  m_data[index] = element;
  m_length++;
  return index;
}

size_t Vector::Erase(size_t index) {
  if (index >= m_length) {
    throw std::out_of_range{"Vector::Erase index out of range"};
  }

  // Shift elements down to fill the gap
  bool deleting_last = (index == m_length - 1);
  for (size_t i{index}; i < m_length - 1; ++i) {
    m_data[i] = std::move(m_data[i + 1]);
  }

  m_length--;
  if (deleting_last) {
    return index - 1;
  }
  return index;
}

ssize_t Vector::Find(const std::string& target) const {
  for (size_t i{0}; i < m_length; ++i) {
    if (m_data[i] == target) {
      return static_cast<ssize_t>(i);
    }
  }
  return -1;
}

bool Vector::Contains(const std::string& target) const {
  return Find(target) != -1;
}

