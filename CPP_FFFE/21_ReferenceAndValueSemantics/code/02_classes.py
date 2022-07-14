class Fraction:
    def __init__(self, n, d):
        self.numerator = n
        self.denominator = d

a = Fraction(3, 5)
b = a
a.numerator = 0

method = "value" if a != b else "reference"
print(f"{method} semantics for classes")
