#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
#include <iterator>
#include <type_traits>
#include <set>

using namespace std;

#ifndef COMBINATORS_HPP
#define COMBINATORS_HPP

// Organise them in namespace, too messy right now

// map over the collection to produce a new collection
template <typename InpCollection, typename OutCollection, typename unop>
  OutCollection _map(InpCollection col, OutCollection& oCol, unop op) {
  std::transform(col.begin(),col.end(),oCol.begin(),op);
  return oCol;
}


// convert sequence to (element, index) typically a pair in C++
template <typename InputCollection>
  auto _zipWithIndex(InputCollection col) -> std::vector<pair<typename InputCollection::value_type,int> > {
  auto colItr = col.begin();
  typedef typename InputCollection::value_type InpColType;
  std::vector<pair<InpColType, int>> oCol(col.size());
  std::transform(col.begin(),col.end(),oCol.begin(),[&](const InpColType& x) {
                        auto itr = colItr++;
                        size_t index = std::distance(col.begin(), itr);
                        return make_pair(x, index);  });
  return oCol;
}

#endif
