#ifndef INSERTION_HPP_
# define INSERTION_HPP_

# include "ASorter.hpp"

namespace Sort
{
  template <typename T>
  class Insertion : public ASorter<T>
  {
  public :
    Insertion(const Comparator<typename T::value_type>&);
    Insertion(Comparator<typename T::value_type>&&);
    virtual ~Insertion();
    virtual void sort(T&) const;
  };

  template <typename T>
  Insertion<T>::Insertion(const Comparator<typename T::value_type>& comparator) :
    ASorter<T>(comparator)
  { }
  
  template <typename T>
  Insertion<T>::Insertion(Comparator<typename T::value_type>&& comparator) :
    ASorter<T>(std::forward<Comparator<typename T::value_type>>(comparator))
  { }
  
  template <typename T>
  Insertion<T>::~Insertion() { }
    
  template <typename T>
  void Insertion<T>::sort(T& container) const
  {
    typename T::iterator begin = container.begin();
    typename T::iterator end = container.end();
    typename T::reverse_iterator rendPrev = std::prev(container.rend());

    while (begin != end)
      {
	typename T::reverse_iterator rbeginNext(std::next(begin));
	typename T::reverse_iterator rbeginNextNext = std::next(rbeginNext);
	typename T::value_type value = *rbeginNext;

	while (rbeginNext != rendPrev
	       && this->_comparator(*rbeginNextNext, value)) 
	  {
	    *rbeginNext = *rbeginNextNext;
	    ++rbeginNext;
	    ++rbeginNextNext;
	  }
	*rbeginNext = value;
	++begin;
      }
  }
}

#endif /* !INSERTION_HPP_ */
