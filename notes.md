# COA Unit 3: Open Book Exam Notes
## ALU, Adders, Multiplication, Division, IEEE 754

---

# FORMULA SHEET

## Boolean Algebra & De Morgan's Laws
- **De Morgan's Theorem 1**: ¬(A ∧ B) = ¬A ∨ ¬B
- **De Morgan's Theorem 2**: ¬(A ∨ B) = ¬A ∧ ¬B
- **Bubbled OR**: NOR gate equivalent to AND with inverted inputs
- **Bubbled AND**: NAND gate equivalent to OR with inverted inputs

## Adder Circuits
- **Half Adder**: Sum = A ⊕ B, Carry = A ∧ B
- **Full Adder**: Sum = A ⊕ B ⊕ Cin, Cout = (A ∧ B) ∨ (B ∧ Cin) ∨ (A ∧ Cin)
- **Ripple Carry Adder Delay**: 
  - Sum delay: 4 gate delays per bit
  - Carry delay: 2 gate delays per bit
  - Total delay for n-bit: 2n + 2 gate delays
- **Carry Look-ahead Adder**:
  - Gi = Ai ∧ Bi (Generate)
  - Pi = Ai ⊕ Bi (Propagate)
  - Ci+1 = Gi ∨ (Pi ∧ Ci)
  - Ci+1 = Gi ∨ (Pi ∧ Gi-1) ∨ (Pi ∧ Pi-1 ∧ Gi-2) ∨ ... ∨ (Pi ∧ Pi-1 ∧ ... ∧ P0 ∧ C0)

## Multiplication Algorithms
- **Shift-and-Add**: 
  - Initialize product = 0
  - For each bit in multiplier (LSB to MSB):
    - If multiplier bit = 1: product += multiplicand
    - Shift multiplicand left by 1 bit
- **Booth Algorithm** (for n-bit operands):
  - Extend multiplier with LSB-1 = 0
  - Scan multiplier bits in pairs (current, previous)
  - 00 → 0, 01 → +1, 10 → -1, 11 → 0
  - Apply operation: 0 → no op, +1 → add M, -1 → subtract M
  - Shift right arithmetic after each step

## Division Algorithms
- **Restoring Division**:
  - Initialize: A=0, Q=dividend, M=divisor, count=n
  - For each iteration:
    1. Shift left AQ
    2. A = A - M
    3. If A ≥ 0: Set Q0 = 1
    4. Else: Set Q0 = 0, restore A = A + M
    5. Decrement count
- **Non-Restoring Division**:
  - Initialize: A=0, Q=dividend, M=divisor, count=n
  - For each iteration:
    1. Shift left AQ
    2. If previous step succeeded: A = A - M
       Else: A = A + M
    3. If A ≥ 0: Set Q0 = 1
    4. Else: Set Q0 = 0
    5. Decrement count
  - Final correction: If A < 0: A = A + M

## IEEE 754 Floating Point
- **Single Precision** (32-bit): 1 sign + 8 exponent + 23 fraction
  - Bias = 127
  - Value = (-1)^s × (1.f) × 2^(E-127)
- **Double Precision** (64-bit): 1 sign + 11 exponent + 52 fraction
  - Bias = 1023
  - Value = (-1)^s × (1.f) × 2^(E-1023)
- **Special Values**:
  - Zero: E=0, F=0 (±0 distinguished by sign bit)
  - Infinity: E=all 1's, F=0 (±∞ distinguished by sign bit)
  - NaN: E=all 1's, F≠0
- **Normal Range**:
  - Single: ±2^-126 to ±(2-2^-23)×2^127 ≈ ±1.18×10^-38 to ±3.4×10^38
  - Double: ±2^-1022 to ±(2-2^-52)×2^1023 ≈ ±2.2×10^-308 to ±1.8×10^308

---

# EXAM TACTICS
1. **Time Management**: 50 marks in ~90 seconds per mark → ~75 minutes total
2. **Show All Steps**: For calculative questions, show workings clearly
3. **Use Diagrams**: Sketch logic circuits when describing adders/dividers
4. **Verify Answers**: Use slide references to check your work
5. **Formula Sheet First**: Reference it during calculations
6. **Trace Tables**: Show intermediate states for algorithms
7. **Slide References**: Cite slides like [S64] to show preparation
8. **Units Matter**: Remember bit widths (4-bit, 8-bit, n-bit)
9. **Check Special Cases**: Zero, overflow, underflow in floating point
10. **Read Carefully**: Note if asking for signed/unsigned operations

---

