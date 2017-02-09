#ifndef SELECTION_HPP_
# define SELECTION_HPP_

# include "ASorter.hpp"

namespace Sort
{  
  template <typename T>
  class Selection : public ASorter<T>
  {
  public :
    Selection(const Comparator<typename T::value_type>&);
    Selection(Comparator<typename T::value_type>&&);
    virtual ~Selection();
    virtual void sort(T&) const;
  };
  
  template <typename T>
  Selection<T>::Selection(const Comparator<typename T::value_type>& comparator) :
    ASorter<T>(comparator)
  { }
  
  template <typename T>
  Selection<T>::Selection(Comparator<typename T::value_type>&& comparator) :
    ASorter<T>(std::forward<Comparator<typename T::value_type>>(comparator))
  { }
  
  template <typename T>
  Selection<T>::~Selection() { }
  
  template <typename T>
  void Selection<T>::sort(T& container) const
  {
    typename T::iterator begin = container.begin();
    typename T::iterator end = container.end();
    
    while (begin != end)
      {
	typename T::iterator beginNext = std::next(begin);
	typename T::iterator max = begin;

	while (beginNext != end)
	  {
	    if (this->_comparator(*max, *beginNext))
	      max = beginNext;
	    ++beginNext;
	  }
	std::swap(*begin, *max);
	++begin;
      }
  }
}

#endif /* !SELECTION_HPP_ */
