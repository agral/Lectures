constexpr auto fib(int n) {
  if (n<0) {
    throw "Must use nonnegative integers";
  }
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return fib(n-1) + fib(n-2);
}

int main()
{
  constexpr int rv = fib(7);
  return rv;
}
