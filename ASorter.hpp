#ifndef ASORTER_HPP_
# define ASORTER_HPP_

# include <utility>
# include <functional>

# include "CallTraits.hpp"

namespace Sort
{
  template <typename T>
  using Comparator =
    std::function<bool (typename TypeTraits::CallTraits<T>::ParamType,
			typename TypeTraits::CallTraits<T>::ParamType)>;
  
  template <typename T>
  class ASorter
  {
  protected :
    Comparator<typename T::value_type> _comparator;
    
  protected :
    ASorter(const Comparator<typename T::value_type>&);
    ASorter(Comparator<typename T::value_type>&&);
    
  public :
    virtual ~ASorter();
    virtual void sort(T&) const = 0;
  };

  template <typename T>
  ASorter<T>::ASorter(const Comparator<typename T::value_type>& comparator) :
    _comparator(comparator)
  { }
  
  template <typename T>
  ASorter<T>::ASorter(Comparator<typename T::value_type>&& comparator) :
    _comparator(std::move<Comparator<typename T::value_type>>(comparator))
  { }
  
  template <typename T>
  ASorter<T>::~ASorter() { }
}

#endif /* !ASORTER_HPP_ */
