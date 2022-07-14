class Fraction {
  public int numerator, denominator;
  public Fraction(int n, int d) {
    numerator = n;
    denominator = d;
  }
}

class Passing {
  static void change_fraction(Fraction f) {
    f.numerator = 1;
    f.denominator = 2;
    System.out.printf("Inside change_fraction, f == (%d/%d)\n", f.numerator, f.denominator);
  }

  static void make_new_fraction(Fraction f) {
    f = new Fraction(8, 13);
    System.out.printf("Inside make_new_fraction, f == (%d/%d)\n", f.numerator, f.denominator);
  }

  public static void main(String[] args) {
    Fraction a = new Fraction(3, 5);
    System.out.printf("Before change_fraction, a == (%d/%d)\n", a.numerator, a.denominator);
    change_fraction(a);
    System.out.printf("After change_fraction, a == (%d/%d)\n", a.numerator, a.denominator);
    System.out.println();
    System.out.printf("Before make_new_fraction, a == (%d/%d)\n", a.numerator, a.denominator);
    make_new_fraction(a);
    System.out.printf("After make_new_fraction, a == (%d/%d)\n", a.numerator, a.denominator);
  }
}
