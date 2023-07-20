#include <cstdint>
#include <array>
#include <map>
#include <cstddef>


struct Nucleotide {
    char Symbol;
    size_t Position;
    int ChromosomeNum;
    int GeneNum;
    bool IsMarked;
    char ServiceInfo;
};

const std::array<char, 4> symbols = {'A', 'T', 'G', 'C'};
const std::map<char, uint64_t> symbol_index = {{'A', 0 }, {'T', 1}, {'G', 2}, {'C', 3}};

struct CompactNucleotide {
    uint64_t Symbol:2;
    uint64_t Position:32;
    uint64_t ChromosomeNum:6;
    uint64_t GeneNum:15;
    uint64_t IsMarked:1;
    uint64_t ServiceInfo:8;
};

static_assert(sizeof(CompactNucleotide) <= 8, "The size of CompactNucleotide is greater than 8");

bool operator == (const Nucleotide& lhs, const Nucleotide& rhs);

CompactNucleotide Compress(const Nucleotide& n);
Nucleotide Decompress(const CompactNucleotide& cn);


bool operator == (const Nucleotide& lhs, const Nucleotide& rhs) {
  return (lhs.Symbol == rhs.Symbol)
      && (lhs.Position == rhs.Position)
      && (lhs.ChromosomeNum == rhs.ChromosomeNum)
      && (lhs.GeneNum == rhs.GeneNum)
      && (lhs.IsMarked == rhs.IsMarked)
      && (lhs.ServiceInfo == rhs.ServiceInfo);
}


CompactNucleotide Compress(const Nucleotide& n) {
  return {
    .Symbol = symbol_index.at(n.Symbol),
    .Position = n.Position,
    .ChromosomeNum = static_cast<uint64_t>(n.ChromosomeNum),
    .GeneNum = static_cast<uint64_t>(n.GeneNum),
    .IsMarked = static_cast<uint64_t>(n.IsMarked ? 1 : 0),
    .ServiceInfo = static_cast<uint64_t>(n.ServiceInfo),
  };
};


Nucleotide Decompress(const CompactNucleotide& cn) {
  return {
    .Symbol = symbols[cn.Symbol],
    .Position = cn.Position,
    .ChromosomeNum = cn.ChromosomeNum,
    .GeneNum = cn.GeneNum,
    .IsMarked = (cn.IsMarked == 1),
    .ServiceInfo = static_cast<char>(cn.ServiceInfo),
  };
}
