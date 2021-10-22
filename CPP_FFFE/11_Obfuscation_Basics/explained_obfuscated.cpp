#include <cstdio>

// 1. The units array could be converted into an array:
const char* const units[] = {
  "zero", "jeden", "dwa", "trzy", "cztery", "pięć", "sześć", "siedem", "osiem", "dziewięć"};

const char* u="$)/38?FNU[Twój polski numer to %s\n\0zero\0jeden\0dwa\0trzy\0cztery\0pięć\0sześć\0siedem\0osiem\0dziewięć";
///////////////0000000000111111111122222222223333 3 33334 444444 4445 55555 5555666 66666 777777 7788888 888889 99999999
///////////////0123456789012456789012345678901234 5 67890 123456 7890 12345 6789012 34579 012357 8901234 567890 12345679


// Offsets: 36, 41, 47, 51, 56, 63, 70, 78, 85, 91
int main()
{
  int a;scanf("%d",&a);printf(u+10,u+u[a]);
  //for(auto v=0;v<10;++v)printf(u+10, u+u[v]);
}
