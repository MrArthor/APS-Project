# Algorithm And Problem Solving Project
## Plagarism And Spam Checher

Plagiarism & Spam Checker is a project designed to mainly check the “common content” between the Content stored  and the content submitted by the user.
It also lists out the Spam/Inappropriate words from the submitted work.

- Made By [Vansh Sachdev](https://github.com/mrarthor)
- Portfolio [MrArthor.xyz](http://mrarthor.xyz/)
- Student At Jaypee Institute Of Information Technology
- [LinkedIn](https://www.linkedin.com/in/mrarthor/)


## Classification Of String Matching Algorithms

The various algorithms can be classified by the number of patterns each uses.
- Single-pattern algorithms
- Naïve string-search algorithm
- Rabin–Karp algorithm
- Knuth–Morris–Pratt algorithm
- Boyer–Moore string-search algorithm
- Longest Common Substring algorithm

Algorithms using a finite set of patterns
- Aho–Corasick string matching algorithm (extension of Knuth-Morris-Pratt)
- Commentz-Walter algorithm (extension of Boyer-Moore)
- Set-BOM (extension of Backward Oracle Matching)
- Rabin–Karp string search algorithm.


## Algorithm Description:



### Rabin Karp Algorithm Approach:

- A string search algorithm which compares a string's hash values, rather than the strings themselves. We are taking a help of Karp-Rabin Algorithm. It uses fingerprints to find occurrences of one string into another string. Karp-Rabin Algorithm reduces time of comparison of two sequences by assigning hash value to each string and word. Without hash value, it takes too much time for comparison like if there is a word W and input string is S then word is compared with every string and sub string in program and hence it consumes moretime. 
Karp-Rabin has introduced concept of Hash value to avoid time complexity O(m2). It assigns hash value by calculating to both word and string/substring. So hash of substring (S) matches with hash value of W then only we can say exact comparison is done.


#### Hash Values:

- A hash value is a numeric value of a fixed length that uniquely identifies data. The most wonderful character of Hash Values is that they are highly unique. No two data can theoretically have same Hash Value.
Karp-Rabin algorithm preferred category from left to right comparison. Function of hash must able to find has value efficiently. When first time name would be hashing with the same hash it save the data causing yields a value which will be compared to at data is index with the value.
It can deal with multiple pattern matching that’s why people preferred this Karp-Rabin algorithm. Otherwise behavior of other algorithm is to perform basic pattern matching. 
Its having O(nm) complexity. Where n is length of text and m is length of pattern. It is little bit slow also due to we have to check every single character from the text. The steps followed for algorithm development are as follows:
• We have taken String s and an input file and the patterns taken are each 	sentence separated by delimiter full stop in String s.
• For each sentence we checked if the sentence is matched with any of the 	lines of input files.
• At last we have kept two counters :- m for total number of sentences in 	the string s and n for total number of matched sentences of string s.


### ALOGORITHM USED FOR PLAGIARSM CHECKER:

- This algorithm is based on the concept of hashing, so if you are not familiar with string hashing.
Rabin Karp algorithm matches the hash value of the pattern with the hash value of current substring of text, and if the hash values match then only it starts matching individual characters. So Rabin Karp algorithm needs to calculate hash values for following strings.
1) Pattern itself. 
2) All the substrings of the text of length m. 
This algorithm was authored by Rabin and Karp in 1987.
