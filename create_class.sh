#!/bin/bash

# Default values
template=false
default=false

# Parse command line options
while [[ $# -gt 0 ]]; do
  key="$1"
  case $key in
    -t|--template)
      template=true
      shift # past argument
      ;;
    -d|--dflag)
      default=true
      shift # past argument
      ;;
    *)
      break
      ;;
  esac
done

# Check if class name is provided
if [ -z "$1" ]; then
  echo "Usage: ./create_class.sh [-t|--template] [-d|--default] <ClassName>"
  exit 1
fi

# Assign class name to a variable
CLASS_NAME=$1
HEADER_FILE="${CLASS_NAME}.h"
SOURCE_FILE="${CLASS_NAME}.cpp"

if [ "$default" = true ]; then
  echo "Creating class $CLASS_NAME with default constructor..."
  # Add your logic for default version here

  cat <<EOL > $HEADER_FILE
#pragma once

#include <iostream>
#include <utility>

// #define DEBUG_MSG

#ifdef DEBUG_MSG
    #define DEBUG_PRINT(msg) std::cout << msg << std::endl;
#else
    #define DEBUG_PRINT(msg)
#endif

class $CLASS_NAME
{
public:
	// Default constructor
	$CLASS_NAME() = default;

	// Copy constructor
	$CLASS_NAME(const $CLASS_NAME&) = default;

	// Copy assignment operator
	$CLASS_NAME& operator=(const $CLASS_NAME&) = default;

	// Move constructor
	$CLASS_NAME($CLASS_NAME&&) noexcept = default;

	// Move assignment operator
	$CLASS_NAME& operator=($CLASS_NAME&&) noexcept = default;

	// Destructor
	~$CLASS_NAME() = default;

private:

};
EOL

# Create the source file

cat <<EOL > $SOURCE_FILE
#include "$HEADER_FILE"
EOL

  echo "Files $HEADER_FILE and $SOURCE_FILE have been created."
  exit 0
fi

# Your script logic here
if [ "$template" = false ]; then # Version for template=false
  echo "Creating class $CLASS_NAME without template..."
  # Add your logic for non-template version here

  cat <<EOL > $HEADER_FILE
#pragma once

#include <iostream>
#include <utility>

// #define DEBUG

#ifdef DEBUG
    #define DEBUG_PRINT(msg) std::cout << msg << std::endl;
#else
    #define DEBUG_PRINT(msg)
#endif

class $CLASS_NAME
{
public:
	// Default constructor
	$CLASS_NAME();

	// Copy constructor
	$CLASS_NAME(const $CLASS_NAME& rhs);

	// Copy assignment operator
	$CLASS_NAME& operator=($CLASS_NAME rhs) noexcept;

	// Move constructor
	$CLASS_NAME($CLASS_NAME&& rhs) noexcept;

	// Destructor
	~$CLASS_NAME();

	// Swap function
	void swap($CLASS_NAME& first, $CLASS_NAME& second) noexcept;

private:

};
EOL

# Create the source file

cat <<EOL > $SOURCE_FILE
#include "$HEADER_FILE"

// Default constructor
$CLASS_NAME::$CLASS_NAME()
{
	DEBUG_PRINT("$CLASS_NAME:: default constructor called");
}

// Copy constructor
$CLASS_NAME::$CLASS_NAME(const $CLASS_NAME& rhs)
{
	DEBUG_PRINT("$CLASS_NAME:: copy constructor called");
}

// Copy assignment operator
$CLASS_NAME& $CLASS_NAME::operator=($CLASS_NAME rhs) noexcept
{
	DEBUG_PRINT("$CLASS_NAME:: copy assignment operator called");

	swap(*this, rhs);
	return *this;
}

// Move constructor
$CLASS_NAME::$CLASS_NAME($CLASS_NAME&& rhs) noexcept
{
	DEBUG_PRINT("$CLASS_NAME:: move constructor called");
}

// Destructor
$CLASS_NAME::~$CLASS_NAME()
{
	DEBUG_PRINT("$CLASS_NAME:: destructor called");
}

void $CLASS_NAME::swap($CLASS_NAME& first, $CLASS_NAME& second) noexcept
{
	using std::swap;
}
EOL

  echo "Files $HEADER_FILE and $SOURCE_FILE have been created."
else # Version for template=true
  echo "Creating class $CLASS_NAME with template..."
  # Add your logic for template version here

  cat <<EOL > $HEADER_FILE
#pragma once

#include <iostream>
#include <utility>
#include <memory>

// #define DEBUG

#ifdef DEBUG
    #define DEBUG_PRINT(msg) std::cout << msg << std::endl;
#else
    #define DEBUG_PRINT(msg)
#endif

class $CLASS_NAME
{
public:
	// Default constructor
	$CLASS_NAME();

	// Copy constructor
	$CLASS_NAME(const $CLASS_NAME& rhs);

	// Copy assignment operator
	$CLASS_NAME& operator=($CLASS_NAME rhs) noexcept;

	// Move constructor
	$CLASS_NAME($CLASS_NAME&& rhs) noexcept;

	// Destructor
	~$CLASS_NAME();

	// Swap function
	void swap($CLASS_NAME& first, $CLASS_NAME& second) noexcept;

	// Setters
	void setX(int x) { m_x = x; }
	void setRaw(int* raw) { m_Raw = raw; }
	void setUnique(std::unique_ptr<int> unique) { m_Unique = std::move(unique); }
	void setShared(std::shared_ptr<int> shared) { m_Shared = shared; }

	// Getters
	int getX() const { return m_x; }

	int getRawValue() const
	{
		if (m_Raw) {
			return *m_Raw;
		}
		else {
			throw std::runtime_error("m_Raw is nullptr");
		}
	}

	int getUniqueValue() const
	{
		if (m_Unique) {
			return *m_Unique;
		}
		else {
			throw std::runtime_error("m_Unique is nullptr");
		}
	}

	int getSharedValue() const
	{
		if (m_Shared) {
			return *m_Shared;
		}
		else {
			throw std::runtime_error("m_Shared is nullptr");
		}
	}

private:
	int m_x = 0;
	int *m_Raw = nullptr;
	std::unique_ptr<int> m_Unique;
	std::shared_ptr<int> m_Shared;
};
EOL

# Create the source file

cat <<EOL > $SOURCE_FILE
#include "$HEADER_FILE"

// Default constructor
$CLASS_NAME::$CLASS_NAME()
	: m_x(1),
	  m_Raw(new int(2)),
	  m_Unique(std::make_unique<int>(3)),
	  m_Shared(std::make_shared<int>(4))
{
	DEBUG_PRINT("$CLASS_NAME:: default constructor called");
}

// Copy constructor
$CLASS_NAME::$CLASS_NAME(const $CLASS_NAME& rhs)
	: m_x(rhs.m_x),
	  m_Raw(new int(*rhs.m_Raw)),
	  m_Unique(std::make_unique<int>(*rhs.m_Unique)),
	  m_Shared(std::make_shared<int>(*rhs.m_Shared))
{
	DEBUG_PRINT("$CLASS_NAME:: copy constructor called");
}

// Copy assignment operator
$CLASS_NAME& $CLASS_NAME::operator=($CLASS_NAME rhs) noexcept
{
	DEBUG_PRINT("$CLASS_NAME:: copy assignment operator called");

	swap(*this, rhs);
	return *this;
}

// Move constructor
$CLASS_NAME::$CLASS_NAME($CLASS_NAME&& rhs) noexcept
	: m_x(std::move(rhs.m_x)),
	  m_Raw(std::exchange(rhs.m_Raw, nullptr)),
	  m_Unique(std::move(rhs.m_Unique)),
	  m_Shared(std::move(rhs.m_Shared))
{
	DEBUG_PRINT("$CLASS_NAME:: move constructor called");
}

// Destructor
$CLASS_NAME::~$CLASS_NAME()
{
	DEBUG_PRINT("$CLASS_NAME:: destructor called");

	delete m_Raw;
}

void $CLASS_NAME::swap($CLASS_NAME& first, $CLASS_NAME& second) noexcept
{
	std::swap(first.m_x, second.m_x);
	std::swap(first.m_Raw, second.m_Raw);
	std::swap(first.m_Unique, second.m_Unique);
	std::swap(first.m_Shared, second.m_Shared);
}
EOL

  echo "Files $HEADER_FILE and $SOURCE_FILE have been created."
fi
