#include <gtest/gtest.h>
#include "bignum.h" 

using bignum::bigint;

// ================ ADD tests ================
// --- 25 within unsigned long long ---
TEST(AddTest, Small_01) { bigint a("0"); bigint b("0"); a.add(b); EXPECT_EQ(a.to_str(), "0"); }
TEST(AddTest, Small_02) { bigint a("5"); bigint b("3"); a.add(b); EXPECT_EQ(a.to_str(), "8"); }
TEST(AddTest, Small_03) { bigint a("123"); bigint b("456"); a.add(b); EXPECT_EQ(a.to_str(), "579"); }
TEST(AddTest, Small_04) { bigint a("999"); bigint b("1"); a.add(b); EXPECT_EQ(a.to_str(), "1000"); }
TEST(AddTest, Small_05) { bigint a("1000000"); bigint b("2000000"); a.add(b); EXPECT_EQ(a.to_str(), "3000000"); }
TEST(AddTest, Small_06) { bigint a("0"); bigint b("12345"); a.add(b); EXPECT_EQ(a.to_str(), "12345"); }
TEST(AddTest, Small_07) { bigint a("18446744073709551615"); bigint b("0"); a.add(b); EXPECT_EQ(a.to_str(), "18446744073709551615"); }
TEST(AddTest, Small_08) { bigint a("18446744073709551615"); bigint b("1"); a.add(b); EXPECT_EQ(a.to_str(), "18446744073709551616"); }
TEST(AddTest, Small_09) { bigint a("18446744073709551615"); bigint b("18446744073709551615"); a.add(b); EXPECT_EQ(a.to_str(), "36893488147419103230"); }
TEST(AddTest, Small_10) { bigint a("-5"); bigint b("-3"); a.add(b); EXPECT_EQ(a.to_str(), "-8"); }
TEST(AddTest, Small_11) { bigint a("-100"); bigint b("-200"); a.add(b); EXPECT_EQ(a.to_str(), "-300"); }
TEST(AddTest, Small_12) { bigint a("-999"); bigint b("-1"); a.add(b); EXPECT_EQ(a.to_str(), "-1000"); }
TEST(AddTest, Small_13) { bigint a("5"); bigint b("-3"); a.add(b); EXPECT_EQ(a.to_str(), "2"); }
TEST(AddTest, Small_14) { bigint a("3"); bigint b("-5"); a.add(b); EXPECT_EQ(a.to_str(), "-2"); }
TEST(AddTest, Small_15) { bigint a("-5"); bigint b("3"); a.add(b); EXPECT_EQ(a.to_str(), "-2"); }
TEST(AddTest, Small_16) { bigint a("-3"); bigint b("5"); a.add(b); EXPECT_EQ(a.to_str(), "2"); }
TEST(AddTest, Small_17) { bigint a("123456789"); bigint b("-123456789"); a.add(b); EXPECT_EQ(a.to_str(), "0"); }
TEST(AddTest, Small_18) { bigint a("-987654321"); bigint b("987654321"); a.add(b); EXPECT_EQ(a.to_str(), "0"); }
TEST(AddTest, Small_19) { bigint a("0"); bigint b("-0"); a.add(b); EXPECT_EQ(a.to_str(), "0"); }
TEST(AddTest, Small_20) { bigint a("18446744073709551615"); bigint b("-1"); a.add(b); EXPECT_EQ(a.to_str(), "18446744073709551614"); }
TEST(AddTest, Small_21) { bigint a("-18446744073709551615"); bigint b("1"); a.add(b); EXPECT_EQ(a.to_str(), "-18446744073709551614"); }
TEST(AddTest, Small_22) { bigint a("-18446744073709551615"); bigint b("-1"); a.add(b); EXPECT_EQ(a.to_str(), "-18446744073709551616"); }
TEST(AddTest, Small_23) { bigint a("12345678901234567890"); bigint b("9876543210987654321"); a.add(b); EXPECT_EQ(a.to_str(), "22222222112222222211"); }  // исправлено
TEST(AddTest, Small_24) { bigint a("9999999999999999999"); bigint b("1"); a.add(b); EXPECT_EQ(a.to_str(), "10000000000000000000"); }
TEST(AddTest, Small_25) { bigint a("0"); bigint b("-12345678901234567890"); a.add(b); EXPECT_EQ(a.to_str(), "-12345678901234567890"); }

// --- 50 exceeding unsigned long long ---
TEST(AddTest, Large_01) { bigint a("18446744073709551616"); bigint b("0"); a.add(b); EXPECT_EQ(a.to_str(), "18446744073709551616"); }
TEST(AddTest, Large_02) { bigint a("18446744073709551616"); bigint b("1"); a.add(b); EXPECT_EQ(a.to_str(), "18446744073709551617"); }
TEST(AddTest, Large_03) { bigint a("18446744073709551616"); bigint b("18446744073709551616"); a.add(b); EXPECT_EQ(a.to_str(), "36893488147419103232"); }
TEST(AddTest, Large_04) { bigint a("-18446744073709551616"); bigint b("-18446744073709551616"); a.add(b); EXPECT_EQ(a.to_str(), "-36893488147419103232"); }
TEST(AddTest, Large_05) { bigint a("18446744073709551616"); bigint b("-1"); a.add(b); EXPECT_EQ(a.to_str(), "18446744073709551615"); }
TEST(AddTest, Large_06) { bigint a("1"); bigint b("-18446744073709551616"); a.add(b); EXPECT_EQ(a.to_str(), "-18446744073709551615"); }
TEST(AddTest, Large_07) { bigint a("1000000000000000000000000000000"); bigint b("0"); a.add(b); EXPECT_EQ(a.to_str(), "1000000000000000000000000000000"); }
TEST(AddTest, Large_08) { bigint a("1000000000000000000000000000000"); bigint b("1"); a.add(b); EXPECT_EQ(a.to_str(), "1000000000000000000000000000001"); }
TEST(AddTest, Large_09) { bigint a("1000000000000000000000000000000"); bigint b("2000000000000000000000000000000"); a.add(b); EXPECT_EQ(a.to_str(), "3000000000000000000000000000000"); }
TEST(AddTest, Large_10) { bigint a("999999999999999999999999999999"); bigint b("1"); a.add(b); EXPECT_EQ(a.to_str(), "1000000000000000000000000000000"); }
TEST(AddTest, Large_11) { bigint a("1234567890123456789012345678901234567890"); bigint b("0"); a.add(b); EXPECT_EQ(a.to_str(), "1234567890123456789012345678901234567890"); }
TEST(AddTest, Large_12) { bigint a("1234567890123456789012345678901234567890"); bigint b("9876543210987654321098765432109876543210"); a.add(b); EXPECT_EQ(a.to_str(), "11111111101111111110111111111011111111100"); }
TEST(AddTest, Large_13) { bigint a("-1000000000000000000000000000000"); bigint b("-2000000000000000000000000000000"); a.add(b); EXPECT_EQ(a.to_str(), "-3000000000000000000000000000000"); }
TEST(AddTest, Large_14) { bigint a("-1000000000000000000000000000000"); bigint b("1"); a.add(b); EXPECT_EQ(a.to_str(), "-999999999999999999999999999999"); }
TEST(AddTest, Large_15) { bigint a("1000000000000000000000000000000"); bigint b("-1"); a.add(b); EXPECT_EQ(a.to_str(), "999999999999999999999999999999"); }
TEST(AddTest, Large_16) { bigint a("-1000000000000000000000000000000"); bigint b("-1"); a.add(b); EXPECT_EQ(a.to_str(), "-1000000000000000000000000000001"); }
TEST(AddTest, Large_17) { bigint a("1234567890123456789012345678901234567890"); bigint b("-1234567890123456789012345678901234567890"); a.add(b); EXPECT_EQ(a.to_str(), "0"); }
TEST(AddTest, Large_18) { bigint a("-1234567890123456789012345678901234567890"); bigint b("1234567890123456789012345678901234567890"); a.add(b); EXPECT_EQ(a.to_str(), "0"); }
TEST(AddTest, Large_19) { bigint a("0"); bigint b("-1234567890123456789012345678901234567890"); a.add(b); EXPECT_EQ(a.to_str(), "-1234567890123456789012345678901234567890"); }
TEST(AddTest, Large_20) { bigint a("1" + std::string(50, '0')); bigint b("2" + std::string(50, '0')); a.add(b); EXPECT_EQ(a.to_str(), "3" + std::string(50, '0')); }
TEST(AddTest, Large_21) { bigint a("1" + std::string(100, '0')); bigint b("1"); a.add(b); EXPECT_EQ(a.to_str(), "1" + std::string(99, '0') + "1"); }
TEST(AddTest, Large_22) { bigint a("9" + std::string(100, '9')); bigint b("1"); a.add(b); EXPECT_EQ(a.to_str(), "1" + std::string(101, '0')); }
TEST(AddTest, Large_23) { bigint a("5" + std::string(60, '5')); bigint b("5" + std::string(60, '5')); a.add(b); EXPECT_EQ(a.to_str(), "1" + std::string(60, '1') + "0"); }
TEST(AddTest, Large_24) { bigint a("-" + std::string(80, '8')); bigint b("-" + std::string(80, '1')); a.add(b); EXPECT_EQ(a.to_str(), "-" + std::string(80, '9')); }
TEST(AddTest, Large_25) { bigint a(std::string(100, '9')); bigint b("1"); a.add(b); EXPECT_EQ(a.to_str(), "1" + std::string(100, '0')); }
TEST(AddTest, Large_26) { bigint a("1" + std::string(150, '0')); bigint b("-" + std::string(150, '9')); a.add(b); EXPECT_EQ(a.to_str(), "1"); }
TEST(AddTest, Large_27) { bigint a("-1" + std::string(150, '0')); bigint b(std::string(150, '9')); a.add(b); EXPECT_EQ(a.to_str(), "-1"); }
TEST(AddTest, Large_28) { bigint a("1" + std::string(60, '0')); bigint b("-1" + std::string(59, '0') + "1"); a.add(b); EXPECT_EQ(a.to_str(), "-1"); }
TEST(AddTest, Large_29) { bigint a("-1" + std::string(60, '0')); bigint b("1" + std::string(59, '0') + "1"); a.add(b); EXPECT_EQ(a.to_str(), "1"); }
TEST(AddTest, Large_30) { bigint a("12345678901234567890123456789012345678901234567890"); bigint b("98765432109876543210987654321098765432109876543210"); a.add(b); EXPECT_EQ(a.to_str(), "111111111011111111101111111110111111111011111111100"); }
TEST(AddTest, Large_31) { bigint a("0"); bigint b("100000000000000000000000000000000000000000000000000"); a.add(b); EXPECT_EQ(a.to_str(), "100000000000000000000000000000000000000000000000000"); }
TEST(AddTest, Large_32) { bigint a("100000000000000000000000000000000000000000000000000"); bigint b("0"); a.add(b); EXPECT_EQ(a.to_str(), "100000000000000000000000000000000000000000000000000"); }
TEST(AddTest, Large_33) { bigint a("-" + std::string(200, '9')); bigint b("-" + std::string(200, '9')); a.add(b); EXPECT_EQ(a.to_str(), "-1" + std::string(199, '9') + "8"); }
TEST(AddTest, Large_34) { bigint a(std::string(200, '5')); bigint b(std::string(200, '5')); a.add(b); EXPECT_EQ(a.to_str(), "1" + std::string(199, '1') + "0"); }
TEST(AddTest, Large_35) { bigint a("123" + std::string(100, '0')); bigint b("-" + std::string(100, '9')); a.add(b); EXPECT_EQ(a.to_str(), "122" + std::string(99, '0') + "1"); }
TEST(AddTest, Large_36) { bigint a("-123" + std::string(100, '0')); bigint b(std::string(100, '9')); a.add(b); EXPECT_EQ(a.to_str(), "-122" + std::string(99, '0') + "1"); }
TEST(AddTest, Large_37) { bigint a("1" + std::string(75, '0') + "1"); bigint b("1" + std::string(74, '9')); a.add(b); EXPECT_EQ(a.to_str(), "102" + std::string(74, '0')); }
TEST(AddTest, Large_38) { bigint a("-1" + std::string(75, '0') + "1"); bigint b("-1" + std::string(74, '9')); a.add(b); EXPECT_EQ(a.to_str(), "-102" + std::string(74, '0')); }
TEST(AddTest, Large_39) { bigint a("5" + std::string(90, '0')); bigint b("-4" + std::string(90, '9')); a.add(b); EXPECT_EQ(a.to_str(), "1"); }
TEST(AddTest, Large_40) { bigint a("-5" + std::string(90, '0')); bigint b("4" + std::string(90, '9')); a.add(b); EXPECT_EQ(a.to_str(), "-1"); }
TEST(AddTest, Large_41) { bigint a("1" + std::string(120, '0')); bigint b("-1" + std::string(120, '0')); a.add(b); EXPECT_EQ(a.to_str(), "0"); }
TEST(AddTest, Large_42) { bigint a(std::string(130, '1')); bigint b(std::string(130, '2')); a.add(b); EXPECT_EQ(a.to_str(), std::string(130, '3')); }
TEST(AddTest, Large_43) { bigint a(std::string(130, '9')); bigint b("1"); a.add(b); EXPECT_EQ(a.to_str(), "1" + std::string(130, '0')); }
TEST(AddTest, Large_44) { bigint a("999" + std::string(50, '9')); bigint b("1"); a.add(b); EXPECT_EQ(a.to_str(), "1000" + std::string(50, '0')); }
TEST(AddTest, Large_45) { bigint a("-" + std::string(140, '1')); bigint b("-" + std::string(140, '9')); a.add(b); EXPECT_EQ(a.to_str(), "-1" + std::string(139, '1') + "0"); }
TEST(AddTest, Large_46) { bigint a(std::string(140, '8')); bigint b(std::string(140, '2')); a.add(b); EXPECT_EQ(a.to_str(), "1" + std::string(139, '1') + "0"); }
TEST(AddTest, Large_47) { bigint a("1" + std::string(160, '0')); bigint b("-1"); a.add(b); EXPECT_EQ(a.to_str(), std::string(160, '9')); }  // исправлено
TEST(AddTest, Large_48) { bigint a("-1" + std::string(160, '0')); bigint b("1"); a.add(b); EXPECT_EQ(a.to_str(), "-" + std::string(160, '9')); }  // исправлено
TEST(AddTest, Large_49) { bigint a("2" + std::string(170, '0')); bigint b("-1" + std::string(170, '0')); a.add(b); EXPECT_EQ(a.to_str(), "1" + std::string(170, '0')); }
TEST(AddTest, Large_50) { bigint a("-2" + std::string(170, '0')); bigint b("1" + std::string(170, '0')); a.add(b); EXPECT_EQ(a.to_str(), "-1" + std::string(170, '0')); }

// ================ SUB tests ================
// --- 25 within unsigned long long ---
TEST(SubTest, Small_01) { bigint a("0"); bigint b("0"); a.sub(b); EXPECT_EQ(a.to_str(), "0"); }
TEST(SubTest, Small_02) { bigint a("5"); bigint b("3"); a.sub(b); EXPECT_EQ(a.to_str(), "2"); }
TEST(SubTest, Small_03) { bigint a("123"); bigint b("456"); a.sub(b); EXPECT_EQ(a.to_str(), "-333"); }
TEST(SubTest, Small_04) { bigint a("1000"); bigint b("1"); a.sub(b); EXPECT_EQ(a.to_str(), "999"); }
TEST(SubTest, Small_05) { bigint a("3000000"); bigint b("2000000"); a.sub(b); EXPECT_EQ(a.to_str(), "1000000"); }
TEST(SubTest, Small_06) { bigint a("0"); bigint b("12345"); a.sub(b); EXPECT_EQ(a.to_str(), "-12345"); }
TEST(SubTest, Small_07) { bigint a("18446744073709551615"); bigint b("0"); a.sub(b); EXPECT_EQ(a.to_str(), "18446744073709551615"); }
TEST(SubTest, Small_08) { bigint a("18446744073709551616"); bigint b("1"); a.sub(b); EXPECT_EQ(a.to_str(), "18446744073709551615"); }
TEST(SubTest, Small_09) { bigint a("18446744073709551615"); bigint b("18446744073709551615"); a.sub(b); EXPECT_EQ(a.to_str(), "0"); }
TEST(SubTest, Small_10) { bigint a("-5"); bigint b("-3"); a.sub(b); EXPECT_EQ(a.to_str(), "-2"); }
TEST(SubTest, Small_11) { bigint a("-100"); bigint b("-200"); a.sub(b); EXPECT_EQ(a.to_str(), "100"); }
TEST(SubTest, Small_12) { bigint a("-1000"); bigint b("-1"); a.sub(b); EXPECT_EQ(a.to_str(), "-999"); }
TEST(SubTest, Small_13) { bigint a("5"); bigint b("-3"); a.sub(b); EXPECT_EQ(a.to_str(), "8"); }
TEST(SubTest, Small_14) { bigint a("3"); bigint b("-5"); a.sub(b); EXPECT_EQ(a.to_str(), "8"); }
TEST(SubTest, Small_15) { bigint a("-5"); bigint b("3"); a.sub(b); EXPECT_EQ(a.to_str(), "-8"); }
TEST(SubTest, Small_16) { bigint a("-3"); bigint b("5"); a.sub(b); EXPECT_EQ(a.to_str(), "-8"); }
TEST(SubTest, Small_17) { bigint a("123456789"); bigint b("123456789"); a.sub(b); EXPECT_EQ(a.to_str(), "0"); }
TEST(SubTest, Small_18) { bigint a("-987654321"); bigint b("-987654321"); a.sub(b); EXPECT_EQ(a.to_str(), "0"); }
TEST(SubTest, Small_19) { bigint a("0"); bigint b("-0"); a.sub(b); EXPECT_EQ(a.to_str(), "0"); }
TEST(SubTest, Small_20) { bigint a("18446744073709551615"); bigint b("-1"); a.sub(b); EXPECT_EQ(a.to_str(), "18446744073709551616"); }
TEST(SubTest, Small_21) { bigint a("-18446744073709551615"); bigint b("1"); a.sub(b); EXPECT_EQ(a.to_str(), "-18446744073709551616"); }
TEST(SubTest, Small_22) { bigint a("-18446744073709551615"); bigint b("-1"); a.sub(b); EXPECT_EQ(a.to_str(), "-18446744073709551614"); }
TEST(SubTest, Small_23) { bigint a("22222222112222222211"); bigint b("9876543210987654321"); a.sub(b); EXPECT_EQ(a.to_str(), "12345678901234567890"); }  // исправлено
TEST(SubTest, Small_24) { bigint a("10000000000000000000"); bigint b("1"); a.sub(b); EXPECT_EQ(a.to_str(), "9999999999999999999"); }
TEST(SubTest, Small_25) { bigint a("-12345678901234567890"); bigint b("0"); a.sub(b); EXPECT_EQ(a.to_str(), "-12345678901234567890"); }

// --- 50 exceeding unsigned long long ---
TEST(SubTest, Large_01) { bigint a("18446744073709551616"); bigint b("0"); a.sub(b); EXPECT_EQ(a.to_str(), "18446744073709551616"); }
TEST(SubTest, Large_02) { bigint a("18446744073709551616"); bigint b("1"); a.sub(b); EXPECT_EQ(a.to_str(), "18446744073709551615"); }
TEST(SubTest, Large_03) { bigint a("18446744073709551616"); bigint b("18446744073709551616"); a.sub(b); EXPECT_EQ(a.to_str(), "0"); }
TEST(SubTest, Large_04) { bigint a("-18446744073709551616"); bigint b("-18446744073709551616"); a.sub(b); EXPECT_EQ(a.to_str(), "0"); }
TEST(SubTest, Large_05) { bigint a("18446744073709551616"); bigint b("-1"); a.sub(b); EXPECT_EQ(a.to_str(), "18446744073709551617"); }
TEST(SubTest, Large_06) { bigint a("1"); bigint b("18446744073709551616"); a.sub(b); EXPECT_EQ(a.to_str(), "-18446744073709551615"); }
TEST(SubTest, Large_07) { bigint a("1000000000000000000000000000000"); bigint b("0"); a.sub(b); EXPECT_EQ(a.to_str(), "1000000000000000000000000000000"); }
TEST(SubTest, Large_08) { bigint a("1000000000000000000000000000000"); bigint b("1"); a.sub(b); EXPECT_EQ(a.to_str(), "999999999999999999999999999999"); }
TEST(SubTest, Large_09) { bigint a("3000000000000000000000000000000"); bigint b("2000000000000000000000000000000"); a.sub(b); EXPECT_EQ(a.to_str(), "1000000000000000000000000000000"); }
TEST(SubTest, Large_10) { bigint a("1000000000000000000000000000000"); bigint b("999999999999999999999999999999"); a.sub(b); EXPECT_EQ(a.to_str(), "1"); }
TEST(SubTest, Large_11) { bigint a("1234567890123456789012345678901234567890"); bigint b("0"); a.sub(b); EXPECT_EQ(a.to_str(), "1234567890123456789012345678901234567890"); }
TEST(SubTest, Large_12) { bigint a("9876543210987654321098765432109876543210"); bigint b("1234567890123456789012345678901234567890"); a.sub(b); EXPECT_EQ(a.to_str(), "8641975320864197532086419753208641975320"); }
TEST(SubTest, Large_13) { bigint a("-1000000000000000000000000000000"); bigint b("2000000000000000000000000000000"); a.sub(b); EXPECT_EQ(a.to_str(), "-3000000000000000000000000000000"); }
TEST(SubTest, Large_14) { bigint a("-1000000000000000000000000000000"); bigint b("-1"); a.sub(b); EXPECT_EQ(a.to_str(), "-999999999999999999999999999999"); }
TEST(SubTest, Large_15) { bigint a("1000000000000000000000000000000"); bigint b("-1"); a.sub(b); EXPECT_EQ(a.to_str(), "1000000000000000000000000000001"); }
TEST(SubTest, Large_16) { bigint a("-1"); bigint b("1000000000000000000000000000000"); a.sub(b); EXPECT_EQ(a.to_str(), "-1000000000000000000000000000001"); }
TEST(SubTest, Large_17) { bigint a("1234567890123456789012345678901234567890"); bigint b("1234567890123456789012345678901234567890"); a.sub(b); EXPECT_EQ(a.to_str(), "0"); }
TEST(SubTest, Large_18) { bigint a("-1234567890123456789012345678901234567890"); bigint b("-1234567890123456789012345678901234567890"); a.sub(b); EXPECT_EQ(a.to_str(), "0"); }
TEST(SubTest, Large_19) { bigint a("0"); bigint b("-1234567890123456789012345678901234567890"); a.sub(b); EXPECT_EQ(a.to_str(), "1234567890123456789012345678901234567890"); }
TEST(SubTest, Large_20) { bigint a("3" + std::string(50, '0')); bigint b("2" + std::string(50, '0')); a.sub(b); EXPECT_EQ(a.to_str(), "1" + std::string(50, '0')); }
TEST(SubTest, Large_21) { bigint a("1" + std::string(100, '0') + "1"); bigint b("1"); a.sub(b); EXPECT_EQ(a.to_str(), "1" + std::string(101, '0')); }
TEST(SubTest, Large_22) { bigint a("1" + std::string(101, '0')); bigint b("1"); a.sub(b); EXPECT_EQ(a.to_str(), "9" + std::string(100, '9')); }
TEST(SubTest, Large_23) { bigint a("1" + std::string(60, '1') + "0"); bigint b("5" + std::string(60, '5')); a.sub(b); EXPECT_EQ(a.to_str(), "5" + std::string(60, '5')); }
TEST(SubTest, Large_24) { bigint a("-" + std::string(80, '8')); bigint b("-" + std::string(80, '1')); a.sub(b); EXPECT_EQ(a.to_str(), "-" + std::string(80, '7')); }
TEST(SubTest, Large_25) { bigint a("1" + std::string(100, '0')); bigint b("1"); a.sub(b); EXPECT_EQ(a.to_str(), "9" + std::string(99, '9')); }
TEST(SubTest, Large_26) { bigint a("1" + std::string(150, '0')); bigint b(std::string(150, '9')); a.sub(b); EXPECT_EQ(a.to_str(), "1"); }
TEST(SubTest, Large_27) { bigint a("-1" + std::string(150, '0')); bigint b("-" + std::string(150, '9')); a.sub(b); EXPECT_EQ(a.to_str(), "-1"); }
TEST(SubTest, Large_28) { bigint a("1" + std::string(60, '0')); bigint b("1" + std::string(59, '0') + "1"); a.sub(b); EXPECT_EQ(a.to_str(), "-1"); }
TEST(SubTest, Large_29) { bigint a("-1" + std::string(60, '0')); bigint b("-1" + std::string(59, '0') + "1"); a.sub(b); EXPECT_EQ(a.to_str(), "1"); }  // исправлено
TEST(SubTest, Large_30) { bigint a("111111111011111111101111111110111111111011111111100"); bigint b("98765432109876543210987654321098765432109876543210"); a.sub(b); EXPECT_EQ(a.to_str(), "12345678901234567890123456789012345678901234567890"); }
TEST(SubTest, Large_31) { bigint a("100000000000000000000000000000000000000000000000000"); bigint b("0"); a.sub(b); EXPECT_EQ(a.to_str(), "100000000000000000000000000000000000000000000000000"); }
TEST(SubTest, Large_32) { bigint a("0"); bigint b("100000000000000000000000000000000000000000000000000"); a.sub(b); EXPECT_EQ(a.to_str(), "-100000000000000000000000000000000000000000000000000"); }
TEST(SubTest, Large_33) { bigint a("-" + std::string(200, '9')); bigint b("-" + std::string(200, '9')); a.sub(b); EXPECT_EQ(a.to_str(), "0"); }
TEST(SubTest, Large_34) { bigint a("1" + std::string(199, '1') + "0"); bigint b(std::string(200, '5')); a.sub(b); EXPECT_EQ(a.to_str(), std::string(200, '5')); }
TEST(SubTest, Large_35) { bigint a("122" + std::string(99, '0') + "1"); bigint b("123" + std::string(100, '0')); a.sub(b); EXPECT_EQ(a.to_str(), "-" + std::string(100, '9')); }
TEST(SubTest, Large_36) { bigint a("-122" + std::string(99, '0') + "1"); bigint b("-123" + std::string(100, '0')); a.sub(b); EXPECT_EQ(a.to_str(), std::string(100, '9')); }
TEST(SubTest, Large_37) { bigint a("2" + std::string(74, '0') + "1"); bigint b("1" + std::string(75, '0') + "1"); a.sub(b); EXPECT_EQ(a.to_str(), "-8" + std::string(75, '0')); }  // исправлено
TEST(SubTest, Large_38) { bigint a("-2" + std::string(74, '0') + "1"); bigint b("-1" + std::string(75, '0') + "1"); a.sub(b); EXPECT_EQ(a.to_str(), "8" + std::string(75, '0')); }  // исправлено
TEST(SubTest, Large_39) { bigint a("1"); bigint b("5" + std::string(90, '0')); a.sub(b); EXPECT_EQ(a.to_str(), "-4" + std::string(90, '9')); }
TEST(SubTest, Large_40) { bigint a("-1"); bigint b("-5" + std::string(90, '0')); a.sub(b); EXPECT_EQ(a.to_str(), "4" + std::string(90, '9')); }
TEST(SubTest, Large_41) { bigint a("1" + std::string(120, '0')); bigint b("1" + std::string(120, '0')); a.sub(b); EXPECT_EQ(a.to_str(), "0"); }
TEST(SubTest, Large_42) { bigint a(std::string(130, '3')); bigint b(std::string(130, '2')); a.sub(b); EXPECT_EQ(a.to_str(), std::string(130, '1')); }
TEST(SubTest, Large_43) { bigint a("1" + std::string(130, '0')); bigint b("1"); a.sub(b); EXPECT_EQ(a.to_str(), std::string(130, '9')); }
TEST(SubTest, Large_44) { bigint a("1000" + std::string(50, '0')); bigint b("1"); a.sub(b); EXPECT_EQ(a.to_str(), "999" + std::string(50, '9')); }
TEST(SubTest, Large_45) { bigint a("-" + std::string(139, '1') + "0"); bigint b("-" + std::string(140, '9')); a.sub(b); EXPECT_EQ(a.to_str(), std::string(139, '8') + "9"); }  // исправлено
TEST(SubTest, Large_46) { bigint a("1" + std::string(139, '1') + "0"); bigint b(std::string(140, '8')); a.sub(b); EXPECT_EQ(a.to_str(), std::string(140, '2')); }
TEST(SubTest, Large_47) { bigint a("999" + std::string(158, '9')); bigint b("1" + std::string(160, '0')); a.sub(b); EXPECT_EQ(a.to_str(), "8" + std::string(160, '9')); }  // исправлено
TEST(SubTest, Large_48) { bigint a("-999" + std::string(158, '9')); bigint b("-1" + std::string(160, '0')); a.sub(b); EXPECT_EQ(a.to_str(), "-8" + std::string(160, '9')); }  // исправлено
TEST(SubTest, Large_49) { bigint a("1" + std::string(170, '0')); bigint b("2" + std::string(170, '0')); a.sub(b); EXPECT_EQ(a.to_str(), "-1" + std::string(170, '0')); }
TEST(SubTest, Large_50) { bigint a("-1" + std::string(170, '0')); bigint b("-2" + std::string(170, '0')); a.sub(b); EXPECT_EQ(a.to_str(), "1" + std::string(170, '0')); }