#include "Bubble.hpp"
#include "Selection.hpp"
#include "Insertion.hpp"
#include "Merge.hpp"
#include "Quick.hpp"

#include "TestSortAlgorithm.hh"

#include <iostream>

namespace Test
{
  void TestSortAlgorithm::setUp()
  {
    // Container to sort : { 12, 36, 5, 20, 2 }    
    _noSortedContainer.emplace_back(12);
    _noSortedContainer.emplace_back(36);
    _noSortedContainer.emplace_back(5);
    _noSortedContainer.emplace_back(20);
    _noSortedContainer.emplace_back(2);

    // Container already sorted : { 2, 5, 12, 20, 36 }
    _sortedContainer.emplace_back(2);
    _sortedContainer.emplace_back(5);
    _sortedContainer.emplace_back(12);
    _sortedContainer.emplace_back(20);
    _sortedContainer.emplace_back(36);

    _functor = [](const TypeTraits::CallTraits<int>::ParamType& i,
		  const TypeTraits::CallTraits<int>::ParamType& i2) -> bool
      { return i > i2; };
  }
  
  void TestSortAlgorithm::tearDown() { }

  void TestSortAlgorithm::testBubbleSort()
  {
    Sort::ASorter<ContainerValue<int>> *sorter;
    ContainerValue<int> container;

    sorter = new Sort::Bubble<ContainerValue<int>>(_functor);
    container.assign(_noSortedContainer.cbegin(), _noSortedContainer.cend());
    sorter->sort(container);

    delete sorter;

    CPPUNIT_ASSERT(container == _sortedContainer);
  }
  
  void TestSortAlgorithm::testSelectionSort()
  {
    Sort::ASorter<ContainerValue<int>> *sorter;
    ContainerValue<int> container;

    sorter = new Sort::Selection<ContainerValue<int>>(_functor);
    container.assign(_noSortedContainer.cbegin(), _noSortedContainer.cend());
    sorter->sort(container);

    delete sorter;

    CPPUNIT_ASSERT(container == _sortedContainer);
  }
  
  void TestSortAlgorithm::testInsertionSort()
  {
    Sort::ASorter<ContainerValue<int>> *sorter;
    ContainerValue<int> container;

    sorter = new Sort::Insertion<ContainerValue<int>>(_functor);
    container.assign(_noSortedContainer.cbegin(), _noSortedContainer.cend());
    sorter->sort(container);

    delete sorter;

    CPPUNIT_ASSERT(container == _sortedContainer);
  }
  
  void TestSortAlgorithm::testMergeSort()
  {
    Sort::ASorter<ContainerValue<int>> *sorter;
    ContainerValue<int> container;

    sorter = new Sort::Merge<ContainerValue<int>>(_functor);
    container.assign(_noSortedContainer.cbegin(), _noSortedContainer.cend());
    sorter->sort(container);

    delete sorter;

    CPPUNIT_ASSERT(container == _sortedContainer);
  }
  
  void TestSortAlgorithm::testQuickSort()
  {
    Sort::ASorter<ContainerValue<int>> *sorter;
    ContainerValue<int> container;

    sorter = new Sort::Quick<ContainerValue<int>>(_functor);
    container.assign(_noSortedContainer.cbegin(), _noSortedContainer.cend());
    sorter->sort(container);

    delete sorter;

    CPPUNIT_ASSERT(container == _sortedContainer);
  }
}
