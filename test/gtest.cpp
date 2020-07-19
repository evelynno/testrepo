#include "gtest/gtest.h"        // framework headers
#include "gmock/gmock.h"        // mocking headers
#include "main.h"
#include "rapidcheck/gtest.h"


// Mocked class of interface
class mockInterface : public interface {
public:
    MOCK_METHOD(int, private_function, (), (override));
};

using ::testing::Return;

// Mocking the private_function() in interface
// Confirming it returns correctly with all possible inputs
TEST(mockTest, testIf) {
    mockInterface m;
    EXPECT_CALL(m, private_function())
        .WillOnce(Return(2))
        .WillOnce(Return(1))
        .WillOnce(Return(0));

    ASSERT_EQ(1, m.public_function());
    ASSERT_EQ(1, m.public_function());
    ASSERT_EQ(0, m.public_function());
}

// Testing create_cx
TEST(mainTests, testCreateCx) {
    int_cx* cx = create_cx();
    ASSERT_NE(cx, nullptr);
    ASSERT_NE(cx->in, nullptr);
}

// Testing results of inside_function()
TEST(mainTests, testInsideFunction) {
    ASSERT_EQ(1, inside_function());
}

// Testing mocking of inside_function()
TEST(mainTests, testOutsideFunction) {
    ASSERT_EQ(1, outside_function());
    // We can't easily mock single functions (although it is possible
    // by wrapping them in a class)
    // https://chromium.googlesource.com/external/github.com/google/googletest/+/HEAD/googlemock/docs/cook_book.md#MockingFreeFunctions
    ASSERT_EQ(0, outside_function());
}

RC_GTEST_PROP(rapidcheckTest, add_two_ints, (int a, int b)){
    RC_ASSERT(a+b == add_two_ints(a,b));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
