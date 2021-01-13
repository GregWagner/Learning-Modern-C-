#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include <boost/smart_ptr/scoped_ptr.hpp>

class DeadMenOfDunharrow {
  public:
    DeadMenOfDunharrow(const char* m = "") :message {m} {
      ++oaths_to_fulfill;
    }

    ~DeadMenOfDunharrow() {
      --oaths_to_fulfill;
    }
    
    const char* message;
    static int oaths_to_fulfill;
};

int DeadMenOfDunharrow::oaths_to_fulfill {};
using ScopedOathbreakers = boost::scoped_ptr<DeadMenOfDunharrow>;

TEST_CASE("ScopedPtr evaluates to") {
  SECTION("true when full") {
    ScopedOathbreakers aragorn {new DeadMenOfDunharrow{}};
    REQUIRE(aragorn);
  }
  SECTION("false when empty") {
    ScopedOathbreakers aragorn;
    REQUIRE_FALSE(aragorn);

  }
}
