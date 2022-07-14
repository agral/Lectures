a = [0, 1, 2, 3]
b = a
a[0] = 101

method = "value" if a != b else "reference"
print(f"{method} semantics for lists")
