### Zachowanie NaN
Zacznijmy od tego czym jest **NaN**. Jest to specjalna stała dla liczb zmiennoprzecinkowych oznaczająca brak sensownej wartości. Jest to akronim angielskiego wyrażenia "Not A Number", czyli luźno tłumacząc "to nie liczba". **NaN** jest zdefiniowany formalnie w normie IEEE 754 dotyczącej obliczeń zmiennoprzecinkowych. My jednak nie będziemy czytać dokumentacji, a po prostu spojrzymy sobie na to jak **NaN** się zachowuje.

Spójrzmy więc w kod źródłowy `nan_behavior.cpp` . Mamy tam poza `main()`em dwie funkcje pomocnicze:
 - `pretty_print()` wypisuje żółty tekst "NaN" lub wartość doubla, co pozwoli nam sprawdzać wartości przechowywane w różnych double'ach, i czy jest to **NaN**, czy nie jest.
 - `print_binary_representation()` wypisuje reprezentację danego double'a w pamięci. Funkcja jest krótka i prosta, za to działa poprawnie wyłącznie tam, gdzie double zajmuje 64 bity. Nie przejmujemy się tym, nasza platforma właśnie taka jest, a w razie potrzeby można oczywiście funkcję skomplikować i dodać detekcję i obsługę innych platform.

W samej funkcji `main()` zawarłem kilka sposobów na przypisanie do zmiennej czy stałej typu `double` wartości **NaN**. Najpierw więc, w linii #20, używamy stałej `NAN` z headera `cmath`. Jest to zaszłość z języka C, której nowoczesny kod C++ raczej nie używa, bo preferuje używanie metody `std::nan()` z tego samego headera `cmath`. Działanie metody zostało pokazane w liniach 25-30. Aby wywołać `std::nan()` konieczne jest podanie argumentu w formie C-stringa. Generalnie całe zachowanie metody `std::nan()` jest zależne od platformy (po angielsku *platform_specific*). Dla pustych stringów lub argumentów nie dających przełożyć się na liczbę zostanie zwrócona konkretna reprezentacja. Dla argumentów które można zinterpretować jako liczbę, zostanie zwrócona taka reprezentacja, która ma z tą liczbą coś wspólnego. Wszystko to jest zależne od platformy, gwarancję mamy tylko taką, że będzie to **NaN**.
W liniach 33-35 zostaje wypisana binarna reprezentacja pamięci dla tak stworzonych **NaN**-ów. Wyniki uruchomienia kodu zobaczymy za chwilę. Mamy też tzw. cichy **NaN** --- cichy, czyli nieustawiający flag błędów, ale dziś nie będę omawiał różnic między cichymi a sygnalizującymi **NaN**ami. Aby użyć cichego **NaN**, korzystamy z headera `limits` tak jak pokazuje linia #38.
Ciekawą cechą wartości **NaN** jest to, że wszelkie porównania innych wartości z **NaN**em ewaluują się jako fałszywe. Tak więc na przykład **NaN** nie jest ani większe, ani mniejsze, ani równe zeru. W szczególności **NaN** nie jest równe innej wartości **NaN**, jak również nie jest równe sobie samej. Nic dziwnego --- to w końcu Not A Number, nie jest liczba.

### Typowe źródła wartości NaN
**NaN** może pojawić się w programach niejako "spontanicznie", jako wynik nieoznaczonych obliczeń zmiennoprzecinkowych. Nieoznaczonych, czyli takich które nie mają sensownej wartości. Przykłady w pliku `typical_nan_sources.cpp`, o budowie analogicznej do poprzedniego. I tak na przykład **NaN** jest wynikiem:
1. odejmowania nieskończoności od nieskończoności
2. dzielenia zera przez zero (w matematyce tzw. wyraz nieoznaczony)
3. mnożenia zera przez nieskończoność
4. wyciągania pierwiastka kwadratowego z dowolnej ujemnej wartości
5. obliczania dowolnego logarytmu --- na przykład naturalnego --- z dowolnej ujemnej wartości
6. obliczania arcus sinusa czy arcus cosinusa spoza dziedziny funkcji, czyli przedziału <-1, 1>

Tu jeszcze mała uwaga: w innych językach jak np. ECMAScript możemy otrzymać **NaN** w wyniku dzielenia modulo, na przykład inf modulo liczba bądź liczba modulo zero. Nie w C++ --- tutaj operator modulo działa wyłącznie na typach całkowitych, więc pierwszy przypadek odpada - typy całkowite nie posiadają reprezentacji nieskończoności. Natomiast drugi przypadek, czyli modulo zero, to w C++ po prostu *undefined behavior*.

### Warsztat: programowanie smartwatcha
Wyobraźmy sobie, że programujemy smartwatcha. Zegarek posiada moduł GPS, który na żądanie zwraca aktualny czas oraz wysokość i szerokość geograficzną. Naszym zadaniem jest automatyczna klasyfikacja treningu użytkownika jako lekki chód albo ciężki bieg, w zależności od wskazań GPSa. W pliku `nan_poisoning_demo.cpp` korzystamy z już przetworzonych danych z zakończonego treningu. Dane te składają się ze wskazania czasu oraz z odległości w tym momencie od punktu startu. Odpada więc nam złożone obliczeniowo przekształcanie wysokości/szerokości geograficznej na metry i możemy skupić się na przyjemnym.

Musimy zdecydować, czy te dane reprezentują wolny chód, czy szybki bieg. Przyjmujemy, że trening dla którego średnia szybkość była większa niż 2 m/s, czyli 7.2 km/h, to bieg. Z kolei średnia szybkość mniejsza od tego progu odpowiada chodowi.
Do dzieła więc. W liniach (#17-32) Wczytujemy dane treningowe. Dla każdego z tych punktów możemy wyliczyć prędkość chwilową: delta-v wynosi przyrost pokonanej drogi podzielony przez przyrost czasu od ostatniego pomiaru. Robimy to w liniach (#34-46). Dla pierwszego pomiaru przyjmujemy delta-v równe zeru. Następnie, wiedząc że moduł GPS jest odpytywany zgrubnie co sekundę, możemy zaproksymować prędkość średnią jako średnią z wszystkich chwilowych prędkości (#49). To takie zgrubne całkowanie w dziedzinie czasu. Porównujemy, oczekując klasyfikacji jako bieg - według danych przyrost drogi w każdej sekundzie biegu wynosił przynajmniej 2 metry ([wykres na desmos](https://www.desmos.com/calculator/mhq4hsncnh)). Tymczasem werdykt brzmi: to **nie był** bieg.

Co tu się stało?
Uruchamiamy debugger i widzimy, że wyliczona przez nas średnia prędkość wynosi **NaN**. Oznacza to, że w którymś z obliczeń otrzymaliśmy wynik **NaN**, który następnie "zatruł" pozostałe obliczenia, bo oczywiście dowolna wartość sumowana, mnożona, dzielona itd z wartością **NaN** daje w wyniku także **NaN**. To jest właśnie tytułowy **NaN poisoning**. Dam Wam teraz chwilę, dosłownie pół minuty, spróbujcie znaleźć miejsce, w którym NaN się pojawia.

(oczekiwanie na odpowiedzi słuchaczy - pół minuty)

Źródłem błędu jest zduplikowany pomiar w piątej sekundzie biegu. Z jakiegoś powodu pojawił się on dwa razy. Jednak nasz sposób wyznaczania prędkości chwilowej spowoduje dla tego drugiego punktu liczenie ilorazu zera przez zero (przyrost i drogi, i czasu wyniósł dokładnie zero). A to jest **NaN**, które następnie sumowane z innymi wynikami i dzielone, pozostaje niezmiennie **NaN**em.

Aby rozwiązać ten problem, musimy weryfikować poprawność danych czytanych z GPSa. Prostą poprawką będzie weryfikacja, czy znacznik czasu kolejnego pomiaru jest większy od ostatnio zanalizowanego. Odrzucamy wszystkie pomiary, gdzie znacznik czasu jest równy bądź mniejszy od poprzedniego. I naprawione: teraz program poprawnie klasyfikuje ten krótki sprint jako bieg.

### Słowa końcowe
Opisałem problem **NaN poisoningu** w języku C++, ale problem występuje w każdym języku --- wszędzie tam, gdzie jest używany standard IEEE 754. Jak się przed tym chronić? Kiedyś szukano takich błędów manualnie. Dziś, w erze sanitizerów, UndefinedBehaviorSanitizer znajduje błędy wynikające z dzielenia przez 0 po podaniu flagi `-fsanitize=float-divide-by-zero`.
