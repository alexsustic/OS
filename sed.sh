#!/bin/bash

echo 1.Prefixati fiecare linie dintr-un fisier cu **abc** :
sed "s/^/abc/gi" lab3_sed.txt
echo 2.Inlocuiti fiecare linie goala dintr-un fisier cu **empty** :
sed "s/^$/empty/gi" lab3_sed.txt
echo 3.Convertiti taburile in 3 spatii dintr-un text dat :
sed "s/ /   /gi" lab3_sed.txt
echo 4.Rotiti cu o pozitie fiecare triplet de caractere dintr-un fisiser :
sed "s/\(.\)\(.\)\(.\)/\2\3\1/gi" lab3_sed.txt


