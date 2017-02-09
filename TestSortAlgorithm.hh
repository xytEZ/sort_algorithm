#ifndef TEST_SORT_ALGORITHM_HH_
# define TEST_SORT_ALGORITHM_HH_

# include <cppunit/TestFixture.h>
# include <cppunit/extensions/HelperMacros.h>
# include <functional>
# include <list>

# include "CallTraits.hpp"

namespace Test
{
  class TestSortAlgorithm : public CppUnit::TestFixture
  {
    CPPUNIT_TEST_SUITE(TestSortAlgorithm);
    CPPUNIT_TEST(testBubbleSort);
    CPPUNIT_TEST(testSelectionSort);
    CPPUNIT_TEST(testInsertionSort);
    CPPUNIT_TEST(testMergeSort);
    CPPUNIT_TEST(testQuickSort);
    CPPUNIT_TEST_SUITE_END();

  private :
    template <typename T>
    using ContainerValue = std::list<T>;

    template <typename T>
    using Functor =
      std::function<bool (const TypeTraits::CallTraits<int>::ParamType&,
			  const TypeTraits::CallTraits<int>::ParamType&)>;
    
  private :
    ContainerValue<int> _noSortedContainer;
    ContainerValue<int> _sortedContainer;
    Functor<int> _functor;

  public :
    void setUp();
    void tearDown();

  protected :
    void testBubbleSort();
    void testSelectionSort();
    void testInsertionSort();
    void testMergeSort();
    void testQuickSort();
  };
}

#endif /* !TEST_SORT_ALGORITHM_HH_ */
