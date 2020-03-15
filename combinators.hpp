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

// filter the elements based on a Predicate
template <typename InputCollection, typename Predicate>
InputCollection _filter(InputCollection iCol, Predicate predicate) {
  typedef typename InputCollection::value_type InpColType;
  std::vector<InpColType> oCol;
  std::copy_if(iCol.begin(),iCol.end(),std::back_inserter(oCol), predicate);
  return oCol;
}

// filter the elements which does not satisfy the predicate
template <typename InputCollection, typename Predicate>
InputCollection _filterNot(InputCollection iCol, Predicate predicate) {
  auto oCol = _filter(iCol, [predicate] (typename InputCollection::value_type i) {return !predicate(i);});
  return oCol;
}



#endif
