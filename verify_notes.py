#!/usr/bin/env python3
"""
Verification script for numeric examples in the exam notes
"""

import struct

def verify_ieee_conversion():
    """Verify IEEE 754 conversions mentioned in notes"""
    print("=== IEEE 754 Conversion Verification ===")
    
    # Test the examples from the notes
    hex_values = ["42AA4000", "4055480000000000"]
    expected = 85.125
    
    for hex_val in hex_values:
        if len(hex_val) == 8:
            val = struct.unpack('>f', bytes.fromhex(hex_val))[0]
            precision = "single"
        else:
            val = struct.unpack('>d', bytes.fromhex(hex_val))[0]
            precision = "double"
            
        print(f"{hex_val} ({precision}) = {val}")
        assert abs(val - expected) < 1e-10, f"Mismatch for {hex_val}: expected {expected}, got {val}"
    
    print("✓ All IEEE 754 conversions verified correctly\n")

def verify_binary_multiplication():
    """Verify binary multiplication examples"""
    print("=== Binary Multiplication Verification ===")
    
    # 9 x 12 = 108
    # 9 = 1001, 12 = 1100
    bin1, bin2 = "1001", "1100"
    expected_decimal = 108
    expected_binary = "1101100"
    
    num1 = int(bin1, 2)
    num2 = int(bin2, 2)
    product = num1 * num2
    product_bin = bin(product)[2:]
    
    print(f"{bin1}₂ × {bin2}₂ = {product_bin}₂")
    print(f"Decimal: {num1}₁₀ × {num2}₁₀ = {product}₁₀")
    
    assert product == expected_decimal, f"Expected {expected_decimal}, got {product}"
    assert product_bin == expected_binary, f"Expected {expected_binary}, got {product_bin}"
    
    print("✓ Binary multiplication verified correctly\n")

def verify_ieee_special_values():
    """Verify IEEE 754 special values"""
    print("=== IEEE 754 Special Values Verification ===")
    
    # Positive infinity
    pos_inf_single = struct.unpack('>f', bytes.fromhex('7f800000'))[0]
    pos_inf_double = struct.unpack('>d', bytes.fromhex('7ff0000000000000'))[0]
    
    # Negative infinity
    neg_inf_single = struct.unpack('>f', bytes.fromhex('ff800000'))[0]
    neg_inf_double = struct.unpack('>d', bytes.fromhex('fff0000000000000'))[0]
    
    # NaN
    nan_single = struct.unpack('>f', bytes.fromhex('7fc00000'))[0]
    nan_double = struct.unpack('>d', bytes.fromhex('7ff8000000000000'))[0]
    
    assert str(pos_inf_single) == 'inf', f"Expected inf, got {pos_inf_single}"
    assert str(pos_inf_double) == 'inf', f"Expected inf, got {pos_inf_double}"
    assert str(neg_inf_single) == '-inf', f"Expected -inf, got {neg_inf_single}"
    assert str(neg_inf_double) == '-inf', f"Expected -inf, got {neg_inf_double}"
    assert str(nan_single) == 'nan', f"Expected nan, got {nan_single}"
    assert str(nan_double) == 'nan', f"Expected nan, got {nan_double}"
    
    print("✓ All IEEE 754 special values verified correctly\n")

def verify_de_morgan():
    """Verify De Morgan's theorem via truth table"""
    print("=== De Morgan's Theorem Verification ===")
    
    # De Morgan's first theorem: ¬(A ∧ B) = ¬A ∨ ¬B
    print("Verifying: ¬(A ∧ B) = ¬A ∨ ¬B")
    
    all_match = True
    for A in [0, 1]:
        for B in [0, 1]:
            left = not (A and B)
            right = (not A) or (not B)
            if left != right:
                all_match = False
                print(f"Mismatch at A={A}, B={B}: left={left}, right={right}")
    
    if all_match:
        print("✓ De Morgan's first theorem verified correctly")
    
    # De Morgan's second theorem: ¬(A ∨ B) = ¬A ∧ ¬B
    print("Verifying: ¬(A ∨ B) = ¬A ∧ ¬B")
    
    all_match = True
    for A in [0, 1]:
        for B in [0, 1]:
            left = not (A or B)
            right = (not A) and (not B)
            if left != right:
                all_match = False
                print(f"Mismatch at A={A}, B={B}: left={left}, right={right}")
    
    if all_match:
        print("✓ De Morgan's second theorem verified correctly\n")

def main():
    print("Verifying numeric examples in COA Unit 3 exam notes...\n")
    
    try:
        verify_ieee_conversion()
        verify_binary_multiplication()
        verify_ieee_special_values()
        verify_de_morgan()
        
        print("🎉 All verifications passed! The notes contain correct numeric examples.")
        
    except AssertionError as e:
        print(f"❌ Verification failed: {e}")
        return 1
    except Exception as e:
        print(f"❌ Unexpected error during verification: {e}")
        return 1
    
    return 0

if __name__ == "__main__":
    exit(main())
