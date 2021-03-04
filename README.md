# Studentų pažymių skaičiuoklė #
Programa yra skirta apskaičiuoti studento vidurkį/medianą, pagal jo įvestus/sugeneruotus arba iš failo nuskaitytus namų darbų ir egzamino pažymius.

## Veikimo principas ##

### Pagrindinis ###

* Vartotojas turi pasirinkti ar nori apskaičiuoti **vidurkį/medianą**.
* Vartotojas turi pasirinkti ar nori įvesti duomenis **rankiniu būdu** (kitu atveju duomenys bus skaitomi iš tekstinio failo **"kursiokai.txt"** arba **sugeneruoto pasirinkto** failo).

#### Vartotojui pasirinkus duomenų įvedimą rankiniu būdu ####

* Vartotojas turi pasirinkti ar nori įvesti studentų skaičių.

* Kiekvienam studentui vartotojas turi įvesti:
  * vardą;
  * pavardę.
* Vartotojas gali pasirinkti ar nori įvesti studento pažymių kiekį rankiniu būdu:
  * Jei taip, vartotojas gali įvesti studentų pažymių kiekį. Tuomet vartotojas gali pasirinkti ar nori įvesti studento pažymius rankiniu būdu. Jei ne, programa atsitiktinai sugeneruoja studento pažymius.
  * Jei ne, vartotojas turi įvesti studento pažymius. Tai vartotojas gali daryti iki tol, kol vietoje pažymio neįveda `stop`.
  
* Vartotojas gali pasirinkti ar nori įvesti studento egzamino pažymį rankiniu būdu:
  * Jei taip, vartotojas turi įvesti egzamino pažymį.
  * Jei ne, programa atsitiktinai sugeneruoja šio studento egzamino pažymį.
  
* Vartotojas pasirenka ar nori įvesti dar vieną studentą (jei nežinomas studentų skaičius). Jei taip, visi 2 dalies punktai vykdomi dar kartą, iki tol, kol vartotojas nebenori įvesti daugiau studentų.

* Programa apskaičiuoja vidurkį/medianą ir išveda duomenis:
  * Pavardę
  * Vardą
  * Galutinį pažymį (vidurkį/medianą).

#### Vartotojui pasirinkus duomenų įvedimą iš tekstinio failo ####

* Vartotojas turi pasirinkti ar nori sugeneruoti failus. **Jei taip**, sugeneruojamas failas  (galimi 5 skirtingų dydžių failai (1000, 10000, 100000, 1000000, 10000000)). Tuomet vartotojas turi pasirinkti iš kurio failo nori imti duomenis. **Jei vartotojas nenori generuoti failų,** duomenys imami iš `kursiokai.txt` failo.

* Programa nuskaito duomenis iš aprašyto failo.

* Programa apskaičiuoja vidurkį/medianą ir išveda duomenis:
  * Pavardę
  * Vardą
  * Galutinį pažymį (vidurkį/medianą).

:heavy_exclamation_mark: **Pažymius vartotojas turi įvesti nenaudodamas tarpo - po kiekvieno įvesto pažymio vartotojas turi paspausti `enter`.**

:heavy_exclamation_mark: Galutinis vidurkis skaičiuojamas pagal formulę: `galutinis = 0.4 * vidurkis/mediana + 0.6 * egzaminas`.

:heavy_exclamation_mark: Duomenys išvedami surikiuoti pagal studentų pavardes didėjimo tvarka.

:heavy_exclamation_mark: Programa išveda studentų duomenis į du failus: `Winners.txt` ir `Losers.txt`. Jei studento vidurkis < 5, jis pridedamas į `Losers` grupę, jei vidurkis didesnis - į `Winners` grupę.

### Papildomas ###

Programa išveda klaidą ir prašo pakartoti įvedimą šiais atvejais:

* Vartotojui vietoje `y` arba `n` įvedus kitokį simbolį;
* Vartotojui vietoje studentų ir pažymių skaičiaus įvedus: neleistiną simbolį, raidę, žodį arba skaičių, mažesnį už 1;
* Varototojui vietoje vardo ir pavardės įvedus ne žodį.
* Vartotojui vietoje pažymio (kuris turi būti nuo `1` iki `10`) įvedus bet kokį kitą simbolį ar žodį;
* Vartotojui vietoje pažymio (kuris turi būti nuo `1` iki `10`) arba `stop`, pažymių įvedimo funkcijoje su nežinomu pažymių kiekiu, įvedus bet kokį kitą simbolį ar žodį.
* Vartotojui vietoje failo numerio (`1 - 5`) įvedus bet kokį kitą simbolį ar žodį.

:heavy_exclamation_mark: Pakartotinis įvedimas vyksta iki tol, kol vartotojas įveda teisingą norimą reikšmę.

Sistema nutraukia darbą šiais atvejais:

* Neegzistuojant duomenų failui.
* Duomenų faile studento pažymių vietose esant raidei, žodžiui ar kitam neleistinam simboliui.
* Duomenų faile studento pažymiui neatitinkant pažymių intervalo [0, 10].
* Duomenų faile studento pažymių nebuvimui (tuščia eilutė).
* Duomenų faile studento pažymiui esant iš daugiau nei 1 ar 2 simbolių.
* Įvykus bet kokiai sisteminei klaidai.

## Įdiegimo instrukcija ##
* Atsisiųskite norimą programos versiją (rekomenduojama atsisiųsti naujausią versiją) iš [Releases](https://github.com/aistestonciute/2_uzd/releases) aplanko.
* Išarchyvuokite parsisiųstą failą.
* Paleiskite programų failus per komandinę eilutę: 
   `g++ -o main main.cpp functions.cpp` `./main`.

## Veikimo instrukcija ##
* Paleidus programą sekite instrukcijas ir įveskite prašomus kintamuosius.


## Versijos ##

* [v0.1](https://github.com/aistestonciute/2_uzd/releases/tag/0.1) Pradinė sistemos versija. Programa yra realizuota dviem būdais: su `C` tipo masyvais ir su `vektoriais`. Programa su C tipo masyvais saugoma **main_array.cpp**, o su vektoriais - **main_vector.cpp**.
* [v0.2](https://github.com/aistestonciute/2_uzd/releases/tag/0.2) Pridėta funkcija, leidžianti vartotojui pasirinkti kokiu būdu įvesti duomenis - rankiniu ar nuskaitymu iš tekstinio failo. Ši versija yra v0.1 patobulintas **main_vector.cpp** failas, realizuojantis programą tik su `<vector>` tipo konteineriais. Sutvarkytas duomenų paėmimas iš failo naudojant `buffer`. Pridėta `WINPAUSE`.
 * [v0.3](https://github.com/aistestonciute/2_uzd/releases/tag/0.3) Sukurtas `functions.cpp` failas, kuriame sudėtos visos [v0.2](https://github.com/aistestonciute/2_uzd/releases/tag/0.2) realizuotos funkcijos. Sukurtas `functions.hpp` - saugantis funkcijų aprašymus ir `struct Student`. `main.cpp` pridėtas klaidų mėtymas ir gaudymas (`exceptional handling`) su klaidų išraiškomis (`error case`). Šiame faile taip pat ištrintos visos funkcijos, palikta tik `int main()`.
 * [v0.4](https://github.com/aistestonciute/2_uzd/releases/tag/0.4) Sukurta funkcija, leidžianti generuoti duomenų failus (dydžiai: 1000, 10000, 100000, 1000000, 10000000). Pridėtas studentų rūšiavimas į dvi grupes: `Winners` (studento vidurkis >= 5) ir `Losers` (studento vidurkis < 5). `Winners` ir `Losers` išvedami į du atskirus failus: `Winners.txt` ir `Losers.txt` Atliktas programos veikimo (spartos) analizė su kiekvienu sugeneruotu duomenų failu.
