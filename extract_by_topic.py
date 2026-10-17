#!/usr/bin/env python3
"""
Extract content by topic areas from PPTX slides
"""

import os
import re

def extract_slide_text(slide_num):
    """Extract text from a specific slide"""
    slide_file = f"pptx_contents/ppt/slides/slide{slide_num}.xml"
    if not os.path.exists(slide_file):
        return None
    
    with open(slide_file, 'r') as f:
        content = f.read()
    
    # Extract all text elements
    text_elements = re.findall(r'<a:t>([^<]+)</a:t>', content)
    return ' '.join(text_elements)

def get_slide_range_text(start, end):
    """Get text from a range of slides"""
    all_text = []
    for i in range(start, end + 1):
        text = extract_slide_text(i)
        if text and text.strip():
            all_text.append(f"[Slide {i}] {text}")
    return '\n'.join(all_text)

def extract_topic_content():
    """Extract content for each major topic"""
    
    topics = {
        "ALU_Design": (1, 15),
        "De_Morgans_Law": (16, 25),
        "Adders": (26, 40),
        "Division": (41, 60),
        "Multiplication_Basics": (61, 80),
        "Booth_Algorithm": (81, 90),
        "Bit_Pair_Recoding": (91, 100),
        "Carry_Save": (101, 110),
        "IEEE_754": (111, 116)
    }
    
    print("=== EXTRACTED CONTENT BY TOPIC ===\n")
    
    for topic, (start, end) in topics.items():
        print(f"=== {topic.replace('_', ' ')} (Slides {start}-{end}) ===")
        content = get_slide_range_text(start, end)
        # Limit output to avoid too much text
        if len(content) > 1000:
            print(content[:1000] + "...\n[Content truncated]")
        else:
            print(content)
        print("\n" + "="*60 + "\n")

if __name__ == "__main__":
    extract_topic_content()
