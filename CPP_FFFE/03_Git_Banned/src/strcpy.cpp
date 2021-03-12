#include <cstdio>
#include <cstring>

int main()
{
  char buffer[100];
  const char* LONG_TEXT = "This is quite a long string of text";
  strcpy(buffer, LONG_TEXT);
  printf("%s\n", buffer);

  const char* TEST_TEXT = "test string";
  const size_t LENGTH = 4;

  strncpy(buffer, TEST_TEXT, LENGTH);
  printf("%s\n", buffer);

  return 0;
}
