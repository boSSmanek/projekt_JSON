# Projekt polegający na napisaniu aplikacji do edycji plików .json
### Program umożliwia:
- importowanie jsona
- dodanie mocy lub wybranie z wcześniej używanych (wartości zapisywane są w generowanym pliku powers.json, a następnie czytane są z niego wartości; jeśli nie istnieje to jest tworzony przy pierwszym dodaniu mocy)
- wybór mocy i otworzenie dla niej jsona
- zmianę określonych parametrów, a także zabezpieczenie przed niechcianymi zmianami wprowadzanymi przez użytkownika
- wyeksportowanie do nowego jsona
- wygenerowanie folderu o nazwie wybranej mocy, a w nim plik csv z konfiguracją

### Wady:
- niestety, ale po edycji jednego jsona dla danej mocy trzeba go zapisać, ponieważ otwarcie kolejnego powoduje, że zmiany w poprzednim są usuwane

### Pliki:
- main.py -> plik z aplikacją
- ID.h -> plik nagłówkowy, który używany jest do tłumaczenia ID z jsona na odpowiednia nazwę w csv
- menuSimple.json -> MENU w jsonie
- header_to_dict.py -> wyciąganie ID z ID.h
