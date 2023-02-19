# REST API w C++

Ten program w języku C++ korzysta z REST API i obsługuje odpowiedź serwera w formacie JSON. Program wykorzystuje bibliotekę cURL do wysłania żądania HTTP na podany URL i odbierania odpowiedzi serwera, a następnie korzysta z biblioteki nlohmann/json do przetworzenia odpowiedzi serwera w formacie JSON i wyświetlenia określonego pola z tej odpowiedzi.

## Jak skompilować i uruchomić program

Aby skompilować program, należy mieć zainstalowaną bibliotekę cURL i bibliotekę nlohmann/json. Następnie można skompilować program przy użyciu następującego polecenia w terminalu: g++ -o main main.cpp -lcurl

Po skompilowaniu programu można go uruchomić w terminalu, wpisując: ./main


## Przykładowa odpowiedź serwera

Przykładowa odpowiedź serwera (w formacie JSON) dla URL "https://jsonplaceholder.typicode.com/posts/1":

```json
{
  "userId": 1,
  "id": 1,
  "title": "sunt aut facere repellat provident occaecati excepturi optio reprehenderit",
  "body": "quia et suscipit\nsuscipit... voluptatem sequi\nnesciunt."
}
```
Program wyświetli pole "title" z tej odpowiedzi.

# Autor
Program napisany przez Michał Lewandowski.

