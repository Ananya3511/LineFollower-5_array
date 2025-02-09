# Line-Follower_5array

This Arduino code is for a line-following robot that uses sensors to detect a line and steer the robot accordingly. The robot moves forward, turns left, or turns right based on the readings from multiple sensors placed along the robot's path. The code uses motors controlled by an H-bridge to move the robot in different directions and at different speeds.

## Features
- Controls motors based on sensor input.
- Adjusts the robot's movement (forward, left, right) depending on the sensor's state.
- Offers multiple modes of movement: forward, left turn, right turn, and stop.
- Reads input from analog sensors to detect obstacles or lines.

## Components
- **Motors**: Two motors to drive the robot.
- **H-Bridge Driver**: Used to control the direction and speed of the motors.
- **Sensors**: 5 IR sensors are used to determine the robot's position and movement direction.
  - A0 to A4: Input pins for sensors.
- **Arduino Pins**:
  - **in1, in2, in3, in4**: Control pins for motor direction.
  - **enA, enB**: Enable pins to control motor speed.

## Pin Definitions
- `in1` = 2
- `in2` = 3
- `in3` = 4
- `in4` = 5
- `enA` = 9
- `enB` = 6

## Motor Control
- Motor 1 and Motor 2 can be controlled with speed values (`M1_Speed`, `M2_Speed`).
- Left and Right turns have adjustable speeds (`LeftRotationSpeed`, `RightRotationSpeed`).

## Setup
1. Set up the Arduino with the specified sensor pins and motor control pins.
2. Connect sensors (A0, A1, A2, A3, A4) to detect various states.
3. Use PWM (analogWrite) to control the motor speed.

## Code Explanation
### `setup()`
The setup function initializes all the necessary pins (for the motors and sensors) and starts the serial communication for debugging.

### `loop()`
In the loop, the program reads the sensor states and adjusts the robot's movement accordingly:
- If all sensors detect no obstacles, the robot turns left.
- If the sensors detect a line, the robot moves forward.
- If the robot needs to turn, it adjusts direction based on the sensor configuration.

### Movement Functions
- `forward()`: Makes the robot move forward.
- `right()`: Turns the robot right.
- `left()`: Turns the robot left.
- `right1()` and `left1()`: Adjusted turns for finer control of the motors.
- `Stop()`: Stops the robot.

## Sensor States

### Sensor Configuration
Each sensor (A0-A4) can have 2 states:
- `0`: No line or obstacle detected.
- `1`: Line or obstacle detected.

The robot's movement is determined based on the combination of sensor readings.

### Example Sensor States and Corresponding Actions
- `0, 0, 0, 0, 0`: Turns left.
- `0, 0, 1, 0, 0`: Moves forward.
- `1, 1, 1, 0, 0`: Moves forward.
- `0, 1, 1, 0, 0`: Turns right.

## Motor Speed Adjustments
The motor speed can be adjusted for each motor individually by modifying the `M1_Speed` and `M2_Speed` variables. The robot can also rotate at different speeds based on the left and right rotation speed values (`LeftRotationSpeed` and `RightRotationSpeed`).

## Usage
Upload the code to your Arduino board and power the robot. It will automatically respond to the sensor inputs and move accordingly.

### How to Run

1. Download and install [Arduino IDE](https://www.arduino.cc/en/software).
2. Connect your Arduino to your computer using a USB cable.
3. Open the code in the Arduino IDE.
4. Select your Arduino board (I used Arduino Nano) and the correct port from the **Tools** menu.
5. Upload the sketch to the board.
6. Open the Serial Monitor to check sensor readings and debug output.
