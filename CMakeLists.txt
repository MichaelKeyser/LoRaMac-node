#edit this to be updated

idf_component_register(SRCS "src/radio/sx1276.c" "src/mac/LoRaMac.c" "src/mac/LoRaMacParser.c" "src/mac/LoRaMacCrypto.c" 
                        "src/mac/LoRaMacCommands.c" "src/mac/LoRaMacSerializer.c" "src/mac/region/RegionBaseUS.c" 
                        "src/mac/region/Region.c" "src/mac/region/RegionCommon.c" "src/mac/region/RegionUS915.c" 
                        "src/mac/LoRaMacAdr.c" "src/mac/LoRaMacClassB.c" "src/mac/LoRaMacConfirmQueue.c" "src/system/systime.c" 
                        "src/system/timer.c" "src/system/nvmm.c" "src/system/gpio.c" "src/system/delay.c" "src/system/i2c.c" 
                        "src/system/fifo.c" "src/system/adc.c" "src/system/gps.c" "src/system/uart.c" "src/system/spi.c" "src/boards/utilities.c" 
                        "src/boards/ESP32/delay-board.c" "src/boards/ESP32/gpio-board.c" "src/boards/ESP32/board.c" "src/boards/ESP32/RFM95W-board.c"
                        "src/boards/ESP32/rtc-board.c" "src/boards/ESP32/uart-board.c" "src/boards/ESP32/eeprom-board.c"
                        "src/lorawan/CayenneLpp.c" "src/lorawan/cli.c" "src/lorawan/LmHandlerMsgDisplay.c" "src/lorawan/NvmDataMgmt.c"
                        "src/lorawan/LmHandler/LmHandler.c"
                        "src/lorawan/LmHandler/packages/FragDecoder.c" "src/lorawan/LmHandler/packages/LmhpClockSync.c" "src/lorawan/LmHandler/packages/LmhpCompliance.c" 
                        "src/lorawan/LmHandler/packages/LmhpFragmentation.c" "src/lorawan/LmHandler/packages/LmhpRemoteMcastSetup.c"
                    INCLUDE_DIRS "src/boards" "src/boards/ESP32" "src/mac" "src/radio" "src/system" "src/mac/region" "src/lorawan" "src/lorawan/LmHandler" 
                        "src/peripherals/secure-element-name-se" "src/lorawan/LmHandler/packages")

                    #"src/boards/ESP32/spi-board.c"