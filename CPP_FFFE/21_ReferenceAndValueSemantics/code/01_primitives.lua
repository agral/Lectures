local a = 10
local b = a
a = 20
print(string.format("b == %d", b))
print(string.format(
    "%s semantics for primitives",
    (b == 10 and "value" or "reference")
))
