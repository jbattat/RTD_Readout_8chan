# 8-channel RTD Readout Board with Serial Communication
Design and implementation of an 8-channel RTD readout

# System Diagram
![Alt text](images/SystemDiagram.png)

# Schematic 
![Alt text](images/PCB_Schematic.png)

# Known Issue
*Board will not function without this fix*

For PCB v2, one ground net connection is missing and must be manually wired. Fix: Connect G pin of Teensy to the ground pins of the 6 pin Molex connector (U1). Shown below.

![Alt text](images/PopulatedPCBBack.png)

# Hardware Components

| Component | Function |
| :--- | :--- |
| Teensy 4.0 | Microcontroller | 
| Custom RTB PCB | allows communication between Teensy, 8 RTDs, and Waveshare, See: [Fab Files](Hardware/PCB%20v2/Fab%20Files/)| 
| RTDs + thermocouples | 8 temperature sensors | 
| TTL-to-Serial Converter | communication interface to Waveshare  | 
| Waveshare | external controller | 
| Custom enclosure | houses all electronics and wiring | 
| 5V power supply | powers entire system | 

See [BOM](Hardware/bom.md) for component details.

# Assembly Instructions
1. Upload [Teensy Code](Software/TeensyCode/EightRTDBoard_05052026.ino) to Teensy 4.0.
2. Populate PCB. *If using v2 PCB, make sure you perform fix detailed in [Known Issue](#known-issue)*
5. [Wire 6 pin molex connection](#wiring). See: [TTL-to-Serial and 5V to PCB Wiring](#ttl-to-serial-and-5v-power-jack-to-pcb)
6. [Mount electronics in enclosure](#ttl-to-serial-to-PCB)
7. Connect Waveshare Device to TTL-to-Serial converter via D9-to-D9 1 to 1 connector.
8. Close enclosure.

# Enclosure Layout
![Alt text](images/Box.png)
Enclosure has cutouts for 3 D9 connections and for the 5V Power Jack.
## Front Panel
| Component | Function |
| :--- | :--- |
| 5V Power Jack | power input | 
| D9 #1 | TTL-to-Serial communication interface | 

## Back Panel
| Component | Function |
| :--- | :--- |
| D9 #2 | thermocouple to RTDs 1-4 connection | 
| D9 #3 | thermocouple to RTDs 5-8 connection | 

# Wiring
## TTL-to-Serial and 5V Power Jack to PCB
![Alt text](images/TTLand5VtoPCB.png)

## RTD Connections

| RTD | CS | D9 | D9 Pin to RTD+ | D9 Pin to RTD- |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 7 | 1 | 5 | 9 |
| 2 | 6 | 1 | 4 | 8 |
| 3 | 8 | 1 | 2 | 7 |
| 4 | 5 | 1 | 1 | 6 |
| 5 | 9 | 2 | 5 | 9 |
| 6 | 4 | 2 | 4 | 8 |
| 7 | 10 | 2 | 2 | 7 |
| 8 | 3 | 2 | 1 | 6 |

# Commands
The teensy is programmed to transmit temperature data to the Waveshare for all 8 RTDs when it receives the letter 't' as input and to transmit information helpful for debugging (resistance values) to the Teensy's serial monitor when the letter 'd' is received. 

# Potential Upgrades
Potential upgrades include:
1. updating the teensy code with commands to request the temperature of a single RTD
2. 
