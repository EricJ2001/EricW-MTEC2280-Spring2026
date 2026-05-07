let serialPort;
let ledOne = 0;
let ledTwo = 0;

let mode = 0;

let waveAngle = 0;

let flashSize = 100;

let barHeight = 200;

function setup()
{
  createCanvas(900, 600);

  serialPort = new p5.SerialPort();

  serialPort.open('/dev/cu.usbserial-110');

  serialPort.on('open', portOpen);

  rectMode(CENTER);

  angleMode(DEGREES);
}

function draw()
{
  background(10, 10, 30);

  fill(255);

  textAlign(CENTER);

  textSize(28);

  text("Rhythm Light Controller",
       width / 2,
       40);

  
  if (mode == 0)
  {
    text("MODE 1 : DJ Pad",
         width / 2,
         80);

    ledOne = int(map(mouseX,
                     0,
                     width,
                     0,
                     255));

    ledTwo = int(map(mouseY,
                     0,
                     height,
                     255,
                     0));

    serialPort.write(ledOne + "," +
                     ledTwo + "\n");

    fill(255, 80, 120);

    rect(width / 3,
         height / 2,
         120,
         mouseY);

    fill(80, 180, 255);

    ellipse(mouseX,
            height / 2,
            flashSize);

    fill(255);

    triangle(mouseX,
             100,
             mouseX - 40,
             200,
             mouseX + 40,
             200);

    stroke(255);

    line(width / 2,
         0,
         mouseX,
         mouseY);

    noStroke();
  }

  else
  {
    text("MODE 2 : Pulse Wave",
         width / 2,
         80);

    waveAngle += 4;

    ledOne = int(map(sin(waveAngle),
                     -1,
                     1,
                     0,
                     255));

    ledTwo = int(map(cos(waveAngle),
                     -1,
                     1,
                     0,
                     255));

    serialPort.write(ledOne + "," +
                     ledTwo + "\n");

    fill(255, 200, 80);

    ellipse(width / 2,
            height / 2,
            200 + sin(waveAngle) * 100);

    fill(120, 255, 180);

    rect(width / 2,
         height / 2,
         100,
         300 + cos(waveAngle) * 150);

    fill(255);

    triangle(width / 2,
             150,
             width / 2 - 80,
             300,
             width / 2 + 80,
             300);

    stroke(255);

    line(width / 2,
         height / 2,
         width / 2 + cos(waveAngle) * 250,
         height / 2 + sin(waveAngle) * 250);

    noStroke();
  }

  fill(255);

  textSize(18);

  text("LED 1 : " + ledOne,
       150,
       height - 60);

  text("LED 2 : " + ledTwo,
       150,
       height - 30);
}

function mousePressed()
{
  if (mode == 0)
  {
    mode = 1;
  }

  else
  {
    mode = 0;
  }

  flashSize = random(80, 220);
}

function portOpen()
{
  console.log("Serial Connected");
}