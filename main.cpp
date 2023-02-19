#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

int main() {
  CURL* curl = curl_easy_init(); // Inicjalizacja biblioteki cURL
  if (curl) {
    // Ustawienie URL i opcji żądania HTTP
    curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/posts/1");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    // Ustawienie funkcji callback do zapisywania odpowiedzi serwera
    string response_data;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](char* ptr, size_t size, size_t nmemb, void* userdata) -> size_t {
      ((string*)userdata)->append(ptr, size * nmemb);
      return size * nmemb;
    });
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);

    // Wykonanie żądania HTTP
    CURLcode res = curl_easy_perform(curl);
    if (res == CURLE_OK) {
      // Przetworzenie odpowiedzi serwera w formacie JSON
      json response_json = json::parse(response_data);

      // Wyświetlenie pola "title" z odpowiedzi serwera
      cout << "Title: " << response_json["title"].get<string>() << endl;
    } else {
      cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
    }

    curl_easy_cleanup(curl); // Zwolnienie zasobów biblioteki cURL
  }

  return 0;
}
