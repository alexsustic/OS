#!/bin/bash
echo 1. Display all the lines with words that contains **cat**:

grep "cat" lab3_grep.txt

echo 2. Display all the lines that start with a word which have the prefix **ing** :

grep "^ing" lab3_grep.txt

echo 3. Display all the lines that have an odd number of characters :

grep "^\(..\)\+\(.\)$" lab3_grep.txt

echo 4. Display all the lines which contains words with 3 consecutive consonants :

grep "\<\(.\)*[^aeiouAEIOU ]\{3,\}\(.\)*\>" lab3_grep.txt
