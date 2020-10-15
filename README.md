# esp8266-web-server
This project is a sample of a traffic lights leds, using a nodemcu board

# Requirements

- Plataform IO
- A nodemcu v2 board
- USB mini
- A traffic light module
- A breadboard or a protoboard
- Jumpers Male x Female

# Getting Started

Setting your ports configuration in **```plataformio.ini```** file

```ini

; Custom Upload Port
upload_port = /dev/tty.usbserial-1420

; Custom Serial Monitor port
monitor_port = /dev/tty.usbserial-1420

```

Set your **SSID** and **PASSWORD** in **```main.cpp```** file

```c++
  nodemcu.wifiBegin("my-ssid", "my-password");
```

After this configuration upload your sketch and have fun!


# Sketch

<img src="https://github.com/leomenezessz/esp8266-web-server/blob/master/traffic-light-sketch.jpeg" width="400">









