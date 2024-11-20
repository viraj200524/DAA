import heapq
from collections import defaultdict, Counter
import readbooks as rb
from tabulate import tabulate

# Define a class for Huffman Tree nodes
class HuffmanNode:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    # Compare nodes based on frequency for heapq
    def __lt__(self, other):
        return self.freq < other.freq

# Build the Huffman Tree
def build_huffman_tree(text):
    freq = Counter(text)
    heap = [HuffmanNode(char, freq) for char, freq in freq.items()]
    heapq.heapify(heap)
    
    while len(heap) > 1:
        node1 = heapq.heappop(heap)
        node2 = heapq.heappop(heap)
        merged = HuffmanNode(None, node1.freq + node2.freq)
        merged.left = node1
        merged.right = node2
        heapq.heappush(heap, merged)
    
    return heap[0], freq

# Generate Huffman Codes
def generate_codes(node, code, codes):
    if node is None:
        return
    
    if node.char is not None:
        codes[node.char] = code
    
    generate_codes(node.left, code + "0", codes)
    generate_codes(node.right, code + "1", codes)

# Compress the text using Huffman Coding
def compress(text):
    root, freq = build_huffman_tree(text)
    codes = {}
    generate_codes(root, "", codes)
    compressed = ''.join([codes[char] for char in text])
    return compressed, codes, freq

# Calculate the compression ratio
def calculate_compression_ratio(original_text, compressed_text):
    original_size = len(original_text) * 8  # Original text size in bits (1 char = 8 bits)
    compressed_size = len(compressed_text)  # Compressed text size (already in bits)
    return original_size, compressed_size

def process_file(file_type, file_path_or_url):
    # Extract text based on the file type
    if file_type == 'html':
        text = rb.extract_text_from_html(file_path_or_url)  # URL for HTML files
    elif file_type == 'docx':
        text = rb.extract_text_from_doc(file_path_or_url)  # DOCX file path
    elif file_type == 'pdf':
        text = rb.extract_text_from_pdf_plumber(file_path_or_url)  # PDF file path
    elif file_type == 'txt':
        text = rb.extract_text_from_txt(file_path_or_url)  # TXT file path
    else:
        raise ValueError(f"Unsupported file type: {file_type}")
    
    # Print the extracted text
    print(f"Contents of {file_path_or_url}:\n{text}\n")

    # Compress the extracted text
    compressed_text, huffman_codes, frequencies = compress(text)
    original_size, compressed_size = calculate_compression_ratio(text, compressed_text)
    
    # Prepare table for Huffman codes and frequencies
    table_data = [[char, freq, huffman_codes[char]] for char, freq in frequencies.items()]
    headers = ["Character", "Frequency", "Huffman Code"]
    table = tabulate(table_data, headers, tablefmt="grid")

    # Output the results
    print(f"Huffman Codes and Frequencies:\n{table}\n")
    print(f"Original text size (in bits): {original_size}")
    print(f"Compressed text size (in bits): {compressed_size}")
    print(f"Compression ratio: {compressed_size / original_size}")
    return compressed_text, huffman_codes

# Example usage:
print('\n1. HTML : \n')
process_file('html', 'file_1.html')
print('\n')
process_file('html', 'file_2.html')

# For DOCX file (provide the file path):
print('\n2. Doc : \n')
process_file('docx', 'file_1.docx')
print('\n')
process_file('docx', 'file_2.docx')

# For PDF file (provide the file path):
print('\n3. PDF : \n')
process_file('pdf', 'file_1.pdf')
print('\n')
process_file('pdf', 'file_2.pdf')

# For TXT file (provide the file path):
print('\n4. TXT : \n')
process_file('txt', 'file_1.txt')
print('\n')
process_file('txt', 'file_2.txt')
