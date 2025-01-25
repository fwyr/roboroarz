# RoboRoarZ'25 (Singapore)

This repository contains the code for Team Delirium (4th place in Senior Category), maneuvering a Smorphi² robot equipped with a HuskyLens camera for line-following in a maze. 

## Repository Structure
- `main.ino` — the main file for the Smorphi² robot
- `movements.ino` — the movement handler 
- `sensor_initialisation.ino` — initialises & changes sensor status according to the robot's shape

## Boards & Libraries

- esp32 by Espressif (ESP32 Dev Module)
- Adafruit Motor Shield V2 Library
- Adafruit MCP23017 Arduino Library
- EspSoftwareSerial Library
- [Smorphi Libraries](https://github.com/wefaarobotics/smorphi)
- [HUSKYLENS Arduino API](https://github.com/HUSKYLENS/HUSKYLENSArduino)
- [Silicon Labs CP210x USB-to-UART VCP Driver](https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers)

Note that software documentation for the Smorphi robot can found in [WefaaRobotics' Github wiki](https://github.com/WefaaRobotics/Smorphi/wiki/Smorphi-Code-Documentation). The original template provided to all participants can be found [here](https://github.com/WefaaRobotics/RRZ_SG_25).

If provided in future competitions, we do not recommend using the Smorphi fork of the Ardublockly locally-run block-based coding platform due to its utilisation of deprecated code — but in case anyone does, it may be important to note the following fixes within the source code itself.
- Change all instances of `getargspec` to `getfullargspec`. Affected files are found in the `ardbublocklyserver/local-packages/bottle` directory.
- Change all instances of `from collections import MutableMapping` to `from collections.abc import MutableMapping`. This throws an error for Python 3.8 and onwards. Affected files are found in the `ardublocklyserver/local-packages/configparser` directory.

## License
This project is licensed under the MIT License. See [LICENSE](LICENSE) for more details.

