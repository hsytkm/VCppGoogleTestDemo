#include "pch.h"
#include "../TargetStaticLib/LibClass.h"

using namespace MyStaticLib;

/// <summary>
/// 静的ライブラリのテスト
/// </summary>
namespace TargetStaticLibTest {
    TEST(LibClass, Add関数) {
        auto lib = new LibClass();

        // 一致
        EXPECT_EQ(2, lib->AddValues(1, 1));
        EXPECT_EQ(-5, lib->AddValues(-2, -3));

        // 不一致
        EXPECT_NE(100, lib->AddValues(2, 3));

        // 例外なし
        EXPECT_NO_THROW(lib->AddValues(0, 0));
    }

    TEST(LibClass, DivideMethod) {
        auto lib = new LibClass();

        // 一致
        EXPECT_EQ(1, lib->DivideValues(1, 1));
        EXPECT_EQ(7.0, lib->DivideValues(7, 1));

        // 一致(double専用マクロで ほぼ等しいを判定）
        EXPECT_DOUBLE_EQ(0.5, lib->DivideValues(1, 2));

        // 例外あり(ゼロ除算でなんか投げる)
        EXPECT_ANY_THROW(lib->DivideValues(1, 0));

        // 例外あり(ゼロ除算で指定を投げる)
        EXPECT_THROW(lib->DivideValues(2, 0), std::runtime_error);
    }
}
