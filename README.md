# Zadanie

W `string_01.h` zaimplementuj zestaw funkcji, który będzie wykonywał następujące operacje:

1. będzie budowała nowy string „od tyłu” i go zwracała
    ```c++
    auto reverse(const std::string & str) -> std::string
    ```

1. będzie zamieniała małą literę na dużą na początku każdego słowa i zwróci nowy string
    ```c++
    auto first_to_upper(const std::string & str) -> std::string
    ```

1. będzie liczyła samogłoski w podanym stringu i zwróci ich liczbę
    ```c++
    auto count_vowels(const std::string & str) -> int
    ```

1. będzie sprawdzała czy w stringu są cyfry; jeżeli tak, niech liczy ich sumę i ją zwróci
    ```c++
    auto sum_digits(const std::string & str) -> int
    ```

1. będzie sprawdzała, czy dany string `str` zawiera dany ciąg `substr`, zwraca pozycję licząc od 0 lub -1 jeśli brak
    ```c++
    auto search_substr(const std::string & str, const std::string & substr) -> int
    ```

1. będzie przeszukiwała string (podobny do find) w oparciu wyłącznie o wskaźniki, zwraca pozycję licząc od 0 lub -1 jeśli brak
    ```c++
    auto custom_serach(const char * str, const char * substr) -> int
    ```

W `string_01.cc` napisz funkcję main która:
1. będzie przyjmowała dowolny string „z klawiatury”
1. wywoła powyższe funkcje w danej kolejności

# Instrukcje

1. Zrób fork tego repozytorium klikajać w przycisk `Fork` w prawym górnym roku tej strony. Potwierdz domyślne wartości na następnym ekranie.
1. Sklonuj twoje repozytorium lokalnie. Wybierz zielony przycisk `Code`, w zakładce `Local` wybierz `SSH`, skopiuj string.
1. W lokalnym terminalu wpisz:
    ```bash
    git clone [tutaj wklej skopiowany link]

1. W terminalu wykonaj polecania:
    ```bash
    cd cpp_string_01
    make
    make test
    ```
    Spowoduje to skompilowanie projektu oraz uruchomienie testów. Projekt początkowy będzie miał sporo błędów i ostrzeżeń.

1. W ramach pracy nad projektem powinieneś edytować tylko pliki `string_01.h` oraz `string_01.cc`, pozostałe pliki powinny być nieedytowane.

1. W pliku `string_01.h` postaraj się edytować tylko przestrzenie między deklaracją funkcji a klamrą zamykajacą. Ingerencje w te linijki mogą spowodować problemy z aktualizacją forków i będą wymagały odpowiednich ręcznych akcji.

1. Po naniesieniu zmian, wykonaj:
    ```bash
    git add -p
    ```
    i zatwierdz wszystkie zmiany za pomocą klawisza `y` lub odrzuć dzięki `n` jeśli nie chcesz danej zmiany wysyłać. Następnie:
    ```bash
    git commit
    ```
    Otworzy się edytor, wpisz treść wiadomości do commita i zapisz i zamknij plik. Następnie:
    ```bash
    git push
    ```
    aby wysłać zmiany na serwer gita.
