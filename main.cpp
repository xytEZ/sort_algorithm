#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <iostream>

#include "TestSortAlgorithm.hh"

CPPUNIT_TEST_SUITE_REGISTRATION(Test::TestSortAlgorithm);

int main()
{
  CPPUNIT_NS::TestResult testResult;
  CPPUNIT_NS::TestResultCollector collectedResults;
  CPPUNIT_NS::BriefTestProgressListener progress;
  CPPUNIT_NS::TestRunner testRunner;

  testResult.addListener(&collectedResults);
  testResult.addListener(&progress);
  testRunner
    .addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
  testRunner.run(testResult);

  CPPUNIT_NS::CompilerOutputter compilerOutputter(&collectedResults, std::cerr);

  compilerOutputter.write();
  return collectedResults.wasSuccessful();
}
