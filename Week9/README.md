# Power Management

## Notes

![Power Management notes](https://user-images.githubusercontent.com/60868965/210139686-4a7b4b2e-81eb-44b3-9b9d-05cca4c2eaf1.png)

[[Link]](https://excalidraw.com/#json=EHTipB7fbFsHbOwixGVFH,0tbjfs-etQt9fLjhxoo5RA)

## Taking off the 'brain'

I uploaded a [fade](https://github.com/arduino/arduino-examples/tree/main/examples/01.Basics/Fade) sketch beforehand. So I can verify the sketch is working.

|                                                           Picture                                                           | Description                                                                                                 |
| :-------------------------------------------------------------------------------------------------------------------------: | :---------------------------------------------------------------------------------------------------------- |
|                                      ![Atmega Arduino](https://imgur.com/dvVaQoq.png)                                       | You may need [IC Extractor](https://my.cytron.io/p-pro-skit-ic-extractor?ref=99Y7TxrNIn6Jo) tool like shown |
| ![AtMega breadboard](https://user-images.githubusercontent.com/60868965/210139822-4e7bb75b-8722-4cc2-a54b-b2f044ed1dae.jpg) | Put the IC on the breadboard.                                                                               |

Instruction can be read here: https://dronebotworkshop.com/arduino-uno-atmega328/

## Powering up the devices

There are many possible ways to power up the microcontroller. Please always refer to the datasheet to avoid any damage.

### Using power module

I'm using [Breadboard Power Module MD-102](https://my.cytron.io/p-breadboard-power-module-md-102?ref=99Y7TxrNIn6Jo) so I can connect to 12V external power and easily provide the required voltage to the microcontroller.

![Arduino standalone power](https://imgur.com/7vR85d9.png)

### Using NiCd 4.8V battery

![image nicd arduino](https://imgur.com/XCCBizT.png)

The nominal voltage is 4.8V but I actually get around 4.5V

### Using AA battery (x3)

One AA battery is 1.5V. So I need 3 of them to get 4.5V.

![image aa arduino](https://imgur.com/EoFaOEb.png)
