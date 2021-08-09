def gray_code(n):
    return [i^(i>>1) for i in range(1<<n)]

if __name__=="__main__":
    n = int(input("Enter number:"))
    while n >= 0:
        print(f"Grey code of {n} bit binary numbers are {gray_code(n)}.")
        n = int(input("Enter number:"))