#include "pch.h"
#include "../TargetStaticLib/LibClass.h"

using namespace MyStaticLib;

/// <summary>
/// �ÓI���C�u�����̃e�X�g
/// </summary>
namespace TargetStaticLibTest {
    TEST(LibClass, Add�֐�) {
        auto lib = new LibClass();

        // ��v
        EXPECT_EQ(2, lib->AddValues(1, 1));
        EXPECT_EQ(-5, lib->AddValues(-2, -3));

        // �s��v
        EXPECT_NE(100, lib->AddValues(2, 3));

        // ��O�Ȃ�
        EXPECT_NO_THROW(lib->AddValues(0, 0));
    }

    TEST(LibClass, DivideMethod) {
        auto lib = new LibClass();

        // ��v
        EXPECT_EQ(1, lib->DivideValues(1, 1));
        EXPECT_EQ(7.0, lib->DivideValues(7, 1));

        // ��v(double��p�}�N���� �قړ������𔻒�j
        EXPECT_DOUBLE_EQ(0.5, lib->DivideValues(1, 2));

        // ��O����(�[�����Z�łȂ񂩓�����)
        EXPECT_ANY_THROW(lib->DivideValues(1, 0));

        // ��O����(�[�����Z�Ŏw��𓊂���)
        EXPECT_THROW(lib->DivideValues(2, 0), std::runtime_error);
    }
}
