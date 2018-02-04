# Statki-terminalowe

Projekt zrealizowany w ramach zaliczenia przedmiotu "Programowanie obiektowe w C++".
Niniejszy opis jest kopiowaną treścią z dokumentacji zatem może numeracja być nieskładna.
Data powstania: ~05.2014r.


# Zadanie, które program ma realizować
Program umożliwia grę w „Statki” w dwóch trybach – gracz na gracza oraz gracz na komputer (dwie
możliwości wyboru poziomu trudności).
Lista opcji do wyboru z krótkim opisem każdej z nich
Prawie wszystkie pola które ma uzupełnić gracz zawierają kontrolę błędów. Wyjątkiem jest
wprowadzanie danych z zakresu położenia statku. Jeżeli jest napisane „LITERA LICZBA LICZBA” to
program zakłada poprawność podanych wartości (gdzie litera to litera, gdzie liczba to liczba). Nie
dotyczy to błędnego zakresu jak np. podania 5pól dla czteromasztowca czy próby utworzenia obiektu
poza planszą– tutaj zawiera już kontrole błędów.
Poziomy trudności:
1. Komputer strzela zupełnie losowo.
2. Komputer „oszukuje” znając położenia okrętów gracza i w zależności od wylosowanej
wartości ustala czy ma teraz trafić losowo w jeden ze statków czy gdziekolwiek.
Nietypowe zachowania programu
Program nie sprawdza czy na dane pole już był oddany strzał i ponownie je ostrzela. Będzie to jednak
kosztowało punkty (uzna za normalny kolejny strzał).
Niezgodności z założeniami przekazanymi w treści zadania
1. Program nie zawiera możliwości kontynuacji wcześniej rozpoczętej gry.
2. Statki mogą być ustawiane obok siebie.
3. Gracze/komputer zawsze strzelają na przemian. Nawet jeżeli został trafiony statek.


Składnia danych wejściowych i wyjściowych
Struktura plików, typy danych przechowywane w poszczególnych polach
pliku
W „intro.txt” zawarte są wszelkie informacje dotyczące programu (legenda oznaczeń pól, opisane
tryby rozgrywki, nietypowe założenia).
W „rank.txt” znajdują się wyniki graczy. Każdy kolejny jest dopisywany na końcu pliku w formacie
„NAZWA_GRACZA ILOŚĆ_RUCHÓW POZIOM_PRZECIWNIKA” .
Struktura katalogów niezbędna dla poprawnego działania programu
Wszystko w jednym folderze (tam gdzie .exe to też muszą być zawarte pliki .txt).
