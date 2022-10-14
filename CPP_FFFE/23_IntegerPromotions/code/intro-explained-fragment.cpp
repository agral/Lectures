int main()
{
  long negative{-123};
  unsigned short positive{123};
  std::size_t unsigned_positive{456};

  print_comparison(negative, positive);           // A
  print_comparison(negative, unsigned_positive);  // B
  explain();
}

void explain() {
  std::cout << "-123(long) is "
    << static_cast<unsigned long>(-123)
    << "(unsigned long)\n";
}
