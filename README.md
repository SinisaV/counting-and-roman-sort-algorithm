# Sorting Program

This C++ program provides two sorting algorithms, Counting Sort and Roman Sort. It reads a list of integers from a file, performs the specified sorting algorithm, and then writes the sorted list to an output file.

## Usage

### Compilation and Execution

```
g++ main.cpp -o sorting_program
./sorting_program <algorithm_flag> <input_filename>
```

#### Sorting Algorithm Flag

Choose the sorting algorithm by specifying the appropriate flag:

- `0`: Counting Sort
- `1`: Roman Sort

#### Input Filename

Provide the path to the input file containing a list of integers.

### Example
```
./sorting_program 0 input.txt
```

This command will perform Counting Sort on the integers in the input.txt file and create an output file named out.txt with the sorted result.

## Sorting Algorithms
### Counting Sort
A linear time sorting algorithm suitable for a specific range of integers.

### Roman Sort
A unique sorting algorithm designed for lists of integers.

## Notes
The program assumes valid input files with correct integer data.
