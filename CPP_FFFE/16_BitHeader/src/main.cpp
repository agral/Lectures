#include <bit>
#include <bitset>
#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::vector;
using std::cout;

const vector<uint8_t> INTERESTING_NUMBERS = {
  0,
  0b1010, /* 10 */
  0b00001111, /* 15 */
  0b00100000, /* 32 */
  0b00111111, /* 63 */
  0b10000000, /* 128 */
  0b10101010, /* 170 */
  0b11111111 /* 255 */
};

std::string pretty(uint8_t number)
{
  std::stringstream ss{};
  ss << static_cast<unsigned>(number) << " [" << std::bitset<8>(number) << "]";
  return ss.str();
}

void demo_endian() {
  cout << "Endianness test:\nThis machine uses ";
  if constexpr (std::endian::native == std::endian::big) {
    cout << "big-endian\n";
  }
  else if constexpr (std::endian::native == std::endian::little) {
    cout << "little-endian\n";
  }
  else {
    cout << "mixed-endian\n";
  }
}

void demo_popcount() {
  for (const auto& num : INTERESTING_NUMBERS) {
    cout << "popcount(" << pretty(num) << ") == " << std::popcount(num) << '\n';
  }
}

void demo_has_single_bit() {
  for (const auto& num: INTERESTING_NUMBERS) {
    cout << "has_single_bit(" << pretty(num) << ") == " << std::has_single_bit(num) << '\n';
  }
}

void demo_bit_floor_ceil() {
  for (const auto& num: INTERESTING_NUMBERS) {
    cout << "bit_floor(" << pretty(num) << ") == " << pretty(std::bit_floor(num)) << '\n'
         << "bit_ceil(" << pretty(num) << ") == " << pretty(std::bit_ceil(num)) << "\n\n";
  }
}

void demo_bit_width() {
  for (const auto& num: INTERESTING_NUMBERS) {
    cout << "bit_width(" << pretty(num) << ") == " << static_cast<unsigned>(std::bit_width(num)) << '\n';
  }
}

void demo_countl_countr_zero() {
  for (const auto& num: INTERESTING_NUMBERS) {
    cout << "countl_zero(" << pretty(num) << ") == " << static_cast<unsigned>(std::countl_zero(num)) << '\n'
         << "countr_zero(" << pretty(num) << ") == " << static_cast<unsigned>(std::countr_zero(num)) << "\n\n";
  }
}
void demo_countl_countr_one() {
  for (const auto& num: INTERESTING_NUMBERS) {
    cout << "countl_one(" << pretty(num) << ") == " << static_cast<unsigned>(std::countl_one(num)) << '\n'
         << "countr_one(" << pretty(num) << ") == " << static_cast<unsigned>(std::countr_one(num)) << "\n\n";
  }
}

int main()
{
  // std::endian() - test the endianness on current machine
  demo_endian();
  cout << "\n";

  // std::popcount() - return the number of set (1) bits in the provided argument
  demo_popcount();

  // std::has_single_bit() - return true if a number is a power of two
  demo_has_single_bit();

  // std::bit_floor() - return the largest power of two not greater than the provided argument
  // std::bit_ceil() - return the smallest power of two not smaller than the provided argument
  demo_bit_floor_ceil();

  // std::bit_width() - return the smallest number of bits necessary to represent the provided argument
  demo_bit_width();

  // std::rotl(), std::rotr() - compute the result of bitwise left/right-rotating the number by n digits
  {
    uint8_t num{0b00110001};
    cout << "num = " << pretty(num) << "\n";
    cout << "rotl(num, 1) = " << pretty(std::rotl(num, 1)) << "\n";
    cout << "rotl(num, 3) = " << pretty(std::rotl(num, 3)) << "\n";
    cout << "rotr(num, 1) = " << pretty(std::rotr(num, 1)) << "\n";
    cout << "rotr(num, 3) = " << pretty(std::rotr(num, 3)) << "\n";
  }
  // std::countl_zero - return the number of consecutive '0' bits, starting from the MSB
  // std::countr_zero - return the number of consecutive '0' bits, starting from the LSB
  // std::countl_one - return the number of consecutive '1' bits, starting from the MSB
  // std::countr_one - return the number of consecutive '1' bits, starting from the LSB
  demo_countl_countr_zero();
  demo_countl_countr_one();
}
