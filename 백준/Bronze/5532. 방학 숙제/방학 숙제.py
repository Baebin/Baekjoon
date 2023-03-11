if __name__ == "__main__":
    L = int(input())
    A = int(input())
    B = int(input())
    C = int(input())
    D = int(input())

    ans = max((A // C) + (A % C != 0), (B // D) + (B % D != 0))
    print(L - ans)