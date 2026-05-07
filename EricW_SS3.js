let serialPort;


let sensorData = [];


let button_1 = 0;
let button_2 = 0;


let pot_1 = 0;
let pot_2 = 0;


let circleSize = 100;
let squareSize = 100;
let moveX = 200;
let moveY = 200;

function setup()
{
  createCanvas(900, 600);

  
  serialPort = new p5.SerialPort();

  serialPort.open('/dev/cu.usbserial-110');

  serialPort.on('data', serialEvent);

  rectMode(CENTER);
}

function draw()
{
  
  let bgColor = map(pot_1, 0, 4095, 0, 255);

  circleSize = map(pot_1, 0, 4095, 50, 300);

  squareSize = map(pot_2, 0, 4095, 40, 250);

  moveX = map(pot_1, 0, 4095, 100, width - 100);

  moveY = map(pot_2, 0, 4095, 100, height - 100);

  // BACKGROUND
  background(bgColor, 120, 180);

  
  if (button_1 == 1)
  {
    fill(255, 80, 80);
  }

  else
  {
    fill(80, 200, 255);
  }

  
  ellipse(moveX, height / 2, circleSize);

  
  if (button_2 == 1)
  {
    fill(255, 255, 0);
  }

  else
  {
    fill(120, 255, 120);
  }

  
  rect(width / 2, moveY, squareSize, squareSize);

  
  fill(255);
  triangle(700, 150, 800, 350, 600, 350);

  
  strokeWeight(5);
  line(0, 0, moveX, moveY);

  
  noStroke();
  fill(255, 100, 200);
  ellipse(width - moveX, height - moveY, 50);
}


function serialEvent()
{
  let incomingData = serialPort.readLine();

  incomingData = trim(incomingData);

  if (!incomingData) return;

  sensorData = incomingData.split(",");

  
  button_1 = int(sensorData[0]);
  button_2 = int(sensorData[1]);

  pot_1 = int(sensorData[2]);
  pot_2 = int(sensorData[3]);
}