# Motion Detection System with GSM Notification

This project utilizes an Arduino board along with a passive infrared (PIR) motion sensor and a GSM module to create a motion detection system that sends SMS notifications when motion is detected. The system is suitable for applications such as home security, monitoring restricted areas, or detecting unauthorized access.

## Hardware Components:
- Arduino board (e.g., Arduino Uno)
- Passive Infrared (PIR) motion sensor
- GSM module (SIM900L)
- Buzzer
- Jumper wires

## Software Dependencies:
- Arduino IDE
- SoftwareSerial library

## Setup Instructions:
1. Connect the components according to the following pin configuration:
   - PIR sensor output to Arduino pin 6 (PIR_PIN)
   - Buzzer to Arduino pin 12 (BUZZER_PIN)
   - GSM module RX pin to Arduino pin 10 (GSM_RX_PIN)
   - GSM module TX pin to Arduino pin 9 (GSM_TX_PIN)
2. Install the necessary libraries in the Arduino IDE, including SoftwareSerial.
3. Upload the provided Arduino sketch to the Arduino board.

## Usage:
1. Power on the Arduino board.
2. When motion is detected by the PIR sensor, the buzzer will sound, and an SMS notification will be sent to the specified phone number.
3. The SMS will contain the message "Security Alert! Motion Detected".

## Customization:
- Modify the phone number in the `sendSMS` function to specify the recipient of the SMS notifications.
- Adjust the delay durations in the `loop` function to customize the system's behavior (e.g., delay before rechecking for motion).

## Notes:
- Ensure that the GSM module is properly configured and has an active SIM card with SMS capabilities.
- Test the system in the desired environment to ensure reliable performance and adjust sensitivity settings of the PIR sensor if necessary.

## License:
This project is provided under the [MIT License](https://opensource.org/licenses/MIT). Feel free to modify and distribute it according to your requirements.

## Author:
[Joseph Mutyaba/JosephMutyaba/josephsteinson@gmail.com]
