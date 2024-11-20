import pdb

def add_numbers(a, b):
    pdb.set_trace()  # Set a breakpoint
    # Intentional issue: using string concatenation instead of addition
    result = str(a) + str(b)
    return result

def main():
    x = 5
    y = 10
    print("Before calling add_numbers")
    sum_result = add_numbers(x, y)
    print("After calling add_numbers")
    print(f"The sum is: {sum_result}")

if __name__ == "__main__":
    main()
