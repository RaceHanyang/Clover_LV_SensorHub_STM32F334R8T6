# Sensor Hub README

# **Clover_LV_SensorHub_STM32F334R8T6**

Sensor Hub MCU, STM32F334R, of Clover.

With a new circuit design, this project has been built from the ground.

A couple of these MCU embedded circuits are attached on Clover, one on the front and the other on the rear and serve as follows.

1. **Read hall effect Wheel Speed Sensor(”WSS”)** 
- Process PWM pulse generated from two WSSs in form of RPM(Revolution Per Minute.).
- Check for the duty ratio of each wheel if they are out of a predetermined range, implying the measurement is executed abnormally.
- Send two pairs, one pair for the left wheel and the other for the right, of a measured RPM value and its range check result to Infineon TriCore275 VCU through a CAN2.0B bus.
1. **Read Shock Absorber Contraction.**
- Process voltage signal - analog signal ranging from 0 to 5V - through ADC.
- 2 linear potentiometers per wheel, summing to 4 per circuit.
- Send those 4 values to an Infineon Tricore275 Datalogger through a CAN2.0B bus.
- Conversion from the saturation of the linear potentiometers to the actual movement of wheels shall be processed externally during post-race analysis.
1. **I2C Expansion Ready.**
- Though we do not have any I2C peripherals in Clover yet, the circuit has port enabled for an I2C device.

# Sensors Deployed

1. **Wheel Speed Sensor**

Vendor: ZF(aka Cherry)

Code: GS101205

Datasheet: 

[ZF](https://switches-sensors.zf.com/us/wp-content/uploads/sites/7/2014/04/Datasheet_GS101205_EN_29_11_17.pdf)

1. **Linear Potentiometer**

Miran KPM16-SL-J

# Associated JIRA Project

[Jira](https://racehanyang.atlassian.net/jira/software/projects/SH/boards/4/backlog)

Should you believe you have access to our issue tracker system, please reach @Terry Yoon to grant permission.

Or, outsiders, namely other FSAE teams, may request internal documentation if some conditions are arranged. Please mail @Terry Yoon with some form of your self-description.

# Author in Charge

**Terry Yoon - 윤성배**

Team of Electric Control, Race 29th.

📧 *yoonsb@hanyang.ac.kr*

🗃️ *blog.terrysyoon.com*

# Dev Environments

**STM32CubeIDE:** *V1.10.0*

**STM32F334R FW:** *STM32Cube FW_F3 V1.11.3*

Windows 10 PC

*Readme V1.0*

Jan *9th, 2023*

@Terry Yoon