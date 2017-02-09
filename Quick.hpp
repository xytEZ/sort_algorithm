#ifndef QUICK_HPP_
# define QUICK_HPP_

# include "ASorter.hpp"

namespace Sort
{
  template <typename T>
  class Quick : public ASorter<T>
  {
  public :
    Quick(const Functor<typename T::value_type>&);
    Quick(Functor<typename T::value_type>&&);
    virtual ~Quick();
    virtual void sort(T&) const;

  private :
    void quickSort(T&,
		   typename T::iterator&&,
		   typename T::iterator&&) const;
    
    typename T::iterator partition(T&,
				   const typename T::iterator&,
				   const typename T::iterator&) const;
    };

  template <typename T>
  Quick<T>::Quick(const Functor<typename T::value_type>& functor) :
    ASorter<T>(functor)
  { }
  
  template <typename T>
  Quick<T>::Quick(Functor<typename T::value_type>&& functor) :
    ASorter<T>(std::forward<Functor<typename T::value_type>>(functor))
  { }
  
  template <typename T>
  Quick<T>::~Quick() { }
  
  template <typename T>
  void Quick<T>::sort(T& container) const
  {
    if (container.size() > 1)
      quickSort(container, container.begin(), container.end());
  }
  
  template <typename T>
  void Quick<T>::quickSort(T& container,
			   typename T::iterator&& first,
			   typename T::iterator&& last) const
  {
    if (first != last)
      {
	typename T::iterator pivot = partition(container, first, last);

	quickSort(container,
		  std::forward<typename T::iterator>(first),
		  std::move(pivot));
	quickSort(container,
		  std::next(pivot),
		  std::forward<typename T::iterator>(last));
      }
  }

  template <typename T>
  typename T::iterator Quick<T>::partition(T& container,
					   const typename T::iterator& first,
					   const typename T::iterator& last) const
  {
    typename T::value_type pivot = *first;
    typename T::iterator left = first;
    typename T::iterator right = last;

    while (left != right)
      {
	while (*left < pivot)
	  ++left;
	while (*right > pivot)
	  --right;
	if (left != right)
	  std::swap(*left, *right);
      }
    return right;
  }
}

#endif /* !QUICK_HPP_ */
