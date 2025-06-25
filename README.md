# 📘 Complex CLI Calculator

A command-line calculator for complex numbers written in C.  
This program defines a new `complex` type using `typedef`, and supports several operations on complex numbers via user input.

---

## 🧱 Data Structure

The `complex` type is implemented using `typedef` and represents a complex number in the form:

```
a + bi
```

The program predefines six variables of type `complex`: `A`, `B`, `C`, `D`, `E`, `F`.  
At startup, all variables are initialized to `0 + 0i`.

---

## ⚙️ Compilation

To compile the project:

```bash
gcc main.c -o complex_calc -lm
```

> Note: `-lm` is required to link the math library for `sqrt`, `fabs`, etc.

---

## ▶️ Usage

Once compiled, run the program:

```bash
./complex_calc
```

Then, enter one command per line. To exit, use the `stop` command.

---

## 🧪 Supported Commands

| Command                      | Description                                         |
|------------------------------|-----------------------------------------------------|
| `read_comp A, r, i`          | Sets complex variable A to real `r` and imaginary `i` |
| `print_comp A`               | Prints the value of complex variable A             |
| `add_comp A, B`              | Adds complex A + B and prints the result           |
| `sub_comp A, B`              | Subtracts B from A (A - B) and prints the result    |
| `mult_comp_real A, r`        | Multiplies complex A by real number `r`            |
| `mult_comp_img A, i`         | Multiplies complex A by imaginary number `i`       |
| `mult_comp_comp A, B`        | Multiplies complex A * B and prints the result     |
| `abs_comp A`                 | Calculates and prints the absolute value of A      |
| `stop`                       | Exits the program                                  |

---

## 🧾 Example Input

```text
read_comp A, 3, -2
read_comp B, 1.5, 4
print_comp A
add_comp A, B
mult_comp_real A, 2
abs_comp B
stop
```

---

## 🧠 Features and Challenges

This project includes:

- Handling and parsing user input in real time
- String parsing and argument extraction using standard C functions
- Detecting and reporting syntax and logical errors
- Printing detailed and user-friendly error messages for invalid input (e.g., illegal variable names, missing parameters, invalid separators)
- Managing program flow using structured functions for each command

---

## 📄 License

This project is for educational purposes and has no specific license.
