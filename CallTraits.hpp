#ifndef CALL_TRAITS_HPP_
# define CALL_TRAITS_HPP_

namespace TypeTraits
{
  template <typename T>
  struct CallTraits
  {
    template <typename U, bool isRef>
    struct CallTraitsImpl;

    template <typename U>
    struct CallTraitsImpl<U, true>
    {
      typedef const U& type;
    };

    template <typename U>
    struct CallTraitsImpl<U, false>
    {
      typedef U type;
    };

#if _WIN64 || __amd64__
    typedef typename CallTraitsImpl<T, (sizeof(T) > 8)>::type ParamType;
#else
    typedef typename CallTraitsImpl<T, (sizeof(T) > 4)>::type ParamType;
#endif
  };
}

#endif /* !CALL_TRAITS_HPP_ */
