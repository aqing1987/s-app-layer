/*
 * Deoxyribonucleic acid, DNA is the primary information storage molecule in
 * biological systems. It is composed of four nucleic acid bases Guanine ('G'),
 * Cytosine ('C'), Adenine ('A'), and Thymine ('T').
 *
 * Ribonucleic acid, RNA, is the primary messenger molecule in cells. RNA
 * differs slightly from DNA its chemical structure and contains no Thymine.
 * In RNA Thymine is replaced by another nucleic acid Uracil ('U').
 *
 * Create a funciton which translates a given DNA string into RNA.
 * */

#include <iostream>
#include <algorithm>
#include <string>

// better solution
std::string DNAtoRNA2(std::string dna) {
  std::replace(begin(dna), end(dna), 'T', 'U');
  return dna;
}

std::string DNAtoRNA(std::string dna) {
  std::string rna;
  for (auto it = dna.cbegin(); it != dna.cend(); ++it) {
    if (*it == 'T')
      rna += 'U';
    else
      rna += *it;
  }

  return rna;
}

int main() {
  std::cout << DNAtoRNA2("GCAT") << std::endl;
  return 0;
}