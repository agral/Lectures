a = 10
b = a
a = 20
print(f"b == {b}")
semantic_method = "value" if b == 10 else "reference"
print(f"{semantic_method} semantics for primitives")
