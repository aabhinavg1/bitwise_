# # Adder - A Bitwise Addition Algorithm

## Overview

An **adder** is a fundamental digital circuit (or algorithm) that performs the addition of binary numbers. In computer systems:

- **Hardware Perspective:** An adder is built using logic gates (XOR, AND, OR) in CPUs/ALUs.
- **Software Perspective:** An adder is implemented as a function that mimics the behavior using bitwise operations.

## Key Concepts for Bitwise Addition

### 1. XOR (^) - Partial Sum Without Carry
The XOR operation computes the raw sum of bits without considering the carry.

#### Behavior:
- `0 ^ 0 = 0`
- `0 ^ 1 = 1`
- `1 ^ 0 = 1`
- `1 ^ 1 = 0` (Carry is ignored)

#### Role: Computes the raw sum of bits without carry consideration.

### 2. AND (&) + Left Shift (<<) - Carry Calculation
The AND operation identifies where both bits are `1`, indicating a carry, while the left shift propagates the carry to the next higher bit position.

#### AND Operation:
- `1 & 1 = 1` (carry is generated)
- All other combinations yield `0`.

#### Left Shift (<<): Moves the carry to the next higher bit.

## Algorithm Steps

**Input:** Two integers `a` and `b`.

### Loop Until No Carry (`b == 0`):
1. **Compute Carry:**
   - `carry = (a & b) << 1`
   - (Detects carry bits and shifts them left.)

2. **Update Sum:**
   - `a = a ^ b`
   - (Stores the partial sum without carry.)

3. **Propagate Carry:**
   - `b = carry`
   - (Repeats the process for the next bit position.)

**Result:** `a` holds the final sum after all iterations.

---

## Ensuring 32-Bit Operation

Use `uint32_t` (C/C++) to ensure 32-bit operation.

### Why This Works for 32-Bit Numbers

- **Bitwise Parallelism:** XOR, AND, and shifts operate on all 32 bits simultaneously.
- **Termination Guarantee:** Each iteration reduces the carry (`b`), eventually reaching `0`.
- **Overflow Handling:** Natural wraparound (like in hardware) if the result exceeds 32 bits.

### Example: `5 (0101)` + `3 (0011)`

| Step | a (XOR)     | b (Carry) | Explanation                                      |
|------|-------------|-----------|--------------------------------------------------|
| 1    | 0101 ^ 0011 = 0110 (6) | (0101 & 0011) << 1 = 0010 (2) | Partial sum = 6, carry = 2                      |
| 2    | 0110 ^ 0010 = 0100 (4) | (0110 & 0010) << 1 = 0100 (4) | Partial sum = 4, carry = 4                      |
| 3    | 0100 ^ 0100 = 0000 (0) | (0100 & 0100) << 1 = 1000 (8) | Partial sum = 0, carry = 8                      |
| 4    | 0000 ^ 1000 = 1000 (8) | (0000 & 1000) << 1 = 0000 (0) | Done! Final result = 8                          |

---

## Ensuring 32-Bit Width

By using `uint32_t` for operations, we prevent unintended sign-extension or overflow, ensuring the result remains within 32 bits.

### Manual Bitmasking (If Needed)

If you want to discard overflow bits, mask the result with `0xFFFFFFFF` to ensure it remains within 32-bit bounds.

---

## Extending to 64-Bit

The same logic applies for 64-bit operations:

- Use `uint64_t` and ensure operations respect 64-bit boundaries.

---

## Key Takeaways

- **XOR =** Sum without carry.
- **AND + Shift =** Carry propagation.
- Loop until carry is zero.
- **32-bit safety:** Use fixed-width types or apply masking.

---

This adder algorithm demonstrates bitwise addition at the hardware level, providing a deep understanding of how addition operates in digital circuits and computer systems.
