#ifndef BUBBLE_HPP_
# define BUBBLE_HPP_

# include "ASorter.hpp"

namespace Sort
{
  template <typename T>
  class Bubble : public ASorter<T>
  {
  public :
    Bubble(const Comparator<typename T::value_type>&);
    Bubble(Comparator<typename T::value_type>&&);
    virtual ~Bubble();
    virtual void sort(T&) const;
  };

  template <typename T>
  Bubble<T>::Bubble(const Comparator<typename T::value_type>& comparator) :
    ASorter<T>(comparator)
  { }
  
  template <typename T>
  Bubble<T>::Bubble(Comparator<typename T::value_type>&& comparator) :
    ASorter<T>(std::forward<Comparator<typename T::value_type>>(comparator))
  { }
  
  template <typename T>
  Bubble<T>::~Bubble() { }
  
  template <typename T>
  void Bubble<T>::sort(T& container) const
  {
    typename T::reverse_iterator rbegin = container.rbegin();
    typename T::reverse_iterator rend = container.rend();
    
    while (rbegin != rend)
      {
	typename T::iterator begin = container.begin();
	
	while (begin != rbegin.base())
	  {
	    if (this->_comparator(*begin, *rbegin))
	      std::swap(*begin, *rbegin);
	    ++begin;
	  }
	++rbegin;
      }
  }
}

#endif /*! BUBBLE_HPP_ */
