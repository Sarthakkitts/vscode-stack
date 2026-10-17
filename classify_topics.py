#!/usr/bin/env python3
"""
Classify topics as calculative/derivation/theory and analyze slide distribution
"""

def classify_topics():
    """Classify each topic based on content analysis"""
    
    # Based on slide analysis from extract_by_topic.py
    topic_classification = {
        "ALU_Design": {
            "slides": "1-15",
            "type": "theory",
            "description": "ALU definition, components, design principles"
        },
        "De_Morgans_Law": {
            "slides": "16-25", 
            "type": "derivation",
            "description": "Boolean algebra theorems, logic gate implementations"
        },
        "Adders": {
            "slides": "26-40",
            "type": "calculative",
            "description": "Half/full adder design, ripple carry, carry look-ahead"
        },
        "Division": {
            "slides": "41-60",
            "type": "calculative",
            "description": "Restoring/non-restoring division algorithms, examples"
        },
        "Multiplication_Basics": {
            "slides": "61-80",
            "type": "calculative",
            "description": "Shift-and-add multiplication, array multipliers"
        },
        "Booth_Algorithm": {
            "slides": "81-90",
            "type": "calculative",
            "description": "Booth multiplication algorithm, bit-pair recoding"
        },
        "Bit_Pair_Recoding": {
            "slides": "91-100",
            "type": "calculative",
            "description": "Booth bit-pair recoding technique"
        },
        "Carry_Save": {
            "slides": "101-110",
            "type": "calculative",
            "description": "Carry-save addition, summand reduction"
        },
        "IEEE_754": {
            "slides": "111-116",
            "type": "theory",
            "description": "Floating point representation, special values, ranges"
        }
    }
    
    print("=== TOPIC CLASSIFICATION ===\n")
    
    calculative_count = 0
    derivation_count = 0
    theory_count = 0
    
    for topic, info in topic_classification.items():
        print(f"{topic.replace('_', ' ')}:")
        print(f"  Slides: {info['slides']}")
        print(f"  Type: {info['type'].upper()}")
        print(f"  Description: {info['description']}\n")
        
        if info['type'] == 'calculative':
            calculative_count += 1
        elif info['type'] == 'derivation':
            derivation_count += 1
        elif info['type'] == 'theory':
            theory_count += 1
    
    print("=== SUMMARY ===")
    print(f"Calculative topics: {calculative_count}")
    print(f"Derivation topics: {derivation_count}")
    print(f"Theory topics: {theory_count}")
    
    total_slides = 116
    print(f"\nTotal slides: {total_slides}")
    
    # Predict likely 5-question split based on topic importance and type
    print("\n=== PREDICTED 5-QUESTION SPLIT ===")
    print("Based on topic weightage and exam pattern:")
    print("1. ALU Design (Theory) - Definition, components, specifications")
    print("2. Adders (Calculative) - Full adder design, ripple carry example")
    print("3. Division (Calculative) - Restoring vs non-restoring division trace")
    print("4. Multiplication (Calculative) - Booth algorithm or bit-pair recoding")
    print("5. IEEE 754 (Theory) - Floating point representation, special values")
    
    print("\nRationale:")
    print("- ALU is foundational (theory)")
    print("- Adders are core arithmetic (calculative)")
    print("- Division has detailed algorithms (calculative)")
    print("- Booth algorithm is important for signed multiplication (calculative)")
    print("- IEEE 754 is essential for floating point (theory)")

if __name__ == "__main__":
    classify_topics()
