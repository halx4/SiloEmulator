__Master Branch is not used in this repo. Use the rest branches instead.__

# SiloEmulator

Silo emulator is an arduino-based system implementing the full (incl. mixer and heater) silo interface as described in the [liqueur plant case study].

 It is designed to interface directly with raspberry pi (and any 3.3V logic controller) with digital i/o ’s and a serial connection. A thermometer (Maxim DS18B20) is integrated so the user can change the actual measured temperature by heating it but there is also the option to emulate the temperature’s changes depending on heater’s and valves’ state. One more capability implemented is the option of sending the temperature over the serial line or exposing the thermometer’s data pin as output so the silo's controller can communicate directly with the thermometer. Silo’s state is exposed by the corresponding outputs (digital pins and serial line) along with visual (leds and 8-segment display) and audible (buzzer) indications for easier debugging and demonstration.


[liqueur plant case study]: https://sites.google.com/site/uml4iot/liqueur-plant-case-study

