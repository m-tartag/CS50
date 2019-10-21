  
from cs50 import get_int

def main():
    height = 0
    while(height > 8 or height < 1):
        height = get_int("Enter Height: ")

# EZLOOP
    for i in range (height):
        print(" " * (height - (i + 1)) + "#" * (i + 1) + "  " + "#" * (i + 1))


if __name__ == "__main__":
    main()