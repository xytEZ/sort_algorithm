#ifndef MERGE_HPP_
# define MERGE_HPP_

# include "ASorter.hpp"

namespace Sort
{
  template <typename T>
  class Merge : public ASorter<T>
  {
  public :
    Merge(const Comparator<typename T::value_type>&);
    Merge(Comparator<typename T::value_type>&&);
    virtual ~Merge();
    virtual void sort(T&) const;
    
  private :
    T mergeSort(T&, T&) const;
  };

  template <typename T>
  Merge<T>::Merge(const Comparator<typename T::value_type>& comparator) :
    ASorter<T>(comparator)
  { }
  
  template <typename T>
  Merge<T>::Merge(Comparator<typename T::value_type>&& comparator) :
    ASorter<T>(std::forward<Comparator<typename T::value_type>>(comparator))
  { }
  
  template <typename T>
  Merge<T>::~Merge() { }

  template <typename T>
  void Merge<T>::sort(T& container) const
  {
    if (container.size() > 1)
      {
	T left(container.cbegin(),
	       std::next(container.cbegin(), (container.size() / 2)));
	T right(std::next(container.cbegin(), (container.size() / 2)),
		container.cend());
	
	sort(left);
	sort(right);
	container = mergeSort(left, right);
      }
  }

  template <typename T>
  T Merge<T>::mergeSort(T& left, T& right) const
  {
    T result;
    typename T::iterator leftBegin = left.begin();
    typename T::iterator leftEnd = left.end();
    typename T::iterator rightBegin = right.begin();
    typename T::iterator rightEnd = right.end();

    while (leftBegin != leftEnd && rightBegin != rightEnd)
      {
	if (this->_comparator(*leftBegin, *rightBegin))
	  {
	    result.push_back(std::move(*rightBegin));
	    ++rightBegin;
	  }
	else
	  {
	    result.push_back(std::move(*leftBegin));
	    ++leftBegin;
	  }
      }
    while (leftBegin != leftEnd)
      {
	result.push_back(std::move(*leftBegin));
	++leftBegin;
      }
    while (rightBegin != rightEnd)
      {
	result.push_back(std::move(*rightBegin));
	++rightBegin;
      }
    return result;
  }
}

#endif /*! MERGE_HPP_ */
