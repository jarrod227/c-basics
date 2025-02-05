# Palindrome Number Checker

## Description

This project contains a C program that checks whether a given integer is a palindrome. A palindrome is a number that remains the same when its digits are reversed.

## Features

- Efficient algorithm that only processes half of the digits.
- No extra space required apart from integer variables.
- Handles edge cases like negative numbers and trailing zeros.

## Compilation Instructions

To compile the program using GCC, run:

```sh
gcc PalindromeNumber.c -o PalindromeNumber
```

## Running the Program

### On Linux/macOS:
```sh
./PalindromeNumber
```

### On Windows (Command Prompt):
```cmd
PalindromeNumber.exe
```

### On Windows (PowerShell):
```powershell
.\PalindromeNumber.exe
```

## Expected Output

- If the number is a palindrome:
  ```
  x = 142878241 is Palindrome
  ```
- If the number is not a palindrome:
  ```
  x = 12345 is not Palindrome
  ```

## Complexity Analysis

- **Time Complexity**: \(O(\log_{10} N)\) – Only half of the digits are processed.
- **Space Complexity**: \(O(1)\) – No additional memory is used.
