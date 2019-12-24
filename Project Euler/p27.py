
# 함수 검증


def euler(x, a, b):
    prime = x**2 + a * x + b
    # print(prime)
    if prime < 0:
        return 4
    else:
        return int(prime)

# 소수 검증


def prime_check(x):
    mul = [1]
    for i in range(2, int(x**(1 / 2) + 1)):
        if x % i == 0:
            mul.append(i)
    if len(mul) == 1:
        return True
    else:
        return False


def euler_formula(a, b):
    n = 0
    chk = prime_check(1)
    while chk:
        x = euler(n, a, b)
        chk = prime_check(x)
        n = n + 1
    return n - 1


elements = [(0, 0, 0)]
for a in range(-999, 1000):
    for b in range(-999, 1000):
        n = euler_formula(a, b)
        element = (n, a, b)
        if elements[0][0] < n:
            elements[0] = element
            print(elements)
        else:
            pass
