PROJECT=kobra
INCS = \
        -I../CMSIS_5/CMSIS/Core/Include \
	-I../source/compoment/adc \
	-I../source/compoment/i2c \
	-I../source/compoment/sdio \
	-I../source/compoment/sdio/sd_card/inc \
	-I../source/compoment/spi \
	-I../source/compoment/uart \
	-I../source/compoment/Utility \
	-I../source/drivers/board \
	-I../source/drivers/library \
	-I../source/drivers/library/inc \
	-I../source/framework/cores \
	-I../source/framework/usb \
	-I../source/framework/variants \
	-I../source/main \
	-I../source/main/hdsc32core \
	-I../source/Marlin \
	-I../source/Marlin/src \
	-I../source/Marlin/src/pins \
	-I../source/Marlin/src/core \
	-I../source/Marlin/src/feature \
	-I../source/Marlin/src/feature/bedlevel \
	-I../source/Marlin/src/feature/bedlevel/abl \
	-I../source/Marlin/src/feature/bedlevel/mbl \
	-I../source/Marlin/src/feature/bedlevel/ubl \
	-I../source/Marlin/src/feature/digipot \
	-I../source/Marlin/src/feature/leds \
	-I../source/Marlin/src/feature/mmu \
	-I../source/Marlin/src/feature/password \
	-I../source/Marlin/src/gcode \
	-I../source/Marlin/src/HAL \
	-I../source/Marlin/src/HAL/shared \
	-I../source/Marlin/src/HAL/shared/backtrace \
	-I../source/Marlin/src/HAL/STM32 \
	-I../source/Marlin/src/HAL/STM32/tft \
	-I../source/Marlin/src/HAL/STM32/inc \
	-I../source/Marlin/src/inc \
	-I../source/Marlin/src/lcd \
	-I../source/Marlin/src/lcd/dogm \
	-I../source/Marlin/src/lcd/dogm/fontdata \
	-I../source/Marlin/src/lcd/dwin \
	-I../source/Marlin/src/lcd/language \
	-I../source/Marlin/src/lcd/menu \
	-I../source/Marlin/src/lcd/menu/game \
	-I../source/Marlin/src/libs \
	-I../source/Marlin/src/module \
	-I../source/Marlin/src/module/stepper \
	-I../source/Marlin/src/module/thermistor \
	-I../source/Marlin/src/pins \
	-I../source/Marlin/src/pins/stm32f1 \
	-I../source/Marlin/src/sd \
	-I../source/Marlin/src/sd/usb_flashdrive \
	-I../source/Marlin/src/sd/usb_flashdrive/lib-uhs2 \
	-I../source/Marlin/src/lcd/extui \
	-I../source/Marlin/src/lcd/extui/lib/anycubic \
	-I../source/Marlin/src/lcd/extui/lib/dgus \
	-I../source/Marlin/src/lcd/extui/lib/dgus/fysetc \
	-I../source/Marlin/src/lcd/extui/lib/dgus/hiprecy \
	-I../source/Marlin/src/lcd/extui/lib/dgus/origin \
	-I../source/Marlin/src/lcd/extui/lib/ftdi_eve_touch_ui \
	-I../source/Marlin/src/lcd/extui/lib/ftdi_eve_touch_ui/archim2-flash \
	-I../source/Marlin/src/lcd/extui/lib/ftdi_eve_touch_ui/ftdi_eve_lib \
	-I../source/Marlin/src/lcd/extui/lib/ftdi_eve_touch_ui/ftdi_eve_lib/basic \
	-I../source/Marlin/src/lcd/extui/lib/ftdi_eve_touch_ui/ftdi_eve_lib/extended \
	-I../source/Marlin/src/lcd/extui/lib/ftdi_eve_touch_ui/ftdi_eve_lib/extended/unicode \
	-I../source/Marlin/src/lcd/extui/lib/ftdi_eve_touch_ui/ftdi_eve_lib/extras \
	-I../source/Marlin/src/lcd/extui/lib/ftdi_eve_touch_ui/language \
	-I../source/Marlin/src/lcd/extui/lib/ftdi_eve_touch_ui/screens \
	-I../source/Marlin/src/lcd/extui/lib/ftdi_eve_touch_ui/theme \
	-I../source/Marlin/src/lcd/extui//lib/mks_ui \
	-I../source/Marlin/src/lcd/HD44780 \
	-I../source/Marlin/src/sd/usb_flashdrive/lib-uhs3/dyn_SWI \
	-I../source/Marlin/src/sd/usb_flashdrive/lib-uhs3/UHS_host \
	-I../source/Marlin/src/sd/usb_flashdrive/lib-uhs3/UHS_host/UHS_BULK_STORAGE \
	-I../source/Marlin/src/sd/usb_flashdrive/lib-uhs3/UHS_host/USB_HOST_SHIELD \
	-I../source/Marlin/src/libs/heatshrink \
	-I../source/Marlin/src/libs/L64XX \
	-I../source/Marlin/src/lcd/dogm/status \
	-I../source/Marlin/src/lcd/dwin/e3v2 \
 	-I../source/Marlin/src/lcd/extui/lib/anycubic_chiron \
	-I../source/Marlin/src/lcd/extui/lib/anycubic_dgus \
	-I../source/Marlin/src/lcd/extui/lib/anycubic_i3mega \
	-I../source/Marlin/src/lcd/tft \
	-I../source/Marlin/src/lcd/tft_io \
	-I../source/Marlin/src/lcd/TFTGLCD \
	-I../source/Marlin/src/lcd/touch \
	-I../source/Marlin/src/module/stepper/source \
	-I../source/framework/TMCStepper \
	-I../source/framework/TMCStepper/source \
	-I../source/arduino \
	-I../source/board \
	-I../source/FatFs \
	-I../source/framework/SoftwareSerial 
DEFINES= -D__LONGLONG="long long" \
	-DHC32F46x \
	-DUSE_DEVICE_DRIVER_LIB \
	-D__TARGET_FPU_VFP \
	-D__FPU_PRESENT=1 \
	-DARM_MATH_CM4 \
	-DARM_MATH_ROUNDING \
	-D__MPU_PRESENT=1 \
	-DSTM32_HIGH_DENSITY \
	-DARDUINO_ARCH_STM32F1 \
	-D__CC_ARM \
	-D ARM_MATH_MATRIX_CHECK \
	-DARDUINO_ARCH_STM32 \
	-DRAMSTART=0x1fff8000 \
	-DRAMEND=0x1fffffff

CSOURCES=	\
	../source/drivers/library/src/hc32f46x_adc.c \
	../source/drivers/library/src/hc32f46x_aes.c \
	../source/drivers/library/src/hc32f46x_can.c \
	../source/drivers/library/src/hc32f46x_clk.c \
	../source/drivers/library/src/hc32f46x_cmp.c \
	../source/drivers/library/src/hc32f46x_crc.c \
	../source/drivers/library/src/hc32f46x_dcu.c \
	../source/drivers/library/src/hc32f46x_dmac.c \
	../source/drivers/library/src/hc32f46x_efm.c \
	../source/drivers/library/src/hc32f46x_emb.c \
	../source/drivers/library/src/hc32f46x_event_port.c \
	../source/drivers/library/src/hc32f46x_exint_nmi_swi.c \
	../source/drivers/library/src/hc32f46x_gpio.c \
	../source/drivers/library/src/hc32f46x_hash.c \
	../source/drivers/library/src/hc32f46x_i2c.c \
	../source/drivers/library/src/hc32f46x_i2s.c \
	../source/drivers/library/src/hc32f46x_icg.c \
	../source/drivers/library/src/hc32f46x_interrupts.c \
	../source/drivers/library/src/hc32f46x_keyscan.c \
	../source/drivers/library/src/hc32f46x_mpu.c \
	../source/drivers/library/src/hc32f46x_ots.c \
	../source/drivers/library/src/hc32f46x_pwc.c \
	../source/drivers/library/src/hc32f46x_qspi.c \
	../source/drivers/library/src/hc32f46x_rmu.c \
	../source/drivers/library/src/hc32f46x_rtc.c \
	../source/drivers/library/src/hc32f46x_sdioc.c \
	../source/drivers/library/src/hc32f46x_spi.c \
	../source/drivers/library/src/hc32f46x_sram.c \
	../source/drivers/library/src/hc32f46x_swdt.c \
	../source/drivers/library/src/hc32f46x_timer0.c \
	../source/drivers/library/src/hc32f46x_timer4_cnt.c \
	../source/drivers/library/src/hc32f46x_timer4_emb.c \
	../source/drivers/library/src/hc32f46x_timer4_oco.c \
	../source/drivers/library/src/hc32f46x_timer4_pwm.c \
	../source/drivers/library/src/hc32f46x_timer4_sevt.c \
	../source/drivers/library/src/hc32f46x_timer6.c \
	../source/drivers/library/src/hc32f46x_timera.c \
	../source/drivers/library/src/hc32f46x_trng.c \
	../source/drivers/library/src/hc32f46x_usart.c \
	../source/drivers/library/src/hc32f46x_wdt.c \
	../source/drivers/library/src/hc32f46x_utility.c \
	../source/main/hdsc32core/system_hc32f46x.c \
	../source/FatFs/diskio.c \
	../source/FatFs/ff.c \
	../source/FatFs/ffsystem.c \
	../source/FatFs/ffunicode.c \
	../source/compoment/sdio/sd_card/src/sd_card.c \
	../source/compoment/sdio/sd_card/src/sdmmc_cmd.c


CPPSOURCES=	\
	../source/app/app_fatfs_test.cpp \
	../source/app/app_sserial_test.cpp \
	../source/app/app_uart.cpp \
	../source/app/main.cpp \
	../source/arduino/HardwareSerial.cpp \
	../source/arduino/Print.cpp \
	../source/arduino/Stream.cpp \
	../source/arduino/WString.cpp \
	../source/board/bsp_adc.cpp \
	../source/board/bsp_flash.cpp \
	../source/board/bsp_init.cpp \
	../source/board/bsp_irq.cpp \
	../source/board/bsp_ots.cpp \
	../source/board/bsp_pwm.cpp \
	../source/board/bsp_rmu.cpp \
	../source/board/bsp_sdio.cpp \
	../source/board/bsp_timer.cpp \
	../source/board/bsp_wdt.cpp \
	../source/drivers/board/board_adc.cpp \
	../source/drivers/board/board_sdio.cpp \
	../source/drivers/board/board_tim0.cpp \
	../source/drivers/board/startup.cpp \
	../source/framework/cores/Arduino.cpp \
	../source/framework/cores/flash.cpp \
	../source/framework/cores/io.cpp \
	../source/framework/cores/iwdg.cpp \
	../source/framework/cores/Tone.cpp \
	../source/framework/SoftwareSerial/SoftwareSerial.cpp \
	../source/framework/TMCStepper/source/CHOPCONF.cpp \
	../source/framework/TMCStepper/source/COOLCONF.cpp \
	../source/framework/TMCStepper/source/DRV_CONF.cpp \
	../source/framework/TMCStepper/source/DRVCONF.cpp \
	../source/framework/TMCStepper/source/DRVCTRL.cpp \
	../source/framework/TMCStepper/source/DRV_STATUS.cpp \
	../source/framework/TMCStepper/source/DRVSTATUS.cpp \
	../source/framework/TMCStepper/source/ENCMODE.cpp \
	../source/framework/TMCStepper/source/GCONF.cpp \
	../source/framework/TMCStepper/source/IHOLD_IRUN.cpp \
	../source/framework/TMCStepper/source/PWMCONF.cpp \
	../source/framework/TMCStepper/source/RAMP_STAT.cpp \
	../source/framework/TMCStepper/source/SERIAL_SWITCH.cpp \
	../source/framework/TMCStepper/source/SGCSCONF.cpp \
	../source/framework/TMCStepper/source/SHORT_CONF.cpp \
	../source/framework/TMCStepper/source/SMARTEN.cpp \
	../source/framework/TMCStepper/source/SW_MODE.cpp \
	../source/framework/TMCStepper/source/TMC2208Stepper.cpp \
	../source/framework/TMCStepper/source/TMC2209Stepper.cpp \
	../source/framework/TMCStepper/source/TMCStepper.cpp \
	../source/Marlin/src/core/serial.cpp \
	../source/Marlin/src/core/utility.cpp \
	../source/Marlin/src/feature/babystep.cpp \
	../source/Marlin/src/feature/bedlevel/abl/abl.cpp \
	../source/Marlin/src/feature/bedlevel/bedlevel.cpp \
	../source/Marlin/src/feature/controllerfan.cpp \
	../source/Marlin/src/feature/e_parser.cpp \
	../source/Marlin/src/feature/fwretract.cpp \
	../source/Marlin/src/feature/pause.cpp \
	../source/Marlin/src/feature/powerloss.cpp \
	../source/Marlin/src/feature/power_monitor.cpp \
	../source/Marlin/src/feature/repeat.cpp \
	../source/Marlin/src/feature/runout.cpp \
	../source/Marlin/src/feature/tmc_util.cpp \
	../source/Marlin/src/feature/z_stepper_align.cpp \
	../source/Marlin/src/gcode/bedlevel/abl/G29.cpp \
	../source/Marlin/src/gcode/bedlevel/abl/M421.cpp \
	../source/Marlin/src/gcode/bedlevel/G26.cpp \
	../source/Marlin/src/gcode/bedlevel/G35.cpp \
	../source/Marlin/src/gcode/bedlevel/G42.cpp \
	../source/Marlin/src/gcode/bedlevel/M420.cpp \
	../source/Marlin/src/gcode/calibrate/G28.cpp \
	../source/Marlin/src/gcode/calibrate/G33.cpp \
	../source/Marlin/src/gcode/calibrate/G34.cpp \
	../source/Marlin/src/gcode/calibrate/G34_M422.cpp \
	../source/Marlin/src/gcode/calibrate/G425.cpp \
	../source/Marlin/src/gcode/calibrate/G76_M192_M871.cpp \
	../source/Marlin/src/gcode/calibrate/M100.cpp \
	../source/Marlin/src/gcode/calibrate/M12.cpp \
	../source/Marlin/src/gcode/calibrate/M425.cpp \
	../source/Marlin/src/gcode/calibrate/M48.cpp \
	../source/Marlin/src/gcode/calibrate/M665.cpp \
	../source/Marlin/src/gcode/calibrate/M666.cpp \
	../source/Marlin/src/gcode/calibrate/M852.cpp \
	../source/Marlin/src/gcode/caselight/M355.cpp \
	../source/Marlin/src/gcode/config/M200-M205.cpp \
	../source/Marlin/src/gcode/config/M217.cpp \
	../source/Marlin/src/gcode/config/M218.cpp \
	../source/Marlin/src/gcode/config/M220.cpp \
	../source/Marlin/src/gcode/config/M221.cpp \
	../source/Marlin/src/gcode/config/M281.cpp \
	../source/Marlin/src/gcode/config/M301.cpp \
	../source/Marlin/src/gcode/config/M302.cpp \
	../source/Marlin/src/gcode/config/M304.cpp \
	../source/Marlin/src/gcode/config/M305.cpp \
	../source/Marlin/src/gcode/config/M43.cpp \
	../source/Marlin/src/gcode/config/M540.cpp \
	../source/Marlin/src/gcode/config/M575.cpp \
	../source/Marlin/src/gcode/config/M672.cpp \
	../source/Marlin/src/gcode/config/M92.cpp \
	../source/Marlin/src/gcode/control/M108_M112_M410.cpp \
	../source/Marlin/src/gcode/control/M111.cpp \
	../source/Marlin/src/gcode/control/M120_M121.cpp \
	../source/Marlin/src/gcode/control/M17_M18_M84.cpp \
	../source/Marlin/src/gcode/control/M211.cpp \
	../source/Marlin/src/gcode/control/M226.cpp \
	../source/Marlin/src/gcode/control/M280.cpp \
	../source/Marlin/src/gcode/control/M350_M351.cpp \
	../source/Marlin/src/gcode/control/M380_M381.cpp \
	../source/Marlin/src/gcode/control/M3-M5.cpp \
	../source/Marlin/src/gcode/control/M400.cpp \
	../source/Marlin/src/gcode/control/M42.cpp \
	../source/Marlin/src/gcode/control/M605.cpp \
	../source/Marlin/src/gcode/control/M7-M9.cpp \
	../source/Marlin/src/gcode/control/M80_M81.cpp \
	../source/Marlin/src/gcode/control/M85.cpp \
	../source/Marlin/src/gcode/control/M993_M994.cpp \
	../source/Marlin/src/gcode/control/M997.cpp \
	../source/Marlin/src/gcode/control/M999.cpp \
	../source/Marlin/src/gcode/control/T.cpp \
	../source/Marlin/src/gcode/eeprom/M500-M504.cpp \
	../source/Marlin/src/gcode/feature/advance/M900.cpp \
	../source/Marlin/src/gcode/feature/controllerfan/M710.cpp \
	../source/Marlin/src/gcode/feature/digipot/M907-M910.cpp \
	../source/Marlin/src/gcode/feature/network/M552-M554.cpp \
	../source/Marlin/src/gcode/feature/pause/G27.cpp \
	../source/Marlin/src/gcode/feature/pause/G60.cpp \
	../source/Marlin/src/gcode/feature/pause/G61.cpp \
	../source/Marlin/src/gcode/feature/pause/M125.cpp \
	../source/Marlin/src/gcode/feature/pause/M600.cpp \
	../source/Marlin/src/gcode/feature/pause/M603.cpp \
	../source/Marlin/src/gcode/feature/pause/M701_M702.cpp \
	../source/Marlin/src/gcode/feature/powerloss/M1000.cpp \
	../source/Marlin/src/gcode/feature/powerloss/M413.cpp \
	../source/Marlin/src/gcode/feature/power_monitor/M430.cpp \
	../source/Marlin/src/gcode/feature/runout/M412.cpp \
	../source/Marlin/src/gcode/feature/trinamic/M122.cpp \
	../source/Marlin/src/gcode/feature/trinamic/M569.cpp \
	../source/Marlin/src/gcode/feature/trinamic/M906.cpp \
	../source/Marlin/src/gcode/feature/trinamic/M911-M914.cpp \
	../source/Marlin/src/gcode/gcode.cpp \
	../source/Marlin/src/gcode/gcode_d.cpp \
	../source/Marlin/src/gcode/geometry/G17-G19.cpp \
	../source/Marlin/src/gcode/geometry/G53-G59.cpp \
	../source/Marlin/src/gcode/geometry/G92.cpp \
	../source/Marlin/src/gcode/geometry/M206_M428.cpp \
	../source/Marlin/src/gcode/host/M110.cpp \
	../source/Marlin/src/gcode/host/M113.cpp \
	../source/Marlin/src/gcode/host/M114.cpp \
	../source/Marlin/src/gcode/host/M115.cpp \
	../source/Marlin/src/gcode/host/M118.cpp \
	../source/Marlin/src/gcode/host/M119.cpp \
	../source/Marlin/src/gcode/host/M16.cpp \
	../source/Marlin/src/gcode/host/M360.cpp \
	../source/Marlin/src/gcode/host/M876.cpp \
	../source/Marlin/src/gcode/lcd/M0_M1.cpp \
	../source/Marlin/src/gcode/lcd/M117.cpp \
	../source/Marlin/src/gcode/lcd/M145.cpp \
	../source/Marlin/src/gcode/lcd/M250.cpp \
	../source/Marlin/src/gcode/lcd/M300.cpp \
	../source/Marlin/src/gcode/lcd/M73.cpp \
	../source/Marlin/src/gcode/lcd/M995.cpp \
	../source/Marlin/src/gcode/motion/G0_G1.cpp \
	../source/Marlin/src/gcode/motion/G2_G3.cpp \
	../source/Marlin/src/gcode/motion/G4.cpp \
	../source/Marlin/src/gcode/motion/G5.cpp \
	../source/Marlin/src/gcode/motion/G6.cpp \
	../source/Marlin/src/gcode/motion/G80.cpp \
	../source/Marlin/src/gcode/motion/M290.cpp \
	../source/Marlin/src/gcode/parser.cpp \
	../source/Marlin/src/gcode/probe/G30.cpp \
	../source/Marlin/src/gcode/probe/G31_G32.cpp \
	../source/Marlin/src/gcode/probe/G38.cpp \
	../source/Marlin/src/gcode/probe/M401_M402.cpp \
	../source/Marlin/src/gcode/probe/M851.cpp \
	../source/Marlin/src/gcode/probe/M951.cpp \
	../source/Marlin/src/gcode/queue.cpp \
	../source/Marlin/src/gcode/scara/M360-M364.cpp \
	../source/Marlin/src/gcode/sd/M1001.cpp \
	../source/Marlin/src/gcode/sd/M20.cpp \
	../source/Marlin/src/gcode/sd/M21_M22.cpp \
	../source/Marlin/src/gcode/sd/M23.cpp \
	../source/Marlin/src/gcode/sd/M24_M25.cpp \
	../source/Marlin/src/gcode/sd/M26.cpp \
	../source/Marlin/src/gcode/sd/M27.cpp \
	../source/Marlin/src/gcode/sd/M28_M29.cpp \
	../source/Marlin/src/gcode/sd/M30.cpp \
	../source/Marlin/src/gcode/sd/M32.cpp \
	../source/Marlin/src/gcode/sd/M33.cpp \
	../source/Marlin/src/gcode/sd/M34.cpp \
	../source/Marlin/src/gcode/sd/M524.cpp \
	../source/Marlin/src/gcode/sd/M808.cpp \
	../source/Marlin/src/gcode/sd/M928.cpp \
	../source/Marlin/src/gcode/stats/M31.cpp \
	../source/Marlin/src/gcode/stats/M75-M78.cpp \
	../source/Marlin/src/gcode/temp/M104_M109.cpp \
	../source/Marlin/src/gcode/temp/M105.cpp \
	../source/Marlin/src/gcode/temp/M106_M107.cpp \
	../source/Marlin/src/gcode/temp/M140_M190.cpp \
	../source/Marlin/src/gcode/temp/M141_M191.cpp \
	../source/Marlin/src/gcode/temp/M155.cpp \
	../source/Marlin/src/gcode/temp/M303.cpp \
	../source/Marlin/src/gcode/units/G20_G21.cpp \
	../source/Marlin/src/gcode/units/M149.cpp \
	../source/Marlin/src/gcode/units/M82_M83.cpp \
	../source/Marlin/src/HAL/shared/eeprom_api.cpp \
	../source/Marlin/src/HAL/shared/esp_wifi.cpp \
	../source/Marlin/src/HAL/shared/HAL_spi_L6470.cpp \
	../source/Marlin/src/HAL/shared/servo.cpp \
	../source/Marlin/src/HAL/STM32/eeprom_flash.cpp \
	../source/Marlin/src/HAL/STM32/eeprom_sdcard.cpp \
	../source/Marlin/src/HAL/STM32/fastio.cpp \
	../source/Marlin/src/HAL/STM32/HAL.cpp \
	../source/Marlin/src/HAL/STM32/sdio.cpp \
	../source/Marlin/src/HAL/STM32/timers.cpp \
	../source/Marlin/src/HAL/STM32/watchdog.cpp \
	../source/Marlin/src/lcd/extui/anycubic_chiron_lcd.cpp \
	../source/Marlin/src/lcd/extui/anycubic_dgus_lcd.cpp \
	../source/Marlin/src/lcd/extui/lib/anycubic_chiron/chiron_tft.cpp \
	../source/Marlin/src/lcd/extui/lib/anycubic_chiron/FileNavigator.cpp \
	../source/Marlin/src/lcd/extui/lib/anycubic_chiron/Tunes.cpp \
	../source/Marlin/src/lcd/extui/lib/anycubic_dgus/dgus_FileNavigator.cpp \
	../source/Marlin/src/lcd/extui/lib/anycubic_dgus/dgus_tft.cpp \
	../source/Marlin/src/lcd/extui/lib/anycubic_dgus/dgus_Tunes.cpp \
	../source/Marlin/src/lcd/extui/ui_api.cpp \
	../source/Marlin/src/lcd/fontutils.cpp \
	../source/Marlin/src/lcd/marlinui.cpp \
	../source/Marlin/src/libs/buzzer.cpp \
	../source/Marlin/src/libs/crc16.cpp \
	../source/Marlin/src/libs/dtostrf.cpp \
	../source/Marlin/src/libs/hex_print.cpp \
	../source/Marlin/src/libs/nozzle.cpp \
	../source/Marlin/src/libs/numtostr.cpp \
	../source/Marlin/src/libs/stopwatch.cpp \
	../source/Marlin/src/libs/vector_3.cpp \
	../source/Marlin/src/MarlinCore.cpp \
	../source/Marlin/src/module/endstops.cpp \
	../source/Marlin/src/module/motion.cpp \
	../source/Marlin/src/module/planner.cpp \
	../source/Marlin/src/module/printcounter.cpp \
	../source/Marlin/src/module/probe.cpp \
	../source/Marlin/src/module/settings.cpp \
	../source/Marlin/src/module/stepper.cpp \
	../source/Marlin/src/module/stepper/indirection.cpp \
	../source/Marlin/src/module/stepper/trinamic.cpp \
	../source/Marlin/src/module/temperature.cpp \
	../source/Marlin/src/module/tool_change.cpp \
	../source/Marlin/src/sd/cardreader.cpp \
	../source/Marlin/src/sd/Sd2Card.cpp \
	../source/Marlin/src/sd/SdBaseFile.cpp \
	../source/Marlin/src/sd/SdFatUtil.cpp \
	../source/Marlin/src/sd/SdFile.cpp \
	../source/Marlin/src/sd/SdVolume.cpp \
	../source/drivers/board/board_gpio.cpp \
	../source/Marlin/src/sd/usb_flashdrive/Sd2Card_FlashDrive.cpp


#	../source/Marlin/src/module/servo.cpp \

MCU=cortex-m7
CFLAGS=-mcpu=$(MCU) -mtune=cortex-m7 -mthumb -Og -fomit-frame-pointer -falign-functions=16 -ffunction-sections -fdata-sections -fno-common -flto -mfloat-abi=hard -mfpu=fpv5-d16  -Wall -Wextra -Wundef

CPPFLAGS=-mcpu=$(MCU) -mtune=cortex-m7 -mthumb -Og -fomit-frame-pointer -falign-functions=16 -ffunction-sections -fdata-sections -fno-common -flto -mfloat-abi=hard -mfpu=fpv5-d16  -Wall -Wextra -Wundef

LLIBDIR=
RULESPATH=
LDSCRIPT=../hc32f46x.ld
LDOPT=
LDFLAGS=-mcpu=$(MCU) -mthumb -Og -ggdb -fomit-frame-pointer -falign-functions=16 -flto=auto -ffunction-sections -fdata-sections -fno-common -flto -mfloat-abi=hard -mfpu=fpv5-d16 -nostartfiles -Wl,-Map=$(OBJDIR)/$(PROJECT).map,--cref,--no-warn-mismatch,--library-path=/home/gsohler/git/,--script=$(LDSCRIPT),--gc-sections,--defsym=__process_stack_size__=0x400,--defsym=__main_stack_size__=0x400

LIBS=

OBJDIR=./obj

ALLSOURCES      := $(CSOURCES) $(CPPSOURCES)
VPATH  := $(sort  $(dir $(ALLSOURCES)))

COBJECTS    := $(addprefix $(OBJDIR)/, $(notdir $(CSOURCES:.c=.o)))
CPPOBJECTS  := $(addprefix $(OBJDIR)/, $(notdir $(CPPSOURCES:.cpp=.o)))

OBJECTS = $(COBJECTS) $(CPPOBJECTS)

CC=arm-none-eabi-gcc
LD=arm-none-eabi-gcc
CPPC=arm-none-eabi-g++

all:	${OBJDIR}/$(PROJECT).elf

$(COBJECTS) : $(OBJDIR)/%.o : %.c
ifeq ($(verbose),1)
	@echo
	$(CC) -c $(CFLAGS) $(INCS) $(DEFINES) $< -o $@
else
	@echo Compiling $(<F)
	@$(CC) -c $(CFLAGS) $(INCS) $(DEFINES) $< -o $@
endif

$(CPPOBJECTS) : $(OBJDIR)/%.o : %.cpp
ifeq ($(verbose),1)
	@echo
	$(CPPC) -c $(CPPFLAGS) $(INCS) $(DEFINES) $< -o $@
else
	@echo Compiling $(<F)
	@$(CPPC) -c $(CPPFLAGS) $(INCS) $(DEFINES) $< -o $@
endif

$(OBJDIR)/$(PROJECT).elf:$(OBJECTS) $(LDSCRIPT)
	$(LD) $(OBJECTS) $(LDFLAGS) -o $(OBJDIR)/$(PROJECT).elf

clean:
	rm -rf obj/*

test:
	echo $(CPPOBJECTS)

