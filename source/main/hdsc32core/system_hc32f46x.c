/*******************************************************************************
 * Copyright (C) 2016, Huada Semiconductor Co., Ltd. All rights reserved.
 *
 * This software is owned and published by:
 * Huada Semiconductor Co., Ltd. ("HDSC").
 *
 * BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
 * BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
 *
 * This software contains source code for use with HDSC
 * components. This software is licensed by HDSC to be adapted only
 * for use in systems utilizing HDSC components. HDSC shall not be
 * responsible for misuse or illegal use of this software for devices not
 * supported herein. HDSC is providing this software "AS IS" and will
 * not be responsible for issues arising from incorrect user implementation
 * of the software.
 *
 * Disclaimer:
 * HDSC MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
 * REGARDING THE SOFTWARE (INCLUDING ANY ACCOMPANYING WRITTEN MATERIALS),
 * ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING,
 * WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED
 * WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED
 * WARRANTY OF NONINFRINGEMENT.
 * HDSC SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT,
 * NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT
 * LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
 * LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR
 * INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA,
 * SAVINGS OR PROFITS,
 * EVEN IF Disclaimer HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
 * INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED
 * FROM, THE SOFTWARE.
 *
 * This software may be replicated in part or whole for the licensed use,
 * with the restriction that this Disclaimer and Copyright notice must be
 * included with each copy of this software, whether used in part or whole,
 * at all times.
 */
/******************************************************************************/
/** \file system_hc32f46x.c
 **
 ** A detailed description is available at
 ** @link Hc32f46xSystemGroup Hc32f46xSystem description @endlink
 **
 **   - 2018-10-15  1.0  Zhangxl First version
 **
 ******************************************************************************/

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "hc32_common.h"

/**
 *******************************************************************************
 ** \addtogroup Hc32f46xSystemGroup
 ******************************************************************************/

/*******************************************************************************
 * Global pre-processor symbols/macros ('define')
 ******************************************************************************/

//@{

/**
 ******************************************************************************
 ** System Clock Frequency (Core Clock) Variable according CMSIS
 ******************************************************************************/
uint32_t HRC_VALUE = HRC_16MHz_VALUE;
uint32_t SystemCoreClock = MRC_VALUE;

/**
 ******************************************************************************
 ** \brief  Setup the microcontroller system. Initialize the System and update
 ** the SystemCoreClock variable.
 **
 ** \param  None
 ** \return None
 ******************************************************************************/
void SystemInit(void)
{
#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    SCB->CPACR |= ((3UL << 20) | (3UL << 22)); /* set CP10 and CP11 Full Access */
#endif

    SystemCoreClockUpdate();
}

void SystemCoreClockUpdate(void)  // Update SystemCoreClock variable
{
    uint8_t tmp = 0u;
    uint32_t plln = 19u, pllp = 1u, pllm = 0u, pllsource = 0u;

    /* Select proper HRC_VALUE according to ICG1.HRCFREQSEL bit */
    /* ICG1.HRCFREQSEL = '0' represent HRC_VALUE = 20000000UL   */
    /* ICG1.HRCFREQSEL = '1' represent HRC_VALUE = 16000000UL   */
    if (1UL == (HRC_FREQ_MON() & 1UL))
    {
        HRC_VALUE = HRC_16MHz_VALUE;
    }
    else
    {
        HRC_VALUE = HRC_20MHz_VALUE;
    }

    tmp = M4_SYSREG->CMU_CKSWR_f.CKSW;
    switch (tmp)
    {
        case 0x00:  /* use internal high speed RC */
            SystemCoreClock = HRC_VALUE;
            break;
        case 0x01:  /* use internal middle speed RC */
            SystemCoreClock = MRC_VALUE;
            break;
        case 0x02:  /* use internal low speed RC */
            SystemCoreClock = LRC_VALUE;
            break;
        case 0x03:  /* use external high speed OSC */
            SystemCoreClock = XTAL_VALUE;
            break;
        case 0x04:  /* use external low speed OSC */
            SystemCoreClock = XTAL32_VALUE;
            break;
        case 0x05:  /* use MPLL */
            /* PLLCLK = ((pllsrc / pllm) * plln) / pllp */
            pllsource = M4_SYSREG->CMU_PLLCFGR_f.PLLSRC;
            plln = M4_SYSREG->CMU_PLLCFGR_f.MPLLN;
            pllp = M4_SYSREG->CMU_PLLCFGR_f.MPLLP;
            pllm = M4_SYSREG->CMU_PLLCFGR_f.MPLLM;
            /* use exteranl high speed OSC as PLL source */
            if (0ul == pllsource)
            {
                SystemCoreClock = (XTAL_VALUE) / (pllm + 1ul) * (plln + 1ul) / (pllp + 1ul);
            }
            /* use interanl high RC as PLL source */
            else if (1ul == pllsource)
            {
                SystemCoreClock = (HRC_VALUE) / (pllm + 1ul) * (plln + 1ul) / (pllp + 1ul);
            }
            else
            {
                /* Reserved */
            }
            break;
    }
}

void ADC2SeqCmp_IrqHandler(void) {}
void DC1B_IrqHandler(void) {}
void ADC1ChCmp_IrqHandler(void) {}
void ADC1SeqCmp_IrqHandler(void) {}
void ADC2A_IrqHandler(void) {}
void ADC2B_IrqHandler(void) {}
void ADC2ChCmp_IrqHandler(void) {}
void BusFault_IrqHandler(void) {}
void Can_IrqHandler(void) {}
void Dcu1_IrqHandler(void) {}
void Dcu2_IrqHandler(void) {}
void Dcu3_IrqHandler(void) {}
void Dcu4_IrqHandler(void) {}
void DebugMon_IrqHandler(void) {}
void Dma1Btc0_IrqHandler(void) {}
void Dma1Btc1_IrqHandler(void) {}
void Dma1Btc2_IrqHandler(void) {}
void Dma1Btc3_IrqHandler(void) {}
void Dma1Err0_IrqHandler(void) {}
void Dma1Err1_IrqHandler(void) {}
void Dma1Err2_IrqHandler(void) {}
void Dma1Err3_IrqHandler(void) {}
void Dma1Tc1_IrqHandler(void) {}
void Dma1Tc2_IrqHandler(void) {}
void Dma1Tc3_IrqHandler(void) {}
void Dma2Btc0_IrqHandler(void) {}
void Dma2Btc1_IrqHandler(void) {}
void Dma2Btc2_IrqHandler(void) {}
void Dma2Btc3_IrqHandler(void) {}
void Dma2Err0_IrqHandler(void) {}
void Dma2Err1_IrqHandler(void) {}
void Dma2Err2_IrqHandler(void) {}
void Dma2Err3_IrqHandler(void) {}
void Dma2Tc0_IrqHandler(void) {}
void Dma2Tc1_IrqHandler(void) {}
void Dma2Tc2_IrqHandler(void) {}
void Dma2Tc3_IrqHandler(void) {}
void EfmColErr_IrqHandler(void) {}
void EfmOpEnd_IrqHandler(void) {}
void EfmPgmEraseErr_IrqHandler(void) {}
void Emb2_IrqHandler(void) {}
void Emb3_IrqHandler(void) {}
void Emb4_IrqHandler(void) {}
void Extint00_IrqHandler(void) {}
void Extint01_IrqHandler(void) {}
void Extint02_IrqHandler(void) {}
void Extint03_IrqHandler(void) {}
void Extint04_IrqHandler(void) {}
void Extint05_IrqHandler(void) {}
void Extint06_IrqHandler(void) {}
void Extint07_IrqHandler(void) {}
void Extint08_IrqHandler(void) {}
void Extint09_IrqHandler(void) {}
void Extint10_IrqHandler(void) {}
void Extint11_IrqHandler(void) {}
void Extint12_IrqHandler(void) {}
void Extint13_IrqHandler(void) {}
void Extint14_IrqHandler(void) {}
void Extint15_IrqHandler(void) {}
void FcmEnd_IrqHandler(void) {}
void FcmErr_IrqHandler(void) {}
void FcmOV_IrqHandler(void) {}
void HardFault_IrqHandler(void) {}
void I2c1Err_IrqHandler(void) {}
void I2c1TxEmpty_IrqHandler(void) {}
void I2c1TxEnd_IrqHandler(void) {}
void I2c2Err_IrqHandler(void) {}
void I2c2RxEnd_IrqHandler(void) {}
void I2c2TxEmpty_IrqHandler(void) {}
void I2c2TxEnd_IrqHandler(void) {}
void I2c3Err_IrqHandler(void) {}
void I2c3RxEnd_IrqHandler(void) {}
void I2c3TxEmpty_IrqHandler(void) {}
void I2c3TxEnd_IrqHandler(void) {}
void I2s1Err_IrqHandler(void) {}
void I2s1Rx_IrqHandler(void) {}
void I2s1Tx_IrqHandler(void) {}
void I2s2Err_IrqHandler(void) {}
void I2s2Rx_IrqHandler(void) {}
void I2s2Tx_IrqHandler(void) {}
void I2s3Err_IrqHandler(void) {}
void I2s3Rx_IrqHandler(void) {}
void I2s3Tx_IrqHandler(void) {}
void I2s4Err_IrqHandler(void) {}
void I2s4Rx_IrqHandler(void) {}
void I2s4Tx_IrqHandler(void) {}
void Lvd1_IrqHandler(void) {}
void Lvd2_IrqHandler(void) {}
void MainOscStop_IrqHandler(void) {}
void MemManage_IrqHandler(void) {}
void NMI_IrqHandler(void) {}
void PendSV_IrqHandler(void) {}
void QspiInt_IrqHandler(void) {}
void Sdio2_IrqHandler(void) {}
void Spi1Err_IrqHandler(void) {}
void Spi1Idle_IrqHandler(void) {}
void Spi1RxEnd_IrqHandler(void) {}
void Spi1TxEmpty_IrqHandler(void) {}
void Spi2Err_IrqHandler(void) {}
void Spi2Idle_IrqHandler(void) {}
void Spi2RxEnd_IrqHandler(void) {}
void Spi2TxEmpty_IrqHandler(void) {}
void Spi3Err_IrqHandler(void) {}
void Spi3Idle_IrqHandler(void) {}
void Spi3RxEnd_IrqHandler(void) {}
void Spi3TxEmpty_IrqHandler(void) {}
void Spi4Err_IrqHandler(void) {}
void Spi4Idle_IrqHandler(void) {}
void Spi4RxEnd_IrqHandler(void) {}
void Spi4TxEmpty_IrqHandler(void) {}
void SVC_IrqHandler(void) {}
void Swdt_IrqHandler(void) {}
void Timer01GCMB_IrqHandler(void) {}
void Timer02GCMA_IrqHandler(void) {}
void Timer02GCMB_IrqHandler(void) {}
void Timer41GCMUH_IrqHandler(void) {}
void Timer41GCMUL_IrqHandler(void) {}
void Timer41GCMVH_IrqHandler(void) {}
void Timer41GCMVL_IrqHandler(void) {}
void Timer41GCMWH_IrqHandler(void) {}
void Timer41GCMWL_IrqHandler(void) {}
void Timer41GOV_IrqHandler(void) {}
void Timer41GUD_IrqHandler(void) {}
void Timer41ReloadU_IrqHandler(void) {}
void Timer41ReloadV_IrqHandler(void) {}
void Timer41ReloadW_IrqHandler(void) {}
void Timer42GCMVH_IrqHandler(void) {}
void Timer42GCMVL_IrqHandler(void) {}
void Timer42GCMWH_IrqHandler(void) {}
void Timer42GCMWL_IrqHandler(void) {}
void Timer42GOV_IrqHandler(void) {}
void Timer42GUD_IrqHandler(void) {}
void Timer42ReloadU_IrqHandler(void) {}
void Timer42ReloadV_IrqHandler(void) {}
void Timer42ReloadW_IrqHandler(void) {}
void Timer43GCMUL_IrqHandler(void) {}
void Timer43GCMVH_IrqHandler(void) {}
void Timer43GCMVL_IrqHandler(void) {}
void Timer43GCMWH_IrqHandler(void) {}
void Timer43GCMWL_IrqHandler(void) {}
void Timer43GOV_IrqHandler(void) {}
void Timer43GUD_IrqHandler(void) {}
void Timer43ReloadV_IrqHandler(void) {}
void Timer43ReloadW_IrqHandler(void) {}
void Timer61GCMB_IrqHandler(void) {}
void Timer61GCMC_IrqHandler(void) {}
void Timer61GCMD_IrqHandler(void) {}
void Timer61GCME_IrqHandler(void) {}
void Timer61GCMF_IrqHandler(void) {}
void Timer61GDT_IrqHandler(void) {}
void Timer61GOV_IrqHandler(void) {}
void Timer61GUD_IrqHandler(void) {}
void Timer61SCMA_IrqHandler(void) {}
void Timer61SCMB_IrqHandler(void) {}
void Timer62GCMA_IrqHandler(void) {}
void Timer62GCMB_IrqHandler(void) {}
void Timer62GCMC_IrqHandler(void) {}
void Timer62GCMD_IrqHandler(void) {}
void Timer62GCME_IrqHandler(void) {}
void Timer62GCMF_IrqHandler(void) {}
void Timer62GDT_IrqHandler(void) {}
void Timer62GOV_IrqHandler(void) {}
void Timer62GUD_IrqHandler(void) {}
void Timer62SCMA_IrqHandler(void) {}
void Timer62SCMB_IrqHandler(void) {}
void Timer63GCMB_IrqHandler(void) {}
void Timer63GCMC_IrqHandler(void) {}
void Timer63GCMD_IrqHandler(void) {}
void Timer63GCME_IrqHandler(void) {}
void Timer63GCMF_IrqHandler(void) {}
void Timer63GDT_IrqHandler(void) {}
void Timer63GOV_IrqHandler(void) {}
void Timer63GUD_IrqHandler(void) {}
void Timer63SCMA_IrqHandler(void) {}
void Timer63SCMB_IrqHandler(void) {}
void TimerA1CMP_IrqHandler(void) {}
void TimerA1UD_IrqHandler(void) {}
void TimerA2CMP_IrqHandler(void) {}
void TimerA2OV_IrqHandler(void) {}
void TimerA2UD_IrqHandler(void) {}
void TimerA3CMP_IrqHandler(void) {}
void TimerA3OV_IrqHandler(void) {}
void TimerA3UD_IrqHandler(void) {}
void TimerA4CMP_IrqHandler(void) {}
void TimerA4OV_IrqHandler(void) {}
void TimerA4UD_IrqHandler(void) {}
void TimerA5CMP_IrqHandler(void) {}
void TimerA5OV_IrqHandler(void) {}
void TimerA5UD_IrqHandler(void) {}
void TimerA6CMP_IrqHandler(void) {}
void TimerA6OV_IrqHandler(void) {}
void TimerA6UD_IrqHandler(void) {}
void UsageFault_IrqHandler(void) {}
void Usart1RxEnd_IrqHandler(void) {}
void Usart1RxErr_IrqHandler(void) {}
void Usart1RxTO_IrqHandler(void) {}
void Usart1TxEmpty_IrqHandler(void) {}
void Usart1TxEnd_IrqHandler(void) {}
void Usart2RxEnd_IrqHandler(void) {}
void Usart2RxErr_IrqHandler(void) {}
void Usart2RxTO_IrqHandler(void) {}
void Usart2TxEmpty_IrqHandler(void) {}
void Usart2TxEnd_IrqHandler(void) {}
void Usart3RxEnd_IrqHandler(void) {}
void Usart3RxTO_IrqHandler(void) {}
void Usart3TxEmpty_IrqHandler(void) {}
void Usart3TxEnd_IrqHandler(void) {}
void Usart4RxEnd_IrqHandler(void) {}
void Usart4RxErr_IrqHandler(void) {}
void Usart4RxTO_IrqHandler(void) {}
void Usart4TxEmpty_IrqHandler(void) {}
void Usart4TxEnd_IrqHandler(void) {}
void UsbGlobal_IrqHandler(void) {}
void WakeupTimer_IrqHandler(void) {}
void WdtIrqHandler(void) {}
void Dma1Tc0_IrqHandl(void) {}
void Timer01GCMA_IrqHandler(void) {}
void TimerA1OV_IrqHandler(void) {}
void Usart3RxErr_IrqHandler(void) {}
void Dma1Tc0_IrqHandler(void) {}
void Timer61GCMA_IrqHandler(void) {}
void Emb1_IrqHandler(void) {}
void I2c1RxEnd_IrqHandler(void) {}
void Timer63GCMA_IrqHandler(void) {}
void Timer43GCMUH_IrqHandler(void) {}
void Wdt_IrqHandler(void) {}
void ADC1A_IrqHandler(void) {}
void ADC1B_IrqHandler(void) {}
void Sdio1_IrqHandler(void) {}

//@} // UsartGroup

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
