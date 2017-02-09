#ifndef ASORTER_HPP_
# define ASORTER_HPP_

# include <utility>
# include <functional>

namespace Sort
{
  template <typename T>
  using Functor = std::function<bool (const T&, const T&)>;
  
  template <typename T>
  class ASorter
  {
  protected :
    Functor<typename T::value_type> _functor;
    
  protected :
    ASorter(const Functor<typename T::value_type>&);
    ASorter(Functor<typename T::value_type>&&);
    
  public :
    virtual ~ASorter();
    virtual void sort(T&) const = 0;
  };

  template <typename T>
  ASorter<T>::ASorter(const Functor<typename T::value_type>& functor) :
    _functor(functor)
  { }
  
  template <typename T>
  ASorter<T>::ASorter(Functor<typename T::value_type>&& functor) :
    _functor(std::move<Functor<typename T::value_type>>(functor))
  { }
  
  template <typename T>
  ASorter<T>::~ASorter() { }
}

#endif /* !ASORTER_HPP_ */
