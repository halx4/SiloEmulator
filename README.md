__Master Branch is not used in this repo. Actual code is in the other branches.__

## Silo Emulator Overview

Silo emulator is an arduino-based system implementing the full (incl. mixer and heater) silo interface as described in the [liqueur plant case study].

It is designed to interface directly with raspberry pi (and any 3.3V logic controller) with digital i/o ’s and a serial connection. A thermometer (Maxim DS18B20) is integrated so the user can change the actual measured temperature by heating it but there is also the option to emulate the temperature’s changes depending on heater’s and valves’ state. One more capability implemented is the option of sending the temperature over the serial line or exposing the thermometer’s data pin as output so the silo's controller can communicate directly with the thermometer. Silo’s state is exposed by the corresponding outputs (digital pins and serial line) along with visual (leds and 8-segment display) and audible (buzzer) indications for easier debugging and demonstration.

## Silo Emulator Specifications

### Indications
  - Temperature : 8 seg-display, 2 digits
  - Led bargraph
  - InValve led
  - OutValve led
  - Full led
  - Empty led
  - Heater led
  - Mixer led
  - Mixer buzzer

### Embedded Sensors
  - DS18B20 Thermometer

### I/O pins
(Logic 1=3.3V , Logic 0 = 0V)

1. FULL (OUT)
2. EMPTY (OUT)
3. +5V (IN/OUT)
4. DS18B20 DQ 
5. GND
6. +3.3V
7. <span class='overlined'>HEATER</span>  (IN) (ACTIVE LOW)
8. <span class='overlined'>INVALVE</span> (IN) (ACTIVE LOW)
9. TX
10. <span class='overlined'>OUTVALVE</span> (IN) (ACTIVE LOW)
11. RX
12. <span class='overlined'>MIXER</span> (IN) (ACTIVE LOW)

### Thermometer Interfacing Modes

- TIM1 (Thermometer Interfacing Mode 1)
Thermometer operates via the serial connection
- TIM2 (Thermometer Interfacing Mode 2)
DS18B20's data pin can be accessed directly from pin4 of the circuit. (3.3v logic)

Mode delection:

| Mode\ solder jumper |           SJ1          | SJ2     |
|:-------------------:|:----------------------:|:-------:|
|     **TIM1**        |  Bridge Middle with 5V | Bridged |
|     **TIM2**        | Bridge Middle with 3V3 | Open    |


### Source code
There are two flavors of the firmware, with slightly different functionality between them:
 - THERMOMETER SIMULATED VERSION (thermometerSimulated brach)
    - Thermometer is not utilized and changes in temperature are emulated according to the state of the heater and the valves.
 - THERMOMETER ENABLED VERSION (thermometerEnabled brach)
    - Temperature indication is generated after obtaining actual measurement from the thermometer

### External dependencies
Please import these libraries before compiling the firmware:
- [TimingUtils](https://github.com/halx4/TimingUtils)
- [BittyStructures](https://github.com/halx4/BittyStructures)


[liqueur plant case study]: https://sites.google.com/site/uml4iot/liqueur-plant-case-study

