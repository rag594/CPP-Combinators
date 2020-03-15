#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#ifndef COMBINATORS_HPP
#define COMBINATORS_HPP

// Organise them in namespace, too messy right now

// map over the collection to produce a new collection
template <typename InpCollection, typename OutCollection, typename unop>
  OutCollection mapOver(InpCollection col, OutCollection& oCol, unop op) {
  std::transform(col.begin(),col.end(),oCol.begin(),op);
  return oCol;
}


// convert sequence to (element, index) typically a pair in C++
template <typename InpCollection, typename OutCollection>
  OutCollection zipWithIndex(InpCollection col, OutCollection& oCol) {
  auto colItr = col.begin();
  std::transform(col.begin(),col.end(),oCol.begin(),[&](int& x) {
                        auto itr = colItr++;
                        size_t index = std::distance(col.begin(), itr);
                        return make_pair(x, index);  });
  return oCol;
}

#endif
