# Studentų pažymių skaičiuoklė #
Programa yra skirta apskaičiuoti studento vidurkį/medianą, pagal jo įvestus/sugeneruotus namų darbų ir egzamino pažymius.

## Veikimo principas ##

### Pagrindinis ###

* Vartotojas turi pasirinkti ar nori įvesti studentų skaičių (1. - taip; 2. ne).

1. **JEI TAIP**
* Vartotojas turi pasirinkti ar nori apskaičiuoti vidurkį/medianą.
*  Vartotojas turi įvesti studentų skaičių.
* Kiekvienam studentui vartotojas turi įvesti:
  * vardą;
  * pavardę.
* Vartotojas gali pasirinkti ar nori įvesti studento pažymių kiekį rankiniu būdu:
  *  Jei taip, vartotojas gali įvesti studentų pažymių kiekį. Tuomet vartotojas gali pasirinkti ar nori įvesti studento pažymius rankiniu būdu:
      * Jei taip, vartotojas gali įvesti pažymius.
      * Jei ne, programa atsititktinai sugeneruoja šio studento pažymius.
  * Jei ne, vartotojas turi įvesti studento pažymius. Tai vartotojas gali daryti iki tol, kol vietoje pažymio neįveda "stop".
* Vartotojas gali pasirinkti ar nori įvesti studento egzamino pažymį rankiniu būdu:
  * Jei taip, vartotojas turi įvesti egzamino pažymį.
  * Jei ne, programa atsitiktinai sugeneruoja šio studento egzamino pažymį.
* Programa apskaičiuoja vidurkį/medianą ir išveda duomenis:
  * Pavardę
  * Vardą
  * Galutinį pažymį (vidurkį/medianą).

2. **JEI NE**
* Vartotojas turi pasirinkti ar nori apskaičiuoti vidurkį/medianą.
* Kiekvienam studentui vartotojas turi įvesti:
  * vardą;
  * pavardę.
* Vartotojas gali pasirinkti ar nori įvesti studento pažymių kiekį rankiniu būdu:
  *  Jei taip, vartotojas gali įvesti studentų pažymių kiekį. Tuomet vartotojas gali pasirinkti ar nori įvesti studento pažymius rankiniu būdu:
      * Jei taip, vartotojas gali įvesti pažymius.
      * Jei ne, programa atsititktinai sugeneruoja šio studento pažymius.
  * Jei ne, vartotojas turi įvesti studento pažymius. Tai vartotojas gali daryti iki tol, kol vietoje pažymio neįveda "stop".
* Vartotojas gali pasirinkti ar nori įvesti studento egzamino pažymį rankiniu būdu:
  * Jei taip, vartotojas turi įvesti egzamino pažymį.
  * Jei ne, programa atsitiktinai sugeneruoja šio studento egzamino pažymį.
* Vartotojas pasirenka ar nori įvesti dar vieną studentą. Jei taip, visi 2 dalies punktai vykdomi dar kartą, iki tol, kol vartotojas nebenori įvesti daugiau studentų.
* Programa apskaičiuoja vidurkį/medianą ir išveda duomenis:
  * Pavardę
  * Vardą
  * Galutinį pažymį (vidurkį/medianą).

:heavy_exclamation_mark: **Pažymius vartotojas turi įvesti nenaudodamas tarpo - po kiekvieno įvesto pažymio vartotojas turi paspausti *enter*.**

:heavy_exclamation_mark: Galutinis vidurkis skaičiuojamas pagal formulę: **galutinis = 0.4 * vidurkis + 0.6 * egzaminas**.

:heavy_exclamation_mark: Duomenys išvedami surikiuoti pagal studentų pavardes didėjimo tvarka.

### Papildomas ###

Programa išveda klaidą ir prašo pakartoti įvedimą šiais atvejais:

* Vartotojui vietoje "y" arba "n" įvedus kitokį simbolį;
* Vartotojui vietoje studentų ir pažymių skaičiaus įvedus: neleistiną simbolį, raidę, žodį arba skaičių, mažesnį už 1;
* Varototojui vietoje vardo ir pavardės įvedus ne žodį;.
* Vartotojui vietoje pažymio (kuris turi būti nuo 1 iki 10) įvedus bet kokį kitą simbolį ar žodį;
* Vartotojui vietoje pažymio (kuris turi būti nuo 1 iki 10) arba "stop", pažymių įvedimo funkcijoje su nežinomu pažymių kiekiu, įvedus bet kokį kitą simbolį ar žodį.
  
:heavy_exclamation_mark: Pakartotinis įvedimas vyksta iki tol, kol vartotojas įveda teisingą norimą reikšmę.

:heavy_exclamation_mark: Programa yra realizuota dviem būdais: su C tipo masyvais ir su vektoriais. Programa su C tipo masyvais saugoma **main_array.cpp**, o su vektoriais - **main_vector.cpp**.


## Įdiegimo instrukcija ##
* Atsisiųskite norimą programos versiją (rekomenduojama atsisiųsti naujausią versiją) iš [Releases](https://github.com/aistestonciute/2_uzd/releases) aplanko.
* Išarchyvuokite parsisiųstą failą.
* Paleiskite main.cpp programą naudojantis C++ IDE (pvz. CodeBlocks arba Visual Studio) arba per komandinę eilutę.

## Veikimo instrukcija ##
* Paleidus programą įveskite norimus kintamuosius. 


## Versijos ##

* [v0.1](https://github.com/aistestonciute/2_uzd/releases/tag/0.1) Pradinė sistemos versija.
