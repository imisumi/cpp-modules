#!/bin/bash

# Define ANSI color codes
GREEN="\033[0;32m"
RED="\033[0;31m"
RESET="\033[0m"

# Function to generate a random sequence of numbers
generate_random_numbers() {
    local num_count=$((RANDOM % 3000 + 1))  # Number of numbers (1-3000)
    echo "$num_count"
}

# Function to run the program with random arguments
run_test() {
    local num_count="$1"
    local args=()  # Initialize an empty array to hold the arguments

    # Generate random numbers and store them as individual arguments
    for ((i=0; i<num_count; i++)); do
        args+=($((RANDOM % 10000 + 1)))  # Random numbers between 1 and 10000
    done

    # Run the program with the generated arguments, suppress output
    ./PmergeMe "${args[@]}" > /dev/null 2>&1
    local exit_code=$?

    # Check if the program returns 1 (error)
    if [ $exit_code -eq 1 ]; then
        echo -e "${RED}FAIL: $num_count${RESET}"
        echo "Sequence: ${args[@]}"  # Print the sequence of numbers if it fails
        exit 1  # Exit on failure
    else
        echo -e "${GREEN}SUCCESS: $num_count${RESET}"
    fi
}

# Loop to run the test multiple times
for i in {1..10000}; do  # You can adjust the number of iterations
    num_count=$(generate_random_numbers)
    run_test "$num_count"
    # sleep 1  # Optional: Adding a small delay between runs for stability
done
