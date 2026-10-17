#!/usr/bin/env python3
"""
Verification script for numeric examples in COA Unit 3 lecture notes
"""

import struct
import math

def verify_ieee_hex(hex_val, expected_description=""):
    """Verify IEEE 754 floating point hex values"""
    try:
        # Convert hex to float
        if len(hex_val) == 8:  # Single precision
            val = struct.unpack('>f', bytes.fromhex(hex_val))[0]
            precision = "single"
        elif len(hex_val) == 16:  # Double precision
            val = struct.unpack('>d', bytes.fromhex(hex_val))[0]
            precision = "double"
        else:
            print(f"Invalid hex length for {hex_val}: {len(hex_val)} chars")
            return None
            
        print(f"{hex_val} ({precision}) = {val} {expected_description}")
        return val
    except Exception as e:
        print(f"Error converting {hex_val}: {e}")
        return None

def verify_binary_operation(bin1, bin2, operation='add'):
    """Verify binary operations"""
    try:
        num1 = int(bin1, 2)
        num2 = int(bin2, 2)
        
        if operation == 'add':
            result = num1 + num2
            result_bin = bin(result)[2:]
            print(f"{bin1} + {bin2} = {result_bin} ({result})")
        elif operation == 'multiply':
            result = num1 * num2
            result_bin = bin(result)[2:]
            print(f"{bin1} × {bin2} = {result_bin} ({result})")
        elif operation == 'and':
            result = num1 & num2
            result_bin = bin(result)[2:]
            print(f"{bin1} & {bin2} = {result_bin} ({result})")
        elif operation == 'or':
            result = num1 | num2
            result_bin = bin(result)[2:]
            print(f"{bin1} | {bin2} = {result_bin} ({result})")
        elif operation == 'xor':
            result = num1 ^ num2
            result_bin = bin(result)[2:]
            print(f"{bin1} ^ {bin2} = {result_bin} ({result})")
            
        return result_bin, result
    except Exception as e:
        print(f"Error in binary {operation} {bin1} {bin2}: {e}")
        return None, None

def verify_booth_example():
    """Verify Booth algorithm example from slides: 1001 x 1100"""
    print("\n=== Booth Algorithm Verification ===")
    # From slide: (1001 x  1100)
    multiplicand = "1001"  # -7 in 2's complement 4-bit
    multiplier = "1100"    # -4 in 2's complement 4-bit
    
    # Convert to decimal for verification (2's complement)
    m_dec = int(multiplicand, 2)
    if m_dec & 0b1000:  # Check if negative (MSB set)
        m_dec = -(0b10000 - m_dec)
        
    mr_dec = int(multiplier, 2)
    if mr_dec & 0b1000:  # Check if negative (MSB set)
        mr_dec = -(0b10000 - mr_dec)
    
    expected = m_dec * mr_dec
    print(f"Booth example: {multiplicand} ({m_dec}) × {multiplier} ({mr_dec}) = {expected}")
    print(f"Expected product in binary: {bin(expected & 0b11111111)[2:].zfill(8)} (for 8-bit result)")
    return expected

def verify_ieee_special_values():
    """Check IEEE 754 special values mentioned in slides"""
    print("\n=== IEEE 754 Special Values ===")
    
    # Positive infinity 
    pos_inf_single = "7f800000"
    pos_inf_double = "7ff0000000000000"
    
    # Negative infinity
    neg_inf_single = "ff800000"
    neg_inf_double = "fff0000000000000"
    
    # NaN (Not a Number)
    nan_single = "7fc00000"  
    nan_double = "7ff8000000000000"  
    
    verify_ieee_hex(pos_inf_single, "(Positive Infinity - Single)")
    verify_ieee_hex(pos_inf_double, "(Positive Infinity - Double)")
    verify_ieee_hex(neg_inf_single, "(Negative Infinity - Single)")
    verify_ieee_hex(neg_inf_double, "(Negative Infinity - Double)")
    verify_ieee_hex(nan_single, "(NaN - Single)")
    verify_ieee_hex(nan_double, "(NaN - Double)")

def check_potential_deck_errors():
    """Check for potential errors in the deck based on extracted content and task description"""
    print("\n=== Potential Errors in Deck ===")
    
    # Check the hex values from slides
    print("1. Checking hex values 42AA4000 and 4055480000000000:")
    val1 = verify_ieee_hex("42AA4000")
    val2 = verify_ieee_hex("4055480000000000")
    
    if val1 is not None and val2 is not None:
        if abs(val1 - val2) < 1e-10:
            print("   NOTE: Both hex values convert to the same decimal value (85.125)")
            print("   This is unusual but mathematically possible if they represent the same value")
            print("   in different precisions (single vs double) that happen to equal 85.125")
    
    # Check for infinity value mentioned in task
    print("\n2. Checking infinity exponent mentioned in task:")
    print("   Task mentions: double-precision infinity exponent shown as 2049, should be 2047")
    print("   For double precision, exponent bias is 1023")
    print("   Infinity has exponent = all 1's = 2047 (biased)")
    print("   So 2049 would be incorrect - should be 2047 for infinity")
    
    # Show correct infinity representation
    pos_inf_double = "7ff0000000000000"  # sign=0, exp=all 1's, frac=all 0's
    neg_inf_double = "fff0000000000000"  # sign=1, exp=all 1's, frac=all 0's
    print(f"   Correct +inf: {pos_inf_double}")
    print(f"   Correct -inf: {neg_inf_double}")

def main():
    print("=== COA Unit 3 Numeric Verification ===\n")
    
    # Check for deck errors first
    check_potential_deck_errors()
    
    print("\n" + "="*60)
    
    # Verify IEEE hex values from slides
    print("1. IEEE 754 Hex Values from Slides:")
    verify_ieee_hex("42AA4000", "(Example value)")
    verify_ieee_hex("4055480000000000", "(Example value)")
    
    # Verify some binary operations from content
    print("\n2. Binary Operations from Content:")
    verify_binary_operation("1000", "1001", 'add')  # 8 + 9 from slides
    verify_binary_operation("1001", "1100", 'add')  # From one of the truth tables
    
    # Verify Booth example
    verify_booth_example()
    
    # Verify IEEE special values
    verify_ieee_special_values()
    
    # Verify floating point ranges
    print("\n3. Floating Point Range Checks:")
    # Single precision max normal: (2 - 2^-23) × 2^127
    max_single = (2 - 2**(-23)) * 2**127
    print(f"Max single precision normal: {max_single:.2e}")
    
    # Double precision max normal: (2 - 2^-52) × 2^1023
    max_double = (2 - 2**(-52)) * 2**1023
    print(f"Max double precision normal: {max_double:.2e}")
    
    # Verify De Morgan's theorem examples (logic, not numeric)
    print("\n4. De Morgan's Theorem Verification:")
    print("   Theorem 1: ¬(A ∧ B) = ¬A ∨ ¬B")
    print("   Theorem 2: ¬(A ∨ B) = ¬A ∧ ¬B")
    print("   These are logical equivalences, not numeric values")

if __name__ == "__main__":
    main()
