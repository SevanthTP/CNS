def euclid(m, n):
    if n == 0:
        return m
    else:
        r = m % n
        return euclid(n, r)

def exteuclid(a, b):
    r1 = a
    r2 = b
    s1 = int(1)
    s2 = int(0)
    t1 = int(0)
    t2 = int(1)
    while r2 > 0:
        q = r1 // r2
        r = r1 - q * r2
        r1 = r2
        r2 = r
        s = s1 - q * s2
        s1 = s2
        s2 = s
        t = t1 - q * t2
        t1 = t2
        t2 = t
    if t1 < 0:
        t1 += a
    return (r1, t1)

p = 823
q = 953
n = p * q
pn = (p - 1) * (q - 1)
key = []
for i in range(2, pn):
    gcd = euclid(pn, i)
    if gcd == 1:
        key.append(i)

e = int(313)
r, d = exteuclid(pn, e)
if r == 1:
    d = d % pn
    print("decryption key is: ", d)
else:
    print("Multiplicative inverse for the given encryption key does not exist. Choose a different encryption key")

m = 56234
s = (m ** d) % n
m1 = (s ** e) % n
if m == m1:
    print("As m = m1, Accept the message sent by Alice")
else:
    print("As m not equal to m1, Do not accept the message sent by Alice")