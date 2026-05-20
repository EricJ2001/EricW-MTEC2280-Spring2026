
let serialPort;

let sendValue = 0;

let visualMode = 0;

let movingCircleX = 0;
let circleSpeed = 6;

let pulseSize = 100;

function setup()
{
  createCanvas(900, 600);

  serialPort = new p5.SerialPort();

  serialPort.open('/dev/cu.usbserial-110');

  serialPort.on('open', portOpen);

  serialPort.on('error', portError);

  rectMode(CENTER);

  textAlign(CENTER, CENTER);
}

function draw()
{
  background(15, 20, 40);

  fill(255);

  textSize(28);

  text("Interactive UART LED Controller", width / 2, 40);

  textSize(18);


  if (visualMode == 0)
  {
    text("MODE 1 : Mouse Control", width / 2, 80);

    sendValue = int(map(mouseX, 0, width, 0, 1000));

    serialPort.write(sendValue + '\n');

    pulseSize = map(mouseX, 0, width, 50, 300);

    fill(100, 180, 255);

    ellipse(mouseX, height / 2, pulseSize);

    fill(255, 120, 120);

    rect(width / 2, 450, pulseSize, pulseSize);

    fill(255);

    triangle(mouseX, 120,
             mouseX - 60, 240,
             mouseX + 60, 240);
  }


  else
  {
    text("MODE 2 : Automatic Animation", width / 2, 80);

    movingCircleX += circleSpeed;

    if (movingCircleX > width || movingCircleX < 0)
    {
      circleSpeed *= -1;
    }

    sendValue = int(map(movingCircleX, 0, width, 0, 1000));

    serialPort.write(sendValue + '\n');

    fill(255, 200, 80);

    ellipse(movingCircleX, height / 2, 160);

    fill(120, 255, 160);

    rect(width / 2, movingCircleX / 2, 120, 120);

    fill(255);

    triangle(movingCircleX, 500,
             movingCircleX - 60, 580,
             movingCircleX + 60, 580);
  }

  fill(255);

  textSize(22);

  text("Serial Value: " + sendValue,
       width / 2,
       height - 40);
}

function mousePressed()
{
  if (visualMode == 0)
  {
    visualMode = 1;
  }

  else
  {
    visualMode = 0;
  }
}

function portOpen()
{
  console.log("Serial Port Opened");
}

function portError(err)
{
  console.log("Serial Error: ", err);
}