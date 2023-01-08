#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <fstream>        // std::fstream
#include "../HTMLChecker.cpp"


TEST_CASE("The working path should be set") {
    fstream file_in("samples/simple.html", fstream::in);
    bool is_empty = file_in.peek() == std::ifstream::traits_type::eof();
    REQUIRE_FALSE(is_empty);
}

TEST_CASE("Should be able to create a HTML Checker") {
    HTMLChecker checker = HTMLChecker();
}
TEST_CASE("Should be able to load a HTML file") {
    HTMLChecker checker = HTMLChecker();
    REQUIRE(checker.load("samples/simple.html"));
}


TEST_CASE("Simple.html should be valid") {
    HTMLChecker checker = HTMLChecker();
    REQUIRE(checker.load("samples/simple.html"));
    REQUIRE(checker.isValid());
}

TEST_CASE("should fail if an HTML is missing a closing tag part way through the document") {
    HTMLChecker checker = HTMLChecker();
    REQUIRE(checker.load("samples/missing_closing_tag.html"));
    REQUIRE_FALSE(checker.isValid());
}

TEST_CASE("should fail if an HTML is missing a closing tag at the end of the document") {
    HTMLChecker checker = HTMLChecker();
    REQUIRE(checker.load("samples/missing_closing_tag_at_end.html"));
    REQUIRE_FALSE(checker.isValid());
}

TEST_CASE("Should fail if an opening html tag is missing") {
    HTMLChecker checker = HTMLChecker();
    REQUIRE(checker.load("samples/missing_opening_tag.html"));
    REQUIRE_FALSE(checker.isValid());
}
