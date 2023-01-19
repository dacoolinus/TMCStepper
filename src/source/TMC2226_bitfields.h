#pragma once
#pragma pack(push, 1)

namespace TMC2226_n{

    // ---------------------------------------------
    // General Registers
    // ---------------------------------------------
    struct GCONF_t {
        constexpr static uint8_t address = 0x00;
        union {
            uint16_t sr: 10;
            struct {
                bool i_scale_analog : 1,
                internal_rsense: 1,
                en_spreadcycle: 1,
                shaft: 1,
                index_otpw: 1,
                index_step: 1,
                pdn_disable: 1,
                mstep_reg_select: 1,
                multistep_filt: 1,
                test_mode: 1;
            };
        };
    };

    struct GSTAT_t {
        constexpr static uint8_t address = 0x01;
        union {
            uint16_t sr;
            struct {
                bool reset: 1,
                drv_err: 1,
                uv_cp: 1;
            };
        };
    };

    struct IFCNT_t {
        constexpr static uint8_t address = 0x02;
        uint8_t sr;
    };

    struct SLAVECONF_t {
        constexpr static uint8_t address = 0x03;
    };

    struct OTP_PROG_t {
        constexpr static uint8_t address = 0x04;
    };

    struct OTP_READ_t {
        constexpr static uint8_t address = 0x05;
    };

    struct IOIN_t {
        constexpr static uint8_t address = 0x06;
        union {
            uint32_t sr;
            struct {
                bool enn: 1,
                    :1,
                    ms1: 1,
                    ms2: 1,
                    diag: 1,
                    :1,
                    pdn_uart: 1,
                    step: 1,
                    spread_en: 1,
                    dir: 1;
                uint16_t: 14;
                uint8_t version: 8;
            };
        };
    };

    struct FACTORY_CONF_t {
        constexpr static uint8_t address = 0x07;
        union {
            uint16_t sr;
            struct {
                uint8_t fclktrim: 5,
                                : 3,
                        ottrim  : 2;
            };
        };
    };

    // ---------------------------------------------
    // Velocity Dependent Control Registers
    // ---------------------------------------------

    struct IHOLD_IRUN_t {
        constexpr static uint8_t address = 0x10;
    };

    struct TPOWER_DOWN_t {
        constexpr static uint8_t address = 0x11;
    };

    struct TSTEP_t {
        constexpr static uint8_t address = 0x12;
    };

    struct TPWMTHRS_t {
        constexpr static uint8_t address = 0x13;
    };

    struct VACTUAL_t {
        constexpr static uint8_t address = 0x22;
        uint32_t sr;
    };

    // ---------------------------------------------
    // StallGuard Control Registers
    // ---------------------------------------------

    struct TCOOLTHRS_t {
        constexpr static uint8_t address = 0x14;
    };

    struct SGTHRS_t {
        constexpr static uint8_t address = 0x40;
    };

    struct SG_RESULT_t {
        constexpr static uint8_t address = 0x41;
    };

    struct COOLCONF_t {
        constexpr static uint8_t address = 0x42;
    };

    // ---------------------------------------------
    // Sequencer Registers
    // ---------------------------------------------

    struct MSCNT_t {
        constexpr static uint8_t address = 0x6A;
    };

    struct MSCURACT_t {
        constexpr static uint8_t address = 0x6B;
    };

    // ---------------------------------------------
    // Chopper Control Registers
    // ---------------------------------------------

    struct CHOPCONF_t {
        constexpr static uint8_t address = 0x6C;
    };

    struct DRV_STATUS_t {
        constexpr static uint8_t address = 0x6F;
    };

    struct PWMCONF_t {
        constexpr static uint8_t address = 0x70;
    };

    struct PWM_SCALE {
        constexpr static uint8_t address = 0x71;
    };

    struct PWM_AUTO {
        constexpr static uint8_t address = 0x72;
    };

}

#pragma pack(pop)