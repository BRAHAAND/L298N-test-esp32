# L298N-test-esp32
# ESP32 + L298N Motor Test

**A minimal test that drives one DC motor in both directions with PWM speed control, using an ESP32 and an L298N motor driver.**
<p align=center>
  <img width="50%" height="1615" alt="IMG20261004001903" src="https://github.com/user-attachments/assets/63a225c5-08d8-4bb0-af3b-9bd89d007afe" />
</p>


## Hardware

- ESP32 dev board
- L298N motor driver
- 1 DC motor
- 7-9 V battery pack
- Jumper wires

## Wiring

| From | To |
|---|---|
| Battery + | L298N 12V |
| Battery − | L298N GND |
| ESP32 GND | L298N GND (common ground) |
| Motor wire 1 | L298N OUT1 |
| Motor wire 2 | L298N OUT2 |
| ESP32 GPIO18 | L298N ENA |
| ESP32 GPIO19 | L298N IN1 |
| ESP32 GPIO21 | L298N IN2 |

Notes:
- Remove the ENA jumper so PWM can control speed.
- Leave the L298N 5V pin unconnected. The ESP32 is powered over USB.
- The common ground between the ESP32 and the L298N is required.
- Connect the battery last, after uploading the sketch.

## Software

- Arduino IDE
- ESP32 Arduino core 3.x (uses `ledcAttach` / `ledcWrite` with a pin number)

For core 2.x, replace `ledcAttach(ENA, PWM_FREQ, PWM_RES)` with `ledcSetup(0, PWM_FREQ, PWM_RES); ledcAttachPin(ENA, 0);` and use channel `0` in `ledcWrite`.

## How to run

1. Wire everything with the battery disconnected.
2. Open `l298n_motor_test/l298n_motor_test.ino` in the Arduino IDE.
3. Select your ESP32 board and port, then upload.
4. Open the Serial Monitor at 115200 baud.
5. Connect the battery.

The motor runs forward 2 s, stops 1 s, runs in reverse 2 s, stops 3 s, and repeats.

## Troubleshooting

| Symptom | Fix |
|---|---|
| Hums but doesn't spin | Raise `SPEED` toward 255, check the battery |
| Does nothing | Check common ground, the removed ENA jumper, battery polarity |
| Spins only one way | Recheck the IN1 / IN2 wires |
| Wrong direction | Swap the motor wires on OUT1 / OUT2 |
| ESP32 resets when the motor starts | Add a 0.1 µF ceramic capacitor across the motor terminals |

## License

MIT
