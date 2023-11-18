import processing.serial.*;

Serial myPort;

PImage logo;

int bgcolor = 0;

void setup()
{
   colorMode(HSB, 255);
   logo = loadImage("https://www.sevenstring.org/data/styles/10/styles/sevenstring/xenforo/logo.gif");
   windowResize(logo.width, logo.height);
   
   println("Available serial ports: ");
   String[] ports = Serial.list();
   println(ports);
   
   myPort = new Serial(this, Serial.list()[0], 9600);
}

void draw()
{
  if (myPort.available() > 0)
  {
    bgcolor = myPort.read();
    println(bgcolor);
  }
  
  background(bgcolor, 255, 255);
  image(logo, 0, 0);
}
