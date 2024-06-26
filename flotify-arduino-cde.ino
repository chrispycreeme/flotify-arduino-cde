#include <WiFiS3.h>
#include "arduino_secrets.h"
#include "webpage.h"
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <SoftwareSerial.h>

Adafruit_BMP085 bmp;

#define trigPin 10
#define echoPin 9
SoftwareSerial BluetoothModule(10, 9); // RX, TX

extern const char webserver[] PROGMEM;

char ssid[] = SECRET_SSID; // your network SSID (name)
char pass[] = SECRET_PASS; // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;          // your network key index number (needed only for WEP)

int duration, distance;

int rainSensor = A1;
int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup()
{
  Serial.begin(9600); // initialize serial communication
  BluetoothModule.begin(9600);
  if (!bmp.begin())
  {
    Serial.println("Could not find a valid BMP180 sensor, check wiring!");
    while (1)
    {
    }
  }
  pinMode(rainSensor, INPUT); // set the LED pin mode
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE)
  {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true)
      ;
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION)
  {
    Serial.println("Please upgrade the firmware");
  }

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid); // print the network name (SSID);

    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);
    // wait 10 seconds for connection:
    delay(10000);
  }
  server.begin();    // start the web server on port 80
  printWifiStatus(); // you're connected now, so print out the status
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  delay(1000);
  Serial.println(distance);

  int rainValue = analogRead(rainSensor);

  int rainIntensity;
  rainIntensity = (rainValue >= 850 && rainValue <= 1023) ? 1 : (rainValue >= 700 && rainValue < 850) ? 2
                                                            : (rainValue >= 500 && rainValue < 700)   ? 3
                                                            : (rainValue < 500)                       ? 4
                                                                                                      : rainIntensity;

  Serial.print("Temperature = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  long temperature = bmp.readTemperature();

  WiFiClient client = server.available(); // listen for incoming clients
  if (client)
  {                               // if you get a client,
    Serial.println("new client"); // print a message out the serial port
    String currentLine = "";      // make a String to hold incoming data from the client
    String request = "";          // hold the request
    while (client.connected())
    { // loop while the client's connected
      if (client.available())
      {                         // if there's bytes to read from the client,
        char c = client.read(); // read a byte, then
        Serial.write(c);        // print it out to the serial monitor
        request += c;           // store the byte in the request string

        if (c == '\n')
        {
          if (currentLine.length() == 0)
          {
            if (request.indexOf("GET /rain") >= 0)
            {
              // send the rain value
              client.println("HTTP/1.1 200 OK");
              client.println("Content-Type: application/json");
              client.println("Access-Control-Allow-Origin: *");
              client.println();
              client.print("{\"rainIntensity\": ");
              client.print(rainIntensity);
              client.print(", \"waterLevel\": ");
              client.print(distance);
              client.print(", \"temperature\": ");
              client.print(temperature);
              client.println("}");
            }
            else
            {
              // send the main page with JavaScript
              client.println("HTTP/1.1 200 OK");
              client.println("Content-type:text/html");
              client.println();

              // Read HTML from PROGMEM and send it to the client
              client.print(webserver);

              // The HTTP response ends with another blank line:
              client.println();
            }
            break;
          }
          else
          { // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        }
        else if (c != '\r')
        {                   // if you got anything else but a carriage return character,
          currentLine += c; // add it to the end of the currentLine
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}

void printWifiStatus()
{
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}
