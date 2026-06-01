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
## TTL-to-Serial to PCB

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


# To do:
+ describe the fix needed on the pcb (for v2). can you update the schematic and board layout files so that the next board submission will not need the manual fix. 
+ add photos to README
+ wiring for the Molex connector
+ wiring from TTL-to-Serial to PCB
+ BOM (Bill of materials) (include BUD box and barrel connector and TTL-to-serial adapter board)
+ Commands that the teensy understands (e.g. what is the command to get all temperature readings?)
+ potential upgrades (can you request just a single temperature reading?)
