# LCD Thermometer
Interim Critique

By André Bourgeois

# Description
The intent of this project was to create a sensor system that would help to inform my understanding of the world. The resulting design was an iteration on previous projects
that I completed throughout this course - resulting in the capture of data that I care about, displayed in a way that I can easily understand.

# Materials
- Arduion Uno
- Breadboard
- Plastic Arduino Base
- USB Cable
- DHT22 Temperature/Humidity Sensor
- LCD Screen
- Potentiometer
- 220 Resistor
- Wires

# The Process
**Prototype 1**

My first prototype for this project was [LEDstripURF](https://github.com/andrelbourgeois/CASA0016/tree/master/LEDstripURF). Using an ultrasonic range finder (URF) as an input, and
an LED strip as an output, this sensor network was able to detect the distance of an object and visually display a value of this distance by lighting up the LEDs. A greater
distance from the URF results in more LEDs being lit up to represent the increased distance. I couldnèt find a real need for a URF in my life, so my first step was to replace
the sensor and choose something which I thought would add more value to my life than detecting distance - temperature.

![LEDstripURF](https://user-images.githubusercontent.com/33913141/144129281-4d4bb6da-3713-4bb9-be24-c0350a4b07c0.jpg)

**Prototype 2**

My second prototype for this project was [LEDstripTHERMOMETER](https://github.com/andrelbourgeois/CASA0016/tree/master/LEDstripTHERMOMETER). Very similar to the last protoype,
however, it uses a DHT22 temperature and humidity sensor (DHT22) as an input. The function of this build is similar, wherein a higher temperature will light up more LEDs to
represent the greater value. The next issues I realized was how inaccurate this LED strip was at relaying information, particularly values that exceed 8 (the number of LEDs
on the strip) or negative values. This is because the temperature value is mapped to the 8 LEDs. In my case, using a maxmimum temperature value of 40, each LED would represent
5 degrees - a fairly significant number. I decided it would be better to switch the LED strip for something a little more human-friendly.

![LEDstripTHERMOMETER](https://user-images.githubusercontent.com/33913141/144129314-a341689a-9762-4c7f-a57e-eb049f3dec82.jpg)


**Final Build**

In the final build, LCDtheremometer, I switched the LED strip from a liquid crystal display (LCD) which I found was much more accurate, and much easier to read. It reduces the amount of mental math I need to do whenever I want to know the temperature, and let's be honest - visually appealing.

- Step 1:\


![LCDthermometer](https://user-images.githubusercontent.com/33913141/144129329-fab20756-0b29-436e-a109-5b38f9693be5.jpg)

**Problems & Solutions**

- Problem: My LCD turned on my it's just a blank screen.\
Solution: Add a potentiometer which can adjust the resolution on the LCD.

- Problem: My DHT22 was not giving a temperature value and instead, my LCD was reading "Nan".\
Solution: "Nan" stands for "Not a number" - I realized that the temperature value was staying a blank floating point number, and was not recieving a value from the DHT22.
I also realized that the DHT22 was not oriented properly. By rotating it 90° and adjusting the wires accordingly, I was able to recieve the correct value.

- Problem: LCD showing a lot of random  characters and symbols - looks like an alien language.\
Solution: I'm not actually sure what the issue is here, but unplugging the board and plugging it back into the computer fixes this issue every time.

**Next Steps**

- My current build is not mobile, so I would like to attach a mobile power source to it. Something that does not rely on external factors for power - like solar panels - 
because I would like to be able to use this indoors as well. I think a battery would be suitable, however, the lithium battery that I currently have is only 3.7 volts,
and isn't strong enough to run my 5 volt build.
- I coded in a starting screen for my LCD. It doesn't show up when my LCD starts, or maybe it shows up too quickly to see, but I would like to fix this as well.
- Add an enclosure
- Add in setp-by-step to the README.md
- Add a fritzing diagram

