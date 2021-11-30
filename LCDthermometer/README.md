# LCD Thermometer
Interim Critique

By André Bourgeois

# Description
The intent of this project was to create a sensor system that would help to inform my understanding of the world. The resulting design was an iteration on previous projects
that I completed throughout this course - resulting in the capture of data that I care about, displayed in a way that I can easily understand.

# The Process
**Prototype 1**

My first prototype for this project was [LEDstripURF](https://github.com/andrelbourgeois/CASA0016/tree/master/LEDstripURF). Using an ultrasonic range finder (URF) as an input, and
an LED strip as an output, this sensor network was able to detect the distance of an object and visually display a value of this distance by lighting up the LEDs. A greater
distance from the URF results in more LEDs being lit up to represent the increased distance. I couldnèt find a real need for a URF in my life, so my first step was to replace
the sensor and choose something which I thought would add more value to my life than detecting distance - temperature.


**Prototype 2**

My second prototype for this project was [LEDstripTHERMOMETER](https://github.com/andrelbourgeois/CASA0016/tree/master/LEDstripTHERMOMETER). Very similar to the last protoype,
however, it uses a DHT22 temperature and humidity sensor (DHT22) as an input. The function of this build is similar, wherein a higher temperature will light up more LEDs to
represent the greater value. The next issues I realized was how inaccurate this LED strip was at relaying information, particularly values that exceed 8 (the number of LEDs
on the strip) or negative values. This is because the temperature value is mapped to the 8 LEDs. In my case, using a maxmimum temperature value of 40, each LED would represent
5 degrees - a fairly significant number. I decided it would be better to switch the LED strip for something a little more human-friendly.

**Final Build**

In the final build, LCDtheremometer, I switched the LED strip from a liquid crystal display (LCD) which I found was much more accurate, and much easier to read. It reduces the amount of mental
math I need to do whenever I want to know the temperature, and let's be honest - visually appealing.
