# Taylor Series Approximation for Sine and Cosine in C

This project is a C program that calculates **sin(x)** and **cos(x)** using their Taylor series (Maclaurin series) expansions.  
It compares the approximated values with the built-in `sin()` and `cos()` functions from `math.h` and shows the percentage error.

---

## What the program does

- Asks the user to:
  - Enter an angle in **degrees**
  - Enter the number of **Taylor series terms**
- Converts the angle from degrees to **radians**
- Approximates:
  - `sin(x)` using the Taylor series for sine
  - `cos(x)` using the Taylor series for cosine
- Uses a **recursive factorial function** in the Taylor formulas
- Compares the Taylor results with:
  - `sin(x)` from `math.h`
  - `cos(x)` from `math.h`
- Calculates and prints the **percentage error** for each function  
  - If the true value is exactly `0`, it prints that the error percentage is *not possible (true value is 0)* to avoid division by zero.

---

## Taylor series used

The program uses these series expansions:

**Sine:**

\[
\sin(x) = \sum_{n=0}^{\infty} (-1)^n \frac{x^{2n+1}}{(2n+1)!}
\]

**Cosine:**

\[
\cos(x) = \sum_{n=0}^{\infty} (-1)^n \frac{x^{2n}}{(2n)!}
\]

The user chooses how many terms to include.  
More terms usually give a better approximation, especially for angles further from 0.

---

## Files

- `main.c` – contains:
  - `main()` function
  - `factorial()` (recursive)
  - `degree_to_radian()`
  - `sine_taylor()`
  - `cosine_taylor()`

---

## How to compile

Use `gcc` (or any C compiler) and link the math library:

```bash
gcc main.c -o taylor -lm
