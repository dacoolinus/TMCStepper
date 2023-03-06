#pragma once
#pragma pack(push, 1)

namespace TMC2226_n
{

    // ---------------------------------------------
    // General Registers
    // ---------------------------------------------
    struct GCONF_t
    {
        constexpr static uint8_t address = 0x00;
        union
        {
            uint16_t sr : 10;
            struct
            {
                bool i_scale_analog : 1,
                    internal_rsense : 1,
                    en_spreadcycle : 1,
                    shaft : 1,
                    index_otpw : 1,
                    index_step : 1,
                    pdn_disable : 1,
                    mstep_reg_select : 1,
                    multistep_filt : 1,
                    test_mode : 1;
            };
        };
    };

    struct GSTAT_t
    {
        constexpr static uint8_t address = 0x01;
        union
        {
            uint16_t sr;
            struct
            {
                bool reset : 1,
                    drv_err : 1,
                    uv_cp : 1;
            };
        };
    };

    struct IFCNT_t
    {
        constexpr static uint8_t address = 0x02;
        uint8_t sr;
    };

    struct SLAVECONF_t
    {
        constexpr static uint8_t address = 0x03;
    };

    struct OTP_PROG_t
    {
        constexpr static uint8_t address = 0x04;
    };

    struct OTP_READ_t
    {
        constexpr static uint8_t address = 0x05;
    };

    struct IOIN_t
    {
        constexpr static uint8_t address = 0x06;
        union
        {
            uint32_t sr;
            struct
            {
                bool enn : 1, : 1,
                    ms1 : 1,
                    ms2 : 1,
                    diag : 1, : 1,
                    pdn_uart : 1,
                    step : 1,
                    spread_en : 1,
                    dir : 1;
                uint16_t : 14;
                uint8_t version : 8;
            };
        };
    };

    struct FACTORY_CONF_t
    {
        constexpr static uint8_t address = 0x07;
        union
        {
            uint16_t sr;
            struct
            {
                uint8_t fclktrim : 5, : 3,
                    ottrim : 2;
            };
        };
    };

    // ---------------------------------------------
    // Velocity Dependent Control Registers
    // ---------------------------------------------

    struct IHOLD_IRUN_t
    {
        constexpr static uint8_t address = 0x10;
    };

    struct TPOWER_DOWN_t
    {
        constexpr static uint8_t address = 0x11;
    };

    struct TSTEP_t
    {
        constexpr static uint8_t address = 0x12;
    };

    struct TPWMTHRS_t
    {
        constexpr static uint8_t address = 0x13;
    };

    struct VACTUAL_t
    {
        constexpr static uint8_t address = 0x22;
        uint32_t sr;
    };

    // ---------------------------------------------
    // StallGuard Control Registers
    // ---------------------------------------------

    struct TCOOLTHRS_t
    {
        constexpr static uint8_t address = 0x14;
    };

    struct SGTHRS_t
    {
        constexpr static uint8_t address = 0x40;
    };

    struct SG_RESULT_t
    {
        constexpr static uint8_t address = 0x41;
        union
        {
            uint32_t sr;
            struct
            {
                uint16_t upper : 16,
                lower : 9;
            };
        };
    };

    struct COOLCONF_t
    {
        constexpr static uint8_t address = 0x42;
    };

    // ---------------------------------------------
    // Sequencer Registers
    // ---------------------------------------------

    struct MSCNT_t
    {
        constexpr static uint8_t address = 0x6A;
    };

    struct MSCURACT_t
    {
        constexpr static uint8_t address = 0x6B;
        union
        {
            uint32_t sr : 25;
            struct
            {
                int16_t cur_a : 9, : 7,
                    cur_b : 9;
            };
        };
    };

    // ---------------------------------------------
    // Chopper Control Registers
    // ---------------------------------------------

    struct CHOPCONF_t
    {
        constexpr static uint8_t address = 0x6C;
        union
        {
            uint32_t sr;
            struct
            {
                uint32_t toff : 4,
                    hstrt : 4,
                    hend : 4, : 4,
                    tbl : 2;
                bool vsense : 1;
                uint8_t : 6,
                    mres : 4;
                bool intpol : 1,
                    dedge : 1,
                    diss2g : 1,
                    diss2vs : 1;
            };
        };
    };

    struct DRV_STATUS_t
    {
        constexpr static uint8_t address = 0x6F;
        union
        {
            uint32_t sr;
            struct
            {
                bool otpw : 1,
                    ot : 1,
                    s2ga : 1,
                    s2gb : 1,
                    s2vsa : 1,
                    s2vsb : 1,
                    ola : 1,
                    olb : 1,
                    t120 : 1,
                    t143 : 1,
                    t150 : 1,
                    t157 : 1;
                uint8_t : 4,
                    cs_actual : 5, : 3, : 6;
                bool stealth : 1,
                    stst : 1;
            };
        };
    };

    struct PWMCONF_t
    {
        constexpr static uint8_t address = 0x70;
        union
        {
            uint32_t sr;
            struct
            {
                uint8_t pwm_ofs : 8,
                    pwm_grad : 8,
                    pwm_freq : 2;
                bool pwm_autoscale : 1,
                    pwm_autograd : 1;
                uint8_t freewheel : 2, : 2,
                    pwm_reg : 4,
                    pwm_lim : 4;
            };
        };
    };

    struct PWM_SCALE_t
    {
        constexpr static uint8_t address = 0x71;
        union
        {
            uint32_t sr;
            struct
            {
                uint8_t pwm_scale_sum : 8, : 8;
                int16_t pwm_scale_auto : 9;
            };
        };
    };

    struct PWM_AUTO_t
    {
        constexpr static uint8_t address = 0x72;
    };

}

#pragma pack(pop)